Overview
========
The MMCCARD FATFS project is a demonstration program that uses the SDK software. Tt mounts a file 
system based on a MMC card then does "creat directory/read directory/create file/write file/read 
file" operation. The file sdhc_config.h has default SDHC configuration which can be adjusted to let
card driver has different performance. The purpose of this example is to show how to use MMCCARD 
driver based FATFS disk in SDK software.

Note:
User can use MMC plus card or emmc(on board IC, but not recommand use emmc socket,due to high speed timing restriction)


Toolchain supported
===================
- IAR embedded Workbench 7.80.4
- Keil MDK 5.21a
- MCUXpresso0.8

Hardware requirements
=====================
- Mini USB cable
- LPCXpresso54608 board
- Personal Computer

Board settings
==============
Insert the card into the card slot

Prepare the Example
1. Connect a mini USB cable between the PC host and the OpenSDA USB port (J2) on twrk64f120m board.
2. Open a serial terminal on PC for OpenSDA serial device with these settings:
   - 115200 baud rate
   - 8 data bits
   - No parity
   - One stop bit
   - No flow control
3. Download the program to the target board.
4. Reset the SoC and run the project.

Prepare the Demo
================

Running the demo
================
When the example runs successfully, following prompts can be seen from the OpenSDA terminal:
FATFS example to demonstrate how to use FATFS with MMC card.

Makes file system......The time may be long if the card capacity is big

Creates directory......

Creates a file in that directory......

Lists the file in that directory......
Directory file : ..
Directory file : ...
General file : F_1.DAT.

Writes/reads file until encounters error......

Writes to above created file.
Reads from above created file.
Compares the read/write content.
The read/write content is consistent.

Input 'q' to quit read/write. 
Input other char to read/write file again.
Customization options
=====================

