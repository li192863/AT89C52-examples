#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"


void main()
{
    LCD_Init();
    LCD_ShowString(1, 1, "Hello, Ms Chen! Ilove you!"); 
    while (1)
    {
        LCD_WriteCommand(0x18);
        Delay(500);
    }
}
