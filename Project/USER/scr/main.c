#include "headfile.h"

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer


    Knob_init();
    oled_init();
    gpio_init(GPIO1, GPIO_PIN_0, GPO, GPO_LOW);
    gpio_init(GPIO2, GPIO_PIN_4, GPO, GPO_LOW);
    tim_interrupt_init_ms(A1,1);
    __bis_SR_register(GIE);//打开全局中断
	while(1)
	{
	    menu_all();
	}
}



