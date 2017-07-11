Overview
========
The SDIO project is a demonstration program that uses the SDK software. It reads/writes the SDIO card reigister. The purpose of this example is to show how to use SDio driver and this is a very simple example.


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
- SDIO card(such as wifi card, we use ATHEROS AR6233X to test)

Board settings
==============
Insert the sdio card into card slot

Prepare the Demo
================
1.  Connect a micro USB cable between the PC host and the LPC-Link USB port (J8) on the board.
2.  Open a serial terminal with the following settings:
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
3.  Download the program to the target board.
4.  Reset the SoC and run the project.

Running the demo
================
When the example runs successfully, following information can be seen on the OpenSDA terminal:

SDIO card simple example.

SDIO init Done

Read function CIS, in direct way

Read function CIS, in extended way, non-block mode, non-word aligned size

Read function CIS, in extended way, block mode, non-word aligned size
The read content is consistent.
Customization options
=====================

