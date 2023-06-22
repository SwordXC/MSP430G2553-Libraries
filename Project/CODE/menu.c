#include "menu.h"

touch_dir touch_v;
Knob_dir Knob_v;

static uint8_t switch_mode=0;// 0:time , 1:date

uint8_t buzzer_flag = 0;
uint8_t timing_flag = 0;
uint8_t run_flag = 1;

#define timeToint 3
#define timeTotiming 10
uint8_t int_time = timeToint;
uint8_t timing_time = timeTotiming;

uint16_t date_day=14;
uint16_t date_month=6;
uint16_t date_year=2023;

uint8_t time_hour=13;
uint8_t time_min=5;
uint8_t time_sec=0;

uint8_t timing_hour=0;
uint8_t timing_min=0;

uint8_t StopWatch_ms=0;
uint8_t StopWatch_sec=0;
uint8_t StopWatch_min=0;
uint8_t StopWatch_hour=0;
uint8_t StopWatch_mode=0;


void strcpy_rewrite(char *ch, const char *_ch)
{
    while ((*ch++ = *_ch++) != '\0');
}

void Clean_Key_Position()
{
    uint8_t i = 0;
    for (i = 0; i < 8; i++) {
        oled_p8x16str(120, i, " ");
    }
}
/*菜单中去除修改参数的导航位置标志*/
void Change_Key_Position(uint8_t x, uint8_t y)
{
    oled_p8x16str(x, y, "                ");
}

void menu_main()
{
    uint8_t i=0;
    oled_fill(0x00);


    if(switch_mode)
    {
        oled_p8x16str(0,0,"DATE:");

        oled_uint16(24,4,date_year);

        oled_p8x16str(56,4,".");

        if(date_month < 10)
        {
            oled_p8x16str(64,4,"0");
            if(date_month == 0) oled_p8x16str(72,4,"0");
            else oled_uint16(72,4,date_month);
        }
        else oled_uint16(64,4,date_month);

        oled_p8x16str(80,4,".");

        if(date_day < 10)
        {
            oled_p8x16str(88,4,"0");
            if(date_day == 0) oled_p8x16str(96,4,"0");
            else oled_uint16(96,4,date_day);
        }
        else oled_uint16(88,4,date_day);
    }
    else
    {
        oled_p8x16str(0,0,"TIME:");
        if(time_hour < 10)
        {
            oled_p8x16str(32,4,"0");
            if(time_hour == 0) oled_p8x16str(40,4,"0");
            else oled_uint16(40,4,time_hour);
        }
        else oled_uint16(32,4,time_hour);

        oled_p8x16str(48,4,":");

        if(time_min < 10)
        {
            oled_p8x16str(56,4,"0");
            if(time_min == 0) oled_p8x16str(64,4,"0");
            else oled_uint16(64,4,time_min);
        }
        else oled_uint16(56,4,time_min);

        oled_p8x16str(72,4,":");

        if(time_sec < 10)
        {
            oled_p8x16str(80,4,"0");
            if(time_sec == 0) oled_p8x16str(88,4,"0");
            else oled_uint16(88,4,time_sec);
        }
        else oled_uint16(80,4,time_sec);
    }



    while(i!=1)
    {
        touch_v=Touch_check();

        if(switch_mode)
        {

            oled_uint16(24,4,date_year);

            oled_p8x16str(56,4,".");

            if(date_month < 10)
            {
                oled_p8x16str(64,4,"0");
                if(date_month == 0) oled_p8x16str(72,4,"0");
                else oled_uint16(72,4,date_month);
            }
            else oled_uint16(64,4,date_month);

            oled_p8x16str(80,4,".");

            if(date_day < 10)
            {
                oled_p8x16str(88,4,"0");
                if(date_day == 0) oled_p8x16str(96,4,"0");
                else oled_uint16(96,4,date_day);
            }
            else oled_uint16(88,4,date_day);
        }
        else
        {
            if(time_hour < 10)
            {
                oled_p8x16str(32,4,"0");
                if(time_hour == 0) oled_p8x16str(40,4,"0");
                else oled_uint16(40,4,time_hour);
            }
            else oled_uint16(32,4,time_hour);

            oled_p8x16str(48,4,":");

            if(time_min < 10)
            {
                oled_p8x16str(56,4,"0");
                if(time_min == 0) oled_p8x16str(64,4,"0");
                else oled_uint16(64,4,time_min);
            }
            else oled_uint16(56,4,time_min);

            oled_p8x16str(72,4,":");

            if(time_sec < 10)
            {
                oled_p8x16str(80,4,"0");
                if(time_sec == 0) oled_p8x16str(88,4,"0");
                else oled_uint16(88,4,time_sec);
            }
            else oled_uint16(80,4,time_sec);
            oled_p8x16str(96,4," ");
        }

        if(touch_v==touch_left)
        {
            i=1;
            oled_fill(0x00);
            menu_all();
        }
        if(touch_v==touch_right)//test
        {
            timing_time=0;
        }
    }
}

