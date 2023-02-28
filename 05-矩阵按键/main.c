#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"


void main()
{
    unsigned char KeyNumber;
    unsigned int Password = 0, Count = 0, Code = 8888;
    LCD_Init();
    LCD_ShowString(1, 1, "Passworld:");
    while (1)
    {
        KeyNumber = MatrixKey();
        if (KeyNumber)
        {
            if (KeyNumber <= 10 && Count < 4) // 1~10为密码区(S10为0)
            {
                Password *= 10; // 密码左移
                Password += KeyNumber % 10; // 获取一位密码
                Count++; // 计次+1
            }
            LCD_ShowNum(2, 1, Password, 4);
            
            if (KeyNumber == 11) // 11为确认
            {
                if (Password == Code)
                {
                    LCD_ShowString(1, 14, "OK ");
                    Password = 0;
                    Count = 0;
                    LCD_ShowNum(2, 1, Password, 4);
                }
                else
                {
                    LCD_ShowString(1, 14, "ERR");
                    Password = 0;
                    Count = 0;
                    LCD_ShowNum(2, 1, Password, 4);
                } 
            }
            
            if (KeyNumber == 12) // 12为取消
            {
                Password = 0;
                Count = 0;
                LCD_ShowNum(2, 1, Password, 4);
            }
        }
    }
}
