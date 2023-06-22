#include "loop.h"
#include "menu.h"

#define buzzer_on gpio_set(GPIO2, GPIO_PIN_4, GPO_HIGH)
#define buzzer_off gpio_set(GPIO2, GPIO_PIN_4, GPO_LOW)

unsigned int tick;

uint8_t buzzer_time;

void WDT_Ontime(void)
{

}
void duty_1ms(void)
{
    if(buzzer_flag && buzzer_time < 150)
    {
        buzzer_on;
        buzzer_time ++;
    }
    else
    {
        buzzer_off;
        buzzer_flag = 0;
        buzzer_time = 0;
    }
}

void duty_10ms(void)
{
    timing_run();
}
void duty_25ms(void)
{
    TouchIN_Dect();
    Knob_Dect();
//    touch_dir touch_v;
//    touch_v = Touch_check();
//    if(touch_v == touch_left)
//    {
//        gpio_set(GPIO1, GPIO_PIN_0, GPO_HIGH);
//        gpio_set(GPIO2, GPIO_PIN_4, GPO_HIGH);
//    }
//    if(touch_v == touch_right)
//    {
//        gpio_set(GPIO1, GPIO_PIN_0, GPO_LOW);
//        gpio_set(GPIO2, GPIO_PIN_4, GPO_LOW);
//    }
//    if(touch_v == touch_no)
//    {
//
//    }



}

void duty_100ms(void)
{



}

void duty_1000ms(void)
{
    time_run();
    buzzer_int();
    buzzer_timing();

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
