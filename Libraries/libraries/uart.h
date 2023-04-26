#ifndef _UART_H_
#define _UART_H_
/* ==============================================================================
 * describe��uart.h
 * author��SwordXC/Liangliang.Zhang
 * date��2023.04.26
 * ==============================================================================*/
#include "headfile.h"

//ʹ��ʱ�뽫LaunchPad��TXD��RXD������ñ�������Ϊ���.
//msp430g2553��ֻ��һ�Դ���.
//ʹ��USB������ʱ����������9600.
void uart_init(uint32_t baud);
void uart_putchar(uint8_t dat);
void uart_putstr(uint8_t *str);
void uart_putint(int dat);//-32768 - 32767  ��Ϊg2553��16λ��оƬ
void uart_putfloat(float dat,uint8_t num);//-999.999 - 999.999 ��ౣ����λС��

//void uart_putbuff(uint8_t *buff, uint32 len);
//void    uart_getchar    (UARTN_enum uartn, uint8 *dat);
//uint8   uart_query      (UARTN_enum uartn, uint8 *dat);
//void    uart_tx_irq     (UARTN_enum uartn, uint32 status);
//void    uart_rx_irq     (UARTN_enum uartn, uint32 status);

#endif
