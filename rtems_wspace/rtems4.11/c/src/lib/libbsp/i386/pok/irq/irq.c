/* irq.c
 *
 *  This file contains the implementation of the function described in irq.h
 *
 *  Copyright (c) 2009 embedded brains GmbH
 *  Copyright (C) 1998 valette@crf.canon.fr
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 */

/* so we can see _API_extensions_Run_postswitch */
#define __RTEMS_VIOLATE_KERNEL_VISIBILITY__ 1

#include <bsp.h>
#include <bsp/irq.h>
#include <bsp/irq-generic.h>

#include <stdlib.h>
#include <rtems/score/apiext.h>
#include <stdio.h>
#include <inttypes.h>

/*
 * pointer to the mask representing the additionnal irq vectors
 * that must be disabled when a particular entry is activated.
 * They will be dynamically computed from teh prioruty table given
 * in BSP_rtems_irq_mngt_set();
 * CAUTION : this table is accessed directly by interrupt routine
 * 	     prologue.
 */
rtems_i8259_masks 	irq_mask_or_tbl[BSP_IRQ_LINES_NUMBER];

uint32_t            irq_count[BSP_IRQ_LINES_NUMBER] = {0};

/*-------------------------------------------------------------------------+
| Cache for 1st and 2nd PIC IRQ line's status (enabled or disabled) register.
+--------------------------------------------------------------------------*/
/*
 * lower byte is interrupt mask on the master PIC.
 * while upper bits are interrupt on the slave PIC.
 * This cache is initialized in ldseg.s
 */
rtems_i8259_masks i8259s_cache = 0xFFFB;

/*-------------------------------------------------------------------------+
|         Function:  BSP_irq_disable_at_i8259s
|      Description: Mask IRQ line in appropriate PIC chip.
| Global Variables: i8259s_cache
|        Arguments: vector_offset - number of IRQ line to mask.
|          Returns: Nothing.
+--------------------------------------------------------------------------*/
int BSP_irq_disable_at_i8259s    (const rtems_irq_number irqLine)
{
  return 0;
}

/*-------------------------------------------------------------------------+
|         Function:  BSP_irq_enable_at_i8259s
|      Description: Unmask IRQ line in appropriate PIC chip.
| Global Variables: i8259s_cache
|        Arguments: irqLine - number of IRQ line to mask.
|          Returns: Nothing.
+--------------------------------------------------------------------------*/
int BSP_irq_enable_at_i8259s    (const rtems_irq_number irqLine)
{
  return 0;
} /* mask_irq */

int BSP_irq_enabled_at_i8259s        	(const rtems_irq_number irqLine)
{
	return 0;
}

/*-------------------------------------------------------------------------+
|         Function: BSP_irq_ack_at_i8259s
|      Description: Signal generic End Of Interrupt (EOI) to appropriate PIC.
| Global Variables: None.
|        Arguments: irqLine - number of IRQ line to acknowledge.
|          Returns: Nothing.
+--------------------------------------------------------------------------*/
int BSP_irq_ack_at_i8259s  	(const rtems_irq_number irqLine)
{
  return 0;
} /* ackIRQ */
