#ifndef _ADC_H_
#define _ADC_H_

/* ==============================================================================
 * describe��adc.h
 * author��SwordXC/Liangliang.Zhang
 * date��2023.04.26
 * ==============================================================================*/

#include "gpio.h"
#include "msp430g2553.h"
#include "stdint.h"
//P1.0 - P1.7 ������ADC
void adc_init(PIN_type type,PIN_enum pin);
//ADC����һ��ͨ�������һ��ֻ�ܿ���һ��ADC����
uint16_t adc_get(void);
#endif
