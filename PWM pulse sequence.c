#include <pic.h>
void delay(unsigned int x)
{
 while(x--);
}
void main()
{
    int i,j;
    PR2=50;
    TMR2=0;
    TRISC2=0;
    RC2=0;
    CCP1CON=0x0F;
    T2CON=0xFF;
    CCPR1L=0;
    while(1)
    {
        for(i=0;i<50;i++)
        {
         CCPR1L=i;
         delay(10000);
        }
        //for(j=50;j>0;j--)
        //{
           // CCPR1L=j;
           // delay(10000);
        //}
    }
}