void menu_all()
{
    uint8_t i=0,j=0;
    oled_fill(0x00);
    oled_p8x16str(0,0,"200910530");
    oled_p8x16str(0,2,"1.Set Date");
    oled_p8x16str(0,4,"2.Set Clock");
    if(switch_mode == 0)
        oled_p8x16str(0,6,"3.Switch[Clock]");
    else
        oled_p8x16str(0,6,"3.Switch[Date]");
    Clean_Key_Position();
    oled_p8x16str(120,j+2,"<");
    while(i!=1)
    {
        Knob_v=Knob_check();
        touch_v=Touch_check();
        if(Knob_v==Knob_U || Knob_v==Knob_D)
        {
            if(Knob_v==Knob_U && j!=0)
            {
                j-=2;
            }
            else if(Knob_v==Knob_U&& j==0)
            {
                j+=4;
            }
            if(Knob_v==Knob_D&& j!=4)
            {
                j+=2;
            }
            else if(Knob_v==Knob_D&& j==4)
            {
                j=0;
            }
            Clean_Key_Position();
            oled_p8x16str(120,j+2,"<");
        }
        if(touch_v==touch_right)
        {
            //i=1;
            oled_fill(0x00);
            menu_main();
        }
        if(touch_v==touch_left)
        {
            switch (j)
            {
                case 0:i=1;oled_fill(0x00);menu_SetDate();break;
                case 2:i=1;oled_fill(0x00);menu_SetClock();break;
                case 4:
                    if(switch_mode==0)
                    {
                        switch_mode=1;
                        oled_p8x16str(0,6,"3.Switch[Date] ");
                    }
                    else if(switch_mode==1)
                    {
                        switch_mode=0;
                        oled_p8x16str(0,6,"3.Switch[Clock]");
                    }
                    break;
            }
        }
    }
}

