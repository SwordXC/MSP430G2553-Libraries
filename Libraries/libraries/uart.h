#ifndef _UART_H_
#define _UART_H_
/* ==============================================================================
 * describe：uart.h
 * author：SwordXC/Liangliang.Zhang
 * date：2023.04.26
 * ==============================================================================*/
#include "headfile.h"

//使用时请将LaunchPad中TXD和RXD的跳线帽由竖插改为横插.
//msp430g2553中只有一对串口.
//使用USB作串口时，波特率用9600.
void uart_init(uint32_t baud);
void uart_putchar(uint8_t dat);
void uart_putstr(uint8_t *str);
void uart_putint(int dat);//-32768 - 32767  因为g2553是16位的芯片
void uart_putfloat(float dat,uint8_t num);//-999.999 - 999.999 最多保留三位小数

//void uart_putbuff(uint8_t *buff, uint32 len);
//void    uart_getchar    (UARTN_enum uartn, uint8 *dat);
//uint8   uart_query      (UARTN_enum uartn, uint8 *dat);
//void    uart_tx_irq     (UARTN_enum uartn, uint32 status);
//void    uart_rx_irq     (UARTN_enum uartn, uint32 status);

#endif
