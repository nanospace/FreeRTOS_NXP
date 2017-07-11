/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016 NXP
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
#include "fsl_i2c.h"
#include "fsl_i2s.h"
#include "fsl_wm8904.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
* Code
******************************************************************************/
void BOARD_I2C_Init(uint32_t boardI2CClock, I2C_Type *I2CBase)
{
    i2c_master_config_t i2cConfig;
    I2C_MasterGetDefaultConfig(&i2cConfig);
    i2cConfig.baudRate_Bps = WM8904_I2C_BITRATE;
    I2C_MasterInit(I2CBase, &i2cConfig, boardI2CClock);
}

void BOARD_SAI_TxInit(I2S_Type *SAIBase)
{
    static i2s_config_t s_TxConfig;

    I2S_TxGetDefaultConfig(&s_TxConfig);
    s_TxConfig.divider =
        CLOCK_GetAudioPllOutFreq() / 16000U / 16U / 2U; /* This should be changed to 48000 if sampling rate is 48k */

    I2S_TxInit(SAIBase, &s_TxConfig);
}

void BOARD_Codec_Init(I2C_Type *I2CBase)
{
    wm8904_config_t codecConfig;
    wm8904_handle_t codecHandle;

    WM8904_GetDefaultConfig(&codecConfig);
    codecConfig.format.sampleRate = kWM8904_SampleRate16kHz;
    codecHandle.i2c = I2CBase;
    if (WM8904_Init(&codecHandle, &codecConfig) != kStatus_Success)
    {
        return;
    }
    /* Initial volume kept low for hearing safety. */
    /* Adjust it to your needs, 0x0006 for -51 dB, 0x0039 for 0 dB etc. */
    WM8904_SetVolume(&codecHandle, 0x0025, 0x0025);
}

void BOARD_I2S_Enable(I2S_Type *SAIBase)
{
    NVIC_EnableIRQ((IRQn_Type)FLEXCOMM6_IRQn);
    /*  Enable interrupt */
    I2S_EnableInterrupts(SAIBase, kI2S_TxErrorFlag | kI2S_TxLevelFlag);
    I2S_Enable(SAIBase);
}
