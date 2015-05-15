CC ?= gcc
CROSS_COMPILE ?= arm-linux-
SRC = globalmem_app.c
OBJ = globalmem_app.o
TARGET ?= globalmem_app

$(TARGET) : $(OBJ)
	$(CROSS_COMPILE)$(CC) $(OBJ) -o $(TARGET) 

$(OBJ) : $(SRC)
	$(CROSS_COMPILE)$(CC) -c $(SRC) -o $(OBJ)

clear:
	rm -rf *.o