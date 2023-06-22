#ifndef _OLED_H_
#define _OLED_H_

#include "headfile.h"

#define OLED_SCL_PIN  P17
#define OLED_SDA_PIN  P16
#define OLED_REST_PIN P23       //液晶复位引脚定义
#define OLED_DC_PIN   P21       //液晶命令位引脚定义
#define OLED_CS_PIN   P14       //定义SPI_CS引脚


#define OLED_SCL_0   gpio_init(GPIO1, GPIO_PIN_7, GPO, GPO_LOW)
#define OLED_SDA_0   gpio_init(GPIO1, GPIO_PIN_6, GPO, GPO_LOW)
#define OLED_RST_0   gpio_init(GPIO2, GPIO_PIN_3, GPO, GPO_LOW)
#define OLED_DC_0    gpio_init(GPIO2, GPIO_PIN_1, GPO, GPO_LOW)
#define OLED_CS_0    gpio_init(GPIO1, GPIO_PIN_4, GPO, GPO_LOW)

#define OLED_SCL_1   gpio_init(GPIO1, GPIO_PIN_7, GPO, GPO_HIGH)
#define OLED_SDA_1   gpio_init(GPIO1, GPIO_PIN_6, GPO, GPO_HIGH)
#define OLED_RST_1   gpio_init(GPIO2, GPIO_PIN_3, GPO, GPO_HIGH)
#define OLED_DC_1    gpio_init(GPIO2, GPIO_PIN_1, GPO, GPO_HIGH)
#define OLED_CS_1    gpio_init(GPIO1, GPIO_PIN_4, GPO, GPO_HIGH)

//-----------------------------------------------

//定义显示方向
//0 横屏模式
//1 横屏模式  旋转180
#define OLED_DISPLAY_DIR 0

#if (0==OLED_DISPLAY_DIR || 1==OLED_DISPLAY_DIR)
#define X_WIDTH         128
#define Y_WIDTH         64

#else
#error "OLED_DISPLAY_DIR 定义错误"

#endif

#define Brightness      0x7f    //设置OLED亮度  越大越亮    范围0-0XFF
#define XLevelL         0x00
#define XLevelH         0x10
#define XLevel          ((XLevelH&0x0F)*16+XLevelL)
#define Max_Column      128
#define Max_Row         64





//--------------------软件SPI--------------------
void oled_init(void);
void oled_fill(uint8_t dat);
void oled_set_pos(uint8_t x, uint8_t y);
void oled_putpixel(uint8_t x,uint8_t y,uint8_t data1);
void oled_clrpixel(uint8_t x,uint8_t y);
void oled_p6x8str(uint8_t x,uint8_t y,const int8_t ch[]);
void oled_p8x16str(uint8_t x,uint8_t y,const int8_t ch[]);
void oled_uint16(uint8_t x, uint8_t y, uint16_t num);
void oled_int16(uint8_t x, uint8_t y, int16_t num);
void oled_printf_int32(uint16_t x,uint16_t y,int32_t dat,uint8_t num);
void oled_printf_float(uint16_t x,uint16_t y,double dat,uint8_t num,uint8_t pointnum);
void oled_dis_bmp(uint16_t high, uint16_t width, uint8_t *p,uint8_t value);
void oled_print_chinese(uint8_t x, uint8_t y, uint8_t size, const uint8_t *p, uint8_t len);


#endif


