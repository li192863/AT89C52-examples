#include <REGX52.H>
#include <INTRINS.h>
#include "Timer0.h"
#include "Key.h"

unsigned char KeyNum, LEDMode;

void main()
{
	P2 = 0xFE;
    Timer0_Init();
    while (1)
    {
        KeyNum = Key();
		if (KeyNum)
		{
			if (KeyNum == 1)
			{
				LEDMode++;
				LEDMode %= 2;
			}
		}
    }
}

void Timer0_Rountine() interrupt 1
{
	static unsigned int T0Count;
    TL0 = 0x18; // 设置定时初始值
    TH0 = 0xFC; // 设置定时初始值
    T0Count++;
    if (T0Count >= 500)
    {
        T0Count = 0;
        if (LEDMode == 0)
		{
			P2 = _crol_(P2, 1); // 循环左移
		}
		if (LEDMode == 1)
		{
			P2 = _cror_(P2, 1); // 循环右移
		}
    }
}