#!/bin/bash

i386-rtems4.11-gcc o-optimize/test.o -L/home/rtems/rtems_hyper/pok_wspace/pok-20120509/libpok --pipe -B/home/rtems/rtems_hyper/rtems_wspace/b-pok/install/i386-rtems4.11/pok/lib/ -specs bsp_specs -qrtems   -g -Wall  -g              -o o-optimize/hello.ralf -lpok
