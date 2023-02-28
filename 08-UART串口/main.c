#include <REGX52.H>
#include "Delay.h"
#include "UART.h"

void main()
{
    UART_Init();
    while (1)
    {
    }
}

void UART_Rountine() interrupt 4
{
    if (RI == 1) // 判断是否发送了数据
    {
        P2 = ~SBUF;
        UART_SendByte(SBUF);
        RI = 0;
    }
}