void menu_SetDate()
{
    uint8_t i=0,j=0,x=0,y=0;char str[22];
    uint8_t Knob_mode=0;
    oled_fill(0x00);
    strcpy_rewrite(str,"Set Date");
    oled_p8x16str(y,x,str);
    strcpy_rewrite(str,"Date:");
    oled_p8x16str(0,2,str);
    //1
    oled_uint16(40,2,date_year);
    oled_p8x16str(72,2,".");
    if(date_month < 10)
    {
        oled_p8x16str(80,2,"0");
        oled_uint16(88,2,date_month);
    }
    else    oled_uint16(80,2,date_month);
    oled_p8x16str(96,2,".");
    if(date_day < 10)
    {
        oled_p8x16str(104,2,"0");
        oled_uint16(112,2,date_day);
    }
    else    oled_uint16(104,2,date_day);

    oled_p8x16str(40,4,"^");
    while(i!=1)
    {
        Knob_v=Knob_check();
        touch_v=Touch_check();

        if(Knob_v==Knob_U || Knob_v==Knob_D)
        {
            if(Knob_mode == 0)
            {
                if(Knob_v==Knob_U)
                {
                    if(j==0) j=7;
                    else if(j!=0) j--;
                }
                if(Knob_v==Knob_D)
                {
                    if(j==7) j=0;
                    else if(j!=7) j++;
                }
                Change_Key_Position(0,4);
                if(j>=4 && j<=5) oled_p8x16str(40+(j+1)*8,4,"^");
                else if(j>=6 && j<=7) oled_p8x16str(40+(j+2)*8,4,"^");
                else oled_p8x16str(40+j*8,4,"^");
            }
            else
            {
                if(Knob_v==Knob_D)
               {
                   switch (j)
                   {
                       case 0:
                           date_year += 1000;
                           if (date_year > 9999) date_year = 9999;
                           break;
                       case 1:
                           date_year += 100;
                           if (date_year > 9999) date_year = 9999;
                           break;
                       case 2:
                           date_year += 10;
                           if (date_year > 9999) date_year = 9999;
                           break;
                       case 3:
                           date_year++;
                           if (date_year > 9999) date_year = 9999;
                           break;
                       case 4:
                           date_month += 10;
                           if (date_month > 12) date_month = 12;
                           break;
                       case 5:
                           date_month++;
                           if (date_month > 12) date_month = 12;
                           break;
                       case 6:
                           date_day += 10;
                           if (date_day > 30) date_day = 30;
                           break;
                       case 7:
                           date_day++;
                           if (date_day > 30) date_day = 30;
                           break;
                   }
               }
               if(Knob_v==Knob_U)
               {
                   switch (j)
                   {
                       case 0:
                           date_year -= 1000;
                           if (date_year < 0) date_year = 0;
                           break;
                       case 1:
                           date_year -= 100;
                           if (date_year < 0) date_year = 0;
                           break;
                       case 2:
                           date_year -= 10;
                           if (date_year < 0) date_year = 0;
                           break;
                       case 3:
                           date_year--;
                           if (date_year < 0) date_year = 0;
                           break;
                       case 4:
                           date_month -= 10;
                           if (date_month < 1) date_month = 1;
                           break;
                       case 5:
                           date_month--;
                           if (date_month < 1) date_month = 1;
                           break;
                       case 6:
                           date_day -= 10;
                           if (date_day < 1) date_day = 1;
                           break;
                       case 7:
                           date_day--;
                           if (date_day < 1) date_day = 1;
                           break;
                   }
               }
               oled_uint16(40,2,date_year);
               if(date_month < 10)
               {
                   oled_p8x16str(80,2,"0");
                   oled_uint16(88,2,date_month);
               }
               else    oled_uint16(80,2,date_month);
               if(date_day < 10)
               {
                   oled_p8x16str(104,2,"0");
                   oled_uint16(112,2,date_day);
               }
               else    oled_uint16(104,2,date_day);
            }

        }
        if(touch_v==touch_left)
        {
           if(Knob_mode == 0) Knob_mode = 1;
           else Knob_mode = 0;
        }
        if(touch_v==touch_right)
        {
            i=1;oled_fill(0x00);menu_all();break;
        }
    }
}
void menu_SetClock()
{
     uint8_t i=0,j=0,x=0,y=0;char str[22];
     oled_fill(0x00);
     strcpy_rewrite(str,"Set Clock");
     oled_p8x16str(y,x,str);
     //1
     x+=2;y=0;
     strcpy_rewrite(str,"1.Set");
     oled_p8x16str(y,x,str);
     //2
     x+=2;y=0;
     strcpy_rewrite(str,"2.Timing");
     oled_p8x16str(y,x,str);
     //3
     x+=2;y=0;
     strcpy_rewrite(str,"3.Stopwatch");
     oled_p8x16str(y,x,str);

     Clean_Key_Position();
     strcpy_rewrite(str,"<");
     oled_p8x16str(120,j+2,str);
     while(i!=1)
     {
         Knob_v=Knob_check();
         touch_v=Touch_check();
         if(Knob_v==Knob_U || Knob_v==Knob_D)
         {
             if(Knob_v==Knob_U && j!=0)
             {
                 j-=2;
             }
             else if(Knob_v==Knob_U&& j==0)
             {
                 j+=4;
             }
             if(Knob_v==Knob_D&& j!=4)
             {
                 j+=2;
             }
             else if(Knob_v==Knob_D&& j==4)
             {
                 j=0;
             }
             Clean_Key_Position();
             strcpy_rewrite(str,"<");
             oled_p8x16str(120,j+2,str);
         }
         if(touch_v==touch_right)
         {
             i=1;
             oled_fill(0x00);
             menu_all();
             break;
         }
         if(touch_v==touch_left)
         {
             switch (j)
             {
                 case 0:i=1;oled_fill(0x00);run_flag=0;menu_SetTime();break;
                 case 2:i=1;oled_fill(0x00);timing_flag=1;menu_Timing();break;
                 case 4:i=1;oled_fill(0x00);menu_StopWatch();break;
             }
         }
     }
}

