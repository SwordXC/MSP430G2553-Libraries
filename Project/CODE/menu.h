/* ==============================================================================
 * describe£ºmenu.h
 * author£ºSwordXC/Liangliang.Zhang
 * date£º2023.05.26
 * ==============================================================================*/

#ifndef _MENU_H_
#define _MENU_H_

#include "headfile.h"

extern uint8_t buzzer_flag;

extern uint16_t date_day;
extern uint16_t date_month;
extern uint16_t date_year;

extern uint8_t time_hour;
extern uint8_t time_min;
extern uint8_t time_sec;

extern uint8_t timing_hour;
extern uint8_t timing_min;

extern uint8_t StopWatch_ms;
extern uint8_t StopWatch_sec;
extern uint8_t StopWatch_min;
extern uint8_t StopWatch_hour;
extern uint8_t StopWatch_mode;


void menu_main(void);
void menu_all(void);
void menu_SetDate(void);
void menu_SetClock(void);
void menu_SetTime(void);
void menu_Timing(void);
void menu_StopWatch(void);

void time_run(void);
void timing_run(void);
void buzzer_int(void);
void buzzer_timing(void);

#endif
