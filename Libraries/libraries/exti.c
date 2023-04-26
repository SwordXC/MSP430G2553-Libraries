#include "exit.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief       exit��ʼ��
// @param       type        ѡ������Ŵ��� [GPIO1/GPIO2]
// @param       pin         �������� (GPIO_PIN_0 - GPIO_PIN_7)
// @param       trigger     ����ģʽ [UP/DOWM] �����ػ��½���
// @return      void
// Sample usage:            exti_interrupt_init(GPIO1, GPIO_PIN_3,GPO, DOWN);��ʼ��P1.3�ж�Ϊ�½���
//-------------------------------------------------------------------------------------------------------------------
void exti_interrupt_init (PIN_type type,PIN_enum pin,EXTITrigger_TypeDef trigger)
{
    if(type == GPIO1)
    {
        P1IE |= pin; //�ж�ʹ��
        if(trigger == DOWN)  //���ô�����ʽ
        {
            P1IES |= pin;
        }
        else
        {
            P1IES &= ~pin;
        }
        P1IFG &= ~pin;//��ձ�־λ
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
// @brief       exitʹ��
// @param       type        ѡ������Ŵ��� [GPIO1/GPIO2]
// @param       pin         �������� (GPIO_PIN_0 - GPIO_PIN_7)
// @return      void
// Sample usage:            exti_interrupt_enable(GPIO1, GPIO_PIN_3);��ʼ��P1.3�ж�Ϊ�½���
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
// @brief       exitʧ��
// @param       type        ѡ������Ŵ��� [GPIO1/GPIO2]
// @param       pin         �������� (GPIO_PIN_0 - GPIO_PIN_7)
// @return      void
// Sample usage:            exti_interrupt_init(GPIO1, GPIO_PIN_3);��ʼ��P1.3�ж�Ϊ�½���
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
