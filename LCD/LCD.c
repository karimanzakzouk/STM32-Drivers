/********************************************************************************
**  FILENAME     : LCD.c    		           			                       **
**  VERSION      : 1.0                                                         **
**  DATE         : 25 March 2020                                               **
**  AUTHOR       : kariman Mohamed                                             **
*********************************************************************************/

#include "STD_TYPES.h"
#include "MACROS.h"
#include "SCHEDULER.h"
#include "GPIO.h"
#include "LCD.h"
#include "LCD_cfg.h"


/******************************************* MACROS *********************************************/

#define LCD_Clear_Display    1    //0b00000001                  // replace all characters with ASCII 'space'
#define LCD_DisplayOn        15  //0b00001111                 // display on, cursor off, don't blink character
#define LCD_FunctionSet8bit  56 // 0x38                      // 8-bit data, 2-line display, 5 x 7 font
#define LCD_EntryMode        6 //0x06                        // shift cursor from left to right on read/write


/**************************** Types************************************/

typedef enum
{
	idle_proc ,
	write_proc,
	clear_proc,
	curserMove_proc
}process_t;

typedef enum
{
	s1 ,
	s2 ,
	s3 ,
	s4
}InitState_t;


/***************************************	static functions prototypes ******************************************/

static void InitProcess(void);
static void WriteProcess(void);
static void ClearProcess(void);
static void MoveCurserProcess(void);

/*************************************************** LCD TASK ****************************************************/
void LcdTask(void);

const Task_t Lcd_Task ={LcdTask,4}; //2msec

/*********************************************** Global Variables ************************************************/

static u8 reqLine , reqDigit;
static u8 initCompleted ;
static u8 userWord[255] ;
static u8 userWordLength;

static notify_t  appWriteDoneNotify;
static notify_t  appClearDoneNotify;
static notify_t  appMoveDoneNotify;

static process_t currentProcess ;

/******************************************* FUNCTIONS **************************************************************/

extern u8 LCD_Init(void)
{
	GPIO_InitTypeDef LCD_PINS = { .pin =(LCD_D0|LCD_D1|LCD_D2|LCD_D3|LCD_D4|LCD_D5|LCD_D6|LCD_D7|LCD_RS|LCD_RW|LCD_EN) ,
		                     	  .port = LCD_PORT , .mode = GPIO_MODE_OUTPUT_PUSH_PULL , .speed = GPIO_SPEED_2_MHZ,
			                      .GPIO_ON = BIT_SET , .GPIO_OFF = BIT_RESET   } ;
	GPIO_voidInitPin(&LCD_PINS );

	GPIO_voidWritePin( LCD_RS , LCD_PORT , BIT_RESET);
    GPIO_voidWritePin( LCD_RW , LCD_PORT , BIT_RESET);
    GPIO_voidWritePin( LCD_EN , LCD_PORT , BIT_RESET);
	return STATUS_OK ;
}

/********************************************************************************************************************/

extern u8 LCD_Write(const char * word, u8 len)
{
	u8 idx , result;
	if(currentProcess == idle_proc)
    {
		  currentProcess = write_proc;
		  for(idx=0; idx < len; idx++)
		  {
			 userWord[idx] = word[idx];
		  }
		  userWordLength = len ;
		  result = STATUS_OK ;
	}
    else
    {
	      result = STATUS_BUSY ;
	}
    return result;
}

/**********************************************************************************************************************/

extern u8 LCD_Clear(void)
{
	u8 result =STATUS_OK;
    if(currentProcess == idle_proc)
    {
       currentProcess = clear_proc;
    }
    else
    {
       result = STATUS_BUSY ;
    }
    return result;
}

/**********************************************************************************************************************/
extern u8 LCD_SetPosition(u8 line , u8 digit)
{
	u8 result=STATUS_OK;
    if(currentProcess == idle_proc)
    {
       currentProcess = curserMove_proc;
       reqLine = line;
       reqDigit = digit;
    }
    else
    {
       result = STATUS_BUSY ;
    }
    return result;
}

/**********************************************************************************************************************/

//COMES EVERY 2 ms
void LcdTask(void)
{
	if(initCompleted)
    {
		  switch(currentProcess)
		  {
			  case idle_proc:
								     /* DO NOTHING */        break;
			  case write_proc:
							  	     WriteProcess();        break;
			  case clear_proc:
								     ClearProcess();        break;
			  case curserMove_proc:
								     MoveCurserProcess();   break;
		  }
	}
    else
    {
          InitProcess();
    }
}

