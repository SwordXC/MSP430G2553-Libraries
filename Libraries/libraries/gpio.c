#include "gpio.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief       GPIO��ʼ��
// @param       type        ѡ������Ŵ��� [GPIO1/GPIO2]
// @param       pin         �������� (GPIO_PIN_0 - GPIO_PIN_7)
// @param       dir         ���ŷ��� [GPI/GPO]
// @param       dat         ����ģʽ [GPIO_LOW/GPIO_HIGH/GPIO_PULLUP]
// @return      void
// Sample usage:            gpio_init(GPIO1, GPIO_PIN_2,GPO, GPIO_HIGH);��ʼ��P1.2Ϊ���ģʽ�ߵ�ƽ
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
// @brief       �������ŵ�ƽ
// @param       type        ѡ������Ŵ��� [GPIO1/GPIO2]
// @param       pin         �������� (GPIO_PIN_0 - GPIO_PIN_7)
// @param       dat         ���ŵĵ�ƽ [GPIO_LOW/GPIO_HIGH]
// @return      void
// Sample usage:            gpio_set(GPIO1, GPIO_PIN_2,GPIO_HIGH);��ʼ��P1.2Ϊ���ģʽ�ߵ�ƽ
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
// @brief       ��ȡ����״̬
// @param       type        ѡ������Ŵ��� [GPIO1/GPIO2]
// @param       pin         �������� (GPIO_PIN_0 - GPIO_PIN_7)
// @return      1/0         1Ϊ�ߵ�ƽ,0Ϊ�͵�ƽ
// Sample usage:            gpio_get(GPIO1, GPIO_PIN_3);��ȡP1.3����״̬
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
// @brief       ��ת����
// @param       type        ѡ������Ŵ��� [GPIO1/GPIO2]
// @param       pin         �������� (GPIO_PIN_0 - GPIO_PIN_7)
// @return      void
// Sample usage:            gpio_toggle(GPIO1, GPIO_PIN_6);��תP1.6������״̬
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
