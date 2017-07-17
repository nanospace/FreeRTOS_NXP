INC
CFLAGS +=

objects := ${COMPILER}/$(patsubst %.c,%.o,$(wildcard *.c)) 
OBJS += ${objects}
