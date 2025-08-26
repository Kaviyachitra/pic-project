#include <pic.h>
void delay(unsigned int x)
{
 while(x--);
}
void cmd(char b)
{
 RB0=0;
 RB1=0;
 RB2=1;
 PORTD=b;
 delay(65000);
 RB2=0;
}
void data(char *a)
{
RB0=1;
while(*a!='\0')
{
 RB1=0;
RB2=1;
PORTD=*a;
delay(65000);
RB2=0;
a++;
}
}
void data1(char c)
{
 RB0=1;
 RB1=0;
 RB2=1;
 PORTD=c;
 delay(65000);
 RB2=0;
}
void num(int m)
{
int a[10],i=0;
while(m>0)
{
a[i]=m%10;
m=m/10;
i++;
}
i--;
while(i>=0)
{
RB0=1;
RB1=0;
RB2=1;
PORTD=a[i]+0x30;
delay(65000);
RB2=0;
i--;
}
}
void main()
{
TRISB=0x00;
PORTB=0x00;
TRISD=0x00;
PORTD=0xFF;
TRISC6=0;
TRISC7=1;
TXSTA=0x26;
RCSTA=0x90;
SPBRG=129;
cmd(0x38);
cmd(0x0F);
cmd(0x80);
char a;
unsigned int b,i=0;
while(1)
{
while(!RCIF);
delay(1000);
a=RCREG;
if(a=='\0')
{
cmd(0x80);
}
else
{
data1(a);
CREN=0;
CREN=1;
}
}
}