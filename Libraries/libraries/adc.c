#include "adc.h"

//----------------------------------------------------------------
// @brief       ADC��ʼ��
// @param       type        ѡ������Ŵ��� [GPIO1/GPIO2]
// @param       pin         �������� (GPIO_PIN_0 - GPIO_PIN_7)
// @return      void
// Sample usage:            adc_init(GPIO1, GPIO_PIN_4);
//----------------------------------------------------------------
void adc_init(PIN_type type,PIN_enum pin)
{
    ADC10CTL1 |= ADC10SSEL_2;   //����ADCʱ��MCLK
    ADC10CTL1 |= ADC10DIV_0;    //ADC 2��Ƶ
    ADC10CTL0 |= SREF_1;        //����ADC��׼Դ
    ADC10CTL0 |= ADC10SHT_3;    //����ADC��������ʱ��64CLK
    ADC10CTL0 &= ~ADC10SR;      //����ADC������200k
    ADC10CTL0 |= REF2_5V;       //ADC��׼ѡ��2.5V
    ADC10CTL0 |= REFON;         //������׼
    switch(pin)
    {
    case GPIO_PIN_0:
        ADC10CTL1 |= INCH_0;        //ѡ��ADC����ͨ��A0
        break;
    case GPIO_PIN_1:
        ADC10CTL1 |= INCH_1;        //ѡ��ADC����ͨ��A1
        break;
    case GPIO_PIN_2:
        ADC10CTL1 |= INCH_2;        //ѡ��ADC����ͨ��A2
        break;
    case GPIO_PIN_3:
        ADC10CTL1 |= INCH_3;        //ѡ��ADC����ͨ��A3
        break;
    case GPIO_PIN_4:
        ADC10CTL1 |= INCH_4;        //ѡ��ADC����ͨ��A4
        break;
    case GPIO_PIN_5:
        ADC10CTL1 |= INCH_5;        //ѡ��ADC����ͨ��A5
        break;
    case GPIO_PIN_6:
        ADC10CTL1 |= INCH_6;        //ѡ��ADC����ͨ��A6
        break;
    case GPIO_PIN_7:
        ADC10CTL1 |= INCH_7;        //ѡ��ADC����ͨ��A7
        break;
    }
    ADC10AE0 |= pin;           //����ģ������
    ADC10CTL0 |= ADC10ON;       //����ADC
}
//----------------------------------------------------------------
// @brief       ��ȡADC�ɼ�����ֵ
// @return      void
// Sample usage:            date = adc_get();
//----------------------------------------------------------------
uint16_t adc_get(void)
{
    ADC10CTL0 |= ADC10SC | ENC;
    while(ADC10CTL1 & ADC10BUSY);
    return ADC10MEM;
}

