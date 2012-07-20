/*  cpu_asm.s
 *
 *  This file contains all assembly code for the Intel i386 implementation
 *  of RTEMS.
 *
 *  COPYRIGHT (c) 1989-1999.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 */

#ifdef HAVE_CONFIG_H
/* #include "config.h" FIXME */
#endif

#include <rtems/asm.h>
#include <rtems/score/cpu.h>

#ifndef CPU_STACK_ALIGNMENT
#error "Missing header? CPU_STACK_ALIGNMENT not defined"
#endif

/*
 * Format of i386 Register structure
 */

.set REG_EFLAGS,  0
.set REG_ESP,     REG_EFLAGS + 4
.set REG_EBP,     REG_ESP + 4
.set REG_EBX,     REG_EBP + 4
.set REG_ESI,     REG_EBX + 4
.set REG_EDI,     REG_ESI + 4
.set SIZE_REGS,   REG_EDI + 4

        BEGIN_CODE

/*
 *  void _CPU_Context_switch( run_context, heir_context )
 *
 *  This routine performs a normal non-FP context.
 */

        .p2align  1
        PUBLIC (_CPU_Context_switch)

.set RUNCONTEXT_ARG,   4                   /* save context argument */
.set HEIRCONTEXT_ARG,  8                   /* restore context argument */

SYM (_CPU_Context_switch):
        movl      RUNCONTEXT_ARG(esp),eax  /* eax = running threads context */
        pushf                              /* push eflags */
        popl      REG_EFLAGS(eax)          /* save eflags */
        movl      esp,REG_ESP(eax)         /* save stack pointer */
        movl      ebp,REG_EBP(eax)         /* save base pointer */
        movl      ebx,REG_EBX(eax)         /* save ebx */
        movl      esi,REG_ESI(eax)         /* save source register */
        movl      edi,REG_EDI(eax)         /* save destination register */

        movl      HEIRCONTEXT_ARG(esp),eax /* eax = heir threads context */

restore:
        pushl     REG_EFLAGS(eax)          /* push eflags */
        popf                               /* restore eflags */
        movl      REG_ESP(eax),esp         /* restore stack pointer */
        movl      REG_EBP(eax),ebp         /* restore base pointer */
        movl      REG_EBX(eax),ebx         /* restore ebx */
        movl      REG_ESI(eax),esi         /* restore source register */
        movl      REG_EDI(eax),edi         /* restore destination register */
        ret

/*
 *  NOTE: May be unnecessary to reload some registers.
 */

/*
 *  void _CPU_Context_restore( new_context )
 *
 *  This routine performs a normal non-FP context.
 */

        PUBLIC (_CPU_Context_restore)

.set NEWCONTEXT_ARG,   4                   /* context to restore argument */

SYM (_CPU_Context_restore):
        movl      NEWCONTEXT_ARG(esp),eax  /* eax = running threads context */
        jmp       restore

/*void _CPU_Context_save_fp_context( &fp_context_ptr )
 *  void _CPU_Context_restore_fp_context( &fp_context_ptr )
 *
 *  This section is used to context switch an i80287, i80387,
 *  the built-in coprocessor or the i80486 or compatible.
 */

.set FPCONTEXT_ARG,   4                    /* FP context argument */

#ifndef __SSE__
        .p2align  1
        PUBLIC (_CPU_Context_save_fp)
SYM (_CPU_Context_save_fp):
        movl      FPCONTEXT_ARG(esp),eax   /* eax = &ptr to FP context area */
        movl      (eax),eax                /* eax = FP context area */
        fsave     (eax)                    /* save FP context */
        ret

        .p2align  1
        PUBLIC (_CPU_Context_restore_fp)
SYM (_CPU_Context_restore_fp):
        movl      FPCONTEXT_ARG(esp),eax   /* eax = &ptr to FP context area */
        movl      (eax),eax                /* eax = FP context area */
        frstor    (eax)                    /* restore FP context */
        ret
#endif

#ifdef __SSE__
#define SSE_OFF  16
#endif


END_CODE

END
