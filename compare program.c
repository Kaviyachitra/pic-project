#include <pic.h>
void delay(unsigned int x)
{
 while(x--);
}

void main()
{
    TRISB=0x00;
    PORTB=0x00;
    TRISC=0x00;

    CCP1CON=0x08;
    T1CON=0x31;
    CCPR1L=0xFF;
    CCPR1H=0xFF;

    while(1)
    {
        while(!CCP1IF);
        CCP1IF=0;
        PORTB=~PORTB;
    }
}