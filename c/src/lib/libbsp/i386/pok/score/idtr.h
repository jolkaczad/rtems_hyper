/**
 * @file rtems/score/idtr.h
 */

/*
 * This file contains definitions for data structure related
 *          to Intel system programming. More information can be found
 *          on Intel site and more precisely in the following book :
 *
 *		Pentium Processor familly
 *		Developper's Manual
 *
 *		Volume 3 : Architecture and Programming Manual
 *
 * Formerly contained in and extracted from libcpu/i386/cpu.h.
 *
 * COPYRIGHT (C) 1998  Eric Valette (valette@crf.canon.fr)
 *                     Canon Centre Recherche France.
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 *
 *  Applications must not include this file directly.
 */

#ifndef __RTEMS_ENABLE_HYPERVISOR__
	/*
	 * functionality of cpukit/score/cpu/ is moved to the appropriate directory
	 * inside lib/libbsp/
	 */
#else

#endif
