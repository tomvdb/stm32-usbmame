CC=arm-none-eabi-gcc
AR=arm-none-eabi-ar

###########################################

vpath %.c src

CFLAGS  = -g -O2 -Wall
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m0 -march=armv6s-m
CFLAGS += -ffreestanding -nostdlib -DUSE_STDPERIPH_DRIVER  -DSTM32F10X_LD
CFLAGS += -I../CMSIS/Include -I../CMSIS/Device/ST/STM32F10x/Include -Iinc

SRCS = usb_core.c \
	usb_init.c \
	usb_int.c \
	usb_mem.c \
	usb_regs.c \
	usb_sil.c
	

OBJS = $(SRCS:.c=.o)

.PHONY: libstm32usb.a

all: libstm32usb.a

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

libstm32usb.a: $(OBJS)
	$(AR) -r $@ $(OBJS)

clean:
	rm -f $(OBJS) libstm32usb.a
