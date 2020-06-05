/*
 * SPI.c
 *
 *  Created on: Apr 22, 2020
 *      Author: kimoz
 */


#include "STD_TYPES.h"
#include "MACROS.h"
#include "SPI.h"


/************************************************ MASKS **************************************************/

/* SPI SPE mask */
#define CR1_SPE_Set          ((u16)0x0040)
#define CR1_SPE_Reset        ((u16)0xFFBF)

/* SPI CRCNext mask */
#define CR1_CRCNext_Set      ((u16)0x1000)

/* SPI CRCEN mask */
#define CR1_CRCEN_Set        ((u16)0x2000)
#define CR1_CRCEN_Reset      ((u16)0xDFFF)

/* SPI SSOE mask */
#define CR2_SSOE_Set         ((u16)0x0004)
#define CR2_SSOE_Reset       ((u16)0xFFFB)

/* SPI registers Masks */
#define CR1_CLEAR_Mask       ((u16)0x3040)
#define I2SCFGR_CLEAR_Mask   ((u16)0xF040)

/* SPI or I2S mode selection masks */
#define SPI_Mode_Select      ((u16)0xF7FF)
#define I2S_Mode_Select      ((u16)0x0800)


/********************************************** REGISTERS *******************************************************/


#define  SPI1_BASE_ADDRESS     (u32)0x40013000
#define  SPI2_BASE_ADDRESS     (u32)0x40003800
#define  SPI3_BASE_ADDRESS     (u32)0x40003C00

typedef struct SPI
{
	u32 CR1;
	u32 CR2; //INTERRUPT  EN
	u32 SR; //FLAGS .... [ BSY > BIT 7 ]
	u32 DR ;
	//NO NEED TO CRC
	u32 CRCPR;
	u32 RXCRCR;
	u32 TXCRCR;
	//NO NEED TO I2S
	u32 I2SCFGR;
	u32 I2SPR;

}SPI_t;



volatile SPI_t *  const  SPI_1  = (SPI_t*) SPI1_BASE_ADDRESS  ;
volatile SPI_t *  const  SPI_2  = (SPI_t*) SPI2_BASE_ADDRESS  ;
volatile SPI_t *  const  SPI_3  = (SPI_t*) SPI3_BASE_ADDRESS  ;



/*******************************************************************************************************/

//extern  SPI_Init_t  SPI_Init_t ;

/************************************************ FUNCTIONS *************************************************/

/* SPIx : SPI1 , SPI2 , SPI3  */

void SPI_Init(void)//SPI_t* SPIx
{

/*
 * CPHA = 1 to write
 * CPOL = 0 low
 * MSTR =1  MASTER
 * BR [2:0] => Baud rate  [ 001: fPCLK/4 = 2M ]
 * SPE =1 EN
 * LSB FIRST = 0     [ MSB = 0 , LSB =1 ]
 *
 * SSI =  1           [ IF MASTER SHOULD BE 1 ]
 * SSM =  1           [ 1 MANAGE BY SW DISCONNECT NSS PIN  FORM MC ]
 * RX ONLY =  0       [ 1 RECEIVE ONLY ]
 * DFF = 8 BITS DATA  [ 0 - U8 , 1 U16 ]
 * [NO CRC].................
 * CRC NEXT = 0
 * CRC EN = 0
 * BIDI OE = 0        [ FOR Bidirectional ]
 * BIDI MODE = 0      [UNI = 0 , Bidirectional = 1 ]
 */


	SPI_1->CR1 = 0X034D ; //  0b0000001101001101; //0X034D

}


u8  SPI_Send( u8 data ) //SPI_t* SPIx ,
{
	/* SEND DATA  */
	SPI_1->DR = (u32)data ;

    /* WAIT BUSY FLAG  [ BSY > BIT 7 ]  */
    //while( GET_BIT( SPI_1->SR , 7 ) == 1 );


	return  (u8)SPI_1->DR ;
}






/*
u8  SPI_Receive(SPI_t* SPIx , u8* data)
{





  return  0 ;
}

*/



//	u16 tmpreg = 0;
	/*---------------------------- SPIx CR1 Configuration ------------------------*/
	  /* Get the SPIx CR1 value */
//	  tmpreg = SPIx->CR1;
	  /* Clear BIDIMode, BIDIOE, RxONLY, SSM, SSI, LSBFirst, BR, MSTR, CPOL and CPHA bits */
//	  tmpreg &= CR1_CLEAR_Mask;
	  /* Configure SPIx: direction, NSS management, first transmitted bit, BaudRate prescaler
	     master/salve mode, CPOL and CPHA */
	  /* Set BIDImode, BIDIOE and RxONLY bits according to SPI_Direction value */
	  /* Set SSM, SSI and MSTR bits according to SPI_Mode and SPI_NSS values */
	  /* Set LSBFirst bit according to SPI_FirstBit value */
	  /* Set BR bits according to SPI_BaudRatePrescaler value */
	  /* Set CPOL bit according to SPI_CPOL value */
	  /* Set CPHA bit according to SPI_CPHA value */
	  /*tmpreg |= (u16)((u32)SPI_Init_t->SPI_Direction |
			               SPI_Init_t->SPI_Mode |
	                       SPI_Init_t->SPI_DataSize |
					       SPI_Init_t->SPI_CPOL |
	                       SPI_Init_t->SPI_CPHA |
					       SPI_Init_t->SPI_NSS |
	                       SPI_Init_t->SPI_BaudRatePrescaler |
						   SPI_Init_t->SPI_FirstBit);*/

	  /* Write to SPIx CR1 */
//	  SPIx->CR1 = tmpreg;

	  /* Activate the SPI mode (Reset I2SMOD bit in I2SCFGR register) */
//	  SPIx->I2SCFGR &= SPI_Mode_Select;

	/*---------------------------- SPIx CRCPOLY Configuration --------------------*/
	  /* Write to SPIx CRCPOLY */
	 // SPIx->CRCPR = SPI_Init_t->SPI_CRCPolynomial;
