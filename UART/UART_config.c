/*
 * UART_config.c
 *
 *  Created on: May 7, 2020
 *      Author: kariman
 */

#include "STD_TYPES.h"
#include "DMA.h"




DMA_CFG_t  DMA_TX = {

		.TC_enable = DMA_IT_TC_Enable  ,
		.HT_enable = DMA_IT_HT_Disable ,
		.TE_enable = DMA_IT_TE_Disable ,

		.pSize     = DMA_PeripheralDataSize_Byte   ,
		.mSize     = DMA_MemoryDataSize_Byte  ,

		.pAutoInc  = DMA_PeripheralInc_Disable ,
		.mAutoInc  = DMA_MemoryInc_Enable ,

		.M2M       = DMA_M2M_Disable ,
		.direction = DMA_DIR_Peripheral_DST,

		.mode      = DMA_Mode_Normal ,
		.priority  = DMA_Priority_VeryHigh ,

		.enable    = DMA_Channel_Enable ,
		.pAdd      = 0 ,
		.mAdd      = 0 ,
		.CNTR      = 0

};


DMA_CFG_t  DMA_RX = {

		.TC_enable = DMA_IT_TC_Enable  ,
		.HT_enable = DMA_IT_HT_Disable ,
		.TE_enable = DMA_IT_TE_Disable ,

		.pSize     = DMA_PeripheralDataSize_Byte   ,
		.mSize     = DMA_MemoryDataSize_Byte  ,

		.pAutoInc  = DMA_PeripheralInc_Disable ,
		.mAutoInc  = DMA_MemoryInc_Enable ,

		.M2M       = DMA_M2M_Disable ,
		.direction = DMA_DIR_Peripheral_SRC ,

		.mode      = DMA_Mode_Normal ,
		.priority  = DMA_Priority_VeryHigh ,
		.enable    = DMA_Channel_Enable ,
		.pAdd      = 0 ,
		.mAdd      = 0 ,
		.CNTR      = 0

};


