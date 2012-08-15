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

#include <bsp.h>
#include <bsp/poksyscalls.h>
#include <bsp/irq_pok.h>

#include <rtems.h>
#include <rtems/config.h>
#include <rtems/score/tod.h>
#include <rtems/score/watchdog.h>
#include <rtems/score/timestamp.h>

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
 *  Install_clock
 *
 *  Install a clock tick handler and reprograms the chip.  This
 *  is used to initially establish the clock tick.
 */
void rtems_clock_tick_update(uint32_t ticks_u32);
void Install_clock(
  void(*clock_handler)(void)
)
{
  printk ("install_clock()\n");
  pok_syscall1 (POK_SYSCALL_REGISTER_RTEMS_ISR, (uint32_t)isr_dispatch);

  install_handler (POK_IRQSOURCE_CLOCK, clock_handler);

  /*
   * install the notification of ticks missed due to a partition switch on POK
   */
  pok_syscall1 (POK_SYSCALL_REGISTER_RTEMS_ELAPSED_TICKS, (uint32_t)rtems_clock_tick_update); 


/*
  Clock_isrs_const = rtems_configuration_get_microseconds_per_tick() / 1000;
  Clock_isrs = Clock_isrs_const;
*/
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

  /* 
   * updating the system with a number of clock ticks at once
   */
void rtems_clock_tick_update(uint32_t ticks_u32)
{
  /* _TOD_Tickle_ticks(); */
  Timestamp_Control tick;
  uint32_t  nanoseconds_per_tick;
  int i;
  int sec;
  unsigned long ticks = ticks_u32;

  nanoseconds_per_tick = rtems_configuration_get_nanoseconds_per_tick();

  _Timestamp_Set( &tick, 0, nanoseconds_per_tick * ticks);

  _Watchdog_Ticks_since_boot += ticks;

  _Timestamp_Add_to( &_TOD.uptime, &tick );
  _Timestamp_Add_to( &_TOD.now, &tick );

  _TOD.seconds_trigger += nanoseconds_per_tick;
  if ( _TOD.seconds_trigger >= 1000000000UL ) {
    /* more than one second may have elapsed since the last partition switch */
    sec = _TOD.seconds_trigger / 1000000000UL;
    for (i = 0; i < sec; i++){
      _TOD.seconds_trigger -= 1000000000UL;
    }
  }

  /* _Watchdog_Tickle_ticks();  */
  sec = (ticks * nanoseconds_per_tick)/1000000000UL;
  
  _Watchdog_Adjust(&_Watchdog_Ticks_chain, WATCHDOG_FORWARD, ticks);
  _Watchdog_Adjust(&_Watchdog_Seconds_chain, WATCHDOG_FORWARD, sec);

  /* _Scheduler_Tick is an alias to an entry in a jump table, the implementation
   * of which depends on the scheduler used. The workaround is to call it
   * from a for(;;) loop as many times as ticks have elapsed (might be expensive),
   * or just leave the scheduling to follow its own time, unsynchronized with
   * other partitions or the hypervisor's real time passage.
   */
  /* 
   * _Scheduler_Tick();
   *
   * if ( _Thread_Is_context_switch_necessary() &&
   *   _Thread_Is_dispatching_enabled() )
   *   _Thread_Dispatch();
   */
}
