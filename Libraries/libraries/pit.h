#ifndef _PIT_H_
#define _PIT_H_
#include "gpio.h"
/* ==============================================================================
 * describe£ºpit.h
 * author£ºSwordXC/Liangliang.Zhang
 * date£º2023.04.26
 * ==============================================================================*/

typedef enum
{
   A0,
   A1,
   WDT,
}TIM_type;

void InitSystemClock(void);
void tim_interrupt_init_ms (TIM_type tim_pin,int time);
void tim_interrupt_init_freq(TIM_type tim_pin,PIN_type type,PIN_enum pin);
/*
void tim_interrupt_enable (PIN_type type,PIN_enum pin);
void tim_interrupt_disable (PIN_type type,PIN_enum pin);
*/
#endif
