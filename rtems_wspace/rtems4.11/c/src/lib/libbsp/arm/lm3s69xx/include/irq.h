/*
 * Copyright (c) 2011 Sebastian Huber.  All rights reserved.
 *
 *  embedded brains GmbH
 *  Obere Lagerstr. 30
 *  82178 Puchheim
 *  Germany
 *  <rtems@embedded-brains.de>
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rtems.com/license/LICENSE.
 */

#ifndef LIBBSP_ARM_LM3S69XX_IRQ_H
#define LIBBSP_ARM_LM3S69XX_IRQ_H

#ifndef ASM

#include <rtems.h>
#include <rtems/irq.h>
#include <rtems/irq-extension.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ASM */

#define LM3S69XX_IRQ_GPIO_PORT_A 16
#define LM3S69XX_IRQ_GPIO_PORT_B 17
#define LM3S69XX_IRQ_GPIO_PORT_C 18
#define LM3S69XX_IRQ_GPIO_PORT_D 19
#define LM3S69XX_IRQ_GPIO_PORT_E 20
#define LM3S69XX_IRQ_UART_0 21
#define LM3S69XX_IRQ_UART_1 22
#define LM3S69XX_IRQ_SSI_0 23
#define LM3S69XX_IRQ_I2C_0 24
#define LM3S69XX_IRQ_PWM_GENERATOR_0 26
#define LM3S69XX_IRQ_PWM_GENERATOR_1 27
#define LM3S69XX_IRQ_PWM_GENERATOR_2 28
#define LM3S69XX_IRQ_QEI_0 29
#define LM3S69XX_IRQ_ADC0_SEQUENCE_0 30
#define LM3S69XX_IRQ_ADC0_SEQUENCE_1 31
#define LM3S69XX_IRQ_ADC0_SEQUENCE_2 32
#define LM3S69XX_IRQ_ADC0_SEQUENCE_3 33
#define LM3S69XX_IRQ_WATCHDOG_TIMER_0 34
#define LM3S69XX_IRQ_TIMER_0_A 35
#define LM3S69XX_IRQ_TIMER_0_B 36
#define LM3S69XX_IRQ_TIMER_1_A 37
#define LM3S69XX_IRQ_TIMER_1_B 38
#define LM3S69XX_IRQ_TIMER_2_A 39
#define LM3S69XX_IRQ_TIMER_2_B 40
#define LM3S69XX_IRQ_ANALOG_COMPARATOR_0 41
#define LM3S69XX_IRQ_ANALOG_COMPARATOR_1 42
#define LM3S69XX_IRQ_SYSTEM_CONTROL 44
#define LM3S69XX_IRQ_FLASH_MEMORY_CONTROL 45
#define LM3S69XX_IRQ_GPIO_PORT_F 46
#define LM3S69XX_IRQ_GPIO PORT_G 47
#define LM3S69XX_IRQ_UART_2 49
#define LM3S69XX_IRQ_TIMER_3_A 51
#define LM3S69XX_IRQ_TIMER_3_B 52
#define LM3S69XX_IRQ_I2C_1 53
#define LM3S69XX_IRQ_QEI_1 54
#define LM3S69XX_IRQ_ETHERNET_CONTROLLER 58
#define LM3S69XX_IRQ_HIBERNATION_MODULE 59

#define LM3S69XX_IRQ_PRIORITY_VALUE_MIN 0
#define LM3S69XX_IRQ_PRIORITY_VALUE_MAX 7
#define LM3S69XX_IRQ_PRIORITY_COUNT (LM3S69XX_IRQ_PRIORITY_VALUE_MAX + 1)
#define LM3S69XX_IRQ_PRIORITY_HIGHEST LM3S69XX_IRQ_PRIORITY_VALUE_MIN
#define LM3S69XX_IRQ_PRIORITY_LOWEST LM3S69XX_IRQ_PRIORITY_VALUE_MAX

#define BSP_INTERRUPT_VECTOR_MIN 0
#define BSP_INTERRUPT_VECTOR_MAX 59

#endif /* LIBBSP_ARM_LM3S69XX_IRQ_H */
