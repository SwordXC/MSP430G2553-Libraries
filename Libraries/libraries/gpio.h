#ifndef _GPIO_H_
#define _GPIO_H_
/* ==============================================================================
 * describe£ºgpio.h
 * author£ºSwordXC/Liangliang.Zhang
 * date£º2023.04.26
 * ==============================================================================*/
#include "msp430g2553.h"

typedef enum
{
    GPIO1,
    GPIO2,
}PIN_type;


typedef enum
{
    GPIO_PIN_0 = 0x01,//0000 0001
    GPIO_PIN_1 = 0x02,//0000 0010
    GPIO_PIN_2 = 0x04,//0000 0100
    GPIO_PIN_3 = 0x08,//0000 1000
    GPIO_PIN_4 = 0x10,//0001 0000
    GPIO_PIN_5 = 0x20,//0010 0000
    GPIO_PIN_6 = 0x40,//0100 0000
    GPIO_PIN_7 = 0x80,//1000 0000
}PIN_enum;

typedef enum
{
    GPO_LOW = 0,
    GPO_HIGH = 1,
    GPI_PULL_UP,
    GPI_PULL_DOWN,
}GPIOLEVEL_enum;

typedef enum
{
    GPI = 0,
    GPO = 1,
}GPIODIR_enum;


void gpio_init(PIN_type type,PIN_enum pin, GPIODIR_enum dir, GPIOLEVEL_enum dat);
void gpio_set(PIN_type type,PIN_enum pin, GPIOLEVEL_enum dat);
unsigned int gpio_get(PIN_type type,PIN_enum pin);
void gpio_toggle(PIN_type type,PIN_enum pin);
#endif
