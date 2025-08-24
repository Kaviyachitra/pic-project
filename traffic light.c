#include <pic.h>
void main()
{
    TRISB=0x00;
    PORTB=0x00;

    TMR0=0x00;
    OPTION=0x07;

    int count=0;
    while(1)
    {
        while(!TMR0IF);
        TMR0IF=0;
        count++;
        if(count<=500)
        {
            RB0=1;
            RB1=0;
            RB7=0;
        }
        else if(count>500&&count<=800)
        {
            RB0=0;
            RB1=1;
            RB7=0;
        }
        else if(count>800&&count<=1500)
        {
            RB0=0;
            RB1=0;
            RB7=1;
        }
        else
        {
            count=0;
        }
    }
}