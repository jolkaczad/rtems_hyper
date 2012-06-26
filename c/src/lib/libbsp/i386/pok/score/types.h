/**
 * @file rtems/score/types.h
 */

/*
 *  This include file contains type definitions pertaining to the Intel
 *  i386 processor family.
 *
 *  COPYRIGHT (c) 1989-1999.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 */

#ifndef _RTEMS_SCORE_TYPES_H
#define _RTEMS_SCORE_TYPES_H

#if defined(__RTEMS_ENABLE_HYPERVISOR__)
  /*
	 * functionality of cpukit/score/cpu/ is moved to the appropriate directory
	 * inside lib/libbsp/
	 */
#endif

#include <rtems/score/basedefs.h>

#ifndef ASM

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  This section defines the basic types for this processor.
 */

typedef uint16_t Priority_bit_map_Control;
typedef void i386_isr;
typedef i386_isr ( *i386_isr_entry )( void );

#ifdef __cplusplus
}
#endif

#endif  /* !ASM */

#endif
