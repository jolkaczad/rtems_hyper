#include <core/forward_irq.h>
#include <errno.h>

void (*pok_partition_isr_handlers [POK_CONFIG_NB_PARTITIONS])(pok_isr_sources_t source);

void pok_isr_channel (
    pok_isr_sources_t source
)
{
  void (*fptr)(pok_isr_sources_t source);
  if (pok_partition_isr_handlers[source] == NULL){
    return;
  }

  fptr = pok_partition_isr_handlers[source];

  /* here is the place for the context switch and its return */
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

pok_ret_t register_rtems_isr (
    void(*handler)(pok_isr_sources_t source),
    pok_partition_id_t id
)
{
  pok_partition_isr_handlers[id] = handler;

  return POK_ERRNO_OK;
}
