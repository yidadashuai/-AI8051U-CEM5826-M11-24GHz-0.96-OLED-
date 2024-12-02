#ifndef __USART3_H
#define __USART3_H

#include	"config.h"

#define UART3_BUF_LENGTH    64
#define Baudrate3   (65536 - MAIN_Fosc / 115200 / 4)

/*************  本地变量声明    **************/

extern u8  TX3_Cnt;    //发送计数
extern u8  RX3_Cnt;    //接收计数
extern bit B_TX3_Busy; //发送忙标志
extern u8  RX3_Buffer[UART3_BUF_LENGTH]; //接收缓冲
extern bit Rec_Flag ;	//接受完成标志位
extern bit led_Flag;
extern bit beep_Flag;


void UART3_config(u8 brt);    // 选择波特率, 2: 使用Timer2做波特率, 其它值: 使用Timer3做波特率.
void SetTimer2Baudraye(u32 dat);  // 使用Timer2做波特率.
void PrintString3(u8 *puts);


#endif