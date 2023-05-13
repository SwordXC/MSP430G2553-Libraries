/* ==============================================================================
 * describe£ºtouch.h
 * author£ºSwordXC/Liangliang.Zhang
 * date£º2023.05.13
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
#define KEY0_INIT      P2DIR &= ~BIT0; P2SEL &= ~BIT0; P2SEL2 |= BIT0      /*°´¼ü1¿ªÆôÕñµ´*/
#define KEY1_INIT      P2DIR &= ~BIT5; P2SEL &= ~BIT5; P2SEL2 |= BIT5      /*°´¼ü2¿ªÆôÕñµ´*/
#define ALL_OSC_OFF    P2SEL2 &= ~(BIT0 + BIT5)                                    /*¹Ø±ÕÈ«²¿´¥ÃþÕñµ´*/


void TouchIN_Dect(void);
touch_dir Touch_check(void);

#endif
