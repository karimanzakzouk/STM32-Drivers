/*******************************************************************************
 *  FILE         : DMA_program.c                                               *
 *  VERSION      : 1.0                                                         *
 *  AUTHOR       : kariman                                                     *
 *  DATE         : 20 APRIL 2020                                               *
 *******************************************************************************/


#include "STD_TYPES.h"
#include "DMA_interface.h"



/***************************************** MASKS ************************************************/

#define DMA1_IT_GL1                        ((u32)0x00000001)
#define DMA1_IT_TC1                        ((u32)0x00000002)
#define DMA1_IT_HT1                        ((u32)0x00000004)
#define DMA1_IT_TE1                        ((u32)0x00000008)
#define DMA1_IT_GL2                        ((u32)0x00000010)
#define DMA1_IT_TC2                        ((u32)0x00000020)
#define DMA1_IT_HT2                        ((u32)0x00000040)
#define DMA1_IT_TE2                        ((u32)0x00000080)
#define DMA1_IT_GL3                        ((u32)0x00000100)
#define DMA1_IT_TC3                        ((u32)0x00000200)
#define DMA1_IT_HT3                        ((u32)0x00000400)
#define DMA1_IT_TE3                        ((u32)0x00000800)
#define DMA1_IT_GL4                        ((u32)0x00001000)
#define DMA1_IT_TC4                        ((u32)0x00002000)
#define DMA1_IT_HT4                        ((u32)0x00004000)
#define DMA1_IT_TE4                        ((u32)0x00008000)
#define DMA1_IT_GL5                        ((u32)0x00010000)
#define DMA1_IT_TC5                        ((u32)0x00020000)
#define DMA1_IT_HT5                        ((u32)0x00040000)
#define DMA1_IT_TE5                        ((u32)0x00080000)
#define DMA1_IT_GL6                        ((u32)0x00100000)
#define DMA1_IT_TC6                        ((u32)0x00200000)
#define DMA1_IT_HT6                        ((u32)0x00400000)
#define DMA1_IT_TE6                        ((u32)0x00800000)
#define DMA1_IT_GL7                        ((u32)0x01000000)
#define DMA1_IT_TC7                        ((u32)0x02000000)
#define DMA1_IT_HT7                        ((u32)0x04000000)
#define DMA1_IT_TE7                        ((u32)0x08000000)


#define DMA1_FLAG_GL1                      ((u32)0x00000001)
#define DMA1_FLAG_TC1                      ((u32)0x00000002)
#define DMA1_FLAG_HT1                      ((u32)0x00000004)
#define DMA1_FLAG_TE1                      ((u32)0x00000008)
#define DMA1_FLAG_GL2                      ((u32)0x00000010)
#define DMA1_FLAG_TC2                      ((u32)0x00000020)
#define DMA1_FLAG_HT2                      ((u32)0x00000040)
#define DMA1_FLAG_TE2                      ((u32)0x00000080)
#define DMA1_FLAG_GL3                      ((u32)0x00000100)
#define DMA1_FLAG_TC3                      ((u32)0x00000200)
#define DMA1_FLAG_HT3                      ((u32)0x00000400)
#define DMA1_FLAG_TE3                      ((u32)0x00000800)
#define DMA1_FLAG_GL4                      ((u32)0x00001000)
#define DMA1_FLAG_TC4                      ((u32)0x00002000)
#define DMA1_FLAG_HT4                      ((u32)0x00004000)
#define DMA1_FLAG_TE4                      ((u32)0x00008000)
#define DMA1_FLAG_GL5                      ((u32)0x00010000)
#define DMA1_FLAG_TC5                      ((u32)0x00020000)
#define DMA1_FLAG_HT5                      ((u32)0x00040000)
#define DMA1_FLAG_TE5                      ((u32)0x00080000)
#define DMA1_FLAG_GL6                      ((u32)0x00100000)
#define DMA1_FLAG_TC6                      ((u32)0x00200000)
#define DMA1_FLAG_HT6                      ((u32)0x00400000)
#define DMA1_FLAG_TE6                      ((u32)0x00800000)
#define DMA1_FLAG_GL7                      ((u32)0x01000000)
#define DMA1_FLAG_TC7                      ((u32)0x02000000)
#define DMA1_FLAG_HT7                      ((u32)0x04000000)
#define DMA1_FLAG_TE7                      ((u32)0x08000000)



/*************************************** REGISTERS **********************************************/

typedef struct
{
  u32  CCR;
  u32  CNDTR;
  u32  CPAR;
  u32  CMAR;
  u32  RESERVED;

}DMA_CHANNEL_t;


typedef struct
{
  u32  ISR;
  u32  IFCR;
  DMA_CHANNEL_t   CHANNELS[7];

}DMA_t; 


static volatile  DMA_t*  const DMA1  =   (DMA_t*) 0x40020000  ;


/************************************* FUNCTIONS PROTOTYPES **************************************/

