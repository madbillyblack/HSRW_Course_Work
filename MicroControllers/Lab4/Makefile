################################################################################
# Makefile for Lab                                                           #
# Author: Thomas Grunenberg                                                    #
################################################################################


# Options ######################################################################
PORT=/dev/ttyUSB_MySmartUSB
PROGRAMMER=avr911
TARGET_CPU=atmega88pa
TARGET_PROCESSOR=m88p
CFLAGS=-Wall -Os -c -mmcu=$(TARGET_CPU)
LDFLAGS=-Os -mmcu=$(TARGET_CPU)

# Program ######################################################################
all: main.hex
	echo program build complete

program: main.hex
	avrdude -p $(TARGET_PROCESSOR) -c $(PROGRAMMER) -P $(PORT) -U flash:w:main.hex:i


# Hex File #####################################################################
main.hex: main.elf
	avr-objcopy -O ihex main.elf main.hex

main.elf: main.o
	avr-gcc $(LDFLAGS) main.o -o main.elf


# Object Files #################################################################
main.o: main.c
	avr-gcc $(CFLAGS) main.c -o main.o


# Clean ########################################################################
clean:
	rm -f *.o *.elf *.hex *~
