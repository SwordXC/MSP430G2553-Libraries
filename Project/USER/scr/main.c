#include "headfile.h"
int i;
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

    uart_init(9600);
    Knob_init();
    oled_init();
    oled_p8x16str(0,0,"Hello,World!");
    gpio_init(GPIO1, GPIO_PIN_0, GPO, GPO_LOW);
    gpio_init(GPIO2, GPIO_PIN_4, GPO, GPO_LOW);
    tim_interrupt_init_ms(A1,1);
    oled_p8x16str(0,2,"I'm SwordXC.");
    __bis_SR_register(GIE);//打开全局中断
	while(1)
	{

	}
}



