
XENO_INC=/opt/armadeus/buildroot/output/staging/usr/include/xenomai/ 
XENO_LIB=/opt/armadeus/buildroot/output/staging/usr/lib 
EXTRA_CFLAGS=-g -W -Wall -I /opt/armadeus/buildroot/output/build/linux-headers-2.6.29.6/ -I$(XENO_INC) -D_GNU_SOURCE -D_REENTRANT
EXTRA_LDFLAGS=-lpthread -lnative -lrtdk -L$(XENO_LIB)

ifneq (${KERNELRELEASE},)
	obj-m += irq-gpio-rtdm.o

else
	ARCH ?= arm
	CROSS_COMPILE ?= arm-buildroot-linux-uclibcgnueabi-
	KERNEL_DIR = /opt/armadeus/buildroot/output/build/linux-2.6.29.6/
	MODULE_DIR := $(shell pwd)
	CFLAGS := -Wall -g 

.PHONY: all
all:: modules

.PHONY: modules
modules:
	${MAKE} ARCH=${ARCH} CROSS_COMPILE=${CROSS_COMPILE} -C ${KERNEL_DIR} SUBDIRS=${MODULE_DIR}  modules

XENOCONFIG=

.PHONY: clean
clean::
	rm -f  *.o  .*.o  .*.o.* *.ko  .*.ko  *.mod.* .*.mod.* .*.cmd *~
	rm -f Module.symvers Module.markers modules.order 
	rm -rf .tmp_versions
endif
