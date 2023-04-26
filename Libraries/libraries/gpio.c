#include "gpio.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief       GPIO初始化
// @param       type        选择的引脚大类 [GPIO1/GPIO2]
// @param       pin         具体引脚 (GPIO_PIN_0 - GPIO_PIN_7)
// @param       dir         引脚方向 [GPI/GPO]
// @param       dat         引脚模式 [GPIO_LOW/GPIO_HIGH/GPIO_PULLUP]
// @return      void
// Sample usage:            gpio_init(GPIO1, GPIO_PIN_2,GPO, GPIO_HIGH);初始化P1.2为输出模式高电平
//-------------------------------------------------------------------------------------------------------------------
void gpio_init(PIN_type type,PIN_enum pin, GPIODIR_enum dir, GPIOLEVEL_enum dat)
{
    if(dir)//GPO
    {
        if(type == GPIO1)
        {
            P1DIR |= pin;
        }
        else
        {
            P2DIR |= pin;
        }
    }
    else//GPI
    {
        if(type == GPIO1)
        {
            P1DIR &= ~pin;
            if(dat == GPI_PULL_UP) P1REN |= pin;
            else    P1REN &= ~pin;
        }
        else
        {
            P2DIR &= ~pin;
            if(dat == GPI_PULL_UP) P2REN |= pin;
            else    P2REN &= ~pin;
        }
    }

    gpio_set(type,pin,dat);
}

//-------------------------------------------------------------------------------------------------------------------
// @brief       设置引脚电平
// @param       type        选择的引脚大类 [GPIO1/GPIO2]
// @param       pin         具体引脚 (GPIO_PIN_0 - GPIO_PIN_7)
// @param       dat         引脚的电平 [GPIO_LOW/GPIO_HIGH]
// @return      void
// Sample usage:            gpio_set(GPIO1, GPIO_PIN_2,GPIO_HIGH);初始化P1.2为输出模式高电平
//-------------------------------------------------------------------------------------------------------------------
void gpio_set(PIN_type type,PIN_enum pin, GPIOLEVEL_enum dat)
{
    if(dat)
    {
        if(type == GPIO1)
        {
            P1OUT |= pin;
        }
        else
        {
            P2OUT |= pin;
        }
    }
    else
    {
        if(type == GPIO1)
        {
            P1OUT &= ~pin;
        }
        else
        {
            P2OUT &= ~pin;
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief       读取引脚状态
// @param       type        选择的引脚大类 [GPIO1/GPIO2]
// @param       pin         具体引脚 (GPIO_PIN_0 - GPIO_PIN_7)
// @return      1/0         1为高电平,0为低电平
// Sample usage:            gpio_get(GPIO1, GPIO_PIN_3);读取P1.3引脚状态
//-------------------------------------------------------------------------------------------------------------------
unsigned int gpio_get(PIN_type type,PIN_enum pin)
{
    if(type == GPIO1)
    {
        if(P1IN & pin) return 1;
        else return 0;
    }
    else
    {
        if(P2IN & pin) return 1;
        else return 0;
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief       翻转引脚
// @param       type        选择的引脚大类 [GPIO1/GPIO2]
// @param       pin         具体引脚 (GPIO_PIN_0 - GPIO_PIN_7)
// @return      void
// Sample usage:            gpio_toggle(GPIO1, GPIO_PIN_6);翻转P1.6的引脚状态
//-------------------------------------------------------------------------------------------------------------------
void gpio_toggle(PIN_type type,PIN_enum pin)
{
    if(type == GPIO1)
    {
        P1OUT ^= pin;
    }
    else
    {
        P2OUT ^= pin;
    }
}
