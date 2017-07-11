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

/*  Standard C Included Files */
#include <stdio.h>
#include <string.h>
#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_i2c.h"

#include "pin_mux.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define EXAMPLE_I2C_MASTER_BASE (I2C9_BASE)
#define EXAMPLE_I2C_SLAVE_BASE (I2C8_BASE)
#define I2C_MASTER_CLOCK_FREQUENCY (12000000)
#define I2C_SLAVE_CLOCK_FREQUENCY (12000000)

#define EXAMPLE_I2C_MASTER ((I2C_Type *)EXAMPLE_I2C_MASTER_BASE)
#define EXAMPLE_I2C_SLAVE ((I2C_Type *)EXAMPLE_I2C_SLAVE_BASE)

#define I2C_MASTER_SLAVE_ADDR_7BIT (0x50U)
#define I2C_BAUDRATE (100000) /* 100K */
#define I2C_DATA_LENGTH (32)  /* MAX is 256 */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

uint8_t g_slave_buff[I2C_DATA_LENGTH];
uint8_t g_master_buff[I2C_DATA_LENGTH];

i2c_master_handle_t g_m_handle;
i2c_slave_handle_t g_s_handle;

volatile bool g_slaveCompleted = false;
volatile bool g_masterCompleted = false;

/*******************************************************************************
 * Code
 ******************************************************************************/

static void i2c_slave_callback(I2C_Type *base, volatile i2c_slave_transfer_t *xfer, void *param)
{
    switch (xfer->event)
    {
        /* Setup the slave receive buffer */
        case kI2C_SlaveReceiveEvent:
            xfer->rxData = g_slave_buff;
            xfer->rxSize = I2C_DATA_LENGTH;
            break;

        /* The master has sent a stop transition on the bus */
        case kI2C_SlaveCompletionEvent:
            g_slaveCompleted = true;
            break;

        /* Transmit event not handled in this demo */
        case kI2C_SlaveTransmitEvent:
        default:
            break;
    }
}

/*!
 * @brief Main function
 */
int main(void)
{
    uint32_t i = 0;
    i2c_slave_config_t slaveConfig;
    i2c_master_transfer_t masterXfer = {0};
    status_t reVal = kStatus_Fail;

    /* attach 12 MHz clock to FLEXCOMM0 (debug console) */
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);

    /* attach 12 MHz clock to FLEXCOMM9 (I2C master) */
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM9);

    /* attach 12 MHz clock to FLEXCOMM8 (I2C slave) */
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM8);

    /* reset FLEXCOMM for I2C */
    RESET_PeripheralReset(kFC9_RST_SHIFT_RSTn);
    RESET_PeripheralReset(kFC8_RST_SHIFT_RSTn);

    BOARD_InitPins();
    BOARD_BootClockFROHF48M();
    BOARD_InitDebugConsole();

    PRINTF("\r\nI2C example -- MasterInterrupt_SlaveInterrupt.\r\n");

/*  Set i2c slave interrupt priority higher. */
#if (EXAMPLE_I2C_SLAVE_BASE == I2C0_BASE)
    NVIC_SetPriority(I2C0_IRQn, 0);
#elif(EXAMPLE_I2C_SLAVE_BASE == I2C1_BASE)
    NVIC_SetPriority(I2C1_IRQn, 0);
#elif(EXAMPLE_I2C_SLAVE_BASE == I2C2_BASE)
#if defined(FSL_FEATURE_INTMUX_IRQ_START_INDEX)
    /* Don't try to set I2C2 IRQ priority if it is an INTMUX IRQ */
    if (I2C2_IRQn < FSL_FEATURE_INTMUX_IRQ_START_INDEX)
#endif /* FSL_FEATURE_INTMUX_IRQ_START_INDEX */
    {
        NVIC_SetPriority(I2C2_IRQn, 0);
    }
#endif

#if (EXAMPLE_I2C_MASTER_BASE == I2C0_BASE)
    NVIC_SetPriority(I2C0_IRQn, 1);
#elif(EXAMPLE_I2C_MASTER_BASE == I2C1_BASE)
    NVIC_SetPriority(I2C1_IRQn, 1);
#elif(EXAMPLE_I2C_MASTER_BASE == I2C2_BASE)
#if defined(FSL_FEATURE_INTMUX_IRQ_START_INDEX)
    /* Don't try to set I2C2 IRQ priority if it is an INTMUX IRQ */
    if (I2C2_IRQn < FSL_FEATURE_INTMUX_IRQ_START_INDEX)
    {
#endif /* FSL_FEATURE_INTMUX_IRQ_START_INDEX */
        NVIC_SetPriority(I2C2_IRQn, 1);
    }
