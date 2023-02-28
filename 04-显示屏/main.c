#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"

void main()
{
    int result = 0;
    LCD_Init(); // 初始化
    while (1)
    {
        Delay(1000);
       LCD_ShowNum(1, 1, result++, 3);
    }
}
