#include "loop.h"
unsigned int tick;


void duty_1ms(void)
{

}
void duty_10ms(void)
{
    static int duty = 0;
    static int flag = 0;

    if(duty == 1000) flag = 1;
    else if(duty == 0) flag = 0;

    if(flag == 0)
    {
        duty += 10;
    }
    else
    {
        duty -= 10;
    }
    pwm_duty(GPIO2, GPIO_PIN_5,duty);

}
void duty_100ms(void)
{

}
void duty_1000ms(void)
{
    //gpio_toggle(GPIO1, GPIO_PIN_0);

}

void PIT1_handler(void)
{
    tick++;
    duty_1ms();
    if(tick%10 == 0)
    {
        duty_10ms();
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
