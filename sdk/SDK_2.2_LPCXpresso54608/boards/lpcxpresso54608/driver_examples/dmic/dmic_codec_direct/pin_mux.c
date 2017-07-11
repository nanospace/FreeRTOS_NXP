/*
 * Copyright (c) 2017, Freescale Semiconductor, Inc.
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

/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
PinsProfile:
- !!product 'Pins v2.0'
- !!processor 'LPC54608J512'
- !!package 'LPC54608J512ET180'
- !!mcu_data 'ksdk2_0'
- !!processor_version '0.0.0'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

#include "fsl_common.h"
#include "fsl_iocon.h"
#include "pin_mux.h"

#define IOCON_PIO_DIGITAL_EN        0x0100u   /*!< Enables digital function */
#define IOCON_PIO_FUNC1               0x01u   /*!< Selects pin function 1 */
#define IOCON_PIO_FUNC2               0x02u   /*!< Selects pin function 2 */
#define IOCON_PIO_FUNC3               0x03u   /*!< Selects pin function 3 */
#define IOCON_PIO_FUNC5               0x05u   /*!< Selects pin function 5 */
#define IOCON_PIO_I2CDRIVE_HIGH     0x0400u   /*!< High drive: 20 mA */
#define IOCON_PIO_I2CFILTER_DI      0x0800u   /*!< I2C 50 ns glitch filter disabled */
#define IOCON_PIO_I2CSLEW_I2C         0x00u   /*!< I2C mode */
#define IOCON_PIO_INPFILT_OFF       0x0200u   /*!< Input filter disabled */
#define IOCON_PIO_INPFILT_ON          0x00u   /*!< Input filter enabled */
#define IOCON_PIO_INV_DI              0x00u   /*!< Input function is not inverted */
#define IOCON_PIO_MODE_INACT          0x00u   /*!< No addition pin function */
#define IOCON_PIO_OPENDRAIN_DI        0x00u   /*!< Open drain is disabled */
#define IOCON_PIO_SLEW_STANDARD       0x00u   /*!< Standard mode, output slew rate control is enabled */
#define PIN0_IDX                         0u   /*!< Pin number for pin 0 in a port 3 */
#define PIN1_IDX                         1u   /*!< Pin number for pin 1 in a port 3 */
#define PIN2_IDX                         2u   /*!< Pin number for pin 2 in a port 1 */
#define PIN3_IDX                         3u   /*!< Pin number for pin 3 in a port 1 */
#define PIN11_IDX                       11u   /*!< Pin number for pin 11 in a port 3 */
#define PIN18_IDX                       18u   /*!< Pin number for pin 18 in a port 2 */
#define PIN19_IDX                       19u   /*!< Pin number for pin 19 in a port 2 */
#define PIN20_IDX                       20u   /*!< Pin number for pin 20 in a port 2 */
#define PIN23_IDX                       23u   /*!< Pin number for pin 23 in a port 3 */
#define PIN24_IDX                       24u   /*!< Pin number for pin 24 in a port 3 */
#define PIN29_IDX                       29u   /*!< Pin number for pin 29 in a port 0 */
#define PIN30_IDX                       30u   /*!< Pin number for pin 30 in a port 0 */
#define PORT0_IDX                        0u   /*!< Port index */
#define PORT1_IDX                        1u   /*!< Port index */
#define PORT2_IDX                        2u   /*!< Port index */
#define PORT3_IDX                        3u   /*!< Port index */
#define PORT4_IDX                        4u   /*!< Port index */

