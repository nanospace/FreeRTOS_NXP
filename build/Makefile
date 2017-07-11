#******************************************************************************
#
# Makefile - Rules for building the driver library and examples.
#
# Copyright (c) 2005,2006 Luminary Micro, Inc.  All rights reserved.
#
# Software License Agreement
#
# Luminary Micro, Inc. (LMI) is supplying this software for use solely and
# exclusively on LMI's Stellaris Family of microcontroller products.
#
# The software is owned by LMI and/or its suppliers, and is protected under
# applicable copyright laws.  All rights are reserved.  Any use in violation
# of the foregoing restrictions may subject the user to criminal sanctions
# under applicable laws, as well as to civil liability for the breach of the
# terms and conditions of this license.
#
# THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
# OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
# LMI SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
# CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
#
#******************************************************************************
GNU_TOOL_DIR=../tools/gcc-arm-none-eabi-6-2017-q2-update/bin

include makedefs

RTOS_SOURCE_DIR=../sdk/SDK_2.2_LPCXpresso54608/rtos/freertos_9.0.0/Source
SDK_DEVICE_DIR=../sdk/SDK_2.2_LPCXpresso54608/devices/LPC54608/mcuxpresso
APP_SOURCE_DIR=../src

CFLAGS+=-I ../inc \
        -I . \
		-I ${RTOS_SOURCE_DIR}/include \
		-I ${RTOS_SOURCE_DIR}/portable/GCC/ARM_CM4F \
		-I ../sdk/SDK_2.2_LPCXpresso54608/devices/LPC54608 \
		-I ../sdk/SDK_2.2_LPCXpresso54608/devices/LPC54608/utilities \
		-I ../sdk/SDK_2.2_LPCXpresso54608/devices/LPC54608/drivers \		
		-I ../sdk/SDK_2.2_LPCXpresso54608/CMSIS/Include \
		-D GCC_ARMCM4 \
		-D CPU_LPC54608J512BD208 \
		-D inline=

VPATH=${RTOS_SOURCE_DIR}:${RTOS_SOURCE_DIR}/portable/MemMang:${RTOS_SOURCE_DIR}/portable/GCC/ARM_CM4F:${APP_SOURCE_DIR}:${SDK_DEVICE_DIR}


OBJS= ${COMPILER}/main.o	\
      ${COMPILER}/board.o   \
	  ${COMPILER}/clock_config.o \
	  ${COMPILER}/pin_mux.o \
	  ${COMPILER}/list.o    \
      ${COMPILER}/queue.o   \
      ${COMPILER}/tasks.o   \
      ${COMPILER}/port.o    \
      ${COMPILER}/heap_1.o  \
	  ${COMPILER}/event_groups.o \
	  ${COMPILER}/timers.o  \
	  ${COMPILER}/croutine.o
#	  ${COMPILER}/pendsv_handler.o

INIT_OBJS= ${COMPILER}/startup_LPC54608.o

LIBS= ${SDK_DEVICE_DIR}/libfsl_power_lib.a ${SDK_DEVICE_DIR}/libfsl_power_lib_softabi.a


#
# The default rule, which causes init to be built.
#
all: ${COMPILER}           \
     ${COMPILER}/RTOSDemo.axf \
	 
#
# The rule to clean out all the build products
#

clean:
	@rm -rf ${COMPILER} ${wildcard *.bin} RTOSDemo.axf
	
#
# The rule to create the target directory
#
${COMPILER}:
	@mkdir ${COMPILER}

${COMPILER}/RTOSDemo.axf: ${INIT_OBJS} ${OBJS} ${LIBS}
SCATTER_RTOSDemo=standalone.ld
ENTRY_RTOSDemo=ResetISR

#
#
# Include the automatically generated dependency files.
#
-include ${wildcard ${COMPILER}/*.d} __dummy__


	 



