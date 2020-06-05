/*******************************************************************************
 *  FILE         : UART.h                                            *
 *  VERSION      : 1.0                                                         *
 *  AUTHOR       : kariman                                                     *
 *  DATE         : 20 APRIL 2020                                               *
 *******************************************************************************/

#ifndef UART_H
#define UART_H


/********************** macros  **************************/

/*LIN Configuration options*/
#define LIN_BREAK_INTERRRUPT_ENABLED	0x00000040
#define LIN_BREAK_INTERRRUPT_DISABLED	0x00000000

#define LIN_BREAK_DETECTION_LENGTH_11	0x00000020
#define LIN_BREAK_DETECTION_LENGTH_10	0x00000000



/********************* types ******************************/

typedef void (*cbf_t)(void);

typedef struct
{
	u32 SR;
	u32 DR;
	u32 BRR;
	u32 CR1;
	u32 CR2;
	u32 CR3;
	u32 GPTR;

}UART_t;

/*****************  FUNCTION PROTOTYPES *******************/
/*
*
* Description: This API initialize UART
* Input:   1-USART1    
           2-USART2   
           3-USART3    
           4-UART4     
           5-UART5
* Output: void
*
*/
extern void UART_voidInit(UART_t* UART);

/*
*
* Description: This API send a data through UART 
* Input: u8 Array and the length of array
* Output: void
*
*/
extern ERROR_STATUS UART_u8Send( UART_t* UART, u8 * Buffer , u16 Copy_u16Length);

/*
* Description: This API receive a data through UART
* Input: Array and the length of the array
* Output: void
*
*/
extern ERROR_STATUS UART_u8Recieve(UART_t* UART ,  u8* Buffer , u16 Copy_u16Length);

/*
* Description: This API to Configure parameters of UART 
* Input: BaudRate , numbers of stop bits , the type of parity and flow control
* Output: void
*
*/
extern void UART_voidConfigure(UART_t* UART , u32 Copy_u32BaudRate , u8 Copy_u8StopBits , u8 Copy_u8Parity, u8 Copy_u8FlowControl);

/*
*
* Description: This API take the call back function which execute when transmission is done
* Input: function name 
* Output: void
*
*/
extern ERROR_STATUS UART_u8SetTxCbf(cbf_t Txcbf);

/*
* Description: This API take the call back function which execute when receiving is done
* Input: Function name 
* Output: void
*
*/
extern ERROR_STATUS UART_u8SetRxCbf(cbf_t Rxcbf);



/****************************************** LIN *******************************************************/


extern void UART_LIN_Init(UART_t* UART );


extern void UART_LIN_SendBreak(UART_t* UART);


extern u8  UART_LIN_SetBreakCbf(cbf_t  BreakCbf);




#include "UART_config.h"

#endif 

