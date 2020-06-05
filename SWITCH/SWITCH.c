#include"STD_TYPES.h"
#include"GPIO.h"
#include"SWITCH.h"
#include"SWITCH_cfg.h"
#include"SCHEDULER.h"



/* VALUE OF NOT NEEDED CONFIGERATION OF SWITCH LIKE SPEED     */
#define   NONE               0


extern   SWITCH_InitTypeDef  SWITCHES[SWITCHES_NUM];

static   u8  state[SWITCHES_NUM];

/*************************************** SWITCH TASK *******************************/
const Task_t Debounce_Task= {DebounceTask , 4 };  //4 MSEC

void DebounceTask(void);

/**************************************** FUNCTIONS ********************************/

void HSWITCH_Init(u8 switchNum )
{
	GPIO_InitTypeDef  SWITCH = {SWITCHES[switchNum].pin ,SWITCHES[switchNum].port , SWITCHES[switchNum].mode, NONE , NONE , NONE };

	GPIO_voidInitPin(&SWITCH);
}

u8 HSWITCH_getSwitchState(u8 switchNum )
{

	if( SWITCHES[switchNum].mode == GPIO_MODE_INPUT_PULL_UP )
	{
		return state[switchNum] ^= 1 ;
	}
	else
	{
	    return state[switchNum] ;
	}
}



void DebounceTask(void)
{
      static u8 prev_state[SWITCHES_NUM];
      static u8 counter[SWITCHES_NUM];
      u8 current_state[SWITCHES_NUM];
      u8 switchNo;

      for (switchNo=0; switchNo<SWITCHES_NUM; switchNo++)
      {
			  current_state[switchNo] = GPIO_u8ReadPin(SWITCHES[switchNo].pin, SWITCHES[switchNo].port);

			  if(current_state[switchNo] == prev_state[switchNo])
			  {
				  counter[switchNo]++;
			  }
			  else
			  {
				  counter[switchNo]=0;
			  }

			 if(counter[switchNo] == MAX_COUNTS)
			 {
				 state[switchNo] = current_state[switchNo];
				 counter[switchNo]=0;
			 }

			 prev_state[switchNo] = current_state[switchNo];
      }
}
