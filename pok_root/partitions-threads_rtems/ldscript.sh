#!/bin/bash
/usr/bin/ld -m elf_i386 -T $POK_PATH/misc/ldscripts/x86/x86-qemu/kernel.lds \
-o $POK_WSPACE_PATH/partitions-threads_rtems/generated-code/cpu/pok.elf \
kernel/kernel.lo sizes.o \
-Map $POK_WSPACE_PATH/partitions-threads_rtems/generated-code/cpu/pok.elf.map
