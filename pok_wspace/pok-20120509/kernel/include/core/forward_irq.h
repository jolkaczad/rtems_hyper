#ifndef __FORWARD_IRQ_H__ 
#define __FORWARD_IRQ_H__

#include <types.h>
#include <errno.h>

typedef enum {
    POK_IRQSOURCE_CLOCK = 0,
} pok_isr_sources_t;

extern void (*_pok_partition_isr_handlers [POK_CONFIG_NB_PARTITIONS])(pok_isr_sources_t source);

void pok_isr_channel (
  pok_isr_sources_t source
);

pok_ret_t pok_register_rtems_isr (
  void(*handler)(pok_isr_sources_t source),
  pok_partition_id_t id
);

pok_ret_t pok_register_rtems_elapsed_ticks (
  void(*handler)(uint32_t elapsed_ticks),
  pok_partition_id_t id
);

pok_ret_t pok_forward_elapsed_ticks (
  pok_partition_id_t id
);
#endif  /* ifndef __FORWARD_IRQ_H__ */
