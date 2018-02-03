obj-m:=interrupt_module_mmap.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=/home/pi/Documents/smart_products/lab3/lab3_make/rev1 modules
	
clean:
	make -C /lib/modules/$(shell uname -r)/build M=/home/pi/Documents/smart_products/lab3/lab3_make/rev1 clean


