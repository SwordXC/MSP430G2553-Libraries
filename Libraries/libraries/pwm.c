#include "pwm.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief       PWM��ʼ��
// @param       type        ѡ������Ŵ��� [GPIO1/GPIO2]
// @param       pin         �������� (GPIO_PIN_0 - GPIO_PIN_7)
// @param       freq        ѡ��pwmƵ��
// @param       duty        ѡ��ռ�ձ� 0 - PWM_DUTY_MAX
// @return      void
// Sample usage:            pwm_init (GPIO2,GPIO_PIN_4, 2000, 0); ����P2.4ռ�ձ�Ϊ0
//-------------------------------------------------------------------------------------------------------------------
void pwm_init (PIN_type type,PIN_enum pin, unsigned int freq, unsigned int duty)
{
    InitSystemClock();
    /*����ʱ��ԴΪSMCLK*/
    TA1CTL |= TASSEL_2;
    /*���ù���ģʽΪUP|DOWNģʽ*/
    TA1CTL |= MC_3;

    TA1CCR0 = 1000000/freq/2-1;


    /*����Ϊ�Ƚ�ģʽ*/
    TA1CCTL0 &= ~CAP;
    /*����Ϊ�Ƚ�ģʽ*/
    TA1CCTL1 &= ~CAP;
    TA1CCTL2 &= ~CAP;
    /*���ñȽ����ģʽ*/
    TA1CCTL1 |= OUTMOD_6;
    TA1CCTL2 |= OUTMOD_6;
    if(pin == GPIO_PIN_1 || pin == GPIO_PIN_2)
    {
        TA1CCR1 = (int)(TA1CCR0*(1-(float)duty/PWM_DUTY_MAX));           //ռ�ձ� = (TACCR0 - TACCR2) / TACCR0 , Ƶ�� = SMCLK/(TACCR0+1)/2'
    }
    else if(pin == GPIO_PIN_4 || pin == GPIO_PIN_5)
    {
        TA1CCR2 = (int)(TA1CCR0*(1-(float)duty/PWM_DUTY_MAX));           //ռ�ձ� = (TACCR0 - TACCR2) / TACCR0 , Ƶ�� = SMCLK/(TACCR0+1)/2

    }


    if(type == GPIO2)
    {
        P2SEL |= pin;
        P2DIR |= pin;
    }
}
//-------------------------------------------------------------------------------------------------------------------
// @brief       PWMռ�ձ�����
// @param       type        ѡ������Ŵ��� [GPIO1/GPIO2]
// @param       pin         �������� (GPIO_PIN_0 - GPIO_PIN_7)
// @param       duty        ѡ��ռ�ձ� 0 - PWM_DUTY_MAX
// @return      void
// Sample usage:            pwm_duty (GPIO2,GPIO_PIN_4,0); ����P2.4ռ�ձ�Ϊ0
//-------------------------------------------------------------------------------------------------------------------
void pwm_duty (PIN_type type,PIN_enum pin, unsigned int duty)
{
    if(pin == GPIO_PIN_1 || pin == GPIO_PIN_2)
    {
        TA1CCR1 = (int)(TA1CCR0*(1-(float)duty/PWM_DUTY_MAX));           //ռ�ձ� = (TACCR0 - TACCR2) / TACCR0 , Ƶ�� = SMCLK/(TACCR0+1)/2'
    }
    else if(pin == GPIO_PIN_4 || pin == GPIO_PIN_5)
    {
        TA1CCR2 = (int)(TA1CCR0*(1-(float)duty/PWM_DUTY_MAX));           //ռ�ձ� = (TACCR0 - TACCR2) / TACCR0 , Ƶ�� = SMCLK/(TACCR0+1)/2

    }
}
//-------------------------------------------------------------------------------------------------------------------
// @brief       PWMƵ������
// @param       type        ѡ������Ŵ��� [GPIO1/GPIO2]
// @param       pin         �������� (GPIO_PIN_0 - GPIO_PIN_7)
// @param       freq        ѡ��pwmƵ��
// @return      void
// Sample usage:            pwm_init (GPIO2,GPIO_PIN_4, 2000); ����P2.4Ƶ��Ϊ2000
//-------------------------------------------------------------------------------------------------------------------
void pwm_freq(PIN_type type,PIN_enum pin, unsigned int freq)
{
    TA1CCR0 = 1000000/freq/2-1;
}
