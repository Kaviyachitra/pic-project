#include<pic.h>
char arr[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
void delay(unsigned int x)
{
    while(x--);
}
void main()
{
    int i;
    int a,b;
    TRISB=0x00;   
    TRISC=0x00;         
    PORTB=0x00;
    while(1)
    {
        for(i=1;i<=99;i++)  
        {
           a=i/10;
           b=i%10;
           RC1=1;
           PORTB=arr[a];
           delay(65000);
           RC1=0;
		   delay(65000);
           RC2=1;
           PORTB=arr[b];
           delay(65000);
		   RC2=0;
		   delay(65000);
        }
    }
}


