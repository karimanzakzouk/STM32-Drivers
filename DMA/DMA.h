/*******************************************************************************
 *  FILE         : DMA_interface.h                                             *
 *  VERSION      : 1.0                                                         *
 *  AUTHOR       : kariman                                                     *
 *  DATE         : 20 APRIL 2020                                               *
 *******************************************************************************/

#ifndef DMA_INT_H
#define DMA_INT_H



/*************************************************** MACROS ******************************************************/

#define    Channel1                 (u8)0
#define    Channel2                 (u8)1
#define    Channel3                 (u8)2
#define    Channel4                 (u8)3
#define    Channel5                 (u8)4
#define    Channel6                 (u8)5
#define    Channel7                 (u8)6


#define DMA_IT_TC_Enable                   ((u32)0x00000002)
#define DMA_IT_TC_Disable                  ((u32)0x00000000)//((u32)0xFFFFFFFD)

#define DMA_IT_HT_Enable                   ((u32)0x00000004)
#define DMA_IT_HT_Disable                  ((u32)0x00000000)//((u32)0xFFFFFFFB)

#define DMA_IT_TE_Enable                   ((u32)0x00000008)
#define DMA_IT_TE_Disable                  ((u32)0x00000000)//((u32)0xFFFFFFF7)


#define DMA_DIR_Peripheral_DST             ((u32)0x00000010)
#define DMA_DIR_Peripheral_SRC             ((u32)0x00000000)//((u32)0xFFFFFFEF)

#define DMA_PeripheralInc_Enable           ((u32)0x00000040)
#define DMA_PeripheralInc_Disable          ((u32)0x00000000)//((u32)0xFFFFFFBF)

#define DMA_MemoryInc_Enable               ((u32)0x00000080)
#define DMA_MemoryInc_Disable              ((u32)0x00000000)//((u32)0xFFFFFF7F)

#define DMA_PeripheralDataSize_Byte        ((u32)0x00000000)
#define DMA_PeripheralDataSize_HalfWord    ((u32)0x00000100)
#define DMA_PeripheralDataSize_Word        ((u32)0x00000200)

#define DMA_MemoryDataSize_Byte            ((u32)0x00000000)
#define DMA_MemoryDataSize_HalfWord        ((u32)0x00000400)
#define DMA_MemoryDataSize_Word            ((u32)0x00000800)

#define DMA_Mode_Circular                  ((u32)0x00000020)
#define DMA_Mode_Normal                    ((u32)0x00000000)

#define DMA_Priority_VeryHigh              ((u32)0x00003000)
#define DMA_Priority_High                  ((u32)0x00002000)
#define DMA_Priority_Medium                ((u32)0x00001000)
#define DMA_Priority_Low                   ((u32)0x00000000)

#define DMA_M2M_Enable                     ((u32)0x00004000)
#define DMA_M2M_Disable                    ((u32)0x00000000)//((u32)0xFFFFBFFF)

#define DMA_Channel_Enable                 ((u32)0x00000001)
#define DMA_Channel_Disable                ((u32)0x00000000)//((u32)0xFFFFFFFE)



/***************************************************** TYPES *******************************************************/

typedef struct
{
  u32  TC_enable;
  u32  HT_enable;
  u32  TE_enable;
  u32  pSize;
  u32  mSize;
  u32  pAutoInc;
  u32  mAutoInc;
  u32  M2M;
  u32  direction;
  u32  mode;
  u32  priority;
  u32  enable;
  u32  pAdd;
  u32  mAdd;
  u32  CNTR;

}DMA_CFG_t;

/**************************************** FUNCTIONS PROTOTYPES ***************************************************/



/**********************************************************************
 * Description : Function to initialize DMA
 * Return Type : void
 * Input Argument : channel number
 *                  pointer to structure of configuration
 **********************************************************************/
extern void DMA1_Init( u8 channel ,  DMA_CFG_t* DMA );


/**********************************************************************
 * Description : Function to start DMA
 * Return Type : void
 * Input Argument :  channel number
 *                   pointer to structure of configuration
 **********************************************************************/
extern void DMA1_Start( u8 channel ,  DMA_CFG_t* DMA );



/**********************************************************************
 * Description : Function to set the  callback function
 * Return Type : void
 * Input Argument : pointer to function
 **********************************************************************/

extern void DMA1_Channel1_SetCallBack( void(*Cbf)(void));
extern void DMA1_Channel2_SetCallBack( void(*Cbf)(void));
extern void DMA1_Channel3_SetCallBack( void(*Cbf)(void));
extern void DMA1_Channel4_SetCallBack( void(*Cbf)(void));
extern void DMA1_Channel5_SetCallBack( void(*Cbf)(void));
extern void DMA1_Channel6_SetCallBack( void(*Cbf)(void));
extern void DMA1_Channel7_SetCallBack( void(*Cbf)(void));




#include "DMA_config.h"



#endif
