#include "headfile.h"

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

    uart_init(9600);
    gpio_init(GPIO1, GPIO_PIN_0, GPO, GPO_LOW);
    tim_interrupt_init_ms(A1,1);

    __bis_SR_register(GIE);//打开全局中断
	while(1)
	{

	}
}