void menu_SetTime()
{
    uint8_t i=0,j=0,x=0,y=0;char str[22];
    uint8_t Knob_mode=0;
    oled_fill(0x00);
    strcpy_rewrite(str,"SetTime");
    strcpy_rewrite(str,"Time:");
    oled_p8x16str(0,2,str);
    oled_p8x16str(y,x,str);
    if(time_hour < 10)
    {
        oled_p8x16str(40,2,"0");
        if(time_hour == 0) oled_p8x16str(48,2,"0");
        else oled_uint16(48,2,time_hour);
    }
    else oled_uint16(40,2,time_hour);
    oled_p8x16str(56,2,":");
    if(time_min < 10)
    {
        oled_p8x16str(64,2,"0");
        if(time_min == 0) oled_p8x16str(72,2,"0");
        else oled_uint16(72,2,time_min);
    }
    else    oled_uint16(64,2,time_min);

    oled_p8x16str(40,4,"^");
    while(i!=1)
    {
        Knob_v=Knob_check();
        touch_v=Touch_check();

        if(Knob_v==Knob_U || Knob_v==Knob_D)
        {
            if(Knob_mode == 0)
            {
                if(Knob_v==Knob_U)
                {
                    if(j==0) j=3;
                    else if(j!=0) j--;
                }
                if(Knob_v==Knob_D)
                {
                    if(j==3) j=0;
                    else if(j!=3) j++;
                }
                Change_Key_Position(0,4);
               if(j>1) oled_p8x16str(40+(j+1)*8,4,"^");
               else oled_p8x16str(40+j*8,4,"^");

            }
            else
            {
                if(Knob_v==Knob_D)
                {
                    switch (j)
                    {
                        case 0:
                            time_hour += 10;
                            if (time_hour > 23) time_hour = 23;
                            break;
                        case 1:
                            time_hour ++;
                            if (time_hour > 23) time_hour = 23;
                            break;
                        case 2:
                            time_min += 10;
                            if (time_min > 59) time_min = 59;
                            break;
                        case 3:
                            time_min ++;
                            if (time_min > 59) time_min = 59;
                            break;
                    }
                    time_sec=0;
                }
                if(Knob_v==Knob_U)
                {
                    switch (j)
                    {
                        case 0:
                            time_hour -= 10;
                            if (time_hour < 0) time_hour = 0;
                            break;
                        case 1:
                            time_hour --;
                            if (time_hour < 0) time_hour = 0;
                            break;
                        case 2:
                            time_min -= 10;
                            if (time_min < 0) time_min = 0;
                            break;
                        case 3:
                            time_min --;
                            if (time_min < 0) time_min = 0;
                            break;
                    }
                    time_sec=0;
                }
                if(time_hour < 10)
                {
                    oled_p8x16str(40,2,"0");
                    if(time_hour == 0) oled_p8x16str(48,2,"0");
                    else oled_uint16(48,2,time_hour);
                }
                else oled_uint16(40,2,time_hour);
                oled_p8x16str(56,2,":");
                if(time_min < 10)
                {
                    oled_p8x16str(64,2,"0");
                    if(time_min == 0) oled_p8x16str(72,2,"0");
                    else oled_uint16(72,2,time_min);
                }
                else    oled_uint16(64,2,time_min);
                oled_p8x16str(80,2," ");
            }

        }
        if(touch_v==touch_left)
        {
           if(Knob_mode == 0) Knob_mode = 1;
           else Knob_mode = 0;
        }
        if(touch_v==touch_right)
        {
            i=1;oled_fill(0x00);run_flag=1;menu_SetClock();break;
        }
    }
}

