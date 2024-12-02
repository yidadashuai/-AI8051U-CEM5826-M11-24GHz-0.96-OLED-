#ifndef __USART3_H
#define __USART3_H

#include	"config.h"

#define UART3_BUF_LENGTH    64
#define Baudrate3   (65536 - MAIN_Fosc / 115200 / 4)

/*************  ���ر�������    **************/

extern u8  TX3_Cnt;    //���ͼ���
extern u8  RX3_Cnt;    //���ռ���
extern bit B_TX3_Busy; //����æ��־
extern u8  RX3_Buffer[UART3_BUF_LENGTH]; //���ջ���
extern bit Rec_Flag ;	//������ɱ�־λ
extern bit led_Flag;
extern bit beep_Flag;


void UART3_config(u8 brt);    // ѡ������, 2: ʹ��Timer2��������, ����ֵ: ʹ��Timer3��������.
void SetTimer2Baudraye(u32 dat);  // ʹ��Timer2��������.
void PrintString3(u8 *puts);


#endif