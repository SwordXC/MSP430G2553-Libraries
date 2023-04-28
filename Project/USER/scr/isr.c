#include "isr.h"
#include "headfile.h"
#include "loop.h"

#pragma vector = PORT1_VECTOR
__interrupt void Port1_ISR(void)
{
    if(P1IFG & GPIO_PIN_3)
    {
        P1IFG &= ~GPIO_PIN_3;//清中断标志
    }
}

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

#pragma vector = PORT2_VECTOR
__interrupt void Port2_ISR(void)
{

}

#pragma vector = TIMER0_A1_VECTOR
__interrupt void Time_Tick(void)
{
    if(TA0IV == 0x0A)
    {
        PIT1_handler();
    }
}

