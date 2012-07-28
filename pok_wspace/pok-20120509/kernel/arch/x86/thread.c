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

/**
 **\file    thread.c
 **\brief   x86-dependent code for thread management
 **\author  Julian Pidancet
 */

#include <bsp.h>
#include <libc.h>
#include <errno.h>
#include <core/thread.h>

#include "gdt.h"

#include "thread.h"

#ifdef POK_NEEDS_THREADS

uint32_t		pok_context_create (uint32_t thread_id,
                                uint32_t stack_size,
                                uint32_t entry)
{
  start_context_t* sp;
  char*            stack_addr;

  stack_addr = pok_bsp_mem_alloc (stack_size);

  sp = (start_context_t *) (stack_addr + stack_size - 4 - sizeof (start_context_t));

  memset (sp, 0, sizeof (start_context_t));

  sp->ctx.__esp   = (uint32_t) (&sp->ctx.eip); /* for pusha */
  sp->ctx.eip     = (uint32_t) pok_thread_start;
  sp->ctx.cs      = GDT_CORE_CODE_SEGMENT << 3;
  sp->ctx.eflags  = 1 << 9;

  sp->entry       = entry;
  sp->id          = thread_id;

  return ((uint32_t)sp);
}


void			pok_context_switch (uint32_t* old_sp,
                                uint32_t new_sp);
asm (".global pok_context_switch	\n"
     "pok_context_switch:		\n"
     "pushf				\n"
     "pushl %cs				\n"
     "pushl $1f				\n"
     "pusha				\n"
     "movl 48(%esp), %ebx		\n" /* 48(%esp) : &old_sp, 52(%esp) : new_sp */
     "movl %esp, (%ebx)			\n"
     "movl 52(%esp), %esp		\n"
     "popa				\n"
     "iret				\n"
     "1:				\n"
     "ret"
     );

typedef struct {
    uint32_t    eflags;   /* extended flags register                   */
    void       *esp;      /* extended stack pointer register           */
    void       *ebp;      /* extended base pointer register            */
    uint32_t    ebx;      /* extended bx register                      */
    uint32_t    esi;      /* extended source index register            */
    uint32_t    edi;      /* extended destination index flags register */
}   Context_Control; 
void _CPU_Context_switch(
    void  *run,
    void  *heir);
asm (".set REG_EFLAGS,  0 \n"
  ".set REG_ESP,     REG_EFLAGS + 4 \n"
  ".set REG_EBP,     REG_ESP + 4  \n"
  ".set REG_EBX,     REG_EBP + 4  \n"
  ".set REG_ESI,     REG_EBX + 4  \n"
  ".set REG_EDI,     REG_ESI + 4  \n"
  ".set SIZE_REGS,   REG_EDI + 4  \n"

  ".text  \n"

  ".p2align  1 \n"
  ".global _CPU_Context_switch \n"
  "_CPU_Context_switch:  \n"

".set RUNCONTEXT_ARG,   4\n"                  /* save context argument */
".set HEIRCONTEXT_ARG,  8\n"                  /* restore context argument */

        "movl      RUNCONTEXT_ARG(%esp),%eax  \n"  /* eax = running threads context */
        "pushf  \n"                              /* push eflags */
        "popl      REG_EFLAGS(%eax)  \n"          /* save eflags */
        "movl      %esp,REG_ESP(%eax) \n"         /* save stack pointer */
        "movl      %ebp,REG_EBP(%eax) \n"         /* save base pointer */
        "movl      %ebx,REG_EBX(%eax) \n"         /* save ebx */
        "movl      %esi,REG_ESI(%eax) \n"         /* save source register */
        "movl      %edi,REG_EDI(%eax) \n"         /* save destination register */

        "movl      HEIRCONTEXT_ARG(%esp),%eax\n"  /* eax = heir threads context */


        "pushl     REG_EFLAGS(%eax)  \n"          /* push eflags */
        "popf \n"                               /* restore eflags */
        "movl      REG_ESP(%eax),%esp \n"         /* restore stack pointer */
        "movl      REG_EBP(%eax),%ebp \n"         /* restore base pointer */
        "movl      REG_EBX(%eax),%ebx \n"         /* restore ebx */
        "movl      REG_ESI(%eax),%esi \n"         /* restore source register */
        "movl      REG_EDI(%eax),%edi \n"         /* restore destination register */
        "ret"
        );
#endif
