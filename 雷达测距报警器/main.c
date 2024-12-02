
#include "oled.h"
#include "pic.h"
#include "STC32G_GPIO.h"
#include "STC32G_Switch.h"
#include "usart3.h"


//void Blink();									// P0����ˮ��
void Beep();									// ������
/******************** IO������ ********************/
void	GPIO_config(void)
{
	P0_MODE_IO_PU(GPIO_Pin_All);		//P0 ����Ϊ׼˫���
	P1_MODE_IO_PU(GPIO_Pin_All);		//P1 ����Ϊ׼˫���
	P2_MODE_IO_PU(GPIO_Pin_All);		//P2 ����Ϊ׼˫���
	P3_MODE_IO_PU(GPIO_Pin_All);		//P3 ����Ϊ׼˫���
	P4_MODE_IO_PU(GPIO_Pin_All);		//P4 ����Ϊ׼˫���
	P5_MODE_IO_PU(GPIO_Pin_All);		//P5 ����Ϊ׼˫���
	P6_MODE_IO_PU(GPIO_Pin_All);		//P6 ����Ϊ׼˫���
	P7_MODE_IO_PU(GPIO_Pin_All);		//P7 ����Ϊ׼˫���
}

void	I2C_config(void)
{
	I2C_InitTypeDef		I2C_InitStructure;
	I2C_InitStructure.I2C_Mode      = I2C_Mode_Master;		//����ѡ��   I2C_Mode_Master, I2C_Mode_Slave
	I2C_InitStructure.I2C_Enable    = ENABLE;							//I2C����ʹ��,   ENABLE, DISABLE
	I2C_InitStructure.I2C_Speed     = 13;							 		//I2C�����ٶ�,   0~63
	I2C_InitStructure.I2C_MS_WDTA   = DISABLE;							//ʹ�������Զ���������,   ENABLE, DISABLE
	I2C_Init(&I2C_InitStructure);
	
	I2C_SW(I2C_P33_P32);					//I2C_P14_P15,I2C_P24_P25,I2C_P76_P77,I2C_P33_P32
}


void main()
{
	
	WTST = 0;		//���ó���ָ����ʱ��������ֵΪ0�ɽ�CPUִ��ָ����ٶ�����Ϊ���
	EAXFR = 1;		//��չSFR(XFR)����ʹ�� 
	CKCON = 0;      //��߷���XRAM�ٶ�

	GPIO_config();
	I2C_config();
	UART3_config(0);    				//ѡ������, 2: ʹ��Timer2��������, ����ֵ: ʹ��Timer3��������.
    EA = 1;                             //�����ж�
	
	
	
    OLED_Init();                        //OLED��ʼ��
    OLED_BuffClear();                               //���ȫ������
    OLED_BuffShowBMP(0,0,128,8,OLED12864_IMG);
    OLED_BuffShow();                                //������д����ʾ����ʾ
	delay_ms(1000);
	OLED_BuffClear();                               //���ȫ������
	
	while(1)
	{
		P40 = 1;
		P0 = 1;
		if(Rec_Flag)
		{
            OLED_BuffClear();                               //���ȫ������
			OLED_BuffShowString(0,0,RX3_Buffer,0);    		//��ʾ����
			OLED_BuffShow();                                //������д����ʾ����ʾ
			delay_ms(10);									//��ʱ      
			Rec_Flag = 1;
        }
		if(led_Flag)
		{
			P40 = 0;
			P0 = 1;
			led_Flag = 0;
        }
		if(beep_Flag)
		{
			Beep();
			beep_Flag = 0;
        }
			

		
	}
}



//void Blink()									// P0����ˮ��
//{
//	u8 i;
//	for(i = 0;i < 6;i++)				// ��˸3�Σ�������6�����̣�
//	{
//		P0 = ~P0;									// ȡ��ʵ������
//		delay_ms(200);							// ��ʱ200ms
//	}
//}
void Beep()									// ������
{
	u8 i;
	P12 = 0;
	for(i = 0;i < 2;i++)				// ��3�Σ���6�����̣�
	{
		P12 = ~P12;								
		delay_ms(100);					// ��ʱ100ms
	}
}


//void main(void)
//{
//	sysinit();									// STC32��ʼ������
//	UART3_config(0);    						//ѡ������, 2: ʹ��Timer2��������, ����ֵ: ʹ��Timer3��������.	
//	EA = 1;										// ʹ��EA���ж�

//	PrintString3("AI8051U UART3 Test Programme!\r\n");  //UART3����һ���ַ���
//	
//	while (1)
//	{	
//		
//		if((TX3_Cnt != RX3_Cnt) && (!B_TX3_Busy))   //�յ�����, ���Ϳ���
//		{
//			S3BUF = RX3_Buffer[TX3_Cnt];
//			B_TX3_Busy = 1;
//			if(++TX3_Cnt >= UART3_BUF_LENGTH)   TX3_Cnt = 0;
//		}		
//	}
//}


