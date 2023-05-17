CURRENT = $(shell uname -r)
KERNEL_DIR = /lib/modules/$(CURRENT)/build
PWD = $(shell pwd)
SRC = testdriver.c Makefile

obj-m := testdriver.o

all:
	mkdir -p $(PWD)/build && cp $(SRC) $(PWD)/build
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD)/build modules

clean:
	rm -rf build/
