#include<reg51.h>
#include<string.h>
#include "lcdModule.h"

sbit ENABLE = P1^0;
sbit COMMAND_SELECT = P1^1;

/*
 * Function :  LCD Initialisation  
 * @param   : void
 * @return  : void
 */
void lcdInit(void)
{
    LCD_PORT = 0x00;
    COMMAND_SELECT = RESET;
    ENABLE = RESET;
    
    lcdCommandWrite(LCD_SELECT_TWO_LINES);
    TimeDelayCommand();
    
    lcdCommandWrite(LCD_DISPLAY_ON_CURSOR_BLINK);
    TimeDelayCommand();
    
    lcdCommandWrite(LCD_CLEAR_DISPLAY);
    TimeDelayCommand();
    
    lcdCommandWrite(LCD_INC_CURSOR);
    TimeDelayCommand();
}

/*
 * Function       :  Command Write  
 * @param command :  Command value
 * @return        : void
 */
void lcdCommandWrite(unsigned char command)
{
    COMMAND_SELECT = RESET;
    LCD_PORT = command;
    ENABLE = SET;
    TimeDelayCommand();
    ENABLE = RESET;
    TimeDelayCommand();
}

/*
 * Function       :  Data Write  
 * @param dataVal :  Data value
 * @return        : void
 */
void lcdDataWrite(unsigned char dataVal)
{
    COMMAND_SELECT = SET;
    LCD_PORT = dataVal;
    ENABLE = SET;
    TimeDelayCommand();
    ENABLE = RESET;
    TimeDelayCommand();
}

/*
 * Function          :  String Display on LCD  
 * @param stringRow1 :  String to be displayed on Row 1
 * @param stringRow2 :  String to be displayed on Row 1
 * @return           : void
 */
void lcdStrDisplay(unsigned char *stringRow1, unsigned char *stringRow2)
{
    lcdCommandWrite(LCD_DISP_FIRST_LINE);
    TimeDelayCommand();
    while(*stringRow1)
    {
        lcdDataWrite(*stringRow1++);
        TimeDelayData();
    }
    
    lcdCommandWrite(LCD_DISP_SECOND_LINE);
    TimeDelayCommand();
    while(*stringRow2)
    {
        lcdDataWrite(*stringRow2++);
        TimeDelayData();
    }
}

/*
 * Function          :  Character Display on LCD  
 * @param charVal :  Character to be displayed
 * @param addr    :  Location on LCD
 * @return           : void
 */
void lcdCharDisplay(unsigned char charVal,unsigned char addr)
{
    lcdCommandWrite(addr);
    TimeDelayCommand();
    lcdDataWrite(charVal);
    TimeDelayData();
}


/*
 * Function :  Time Delay for command write
 * @param   :  void
 * @return  : void
 */
void TimeDelayCommand()
{
    unsigned char i;
    for(i = 0; i < 100; i++);
}

/*
 * Function :  Time Delay for data write
 * @param   :  void
 * @return  :  void
 */
void TimeDelayData()
{
    unsigned char i;
    for(i = 0; i < 100; i++);
}

/*
 * Function      :  Time Delay
 * @param  delay :  delay value
 * @return  :  void
 */
void TimeDelay(unsigned char delay)
{
    unsigned char x;
    
    for(x = 0; x < delay; x++);
}
