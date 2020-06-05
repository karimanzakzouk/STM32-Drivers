#include "STD_TYPES.h"
#include "MACROS.h"
#include "GPIO_interface.h"

/*************************************** REGISTERS **********************************/

typedef struct
{
	u32   CRL;
	u32   CRH;
	u32   IDR;
	u32   ODR;
	u32   BSR;
	u32   BRR;
	u32   LCK;

}GPIOstruct;

/*************************************** FUNCTIONS **********************************/

void GPIO_voidInitPin(GPIO_InitTypeDef* GPIO_InitStruct)
{
	 u32 tempLow=0 ,tempHigh=0;
	 u8 bitNo=0;

   tempLow  = ((GPIOstruct*)GPIO_InitStruct->port) ->CRL;
   tempHigh = ((GPIOstruct*)GPIO_InitStruct->port) ->CRH;
   
	for (bitNo = 0 ; bitNo<8 ; bitNo++)
	{
		if(  GPIO_InitStruct->pin & (1<<bitNo)  )
		{
			tempLow &= ~ ((0x0F)<< (bitNo<<2));

			if( GPIO_InitStruct->mode & 0x10)
			{
				tempLow |= ( ((GPIO_InitStruct->mode + GPIO_InitStruct->speed)&0x0F) << (bitNo<<2) );
			}
			else if(!(GPIO_InitStruct->mode & 0xF0))
			{
				tempLow |= ((GPIO_InitStruct->mode) << (bitNo<<2) );
			}
 		    else
		    {}
		}
	}

	for (bitNo = 0 ; bitNo<8 ; bitNo++)
	{
		if( GPIO_InitStruct->pin & ( 1 << (bitNo+8) ))
		{
			tempHigh &=~ ((0x0F)<< (bitNo<<2) );

			if( GPIO_InitStruct->mode & 0x10)
			{
				tempHigh |= ( ((GPIO_InitStruct->mode+GPIO_InitStruct->speed)&0x0F) << (bitNo<<2) );
			}
			else if(!(GPIO_InitStruct->mode & 0xF0))
			{
				tempHigh |= ((GPIO_InitStruct->mode)<< (bitNo<<2) );
			}
            else
            {}
		}
	}
  
  ((GPIOstruct*)GPIO_InitStruct->port) ->CRL  = tempLow;
  ((GPIOstruct*)GPIO_InitStruct->port) ->CRH  = tempHigh;


  if (GPIO_InitStruct->mode == GPIO_MODE_INPUT_PULL_UP )
  {
  	GPIO_voidWritePin(GPIO_InitStruct->pin, GPIO_InitStruct->port , BIT_SET );
  }
  else if (GPIO_InitStruct->mode  == GPIO_MODE_INPUT_PULL_DOWN)
  {
  	GPIO_voidWritePin(GPIO_InitStruct->pin, GPIO_InitStruct->port , BIT_RESET );
  }
  else
  {}

}


void GPIO_voidWritePin(u32 pinNo, void* port , u8 state)
{
      GPIOstruct*  GPIO_PORT  = (GPIOstruct*)port;
  	  
           if(state == BIT_SET)
			{
				GPIO_PORT->BSR = pinNo;
			}
			else if(state == BIT_RESET)
			{
				GPIO_PORT->BRR = pinNo;
			}
			else
		    {}
  
}


u8  GPIO_u8ReadPin(u32 pinNo, void* port)
{
	 u8 status;
      
	 GPIOstruct*  GPIO_PORT  = (GPIOstruct*)port;
	 status = (GPIO_PORT->IDR & pinNo) == pinNo;
	// trace_printf("CS..... = %d\n",status );
	return status;
}
