#include "FONT.h"
#include "OLED.h"


//-------------------------------------------------------------------------------------------------------------------
//  @brief      �ڲ����ã��û��������
//  @param      void
//  @return
//  @since      v1.0
//  Sample usage:
//-------------------------------------------------------------------------------------------------------------------
void oled_wrdat(uint8_t dat)
{
    uint8_t i=8;

    OLED_CS_0; //ʹ���źŶˣ�����ʱ����ʹ��
    OLED_DC_1;
    OLED_SCL_0;
    while(i--)
    {
        if(dat&0x80){OLED_SDA_1;}
        else{OLED_SDA_0;}
        OLED_SCL_1;

        OLED_SCL_0;
        dat<<=1;
    }
    OLED_CS_1; //ʹ���źŶˣ�����ʱ����ʹ��
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      �ڲ����ã��û��������
//  @param      void
//  @return
//  @since      v1.0
//  Sample usage:
//-------------------------------------------------------------------------------------------------------------------
void oled_wrcmd(uint8_t cmd)
{
    uint8_t i=8;

    OLED_CS_0; //ʹ���źŶˣ�����ʱ����ʹ��
    OLED_DC_0;
    OLED_SCL_0;;

    while(i--)
    {
        if(cmd&0x80){OLED_SDA_1;}
        else{OLED_SDA_0;}
        OLED_SCL_1;

        OLED_SCL_0;
        cmd<<=1;
    }
    OLED_CS_1; //ʹ���źŶˣ�����ʱ����ʹ��
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      �ڲ����ã��û��������
//  @param      void
//  @return
//  @since      v1.0
//  Sample usage:
//-------------------------------------------------------------------------------------------------------------------
void oled_hexascii(uint16_t hex,int8_t * Print)
{
    uint8_t hexcheck ;
    uint8_t TEMP ;
    TEMP = 6 ;
    Print[TEMP ]='\0';
    while(TEMP)
    {
        TEMP -- ;
        hexcheck  =  hex%10 ;
        hex   /=10 ;
        Print[TEMP ]  = hexcheck + 0x30 ;
    }

}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      OLED��ʼ������
//  @param      NULL
//  @return     void
//  @since      v1.0
//  Sample usage:
//-------------------------------------------------------------------------------------------------------------------
void oled_init(void)
{

    OLED_CS_1;
    OLED_SCL_1;

    OLED_RST_0;
    __delay_cycles(500000);
    OLED_RST_1;

    oled_wrcmd(0xae);//--turn off oled panel
    oled_wrcmd(0x00);//---set low column address
    oled_wrcmd(0x10);//---set high column address
    oled_wrcmd(0x40);//--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
    oled_wrcmd(0x81);//--set contrast control register
    oled_wrcmd(Brightness); // Set SEG Output Current Brightness

#if (0 == OLED_DISPLAY_DIR)
    oled_wrcmd(0xa1);//--Set SEG/Column Mapping     0xa0���ҷ��� 0xa1����
    oled_wrcmd(0xc8);//Set COM/Row Scan Direction   0xc0���·��� 0xc8����
#else
    oled_wrcmd(0xa0);//--Set SEG/Column Mapping     0xa0���ҷ��� 0xa1����
    oled_wrcmd(0xc0);//Set COM/Row Scan Direction   0xc0���·��� 0xc8����
#endif

    oled_wrcmd(0xa6);//--set normal display
    oled_wrcmd(0xa8);//--set multiplex ratio(1 to 64)
    oled_wrcmd(0x3f);//--1/64 duty
    oled_wrcmd(0xd3);//-set display offset  Shift Mapping RAM Counter (0x00~0x3F)
    oled_wrcmd(0x00);//-not offset
    oled_wrcmd(0xd5);//--set display clock divide ratio/oscillator frequency
    oled_wrcmd(0x80);//--set divide ratio, Set Clock as 100 Frames/Sec
    oled_wrcmd(0xd9);//--set pre-charge period
    oled_wrcmd(0xf1);//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
    oled_wrcmd(0xda);//--set com pins hardware configuration
    oled_wrcmd(0x12);
    oled_wrcmd(0xdb);//--set vcomh
    oled_wrcmd(0x40);//Set VCOM Deselect Level
    oled_wrcmd(0x20);//-Set Page Addressing Mode (0x00/0x01/0x02)
    oled_wrcmd(0x02);//
    oled_wrcmd(0x8d);//--set Charge Pump enable/disable
    oled_wrcmd(0x14);//--set(0x10) disable
    oled_wrcmd(0xa4);// Disable Entire Display On (0xa4/0xa5)
    oled_wrcmd(0xa6);// Disable Inverse Display On (0xa6/a7)
    oled_wrcmd(0xaf);//--turn on oled panel
    oled_fill(0x00);  //��ʼ����
    oled_set_pos(0,0);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      OLED��ʾ��������
//  @param      x           x����������0-127
//  @param      y           y����������0-7
//  @return     void
//  @since      v1.0
//  Sample usage:
//-------------------------------------------------------------------------------------------------------------------
void oled_set_pos(uint8_t x, uint8_t y)
{


    oled_wrcmd(0xb0+y);
    oled_wrcmd(((x&0xf0)>>4)|0x10);
    oled_wrcmd((x&0x0f)|0x00);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      OLED��������
//  @param      bmp_data    �����ɫѡ��(0x00 or 0xff)
//  @return     void
//  @since      v1.0
//  Sample usage:
//-------------------------------------------------------------------------------------------------------------------
void oled_fill(uint8_t bmp_data)
{
    uint8_t y,x;

    for(y=0;y<8;y++)
    {
        oled_wrcmd(0xb0+y);
        oled_wrcmd(0x01);
        oled_wrcmd(0x10);
        for(x=0;x<X_WIDTH;x++)  oled_wrdat(bmp_data);
    }
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      OLED����һ��������8�����صĵ�����Ϩ��
//  @param      x           x����������0-127
//  @param      y           y����������0-7
//  @return     void
//  @since      v1.0
//  Sample usage:           oled_putpixel(0,0,0xff);//��0,0���� 8����ȫ������
//  Sample usage:           oled_putpixel(0,0,0x01);//��0,0���� ���λ��������7��Ϩ��
//  @note                   ͬ�������������һ��������8�����صĵ�����Ϩ��
//-------------------------------------------------------------------------------------------------------------------
void oled_putpixel(uint8_t x,uint8_t y,uint8_t data1)
{
    oled_set_pos(x,y);
    oled_wrcmd(0xb0+y);
    oled_wrcmd(((x&0xf0)>>4)|0x10);
    oled_wrcmd((x&0x0f)|0x00);
    oled_wrdat(data1);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      OLED�ر�һ��������������
//  @param      x           x����������0-127
//  @param      y           y����������0-7
//  @return     void
//  @since      v1.0
//  Sample usage:
//-------------------------------------------------------------------------------------------------------------------
void oled_clrpixel(uint8_t x,uint8_t y)
{
    oled_set_pos(x,y);
    oled_wrcmd(0xb0+y);
    oled_wrcmd(((x&0xf0)>>4)|0x10);
    oled_wrcmd((x&0x0f)|0x00);
    oled_wrdat(0x00);
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      OLED��ʾ�ַ���(6*8����)
//  @param      x           x����������0-127
//  @param      y           y����������0-7
//  @param      ch[]        �ַ���
//  @return     void
//  @since      v1.0
//  Sample usage:
//-------------------------------------------------------------------------------------------------------------------
void oled_p6x8str(uint8_t x,uint8_t y,const int8_t ch[])
{
    uint8_t c=0,i=0,j=0;
    while (ch[j]!='\0')
    {
        c =ch[j]-32;
        if(x>126){x=0;y++;}
        oled_set_pos(x,y);
        for(i=0;i<6;i++)    oled_wrdat(oled_6x8[c][i]);
        x+=6;
        j++;
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      OLED��ʾ�ַ���(8*16����)
//  @param      x           x����������0-127
//  @param      y           y����������0-7
//  @param      ch[]        �ַ���
//  @return     void
//  @since      v1.0
//  Sample usage:           ���ע�⣬�������ַ��и�λ16�����yӦ����ÿ�ε���2
//-------------------------------------------------------------------------------------------------------------------
void oled_p8x16str(uint8_t x,uint8_t y,const int8_t ch[])
{
    uint8_t c=0,i=0,j=0;

    while (ch[j]!='\0')
    {
        c =ch[j]-32;
        if(x>120){x=0;y++;}

        oled_set_pos(x,y);
        for(i=0;i<8;i++)    oled_wrdat(oled_8x16[c*16+i]);

        oled_set_pos(x,y+1);
        for(i=0;i<8;i++)    oled_wrdat(oled_8x16[c*16+i+8]);

        x+=8;
        j++;
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      OLED��ʾ�޷�����(6*8����)
//  @param      x           x����������0-127
//  @param      y           y����������0-7
//  @param      num         �޷�����
//  @return     void
//  @since      v1.0
//  Sample usage:
//-------------------------------------------------------------------------------------------------------------------
void oled_uint16_t(uint8_t x, uint8_t y, uint16_t num)
{
    int8_t ch[7];

    oled_hexascii(num,ch);

    //oled_p6x8str(x, y, &ch[1]);       //��ʾ����  6*8����
    oled_p8x16str(x, y, &ch[1]);    //��ʾ����  8*16����
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      OLED��ʾ�з�����(6*8����)
//  @param      x           x����������0-127
//  @param      y           y����������0-7
//  @param      num         �з�����
//  @return     void
//  @since      v1.0
//  Sample usage:
//-------------------------------------------------------------------------------------------------------------------
void oled_int16_t(uint8_t x, uint8_t y, int16_t num)
{
    int8_t ch[7];
    if(num<0)   {num = -num;oled_p6x8str(x, y, "-");}
    else         oled_p6x8str(x, y, " ");
    x+=6;

    oled_hexascii(num,ch);
    oled_p6x8str(x, y, &ch[1]);     //��ʾ����  6*8����
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      OLED��ʾ32λ�з���(ȥ������������Ч��0)
//  @param      x           x����������0-127
//  @param      y           y����������0-7
//  @param      dat         ��Ҫ��ʾ�ı�������������uint32_t
//  @param      num         ��Ҫ��ʾ��λ�� ���10λ  ������������
//  @return     void
//  @since      v1.0
//  Sample usage:           oled_printf_int32_t(0,0,x,5);//x����Ϊint32_t uint16_t int16_t uint8_t int8_t����
//  Sample usage:           ��������ʾһ�� ��-����   ������ʾһ���ո�
//-------------------------------------------------------------------------------------------------------------------
void oled_printf_int32_t(uint16_t x,uint16_t y,int32_t dat,uint8_t num)
{
    int8_t    buff[34];
    uint8_t   length;

    if(10<num)      num = 10;

    num++;
    if(0>dat)   length = zf_sprintf( &buff[0],"%d",dat);//����
    else
    {
        buff[0] = ' ';
        length = zf_sprintf( &buff[1],"%d",dat);
        length++;
    }
    while(length < num)
    {
        buff[length] = ' ';
        length++;
    }
    buff[num] = '\0';

    oled_p6x8str(x, y, buff);   //��ʾ����
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      OLED��ʾ������(ȥ������������Ч��0)
//  @param      x           x����������0-127
//  @param      y           y����������0-7
//  @param      dat         ��Ҫ��ʾ�ı�������������float��double
//  @param      num         ����λ��ʾ����   ���10λ
//  @param      pointnum    С��λ��ʾ����   ���6λ
//  @return     void
//  @since      v1.0
//  Sample usage:           oled_printf_float(0,0,x,2,3);//��ʾ������   ������ʾ2λ   С����ʾ��λ
//  @note                   �ر�ע�⵱����С��������ʾ��ֵ����д���ֵ��һ����ʱ��
//                          ���������ڸ��������ȶ�ʧ���⵼�µģ��Ⲣ������ʾ���������⣬
//                          �й���������飬�����аٶ�ѧϰ   ���������ȶ�ʧ���⡣
//                          ��������ʾһ�� ��-����   ������ʾһ���ո�
//-------------------------------------------------------------------------------------------------------------------
void oled_printf_float(uint16_t x,uint16_t y,double dat,uint8_t num,uint8_t pointnum)
{
    uint8_t   length;
    int8_t    buff[34];
    int8_t    start,end,point;

    if(6<pointnum)  pointnum = 6;
    if(10<num)      num = 10;

    if(0>dat)   length = zf_sprintf( &buff[0],"%f",dat);//����
    else
    {
        length = zf_sprintf( &buff[1],"%f",dat);
        length++;
    }
    point = length - 7;         //����С����λ��
    start = point - num - 1;    //������ʼλ
    end = point + pointnum + 1; //�������λ
    while(0>start)//����λ����  ĩβӦ�����ո�
    {
        buff[end] = ' ';
        end++;
        start++;
    }

    if(0>dat)   buff[start] = '-';
    else        buff[start] = ' ';

    buff[end] = '\0';

    oled_p6x8str(x, y, buff);   //��ʾ����
}



//-------------------------------------------------------------------------------------------------------------------
//  @brief      OLED��ʾͼ��
//  @param      high        ͼ��߶�
//  @param      width       ͼ�����
//  @param      *p          ͼ���ַ�����飩
//  @param      value       ��ֵ����ֵ
//  @return     void
//  @since      v1.0
//  Sample usage:
//  @Note       ʹ��Image2lcd V3.2����ȡģ   C��������   ˮƽɨ��
//              ���ȸ߶���������   ��ɫ��ת  256ɫ
//-------------------------------------------------------------------------------------------------------------------
void oled_dis_bmp(uint16_t high, uint16_t width, uint8_t *p,uint8_t value)
{
    int16_t i,j;
    int16_t temp,temp1;
    uint8_t dat;


    temp1 = high%8;
    if(temp1 == 0) temp = high/8;
    else           temp = high/8+1;

    for(i=0; i<temp; i++)
    {
        oled_set_pos(0,i);
        for(j=0; j<width; j++)
        {
            dat = 0;
            if( i<(temp-1) || !temp1 || temp1>=1)dat |= (*(p+i*8*width+j+width*0) > value? 1: 0)<<0;
            if( i<(temp-1) || !temp1 || temp1>=2)dat |= (*(p+i*8*width+j+width*1) > value? 1: 0)<<1;
            if( i<(temp-1) || !temp1 || temp1>=3)dat |= (*(p+i*8*width+j+width*2) > value? 1: 0)<<2;
            if( i<(temp-1) || !temp1 || temp1>=4)dat |= (*(p+i*8*width+j+width*3) > value? 1: 0)<<3;
            if( i<(temp-1) || !temp1 || temp1>=5)dat |= (*(p+i*8*width+j+width*4) > value? 1: 0)<<4;
            if( i<(temp-1) || !temp1 || temp1>=6)dat |= (*(p+i*8*width+j+width*5) > value? 1: 0)<<5;
            if( i<(temp-1) || !temp1 || temp1>=7)dat |= (*(p+i*8*width+j+width*6) > value? 1: 0)<<6;
            if( i<(temp-1) || !temp1 || temp1>=8)dat |= (*(p+i*8*width+j+width*7) > value? 1: 0)<<7;

            oled_wrdat(dat);
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ������ʾ
//  @param      x       ������ 0-127
//  @param      y       ������ 0-7
//  @param      size    ȡģ��ʱ�����õĺ��������С��Ҳ����һ������ռ�õĵ��󳤿�Ϊ���ٸ��㣬ȡģ��ʱ����Ҫ������һ���ġ�
//  @param      *p      ��Ҫ��ʾ�ĺ�������
//  @param      len     ��Ҫ��ʾ����λ
//  @return     void
//  @since      v1.0
//  Sample usage:
//  @Note       ʹ��PCtoLCD2002����ȡģ           ���롢����ʽ��˳��   16*16
//-------------------------------------------------------------------------------------------------------------------
void oled_print_chinese(uint8_t x, uint8_t y, uint8_t size, const uint8_t *p, uint8_t len)
{
    int16_t i,j,k;

    for(i=0; i<len; i++)
    {
        for(j=0; j<(size/8); j++)
        {
            oled_set_pos(x+i*size,y+j);
            for(k=0; k<16; k++)
            {
                oled_wrdat(*p);
                p++;
            }
        }
    }
}