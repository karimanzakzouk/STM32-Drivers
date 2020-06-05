/*******************************************************************************
 *  FILE         : UART_program.c                                              *
 *  VERSION      : 1.0                                                         *
 *  AUTHOR       : kariman                                                     *
 *  DATE         : 20 APRIL 2020                                               *
 *******************************************************************************/


#include "STD_TYPES.h"
#include "GPIO.h"
#include "NVIC.h"
#include "UART.h"
#include "DMA.h"


/****************************************** MASKS **********************************************/

#define SR_TXE       0x00000080
#define SR_RXNE      0x00000020
#define CR1_UE       0x00002000
#define CR1_TE       0x00000008
#define CR1_RE       0x00000004
#define SR_TXE       0x00000080
#define SR_RXNE      0x00000020
#define SR_TXE_CLR   0xffffff7f
#define SR_RXNE_CLR  0xffffffdf
#define CR1_RXNEIE	 0x00000020
#define CR1_TXIE	 0x00000080
#define SR_TC_CLR    0xffffffbf
#define SR_TC		 0x00000040
#define CR1_TCIE     0x00000040
#define CR1_PCE		 0x00000100
#define CR3_CTSE	 0x00000200
#define CR3_RTSE	 0x00000100


/* mask for bitfield "CR3.DMAT" (DMA enable transmitter) */
#define CR3_DMAT_Enable  (0x00000080)
/* mask for bitfield "CR3.DMAR" (DMA enable receiver) */
#define CR3_DMAR_Enable  (0x00000040)


#define WORD_LENGTH_8   0x00001000
#define WORD_LENGTH_9   0x00000000
#define STOP_BITS_CLR   0xffffdfff
#define STOP_BITS_1     0x00000000
#define STOP_BITS_2     0x00002000
#define BUADRATE_9600   (u32)7500
#define PARITY_CLR      0xfffff9ff


/************ LIN  *****************/
#define CR2_CLKEN_CLR       0xfffff7ff
#define CR2_LBDIE_LBDL_CLR  0xffffff9f
#define CR2_LIN_ENABLE 	    0x00004000
#define CR3_LIN_INIT_CLR    0xffffffD5
#define CR1_LIN_SEND_BREAK  0x00000001
#define SR_LBD              0x00000100




#define ON 			1
#define OFF 		2


#define  UART_RX_Channel       Channel5
#define  UART_TX_Channel       Channel4

/**************************************** Addresses ***********************************************/


#define USART1_BASE_ADDRESS   (u32)0x40013800
#define USART2_BASE_ADDRESS   (u32)0x40004400
#define USART3_BASE_ADDRESS   (u32)0x40004800
#define UART4_BASE_ADDRESS    (u32)0x40004C00
#define UART5_BASE_ADDRESS    (u32)0x40005000


volatile UART_t * UART1 = (UART_t *) USART1_BASE_ADDRESS;
volatile UART_t * UART2 = (UART_t *) USART2_BASE_ADDRESS;
volatile UART_t * UART3 = (UART_t *) USART3_BASE_ADDRESS;
volatile UART_t * UART4 = (UART_t *) UART4_BASE_ADDRESS;
volatile UART_t * UART5 = (UART_t *) UART5_BASE_ADDRESS;


/***************************************** types ***************************************************/

typedef enum
{
	idle,
	busy

}BufferState_t;

typedef struct
{
	volatile u8  * data;
	u32  position;
	u32  size;
	BufferState_t state;

}DataBuffer_t;

DataBuffer_t TxBuffer;
DataBuffer_t RxBuffer;


typedef void (*appTxNotify_t) (void);
typedef void (*appRxNotify_t) (void);
typedef void (*LinBreakNotify_t) (void);

static appRxNotify_t  appRxNotify;
static appTxNotify_t  appTxNotify;
static LinBreakNotify_t LIN_break_CB;


extern  DMA_CFG_t  DMA_RX ;
extern  DMA_CFG_t  DMA_TX ;



/******************************************** FUNCTIONS DEFINITION *******************************************/


/*
 * Description: This API initialize UART
 * Input:  1-USART1
           2-USART2   
           3-USART3    
           4-UART4     
           5-UART5   
           u8 Copy_u8UART_Num
 * Output: void
 *
 */
