/********************************************************************************
**  FILENAME     : LCD_int.h             			                           **
**  VERSION      : 1.0                                                         **
**  DATE         : 25 March 2020                                               **
**  AUTHOR       : kariman Mohamed                                             **
*********************************************************************************/

#ifndef LCD_INT_H_
#define LCD_INT_H_

#define STATUS_OK            0
#define STATUS_BUSY          1
#define STATUS_ERROR         2

#define LINE1   127
#define LINE2   191

#define DIGIT1    1
#define DIGIT2    2
#define DIGIT3    3
#define DIGIT4    4
#define DIGIT5    5
#define DIGIT6    6
#define DIGIT7    7
#define DIGIT8    8
#define DIGIT9    9
#define DIGIT10   10
#define DIGIT11   11
#define DIGIT12   12
#define DIGIT13   13
#define DIGIT14   14
#define DIGIT15   15
#define DIGIT16   16

#define _4BITS_MODE  1
#define _8BITS_MODE  0

typedef   void (*notify_t)(void)  ;



extern u8 LCD_Init(void);
extern u8 LCD_Write(const char * word, u8 len);
extern u8 LCD_Clear(void);
extern u8 LCD_SetPosition(u8 line , u8 digit);



extern void LCD_setWriteDoneNotification(notify_t  cbf);

extern void LCD_setClearDoneNotification(notify_t  cbf);

extern void LCD_setMoveDoneNotification(notify_t  cbf);


#endif /* LCD_INT_H_ */
