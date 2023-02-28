#include <REGX52.H>
#include "Delay.h"

sbit RCK = P3 ^ 5; // RCLK
sbit SCK = P3 ^ 6; // SRCLK
sbit SER = P3 ^ 4; // SER

#define LED_MATRIX_PORT P0

/**
  * @brief  LED矩阵初始化函数
  * @param  无
  * @retval 无
  */
void LEDMatrix_Init()
{
    SCK = 0;
    RCK = 0;
}

/**
  * @brief  74HC595写数据函数
  * @param  Byte 写入的字节
  * @retval 无
  */
void _74HC595_WriteByte(unsigned char Byte)
{
    unsigned char i;
    for (i = 0; i < 8; i++)
    {
        SER = Byte & (0x80 >> i);
        SCK = 1; // 上升沿移位
        SCK = 0; // 置0
    }
    RCK = 1; // 上升沿锁存
    RCK = 0; 
    
}

/**
  * @brief  LED矩阵显示列
  * @param  Column 要显示的列
  * @param  Data 要显示的数据 1亮0灭
  * @retval 无
  */
void LEDMatrix_ShowColumn(unsigned char Column, unsigned char Data)
{
    _74HC595_WriteByte(Data);
    LED_MATRIX_PORT = ~(0x80 >> Column);
    // 消影
    Delay(1); // 延时
    LED_MATRIX_PORT = 0xFF; // 清零
}
