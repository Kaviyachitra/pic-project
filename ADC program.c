#include <pic.h>
#define adc0()
void delay(unsigned int x)
{
    while(x--);
}
void cmd(char b)
{
    RC0=0;
    RC1=0;
    RC2=1;
    PORTD=b;
    delay(65000);
    RC2=0;
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
        RC0=1;
        RC1=0;
        RC2=1;
        PORTD=a[i]+0x30;
        delay(65000);
        RC2=0;
        i--;
    }
}
void main()
{
    int a=0,b=0,c=0;
    TRISA=0xFF;
    TRISC=0x00;
    PORTC=0x00;
    TRISD=0x00;
    PORTD=0x00;
    ADCON0=0xC5;
    ADCON1=0x80;
    cmd(0x38);
    cmd(0x0C);
    while(1)
    {
        cmd(0x80);
        while(!ADIF);
        ADIF=0;
        ADGO=1;
        a=ADRESL;
        b=ADRESH;
        b=b<<8;
        c=b+a;
        num(c);
        delay(5000);
    }
}