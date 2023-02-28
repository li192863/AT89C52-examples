#include <REGX52.H>
#include <INTRINS.h>
#include "Delay.h"

sbit Buzzer = P2 ^ 5;
/**
  * @brief 蜂鸣器私有延时500us函数
  * @param 无
  * @retval 无
  */
void Buzzer_Delay500us()
{
    unsigned char i;
    
    _nop_();
    i = 247;
    while (--i);
}

/**
  * @brief 蜂鸣器发声
  * @param xms 发声时长
  * @retval 无
  */
void Buzzer_Time(unsigned int xms)
{
    unsigned int i;
    for (i = 0; i < xms * 2; i++) // 持续xms毫秒
    {
        Buzzer = !Buzzer;
        Buzzer_Delay500us(); // 周期2ms/频率500Hz
    }
}