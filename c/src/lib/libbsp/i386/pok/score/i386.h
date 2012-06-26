/**
 * @file rtems/score/i386.h
 */

/*
 *  This include file contains information pertaining to the Intel
 *  i386 processor.
 *
 *  COPYRIGHT (c) 1989-1999.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 */


#if defined(__RTEMS_ENABLE_HYPERVISOR__)
  /*
	 * functionality of cpukit/score/cpu/ is moved to the appropriate directory
	 * inside lib/libbsp/
	 */
#endif

#ifndef _RTEMS_SCORE_I386_H
#define _RTEMS_SCORE_I386_H

#define CPU_NAME "Intel i386"
#define CPU_MODEL_NAME "n/a"

#endif	/* include guard */
