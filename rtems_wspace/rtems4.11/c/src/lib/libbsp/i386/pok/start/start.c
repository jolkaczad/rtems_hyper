/*
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rtems.com/license/LICENSE.
 */ 

#include <bsp/bootcard.h>

void _start(void)
{
	boot_card (NULL);
}
