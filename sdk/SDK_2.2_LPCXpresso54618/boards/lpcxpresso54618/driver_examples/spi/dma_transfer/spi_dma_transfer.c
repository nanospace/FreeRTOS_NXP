/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "fsl_debug_console.h"
#include "fsl_device_registers.h"
#include "fsl_spi.h"
#include "fsl_spi_dma.h"
#include "fsl_dma.h"
#include "board.h"
#include "pin_mux.h"
#include <stdbool.h>
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define EXAMPLE_SPI_MASTER SPI9
#define EXAMPLE_SPI_MASTER_IRQ FLEXCOMM9_IRQn
#define EXAMPLE_SPI_MASTER_CLK_SRC kCLOCK_Flexcomm9
#define EXAMPLE_SPI_MASTER_CLK_FREQ CLOCK_GetFreq(kCLOCK_Flexcomm9)
#define EXAMPLE_SPI_SLAVE SPI3
#define EXAMPLE_SPI_SLAVE_IRQ FLEXCOMM3_IRQn
#define EXAMPLE_SPI_SSEL 0
#define EXAMPLE_DMA DMA0

#define EXAMPLE_SPI_MASTER_RX_CHANNEL   22
#define EXAMPLE_SPI_MASTER_TX_CHANNEL   23

#define EXAMPLE_SPI_SLAVE_RX_CHANNEL    6
#define EXAMPLE_SPI_SLAVE_TX_CHANNEL    7

#define TRANSFER_SIZE 256U        /*! Transfer dataSize */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* SPI user callback */
void SPI_MasterUserCallback(SPI_Type *base, spi_dma_handle_t *handle, status_t status, void *userData);
void SPI_SlaveUserCallback(SPI_Type *base, spi_dma_handle_t *handle, status_t status, void *userData);

/*******************************************************************************
 * Variables
 ******************************************************************************/
uint32_t masterRxData[TRANSFER_SIZE] = {0};
uint32_t masterTxData[TRANSFER_SIZE] = {0};
uint32_t slaveRxData[TRANSFER_SIZE] = {0};
uint32_t slaveTxData[TRANSFER_SIZE] = {0};

dma_handle_t masterTxHandle;
dma_handle_t masterRxHandle;
dma_handle_t slaveTxHandle;
dma_handle_t slaveRxHandle;

spi_dma_handle_t masterHandle;
spi_dma_handle_t slaveHandle;

volatile bool isTransferCompleted = false;

/*******************************************************************************
 * Code
 ******************************************************************************/

void SPI_SlaveUserCallback(SPI_Type *base, spi_dma_handle_t *handle, status_t status, void *userData)
{
    if (status == kStatus_Success)
    {
        PRINTF("This is SPI slave dma transfer completed callback. \r\n\r\n");
    }
    isTransferCompleted = true;
}

void SPI_MasterUserCallback(SPI_Type *base, spi_dma_handle_t *handle, status_t status, void *userData)
{
    if (status == kStatus_Success)
    {
        PRINTF("This is SPI master dma transfer completed callback. \r\n\r\n");
    }
}

/*!
 * @brief Main function
 */
