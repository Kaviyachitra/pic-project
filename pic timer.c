#include <pic.h>
void main()
{
    TRISB=0x00;
    PORTB=0xFF;
    TMR0=0x00;    
    OPTION=0x07; 
    int count=0;
    while(1)
    {
        while(!TMR0IF);
        TMR0IF=0; 
        count++; 
        if(count==15)
        {
            PORTB=~PORTB;
            count=0;   
        }
    }
}
