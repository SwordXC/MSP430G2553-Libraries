/* ==============================================================================
 * describe��touch.h
 * author��SwordXC/Liangliang.Zhang
 * date��2023.05.13
 * ==============================================================================*/
#ifndef _TOUCH_H_
#define _TOUCH_H_

#include "headfile.h"

typedef enum
{
    touch_no,
    touch_left,
    touch_right,
}touch_dir;

#define KEY_NUM        2
#define KEY0_INIT      P2DIR &= ~BIT0; P2SEL &= ~BIT0; P2SEL2 |= BIT0      /*����1������*/
#define KEY1_INIT      P2DIR &= ~BIT5; P2SEL &= ~BIT5; P2SEL2 |= BIT5      /*����2������*/
#define ALL_OSC_OFF    P2SEL2 &= ~(BIT0 + BIT5)                                    /*�ر�ȫ��������*/


void TouchIN_Dect(void);
touch_dir Touch_check(void);

#endif
