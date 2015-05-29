DEST_DIR=/tftpboot/local/bin 
#ARMADEUS_BASE_DIR=../ 
#include $(ARMADEUS_BASE_DIR)/Makefile.in 
XENO_INC=/opt/armadeus/buildroot/output/staging/usr/include/xenomai/ 
XENO_INC=/opt/armadeus/buildroot/output/staging/usr/lib 
#XENO=$(ARMADEUS_ROOTFS_DIR)/usr/xenomai 

CC:=arm-buildroot-linux-uclibcgnueabi-gcc 
LD:=arm-buildroot-linux-uclibcgnueabi-ld 
CXX:=arm-buildroot-linux-uclibcgnueabi-g++ 
AS:=arm-buildroot-linux-uclibcgnueabi-as 
NM:=arm-buildroot-linux-uclibcgnueabi-nm 
AR:=arm-buildroot-linux-uclibcgnueabi-ar 
SIZE:=arm-buildroot-linux-uclibcgnueabi-size 
OBJCOPY:=arm-buildroot-linux-uclibcgnueabi-objcopy 

EXEC=blink_led_xeno_userspace
SRC=$(wildcard *.c) 
OBJ=$(SRC:.c=.o) 

CFLAGS=-g -W -Wall -I$(XENO_INC) -I$(XENO)/include -I$ (XENO)/include/native -I$(XENO)/include/rtdm -D_GNU_SOURCE -D_REENTRANT 
LDFLAGS=-lpthread -lnative -lrtdm 
#-L$(XENO_LIB) -L$(XENO)/lib $(XENO)/lib/libnative.a $(XENO)/lib/librtdm.a -rpath $(XENO)/lib -Xlinker   -Xlinker 

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS) 

$(OBJ): $(SRC) 
	$(CC) $(CFLAGS) -o $@ -c $< 

clean: 
	rm -rf $(OBJ) 
	rm -rf $(EXEC) 
	rm -f *.c~ *.h~ Makefile~ 

install: $(EXEC) 
	@mkdir -p $(DEST_DIR)/$(EXEC) 
	echo "$(EXEC):native:!./$(EXEC);popall:control_c" > $
	(DEST_DIR)/$(EXEC)/.runinfo 
	cp -f $(EXEC) $(DEST_DIR)/$(EXEC) 

mrproper: clean 
	rm -rf $(DEST_DIR)/$(EXEC) 

.PHONY: all install clean mrproper 
