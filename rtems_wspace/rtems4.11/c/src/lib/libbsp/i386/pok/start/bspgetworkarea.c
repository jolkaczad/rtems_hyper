/*
 *  This routine is an implementation of the bsp_get_work_area()
 *  that can be used by all BSPs following linkcmds conventions
 *  regarding heap, stack, and workspace allocation.
 *
 *  COPYRIGHT (c) 1989-2008.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Copyright (c) 2011 embedded brains GmbH.
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 */

/* #define BSP_GET_WORK_AREA_DEBUG */

#include <bsp.h>
#include <bsp/bootcard.h>
#ifdef BSP_GET_WORK_AREA_DEBUG
  #include <rtems/bspIo.h>
#endif
#ifdef BSP_INTERRUPT_STACK_AT_WORK_AREA_BEGIN
  #include <rtems/config.h>
#endif

#include <bsp/poksyscalls.h>

#if defined(HAS_UBOOT) && !defined(BSP_DISABLE_UBOOT_WORK_AREA_CONFIG)
  #define USE_UBOOT
#endif

/*
 *  These are provided by the linkcmds for ALL of the BSPs which use this file.
 */
extern char WorkAreaBase[];
extern char HeapSize[];

extern char ELFBase[];
extern char textBase[];
extern char rodataBase[];
extern char dataBase[];

/*
 *  This method returns the base address and size of the area which
 *  is to be allocated between the RTEMS Workspace and the C Program
 *  Heap.
 */
void bsp_get_work_area(
  void      **work_area_start,
  uintptr_t  *work_area_size,
  void      **heap_start,
  uintptr_t  *heap_size
)
{
  uintptr_t ELF_Base = (uintptr_t) ELFBase;
  uintptr_t text_Base = (uintptr_t) textBase;
  uintptr_t rodata_Base = (uintptr_t) rodataBase;
  uintptr_t data_Base = (uintptr_t) dataBase;

  uintptr_t work_base = (uintptr_t) WorkAreaBase;
  uintptr_t ram_end;
  uint32_t size;
  uint32_t base_addr;
  uint32_t pok_stack_size;
  
  #ifdef BSP_INTERRUPT_STACK_AT_WORK_AREA_BEGIN
    work_base += Configuration.interrupt_stack_size;
  #endif

  pok_syscall3 (POK_SYSCALL_PARTITION_GET_MEMORY_INFO, (uint32_t)&size, (uint32_t)&base_addr, (uint32_t)&pok_stack_size);

  *work_area_start = (void *) work_base + pok_stack_size;
  *work_area_size  = size - work_base - pok_stack_size;
  *heap_start      = BSP_BOOTCARD_HEAP_USES_WORK_AREA;
  *heap_size       = (uintptr_t) HeapSize;

  /*
   *  The following may be helpful in debugging what goes wrong when
   *  you are allocating the Work Area in a new BSP.
   */
  #ifdef BSP_GET_WORK_AREA_DEBUG
    {
      void *sp = __builtin_frame_address(0);
      void *end = *work_area_start + *work_area_size;
      printk(
        "ELFBase = 0x%p\n"
        "textBase = 0x%p\n"
        "rodataBase = 0x%p\n"
        "dataBase = 0x%p\n"
        "work_area_start (base_addr) = 0x%p\n"
        "WorkAreaBase = 0x%p\n"
        "work_area_size = %d 0x%08x\n"
        "end = 0x%p\n"
        "heap_start = 0x%p\n"
        "heap_size = %d\n"
        "pok stack size = 0x%p\n"
        "current stack pointer = 0x%p%s\n",
        ELF_Base,
        text_Base,
        rodata_Base,
        data_Base,
        *work_area_start,
        work_base,
        *work_area_size,  /* decimal */
        *work_area_size,  /* hexadecimal */
        end,
        *heap_start,
        *heap_size,
        pok_stack_size,
        sp,
        ((sp >= *work_area_start && sp <= end) ? " OVERLAPS!" : "")
     );
  }
 #endif
}
