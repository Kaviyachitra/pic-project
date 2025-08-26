include<pic.h>

char a[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

void delay(int x)
{
    while(x--);
}

void main()
{
    TRISB = 0x00; 
    TRISC0 = 0;    

    while(1)
    {
        for(int i = 0; i < 10; i = i + 2)
       
            PORTB = a[i];  
            RC0 = 0;       
            delay(65000);
            RC0 = 1;      
        }
    }
}