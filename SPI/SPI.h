

#ifndef _SPI_H_
#define _SPI_H_

#define SPI_Direction_2Lines_FullDuplex ((u16)0x0000)
#define SPI_Direction_2Lines_RxOnly     ((u16)0x0400)
#define SPI_Direction_1Line_Rx          ((u16)0x8000)
#define SPI_Direction_1Line_Tx          ((u16)0xC000)

#define SPI_Mode_Master                 ((u16)0x0104)
#define SPI_Mode_Slave                  ((u16)0x0000)

#define SPI_DataSize_16b                ((u16)0x0800)
#define SPI_DataSize_8b                 ((u16)0x0000)


#define SPI_CPOL_Low                    ((u16)0x0000)
#define SPI_CPOL_High                   ((u16)0x0002)

#define SPI_CPHA_1Edge                  ((u16)0x0000)
#define SPI_CPHA_2Edge                  ((u16)0x0001)

#define SPI_NSS_Soft                    ((u16)0x0200)
#define SPI_NSS_Hard                    ((u16)0x0000)

#define SPI_BaudRatePrescaler_2         ((u16)0x0000)
#define SPI_BaudRatePrescaler_4         ((u16)0x0008)
#define SPI_BaudRatePrescaler_8         ((u16)0x0010)
#define SPI_BaudRatePrescaler_16        ((u16)0x0018)
#define SPI_BaudRatePrescaler_32        ((u16)0x0020)
#define SPI_BaudRatePrescaler_64        ((u16)0x0028)
#define SPI_BaudRatePrescaler_128       ((u16)0x0030)
#define SPI_BaudRatePrescaler_256       ((u16)0x0038)

#define SPI_FirstBit_MSB                ((u16)0x0000)
#define SPI_FirstBit_LSB                ((u16)0x0080)

#define SPI_CRC_Tx                      ((uint8_t)0x00)
#define SPI_CRC_Rx                      ((uint8_t)0x01)

#define SPI_Direction_Rx                ((u16)0xBFFF)
#define SPI_Direction_Tx                ((u16)0x4000)

#define SPI_I2S_IT_TXE                  ((uint8_t)0x71)
#define SPI_I2S_IT_RXNE                 ((uint8_t)0x60)
#define SPI_I2S_IT_ERR                  ((uint8_t)0x50)

#define SPI_I2S_IT_OVR                  ((uint8_t)0x56)
#define SPI_IT_MODF                     ((uint8_t)0x55)
#define SPI_IT_CRCERR                   ((uint8_t)0x54)

#define SPI_I2S_FLAG_RXNE               ((u16)0x0001)
#define SPI_I2S_FLAG_TXE                ((u16)0x0002)
#define SPI_FLAG_CRCERR                 ((u16)0x0010)
#define SPI_FLAG_MODF                   ((u16)0x0020)
#define SPI_I2S_FLAG_OVR                ((u16)0x0040)
#define SPI_I2S_FLAG_BSY                ((u16)0x0080)



/*******************************************************************************************************/


/*
typedef struct SPI
{
	u32 CR1;
	u32 CR2;
	u32 SR;
	u32 DR ;
	u32 CRCPR;
	u32 RXCRCR;
	u32 TXCRCR;
	u32 I2SCFGR;
	u32 I2SPR;

}SPI_t;

extern  volatile SPI_t *  const    SPI_1  ;
extern  volatile SPI_t *  const    SPI_2  ;
extern  volatile SPI_t *  const    SPI_3  ;

*/


void SPI_Init(void); //SPI_t* SPIx

u8  SPI_Send(u8 data);//SPI_t* SPIx  ,


//u8  SPI_Receive(SPI_t* SPIx , u8* data);




#endif
