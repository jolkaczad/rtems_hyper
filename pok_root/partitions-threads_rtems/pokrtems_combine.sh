#!/bin/bash

EXPECTED_ARGS=2

if [ $# -ne $EXPECTED_ARGS ]
then
	echo "error: two arguments are required"
	exit -1
fi

if [ -z $POK_WSPACE_PATH ]
	then
		echo "error: \$POK_WSPACE_PATH is not set"
		exit -2
fi

if [ -z $POK_PATH ]
	then
		echo "error: \$POK_PATH is not set"
		exit -3
fi

SIZE1=`ls -l $1|awk '{print $5}'`
SIZE2=`ls -l $2|awk '{print $5}'`

CURRENT_DIR=`pwd`

# partitions.bin
cat $1 > generated-code/cpu/partitions.bin
cat $2 >> generated-code/cpu/partitions.bin

cd generated-code/cpu

# sizes.o
rm -f sizes.c
touch sizes.c
echo "#include <types.h>" >> sizes.c
echo "uint32_t part_sizes[] = {" >> sizes.c

echo $SIZE1 >> sizes.c
echo "," >> sizes.c
echo $SIZE2 >> sizes.c

echo "};" >> sizes.c

cc -Wall -g -m32 -I$POK_PATH/kernel/include -c sizes.c -o sizes.o

objcopy --add-section .archive2=partitions.bin sizes.o

# pok.elf
ld -m elf_i386 -T $POK_PATH/misc/ldscripts/x86/x86-qemu/kernel.lds \
-o $POK_WSPACE_PATH/partitions-threads_rtems/generated-code/cpu/pok.elf \
kernel/kernel.lo sizes.o \
-Map $POK_WSPACE_PATH/partitions-threads_rtems/generated-code/cpu/pok.elf.map
