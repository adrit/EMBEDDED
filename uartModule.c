#include <reg52.h>
#include"uart.h"

void uartinit()
{
    TMOD=0x20;
    SCON=0x50;
    TH1=-3;
    TR1=1;
}

unsigned char uartdata()
{
    while(1)
    {
       unsigned char a;
       while(RI==0);
       RI=0;
       a=SBUF;
       return(a);
    }
}

void uart_send(unsigned char value)
{
    SBUF = value;
    while(TI == 0);
    TI = 0;
}