/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
BOARD_InitPins:
- options: {coreID: singlecore, enableClock: 'true'}
- pin_list:
  - {pin_num: B13, peripheral: FLEXCOMM0, signal: RXD_SDA_MOSI, pin_signal: PIO0_29/FC0_RXD_SDA_MOSI/CTIMER2_MAT3/SCT0_OUT8/TRACEDATA(2), mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: standard, open_drain: disabled}
  - {pin_num: A2, peripheral: FLEXCOMM0, signal: TXD_SCL_MISO, pin_signal: PIO0_30/FC0_TXD_SCL_MISO/CTIMER0_MAT0/SCT0_OUT9/TRACEDATA(1), mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: standard, open_drain: disabled}
  - {pin_num: C2, peripheral: FLEXCOMM2, signal: CTS_SDA_SSEL0, pin_signal: PIO3_23/FC2_CTS_SDA_SSEL0/UTICK_CAP3, invert: disabled, glitch_filter: disabled, i2c_slew: i2c,
    i2c_drive: high, i2c_filter: disabled}
  - {pin_num: E2, peripheral: FLEXCOMM2, signal: RTS_SCL_SSEL1, pin_signal: PIO3_24/FC2_RTS_SCL_SSEL1/CTIMER4_CAP0/USB0_VBUS, invert: disabled, glitch_filter: disabled,
    i2c_slew: i2c, i2c_drive: high, i2c_filter: disabled}
  - {pin_num: N10, peripheral: FLEXCOMM7, signal: SCK, pin_signal: PIO2_18/LCD_VD(0)/FC3_RXD_SDA_MOSI/FC7_SCK/CTIMER3_MAT0, mode: inactive, invert: disabled, glitch_filter: enabled,
    slew_rate: standard, open_drain: disabled}
  - {pin_num: P12, peripheral: FLEXCOMM7, signal: RXD_SDA_MOSI_DATA, pin_signal: PIO2_19/LCD_VD(1)/FC3_TXD_SCL_MISO/FC7_RXD_SDA_MOSI_DATA/CTIMER3_MAT1, mode: inactive,
    invert: disabled, glitch_filter: enabled, slew_rate: standard, open_drain: disabled}
  - {pin_num: P13, peripheral: FLEXCOMM7, signal: TXD_SCL_MISO_WS, pin_signal: PIO2_20/LCD_VD(2)/FC3_RTS_SCL_SSEL1/FC7_TXD_SCL_MISO_WS/CTIMER3_MAT2/CTIMER4_CAP0,
    mode: inactive, invert: disabled, glitch_filter: enabled, slew_rate: standard, open_drain: disabled}
  - {pin_num: G14, peripheral: FLEXCOMM6, signal: SCK, pin_signal: PIO4_1/FC6_SCK/SCT0_GPI2/EMC_CSN(2), mode: inactive, invert: disabled, glitch_filter: enabled,
    slew_rate: standard, open_drain: disabled}
  - {pin_num: F13, peripheral: FLEXCOMM6, signal: TXD_SCL_MISO_WS, pin_signal: PIO4_3/FC6_TXD_SCL_MISO_WS/CTIMER0_CAP3/SCT0_GPI4/EMC_DYCSN(2), mode: inactive, invert: disabled,
    glitch_filter: enabled, slew_rate: standard, open_drain: disabled}
  - {pin_num: F14, peripheral: FLEXCOMM6, signal: RXD_SDA_MOSI_DATA, pin_signal: PIO4_2/FC6_RXD_SDA_MOSI_DATA/SCT0_GPI3/EMC_CSN(3), mode: inactive, invert: disabled,
    glitch_filter: enabled, slew_rate: standard, open_drain: disabled}
  - {pin_num: B2, peripheral: SYSCON, signal: MCLK, pin_signal: PIO3_11/MCLK/FC0_SCK/FC1_SCK/TRACEDATA(3), mode: inactive, invert: disabled, glitch_filter: enabled,
    slew_rate: standard, open_drain: disabled}
  - {pin_num: D12, peripheral: DMIC0, signal: 'CLK, 0', pin_signal: PIO3_0/LCD_VD(14)/PDM0_CLK/CTIMER1_MAT0, mode: inactive, invert: disabled, glitch_filter: disabled,
    slew_rate: standard, open_drain: disabled}
  - {pin_num: D11, peripheral: DMIC0, signal: 'DATA, 0', pin_signal: PIO3_1/LCD_VD(15)/PDM0_DATA/CTIMER1_MAT1, mode: inactive, invert: disabled, glitch_filter: disabled,
    slew_rate: standard, open_drain: disabled}
  - {pin_num: L14, peripheral: DMIC0, signal: 'CLK, 1', pin_signal: PIO1_2/CAN0_TD/CTIMER0_MAT3/SCT0_GPI6/PDM1_CLK/USB1_PORTPWRN, mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: standard, open_drain: disabled}
  - {pin_num: J13, peripheral: DMIC0, signal: 'DATA, 1', pin_signal: PIO1_3/CAN0_RD/SCT0_OUT4/PDM1_DATA/USB0_PORTPWRN, mode: inactive, invert: disabled, glitch_filter: disabled,
    slew_rate: standard, open_drain: disabled}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitPins(void) {
  CLOCK_EnableClock(kCLOCK_Iocon);                           /* Enables the clock for the IOCON block. 0 = Disable; 1 = Enable.: 0x01u */

  const uint32_t port0_pin29_config = (
    IOCON_PIO_FUNC1 |                                        /* Pin is configured as FC0_RXD_SDA_MOSI */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT0_IDX, PIN29_IDX, port0_pin29_config); /* PORT0 PIN29 (coords: B13) is configured as FC0_RXD_SDA_MOSI */
  const uint32_t port0_pin30_config = (
    IOCON_PIO_FUNC1 |                                        /* Pin is configured as FC0_TXD_SCL_MISO */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT0_IDX, PIN30_IDX, port0_pin30_config); /* PORT0 PIN30 (coords: A2) is configured as FC0_TXD_SCL_MISO */
  const uint32_t port1_pin2_config = (
    IOCON_PIO_FUNC5 |                                        /* Pin is configured as PDM1_CLK */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT1_IDX, PIN2_IDX, port1_pin2_config); /* PORT1 PIN2 (coords: L14) is configured as PDM1_CLK */
  const uint32_t port1_pin3_config = (
    IOCON_PIO_FUNC5 |                                        /* Pin is configured as PDM1_DATA */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT1_IDX, PIN3_IDX, port1_pin3_config); /* PORT1 PIN3 (coords: J13) is configured as PDM1_DATA */
  const uint32_t port2_pin18_config = (
    IOCON_PIO_FUNC3 |                                        /* Pin is configured as FC7_SCK */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_ON |                                   /* Input filter enabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT2_IDX, PIN18_IDX, port2_pin18_config); /* PORT2 PIN18 (coords: N10) is configured as FC7_SCK */
  const uint32_t port2_pin19_config = (
    IOCON_PIO_FUNC3 |                                        /* Pin is configured as FC7_RXD_SDA_MOSI_DATA */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_ON |                                   /* Input filter enabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT2_IDX, PIN19_IDX, port2_pin19_config); /* PORT2 PIN19 (coords: P12) is configured as FC7_RXD_SDA_MOSI_DATA */
  const uint32_t port2_pin20_config = (
    IOCON_PIO_FUNC3 |                                        /* Pin is configured as FC7_TXD_SCL_MISO_WS */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_ON |                                   /* Input filter enabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT2_IDX, PIN20_IDX, port2_pin20_config); /* PORT2 PIN20 (coords: P13) is configured as FC7_TXD_SCL_MISO_WS */
  const uint32_t port3_pin0_config = (
    IOCON_PIO_FUNC2 |                                        /* Pin is configured as PDM0_CLK */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT3_IDX, PIN0_IDX, port3_pin0_config); /* PORT3 PIN0 (coords: D12) is configured as PDM0_CLK */
  const uint32_t port3_pin1_config = (
    IOCON_PIO_FUNC2 |                                        /* Pin is configured as PDM0_DATA */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT3_IDX, PIN1_IDX, port3_pin1_config); /* PORT3 PIN1 (coords: D11) is configured as PDM0_DATA */
  const uint32_t port3_pin11_config = (
    IOCON_PIO_FUNC1 |                                        /* Pin is configured as MCLK */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_ON |                                   /* Input filter enabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT3_IDX, PIN11_IDX, port3_pin11_config); /* PORT3 PIN11 (coords: B2) is configured as MCLK */
  const uint32_t port3_pin23_config = (
    IOCON_PIO_FUNC1 |                                        /* Pin is configured as FC2_CTS_SDA_SSEL0 */
    IOCON_PIO_I2CSLEW_I2C |                                  /* I2C mode */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_I2CDRIVE_HIGH |                                /* High drive: 20 mA */
    IOCON_PIO_I2CFILTER_DI                                   /* I2C 50 ns glitch filter disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT3_IDX, PIN23_IDX, port3_pin23_config); /* PORT3 PIN23 (coords: C2) is configured as FC2_CTS_SDA_SSEL0 */
  const uint32_t port3_pin24_config = (
    IOCON_PIO_FUNC1 |                                        /* Pin is configured as FC2_RTS_SCL_SSEL1 */
    IOCON_PIO_I2CSLEW_I2C |                                  /* I2C mode */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_I2CDRIVE_HIGH |                                /* High drive: 20 mA */
    IOCON_PIO_I2CFILTER_DI                                   /* I2C 50 ns glitch filter disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT3_IDX, PIN24_IDX, port3_pin24_config); /* PORT3 PIN24 (coords: E2) is configured as FC2_RTS_SCL_SSEL1 */
  const uint32_t port4_pin1_config = (
    IOCON_PIO_FUNC2 |                                        /* Pin is configured as FC6_SCK */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_ON |                                   /* Input filter enabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT4_IDX, PIN1_IDX, port4_pin1_config); /* PORT4 PIN1 (coords: G14) is configured as FC6_SCK */
  const uint32_t port4_pin2_config = (
    IOCON_PIO_FUNC2 |                                        /* Pin is configured as FC6_RXD_SDA_MOSI_DATA */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_ON |                                   /* Input filter enabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT4_IDX, PIN2_IDX, port4_pin2_config); /* PORT4 PIN2 (coords: F14) is configured as FC6_RXD_SDA_MOSI_DATA */
  const uint32_t port4_pin3_config = (
    IOCON_PIO_FUNC2 |                                        /* Pin is configured as FC6_TXD_SCL_MISO_WS */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_ON |                                   /* Input filter enabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT4_IDX, PIN3_IDX, port4_pin3_config); /* PORT4 PIN3 (coords: F13) is configured as FC6_TXD_SCL_MISO_WS */
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
