#include<pic.h> 
void delay(unsigned int x) 
{
while(x--);
} 
void main()
{
int k=0X01;
TRISB=0X00;
PORTB=0X00;
while(1)
{
for(k=0X01;k<=0X80;k=k<<1)
{
PORTB=k;
delay(65000); 
}
}
}