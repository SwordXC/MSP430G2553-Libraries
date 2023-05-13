#include "touch.h"
#include "stdint.h"

#define left  0
#define right 1

static unsigned int     FREQ_THRESHOLD_MAX[KEY_NUM] = {2500,2500};
static unsigned int     FREQ_THRESHOLD_MIN[KEY_NUM] = {1000,1000};
static unsigned int     Freq;                      //  当前测频值
static unsigned char    Key_Buff[KEY_NUM][2]={0};           // 软件FIFO
static unsigned char    Key_Num=0;                         //  按键编号
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
* 名       称：Key_Measure_Freq()
* 功       能：测量振荡频率
* 入口参数：无
* 出口参数：无
* 说     明 ： 测量原理是直接对TA0主定时器读数。 如需使用其他定时器，需修改代码。
 ******************************************************************************************************/
void Key_Measure_Freq()
{
    ALL_OSC_OFF ;                                               //关闭所有振荡IO
    switch(num)
    {
        case 0 : KEY0_INIT; Key_Num = left ;break;                          //振荡IO初始化
        case 1 : KEY1_INIT; Key_Num = right ;break;
        default:break;
    }
    Freq=TAR/10;                                      //当前编号按键的频率被测得
    //uart_putint(Freq);

    num ++;                                                  //切换下一振荡IO
    if (num>=KEY_NUM)       num=0;  //各触摸按键循环交替


    TACTL = TASSEL_3+MC_2+TACLR;           //增计数清0，并开始计数
}
/******************************************************************************************************
* 名       称：Key_FIFO()
* 功       能：将当前所测频率与门限电平比较的结果，缓存入4B的软件FIFO
* 入口参数：无
* 出口参数：无
* 说     明 ： 软件FIFO的作用是保存最近4次的测量判断结果。
 ******************************************************************************************************/
void Key_FIFO()                                                                     //存储连续4次测量数据
{
    Key_Buff[Key_Num][0]=Key_Buff[Key_Num][1];
    if( Freq>FREQ_THRESHOLD_MIN[Key_Num] && Freq<FREQ_THRESHOLD_MAX[Key_Num])          //判断是否识别为按键
        Key_Buff[Key_Num][1]=1;
    else
        Key_Buff[Key_Num][1]=0;
}
/******************************************************************************************************
* 名       称：Key_Judge()
* 功       能：按键抗干扰仲裁。
* 入口参数：无
* 出口参数：无
* 说     明 ： 只有连续4次都识别到按键才算按键被按下。
*                   只有连续4次都识别不到按键才算按键被松开。
 ******************************************************************************************************/
void Key_Judge()                                        //按键仲裁，只有连续4次测量结果一致，才算数
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
* 名       称：TouchIN_Dect()
* 功       能：触摸按键检测。
* 入口参数：无
* 出口参数：无
* 说     明 ： 在定时中断内调用该函数。
*                   调用该函数后，全局变量TouchIN就相当于PxIN了
 ******************************************************************************************************/
void TouchIN_Dect()                                         //触摸输入检测
{
    Key_Measure_Freq();                                     //测频
    Key_FIFO();                                                     //软件FIFO缓存最近4次测量数据
    Key_Judge();                                                    //仲裁按键是否按下或松开
}
