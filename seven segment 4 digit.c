#include<pic.h>
char arr[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
void delay(unsigned int x)
{
    while(x--);
}
void main()
{
    int i;
    int a,b,c,d;
    TRISC=0xF0; 
    TRISB=0x00;         
    PORTB=0x00;
    while(1)
    {
        for(i=0;i<=9999;i++)  
        {
           d=i/1000;
           c=(i/100)%10;
           b=(i/10)%10;
		   a=i%10;
		   RC0=1;
           PORTB=arr[d];
           //delay(65000);
           RC0=0;
           RC1=1;
           PORTB=arr[c];
           //delay(65000);
           RC1=0;
           RC2=1;
           PORTB=arr[b];
          // delay(65000);
		   RC2=0;
		   RC3=1;
           PORTB=arr[a];
           //delay(65000);
		   RC3=0;
        }
    }
}