#ifndef _PIT_H_
#define _PIT_H_
/* ==============================================================================
 * describe��pit.h
 * author��SwordXC/Liangliang.Zhang
 * date��2023.04.26
 * ==============================================================================*/

void InitSystemClock(void);
void tim_interrupt_init_ms (int time);

/*
void tim_interrupt_enable (PIN_type type,PIN_enum pin);
void tim_interrupt_disable (PIN_type type,PIN_enum pin);
*/
#endif
