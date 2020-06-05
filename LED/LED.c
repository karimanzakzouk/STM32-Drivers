#include"STD_TYPES.h"
#include"GPIO.h"
#include"LED.h"
#include"LED_cfg.h"


extern  GPIO_InitTypeDef  LEDS[LEDS_NUM] ;



void HLED_Init(u8 ledName )
{
	  GPIO_voidInitPin(&LEDS[ledName]);
}


void HLED_SetLedState(u8 ledName, u8 state )
{
   
	  if(state == BIT_SET)
	  {
		 GPIO_voidWritePin(LEDS[ledName].pin, LEDS[ledName].port,LEDS[ledName].GPIO_ON);
	  }
	  else if (state == BIT_RESET)
	  {
		 GPIO_voidWritePin(LEDS[ledName].pin, LEDS[ledName].port,LEDS[ledName].GPIO_OFF);
	  }
	  else
	  {}
    
}

