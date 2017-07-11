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
#include <stdlib.h>
#include <string.h>
#include "fsl_debug_console.h"
#include "fsl_enet.h"
#include "fsl_phy.h"

#include "pin_mux.h"
#include "board.h"
#include <stdbool.h>
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define EXAMPLE_ENET_BASE ENET
#define EXAMPLE_PHY_ADDR (0x00U)
#define ENET_EXAMPLE_IRQ ETHERNET_IRQn 

#define ENET_RXBD_NUM (4)
#define ENET_TXBD_NUM (4)
#define ENET_RXBUFF_SIZE (ENET_FRAME_MAX_FRAMELEN)
#define ENET_BuffSizeAlign(n) ENET_ALIGN(n, ENET_BUFF_ALIGNMENT)
#define ENET_ALIGN(x, align) ((unsigned int)((x) + ((align)-1)) & (unsigned int)(~(unsigned int)((align)-1)))
#define ENET_EXAMPLE_FRAME_HEADSIZE (14U)
#define ENET_EXAMPLE_DATA_LENGTH (1000U)
#define ENET_EXAMPLE_FRAME_SIZE (ENET_EXAMPLE_DATA_LENGTH + ENET_EXAMPLE_FRAME_HEADSIZE)
#define ENET_EXAMPLE_PACKAGETYPE (4U)
#define ENET_EXAMPLE_SEND_COUNT (20U)

#if defined(__GNUC__)
#ifndef __ALIGN_END
#define __ALIGN_END __attribute__((aligned(ENET_BUFF_ALIGNMENT)))
#endif
#ifndef __ALIGN_BEGIN
#define __ALIGN_BEGIN
#endif
#else
#ifndef __ALIGN_END
#define __ALIGN_END
#endif
#ifndef __ALIGN_BEGIN
#if defined(__CC_ARM)
#define __ALIGN_BEGIN __align(ENET_BUFF_ALIGNMENT)
#elif defined(__ICCARM__)
#define __ALIGN_BEGIN
#endif
#endif
#endif
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void ENET_BuildBroadCastFrame(void);
static void ENET_TXReclaim(void);
static status_t ENET_TXQueue(uint8_t *data, uint16_t length);
static uint8_t *ENET_RXRead(int32_t *length);
static void ENET_RXClaim(uint8_t *buffer);

/*******************************************************************************
 * Variables
 ******************************************************************************/
#if defined(__ICCARM__)
#pragma data_alignment = ENET_BUFF_ALIGNMENT
#endif
__ALIGN_BEGIN enet_rx_bd_struct_t g_rxBuffDescrip[ENET_RXBD_NUM] __ALIGN_END;
#if defined(__ICCARM__)
#pragma data_alignment = ENET_BUFF_ALIGNMENT
#endif
__ALIGN_BEGIN enet_tx_bd_struct_t g_txBuffDescrip[ENET_TXBD_NUM] __ALIGN_END;

enet_handle_t g_handle = {0};
/* The MAC address for ENET device. */
uint8_t g_macAddr[6] = {0xd4, 0xbe, 0xd9, 0x45, 0x22, 0x60};
uint8_t multicastAddr[6] = {0x01, 0x00, 0x5e, 0x00, 0x01, 0x81};
uint8_t g_frame[ENET_EXAMPLE_PACKAGETYPE][ENET_EXAMPLE_FRAME_SIZE];
uint8_t *g_txbuff[ENET_TXBD_NUM];
uint32_t g_txIdx = 0;
uint8_t g_txbuffIdx = 0;
uint8_t g_txGenIdx = 0;
uint8_t g_txCosumIdx = 0;
uint8_t g_txUsed = 0;
uint8_t g_rxGenIdx = 0;
uint32_t g_rxCosumIdx = 0;
uint32_t g_testIdx = 0;
uint32_t g_rxbuffer[ENET_RXBD_NUM];

/*******************************************************************************
 * Code
 ******************************************************************************/
