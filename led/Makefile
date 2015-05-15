CC ?= gcc
CROSS_COMPILE ?= arm-linux-
SRC = led.c
OBJ = led.o
TARGET ?= mini2440_led

$(TARGET) : $(OBJ)
	$(CROSS_COMPILE)$(CC) $(OBJ) -o $(TARGET) 

$(OBJ) : $(SRC)
	$(CROSS_COMPILE)$(CC) -c $(SRC) -o $(OBJ)

clear:
	rm -rf *.o