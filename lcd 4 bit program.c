#include <pic.h>
#define rs RC0
#define rw RC1
#define en RC2
void delay(unsigned int x)
{
    while(x--);
}
void cmd(char cm)
{
    PORTB=(cm & 0xF0);
    rs=0;
    rw=0;
    en=1;
    delay(65000);
    en=0;
    PORTB=((cm<<4)&0xF0);
    rs=0;
    rw=0;
    en=1;
    delay(65000);
    en=0;
}
void data(char dat)
{
    PORTB=(dat&0xF0);
    rs=1;
    rw=0;
    en=1;
    delay(65000);
    en=0;
    PORTB=((dat << 4)&0xF0);
    rs=1;
    rw=0;
    en=1;
    delay(65000);
    en=0;
}
void main()
{
    char name[6]={'K','A','V','I','Y','A'};
    int i;
    TRISB=0x00;
    TRISC=0x00;
    PORTB=0x00;
    cmd(0x02);
    cmd(0x28);
    cmd(0x0C); 
    cmd(0x01);
    cmd(0x80);
    for(i=0; i<6; i++)
    {
        data(name[i]);
        delay(65000);
    }
    while(1);
}