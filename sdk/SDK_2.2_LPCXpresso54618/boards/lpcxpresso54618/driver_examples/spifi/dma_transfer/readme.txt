Overview
========
The SPIFI DMA Example project is a demonstration program that uses the KSDK software to program external serial
flash using DMA and read through AHB bus.


Toolchain supported
===================
- IAR embedded Workbench 7.80.4
- Keil MDK 5.21a
- MCUXpresso0.8

Hardware requirements
=====================
- Micro USB cable
- LPCXpresso54618 board
- Personal Computer

Board settings
==============
No special settings are required.

Prepare the Demo
================
Connect a serial cable from the debug UART port of the board to the PC. Start Tera Term
(http://ttssh2.osdn.jp) and make a connection to the virtual serial port.

1. Start Tera Term
2. New connection -> Serial
3. Set apropriate COMx port (x is port number) in Port context menu. Number is provided by operation
   system and could be different from computer to computer. Select COM number related to virtual
   serial port. Confirm selected port by OK button.
4. Set following connection parameters in menu Setup->Serial port...
        Baud rate:    115200
        Data:         8
        Parity:       none
        Stop:         1
        Flow control: one
5.  Confirm selected parameters by OK button.

Running the demo
================
SPIFI flash dma example started
All data written is correct!
SPIFI DMA example Finished!
Customization options
=====================

