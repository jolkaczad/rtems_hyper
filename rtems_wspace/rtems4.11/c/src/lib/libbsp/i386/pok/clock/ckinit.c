/*  ckinit.c
 *
 *  This file provides a template for the clock device driver initialization.
 *
 *  COPYRIGHT (c) 1989-1999.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 *
 *  $Id$
 */

#include <stdlib.h>

#include <rtems.h>
#include <bsp.h>
#include <bsp/poksyscalls.h>

void Clock_exit( void );
void Clock_isr (void);

/*
 *  The interrupt vector number associated with the clock tick device
 *  driver.
 */

#define CLOCK_VECTOR    4

/*
 *  Clock_driver_ticks is a monotonically increasing counter of the
 *  number of clock ticks since the driver was initialized.
 */

volatile uint32_t         Clock_driver_ticks;
/*
 *  Clock_isrs is the number of clock ISRs until the next invocation of
 *  the RTEMS clock tick routine.  The clock tick device driver
 *  gets an interrupt once a millisecond and counts down until the
 *  length of time between the user configured microseconds per tick
 *  has passed.
 */

uint32_t         Clock_isrs;              /* ISRs until next tick */
uint32_t  Clock_isrs_const;

/*
 * These are set by clock driver during its init
 */

rtems_device_major_number rtems_clock_major = ~0;
rtems_device_minor_number rtems_clock_minor;

/*
 *  The previous ISR on this clock tick interrupt vector.
 */

rtems_isr_entry  Old_ticker;

void Clock_exit( void );

/*
 *  Isr Handler
 */

void Clock_isr(
    void
)
{
/*
 * bump the number of clock driver ticks since initialization
 *
 * determine if it is time to announce the passing of tick as configured
 * to RTEMS through the rtems_clock_tick directive
 *
 * perform any timer dependent tasks
 */

  while(1);
  Clock_driver_ticks++;
  rtems_clock_tick();
/*  Clock_driver_ticks++;
  if(!Clock_isrs) {
    rtems_clock_tick();
    Clock_isrs = Clock_isrs_const;
  }
  else {
    Clock_isrs-- ;
  }
  */
}


/*
 * during development, all the files concerning the POK-RTEMS interrupt channelling
 * will be temporarily kept in the clock driver files for convenience
 */

typedef enum {
  POK_IRQSOURCE_CLOCK = 0,
} pok_isr_sources_t;

void (*isr_handlers[CPU_INTERRUPT_NUMBER_OF_VECTORS])(void) = {NULL};

void isr_dispatch (
    pok_isr_sources_t source
)
{
  void (*fptr)(void);

  while(1); /* just to determine if function gets inside */
  fptr = isr_handlers[source];
  
  if (fptr != NULL){
    fptr();
  }
}

void install_handler (
    pok_isr_sources_t source,
    void (*handler)(void)
)
{
  if (handler == NULL){
    return;
  }

  isr_handlers[source] = handler;
}
/*
 *  Install_clock
 *
 *  Install a clock tick handler and reprograms the chip.  This
 *  is used to initially establish the clock tick.
 */
void Install_clock(
  void(*clock_handler)(void)
)
{
  printk ("install_clock()\n");
  pok_syscall1 (POK_SYSCALL_REGISTER_RTEMS_ISR, (uint32_t)isr_dispatch);

  install_handler (POK_IRQSOURCE_CLOCK, clock_handler);

/*   pok_syscall1 (POK_SYSCALL_REGISTER_TICK_NOTIFY, (uint32_t)&Clock_isr); */
  /*
   *  Initialize the clock tick device driver variables
   */

/*
  Clock_isrs_const = rtems_configuration_get_microseconds_per_tick() / 1000;
  Clock_isrs = Clock_isrs_const;
*/
//  Old_ticker = (rtems_isr_entry) set_vector( clock_isr, CLOCK_VECTOR, 1 );
  /*
   *  Hardware specific initialize goes here
   */

  /* XXX */

  /*
   *  Schedule the clock cleanup routine to execute if the application exits.
   */

  atexit( Clock_exit );
}

/*
 *  Clean up before the application exits
 */

void Clock_exit( void )
{
  /* XXX: turn off the timer interrupts */

  /* XXX: If necessary, restore the old vector */
}

/*
 *  Clock_initialize
 *
 *  Device driver entry point for clock tick driver initialization.
 */

rtems_device_driver Clock_initialize(
  rtems_device_major_number major,
  rtems_device_minor_number minor,
  void *pargp
)
{
  printk("clock init start\n");
  Install_clock( Clock_isr );

  /*
   * make major/minor avail to others such as shared memory driver
   */

  rtems_clock_major = major;
  rtems_clock_minor = minor;

  return RTEMS_SUCCESSFUL;
}