void menu_Timing()
{
    uint8_t i=0,j=0,x=0,y=0;char str[22];
    uint8_t Knob_mode=0;
    oled_fill(0x00);
    strcpy_rewrite(str,"Timing");
    oled_p8x16str(y,x,str);
    strcpy_rewrite(str,"Timing:");
    oled_p8x16str(0,2,str);
    if(timing_hour < 10)
    {
        oled_p8x16str(56,2,"0");
        if(timing_hour == 0) oled_p8x16str(64,2,"0");
        else oled_uint16(64,2,timing_hour);
    }
    else oled_uint16(56,2,timing_hour);
    oled_p8x16str(72,2,":");
    if(timing_min < 10)
    {
        oled_p8x16str(80,2,"0");
        if(timing_min == 0) oled_p8x16str(88,2,"0");
        else oled_uint16(88,2,timing_min);
    }
    else    oled_uint16(80,2,timing_min);


    oled_p8x16str(56,4,"^");
    while(i!=1)
    {
        Knob_v=Knob_check();
        touch_v=Touch_check();

        if(Knob_v==Knob_U || Knob_v==Knob_D)
                {
                    if(Knob_mode == 0)
                    {
                        if(Knob_v==Knob_U)
                        {
                            if(j==0) j=3;
                            else if(j!=0) j--;
                        }
                        if(Knob_v==Knob_D)
                        {
                            if(j==3) j=0;
                            else if(j!=3) j++;
                        }
                        Change_Key_Position(0,4);
                        if(j>=2) oled_p8x16str(56+(j+1)*8,4,"^");
                        else oled_p8x16str(56+j*8,4,"^");
                    }
                    else
                    {
                        if(Knob_v==Knob_D)
                        {
                            switch (j)
                            {
                                case 0:
                                    timing_hour += 10;
                                    if (timing_hour > 23) timing_hour = 23;
                                    break;
                                case 1:
                                    timing_hour ++;
                                    if (timing_hour > 23) timing_hour = 23;
                                    break;
                                case 2:
                                    timing_min += 10;
                                    if (timing_min > 59) timing_min = 59;
                                    break;
                                case 3:
                                    timing_min ++;
                                    if (timing_min > 59) timing_min = 59;
                                    break;
                            }
                        }
                        if(Knob_v==Knob_U)
                        {
                            switch (j)
                            {
                                case 0:
                                    timing_hour -= 10;
                                    if (timing_hour < 0) timing_hour = 0;
                                    break;
                                case 1:
                                    timing_hour --;
                                    if (timing_hour < 0) timing_hour = 0;
                                    break;
                                case 2:
                                    timing_min -= 10;
                                    if (timing_min < 0) timing_min = 0;
                                    break;
                                case 3:
                                    timing_min --;
                                    if (timing_min < 0) timing_min = 0;
                                    break;
                            }
                        }
                        if(timing_hour < 10)
                        {
                            oled_p8x16str(56,2,"0");
                            if(timing_hour == 0) oled_p8x16str(64,2,"0");
                            else oled_uint16(64,2,timing_hour);
                        }
                        else oled_uint16(56,2,timing_hour);
                        oled_p8x16str(72,2,":");
                        if(timing_min < 10)
                        {
                            oled_p8x16str(80,2,"0");
                            if(timing_min == 0) oled_p8x16str(88,2,"0");
                            else oled_uint16(88,2,timing_min);
                        }
                        else    oled_uint16(80,2,timing_min);
                        oled_p8x16str(96,2," ");
                    }

                }
                if(touch_v==touch_left)
                {
                   if(Knob_mode == 0) Knob_mode = 1;
                   else Knob_mode = 0;
                }
                if(touch_v==touch_right)
                {
                    i=1;timing_flag=0;oled_fill(0x00);menu_SetClock();break;
                }
    }

}

