#ifndef _PWM_H_
#define _PWM_H_
/* ==============================================================================
 * describe��pwm.h
 * author��SwordXC/Liangliang.Zhang
 * date��2023.04.26
 * ==============================================================================*/
#include "msp430g2553.h"
#include "gpio.h"
#include "pit.h"

#define PWM_DUTY_MAX 1000
/*******************************************/
//P2.1 P2.2Ϊһ��
//P2.4 P2.5Ϊһ��
//ÿһ��ֻ����һ�֣��Ҳ�ͬ��֮���Ƶ�ʱ�����ͬ
/******************************************/
void pwm_init (PIN_type type,PIN_enum pin, unsigned int freq, unsigned int duty);
void pwm_duty (PIN_type type,PIN_enum pin, unsigned int duty);
void pwm_freq(PIN_type type,PIN_enum pin, unsigned int freq);
#endif
