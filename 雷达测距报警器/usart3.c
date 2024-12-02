#include "usart3.h"

u8  TX3_Cnt;    //���ͼ���
u8  RX3_Cnt;    //���ռ���
bit B_TX3_Busy; //����æ��־

u8  RX3_Buffer[UART3_BUF_LENGTH]; //���ջ���
bit Rec_Flag = 0;	//������ɱ�־λ
bit led_Flag = 0;
bit beep_Flag = 0;
//========================================================================
// ����: void UART3_config(u8 brt)
// ����: UART3��ʼ��������
// ����: brt: ѡ������, 2: ʹ��Timer2��������, ����ֵ: ʹ��Timer3��������.
// ����: none.
// �汾: VER1.0
// ����: 2014-11-28
// ��ע: 
//========================================================================
void UART3_config(u8 brt)    // ѡ������, 2: ʹ��Timer2��������, ����ֵ: ʹ��Timer3��������.
{
    if(brt == 2)
    {
        SetTimer2Baudraye(Baudrate3);
        S3CON = 0x10;       //8λ����, ʹ��Timer2�������ʷ�����, �������
    }
    else
    {
        T3R = 0;		//Timer stop
        S3CON = 0x50;       //8λ����, ʹ��Timer3�������ʷ�����, �������
        T3H = (u8)(Baudrate3 / 256);
        T3L = (u8)(Baudrate3 % 256);
        T3_CT = 0;	//Timer3 set As Timer
        T3x12 = 1;	//Timer3 set as 1T mode
        T3R = 1;		//Timer run enable
    }
    ES3  = 1;       //����UART3�ж�
    S3_S = 1;       //UART3 switch bit1 to: 0: P0.0 P0.1,  1: P5.0 P5.1

    B_TX3_Busy = 0;
    TX3_Cnt = 0;
    RX3_Cnt = 0;
}

//========================================================================
// ����: void PrintString3(u8 *puts)
// ����: ����3�����ַ���������
// ����: puts:  �ַ���ָ��.
// ����: none.
// �汾: VER1.0
// ����: 2014-11-28
// ��ע: 
//========================================================================
void PrintString3(u8 *puts)
{
    for (; *puts != 0;  puts++)     //����ֹͣ��0����
    {
        S3BUF = *puts;
        B_TX3_Busy = 1;
        while(B_TX3_Busy);
    }
}

//========================================================================
// ����: SetTimer2Baudraye(u32 dat)
// ����: ����Timer2�������ʷ�������
// ����: dat: Timer2����װֵ.
// ����: none.
// �汾: VER1.0
// ����: 2014-11-28
// ��ע: 
//========================================================================
void SetTimer2Baudraye(u32 dat)  // ʹ��Timer2��������.
{
    T2R = 0;		//Timer stop
    T2_CT = 0;	//Timer2 set As Timer
    T2x12 = 1;	//Timer2 set as 1T mode
    T2H = (u8)(dat / 256);
    T2L = (u8)(dat % 256);
    ET2 = 0;    //��ֹ�ж�
    T2R = 1;		//Timer run enable
}

//========================================================================
// ����: void UART3_int (void) interrupt UART3_VECTOR
// ����: UART3�жϺ�����
// ����: nine.
// ����: none.
// �汾: VER1.0
// ����: 2014-11-28
// ��ע: 
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
//     if(S3RI)		//������ܵ�����
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
        // ��ȡ���յ����ַ�
        char receivedChar = S3BUF;
    
        // ����ַ����������黺����
        if (RX3_Cnt < UART3_BUF_LENGTH - 1) {
            //������һ������
            if (receivedChar == 'v') {
				Rec_Flag = 1;	//������ɱ�־λ
				led_Flag = 1;
				beep_Flag = 1;
				RX3_Buffer[RX3_Cnt] = '\0'; // ����ַ���������            
				RX3_Cnt = 0; // ����������׼��������һ������
        }        
        	RX3_Buffer[RX3_Cnt++] = receivedChar;
     }
		S3RI = 0;    //Clear Rx flag
    }
} 

