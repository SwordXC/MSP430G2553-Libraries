#include "headfile.h"

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

//	TCA6416A_Init();
//	HT1621_init();
    uart_init(9600);
    Knob_init();
    gpio_init(GPIO1, GPIO_PIN_0, GPO, GPO_LOW);

//    LCD_Clear();
//    LCD_DisplayDigit(1,1);
    tim_interrupt_init_ms(A1,1);
    __bis_SR_register(GIE);//打开全局中断
	while(1)
	{


	}
}