/***************************************** Notification FUNCTIONS **********************************************************************/

extern void LCD_setWriteDoneNotification(notify_t  cbf)
{
	if(cbf)
	   appWriteDoneNotify = cbf ;
}

extern void LCD_setClearDoneNotification(notify_t  cbf)
{
	if(cbf)
	   appClearDoneNotify = cbf ;
}

extern void LCD_setMoveDoneNotification(notify_t  cbf)
{
	if(cbf)
	   appMoveDoneNotify = cbf ;
}


/****************************************************** static functions ***************************************************************/

static void InitProcess(void)
{
	static InitState_t  currentState = s1;
	static u8  E , counter , FLAG ;

	if(counter == 20)
	{
		switch(currentState)
		{
			  case s1:
					 if(E == 1)
					 {
						  GPIO_voidWritePin( LCD_EN , LCD_PORT , BIT_RESET);
						  E=0 ;
						  currentState = s2 ;
					 }

					 else
					 {
							GPIO_voidWritePin( LCD_RS , LCD_PORT , BIT_RESET);
						    GPIO_voidWritePin( LCD_RW , LCD_PORT , BIT_RESET);

						 GPIO_voidWritePin ( LCD_D0 ,  LCD_PORT   ,    GET_BIT(LCD_FunctionSet8bit,0)    );
						 GPIO_voidWritePin ( LCD_D1 ,  LCD_PORT   ,    GET_BIT(LCD_FunctionSet8bit,1)    );
						 GPIO_voidWritePin ( LCD_D2 ,  LCD_PORT   ,    GET_BIT(LCD_FunctionSet8bit,2)    );
						 GPIO_voidWritePin ( LCD_D3 ,  LCD_PORT   ,    GET_BIT(LCD_FunctionSet8bit,3)    );
						 GPIO_voidWritePin ( LCD_D4 ,  LCD_PORT   ,    GET_BIT(LCD_FunctionSet8bit,4)    );
						 GPIO_voidWritePin ( LCD_D5 ,  LCD_PORT   ,    GET_BIT(LCD_FunctionSet8bit,5)    );
						 GPIO_voidWritePin ( LCD_D6 ,  LCD_PORT   ,    GET_BIT(LCD_FunctionSet8bit,6)    );
						 GPIO_voidWritePin ( LCD_D7 ,  LCD_PORT   ,    GET_BIT(LCD_FunctionSet8bit,7)    );

						 GPIO_voidWritePin( LCD_EN , LCD_PORT , BIT_SET);
						 E = 1 ;
					 }
				  break;

			case s2:
					 if(E == 1)
					 {
							GPIO_voidWritePin( LCD_EN , LCD_PORT , BIT_RESET);
							E=0 ;
							currentState = s3 ;
					 }
					 else
					 {
							GPIO_voidWritePin( LCD_RS , LCD_PORT , BIT_RESET);
						    GPIO_voidWritePin( LCD_RW , LCD_PORT , BIT_RESET);

						 GPIO_voidWritePin ( LCD_D0 ,  LCD_PORT   ,    GET_BIT(LCD_DisplayOn,0)    );
						 GPIO_voidWritePin ( LCD_D1 ,  LCD_PORT   ,    GET_BIT(LCD_DisplayOn,1)    );
						 GPIO_voidWritePin ( LCD_D2 ,  LCD_PORT   ,    GET_BIT(LCD_DisplayOn,2)    );
						 GPIO_voidWritePin ( LCD_D3 ,  LCD_PORT   ,    GET_BIT(LCD_DisplayOn,3)    );
						 GPIO_voidWritePin ( LCD_D4 ,  LCD_PORT   ,    GET_BIT(LCD_DisplayOn,4)    );
						 GPIO_voidWritePin ( LCD_D5 ,  LCD_PORT   ,    GET_BIT(LCD_DisplayOn,5)    );
						 GPIO_voidWritePin ( LCD_D6 ,  LCD_PORT   ,    GET_BIT(LCD_DisplayOn,6)    );
						 GPIO_voidWritePin ( LCD_D7 ,  LCD_PORT   ,    GET_BIT(LCD_DisplayOn,7)    );

						 GPIO_voidWritePin( LCD_EN , LCD_PORT , BIT_SET);
						 E = 1 ;
					 }
			  break;

		 case s3:
					 if(E == 1)
					 {
							GPIO_voidWritePin( LCD_EN , LCD_PORT , BIT_RESET);
							E=0 ;
							currentState = s4 ;
					 }
					 else
					 {
							GPIO_voidWritePin( LCD_RS , LCD_PORT , BIT_RESET);
						    GPIO_voidWritePin( LCD_RW , LCD_PORT , BIT_RESET);

						 GPIO_voidWritePin ( LCD_D0 ,  LCD_PORT   ,    GET_BIT(LCD_Clear_Display,0)    );
						 GPIO_voidWritePin ( LCD_D1 ,  LCD_PORT   ,    GET_BIT(LCD_Clear_Display,1)    );
						 GPIO_voidWritePin ( LCD_D2 ,  LCD_PORT   ,    GET_BIT(LCD_Clear_Display,2)    );
						 GPIO_voidWritePin ( LCD_D3 ,  LCD_PORT   ,    GET_BIT(LCD_Clear_Display,3)    );
						 GPIO_voidWritePin ( LCD_D4 ,  LCD_PORT   ,    GET_BIT(LCD_Clear_Display,4)    );
						 GPIO_voidWritePin ( LCD_D5 ,  LCD_PORT   ,    GET_BIT(LCD_Clear_Display,5)    );
						 GPIO_voidWritePin ( LCD_D6 ,  LCD_PORT   ,    GET_BIT(LCD_Clear_Display,6)    );
						 GPIO_voidWritePin ( LCD_D7 ,  LCD_PORT   ,    GET_BIT(LCD_Clear_Display,7)    );

						 GPIO_voidWritePin( LCD_EN , LCD_PORT , BIT_SET);
						 E = 1 ;
					 }

			 break;

		  case s4:
					 if(E == 1)
					 {
							GPIO_voidWritePin( LCD_EN , LCD_PORT , BIT_RESET);
							E=0 ;
							FLAG =1;
					 }
					 else
					 {
							GPIO_voidWritePin( LCD_RS , LCD_PORT , BIT_RESET);
						    GPIO_voidWritePin( LCD_RW , LCD_PORT , BIT_RESET);

						 GPIO_voidWritePin ( LCD_D0 ,  LCD_PORT   ,    GET_BIT(LCD_EntryMode,0)    );
						 GPIO_voidWritePin ( LCD_D1 ,  LCD_PORT   ,    GET_BIT(LCD_EntryMode,1)    );
						 GPIO_voidWritePin ( LCD_D2 ,  LCD_PORT   ,    GET_BIT(LCD_EntryMode,2)    );
						 GPIO_voidWritePin ( LCD_D3 ,  LCD_PORT   ,    GET_BIT(LCD_EntryMode,3)    );
						 GPIO_voidWritePin ( LCD_D4 ,  LCD_PORT   ,    GET_BIT(LCD_EntryMode,4)    );
						 GPIO_voidWritePin ( LCD_D5 ,  LCD_PORT   ,    GET_BIT(LCD_EntryMode,5)    );
						 GPIO_voidWritePin ( LCD_D6 ,  LCD_PORT   ,    GET_BIT(LCD_EntryMode,6)    );
						 GPIO_voidWritePin ( LCD_D7 ,  LCD_PORT   ,    GET_BIT(LCD_EntryMode,7)    );

						 GPIO_voidWritePin( LCD_EN , LCD_PORT , BIT_SET);
						 E = 1 ;
					 }
			 break;
		}
	}
	else
	{
        counter++;
	}

	if (FLAG == 1)
	{
		initCompleted = 1;
	}
}