int main(void)
{
    enet_config_t config;
    uint8_t index;
    void *buff;
    uint32_t refClock = 50000000; /* 50MHZ for rmii reference clock. */
    phy_speed_t speed;
    phy_duplex_t duplex;
    int32_t length = 0;
    uint8_t *buffer;
    uint8_t *data;
    uint32_t timedelay;
    status_t status;
    bool link=false;

    for (index = 0; index < ENET_RXBD_NUM; index++)
    {
        /* This is for rx buffers, static alloc and dynamic alloc both ok. use as your wish. */
        buff = malloc(ENET_RXBUFF_SIZE);
        if (buff)
        {
            g_rxbuffer[index] = (uint32_t)buff;
        }
        else
        {
            PRINTF("Mem Alloc fail\r\n");
        }
    }

    /* prepare the buffer configuration. */
    enet_buffer_config_t buffConfig = {
        ENET_RXBD_NUM,       
        ENET_TXBD_NUM,
        &g_txBuffDescrip[0], 
        &g_txBuffDescrip[0],
        &g_rxBuffDescrip[0], 
        &g_rxBuffDescrip[ENET_RXBD_NUM],
        &g_rxbuffer[0],        
        ENET_BuffSizeAlign(ENET_RXBUFF_SIZE),
    };

    /* Hardware Initialization. */
    CLOCK_EnableClock(kCLOCK_InputMux);
    /* attach 12 MHz clock to FLEXCOMM0 (debug console) */
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);

    BOARD_InitPins();
    BOARD_BootClockFROHF48M();
    BOARD_InitDebugConsole();

    PRINTF("\r\nENET example start.\r\n");

    status = PHY_Init(EXAMPLE_ENET_BASE, EXAMPLE_PHY_ADDR, 0);
    if (status == kStatus_Success)
    {
        PHY_GetLinkSpeedDuplex(EXAMPLE_ENET_BASE, EXAMPLE_PHY_ADDR, &speed, &duplex);
        /* Use the actual speed and duplex when phy success to finish the autonegotiation. */
        config.miiSpeed = (enet_mii_speed_t)speed;
        config.miiDuplex = (enet_mii_duplex_t)duplex;
    } 

    /* Wait for link up and get the actual PHY link speed. */
    PHY_GetLinkStatus(EXAMPLE_ENET_BASE, EXAMPLE_PHY_ADDR, &link);
    while (!link)
    {
        PRINTF("\r\nLink down, please check the cable connection and test will start when link up\r\n");
        for (timedelay = 0; timedelay < 0xFFFFFU; timedelay++)
        {
            __ASM("nop");
        }
        PHY_GetLinkStatus(EXAMPLE_ENET_BASE, EXAMPLE_PHY_ADDR, &link);
    }        


    /* Get default configuration 100M RMII. */
    ENET_GetDefaultConfig(&config);

    /* Initialize ENET. */
    ENET_Init(EXAMPLE_ENET_BASE, &config, &g_macAddr[0], refClock);

    /* Enable the tx/rx interrupt. */
    ENET_EnableInterrupts(EXAMPLE_ENET_BASE, (kENET_DmaTx));
    EnableIRQ(ENET_EXAMPLE_IRQ);

    /* Initialize Descriptor. */
    ENET_DescriptorInit(EXAMPLE_ENET_BASE, &config, &buffConfig);

    /* Active TX/RX. */
    ENET_StartRxTx(EXAMPLE_ENET_BASE, 1, 1);

    /* Build broadcast for sending and active for receiving. */
    ENET_BuildBroadCastFrame();

    PRINTF("\r\nTransmission start now!\r\n");

    while (1)
    {
        length = 0;
        data = ENET_RXRead(&length);
        if (length > 0)
        {
            void *buffer;
            /* Update the buffers and then we can delivery the previous buffer diectly to
             the application without memcpy. */
            buffer = malloc(ENET_RXBUFF_SIZE);
            if (buffer)
            { 
                ENET_RXClaim(buffer);
            }
            else
            {
                ENET_RXClaim(NULL);
                PRINTF("Mem alloc fail\r\n");
            }
            
            PRINTF(" One frame received. the length %d \r\n", length);
            PRINTF(" Dest Address %02x:%02x:%02x:%02x:%02x:%02x Src Address %02x:%02x:%02x:%02x:%02x:%02x \r\n",
                   data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8], data[9], data[10],
                   data[11]);

            /* Free the used one. */
            free(data);
        }
        else if (length < 0)
        {
             ENET_RXClaim(NULL);
        }

        if (g_testIdx < ENET_EXAMPLE_SEND_COUNT)
        {
            /* Send a multicast frame when the PHY is link up. */
            PHY_GetLinkStatus(EXAMPLE_ENET_BASE, EXAMPLE_PHY_ADDR, &link);
            if (link)
            {
                /* Create the buffer for zero-copy transmit. */
                buffer = (uint8_t *)malloc(ENET_EXAMPLE_FRAME_SIZE);
                if (buffer)
                {
                    memcpy(buffer, &g_frame[g_txIdx], ENET_EXAMPLE_FRAME_SIZE);
                    /* Make each transmit different.*/
                    g_txIdx = (g_txIdx + 1) % ENET_EXAMPLE_PACKAGETYPE;

                    /* Store the buffer for mem free. */
                    g_txbuff[g_txbuffIdx] = buffer;
                    g_txbuffIdx = (g_txbuffIdx + 1) % ENET_TXBD_NUM;
                    /* Send the frame out (wait unitl the descriptor ready). */
                    while (ENET_TXQueue(buffer, ENET_EXAMPLE_FRAME_SIZE) != kStatus_Success)
                        ;
                    g_testIdx++;
                    PRINTF("The %d-th frame transmitted success!\r\n", g_testIdx);
                }
                else
                {
                    PRINTF("No available tx buffers\r\n");
                }
            }
            else
            {
                PRINTF(" \r\nThe PHY link down!\r\n");
            }
        }
    }
}

