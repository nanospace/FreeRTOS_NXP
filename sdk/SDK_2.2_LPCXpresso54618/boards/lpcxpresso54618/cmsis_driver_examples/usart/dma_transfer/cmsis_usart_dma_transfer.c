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

#include "board.h"

#include "pin_mux.h"
#include <stdbool.h>
#include "fsl_usart_cmsis.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DEMO_USART Driver_USART0
#define ECHO_BUFFER_LENGTH 8

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

uint8_t g_tipString[] = "USART DMA example\r\nSend back received data\r\nEcho every 8 characters\r\n";
uint8_t g_txBuffer[ECHO_BUFFER_LENGTH] = {0};
uint8_t g_rxBuffer[ECHO_BUFFER_LENGTH] = {0};
volatile bool rxBufferEmpty = true;
volatile bool txBufferFull = false;
volatile bool txOnGoing = false;
volatile bool rxOnGoing = false;

/*******************************************************************************
 * Code
 ******************************************************************************/
uint32_t USART0_GetFreq(void)
{
    return CLOCK_GetFreq(kCLOCK_Flexcomm0);
}
uint32_t USART1_GetFreq(void)
{
    return CLOCK_GetFreq(kCLOCK_Flexcomm1);
}
uint32_t USART2_GetFreq(void)
{
    return CLOCK_GetFreq(kCLOCK_Flexcomm2);
}
uint32_t USART3_GetFreq(void)
{
    return CLOCK_GetFreq(kCLOCK_Flexcomm3);
}
uint32_t USART4_GetFreq(void)
{
    return CLOCK_GetFreq(kCLOCK_Flexcomm4);
}
uint32_t USART5_GetFreq(void)
{
    return CLOCK_GetFreq(kCLOCK_Flexcomm5);
}
uint32_t USART6_GetFreq(void)
{
    return CLOCK_GetFreq(kCLOCK_Flexcomm6);
}
uint32_t USART7_GetFreq(void)
{
    return CLOCK_GetFreq(kCLOCK_Flexcomm7);
}
uint32_t USART8_GetFreq(void)
{
    return CLOCK_GetFreq(kCLOCK_Flexcomm8);
}
uint32_t USART9_GetFreq(void)
{
    return CLOCK_GetFreq(kCLOCK_Flexcomm9);
}

/* USART  callback */
void USART_Callback(uint32_t event)
{
    if (event == ARM_USART_EVENT_SEND_COMPLETE)
    {
        txBufferFull = false;
        txOnGoing = false;
    }

    if (event == ARM_USART_EVENT_RECEIVE_COMPLETE)
    {
        rxBufferEmpty = false;
        rxOnGoing = false;
    }
}

/*!
 * @brief Main function
 */
int main(void)
{
    /* attach 12 MHz clock to FLEXCOMM0 (debug console) */
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);

    USART0_InitPins();
    BOARD_BootClockFROHF48M();

    DMA_Init(DMA0);
    DEMO_USART.Initialize(USART_Callback);
    DEMO_USART.PowerControl(ARM_POWER_FULL);

    /* Set baudrate. */
    DEMO_USART.Control(ARM_USART_MODE_ASYNCHRONOUS, BOARD_DEBUG_UART_BAUDRATE);

    /* Send g_tipString out. */
    txOnGoing = true;

    DEMO_USART.Send(g_tipString, sizeof(g_tipString) - 1);

    /* Wait send finished */
    while (txOnGoing)
    {
    }

    while (1)
    {
        /* If RX is idle and g_rxBuffer is empty, start to read data to g_rxBuffer. */
        if ((!rxOnGoing) && rxBufferEmpty)
        {
            rxOnGoing = true;
            DEMO_USART.Receive(g_rxBuffer, ECHO_BUFFER_LENGTH);
        }

        /* If TX is idle and g_txBuffer is full, start to send data. */
        if ((!txOnGoing) && txBufferFull)
        {
            txOnGoing = true;
            DEMO_USART.Send(g_txBuffer, ECHO_BUFFER_LENGTH);
        }

        /* If g_txBuffer is empty and g_rxBuffer is full, copy g_rxBuffer to g_txBuffer. */
        if ((!rxBufferEmpty) && (!txBufferFull))
        {
            memcpy(g_txBuffer, g_rxBuffer, ECHO_BUFFER_LENGTH);
            rxBufferEmpty = true;
            txBufferFull = true;
        }
    }
}