int main(void)
{
    /* attach 12 MHz clock to FLEXCOMM0 (debug console) */
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM0);

    /* attach 12 MHz clock to SPI3 */
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM3);

    /* attach 12 MHz clock to SPI9 */
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM9);
    
    BOARD_InitPins();
    BOARD_BootClockFROHF48M();
    BOARD_InitDebugConsole();

    PRINTF("SPI dma example start.\r\n");
    PRINTF("This example use one spi instance as master and another as slave on one board.\r\n");
    PRINTF("Please make sure you make the correct line connection. Basically, the connection is: \r\n");
    PRINTF("SPI_master -- SPI_slave   \r\n");
    PRINTF("   CLK      --    CLK  \r\n");
    PRINTF("   PCS      --    PCS  \r\n");
    PRINTF("   SOUT     --    SIN  \r\n");
    PRINTF("   SIN      --    SOUT \r\n");

    /* DMA init */
    DMA_Init(EXAMPLE_DMA);

    /* SPI init */
    uint32_t srcClock_Hz;
    uint32_t errorCount;
    uint32_t i;
    spi_master_config_t masterConfig;
    spi_slave_config_t slaveConfig;
    spi_transfer_t masterXfer;
    spi_transfer_t slaveXfer;

    srcClock_Hz = EXAMPLE_SPI_MASTER_CLK_FREQ;

    /* Master config */
    SPI_MasterGetDefaultConfig(&masterConfig);
    masterConfig.sselNum = (spi_ssel_t)EXAMPLE_SPI_SSEL;
    SPI_MasterInit(EXAMPLE_SPI_MASTER, &masterConfig, srcClock_Hz);

    /* Slave config */
    SPI_SlaveGetDefaultConfig(&slaveConfig);
    /* SPI slave must be enabled afer DMA is ready to transfer data */
    slaveConfig.enableSlave = false;
    SPI_SlaveInit(EXAMPLE_SPI_SLAVE, &slaveConfig);

    /* Set up the transfer data */
    for (i = 0U; i < TRANSFER_SIZE; i++)
    {
        /* SPI is configured for 8 bits transfer - set only lower 8 bits of buffers */
        masterTxData[i] = (uint8_t)(i % 256U);
        masterRxData[i] = (uint8_t)0U;

        slaveTxData[i] = (uint8_t)(~masterTxData[i]);
        slaveRxData[i] = (uint8_t)0U;
    }

    DMA_EnableChannel(EXAMPLE_DMA, EXAMPLE_SPI_MASTER_TX_CHANNEL);
    DMA_EnableChannel(EXAMPLE_DMA, EXAMPLE_SPI_MASTER_RX_CHANNEL);
    DMA_SetChannelPriority(EXAMPLE_DMA, EXAMPLE_SPI_MASTER_TX_CHANNEL, kDMA_ChannelPriority3);
    DMA_SetChannelPriority(EXAMPLE_DMA, EXAMPLE_SPI_MASTER_RX_CHANNEL, kDMA_ChannelPriority2);
    DMA_CreateHandle(&masterTxHandle, EXAMPLE_DMA, EXAMPLE_SPI_MASTER_TX_CHANNEL);
    DMA_CreateHandle(&masterRxHandle, EXAMPLE_DMA, EXAMPLE_SPI_MASTER_RX_CHANNEL);

    DMA_EnableChannel(EXAMPLE_DMA, EXAMPLE_SPI_SLAVE_TX_CHANNEL);
    DMA_EnableChannel(EXAMPLE_DMA, EXAMPLE_SPI_SLAVE_RX_CHANNEL);
    DMA_SetChannelPriority(EXAMPLE_DMA, EXAMPLE_SPI_SLAVE_TX_CHANNEL, kDMA_ChannelPriority0);
    DMA_SetChannelPriority(EXAMPLE_DMA, EXAMPLE_SPI_SLAVE_RX_CHANNEL, kDMA_ChannelPriority1);
    DMA_CreateHandle(&slaveTxHandle, EXAMPLE_DMA, EXAMPLE_SPI_SLAVE_TX_CHANNEL);
    DMA_CreateHandle(&slaveRxHandle, EXAMPLE_DMA, EXAMPLE_SPI_SLAVE_RX_CHANNEL);

    isTransferCompleted = false;

    /* Set up spi slave first */
    SPI_SlaveTransferCreateHandleDMA(EXAMPLE_SPI_SLAVE, &slaveHandle, SPI_SlaveUserCallback, NULL, &slaveTxHandle,
                                     &slaveRxHandle);

    slaveXfer.txData = (uint8_t *)&slaveTxData;
    slaveXfer.rxData = (uint8_t *)&slaveRxData;
    slaveXfer.dataSize = TRANSFER_SIZE * sizeof(slaveTxData[0]);

    if (kStatus_Success != SPI_SlaveTransferDMA(EXAMPLE_SPI_SLAVE, &slaveHandle, &slaveXfer))
    {
        PRINTF("There is error when start SPI_SlaveTransferDMA \r\n");
    }

    /* Enable SPI Slave after DMA is ready to transfer data */
    SPI_Enable(EXAMPLE_SPI_SLAVE, true);

    /* Set up spi master */
    SPI_MasterTransferCreateHandleDMA(EXAMPLE_SPI_MASTER, &masterHandle, SPI_MasterUserCallback, NULL, &masterTxHandle,
                                      &masterRxHandle);

    /* Start master transfer */
    masterXfer.txData = (uint8_t *)&masterTxData;
    masterXfer.rxData = (uint8_t *)&masterRxData;
    masterXfer.dataSize = TRANSFER_SIZE * sizeof(masterTxData[0]);
    masterXfer.configFlags |= kSPI_FrameAssert;

    if (kStatus_Success != SPI_MasterTransferDMA(EXAMPLE_SPI_MASTER, &masterHandle, &masterXfer))
    {
        PRINTF("There is error when start SPI_MasterTransferDMA \r\n ");
    }

    /* Wait until transfer completed */
    while (!isTransferCompleted)
    {
    }

    /* Check the data */
    errorCount = 0U;
    for (i = 0U; i < TRANSFER_SIZE; i++)
    {
        /* compare lower 16 bits - data */
        if ((uint8_t)masterTxData[i] != (uint8_t)slaveRxData[i])
        {
            errorCount++;
        }

        /* compare lower 16 bits - data */
        if ((uint8_t)slaveTxData[i] != (uint8_t)masterRxData[i])
        {
            errorCount++;
        }
    }
    if (errorCount == 0)
    {
        PRINTF("SPI transfer all data matched! \r\n");
    }
    else
    {
        PRINTF("Error occured in SPI transfer ! \r\n");
    }

    SPI_Deinit(EXAMPLE_SPI_MASTER);
    SPI_Deinit(EXAMPLE_SPI_SLAVE);

    while (1)
    {
    }
}
