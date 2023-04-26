#include "adc.h"

//----------------------------------------------------------------
// @brief       ADC初始化
// @param       type        选择的引脚大类 [GPIO1/GPIO2]
// @param       pin         具体引脚 (GPIO_PIN_0 - GPIO_PIN_7)
// @return      void
// Sample usage:            adc_init(GPIO1, GPIO_PIN_4);
//----------------------------------------------------------------
void adc_init(PIN_type type,PIN_enum pin)
{
    ADC10CTL1 |= ADC10SSEL_2;   //设置ADC时钟MCLK
    ADC10CTL1 |= ADC10DIV_0;    //ADC 2分频
    ADC10CTL0 |= SREF_1;        //设置ADC基准源
    ADC10CTL0 |= ADC10SHT_3;    //设置ADC采样保持时间64CLK
    ADC10CTL0 &= ~ADC10SR;      //设置ADC采样率200k
    ADC10CTL0 |= REF2_5V;       //ADC基准选择2.5V
    ADC10CTL0 |= REFON;         //开启基准
    switch(pin)
    {
    case GPIO_PIN_0:
        ADC10CTL1 |= INCH_0;        //选择ADC输入通道A0
        break;
    case GPIO_PIN_1:
        ADC10CTL1 |= INCH_1;        //选择ADC输入通道A1
        break;
    case GPIO_PIN_2:
        ADC10CTL1 |= INCH_2;        //选择ADC输入通道A2
        break;
    case GPIO_PIN_3:
        ADC10CTL1 |= INCH_3;        //选择ADC输入通道A3
        break;
    case GPIO_PIN_4:
        ADC10CTL1 |= INCH_4;        //选择ADC输入通道A4
        break;
    case GPIO_PIN_5:
        ADC10CTL1 |= INCH_5;        //选择ADC输入通道A5
        break;
    case GPIO_PIN_6:
        ADC10CTL1 |= INCH_6;        //选择ADC输入通道A6
        break;
    case GPIO_PIN_7:
        ADC10CTL1 |= INCH_7;        //选择ADC输入通道A7
        break;
    }
    ADC10AE0 |= pin;           //允许模拟输入
    ADC10CTL0 |= ADC10ON;       //开启ADC
}
//----------------------------------------------------------------
// @brief       获取ADC采集到的值
// @return      void
// Sample usage:            date = adc_get();
//----------------------------------------------------------------
uint16_t adc_get(void)
{
    ADC10CTL0 |= ADC10SC | ENC;
    while(ADC10CTL1 & ADC10BUSY);
    return ADC10MEM;
}

