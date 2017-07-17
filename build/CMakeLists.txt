cmake_minimum_required (VERSION 2.8)
project (NetDebugger)

# this is required
SET(CMAKE_SYSTEM_NAME Generic)

# specify the cross compiler
SET(CMAKE_C_COMPILER   ../tools/gcc-arm-none-eabi-6-2017-q2-update/bin)

SET(CMAKE_FIND_ROOT_PATH ../tools/gcc-arm-none-eabi-6-2017-q2-update/lib/gcc/arm-none-eabi/6.3.1/thumb/v7e-m ../sdk/SDK_2.2_LPCXpresso54608/devices/LPC54608/mcuxpresso ../libs)

# search for programs in the build host directories (not necessary)
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM ONLY)
# for libraries and headers in the target directories
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