/**********************************************************************************************************************/

static void WriteProcess(void)
{
	  static u8 currentChar , E;

	  if(E==1)
	  {
		     GPIO_voidWritePin( LCD_EN , LCD_PORT , BIT_RESET);
		     E=0;
	  }
	  else
	  {
			if(userWordLength == currentChar)
			{
				currentProcess = idle_proc ;
				currentChar = 0;
				appWriteDoneNotify();
			}
			else
			{
				 GPIO_voidWritePin( LCD_RS , LCD_PORT , BIT_SET);
				 GPIO_voidWritePin( LCD_RW , LCD_PORT , BIT_RESET);

				 GPIO_voidWritePin ( LCD_D0 ,  LCD_PORT   ,    GET_BIT(userWord[currentChar],0)    );
				 GPIO_voidWritePin ( LCD_D1 ,  LCD_PORT   ,    GET_BIT(userWord[currentChar],1)    );
				 GPIO_voidWritePin ( LCD_D2 ,  LCD_PORT   ,    GET_BIT(userWord[currentChar],2)    );
				 GPIO_voidWritePin ( LCD_D3 ,  LCD_PORT   ,    GET_BIT(userWord[currentChar],3)    );
				 GPIO_voidWritePin ( LCD_D4 ,  LCD_PORT   ,    GET_BIT(userWord[currentChar],4)    );
				 GPIO_voidWritePin ( LCD_D5 ,  LCD_PORT   ,    GET_BIT(userWord[currentChar],5)    );
				 GPIO_voidWritePin ( LCD_D6 ,  LCD_PORT   ,    GET_BIT(userWord[currentChar],6)    );
				 GPIO_voidWritePin ( LCD_D7 ,  LCD_PORT   ,    GET_BIT(userWord[currentChar],7)    );

				 GPIO_voidWritePin( LCD_EN , LCD_PORT , BIT_SET);
				 E=1;
				 currentChar++ ;
			}
	  }
}


