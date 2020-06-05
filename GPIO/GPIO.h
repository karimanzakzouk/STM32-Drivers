#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "STD_TYPES.h"


typedef struct
{
  u32    pin;
  void*  port;
  u8     mode;
  u8     speed;
  u8     GPIO_ON;
  u8     GPIO_OFF;

}GPIO_InitTypeDef;

/*************************************** MACROS **********************************/

#define	BIT_RESET								          (u8)0
#define	BIT_SET									          (u8)1


#define PORTA 										    (void*)0x40010800
#define PORTB 										    (void*)0x40010C00
#define PORTC 										    (void*)0x40011000
                                      
                                      
#define	PIN_0											    (u32)1
#define	PIN_1											    (u32)2
#define	PIN_2											    (u32)4
#define	PIN_3											    (u32)8
#define	PIN_4											    (u32)0x10
#define	PIN_5											    (u32)0x20
#define	PIN_6											    (u32)0x40
#define	PIN_7											    (u32)0x80
#define	PIN_8											    (u32)0x100
#define	PIN_9											    (u32)0x200
#define	PIN_10										        (u32)0x400
#define	PIN_11										        (u32)0x800
#define	PIN_12										        (u32)0x1000
#define	PIN_13										        (u32)0x2000
#define	PIN_14										        (u32)0x4000
#define	PIN_15										        (u32)0x8000


/******************* MODES ***********************/

#define MODE_INPUT_ANALOG							      (u8)0x0
#define MODE_INPUT_FLOATING						          (u8)0x04

#define GPIO_MODE_INPUT_PULL_UP				              (u8)0x28
#define GPIO_MODE_INPUT_PULL_DOWN				          (u8)0x48

#define GPIO_MODE_OUTPUT_PUSH_PULL			          	  (u8)0x10
#define GPIO_MODE_OUTPUT_OPEN_DRAIN		  	              (u8)0x14
#define GPIO_MODE_OUTPUT_AF_PUSH_PULL	  	              (u8)0x18
#define GPIO_MODE_OUTPUT_AF_OPEN_DRAIN	     	          (u8)0x1C


#define	GPIO_SPEED_10_MHZ							      (u8)1
#define	GPIO_SPEED_2_MHZ								  (u8)2
#define	GPIO_SPEED_50_MHZ							      (u8)3


/*************************************** PROTOTYPES **********************************/

extern void GPIO_voidInitPin(GPIO_InitTypeDef*  GPIO_InitStruct);


extern void GPIO_voidWritePin(u32 pinNo, void* port , u8 state);


extern u8   GPIO_u8ReadPin(u32 pinNo, void* port);


#endif
