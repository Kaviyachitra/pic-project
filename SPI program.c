#include<pic.h>
void delay_ms(unsigned int x)
{
while(x--);
}
void SPI_Master_Init() 
{
TRISC3=0;
TRISC5=0;
SSPSTAT=0x00;
SSPCON=0x20;
}
void SPI_Write(char data)
{
SSPBUF = data;
while (!SSPIF);
SSPIF = 0;
}
void main() 
{
SPI_Master_Init();
while(1)
{
SPI_Write('A');
delay_ms(65000);
    }
}