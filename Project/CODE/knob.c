#include "knob.h"
#include "stdint.h"
static int res = 0;
static int res_last = 0;
static int res_dif = 0;

uint8_t res_threshold = 25;

void Knob_init(void)
{
    gpio_init(GPIO1, GPIO_PIN_3, GPO, GPO_LOW);
    gpio_init(GPIO2, GPIO_PIN_2, GPO, GPO_HIGH);
    adc_init(GPIO1, GPIO_PIN_5);
    res = adc_get();
    res_last = res;
}

Knob_dir Knob_check(void)
{
    Knob_dir Knob_value;
    res = adc_get();
//    uart_putint(res);
    res_dif = res - res_last;
    if(res_dif > 0)
    {
        if(res_dif >= res_threshold)
        {
            res_last = res;
            return Knob_D;
        }
    }
    else if(res_dif < 0)
    {
        res_dif = -res_dif;
        if(res_dif >= res_threshold)
        {
            res_last = res;
            return Knob_U;
        }
    }
    else
    {
        return Knob_N;
    }

}
