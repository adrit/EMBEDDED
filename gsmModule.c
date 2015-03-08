#include<reg51.h>
#include<string.h>
#include"gsmModule.h"
#include"uartModule.h"
#include"lcdModule.h"


void gsmInit()
{
    gsmUartCmdPuts("AT");
    gsmSendEnter();
    gsmCheckCond();

    gsmDelay();

    gsmUartCmdPuts("ATE0");
    gsmSendEnter();
    gsmCheckCond();
    gsmDelay();

    gsmUartCmdPuts("AT+CMGF = 1");
    gsmSendEnter();
    gsmCheckCond();
    gsmDelay();

    gsmUartCmdPuts("AT+CNMI = 2,2,0,0,0");
    gsmSendEnter();
    gsmCheckCond();

    gsmDelay();
    gsmDelay();
    gsmDelay();	
}


void gsmUartCmdPuts(unsigned char *var)
{
    unsigned char len,i;
    len = strlen(var);
	
    for(i=0;i<len;i++)
    {
        uart_send(*var);	
        var++;
    } 
}

void gsmCheckCond()
{
    while(uartdata()!= 'K');
}

void gsmSendEnter()
{
    uart_send(0x0d);
    uart_send(0x0a);
}

void gsmMsgSend(unsigned char *cmgs,unsigned char *phno,unsigned char *msg)
{
    gsmUartCmdPuts(cmgs);
    uart_send('"');
    gsmUartCmdPuts(phno);
    uart_send('"');
    gsmSendEnter();

    while(uartdata()!= '>');
	
    gsmUartCmdPuts(msg);
    uart_send(' ');
    uart_send(0x1a); 
    gsmSendEnter();
    lcdStrDisplay("MESSAGE SENT    ","                "); 
}
