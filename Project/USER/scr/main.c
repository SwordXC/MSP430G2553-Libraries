#include "headfile.h"

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	gpio_init(GPIO1, GPIO_PIN_6, GPI, GPI_PULL_UP);
	gpio_init(GPIO1, GPIO_PIN_0, GPO, GPO_LOW);
	gpio_init(GPIO1, GPIO_PIN_3, GPI,GPI_PULL_UP);

	pwm_init(GPIO2, GPIO_PIN_4, 2000, 0);
    uart_init(9600);
    adc_init(GPIO1,GPIO_PIN_4);
	exti_interrupt_init(GPIO1, GPIO_PIN_3, DOWN);//初始化外部中断
	tim_interrupt_init_ms(1);
    __bis_SR_register(GIE);//打开全局中断
	while(1)
	{

	}
}


