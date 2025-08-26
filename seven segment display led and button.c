#include<pic.h>
char a[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
void delay(int x)
{
	while(x--);
}
void main()
{
	
	TRISC3=1;
	TRISC6=0;
	TRISB=0x00;
	PORTB=0x00;
	RC3=0;
	RC6=0;
	while(1)
    {	
		int i=9;
		while(i>=0)
		{
	        if(RC3 == 1)
	        {
				RC6 = 1;
				PORTB = a[i]; 
	            delay(65000);
	            RC6 = 0;   
	            i--;
			}        
        }
    }
}