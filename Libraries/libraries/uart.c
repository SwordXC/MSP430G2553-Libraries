#include "uart.h"


//---------------------------------------------------------
// @brief       串口初始化
// @param       baud         要发送的字节
// @return      void
// Sample usage:            uart_init(9600);
//---------------------------------------------------------
void uart_init(uint32_t baud)
{
    InitSystemClock();
    /*复位USCI_Ax*/
    UCA0CTL1 |= UCSWRST;
    /*选择USCI_Ax为UART模式*/
    UCA0CTL0 &= ~UCSYNC;
    /*配置UART时钟源为SMCLK*/
    UCA0CTL1 |= UCSSEL1;

    /*配置波特率为9600@1MHZ*/
    switch(baud)
    {
    case 9600:
        UCA0BR0 = 0x68;
        UCA0BR1 = 0x00;
        UCA0MCTL = 1 << 1;
        break;
    case 19200:
        UCA0BR0 = 0x34;
        UCA0BR1 = 0x00;
        break;
    case 38400:
        UCA0BR0 = 0x1A;
        UCA0BR1 = 0x00;
        break;
    case 56000:
        UCA0BR0 = 0x11;
        UCA0BR1 = 0x00;
        UCA0MCTL = 7 << 1;
        break;
    case 115200:
        UCA0BR0 = 0x08;
        UCA0BR1 = 0x00;
        UCA0MCTL = 6 << 1;
        break;
    }

    /*使能端口复用*/
    P1SEL |= BIT1 + BIT2;
    P1SEL2 |= BIT1 + BIT2;
    /*清楚复位位，使能UART*/
    UCA0CTL1 &= ~UCSWRST;

    //接收中断启用
    IE2 |= UCA0RXIE;
    //清空接收中断标志
    IFG2 &= ~UCA0RXIFG;
}
//---------------------------------------------------------
// @brief       串口发送字节
// @param       dat         要发送的字节
// @return      void
// Sample usage:            uart_putchar('A');
//---------------------------------------------------------
void uart_putchar(uint8_t dat)
{
    UCA0TXBUF = dat;
    while(UCA0STAT & UCBUSY);

}
//---------------------------------------------------------
// @brief       串口发送字符串
// @param       dat         要发送的字符串
// @return      void
// Sample usage:            uart_putstr("Hello,Wolrd!");
//---------------------------------------------------------
void uart_putstr(uint8_t *str)
{
    while(*str)
    {
        uart_putchar(*str++);
    }
}
//----------------------------------------------------------
// @brief       串口发送整数
// @param       dat         要发送的整数 范围:-32767 - 32767
// @return      void
// Sample usage:            uart_putint(date);
//----------------------------------------------------------
void uart_putint(int dat)
{
    int number,den = 0;
    uint8_t buff[10] = {0};
    uint8_t count = 0,i,neg = 0;
    number = dat;
    if(number < 0)
    {
        number = -number;
        neg = 1;
    }
    do
    {
        number=number/10;
        count++;
    }while(number!=0);

    switch(count)
    {
    case 1:
        den = 1;
        break;
    case 2:
        den = 10;
        break;
    case 3:
        den = 100;
        break;
    case 4:
        den = 1000;
        break;
    case 5:
        den = 10000;
        break;
    }

    number = dat;
    if(number < 0) number = -number;

    if(neg == 1)
    {
        buff[0]='-';
        for(i = 1;i < count+1;i++)
        {
            buff[i] = (uint8_t)(number / den) + '0';
            number = number % den;
            den = den/10;
        }
        buff[count+1]='\n';
    }
    else
    {
        for(i = 0;i < count;i++)
        {
            buff[i] = (uint8_t)(number / den) + '0';
            number = number % den;
            den = den/10;
        }
        buff[count]='\n';
    }

    uart_putstr(buff);
}
//-------------------------------------------------------------------------------------------------------------------
// @brief       串口发送浮点数
// @param       dat         要发送的浮点数 范围:-999.9999 - 999.9999
// @param       num         要保留的小数   范围:0 - 3
// @return      void
// Sample usage:            uart_putfloat(date,3);
//-------------------------------------------------------------------------------------------------------------------
void uart_putfloat(float dat,uint8_t num)
{
    int Integers = 0,decimals = 0,k;
    float frac_part = 0,pow_ten = 1.0;
    uint8_t buff[20] = {0},den = 0;
    uint8_t count = 0,neg = 0,i = 0;
    Integers = (int)dat;
    if(Integers < 0)
    {
        Integers = -Integers;
        neg = 1;
    }
    do
    {
        Integers=Integers/10;
        count++;
    }while(Integers!=0);

    switch(count)
    {
    case 1:
        den = 1;
        break;
    case 2:
        den = 10;
        break;
    case 3:
        den = 100;
        break;
    case 4:
        den = 1000;
        break;
    case 5:
        den = 10000;
        break;
    }

    Integers = (int)dat;
    if(Integers < 0) Integers = -Integers;

    if(neg == 1)
    {
        buff[0]='-';
        for(i = 1;i < count+1;i++)
        {
            buff[i] = (uint8_t)(Integers / den) + '0';
            Integers = Integers % den;
            den = den/10;
        }
        buff[count+1] = '.';
    }
    else
    {
        for(i = 0;i < count;i++)
        {
            buff[i] = (uint8_t)(Integers / den) + '0';
            Integers = Integers % den;
            den = den/10;
        }
        buff[count] = '.';
    }

    Integers = (int)dat;
    if(Integers < 0) Integers = -Integers;
    if(dat < 0) dat = - dat;
    frac_part = dat - Integers;

    switch(num)
    {
    case 1:
        k = 10;
        break;
    case 2:
        k = 100;
        break;
    case 3:
        k = 1000;
        break;
    }
    for(i = 0;i < num; i++)
    {
        pow_ten *= 10;
        decimals +=(int)(frac_part * pow_ten) % 10 * (int)k / pow_ten;
    }
    uart_putstr(buff);
    uart_putint(decimals);
}
