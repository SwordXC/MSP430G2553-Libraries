#include "pit.h"
#include "headfile.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief       ��ʼ��ϵͳʱ��
// @return      void
// Sample usage:  �ڲ�����
//-------------------------------------------------------------------------------------------------------------------
void InitSystemClock()
{
    /*����DCOƵ��Ϊ1MHZ*/
    DCOCTL = CALDCO_1MHZ;
    BCSCTL1 = CALBC1_1MHZ;
    /*����SMCLK��ʱ��ԴΪDCO*/
    BCSCTL2 &= ~SELS;
    /*SMCLK�ķ�Ƶϵ����Ϊ1*/
    BCSCTL2 &= ~(DIVS0 | DIVS1);
}
void tim_interrupt_init_ms (TIM_type tim_pin,int time)
{
    InitSystemClock();
    if(tim_pin == A0)
    {
        /*����ʱ��ԴΪSMCLK*/
        TA0CTL |= TASSEL_2;
        /*���ù���ģʽΪUP Mode*/
        TA0CTL |= MC_1;
        /*���ö�ʱ���*/
        TA0CCR0 = time*1000-1;
        /*����TAIFG�ж�*/
        TA0CTL |= TAIE;
    }
    else if(tim_pin == A1)
    {
        /*����ʱ��ԴΪSMCLK*/
        TA1CTL |= TASSEL_2;
        /*���ù���ģʽΪContinous up Mode*/
        TA1CTL |= MC_1;
        /*���ö�ʱ���*/
        TA1CCR0 = time*1000-1;
        //����TAIFG�ж�
        TA1CTL |= TAIE;
    }
    else if(tim_pin == WDT)
    {
        WDTCTL = WDT_ADLY_16;        // ���������궨��
        IE1 |= WDTIE;                               //ʹ��WDT�ж�
    }
}
void tim_interrupt_init_freq(TIM_type tim_pin,PIN_type type,PIN_enum pin)
{
    if(tim_pin == A1)
    {
        //TA1��CCR2���ڲ�׽����
        TA1CCTL2 |= CAP;
        //�����ز�׽
        TA1CCTL2 |= CM0;
        //����׽�Ƚ��ж�
        TA1CCTL2 |=CCIE;

    }
    if(type == GPIO2)
    {
        TA1CCTL2 |= CCIS0;
        P2DIR &= ~pin;
        P2SEL |= pin;
    }

}
