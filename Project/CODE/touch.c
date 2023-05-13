#include "touch.h"
#include "stdint.h"

#define left  0
#define right 1

static unsigned int     FREQ_THRESHOLD_MAX[KEY_NUM] = {2500,2500};
static unsigned int     FREQ_THRESHOLD_MIN[KEY_NUM] = {1000,1000};
static unsigned int     Freq;                      //  ��ǰ��Ƶֵ
static unsigned char    Key_Buff[KEY_NUM][2]={0};           // ���FIFO
static unsigned char    Key_Num=0;                         //  �������
static uint8_t          state[KEY_NUM] ={0};
static uint8_t          num = 0;
touch_dir Touch_check()
{
    touch_dir touch_value;
    if((state[left] == 1) || (state[right] == 1))
    {
        if(state[left] == 1)
        {
            touch_value = touch_right;
            while(state[left] == 1);
            return touch_value;
        }
        else if(state[right] == 1)
        {
            touch_value = touch_left;
            while(state[right] == 1);
            return touch_value;
        }
    }
    return touch_no;
}

/******************************************************************************************************
* ��       �ƣ�Key_Measure_Freq()
* ��       �ܣ�������Ƶ��
* ��ڲ�������
* ���ڲ�������
* ˵     �� �� ����ԭ����ֱ�Ӷ�TA0����ʱ�������� ����ʹ��������ʱ�������޸Ĵ��롣
 ******************************************************************************************************/
void Key_Measure_Freq()
{
    ALL_OSC_OFF ;                                               //�ر�������IO
    switch(num)
    {
        case 0 : KEY0_INIT; Key_Num = left ;break;                          //��IO��ʼ��
        case 1 : KEY1_INIT; Key_Num = right ;break;
        default:break;
    }
    Freq=TAR/10;                                      //��ǰ��Ű�����Ƶ�ʱ����
    //uart_putint(Freq);

    num ++;                                                  //�л���һ��IO
    if (num>=KEY_NUM)       num=0;  //����������ѭ������


    TACTL = TASSEL_3+MC_2+TACLR;           //��������0������ʼ����
}
/******************************************************************************************************
* ��       �ƣ�Key_FIFO()
* ��       �ܣ�����ǰ����Ƶ�������޵�ƽ�ȽϵĽ����������4B�����FIFO
* ��ڲ�������
* ���ڲ�������
* ˵     �� �� ���FIFO�������Ǳ������4�εĲ����жϽ����
 ******************************************************************************************************/
void Key_FIFO()                                                                     //�洢����4�β�������
{
    Key_Buff[Key_Num][0]=Key_Buff[Key_Num][1];
    if( Freq>FREQ_THRESHOLD_MIN[Key_Num] && Freq<FREQ_THRESHOLD_MAX[Key_Num])          //�ж��Ƿ�ʶ��Ϊ����
        Key_Buff[Key_Num][1]=1;
    else
        Key_Buff[Key_Num][1]=0;
}
/******************************************************************************************************
* ��       �ƣ�Key_Judge()
* ��       �ܣ������������ٲá�
* ��ڲ�������
* ���ڲ�������
* ˵     �� �� ֻ������4�ζ�ʶ�𵽰������㰴�������¡�
*                   ֻ������4�ζ�ʶ�𲻵��������㰴�����ɿ���
 ******************************************************************************************************/
void Key_Judge()                                        //�����ٲã�ֻ������4�β������һ�£�������
{
    if(     (Key_Buff[Key_Num][0]==1)&&(Key_Buff[Key_Num][1]==1)  )
    {
        state[Key_Num] = 1;
    }
    else
    {
        state[Key_Num] = 0 ;

    }

}
/******************************************************************************************************
* ��       �ƣ�TouchIN_Dect()
* ��       �ܣ�����������⡣
* ��ڲ�������
* ���ڲ�������
* ˵     �� �� �ڶ�ʱ�ж��ڵ��øú�����
*                   ���øú�����ȫ�ֱ���TouchIN���൱��PxIN��
 ******************************************************************************************************/
void TouchIN_Dect()                                         //����������
{
    Key_Measure_Freq();                                     //��Ƶ
    Key_FIFO();                                                     //���FIFO�������4�β�������
    Key_Judge();                                                    //�ٲð����Ƿ��»��ɿ�
}
