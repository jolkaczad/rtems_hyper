#!/bin/bash

i386-rtems4.11-gcc -v \
o-optimize/test.o \
--pipe -B$RTEMS_WSPACE_PATH/b-pok/install/i386-rtems4.11/pok/lib/ \
-specs bsp_specs \
-qrtems -g -Wall -g \
-o o-optimize/hello.ralf \
-L$POK_PATH/libpok \

# -Wl,--unresolved-symbols=ignore-all
