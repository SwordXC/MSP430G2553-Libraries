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
void tim_interrupt_init_ms (int time)
{
    InitSystemClock();
    /*����ʱ��ԴΪSMCLK*/
    TA0CTL |= TASSEL_2;
    /*���ù���ģʽΪUP Mode*/
    TA0CTL |= MC_1;
    /*���ö�ʱ���*/
    TA0CCR0 = time*1000-1 ;
    /*����TAIFG�ж�*/
    TA0CTL |= TAIE;
}
