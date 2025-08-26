#include <pic.h>
#define rs RC0
#define rw RC1
#define en RC2
#define R1 RD4
#define R2 RD5
#define R3 RD6
#define R4 RD7
void delay(unsigned int x)
{
    while(x--);
}
void cmd(char cm)
{
    rs=0;
    rw=0;
    PORTB=cm;
    en=1;
    delay(65000);
    en=0;
}
void data(char dat)
{
    rs=1;
    rw=0;
    PORTB=dat;
    en=1;
    delay(65000);
    en=0;
}
void main()
{
    TRISB=0x00;
    TRISC=0x00;
    TRISD=0xF0;
    PORTB=0x00;
    PORTC=0x00;
    PORTD=0x00;
    cmd(0x38);
    cmd(0x0C);
    cmd(0x01);
    while(1)
    {
        PORTD=0xF1;
        if(R1==1)
        {
            data('1');
            while(R1==1);
        }
        if(R2==1)
        {
            data('4');
            while(R2==1);
        }
        if(R3==1)
        {
            data('7');
            while(R3==1);
        }
        if(R4==1)
        {
            data('*');
            while(R4==1);
        }
        PORTD=0xF2;
        if(R1==1)
        {
            data('2');
            while(R1==1);
        }
        if(R2==1)
        {
            data('5');
            while(R2==1);
        }
        if(R3==1)
        {
            data('8');
            while(R3==1);
        }
        if(R4==1)
        {
            data('0');
            while(R4==1);
        }
        PORTD = 0xF4;
        if(R1==1)
        {
            data('3');
            while(R1==1);
        }
        if(R2==1)
        {
            data('6');
            while(R2==1);
        }
        if(R3==1)
        {
            data('9');
            while(R3==1);
        }
        if(R4==1)
        {
            data('#');
            while(R4==1);
        }
    }
}