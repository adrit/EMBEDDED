#include "reg52.h"
#include "adc.h"
#include "lcd.h"


sbit READ         = P1^2;//READ DATA FROM BUFFER
sbit WRITE        = P1^3;//START OF CONVERSION
sbit INTR         = P1^4;//WAIT FOR EOC

unsigned char adcRead()
{
    unsigned char adc_val, val1, val2;
    lcdStrDisplay("DIGITAL VALUE:","                ");
    WRITE = 1;
    READ = 0;
    WRITE = 0;
    TimeDelay(50);
    WRITE = 1;
    TimeDelay(50);
    while(INTR==0);
    READ = 1;
    TimeDelay(50);
    READ = 0;
    adc_val=DATA_OUT;
    val1 = adc_val;
    val1 = val1&0x0F;
    if(val1>9)
        val1+=7; 
    val1+=0x30;
    
    lcdCharDisplay(val1,0x8F);
    val2 = adc_val;
    val2 = (val2>>4)&0x0F;
    if(val2>9)
        val2+=7;
    val2+=0x30;
    
    lcdCharDisplay(val2,0x8E);
    return (adc_val);
} 

void adcInit()
{
   DATA_OUT = INPUT;
   INTR = 1;
   READ = 1;
   WRITE = 1;
}