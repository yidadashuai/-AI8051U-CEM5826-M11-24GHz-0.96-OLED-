
#include "oled.h"
#include "pic.h"
#include "STC32G_GPIO.h"
#include "STC32G_Switch.h"
#include "usart3.h"


//void Blink();									// P0口流水灯
void Beep();									// 蜂鸣器
/******************** IO口配置 ********************/
void	GPIO_config(void)
{
	P0_MODE_IO_PU(GPIO_Pin_All);		//P0 设置为准双向口
	P1_MODE_IO_PU(GPIO_Pin_All);		//P1 设置为准双向口
	P2_MODE_IO_PU(GPIO_Pin_All);		//P2 设置为准双向口
	P3_MODE_IO_PU(GPIO_Pin_All);		//P3 设置为准双向口
	P4_MODE_IO_PU(GPIO_Pin_All);		//P4 设置为准双向口
	P5_MODE_IO_PU(GPIO_Pin_All);		//P5 设置为准双向口
	P6_MODE_IO_PU(GPIO_Pin_All);		//P6 设置为准双向口
	P7_MODE_IO_PU(GPIO_Pin_All);		//P7 设置为准双向口
}

void	I2C_config(void)
{
	I2C_InitTypeDef		I2C_InitStructure;
	I2C_InitStructure.I2C_Mode      = I2C_Mode_Master;		//主从选择   I2C_Mode_Master, I2C_Mode_Slave
	I2C_InitStructure.I2C_Enable    = ENABLE;							//I2C功能使能,   ENABLE, DISABLE
	I2C_InitStructure.I2C_Speed     = 13;							 		//I2C总线速度,   0~63
	I2C_InitStructure.I2C_MS_WDTA   = DISABLE;							//使能主机自动发送设置,   ENABLE, DISABLE
	I2C_Init(&I2C_InitStructure);
	
	I2C_SW(I2C_P33_P32);					//I2C_P14_P15,I2C_P24_P25,I2C_P76_P77,I2C_P33_P32
}


