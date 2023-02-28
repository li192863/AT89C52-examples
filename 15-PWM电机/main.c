#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Nixie.h"
#include "Timer0.h"


sbit Moter = P1 ^ 0;

unsigned char Counter, Compare;
unsigned char KeyNum, Speed;

void main()
{
    Timer0_Init();
    Compare = 5;
    while (1)
    {
        KeyNum = Key();
        if (KeyNum)
        {
            if (KeyNum == 1)
            {
                Speed++;
                Speed %= 4;
            }
        }
        if (Speed == 0) { Compare = 0; }
        if (Speed == 1) { Compare = 30; }
        if (Speed == 2) { Compare = 60; }
        if (Speed == 3) { Compare = 100; }
        Nixie(1, Speed);
    }
}

void Timer0_Rountine() interrupt 1
{
    TL0 = 0xA4; // 设置定时初始值
    TH0 = 0xFF; // 设置定时初始值
    Counter++;
    Counter %= 100;
    if (Counter < Compare)
    {
        Moter = 1;
    }
    else
    {
        Moter = 0;
    }
}