// =============================================================================================
// ���¾�ΪԴ�����Դ��Ĳ��Դ��룬����Ҫʹ�ÿ���ȡ��ע��
// //-----------------------------------------��ʾͼƬ-----------------------------------------   
    // OLED_BuffClear();                                                       //���ȫ������
    // OLED_BuffShowBMP(0,0,128,8,OLED12864_IMG);                              //��ʾLOGOͼƬ
    // OLED_BuffShow();                                                        //������д����ʾ����ʾ
    // delay_ms(DELAY_TIME);                                                   //��ʱ	

// //-----------------------------------------��ʾ�ַ�-----------------------------------------   
//     OLED_BuffClear();                                                       //���ȫ������
//     OLED_BuffShowString(0,0,"HEELO ,WELCOME TO USE STC32&OLED12864!",0);    //��ʾ����
//     OLED_BuffShow();                                                        //������д����ʾ����ʾ
//     delay_ms(DELAY_TIME);                                                   //��ʱ	
    
// //-----------------------------------------��ʾ����-----------------------------------------   
//     OLED_BuffClear();                                                       //���ȫ������
//     OLED_BuffShowString(0,0,"���,��ӭʹ��STC ��\xfd��OLED12864������",0);  //��ʾ����
//     OLED_BuffShow();                                                        //������д����ʾ����ʾ
//     delay_ms(DELAY_TIME);                                                   //��ʱ	       
    
// //-----------------------------------------��ʾ��-----------------------------------------   
//     OLED_BuffClear();                                                       //���ȫ������
//     OLED_BuffShowString(32,0,"�������");                                   //��ʾ����
//     OLED_BuffShow();                                                        //������д����ʾ����ʾ	
//     for( i=0;i<64;i++ )                                                     //ѭ��64��
//     {
//         OLED_BuffShowPoint(i*2,25);                                         //��ʾһ����
//         OLED_BuffShow();                                                    //ˢ����ʾ
//         delay_ms(50);                                                       //��ʱ
//     }
    
// //-----------------------------------------��ʾ��-----------------------------------------   
//     OLED_BuffClear();                                                       //���ȫ������
//     OLED_BuffShowString(32,0,"���߲���");                                   //��ʾ����
//     OLED_BuffShow();                                                        //������д����ʾ����ʾ	
//     for( i=0;i<6;i++ )                                                      //ѭ��6��
//     {
//         OLED_BuffShowLine(4,16+8*i,124,16+8*i);                             //��ʾ����6����
//         OLED_BuffShow();                                                    //ˢ����ʾ
//         delay_ms(100);
//     }        
//     for( i=0;i<16;i+=1 )                                                    //ѭ��16��
//     {
//         OLED_BuffShowLine(8*i+4,16,8*i+4,56);                               //��ʾ16������
//         OLED_BuffShow();                                                    //ˢ����ʾ
//         delay_ms(100);
//     }  

// //-----------------------------------------��ʾԲ-----------------------------------------   
//     OLED_BuffClear();                                                       //���ȫ������
//     OLED_BuffShowString(32,0,"��Բ����");                                   //��ʾ����
//     OLED_BuffShow();                                                        //������д����ʾ����ʾ	
//     for( i=0;i<6;i++ )                                                      //ѭ��6��
//     {
//        OLED_BuffShowCircle(64,40,5+i*3);                                    //��һ��Բ    
//         OLED_BuffShow();                                                    //ˢ����ʾ
//         delay_ms(250);
//     }         

// //-----------------------------------------��ʾ32����-----------------------------------------   
//     OLED_BuffClear();                                                       //���ȫ������
//     OLED_BuffShowString(32,0,"���ֲ���");                                   //��ʾ����
//     OLED_BuffShowChar32(24,3,1,0);                                          //��ʾ����1
//     OLED_BuffShowChar32(40,3,0,0);                                          //��ʾ����0
//     OLED_BuffShowChar32(56,3,10,0);                                         //��ʾ��
//     OLED_BuffShowChar32(72,3,5,0);                                          //��ʾ����5
//     OLED_BuffShowChar32(88,3,5,0);                                          //��ʾ����5
//     OLED_BuffShow();                                                        //������д����ʾ����ʾ	
//     delay_ms(DELAY_TIME);                                                   //��ʱ	 

// //-----------------------------------------���Բ���-----------------------------------------   
//     OLED_BuffClear();                                                       //���ȫ������
//     OLED_BuffShowString(32,0,"���Բ���",0);                                 //��ʾ����
//     OLED_BuffShowString(16,2,"  ������\xfd��  ",0);                         //��ʾ����
//     OLED_BuffShowString(16,4,"  ���Ƿ���  ",1);                             //��ʾ����
//     OLED_BuffShow();                                                        //������д����ʾ����ʾ
//     delay_ms(DELAY_TIME);   

// //-----------------------------------------������ʾ-----------------------------------------   
//     OLED_BuffClear();                                                       //���ȫ������
//     OLED_BuffShowString(32,0,"������ʾ",0);                                 //��ʾ����
//     OLED_BuffShowNum(0,2,-25169,0) ;                                        //��ʾ����
//     OLED_BuffShowNum02F(0,4,3.14159,0);                                     //��ʾ����
//     OLED_BuffShowNum02F(0,6,dat,1);                                         //��ʾ����
//     OLED_BuffShow();                                                        //������д����ʾ����ʾ
//     delay_ms(DELAY_TIME);   