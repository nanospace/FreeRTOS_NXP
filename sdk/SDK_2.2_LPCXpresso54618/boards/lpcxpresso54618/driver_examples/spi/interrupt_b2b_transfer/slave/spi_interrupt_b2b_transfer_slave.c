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

#include "fsl_spi.h"
#include "board.h"
#include "fsl_debug_console.h"

#include "pin_mux.h"
#include <stdbool.h>
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define EXAMPLE_SPI_SLAVE SPI9
#define EXAMPLE_SPI_SLAVE_IRQ FLEXCOMM9_IRQn
#define EXAMPLE_SPI_SSEL 0

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
#define BUFFER_SIZE (64)
spi_slave_handle_t handle;
static uint8_t buff[BUFFER_SIZE];
static uint8_t sendBuff[BUFFER_SIZE];
static volatile bool slaveFinished = false;
/*******************************************************************************
 * Code
 ******************************************************************************/
static void slaveCallback(SPI_Type *base, spi_slave_handle_t *slaveHandle, status_t status, void *userData)
{
    slaveFinished = true;
}

int main(void)
{
    uint32_t i = 0;
    uint8_t err = 0;
    spi_transfer_t xfer = {0};
    spi_slave_config_t userConfig;

    /* attach 12 MHz clock to FLEXCOMM0 (debug console) */
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);

    /* attach 12 MHz clock to SPI9 */
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM9);

    BOARD_InitPins();
    BOARD_BootClockFROHF96M();
    BOARD_InitDebugConsole();
    PRINTF("\n\rSlave is working....\n\r");

    /*
     * userConfig.enableSlave = true;
     * userConfig.polarity = kSPI_ClockPolarityActiveHigh;
     * userConfig.phase = kSPI_ClockPhaseFirstEdge;
     * userConfig.direction = kSPI_MsbFirst;
     */
    SPI_SlaveGetDefaultConfig(&userConfig);
    SPI_SlaveInit(EXAMPLE_SPI_SLAVE, &userConfig);
    SPI_SlaveTransferCreateHandle(EXAMPLE_SPI_SLAVE, &handle, slaveCallback, NULL);
    for (i = 0; i < 64; i++)
    {
        sendBuff[i] = i;
    }

    /* receive data from master*/
    xfer.txData = sendBuff;
    xfer.rxData = buff;
    xfer.dataSize = sizeof(sendBuff);
    SPI_SlaveTransferNonBlocking(EXAMPLE_SPI_SLAVE, &handle, &xfer);

    while (slaveFinished != true)
    {
    }

    for (i = 0; i < BUFFER_SIZE; i++)
    {
        if (buff[i] != i)
        {
            PRINTF("\n\rThe %d number is wrong! It is %dn\r", i, buff[i]);
            err++;
        }
    }
    PRINTF("\r\n");
    if (err == 0)
    {
        PRINTF("Succeed!\n\r");
    }

    while (1)
    {
    }
}
