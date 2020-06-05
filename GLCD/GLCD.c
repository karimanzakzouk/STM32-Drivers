/*
 * GLCD.c
 *
 *  Created on: Apr 22, 2020
 *      Author: kariman
 */


#include "STD_TYPES.h"
#include "GLCD.h"
#include "SPI.h"
#include "SYSTICK.h"
#include "GPIO.h"
#include "Delay.h"




static void GLCD_WriteData(u8 data);

static void GLCD_WriteCmd(u8 cmd);





void GLCD_Init(void)
{
    /* pulse H=2  , L=2  */
	GPIO_voidWritePin(PIN_2, PORTA , BIT_SET);
	SYSTICK_BusyDelay(2);
	//Delay_ms(2000);
	GPIO_voidWritePin(PIN_2, PORTA , BIT_RESET);
    SYSTICK_BusyDelay(2);
	//Delay_ms(2000);

	GPIO_voidWritePin(PIN_2, PORTA , BIT_SET);

	/* INIT CMDS ............................................. */

	/* 1- GO FOR EXTENDED MODE , HORIZOTAL */
	GLCD_WriteCmd(0b00100001);//BIT0 > H=1

    /* TEMP CONTROL : CURVE2 > TYPICAL CURVE */
	GLCD_WriteCmd(0b00000110);//01 ?????????

    /* BIAS SYSTEM 1: 48 */
	GLCD_WriteCmd(0b00010011);

    /* VOP -> CONTRAST  */
	GLCD_WriteCmd(0XBE);//OR 0XBF


	/* 2- GO FOR NORMAL MODE  */
	GLCD_WriteCmd(0b00100000);//BIT0 > H=0
    /* DISPLAY CONTROL CMD */
	GLCD_WriteCmd(0b00001100);

}



void GLCD_Display(u8* data)
{
	u16 i=0 ;

	GLCD_WriteCmd(0b01000000);//y=0
	GLCD_WriteCmd(0b10000000);//x=0


	/* x=0 , y=0 */
	for(i=0 ; i < 504 ; i++)
	{
		GLCD_WriteData(data[i]);
	}


}





void GLCD_WriteData(u8 data)
{
   /* CE = 0  */
   GPIO_voidWritePin(PIN_3, PORTA , BIT_RESET);

   /* CD = 1 FOR DATA   */
   GPIO_voidWritePin(PIN_1, PORTA , BIT_SET);

   /* SEND DATA*/
   SPI_Send(data);

   /* CE = 1  */
   GPIO_voidWritePin(PIN_3, PORTA , BIT_SET);

}


void GLCD_WriteCmd(u8 cmd)
{
	   /* CE = 0  */
	   GPIO_voidWritePin(PIN_3, PORTA , BIT_RESET);

	   /* CD = 0 FOR CMD   */
	   GPIO_voidWritePin(PIN_1, PORTA , BIT_RESET);

	   /* SEND CMD */
	   SPI_Send(cmd);

	   /* CE = 1  */
	   GPIO_voidWritePin(PIN_3, PORTA , BIT_SET);
}



