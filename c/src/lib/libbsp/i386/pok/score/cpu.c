/*
 *  Intel i386 Dependent Source
 *
 *  COPYRIGHT (c) 1989-1999.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 */

#ifdef HAVE_CONFIG_H
/* #include "config.h" */
#endif

#include <rtems.h>
#include <rtems/system.h>
#include <rtems/score/types.h>
#include <rtems/score/isr.h>
#include <rtems/score/idtr.h>

#include <rtems/bspIo.h>
#include <rtems/score/thread.h>

/*  _CPU_Initialize
 *
 *  This routine performs processor dependent initialization.
 *
 *  INPUT PARAMETERS: NONE
 */


void _init (void)
{
}

void _CPU_Initialize(void)
{
}

/*
 *  _CPU_ISR_Get_level
 */

uint32_t   _CPU_ISR_Get_level( void )
{
}

void *_CPU_Thread_Idle_body( uintptr_t ignored )
{
}

struct Frame_ {
	struct Frame_  *up;
	uintptr_t		pc;
};

static void _defaultExcHandler (CPU_Exception_frame *ctx)
{
}

cpuExcHandlerType _currentExcHandler = _defaultExcHandler;

extern void rtems_exception_prologue_0(void);
extern void rtems_exception_prologue_1(void);
extern void rtems_exception_prologue_2(void);
extern void rtems_exception_prologue_3(void);
extern void rtems_exception_prologue_4(void);
extern void rtems_exception_prologue_5(void);
extern void rtems_exception_prologue_6(void);
extern void rtems_exception_prologue_7(void);
extern void rtems_exception_prologue_8(void);
extern void rtems_exception_prologue_9(void);
extern void rtems_exception_prologue_10(void);
extern void rtems_exception_prologue_11(void);
extern void rtems_exception_prologue_12(void);
extern void rtems_exception_prologue_13(void);
extern void rtems_exception_prologue_14(void);
extern void rtems_exception_prologue_16(void);
extern void rtems_exception_prologue_17(void);
extern void rtems_exception_prologue_18(void);
#ifdef __SSE__
extern void rtems_exception_prologue_19(void);
#endif

static rtems_raw_irq_hdl tbl[] = {
	 rtems_exception_prologue_0,
	 rtems_exception_prologue_1,
	 rtems_exception_prologue_2,
	 rtems_exception_prologue_3,
	 rtems_exception_prologue_4,
	 rtems_exception_prologue_5,
	 rtems_exception_prologue_6,
	 rtems_exception_prologue_7,
	 rtems_exception_prologue_8,
	 rtems_exception_prologue_9,
	 rtems_exception_prologue_10,
	 rtems_exception_prologue_11,
	 rtems_exception_prologue_12,
	 rtems_exception_prologue_13,
	 rtems_exception_prologue_14,
     0,
	 rtems_exception_prologue_16,
	 rtems_exception_prologue_17,
	 rtems_exception_prologue_18,
#ifdef __SSE__
	 rtems_exception_prologue_19,
#endif
};

void rtems_exception_init_mngt(void)
{
}
