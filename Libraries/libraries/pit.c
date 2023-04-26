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
void tim_interrupt_init_ms (int time)
{
    InitSystemClock();
    /*设置时钟源为SMCLK*/
    TA0CTL |= TASSEL_2;
    /*设置工作模式为UP Mode*/
    TA0CTL |= MC_1;
    /*设置定时间隔*/
    TA0CCR0 = time*1000-1 ;
    /*开启TAIFG中断*/
    TA0CTL |= TAIE;
}
