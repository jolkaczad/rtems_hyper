/**
 * @file rtems/score/interrupts.h
 */

/*
 *  i386 interrupt macros.
 *
 *  Formerly contained in and extracted from libcpu/i386/cpu.h
 *
 *  COPYRIGHT (c) 1998 valette@crf.canon.fr
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 *
 *  Applications must not include this file directly.
 */

#ifndef _RTEMS_SCORE_INTERRUPTS_H
#define _RTEMS_SCORE_INTERRUPTS_H

#if defined(__RTEMS_ENABLE_HYPERVISOR__)
  /*
	 * functionality of cpukit/score/cpu/ is moved to the appropriate directory
	 * inside lib/libbsp/
	 */
#endif

/* typedefs required by i386/shared/irq/ */
#endif
