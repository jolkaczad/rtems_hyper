/*
 * This is basically copied from POK, should the license be RTEMS' or POK's?
 */

#ifndef _POKSYSCALLS_H_
#define _POKSYSCALLS_H_
/* definitions from POK header files */
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
  POK_ERRNO_PARTITION            =  401,

} pok_ret_t;


typedef enum
{
   POK_SYSCALL_CONSWRITE                           =  10,
   POK_SYSCALL_GETTICK                             =  20,
   POK_SYSCALL_INT_NUMBER                          =  42,
   POK_SYSCALL_THREAD_CREATE                       =  50,
   POK_SYSCALL_THREAD_SLEEP_UNTIL                  =  51,
   POK_SYSCALL_THREAD_SLEEP                        =  52,
   POK_SYSCALL_THREAD_SUSPEND                      =  53,
   POK_SYSCALL_THREAD_RESTART                      =  54,
   POK_SYSCALL_THREAD_STOP                         =  55,
   POK_SYSCALL_THREAD_PERIOD                       =  56,
   POK_SYSCALL_THREAD_STOPSELF                     =  57,
   POK_SYSCALL_THREAD_ID                           =  58,
   POK_SYSCALL_THREAD_STATUS                       =  59,
   
   POK_SYSCALL_MIDDLEWARE_SAMPLING_ID              = 101,
   POK_SYSCALL_MIDDLEWARE_SAMPLING_READ            = 102,
   POK_SYSCALL_MIDDLEWARE_SAMPLING_STATUS          = 103,
   POK_SYSCALL_MIDDLEWARE_SAMPLING_WRITE           = 104,
   POK_SYSCALL_MIDDLEWARE_SAMPLING_CREATE          = 105,
   
   POK_SYSCALL_MIDDLEWARE_QUEUEING_CREATE          = 110,
   POK_SYSCALL_MIDDLEWARE_QUEUEING_SEND            = 111,
   POK_SYSCALL_MIDDLEWARE_QUEUEING_RECEIVE         = 112,
   POK_SYSCALL_MIDDLEWARE_QUEUEING_ID              = 113,
   POK_SYSCALL_MIDDLEWARE_QUEUEING_STATUS          = 114,
   
   POK_SYSCALL_MIDDLEWARE_VIRTUAL_CREATE           = 150,
   POK_SYSCALL_MIDDLEWARE_VIRTUAL_NB_DESTINATIONS  = 151,
   POK_SYSCALL_MIDDLEWARE_VIRTUAL_DESTINATION      = 152,
   POK_SYSCALL_MIDDLEWARE_VIRTUAL_GET_GLOBAL       = 153,
   
   POK_SYSCALL_LOCKOBJ_CREATE                      = 201,
   POK_SYSCALL_LOCKOBJ_OPERATION                   = 202,
   
   POK_SYSCALL_ERROR_HANDLER_CREATE                = 301,
   POK_SYSCALL_ERROR_HANDLER_SET_READY             = 302,
   POK_SYSCALL_ERROR_RAISE_APPLICATION_ERROR       = 303,
   POK_SYSCALL_ERROR_GET                           = 304,
   
   POK_SYSCALL_PARTITION_SET_MODE                  = 404,
   POK_SYSCALL_PARTITION_GET_ID                    = 405,
   POK_SYSCALL_PARTITION_GET_PERIOD                = 406,
   POK_SYSCALL_PARTITION_GET_DURATION              = 407,
   POK_SYSCALL_PARTITION_GET_LOCK_LEVEL            = 408,
   POK_SYSCALL_PARTITION_GET_OPERATING_MODE        = 409,
   POK_SYSCALL_PARTITION_GET_START_CONDITION       = 410,
   POK_SYSCALL_PARTITION_GET_MEMORY_INFO           = 411,
   
   POK_SYSCALL_INB                                 = 501,
   POK_SYSCALL_OUTB                                = 502,
   
   POK_SYSCALL_PCI_REGISTER                        = 601,

   POK_SYSCALL_REGISTER_TICK_NOTIFY                = 701,
   POK_SYSCALL_REGISTER_RTEMS_ISR                  = 702,
   POK_SYSCALL_REGISTER_RTEMS_ELAPSED_TICKS        = 703,
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
 * To reduce the number of functions and improve code coverage, we define
 * only one function to perform the syscall, the other are just maccro
 * This optimization was done only for x86 architecture.
 */
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

#endif /* _POKSYSCALLS_H_ */
