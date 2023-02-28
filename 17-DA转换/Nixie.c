#include <REGX52.H>
#include "Delay.h"

unsigned char NixieTable[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x00};

/**
  * @brief  数码管显示数字
  * @param  pos 要显示数码的位置，范围1~8
  * @param  num 要显示的数码，范围0~F, 空
  * @retval 无
  */
void Nixie(unsigned char pos, unsigned char num)
{
    switch (pos)
    {
        case 1: P2_4 = 1; P2_3 = 1; P2_2 = 1; break;
        case 2: P2_4 = 1; P2_3 = 1; P2_2 = 0; break;
        case 3: P2_4 = 1; P2_3 = 0; P2_2 = 1; break;
        case 4: P2_4 = 1; P2_3 = 0; P2_2 = 0; break;
        case 5: P2_4 = 0; P2_3 = 1; P2_2 = 1; break;
        case 6: P2_4 = 0; P2_3 = 1; P2_2 = 0; break;
        case 7: P2_4 = 0; P2_3 = 0; P2_2 = 1; break;
        case 8: P2_4 = 0; P2_3 = 0; P2_2 = 0; break;
        
    }
    P0 = NixieTable[num];
    // 消影
    Delay(1); // 延时
    P0 = 0x00; // 清零
}