void UART_voidInit (UART_t* UART)
{
	/* GPIO configure pins */
	GPIO_InitTypeDef  USART1_tx;
	GPIO_InitTypeDef  USART1_rx;

	USART1_tx.pin    = PIN_9;
	USART1_tx.speed  = GPIO_SPEED_50_MHZ;
	USART1_tx.mode   = GPIO_MODE_OUTPUT_AF_PUSH_PULL;
	USART1_tx.port   = PORTA;

	USART1_rx.pin   = PIN_10;
	USART1_rx.speed = NONE;
	USART1_rx.mode  = MODE_INPUT_FLOATING;
	USART1_rx.port  = PORTA;

	GPIO_voidInitPin(&USART1_tx);
	GPIO_voidInitPin(&USART1_rx);

	/*Enable usart1*/
	UART -> CR1 |= CR1_UE;

	/*setup default configurations data length=8 bits
	 *one stop bit
	 *BuadRate = 9600
	 */
	UART -> CR1  |= WORD_LENGTH_8;
	UART -> CR2  &= STOP_BITS_CLR;
	UART -> CR2  |= STOP_BITS_1;
	UART -> BRR   = BUADRATE_9600;

	/*  Enable transmitter and receive   */
	UART -> CR1 |= CR1_TE | CR1_RE;


	TxBuffer.state = idle;
	RxBuffer.state = idle;

#if UART_MODE == UART_INT

	/* Setup interrupts */
    NVIC_voidEnableExternalInt(NVIC_USART1);
    //NVIC_voidEnableExternalInt(NVIC_USART2);
    //NVIC_voidEnableExternalInt(NVIC_USART3);
    //NVIC_voidEnableExternalInt(NVIC_UART4);
    //NVIC_voidEnableExternalInt(NVIC_UART5);

	/*Enable transmitter and receive interrupts */
    UART -> CR1 |= CR1_TCIE  | CR1_RXNEIE ;


#elif  UART_MODE == UART_DMA

    UART -> CR3 |= CR3_DMAT_Enable ;
    UART -> CR3 |= CR3_DMAR_Enable ;

	DMA1_Init( UART_TX_Channel , &DMA_TX );
	DMA1_Init( UART_RX_Channel , &DMA_RX );


	UART -> CR1 |= CR1_TCIE ;
	/* Clear TC FLAG */
	UART -> SR &= SR_TC_CLR;

#endif

}

/*
 * Description: This API send a data through UART
 * Input: u8 Array and the length of array
 * Output: void
 *
 */
ERROR_STATUS UART_u8Send(UART_t* UART, u8 * Buffer , u16 Copy_u16Length)
{
	ERROR_STATUS Local_error = ERROR_OK;

#if UART_MODE == UART_INT

	if (Buffer && Copy_u16Length >0)
	{
		if (TxBuffer.state == idle)
		{
			TxBuffer.data = Buffer;
			TxBuffer.size = Copy_u16Length;
			TxBuffer.position = 0;
			TxBuffer.state = busy;

			UART -> DR = TxBuffer.data[TxBuffer.position];
		    TxBuffer.position++;
		}
	}
	else
	{
		Local_error = ERROR_NOK;
	}



#elif  UART_MODE == UART_DMA

	if (Buffer && Copy_u16Length >0)
	{
		DMA_TX.pAdd      =  (u32)& UART->DR;
		DMA_TX.mAdd      =  (u32) Buffer;
	    DMA_TX.CNTR      =  Copy_u16Length;

		DMA1_Start( UART_TX_Channel , &DMA_TX  );
	}
	else
	{
		Local_error = ERROR_NOK;
	}


#endif

	return Local_error;
}

/*
 * Description: This API receive a data through UART
 * Input: Array and the length of the array
 * Output: void
 *
 */
ERROR_STATUS UART_u8Recieve(UART_t* UART, u8* Buffer , u16 Copy_u16Length)
{
	ERROR_STATUS Local_error = ERROR_OK;

#if UART_MODE == UART_INT

	if (Buffer && Copy_u16Length > 0)
	{
		if (RxBuffer.state == idle)
		{
			RxBuffer.data = Buffer;
			RxBuffer.size = Copy_u16Length;
			RxBuffer.position = 0;
			RxBuffer.state = busy;
		}
	}
	else
	{
		Local_error = ERROR_NOK;
	}


#elif  UART_MODE == UART_DMA

	if (Buffer && Copy_u16Length > 0)
	{
		DMA_RX.pAdd      =  (u32)& UART->DR ;
		DMA_RX.mAdd      =  (u32) Buffer;
	    DMA_RX.CNTR      =  Copy_u16Length;

		DMA1_Start( UART_RX_Channel , &DMA_RX  );
	}
	else
	{
		Local_error = ERROR_NOK;
	}

#endif

	return Local_error;
}

/*
 *
 * Description: This API to Configure parameters of UART
 * Input: BaudRate :  BUADRATE_9600 ..
 *  	  StopBits :  STOP_BITS_1 or STOP_BITS_2
 *	  	  Parity   :  ON or OFF
 *	  	  ControlFlow: ON or OFF
 *
 * Output: void
 *
 */
void UART_voidConfigure(UART_t* UART , u32 Copy_u32BaudRate , u8 Copy_u8StopBits , u8 Copy_u8Parity, u8 Copy_u8FlowControl)
{
	UART -> BRR  = Copy_u32BaudRate;

	UART -> CR2 &= STOP_BITS_CLR;
	UART -> CR2 |= Copy_u8StopBits;

	if (Copy_u8Parity == ON)
	{
		UART -> CR1 |= CR1_PCE;
	}
	else
	{
		UART -> CR1 &= ~CR1_PCE;
	}

	if (Copy_u8FlowControl == ON)
	{
		UART -> CR3 |= CR3_CTSE;
		UART -> CR3 |= CR3_RTSE;
	}
	else
	{
		UART -> CR3 &= ~CR3_CTSE;
		UART -> CR3 &= ~CR3_RTSE;
	}

}







