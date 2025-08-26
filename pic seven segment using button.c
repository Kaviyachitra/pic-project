#include <pic.h>

char a[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

void delay(int x)
{
    while(x--);
}

void main()
{
    int i = 1; 

    TRISB = 0x00;  
    TRISC2 = 1;     
    TRISC0 = 0; 

    RC0 = 0;

    while(1)
    {
        if(RC2 == 1)
        {
            PORTB = a[i];

            while(RC2 == 1);

            i++;

            if(i == 10)
                i = 0;  

            delay(65000); 
        }
    }
}