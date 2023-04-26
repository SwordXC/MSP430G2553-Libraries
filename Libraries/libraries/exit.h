#ifndef _EXIT_H_
#define _EXIT_H_

/* ==============================================================================
 * describe£ºexit.h
 * author£ºSwordXC/Liangliang.Zhang
 * date£º2023.04.26
 * ==============================================================================*/
#include "msp430g2553.h"
#include "gpio.h"

typedef enum
{
    UP,
    DOWN,
}EXTITrigger_TypeDef;
void exti_interrupt_init (PIN_type type,PIN_enum pin,EXTITrigger_TypeDef trigger);
void exti_interrupt_enable (PIN_type type,PIN_enum pin);
void exti_interrupt_disable (PIN_type type,PIN_enum pin);

#endif
