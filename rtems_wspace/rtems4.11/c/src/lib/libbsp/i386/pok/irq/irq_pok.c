#include <stdlib.h>

#include <bsp/irq_pok.h>
#include <rtems/config.h>

void (*isr_handlers[CPU_INTERRUPT_NUMBER_OF_VECTORS])(void) = {NULL};

/*
 * isr_dispatch
 *
 * called from POK with the interrupt source passed by parameter,
 * according to which, interrupt handlers inside RTEMS are called
 */
void isr_dispatch (
    pok_isr_sources_t source
)
{
  void (*fptr)(void);

  fptr = isr_handlers[source];
  
  if (fptr != NULL){
    fptr();
  }
}

void install_handler (
    pok_isr_sources_t source,
    void (*handler)(void)
)
{
  if (handler == NULL){
    return;
  }

  isr_handlers[source] = handler;
}
