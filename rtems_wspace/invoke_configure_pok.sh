#!/bin/bash
../rtems/configure --target=i386-rtems4.11 --disable-cxx --disable-networking --disable-posix --enable-rtemsbsp=pok --disable-tests --prefix=/home/rtems/rtems-4.11-work/b-test/install ENABLE_HYPERVISOR=1
