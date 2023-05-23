#include "isr.h"
#include "headfile.h"
#include "loop.h"

#pragma vector = USCIAB0RX_VECTOR
__interrupt void UART_Receive_ISR(void)
{
    static uint8_t rx_buf[128] ={0};
    if(IFG2 & UCA0RXIFG)
    {
        IFG2 &= ~UCA0RXIFG;//清除标志位
        rx_buf[0] = UCA0RXBUF;
        uart_putstr(rx_buf);
        if(rx_buf[0] == 'a')
        {
        }
        else if(rx_buf[0] == 'b')
        {
        }
    }
}
#pragma vector = PORT1_VECTOR
__interrupt void Port1_ISR(void)
{
    if(P1IFG & GPIO_PIN_3)
    {
        P1IFG &= ~GPIO_PIN_3;//清中断标志
    }
}

#pragma vector = PORT2_VECTOR
__interrupt void Port2_ISR(void)
{

}

#pragma vector = TIMER0_A1_VECTOR
__interrupt void Time0_Tick(void)
{
    if(TA0IV == 0x0A)
    {
    }
}
#pragma vector = TIMER1_A1_VECTOR
__interrupt void Time1_Tick(void)
{
    __bis_SR_register(GIE);
    switch(TA1IV)
    {
    case 0x02://捕捉比较中断1
        break;
    case 0x04://捕捉比较中断2
        break;
    case 0x0A://溢出中断
        PIT1_handler();
        break;
    default:
        break;
    }
}
#pragma vector=WDT_VECTOR       // Watch dog Timer interrupt service routine
__interrupt void WDT_ISR(void)
{
    WDT_Ontime();
}
