#include "loop.h"
unsigned int tick;

void WDT_Ontime(void)
{

}
void duty_1ms(void)
{

}

void duty_10ms(void)
{

}
void duty_25ms(void)
{
    TouchIN_Dect();
    touch_dir touch_v;
    touch_v = Touch_check();
    if(touch_v == touch_left)
    {
        gpio_set(GPIO1, GPIO_PIN_0, GPO_HIGH);
        gpio_set(GPIO2, GPIO_PIN_4, GPO_HIGH);
    }
    if(touch_v == touch_right)
    {
        gpio_set(GPIO1, GPIO_PIN_0, GPO_LOW);
        gpio_set(GPIO2, GPIO_PIN_4, GPO_LOW);
    }
    if(touch_v == touch_no)
    {

    }



}

void duty_100ms(void)
{

//    Knob_dir Knob_v;
//    static int num = 0;
//    Knob_v = Knob_check();
//    if(Knob_v == Knob_D)
//    {
//        num++;
//        if(num > 100) num = 100;
//    }
//    if(Knob_v == Knob_U)
//    {
//        num--;
//        if(num < 0) num = 0;
//    }
//    uart_putint(num);

}

void duty_1000ms(void)
{


}

void PIT1_handler(void)
{
    tick++;
    duty_1ms();
    if(tick%10 == 0)
    {
        duty_10ms();
    }
    if(tick%25 == 0)
    {
        duty_25ms();
    }
    if(tick%100 == 0)
    {
        duty_100ms();
    }
    if(tick%1000 == 0)
    {
        duty_1000ms();
    }
    if(tick >= 1000) tick = 0;
}
