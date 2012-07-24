#!/bin/bash

i386-rtems4.11-gcc -L$POK_PATH/libpok --pipe -B$RTEMS_WSPACE_PATH/b-pok/install/i386-rtems4.11/pok/lib/ -specs bsp_specs -qrtems   -g -Wall  -g              -o o-optimize/hello.ralf  o-optimize/test.o -lpok
