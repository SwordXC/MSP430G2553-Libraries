#include "exit.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief       exit初始化
// @param       type        选择的引脚大类 [GPIO1/GPIO2]
// @param       pin         具体引脚 (GPIO_PIN_0 - GPIO_PIN_7)
// @param       trigger     触发模式 [UP/DOWM] 上升沿或下降沿
// @return      void
// Sample usage:            exti_interrupt_init(GPIO1, GPIO_PIN_3,GPO, DOWN);初始化P1.3中断为下降沿
//-------------------------------------------------------------------------------------------------------------------
void exti_interrupt_init (PIN_type type,PIN_enum pin,EXTITrigger_TypeDef trigger)
{
    if(type == GPIO1)
    {
        P1IE |= pin; //中断使能
        if(trigger == DOWN)  //设置触发方式
        {
            P1IES |= pin;
        }
        else
        {
            P1IES &= ~pin;
        }
        P1IFG &= ~pin;//清空标志位
    }
    else
    {
        P2IE |= pin;
        if(trigger == DOWN)
        {
            P2IES |= pin;
        }
        else
        {
            P2IES &= ~pin;
        }
        P2IFG &= ~pin;
    }

}
//-------------------------------------------------------------------------------------------------------------------
// @brief       exit使能
// @param       type        选择的引脚大类 [GPIO1/GPIO2]
// @param       pin         具体引脚 (GPIO_PIN_0 - GPIO_PIN_7)
// @return      void
// Sample usage:            exti_interrupt_enable(GPIO1, GPIO_PIN_3);初始化P1.3中断为下降沿
//-------------------------------------------------------------------------------------------------------------------
void exti_interrupt_enable (PIN_type type,PIN_enum pin)
{
    if(type == GPIO1)
    {
        P1IE |= pin;
    }
    else
    {
        P2IE |= pin;
    }
}
//-------------------------------------------------------------------------------------------------------------------
// @brief       exit失能
// @param       type        选择的引脚大类 [GPIO1/GPIO2]
// @param       pin         具体引脚 (GPIO_PIN_0 - GPIO_PIN_7)
// @return      void
// Sample usage:            exti_interrupt_init(GPIO1, GPIO_PIN_3);初始化P1.3中断为下降沿
//-------------------------------------------------------------------------------------------------------------------
void exti_interrupt_disable (PIN_type type,PIN_enum pin)
{
    if(type == GPIO1)
    {
        P1IE &= ~pin;
    }
    else
    {
        P2IE &= ~pin;
    }
}
