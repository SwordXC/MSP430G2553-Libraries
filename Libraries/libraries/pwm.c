#include "pwm.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief       PWM初始化
// @param       type        选择的引脚大类 [GPIO1/GPIO2]
// @param       pin         具体引脚 (GPIO_PIN_0 - GPIO_PIN_7)
// @param       freq        选择pwm频率
// @param       duty        选择占空比 0 - PWM_DUTY_MAX
// @return      void
// Sample usage:            pwm_init (GPIO2,GPIO_PIN_4, 2000, 0); 设置P2.4占空比为0
//-------------------------------------------------------------------------------------------------------------------
void pwm_init (PIN_type type,PIN_enum pin, unsigned int freq, unsigned int duty)
{
    InitSystemClock();
    /*设置时钟源为SMCLK*/
    TA1CTL |= TASSEL_2;
    /*设置工作模式为UP|DOWN模式*/
    TA1CTL |= MC_3;

    TA1CCR0 = 1000000/freq/2-1;


    /*设置为比较模式*/
    TA1CCTL0 &= ~CAP;
    /*设置为比较模式*/
    TA1CCTL1 &= ~CAP;
    TA1CCTL2 &= ~CAP;
    /*设置比较输出模式*/
    TA1CCTL1 |= OUTMOD_6;
    TA1CCTL2 |= OUTMOD_6;
    if(pin == GPIO_PIN_1 || pin == GPIO_PIN_2)
    {
        TA1CCR1 = (int)(TA1CCR0*(1-(float)duty/PWM_DUTY_MAX));           //占空比 = (TACCR0 - TACCR2) / TACCR0 , 频率 = SMCLK/(TACCR0+1)/2'
    }
    else if(pin == GPIO_PIN_4 || pin == GPIO_PIN_5)
    {
        TA1CCR2 = (int)(TA1CCR0*(1-(float)duty/PWM_DUTY_MAX));           //占空比 = (TACCR0 - TACCR2) / TACCR0 , 频率 = SMCLK/(TACCR0+1)/2

    }


    if(type == GPIO2)
    {
        P2SEL |= pin;
        P2DIR |= pin;
    }
}
//-------------------------------------------------------------------------------------------------------------------
// @brief       PWM占空比设置
// @param       type        选择的引脚大类 [GPIO1/GPIO2]
// @param       pin         具体引脚 (GPIO_PIN_0 - GPIO_PIN_7)
// @param       duty        选择占空比 0 - PWM_DUTY_MAX
// @return      void
// Sample usage:            pwm_duty (GPIO2,GPIO_PIN_4,0); 设置P2.4占空比为0
//-------------------------------------------------------------------------------------------------------------------
void pwm_duty (PIN_type type,PIN_enum pin, unsigned int duty)
{
    if(pin == GPIO_PIN_1 || pin == GPIO_PIN_2)
    {
        TA1CCR1 = (int)(TA1CCR0*(1-(float)duty/PWM_DUTY_MAX));           //占空比 = (TACCR0 - TACCR2) / TACCR0 , 频率 = SMCLK/(TACCR0+1)/2'
    }
    else if(pin == GPIO_PIN_4 || pin == GPIO_PIN_5)
    {
        TA1CCR2 = (int)(TA1CCR0*(1-(float)duty/PWM_DUTY_MAX));           //占空比 = (TACCR0 - TACCR2) / TACCR0 , 频率 = SMCLK/(TACCR0+1)/2

    }
}
//-------------------------------------------------------------------------------------------------------------------
// @brief       PWM频率设置
// @param       type        选择的引脚大类 [GPIO1/GPIO2]
// @param       pin         具体引脚 (GPIO_PIN_0 - GPIO_PIN_7)
// @param       freq        选择pwm频率
// @return      void
// Sample usage:            pwm_init (GPIO2,GPIO_PIN_4, 2000); 设置P2.4频率为2000
//-------------------------------------------------------------------------------------------------------------------
void pwm_freq(PIN_type type,PIN_enum pin, unsigned int freq)
{
    TA1CCR0 = 1000000/freq/2-1;
}