#endif

    /* Set up i2c slave first*/
    I2C_SlaveGetDefaultConfig(&slaveConfig);

    /* Change the slave address */
    slaveConfig.address0.address = I2C_MASTER_SLAVE_ADDR_7BIT;

    /* Initialize the I2C slave peripheral */
    I2C_SlaveInit(EXAMPLE_I2C_SLAVE, &slaveConfig, I2C_SLAVE_CLOCK_FREQUENCY);

    memset(g_slave_buff, 0, sizeof(g_slave_buff));

    /* Create the I2C handle for the non-blocking transfer */
    I2C_SlaveTransferCreateHandle(EXAMPLE_I2C_SLAVE, &g_s_handle, i2c_slave_callback, NULL);

    /* Start accepting I2C transfers on the I2C slave peripheral */
    reVal = I2C_SlaveTransferNonBlocking(EXAMPLE_I2C_SLAVE, &g_s_handle,
                                         kI2C_SlaveReceiveEvent | kI2C_SlaveCompletionEvent);
    if (reVal != kStatus_Success)
    {
        return -1;
    }

    /* Set up i2c master to send data to slave*/
    for (i = 0; i < I2C_DATA_LENGTH; i++)
    {
        g_master_buff[i] = i;
    }

    /* Display the data the master will send */
    PRINTF("Master will send data :");
    for (i = 0; i < I2C_DATA_LENGTH; i++)
    {
        if (i % 8 == 0)
        {
            PRINTF("\r\n");
        }
        PRINTF("0x%2x  ", g_master_buff[i]);
    }

    PRINTF("\r\n\r\n");

    i2c_master_config_t masterConfig;

    /*
     * masterConfig.debugEnable = false;
     * masterConfig.ignoreAck = false;
     * masterConfig.pinConfig = kI2C_2PinOpenDrain;
     * masterConfig.baudRate_Bps = 100000U;
     * masterConfig.busIdleTimeout_ns = 0;
     * masterConfig.pinLowTimeout_ns = 0;
     * masterConfig.sdaGlitchFilterWidth_ns = 0;
     * masterConfig.sclGlitchFilterWidth_ns = 0;
     */
    I2C_MasterGetDefaultConfig(&masterConfig);

    /* Change the default baudrate configuration */
    masterConfig.baudRate_Bps = I2C_BAUDRATE;

    /* Initialize the I2C master peripheral */
    I2C_MasterInit(EXAMPLE_I2C_MASTER, &masterConfig, I2C_MASTER_CLOCK_FREQUENCY);

    /* Create the I2C handle for the non-blocking transfer */
    I2C_MasterTransferCreateHandle(EXAMPLE_I2C_MASTER, &g_m_handle, NULL, NULL);

    /* Setup the master transfer */
    masterXfer.slaveAddress = I2C_MASTER_SLAVE_ADDR_7BIT;
    masterXfer.direction = kI2C_Write;
    masterXfer.subaddress = 0;
    masterXfer.subaddressSize = 0;
    masterXfer.data = g_master_buff;
    masterXfer.dataSize = I2C_DATA_LENGTH;
    masterXfer.flags = kI2C_TransferDefaultFlag;

    /* Send master non-blocking data to slave */
    reVal = I2C_MasterTransferNonBlocking(EXAMPLE_I2C_MASTER, &g_m_handle, &masterXfer);
    if (reVal != kStatus_Success)
    {
        return -1;
    }

    /* Wait for the transfer to complete. */
    while (!g_slaveCompleted)
    {
    }

    /* Transfer completed. Check the data. */
    for (i = 0; i < I2C_DATA_LENGTH; i++)
    {
        if (g_slave_buff[i] != g_master_buff[i])
        {
            PRINTF("\r\nError occured in this transfer ! \r\n");
            break;
        }
    }

    /* Check if we matched on all of the bytes */
    if (i == I2C_DATA_LENGTH)
    {
        PRINTF("\r\n Transfer successful!\r\n ");
    }

    /* Display the slave data */
    PRINTF("\r\nSlave received data :");
    for (i = 0; i < I2C_DATA_LENGTH; i++)
    {
        if (i % 8 == 0)
        {
            PRINTF("\r\n");
        }
        PRINTF("0x%2x  ", g_slave_buff[i]);
    }
    PRINTF("\r\n\r\n");

    /* Hang at the end */
    while (1)
    {
    }
}
