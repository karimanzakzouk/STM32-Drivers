
/********************************************************************************
**  FILENAME     : SCHEDULER_config.c     			                           **
**  VERSION      : 1.0                                                         **
**  DATE         : 20 March 2020                                               **
**  PLATFORM     : STM32F103                                                   **
**  AUTHOR       : kariman Mohamed                                             **
*********************************************************************************/

#include "STD_TYPES.h"
#include "SCHEDULER.h"
#include "SCHEDULER_config.h"



/********************************************* Global Variables **************************************************/

/* tasks and first delay  may be changed according to the application */

extern Task_t Write_Task;
extern Task_t Lcd_Task;
extern Task_t Debounce_Task;
extern Task_t Switch1_Task;
extern Task_t Led1_Task;
extern Task_t Led2_Task;


static SysTaskInfo_t SysTasksInfo[]={
										{&Lcd_Task,0},        //LCD EN
										{&Debounce_Task,0},  //DEBOUNCING
	                                 	{&Switch1_Task,0},  //SWITCH
										{&Led1_Task,0},    //LED1
										{&Write_Task,0},   //LCD
										{&Led2_Task,0},   //LED2

									};


/***************************************** function prototype *******************************************************/

SysTaskInfo_t* SysTasksInfoFunc(void);



/****************************************** function definition *****************************************************/
SysTaskInfo_t* SysTasksInfoFunc(void)
{
	return SysTasksInfo;
}

