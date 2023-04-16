#include<REG52.H>
#include<intrins.h>
sbit P25=P2^5;
sbit P26=P2^6;
sbit P27=P2^7;

void Delay1000ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 43;
	j = 6;
	k = 203;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void main(void)
{
	int i=0;
	
	
	//Y4C置1，锁存器通过P0与灯泡同步
	//y4置0
	//即74hc138译码器下100
	//选用Y4	口
	P25=0;
	P26=0;
	P26=1;
	
	for(i=0;i<3;i++)
	{
		P0=0x00;
	  Delay1000ms();
	  P0=0xFF;
	}
	while(1)
	{
		
		//流水
		
		for(i=0; i<8;i++)
		{
			P0=!(0x01<<i);
		}
		Delay1000ms();
		
		for(i=0;i<8;i++)
		{
			P0|=0x01<<i;//把i位拉高
		}
		Delay1000ms();
	}
	
	
}