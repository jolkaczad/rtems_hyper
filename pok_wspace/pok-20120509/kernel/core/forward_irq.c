#include <core/forward_irq.h>
#include <errno.h>
#include <core/sched.h>
#include <core/time.h>

void (*pok_partition_isr_handlers[POK_CONFIG_NB_PARTITIONS])(pok_isr_sources_t source) = {NULL};
void (*pok_partition_elapsed_ticks_handlers[POK_CONFIG_NB_PARTITIONS])(uint32_t elapsed_ticks) = {NULL};

void pok_isr_channel (
    pok_isr_sources_t source
)
{
  void (*fptr)(pok_isr_sources_t source);

  fptr = pok_partition_isr_handlers[POK_SCHED_CURRENT_PARTITION];

  if (fptr == NULL)
  {
    ;
  }
  else
  {
    /* here is the place for the context switch and its return,
     * these may be arch dependent, not sure yet */

    /*
     *
     *
     *
     */
    fptr (source);
    /*
     *
     *
     *
     */
  }
}

pok_ret_t pok_register_rtems_isr (
    void(*handler)(pok_isr_sources_t source),
    pok_partition_id_t id
)
{
  pok_partition_isr_handlers[id] = handler;

  return POK_ERRNO_OK;
}

/*
 * this might be the place for all other rtems-interrupt related functions
 * to avoid creating new files
 */
pok_ret_t pok_register_rtems_elapsed_ticks (
    void(*handler)(uint32_t elapsed_ticks),
    pok_partition_id_t id
)
{
  /* maybe check if the pointer really belongs to the partition it's coming from first */
  pok_partition_elapsed_ticks_handlers[id] = handler;

  return POK_ERRNO_OK;
}

pok_ret_t pok_forward_elapsed_ticks (
    pok_partition_id_t id
)
{
  static uint32_t tick_old[POK_CONFIG_NB_PARTITIONS] = {0};
  uint32_t tick_delta;

  void (*fptr)(uint32_t elapsed_ticks);
  
  fptr = pok_partition_elapsed_ticks_handlers[id];
  if (fptr == NULL) /* not RTEMS partition or hasn't registered clock tick yet */
  {
    ;
  }
  else
  {
    if (tick_old[id] == 0)  /* first switch */
    {
      tick_delta = 0;
    }
    else
    {
      tick_delta = POK_GETTICK() - tick_old[id];
    }

    tick_old[id] = POK_GETTICK();
    /*
     *
     *
     *
     */
    fptr(tick_delta);
    /*
     *
     *
     *
     */
  }

  return POK_ERRNO_OK;
}
