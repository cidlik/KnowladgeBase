KERN_VER = $(shell uname -r)

KERNEL_DIR = /lib/modules/$(KERN_VER)/build
PWD = $(shell pwd)

obj-m := hello.o

hello-objs := start.o stop.o

default:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules

clean:
	rm -f *.o *.ko *~ modules.order Module.symvers *.mod.c
