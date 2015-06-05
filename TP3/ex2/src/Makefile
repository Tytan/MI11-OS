CC=arm-buildroot-linux-uclibcgnueabi-gcc
LD=arm-buildroot-linux-uclibcgnueabi-ld
CXX=arm-buildroot-linux-uclibcgnueabi-g++
AS=arm-buildroot-linux-uclibcgnueabi-as
NM=arm-buildroot-linux-uclibcgnueabi-nm
AR=arm-buildroot-linux-uclibcgnueabi-ar
SIZE=arm-buildroot-linux-uclibcgnueabi-size
OBJCOPY=arm-buildroot-linux-uclibcgnueabi-objcopy

XENO_INC=/opt/armadeus/buildroot/output/staging/usr/include/xenomai/ 
XENO_LIB=/opt/armadeus/buildroot/output/staging/usr/lib 

EXEC=helloworld2RT
SRC=$(EXEC).c
OBJ=$(SRC:.c=.o)

CFLAGS=-g -W -Wall -I$(XENO_INC) -D_GNU_SOURCE -D_REENTRANT
LDFLAGS=-lpthread -lnative -lrtdk -L$(XENO_LIB)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS) 

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -o $@ -c $< 

clean:
	rm -rf $(OBJ) 
	rm -rf $(EXEC) 

.PHONY: all clean
