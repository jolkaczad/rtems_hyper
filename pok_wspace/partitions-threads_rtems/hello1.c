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

/* #include <libc/stdio.h> */
#include <types.h>
/* #include <core/syscall.h> */

/* definitions from header files */
typedef enum
{
 	POK_ERRNO_OK                    =   0,
 	POK_ERRNO_EINVAL                =   1,

 	POK_ERRNO_UNAVAILABLE           =   2,
 	POK_ERRNO_TOOMANY               =   5,
 	POK_ERRNO_EPERM                 =   6,
 	POK_ERRNO_EXISTS                =   7,

 	POK_ERRNO_ERANGE                =   8,
 	POK_ERRNO_EDOM                  =   9,
 	POK_ERRNO_HUGE_VAL              =  10,

 	POK_ERRNO_EFAULT                =  11,
 	POK_ERRNO_THREAD                =  49,
	POK_ERRNO_THREADATTR            =  50,

	POK_ERRNO_TIME                 =  100,

	POK_ERRNO_PARTITION_ATTR        = 200,

	POK_ERRNO_PORT                 =  301,
	POK_ERRNO_NOTFOUND             =  302,
	POK_ERRNO_DIRECTION            =  303,
	POK_ERRNO_SIZE                 =  304,
	POK_ERRNO_DISCIPLINE           =  305,
	POK_ERRNO_PORTPART             =  307,
	POK_ERRNO_EMPTY                =  308,
	POK_ERRNO_KIND                 =  309,
	POK_ERRNO_FULL                 =  311,
	POK_ERRNO_READY                =  310,
	POK_ERRNO_TIMEOUT              =  250,
	POK_ERRNO_MODE                 =  251,

	POK_ERRNO_LOCKOBJ_UNAVAILABLE  =  500,
	POK_ERRNO_LOCKOBJ_NOTREADY     =  501,
	POK_ERRNO_LOCKOBJ_KIND         =  502,
	POK_ERRNO_LOCKOBJ_POLICY       =  503,

	POK_ERRNO_PARTITION_MODE       =  601,
  POK_ERRNO_PARTITION            =  401
} pok_ret_t;


typedef enum
{
	POK_SYSCALL_CONSWRITE	=	10,
	/*
	 * ***
	 */
} pok_syscall_id_t;

typedef struct
{
	uint32_t             nargs;
	uint32_t             arg1;
	uint32_t             arg2;
	uint32_t             arg3;
	uint32_t             arg4;
	uint32_t             arg5;
} pok_syscall_args_t;


/*
 *  * To reduce the number of functions and improve code coverage, we define
 *   * only one function to perform the syscall, the other are just maccro
 *    * This optimization was done only for x86 architecture.
 *     */
   pok_ret_t pok_do_syscall (pok_syscall_id_t syscall_id, pok_syscall_args_t* args);

	    #define pok_syscall1(sid,arg1) \
		            pok_do_syscall(sid,&((pok_syscall_args_t){2,arg1,0,0,0,0}))

	    #define pok_syscall2(sid,arg1,arg2) \
		            pok_do_syscall(sid,&((pok_syscall_args_t){2,arg1,arg2,0,0,0}))

	    #define pok_syscall3(sid,arg1,arg2,arg3) \
		            pok_do_syscall(sid,&((pok_syscall_args_t){2,arg1,arg2,arg3,0,0}))

	    #define pok_syscall4(sid,arg1,arg2,arg3,arg4) \
		            pok_do_syscall(sid,&((pok_syscall_args_t){2,arg1,arg2,arg3,arg4,0}))

	    #define pok_syscall5(sid,arg1,arg2,arg3,arg4,arg5) \
		            pok_do_syscall(sid,&((pok_syscall_args_t){2,arg1,arg2,arg3,arg4,arg5})) 

/*
pok_ret_t pok_syscall2  (pok_syscall_id_t syscall_id,
		uint32_t arg1,
		uint32_t arg2);
		*/

void user_hello_part1 ()
{
	/*
	printf( "[PART1] Hello Worlds\n");
	*/
	
	char buff[] = {"[PART1] Hello Worlds\n"};
	int pos = sizeof (buff);	

	pok_syscall2 (POK_SYSCALL_CONSWRITE, (uint32_t)buff, pos);
}