void main()
{
	
	WTST = 0;		//设置程序指令延时参数，赋值为0可将CPU执行指令的速度设置为最快
	EAXFR = 1;		//扩展SFR(XFR)访问使能 
	CKCON = 0;      //提高访问XRAM速度

	GPIO_config();
	I2C_config();
	UART3_config(0);    				//选择波特率, 2: 使用Timer2做波特率, 其它值: 使用Timer3做波特率.
    EA = 1;                             //开总中断
	
	
	
    OLED_Init();                        //OLED初始化
    OLED_BuffClear();                               //清除全部缓存
    OLED_BuffShowBMP(0,0,128,8,OLED12864_IMG);
    OLED_BuffShow();                                //将缓存写入显示屏显示
	delay_ms(1000);
	OLED_BuffClear();                               //清除全部缓存
	
	while(1)
	{
		P40 = 1;
		P0 = 1;
		if(Rec_Flag)
		{
            OLED_BuffClear();                               //清除全部缓存
			OLED_BuffShowString(0,0,RX3_Buffer,0);    		//显示数据
			OLED_BuffShow();                                //将缓存写入显示屏显示
			delay_ms(10);									//延时      
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



//void Blink()									// P0口流水灯
//{
//	u8 i;
//	for(i = 0;i < 6;i++)				// 闪烁3次（即亮灭6个过程）
//	{
//		P0 = ~P0;									// 取反实现亮灭
//		delay_ms(200);							// 延时200ms
//	}
//}
void Beep()									// 蜂鸣器
{
	u8 i;
	P12 = 0;
	for(i = 0;i < 2;i++)				// 响3次（即6个过程）
	{
		P12 = ~P12;								
		delay_ms(100);					// 延时100ms
	}
}


//void main(void)
//{
//	sysinit();									// STC32初始化设置
//	UART3_config(0);    						//选择波特率, 2: 使用Timer2做波特率, 其它值: 使用Timer3做波特率.	
//	EA = 1;										// 使能EA总中断

//	PrintString3("AI8051U UART3 Test Programme!\r\n");  //UART3发送一个字符串
//	
//	while (1)
//	{	
//		
//		if((TX3_Cnt != RX3_Cnt) && (!B_TX3_Busy))   //收到数据, 发送空闲
//		{
//			S3BUF = RX3_Buffer[TX3_Cnt];
//			B_TX3_Busy = 1;
//			if(++TX3_Cnt >= UART3_BUF_LENGTH)   TX3_Cnt = 0;
//		}		
//	}
//}


// =============================================================================================
// 以下均为源代码自带的测试代码，如需要使用可以取消注释
// //-----------------------------------------显示图片-----------------------------------------   
    // OLED_BuffClear();                                                       //清除全部缓存
    // OLED_BuffShowBMP(0,0,128,8,OLED12864_IMG);                              //显示LOGO图片
    // OLED_BuffShow();                                                        //将缓存写入显示屏显示
    // delay_ms(DELAY_TIME);                                                   //延时	

// //-----------------------------------------显示字符-----------------------------------------   
//     OLED_BuffClear();                                                       //清除全部缓存
//     OLED_BuffShowString(0,0,"HEELO ,WELCOME TO USE STC32&OLED12864!",0);    //显示数据
//     OLED_BuffShow();                                                        //将缓存写入显示屏显示
//     delay_ms(DELAY_TIME);                                                   //延时	
    
// //-----------------------------------------显示汉字-----------------------------------------   
//     OLED_BuffClear();                                                       //清除全部缓存
//     OLED_BuffShowString(0,0,"你好,欢迎使用STC 驱\xfd动OLED12864的历程",0);  //显示数据
//     OLED_BuffShow();                                                        //将缓存写入显示屏显示
//     delay_ms(DELAY_TIME);                                                   //延时	       
    
// //-----------------------------------------显示点-----------------------------------------   
//     OLED_BuffClear();                                                       //清除全部缓存
//     OLED_BuffShowString(32,0,"画点测试");                                   //显示数据
//     OLED_BuffShow();                                                        //将缓存写入显示屏显示	
//     for( i=0;i<64;i++ )                                                     //循环64次
//     {
//         OLED_BuffShowPoint(i*2,25);                                         //显示一个点
//         OLED_BuffShow();                                                    //刷新显示
//         delay_ms(50);                                                       //延时
//     }
    
// //-----------------------------------------显示线-----------------------------------------   
//     OLED_BuffClear();                                                       //清除全部缓存
//     OLED_BuffShowString(32,0,"画线测试");                                   //显示数据
//     OLED_BuffShow();                                                        //将缓存写入显示屏显示	
//     for( i=0;i<6;i++ )                                                      //循环6次
//     {
//         OLED_BuffShowLine(4,16+8*i,124,16+8*i);                             //显示横着6条线
//         OLED_BuffShow();                                                    //刷新显示
//         delay_ms(100);
//     }        
//     for( i=0;i<16;i+=1 )                                                    //循环16次
//     {
//         OLED_BuffShowLine(8*i+4,16,8*i+4,56);                               //显示16条数线
//         OLED_BuffShow();                                                    //刷新显示
//         delay_ms(100);
//     }  

// //-----------------------------------------显示圆-----------------------------------------   
//     OLED_BuffClear();                                                       //清除全部缓存
//     OLED_BuffShowString(32,0,"画圆测试");                                   //显示数据
//     OLED_BuffShow();                                                        //将缓存写入显示屏显示	
//     for( i=0;i<6;i++ )                                                      //循环6次
//     {
//        OLED_BuffShowCircle(64,40,5+i*3);                                    //画一个圆    
//         OLED_BuffShow();                                                    //刷新显示
//         delay_ms(250);
//     }         

// //-----------------------------------------显示32大字-----------------------------------------   
//     OLED_BuffClear();                                                       //清除全部缓存
//     OLED_BuffShowString(32,0,"大字测试");                                   //显示数据
//     OLED_BuffShowChar32(24,3,1,0);                                          //显示数字1
//     OLED_BuffShowChar32(40,3,0,0);                                          //显示数字0
//     OLED_BuffShowChar32(56,3,10,0);                                         //显示：
//     OLED_BuffShowChar32(72,3,5,0);                                          //显示数字5
//     OLED_BuffShowChar32(88,3,5,0);                                          //显示数字5
//     OLED_BuffShow();                                                        //将缓存写入显示屏显示	
//     delay_ms(DELAY_TIME);                                                   //延时	 

// //-----------------------------------------反显测试-----------------------------------------   
//     OLED_BuffClear();                                                       //清除全部缓存
//     OLED_BuffShowString(32,0,"反显测试",0);                                 //显示数据
//     OLED_BuffShowString(16,2,"  这是正\xfd显  ",0);                         //显示数据
//     OLED_BuffShowString(16,4,"  这是反显  ",1);                             //显示数据
//     OLED_BuffShow();                                                        //将缓存写入显示屏显示
//     delay_ms(DELAY_TIME);   

// //-----------------------------------------变量显示-----------------------------------------   
//     OLED_BuffClear();                                                       //清除全部缓存
//     OLED_BuffShowString(32,0,"变量显示",0);                                 //显示数据
//     OLED_BuffShowNum(0,2,-25169,0) ;                                        //显示数据
//     OLED_BuffShowNum02F(0,4,3.14159,0);                                     //显示数据
//     OLED_BuffShowNum02F(0,6,dat,1);                                         //显示数据
//     OLED_BuffShow();                                                        //将缓存写入显示屏显示
//     delay_ms(DELAY_TIME);   