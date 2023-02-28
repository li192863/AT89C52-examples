#include <REGX52.H>
/**
  * @brief  串口初始化
  * @param  无
  * @retval 无
  */
void UART_Init(void) // 4800bps@11.0592MHz
{
    PCON &= 0x7F; // 波特率不倍速
    SCON = 0x50; // 8位数据,可变波特率
    TMOD &= 0x0F; // 设置定时器模式
    TMOD |= 0x20; // 设置定时器模式
    TL1 = 0xFA; // 设置定时初始值
    TH1 = 0xFA; // 设置定时初始值
    ET1 = 0; // 禁止定时器%d中断
    TR1 = 1; // 定时器1开始计时
    
    EA = 1; // 启动中断
    ES = 1; // 启动串口中断
}

/**
  * @brief  串口发送数据
  * @param  Byte 数据
  * @retval 无
  */
void UART_SendByte(unsigned char Byte)
{
    SBUF = Byte;
    while (TI == 0);
    TI = 0;
}

/* 串口中断函数模板
void UART_Rountine() interrupt 4
{
    if (RI == 1) // 判断是否发送了数据
    {
        P2 = ~SBUF;
        UART_SendByte(SBUF);
        RI = 0;
    }
}
*/
