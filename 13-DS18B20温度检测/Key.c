#include <REGX52.H>
#include "Delay.h"

/**
  * @brief  获取按下的独立按键
  * @param  无
  * @retval 按下的按键，范围0~4
  */
unsigned char Key()
{
    unsigned char KeyNumber = 0;
    
    if (P3_1 == 0) { Delay(20); while (P3_1 == 0); Delay(20); KeyNumber = 1; }
    if (P3_0 == 0) { Delay(20); while (P3_0 == 0); Delay(20); KeyNumber = 2; }
    if (P3_2 == 0) { Delay(20); while (P3_2 == 0); Delay(20); KeyNumber = 3; }
    if (P3_3 == 0) { Delay(20); while (P3_3 == 0); Delay(20); KeyNumber = 4; }
    
    return KeyNumber;
}
