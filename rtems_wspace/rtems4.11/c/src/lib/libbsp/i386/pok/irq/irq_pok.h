#ifndef _IRQ_POK_H_
#define _IRQ_POK_H_

typedef enum {
  POK_IRQSOURCE_CLOCK = 0,
} pok_isr_sources_t;

void install_handler (
    pok_isr_sources_t source,
    void (*handler)(void)
);

void isr_dispatch (
    pok_isr_sources_t source
);

#endif /* _IRQ_POK_H_ */
