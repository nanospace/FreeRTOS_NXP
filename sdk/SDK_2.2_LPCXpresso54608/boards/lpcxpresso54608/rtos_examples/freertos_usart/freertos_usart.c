/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
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

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"

#include "fsl_usart_freertos.h"
#include "fsl_usart.h"

#include "pin_mux.h"
#include <stdbool.h>
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DEMO_USART USART0
#define DEMO_USART_IRQHandler FLEXCOMM0_IRQHandler
#define DEMO_USART_IRQn FLEXCOMM0_IRQn
/* Task priorities. */
#define uart_task_PRIORITY (configMAX_PRIORITIES - 1)
#define USART_NVIC_PRIO 5
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void uart_task(void *pvParameters);

/*******************************************************************************
 * Code
 ******************************************************************************/
const char *to_send = "FreeRTOS USART driver example!\r\n";
const char *send_buffer_overrun = "\r\nRing buffer overrun!\r\n";
uint8_t background_buffer[32];
uint8_t recv_buffer[4];

usart_rtos_handle_t handle;
struct _usart_handle t_handle;

struct rtos_usart_config usart_config = {
    .baudrate = 115200,
    .parity = kUSART_ParityDisabled,
    .stopbits = kUSART_OneStopBit,
    .buffer = background_buffer,
    .buffer_size = sizeof(background_buffer),
};

/*!
 * @brief Application entry point.
 */
int main(void)
{
    /* Init board hardware. */
    /* attach 12 MHz clock to FLEXCOMM0 (debug console) */
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);

    BOARD_InitPins();
    // BOARD_BootClockFROHF48M();
    BOARD_InitDebugConsole();

    xTaskCreate(uart_task, "Uart_task", configMINIMAL_STACK_SIZE + 10, NULL, uart_task_PRIORITY, NULL);

    vTaskStartScheduler();
    for (;;)
        ;
}

/*!
 * @brief Task responsible for printing of "Hello world." message.
 */
static void uart_task(void *pvParameters)
{
    int error;
    size_t n;

    usart_config.srcclk = BOARD_DEBUG_UART_CLK_FREQ;
    usart_config.base = DEMO_USART;

    NVIC_SetPriority(DEMO_USART_IRQn, USART_NVIC_PRIO);

    if (0 > USART_RTOS_Init(&handle, &t_handle, &usart_config))
    {
        vTaskSuspend(NULL);
    }

    /* Send some data */
    if (0 > USART_RTOS_Send(&handle, (uint8_t *)to_send, strlen(to_send)))
    {
        vTaskSuspend(NULL);
    }

    /* Send data */
    do
    {
        error = USART_RTOS_Receive(&handle, recv_buffer, sizeof(recv_buffer), &n);
        if (error == kStatus_USART_RxRingBufferOverrun)
        {
            /* Notify about hardware buffer overrun */
            if (kStatus_Success !=
                USART_RTOS_Send(&handle, (uint8_t *)send_buffer_overrun, strlen(send_buffer_overrun)))
            {
                vTaskSuspend(NULL);
            }
        }
        if (n > 0)
        {
            /* send back the received data */
            USART_RTOS_Send(&handle, (uint8_t *)recv_buffer, n);
        }
        vTaskDelay(1000);
    } while (kStatus_Success == error);

    USART_RTOS_Deinit(&handle);

    vTaskSuspend(NULL);
}