void menu_StopWatch()
{
    uint8_t i=0,j=0,x=0,y=0;char str[22];
    oled_fill(0x00);
    strcpy_rewrite(str,"StopWatch");
    oled_p8x16str(y,x,str);
    //1
    x+=2;y=0;
    strcpy_rewrite(str,"1.St/end");
    oled_p8x16str(y,x,str);
    //2
    x+=2;y=0;
    strcpy_rewrite(str,"2.reset");
    oled_p8x16str(y,x,str);

    if(StopWatch_hour<10)
    {
        oled_p8x16str(20,6,"0");
        if(StopWatch_hour == 0) oled_p8x16str(28,6,"0");
        else oled_uint16(28,6,StopWatch_hour);
    }
    else oled_uint16(20,6,StopWatch_hour);

    oled_p8x16str(36,6,":");

    if(StopWatch_min<10)
    {
        oled_p8x16str(44,6,"0");
        if(StopWatch_min == 0) oled_p8x16str(52,6,"0");
        else oled_uint16(52,6,StopWatch_min);
    }
    else oled_uint16(44,6,StopWatch_min);

    oled_p8x16str(60,6,":");

    if(StopWatch_sec<10)
        {
            oled_p8x16str(68,6,"0");
            if(StopWatch_sec == 0) oled_p8x16str(76,6,"0");
            else oled_uint16(76,6,StopWatch_sec);
        }
    else oled_uint16(68,6,StopWatch_sec);

    oled_p8x16str(84,6,":");

    if(StopWatch_ms<10)
        {
            oled_p8x16str(92,6,"0");
            if(StopWatch_ms == 0) oled_p8x16str(100,6,"0");
            else oled_uint16(100,6,StopWatch_ms);
        }
    else oled_uint16(92,6,StopWatch_ms);

    Clean_Key_Position();
    strcpy_rewrite(str,"<");
    oled_p8x16str(120,j+2,str);
    while(i!=1)
    {
        Knob_v=Knob_check();
        touch_v=Touch_check();
        if(Knob_v==Knob_U || Knob_v==Knob_D)
        {
            if(Knob_v==Knob_U && j!=0)
            {
                j-=2;
            }
            else if(Knob_v==Knob_U&& j==0)
            {
                j+=2;
            }
            if(Knob_v==Knob_D&& j!=2)
            {
                j+=2;
            }
            else if(Knob_v==Knob_D&& j==2)
            {
                j=0;
            }
            Clean_Key_Position();
            strcpy_rewrite(str,"<");
            oled_p8x16str(120,j+2,str);
        }
        if(touch_v==touch_right)
        {
            i=1;
            StopWatch_mode=0;
            oled_fill(0x00);
            menu_SetClock();
            break;
        }
        if(touch_v==touch_left)
        {
            switch (j)
            {
                case 0:
                    if (StopWatch_mode == 0) StopWatch_mode = 1;
                    else if (StopWatch_mode == 1) StopWatch_mode = 0;
                    break;
                case 2:
                    StopWatch_mode = 0;
                    StopWatch_hour = 0;
                    StopWatch_min = 0;
                    StopWatch_sec = 0;
                    StopWatch_ms = 0;
                    break;
            }
        }
        if(StopWatch_hour<10)
            {
                oled_p8x16str(20,6,"0");
                if(StopWatch_hour == 0) oled_p8x16str(28,6,"0");
                else oled_uint16(28,6,StopWatch_hour);
            }
            else oled_uint16(20,6,StopWatch_hour);

            oled_p8x16str(36,6,":");

            if(StopWatch_min<10)
            {
                oled_p8x16str(44,6,"0");
                if(StopWatch_min == 0) oled_p8x16str(52,6,"0");
                else oled_uint16(52,6,StopWatch_min);
            }
            else oled_uint16(44,6,StopWatch_min);

            oled_p8x16str(60,6,":");

            if(StopWatch_sec<10)
                {
                    oled_p8x16str(68,6,"0");
                    if(StopWatch_sec == 0) oled_p8x16str(76,6,"0");
                    else oled_uint16(76,6,StopWatch_sec);
                }
            else oled_uint16(68,6,StopWatch_sec);

            oled_p8x16str(84,6,":");

            if(StopWatch_ms<10)
                {
                    oled_p8x16str(92,6,"0");
                    if(StopWatch_ms == 0) oled_p8x16str(100,6,"0");
                    else oled_uint16(100,6,StopWatch_ms);
                }
            else oled_uint16(92,6,StopWatch_ms);
    }
}

void time_run(void)
{
    if(run_flag)
    {
        time_sec++;
        if(time_sec >59 )
        {
            time_sec = 0;
            time_min ++;
        }
        if(time_min >59)
        {
            time_min = 0;
            time_hour ++;
        }
        if(time_hour >23)
        {
            time_hour = 0;
            date_day++;
        }
        if(date_day > 30)//简约处理
        {
            date_day = 1;
            date_month++;
        }
        if(date_month >12)
        {
            date_month = 1;
            date_year ++;
        }
    }
}
void timing_run(void)
{
    if(StopWatch_mode)
    {
        StopWatch_ms++;
        if(StopWatch_ms >99)
        {
            StopWatch_ms = 0;
            StopWatch_sec ++;
        }
        if(StopWatch_sec>59)
        {
            StopWatch_sec = 0;
            StopWatch_min ++;
        }
        if(StopWatch_min >59)
        {
            StopWatch_min = 0;
            StopWatch_hour ++;
        }
        if(StopWatch_hour >23)
        {
            StopWatch_hour = 23;
        }
    }
}

void buzzer_int(void)
{

    if(run_flag)
    {
        if(time_min == 0)
        {
            while(int_time!=0 && buzzer_flag!=1)
            {
                buzzer_flag = 1;
                int_time--;
            }
        }
        else int_time=timeToint;
    }




}
void buzzer_timing(void)
{
    if(run_flag && timing_flag!=1)
    {
        if(timing_hour == time_hour && timing_min == time_min)
        {

            while(timing_time!=0 && buzzer_flag!=1)
            {
                buzzer_flag = 1;
                timing_time--;
            }

        }
        else timing_time = timeTotiming;
    }

}
