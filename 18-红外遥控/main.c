#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "Int0.h"
#include "Timer0.h"
#include "IR.h"


unsigned char Address, Command, Num;
void main()
{
    LCD_Init();
    Int0_Init();
    IR_Init();
    LCD_ShowString(1, 1, "ADDR  CMD  NUM");
    LCD_ShowString(2, 1, "00    00   000");
    while (1)
    {
        if (IR_GetDataFlag() || IR_GetRepeatFlag())
        {
            Address = IR_GetAddress();
            Command = IR_GetCommand();
            
            LCD_ShowHexNum(2, 1, Address, 2);
            LCD_ShowHexNum(2, 7, Command, 2);
            
            if (Command == IR_VOL_MINUS)
            {
                Num--;
            }
            if (Command == IR_VOL_ADD)
            {
                Num++;
            }
            
            LCD_ShowNum(2, 12, Num, 3);
        }
    }
}
