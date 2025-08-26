#include<pic.h>
char count=0;
int sec=0;
void delay(unsigned int x)
{
	while(x--);
}
void interrupt isr()
{
	if(TMR0IF==1)
	{
		TMR0IF=0;
		count++;
		if(count==76)
		{
			sec++;
			count=0;
		}
	}
}
int main()
{
	TRISB=0x01;
	TRISC=0x00;
	PORTC=0x00;
	RB1=0;
	TMR0=0x00;
	OPTION=0x07;
	GIE=1; 
    INTE=1;
	TMR0IE=1;
	while(1)
	{
		if(RB0==1)
		{
			RB1=~RB1;
			delay(1000);
		}
		if(sec==5)
		{
			PORTC=~PORTC;
			sec=0;
		}
	}
}
