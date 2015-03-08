

/* Function prototype */
void lcdInit(void);
void lcdCommandWrite(unsigned char command);
void lcdDataWrite(unsigned char dataVal);
void lcdStrDisplay(unsigned char *stringRow1, unsigned char *stringRow2);
void lcdCharDisplay(unsigned char charVal,unsigned char addr);
void TimeDelayCommand();
void TimeDelayData();
void TimeDelay(unsigned char delay);

/* Macro definition */
#define LCD_PORT  P0
#define SET       1
#define RESET     0

/* LCD Commands */
#define LCD_CLEAR_DISPLAY           0x01
#define LCD_RETURN_HOME             0x02
#define LCD_DEC_CURSOR              0x04
#define LCD_INC_CURSOR              0x06
#define LCD_SHIFT_DISP_RIGHT        0x05
#define LCD_SHIFT_DISP_LEFT         0x07
#define LCD_DISPLAY_CURSOR_OFF      0x08
#define LCD_DISPLAY_ON_CURSOR_OFF   0x0a
#define LCD_DISPLAY_ON_CURSOR_BLINK 0x0e
#define LCD_SELECT_TWO_LINES        0x38
#define LCD_DISP_FIRST_LINE         0x80
#define LCD_DISP_SECOND_LINE        0xc0


