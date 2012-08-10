/*
 *                               POK header
 * 
 * The following file is a part of the POK project. Any modification should
 * made according to the POK licence. You CANNOT use this file or a part of
 * this file is this part of a file for your own project
 *
 * For more information on the POK licence, please see our LICENCE FILE
 *
 * Please follow the coding guidelines described in doc/CODING_GUIDELINES
 *
 *                                      Copyright (c) 2007-2009 POK team 
 *
 * Created by julien on Thu Jan 15 23:34:13 2009 
 */

#include <libc/stdio.h>
#include <types.h>
#include <core/syscall.h>

int _notify = 0;
int ticks;

void tick_notify (void)
{
  ticks++;

  _notify = 1;
}
    
void user_hello_part1 ()
{
	/*
	printf( "[PART1] Hello Worlds\n");
	*/
	uint32_t size;
	uint32_t stack_size;
	uint32_t base_addr;

  void (*fptr)(void);
	
	char buff[] = {"[PART1] Hello Worlds\n"};
	int pos = sizeof (buff);	

	pok_syscall2 (POK_SYSCALL_CONSWRITE, (uint32_t)buff, pos);

	pok_syscall3 (POK_SYSCALL_PARTITION_GET_MEMORY_INFO, (uint32_t)&size, (uint32_t)&base_addr, (uint32_t)&stack_size);

  fptr = tick_notify;

  fptr();
  pok_syscall1 (POK_SYSCALL_REGISTER_TICK_NOTIFY, fptr);

  printf ("partition fptr address: 0x%x\n", (uint32_t)tick_notify);
	printf ("size: 0x%x, base_add: 0x%x, stack_size: 0x%x\n", size, base_addr, stack_size);

  if (_notify != 0){
    _notify = 0;
    printf ("tick\n");
  }
}
