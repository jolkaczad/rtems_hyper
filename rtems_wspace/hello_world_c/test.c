/*
 *  Simple test program -- simplified version of sample test hello.
 *
 *  $Id$
 */

#include <bsp.h>

#include <stdlib.h>
#include <stdio.h>
void fun(int *a)
{
  int b;
  *a++;
  b = *a;
  return;
}

rtems_task Init(
  rtems_task_argument ignored
)
{
  rtems_interval rt;

  int rtint1, rtint2 = 0;
  unsigned long i = 1;

  printf( "\n\n*** HELLO WORLD TEST ***\n" );
  printf( "Hello World\n" );
  printf( "*** END OF HELLO WORLD TEST ***\n" );
 
  pok_do_syscall(NULL, NULL);

  exit( 0 );
}

/* configuration information */

/* NOTICE: the clock driver is explicitly disabled */
/* #define CONFIGURE_APPLICATION_DOES_NOT_NEED_CLOCK_DRIVER */
#define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER

#define CONFIGURE_RTEMS_INIT_TASKS_TABLE
#define CONFIGURE_MAXIMUM_TASKS 1

#define CONFIGURE_INIT

/* the value is hardcoded from POK, a new syscall is required to retrieve it at runtime */
#define CONFIGURE_MICROSECONDS_PER_TICK 1000

#include <rtems/confdefs.h>

/* end of file */