static void(*DMA1_CH1_CallBack)(void);
static void(*DMA1_CH2_CallBack)(void);
static void(*DMA1_CH3_CallBack)(void);
static void(*DMA1_CH4_CallBack)(void);
static void(*DMA1_CH5_CallBack)(void);
static void(*DMA1_CH6_CallBack)(void);
static void(*DMA1_CH7_CallBack)(void);


/************************************* FUNCTIONS DEFINITION ***************************************/



/*************************************************************************
 * Description : Function to init DMA
 * Return Type : void
 * Input Argument : channel
 ************************************************************************/

void DMA1_Init(u8 channel ,  DMA_CFG_t* DMA)
{

	DMA1 -> CHANNELS[channel].CCR  |= DMA->TC_enable;
	DMA1 -> CHANNELS[channel].CCR  |= DMA->HT_enable;
	DMA1 -> CHANNELS[channel].CCR  |= DMA->TE_enable;

	DMA1 -> CHANNELS[channel].CCR  |= DMA->pSize;
	DMA1 -> CHANNELS[channel].CCR  |= DMA->mSize;

	DMA1 -> CHANNELS[channel].CCR  |= DMA->pAutoInc;
	DMA1 -> CHANNELS[channel].CCR  |= DMA->mAutoInc;

	DMA1 -> CHANNELS[channel].CCR  |= DMA->M2M;
	DMA1 -> CHANNELS[channel].CCR  |= DMA->direction;

	DMA1 -> CHANNELS[channel].CCR  |= DMA->mode;
	DMA1 -> CHANNELS[channel].CCR  |= DMA->priority;

	DMA1 -> CHANNELS[channel].CCR  |= DMA_Channel_Disable ;

}


/**********************************************************************
 * Description : Function to start DMA
 * Return Type : void
 * Input Argument :  channel number
 *                   pointer to structure of configuration
 **********************************************************************/

void DMA1_Start( u8 channel ,  DMA_CFG_t* DMA )
{
  // SET PERIPHERAL ADDRESS FOR DMA CHANNEL
  DMA1 -> CHANNELS[channel].CPAR  =  DMA->pAdd ;
  
  // SET MEMORY ADDRESS FOR DMA CHANNEL
  DMA1 -> CHANNELS[channel].CMAR  =  DMA->mAdd ;
  
  // SET BLOCK LENGTH FOR DMA CHANNEL
  DMA1 -> CHANNELS[channel].CNDTR =  DMA->CNTR ;
  

  // ENABLE DMA CHANNEL
  DMA1 -> CHANNELS[channel].CCR  |= DMA->enable ;
  
}


/*********************************************************************************************************************/


/**********************************************************************
 * Description : Function to set the  callback function
 * Return Type : void
 * Input Argument : pointer to function
 **********************************************************************/

void DMA1_Channel1_SetCallBack( void(*Cbf)(void))
{
    if(Cbf)
	   DMA1_CH1_CallBack = Cbf;
}

void DMA1_Channel2_SetCallBack( void(*Cbf)(void))
{
    if(Cbf)
	   DMA1_CH2_CallBack = Cbf;
}

void DMA1_Channel3_SetCallBack( void(*Cbf)(void))
{
    if(Cbf)
	   DMA1_CH3_CallBack = Cbf;
}

void DMA1_Channel4_SetCallBack( void(*Cbf)(void))
{
    if(Cbf)
	   DMA1_CH4_CallBack = Cbf;
}

void DMA1_Channel5_SetCallBack( void(*Cbf)(void))
{
    if(Cbf)
	   DMA1_CH5_CallBack = Cbf;
}

void DMA1_Channel6_SetCallBack( void(*Cbf)(void))
{
    if(Cbf)
	   DMA1_CH6_CallBack = Cbf;
}

void DMA1_Channel7_SetCallBack( void(*Cbf)(void))
{
    if(Cbf)
	   DMA1_CH7_CallBack = Cbf;
}

/*********************************************************************************************************************/



/***************************************************************************
 * Description : DMA handlers to call the notification function
 * Return Type : void
 * Input Argument :  void
 ***************************************************************************/

void DMA1_Channel1_IRQHandler(void)
{

    if(DMA1_CH1_CallBack)
    {
    	DMA1_CH1_CallBack();
    }
}


void DMA1_Channel2_IRQHandler(void)
{
    if(DMA1_CH2_CallBack)
    {
    	DMA1_CH2_CallBack();
    }
}

void DMA1_Channel3_IRQHandler(void)
{
    if(DMA1_CH3_CallBack)
    {
    	DMA1_CH3_CallBack();
    }
}

void DMA1_Channel4_IRQHandler(void)
{
    if(DMA1_CH4_CallBack)
    {
    	DMA1_CH4_CallBack();
    }
}

void DMA1_Channel5_IRQHandler(void)
{
    if(DMA1_CH5_CallBack)
    {
    	DMA1_CH5_CallBack();
    }
}


void DMA1_Channel6_IRQHandler(void)
{
    if(DMA1_CH6_CallBack)
    {
    	DMA1_CH6_CallBack();
    }
}

void DMA1_Channel7_IRQHandler(void)
{
    if(DMA1_CH7_CallBack)
    {
    	DMA1_CH7_CallBack();
    }
}


