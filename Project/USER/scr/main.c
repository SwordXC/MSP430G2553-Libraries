#include "headfile.h"

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

    uart_init(9600);
    gpio_init(GPIO1, GPIO_PIN_6, GPI, GPI_PULL_UP);
    pwm_init(GPIO2,GPIO_PIN_5,2000,0);
	exti_interrupt_init(GPIO1, GPIO_PIN_3, DOWN);//��ʼ���ⲿ�ж�
	tim_interrupt_init_ms(1);
    __bis_SR_register(GIE);//��ȫ���ж�
	while(1)
	{

	}
}