/*! @brief Build Frame for transmit. */
static void ENET_BuildBroadCastFrame(void)
{
    uint32_t count = 0;
    uint32_t index = 0;

    /* Create different transmit frames. */
    for (index = 0; index < ENET_EXAMPLE_PACKAGETYPE; index++)
    {
        for (count = 0; count < 6U; count++)
        {
            g_frame[index][count] = 0xFFU;
        }
        memcpy(&g_frame[index][6], &g_macAddr[0], 6U);
        g_frame[index][12] = (ENET_EXAMPLE_DATA_LENGTH >> 8) & 0xFFU;
        g_frame[index][13] = ENET_EXAMPLE_DATA_LENGTH & 0xFFU;

        for (count = ENET_EXAMPLE_FRAME_HEADSIZE; count < ENET_EXAMPLE_FRAME_SIZE; count++)
        {
            g_frame[index][count] = (count + index) % 0xFFU;
        }
    }
}

void ETHERNET_IRQHandler(void)
{
    /* Check for the interrupt source type. */
    /* DMA CHANNEL 0. */
    uint32_t status;
    status = ENET_GetDmaInterruptStatus(EXAMPLE_ENET_BASE, 0);
    if (status)
    {
        if (status & kENET_DmaTx)
        {
            ENET_TXReclaim();
        }
        /* Clear the interrupt. */
        ENET_ClearDmaInterruptStatus(EXAMPLE_ENET_BASE, 0, status);
    }
}

static uint8_t *ENET_RXRead(int32_t *length)
{
    uint32_t control;
    uint8_t *data;
    *length = 0;
    
    /* Get the Frame size */
    control = ENET_GetRxDescriptor(&g_rxBuffDescrip[g_rxGenIdx]);
    if (!(control & ENET_RXDESCRIP_RD_OWN_MASK))
    {
        if (control & ENET_RXDESCRIP_WR_LD_MASK)
        {
            /* if no error */
            if (control & ENET_RXDESCRIP_WR_ERRSUM_MASK)
            {
                *length = -1;
            }
            else{
                *length = control & ENET_RXDESCRIP_WR_PACKETLEN_MASK;
                data = (uint8_t *)g_rxbuffer[g_rxGenIdx];
            }
            g_rxGenIdx = (g_rxGenIdx + 1) % ENET_RXBD_NUM;
        }
    }   
    return data;
}

static void ENET_RXClaim(uint8_t* buffer)
{
    if (ENET_GetDmaInterruptStatus(EXAMPLE_ENET_BASE, 0) & kENET_DmaRxBuffUnavail)
    {
        ENET_UpdateRxDescriptor(&g_rxBuffDescrip[g_rxCosumIdx], buffer, NULL, false, false);                    
        /* Command for rx poll when the dma suspend. */
        ENET_UpdateRxDescriptorTail(EXAMPLE_ENET_BASE, 0, (uint32_t)&g_rxBuffDescrip[ENET_RXBD_NUM]);                
    }
    else
    {
        ENET_UpdateRxDescriptor(&g_rxBuffDescrip[g_rxCosumIdx], buffer, NULL, false, false);     
    }

    if (buffer)
    {
        g_rxbuffer[g_rxCosumIdx] = (uint32_t)buffer;
    }
  
    g_rxCosumIdx = (g_rxCosumIdx + 1) % ENET_RXBD_NUM;    
}

static status_t ENET_TXQueue(uint8_t *data, uint16_t length)
{
    uint32_t txdescTailAddr;

    /* Fill the descriptor. */
    if (ENET_IsTxDescriptorDmaOwn(&g_txBuffDescrip[g_txGenIdx]))
    {
        return kStatus_Fail;
    }
    ENET_SetupTxDescriptor(&g_txBuffDescrip[g_txGenIdx], data, length, NULL, 0, length, true, false, kENET_FirstLastFlag, 0);

    /* Increase the index. */
    g_txGenIdx = (g_txGenIdx + 1) % ENET_TXBD_NUM;
    g_txUsed++;

    /* Update the transmit tail address. */
    txdescTailAddr = (uint32_t)&g_txBuffDescrip[g_txGenIdx];
    if (!g_txGenIdx)
    {
        txdescTailAddr = (uint32_t)&g_txBuffDescrip[ENET_TXBD_NUM];
    }
    ENET_UpdateTxDescriptorTail(EXAMPLE_ENET_BASE, 0, txdescTailAddr);
    return kStatus_Success;
}

static void ENET_TXReclaim()
{
    if (!ENET_IsTxDescriptorDmaOwn(&g_txBuffDescrip[g_txCosumIdx]) && (g_txUsed > 0))
    {
        /* Free tx buffers. */
        free(g_txbuff[g_txCosumIdx]);
        g_txUsed--;
        g_txCosumIdx = (g_txCosumIdx + 1) % ENET_TXBD_NUM;
    }
}
