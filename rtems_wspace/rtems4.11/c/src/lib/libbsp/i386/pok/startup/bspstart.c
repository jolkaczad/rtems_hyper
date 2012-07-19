/*
 *  This routine starts the application.  It includes application,
 *  board, and monitor specific initialization and configuration.
 *  The generic CPU dependent initialization has been performed
 *  before this routine is invoked.
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

#include <string.h>

#include <bsp.h>
#include <bsp/poksyscalls.h>
#include <rtems.h>
#include <rtems/bspIo.h>

/*
 * will be used when POK header files can be included
#include <types.h>
#include <libc/stdio.h> 
#include <core/syscall.h> 
*/

/*
pok_ret_t pok_syscall2  (pok_syscall_id_t syscall_id,
    uint32_t arg1,
    uint32_t arg2);
    */
/*
 *  bsp_start
 *
 *  This routine does the bulk of the system initialization.
 */
void bsp_start( void )
{
  char buff[] = {"RTEMS bsp_start()\n"};

  size_t pos;
  pos = sizeof (buff);  /* strlen ("buff[]"); */

  pok_syscall2 (POK_SYSCALL_CONSWRITE, (uint32_t)buff, pos);
}
