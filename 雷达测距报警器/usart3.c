#include "usart3.h"

u8  TX3_Cnt;    //发送计数
u8  RX3_Cnt;    //接收计数
bit B_TX3_Busy; //发送忙标志

u8  RX3_Buffer[UART3_BUF_LENGTH]; //接收缓冲
bit Rec_Flag = 0;	//接受完成标志位
bit led_Flag = 0;
bit beep_Flag = 0;
//========================================================================
// 函数: void UART3_config(u8 brt)
// 描述: UART3初始化函数。
// 参数: brt: 选择波特率, 2: 使用Timer2做波特率, 其它值: 使用Timer3做波特率.
// 返回: none.
// 版本: VER1.0
// 日期: 2014-11-28
// 备注: 
//========================================================================
void UART3_config(u8 brt)    // 选择波特率, 2: 使用Timer2做波特率, 其它值: 使用Timer3做波特率.
{
    if(brt == 2)
    {
        SetTimer2Baudraye(Baudrate3);
        S3CON = 0x10;       //8位数据, 使用Timer2做波特率发生器, 允许接收
    }
    else
    {
        T3R = 0;		//Timer stop
        S3CON = 0x50;       //8位数据, 使用Timer3做波特率发生器, 允许接收
        T3H = (u8)(Baudrate3 / 256);
        T3L = (u8)(Baudrate3 % 256);
        T3_CT = 0;	//Timer3 set As Timer
        T3x12 = 1;	//Timer3 set as 1T mode
        T3R = 1;		//Timer run enable
    }
    ES3  = 1;       //允许UART3中断
    S3_S = 1;       //UART3 switch bit1 to: 0: P0.0 P0.1,  1: P5.0 P5.1

    B_TX3_Busy = 0;
    TX3_Cnt = 0;
    RX3_Cnt = 0;
}

//========================================================================
// 函数: void PrintString3(u8 *puts)
// 描述: 串口3发送字符串函数。
// 参数: puts:  字符串指针.
// 返回: none.
// 版本: VER1.0
// 日期: 2014-11-28
// 备注: 
//========================================================================
void PrintString3(u8 *puts)
{
    for (; *puts != 0;  puts++)     //遇到停止符0结束
    {
        S3BUF = *puts;
        B_TX3_Busy = 1;
        while(B_TX3_Busy);
    }
}

//========================================================================
// 函数: SetTimer2Baudraye(u32 dat)
// 描述: 设置Timer2做波特率发生器。
// 参数: dat: Timer2的重装值.
// 返回: none.
// 版本: VER1.0
// 日期: 2014-11-28
// 备注: 
//========================================================================
void SetTimer2Baudraye(u32 dat)  // 使用Timer2做波特率.
{
    T2R = 0;		//Timer stop
    T2_CT = 0;	//Timer2 set As Timer
    T2x12 = 1;	//Timer2 set as 1T mode
    T2H = (u8)(dat / 256);
    T2L = (u8)(dat % 256);
    ET2 = 0;    //禁止中断
    T2R = 1;		//Timer run enable
}

//========================================================================
// 函数: void UART3_int (void) interrupt UART3_VECTOR
// 描述: UART3中断函数。
// 参数: nine.
// 返回: none.
// 版本: VER1.0
// 日期: 2014-11-28
// 备注: 
//========================================================================
//void UART3_int (void) interrupt 17
//{
//    if(S3RI)
//    {
//        S3RI = 0;    //Clear Rx flag
//        RX3_Buffer[RX3_Cnt] = S3BUF;
//        if(++RX3_Cnt >= UART3_BUF_LENGTH)   RX3_Cnt = 0;
//    }

//    if(S3TI)
//    {
//        S3TI = 0;   //Clear Tx flag
//        B_TX3_Busy = 0;
//    }
//}


//void UART3_int (void) interrupt 17
//{
//     if(S3RI)		//如果接受到数据
//    {
//        S3RI = 0;    //Clear Rx flag
//        RX3_Buffer[RX3_Cnt] = S3BUF;
//		
//		if( RX3_Buffer[RX3_Cnt]== '\n' )	
//		{
//			if( RX3_Buffer[RX3_Cnt-1]== '\r' )
//			{
//				Rec_Flag = 1;
//			}
//			RX3_Cnt = 0;
//		}
//		else
//			RX3_Cnt++;
//    }

//    if(S3TI)
//    {
//        S3TI = 0;    //Clear Tx flag
//        B_TX3_Busy = 0;
//    }

//}


void UART3_int (void) interrupt 17
{
    if (S3RI) 
	{
        // 读取接收到的字符
        char receivedChar = S3BUF;
    
        // 添加字符到接收数组缓冲区
        if (RX3_Cnt < UART3_BUF_LENGTH - 1) {
            //接收完一组数据
            if (receivedChar == 'v') {
				Rec_Flag = 1;	//接收完成标志位
				led_Flag = 1;
				beep_Flag = 1;
				RX3_Buffer[RX3_Cnt] = '\0'; // 添加字符串结束符            
				RX3_Cnt = 0; // 重置索引，准备接收下一组数据
        }        
        	RX3_Buffer[RX3_Cnt++] = receivedChar;
     }
		S3RI = 0;    //Clear Rx flag
    }
} 