/*
 * Description: This API take the call back function which execute when tranmission is done
 * Input: function name
 * Output: void
 *
 */
ERROR_STATUS UART_u8SetTxCbf(cbf_t Txcbf)
{
	ERROR_STATUS Local_error = ERROR_OK;
	if(Txcbf)
	{
		appTxNotify = Txcbf;
	}
	else
	{
		Local_error = ERROR_NOK;
	}
	return Local_error;
}

/*
 * Description: This API take the call back function which execute when recieving is done
 * Input: Function name
 * Output: void
 *
 */
ERROR_STATUS UART_u8SetRxCbf(cbf_t Rxcbf)
{
	ERROR_STATUS Local_error = ERROR_OK;
	if(Rxcbf)
	{
		appRxNotify = Rxcbf;
	}
	else
	{
		Local_error = ERROR_NOK;
	}
	return Local_error;
}


void USART1_IRQHandler (void)
{
	if ((UART1->SR & SR_TC) && (TxBuffer.data) )
	{
		/* Clear TC Bit */
		UART1 -> SR &= SR_TC_CLR;

		if (TxBuffer.position != TxBuffer.size)
		{
			UART1 -> DR = TxBuffer.data[TxBuffer.position];
			TxBuffer.position++;
		}
		else
		{
			TxBuffer.data = NULL;
			TxBuffer.size = 0;
			TxBuffer.position = 0;
			TxBuffer.state = idle;
			appTxNotify();

		}
	}


	if (UART1->SR & SR_RXNE)
	{
		/*  Clear RXNE Bit */
		UART1 -> SR &= SR_RXNE_CLR;
		if (RxBuffer.state == busy )
		{
			RxBuffer.data[RxBuffer.position] = UART1 -> DR ;
			RxBuffer.position++;

			if (RxBuffer.position == RxBuffer.size)
			{
				RxBuffer.data = NULL;
				RxBuffer.size = 0;
				RxBuffer.position = 0;
				RxBuffer.state = idle;
				appRxNotify();
			}
		}
		else
		{
			return ;
		}
	}


    /*  LIN BREAK INTERRUPT   */
	if ( (UART1->SR & SR_LBD) == SR_LBD  )
	{
		/*Clear LBD flag */
		UART1 ->SR &= ~ SR_LBD;

		/*Clear RXNE flag */
		UART1 ->SR &= ~ SR_RXNE;

		/*Clear TC flag */
		UART1 ->SR &= ~ SR_TC;

		if(LIN_break_CB != NULL)
		{
			trace_printf("Break\n");
			LIN_break_CB();
		}
	}

}




/****************************************** LIN *******************************************************/


void UART_LIN_Init(UART_t* UART )
{
	u32 temp1 , temp2 ;

	temp1 = UART -> CR1;

	/* Enable uart */
	temp1 |= CR1_UE;

	/* Enable transmitter and receive */
	temp1 |= CR1_TE | CR1_RE;

	/* word length = 8 bits */
	temp1  |= WORD_LENGTH_8;

	/* Clear parity bit */
	temp1 &= PARITY_CLR;

	UART -> CR1 = temp1;



	temp2 = UART->CR2;

	/* Clear the stop bits */
	temp2  &= STOP_BITS_CLR;
	/* ONE STOP BIT */
	temp2  |= STOP_BITS_1;

	/* Clear CLKEN bit */
	temp2 &= CR2_CLKEN_CLR;

	/*Clear the LBDIE , LBDL bits*/
	temp2 &= CR2_LBDIE_LBDL_CLR;

	/*Setting the LBDIE , LBDL according to user configuration*/
	temp2 |= LIN_BREAK_INTERRUPT;

	/*Setting the LIN enable bit*/
	//temp |= USART_CR2_LIN_ENABLE_MASK;

	UART->CR2 = temp2;


	/*Clear IREN , HDSEL , SCEN bits*/
	UART->CR3 &= CR3_LIN_INIT_CLR;

	/*setting baudrate */
	UART->BRR = CLK_FREQUENCY_HZ / LIN_BAUDRATE;


	TxBuffer.state = idle;
	RxBuffer.state = idle;

}


void UART_LIN_SendBreak(UART_t* UART)
{
	UART->CR1 |= CR1_LIN_SEND_BREAK;
}


u8  UART_LIN_SetBreakCbf(cbf_t  BreakCbf)
{
	u8 local_status = ERROR_OK;
	if(BreakCbf)
	{
		LIN_break_CB = BreakCbf ;
	}
	else
	{
		local_status=ERROR_NOK;
	}
	return local_status;
}





