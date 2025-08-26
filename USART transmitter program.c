#include <pic.h>
char arr[8]="CAREER";
char arr1[11]="Coimbatore";
void delay(unsigned int x) 
{
while(x--);
}
void send_data(char data)
{
while(!TXIF);
TXREG=data;
delay(1000);
}
void main()
{
int i=0;
TRISC6=0;
TRISC7=1;
TXSTA=0x26;
RCSTA=0x90;
SPBRG=129;
 while(1)
{
for(i=0; i<11; i++)
{
send_data(arr1[i]);
delay(65000);
delay(65000);
 }
 }
}