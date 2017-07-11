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

#ifndef __RTE_DEVICE_H
#define __RTE_DEVICE_H

/* Driver name mapping. */
#define RTE_USART0 1
#define RTE_USART0_DMA_EN 0
#define RTE_USART1 0
#define RTE_USART1_DMA_EN 0
#define RTE_USART2 0
#define RTE_USART2_DMA_EN 0
#define RTE_USART3 0
#define RTE_USART3_DMA_EN 0
#define RTE_USART4 0
#define RTE_USART4_DMA_EN 0
#define RTE_USART5 0
#define RTE_USART5_DMA_EN 0
#define RTE_USART6 0
#define RTE_USART6_DMA_EN 0
#define RTE_USART7 0
#define RTE_USART7_DMA_EN 0
#define RTE_USART8 0
#define RTE_USART8_DMA_EN 0
#define RTE_USART9 0
#define RTE_USART9_DMA_EN 0

/* USART configuration. */
#define USART_RX_BUFFER_LEN 64
#define USART0_RX_BUFFER_ENABLE 1
#define USART1_RX_BUFFER_ENABLE 0
#define USART2_RX_BUFFER_ENABLE 0
#define USART3_RX_BUFFER_ENABLE 0
#define USART4_RX_BUFFER_ENABLE 0
#define USART5_RX_BUFFER_ENABLE 0
#define USART6_RX_BUFFER_ENABLE 0
#define USART7_RX_BUFFER_ENABLE 0
#define USART8_RX_BUFFER_ENABLE 0
#define USART9_RX_BUFFER_ENABLE 0

#define RTE_USART0_DMA_TX_CH 1
#define RTE_USART0_DMA_TX_DMA_BASE DMA0
#define RTE_USART0_DMA_RX_CH 0
#define RTE_USART0_DMA_RX_DMA_BASE DMA0

#define RTE_USART1_DMA_TX_CH 3
#define RTE_USART1_DMA_TX_DMA_BASE DMA0
#define RTE_USART1_DMA_RX_CH 2
#define RTE_USART1_DMA_RX_DMA_BASE DMA0

#define RTE_USART2_DMA_TX_CH 5
#define RTE_USART2_DMA_TX_DMA_BASE DMA0
#define RTE_USART2_DMA_RX_CH 4
#define RTE_USART2_DMA_RX_DMA_BASE DMA0

#define RTE_USART3_DMA_TX_CH 7
#define RTE_USART3_DMA_TX_DMA_BASE DMA0
#define RTE_USART3_DMA_RX_CH 6
#define RTE_USART3_DMA_RX_DMA_BASE DMA0

#define RTE_USART4_DMA_TX_CH 9
#define RTE_USART4_DMA_TX_DMA_BASE DMA0
#define RTE_USART4_DMA_RX_CH 8
#define RTE_USART4_DMA_RX_DMA_BASE DMA0

#define RTE_USART5_DMA_TX_CH 11
#define RTE_USART5_DMA_TX_DMA_BASE DMA0
#define RTE_USART5_DMA_RX_CH 10
#define RTE_USART5_DMA_RX_DMA_BASE DMA0

#define RTE_USART6_DMA_TX_CH 13
#define RTE_USART6_DMA_TX_DMA_BASE DMA0
#define RTE_USART6_DMA_RX_CH 12
#define RTE_USART6_DMA_RX_DMA_BASE DMA0

#define RTE_USART7_DMA_TX_CH 15
#define RTE_USART7_DMA_TX_DMA_BASE DMA0
#define RTE_USART7_DMA_RX_CH 14
#define RTE_USART7_DMA_RX_DMA_BASE DMA0

#define RTE_USART8_DMA_TX_CH 17
#define RTE_USART8_DMA_TX_DMA_BASE DMA0
#define RTE_USART8_DMA_RX_CH 16
#define RTE_USART8_DMA_RX_DMA_BASE DMA0

#define RTE_USART9_DMA_TX_CH 19
#define RTE_USART9_DMA_TX_DMA_BASE DMA0
#define RTE_USART9_DMA_RX_CH 18
#define RTE_USART9_DMA_RX_DMA_BASE DMA0

#endif /* __RTE_DEVICE_H */
