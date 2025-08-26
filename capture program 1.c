#include <pic.h>
void delay(unsigned int x)
{
    while(x--);
}
int main()
{
    TRISB=0x00;
    TRISC=0x04;
    PORTB=0x00; 
    CCPR1L=0x00;
    CCPR1H=0x00;
    TMR1L=0x00; 
    TMR1H=0x00; 
    T1CON=0x31;  

    CCP1CON=0x06;
    while(1)
    {
        while(!CCP1IF); 
        CCP1IF=0;    
        RB4=~RB4;
    }
}
