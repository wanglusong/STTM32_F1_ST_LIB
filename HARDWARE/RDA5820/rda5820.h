#ifndef __RDA5820_H
#define __RDA5820_H	 

#include "stm32f10x.h"

typedef unsigned int uint;
typedef unsigned char uchar;

//RDA5820 的寄存器地址
#define RDA5820_READ    0X23  //读RDA5820
#define RDA5820_WRITE	0X22  //写RDA5820
#define RDA5820_WRITE	0X22  //写RDA5820
#define RDA5820_R00         0X00  //读出16个位的ID =0X5820
#define RDA5820_R02					0X02
#define RDA5820_R05					0X05											//……此处省略部分寄存器定义
#define RDA5820_R64     0X64  //RDS_RXMOD[4:3](FIFO模式[10]或者寄存器模式[11])    #define RDA5820_READ  0X23            //读RDA5820
#define RDA5820_WRITE  0X22   

typedef struct RDA5820{
	u8 mode;//模式
	u8 Signal_str;//信号强度
	u8 last_Signal_str;//上次信号强度
	u16 Rxfreq_t;//接收频率
	u16 Txfreq_t;//发射频率
	u8 Txgain_t;//发射增益
	u8 volume;
	u8 Bass_t;//重低音
	u8 function;//功能
	u8 rda_TxPAG;//发送功率
	u8 rda_ADCPAG;//adc增益
}rda5820_func_t;

uint ReadReg(uchar regAddr);
void WriteReg(uchar regAddr,uint val);
void RX_Mode(void);
void TX_Mode(void);
void Vol_Set(uchar vol);
void Mute_Set(uchar mute);
void Bass_Set(uchar bass);
uchar Rssi_Get(void);
void TxPAG_Set(uchar gain);
void TxPGA_Set(uchar gain);
void Band_Set(uchar band);
void Space_Set(uchar spc);
void Freq_Set(uint freq);
u16 RDA5820_Freq_Get(void);
char RDA5820_Init(void);
void TxAdc_Set(uchar gain);	 //ADC 0-3�
void TX_Fm(rda5820_func_t *rda5820_t);//FM发送模式
		 				    
#endif
