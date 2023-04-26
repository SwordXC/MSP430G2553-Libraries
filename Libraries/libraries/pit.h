#ifndef _PIT_H_
#define _PIT_H_
/* ==============================================================================
 * describe£ºpit.h
 * author£ºSwordXC/Liangliang.Zhang
 * date£º2023.04.26
 * ==============================================================================*/

void InitSystemClock(void);
void tim_interrupt_init_ms (int time);

/*
void tim_interrupt_enable (PIN_type type,PIN_enum pin);
void tim_interrupt_disable (PIN_type type,PIN_enum pin);
*/
#endif
