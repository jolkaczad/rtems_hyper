#!/bin/bash

#/opt/rtems-4.11/libexec/gcc/i386-rtems4.11/4.6.3/ld -o o-optimize/hello.ralf \
/opt/rtems-4.11/bin/i386-rtems4.11-ld -nostdlib -M=Wl.map -o o-optimize/hello.ralf \
o-optimize/test.o \
-L$POK_PATH/libpok -L$RTEMS_WSPACE_PATH/b-pok/install/i386-rtems4.11/pok/lib \
-L/opt/rtems-4.11/lib/gcc/i386-rtems4.11/4.6.3 \
-L/opt/rtems-4.11/lib/gcc/i386-rtems4.11/4.6.3/../../../../i386-rtems4.11/lib \
-lgcc --start-group -lrtemsbsp -lrtemscpu -lc -lgcc -lpok \
--end-group -T $RTEMS_WSPACE_PATH/b-pok/install/i386-rtems4.11/pok/lib/linkcmds -lgcc