/**********************************************************************************************************************/

static void ClearProcess(void)
{
	 static u8 E;

	  if(E==1)
	  {
		    GPIO_voidWritePin( LCD_EN , LCD_PORT , BIT_RESET);
		    E=0;
			currentProcess = idle_proc ;
			appClearDoneNotify();
	  }
	  else
	  {
				 GPIO_voidWritePin( LCD_RS , LCD_PORT , BIT_RESET);
				 GPIO_voidWritePin( LCD_RW , LCD_PORT , BIT_RESET);

				 GPIO_voidWritePin ( LCD_D0 ,  LCD_PORT   ,    GET_BIT(LCD_Clear_Display,0)    );
				 GPIO_voidWritePin ( LCD_D1 ,  LCD_PORT   ,    GET_BIT(LCD_Clear_Display,1)    );
				 GPIO_voidWritePin ( LCD_D2 ,  LCD_PORT   ,    GET_BIT(LCD_Clear_Display,2)    );
				 GPIO_voidWritePin ( LCD_D3 ,  LCD_PORT   ,    GET_BIT(LCD_Clear_Display,3)    );
				 GPIO_voidWritePin ( LCD_D4 ,  LCD_PORT   ,    GET_BIT(LCD_Clear_Display,4)    );
				 GPIO_voidWritePin ( LCD_D5 ,  LCD_PORT   ,    GET_BIT(LCD_Clear_Display,5)    );
				 GPIO_voidWritePin ( LCD_D6 ,  LCD_PORT   ,    GET_BIT(LCD_Clear_Display,6)    );
				 GPIO_voidWritePin ( LCD_D7 ,  LCD_PORT   ,    GET_BIT(LCD_Clear_Display,7)    );

				 GPIO_voidWritePin( LCD_EN , LCD_PORT , BIT_SET);
				 E=1;
	  }
}

/**********************************************************************************************************************/

static void MoveCurserProcess(void)
{
	  static u8 E;
      u8  position = reqLine + reqDigit;
 	  if(E==1)
	  {
		  GPIO_voidWritePin( LCD_EN , LCD_PORT , BIT_RESET);
		  E=0;
		  currentProcess = idle_proc ;
		  appMoveDoneNotify();
	  }
	  else
	  {
				 GPIO_voidWritePin( LCD_RS , LCD_PORT , BIT_RESET);
				 GPIO_voidWritePin( LCD_RW , LCD_PORT , BIT_RESET);

				 GPIO_voidWritePin ( LCD_D0 ,  LCD_PORT   ,    GET_BIT(position,0)    );
				 GPIO_voidWritePin ( LCD_D1 ,  LCD_PORT   ,    GET_BIT(position,1)    );
				 GPIO_voidWritePin ( LCD_D2 ,  LCD_PORT   ,    GET_BIT(position,2)    );
				 GPIO_voidWritePin ( LCD_D3 ,  LCD_PORT   ,    GET_BIT(position,3)    );
				 GPIO_voidWritePin ( LCD_D4 ,  LCD_PORT   ,    GET_BIT(position,4)    );
				 GPIO_voidWritePin ( LCD_D5 ,  LCD_PORT   ,    GET_BIT(position,5)    );
				 GPIO_voidWritePin ( LCD_D6 ,  LCD_PORT   ,    GET_BIT(position,6)    );
				 GPIO_voidWritePin ( LCD_D7 ,  LCD_PORT   ,    GET_BIT(position,7)    );

				 GPIO_voidWritePin( LCD_EN , LCD_PORT , BIT_SET);
				 E=1;

	  }
}

/**********************************************************************************************************************/


