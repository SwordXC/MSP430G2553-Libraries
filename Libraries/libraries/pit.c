#include "pit.h"
#include "headfile.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief       初始化系统时钟
// @return      void
// Sample usage:  内部调用
//-------------------------------------------------------------------------------------------------------------------
void InitSystemClock()
{
    /*配置DCO频率为1MHZ*/
    DCOCTL = CALDCO_1MHZ;
    BCSCTL1 = CALBC1_1MHZ;
    /*配置SMCLK的时钟源为DCO*/
    BCSCTL2 &= ~SELS;
    /*SMCLK的分频系数置为1*/
    BCSCTL2 &= ~(DIVS0 | DIVS1);
}
void tim_interrupt_init_ms (TIM_type tim_pin,int time)
{
    InitSystemClock();
    if(tim_pin == A0)
    {
        /*设置时钟源为SMCLK*/
        TA0CTL |= TASSEL_2;
        /*设置工作模式为UP Mode*/
        TA0CTL |= MC_1;
        /*设置定时间隔*/
        TA0CCR0 = time*1000-1;
        /*开启TAIFG中断*/
        TA0CTL |= TAIE;
    }
    else if(tim_pin == A1)
    {
        /*设置时钟源为SMCLK*/
        TA1CTL |= TASSEL_2;
        /*设置工作模式为Continous up Mode*/
        TA1CTL |= MC_1;
        /*设置定时间隔*/
        TA1CCR0 = time*1000-1;
        //开启TAIFG中断
        TA1CTL |= TAIE;
    }
    else if(tim_pin == WDT)
    {
        WDTCTL = WDT_ADLY_16;        // “超级”宏定义
        IE1 |= WDTIE;                               //使能WDT中断
    }
}
void tim_interrupt_init_freq(TIM_type tim_pin,PIN_type type,PIN_enum pin)
{
    if(tim_pin == A1)
    {
        //TA1，CCR2用于捕捉功能
        TA1CCTL2 |= CAP;
        //上升沿捕捉
        TA1CCTL2 |= CM0;
        //允许捕捉比较中断
        TA1CCTL2 |=CCIE;

    }
    if(type == GPIO2)
    {
        TA1CCTL2 |= CCIS0;
        P2DIR &= ~pin;
        P2SEL |= pin;
    }

}
