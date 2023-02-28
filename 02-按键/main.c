#include <REGX52.H>

void Delay(unsigned int);


void main()
{
    unsigned char LEDNum = 0;
    P2 = ~0x01;
    while (1) 
    {
        if (P3_1 == 0) 
        {
            Delay(20); // 按键抖动
            while (P3_1 == 0); // 检测松手
            Delay(20); // 按键抖动
            
            //LEDNum++;
            if (LEDNum == 7)
            {
                LEDNum = 0;
            }
            else
            {
                LEDNum++;
            }
            P2 = ~(0x01 << LEDNum);
        }
        if (P3_0 == 0) 
        {
            Delay(20); // 按键抖动
            while (P3_0 == 0); // 检测松手
            Delay(20); // 按键抖动
            
            if (LEDNum == 0)
            {
                LEDNum = 7;
            }
            else
            {
                LEDNum--;
            }
            P2 = ~(0x01 << LEDNum);
        }
    }
}


void Delay(unsigned int xms) // @12.000MHz
{
    unsigned char i, j;

    while (xms--)
    {
        i = 2;
        j = 239;
        do
        {
            while (--j);
        } while (--i);
    }	
}