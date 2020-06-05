#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#include "STD_TYPES.h"


/********************************Enums*************************************************/
#define    NOK      0
#define    OK       1

#define    OFF      0
#define    ON       1

/*********************************RCC_CR_REG**********************************************/

#define   HSION_MASK        ((u32)0x00000001)
#define   HSIDRY_MASK       ((u32)0x00000002)

/***********TRIM and CAL values***********************/
#define   HSITRIM_MASK      ((u32)0x000000F8)        /* Internal High Speed clock trimming */
#define   HSICAL_MASK       ((u32)0x0000FF00)        /* Internal High Speed clock Calibration */

#define   HSEON_MASK        ((u32)0x00010000)
#define   HSERDY_MASK       ((u32)0x00020000)
#define   HSEBYP_MASK       ((u32)0x00040000)
#define   CSSON_MASK        ((u32)0x00080000)

#define   PLLON_MASK        ((u32)0x01000000)
#define   PLLRDY_MASK       ((u32)0x02000000)

/******************************8**RCC_CFGR_REG******************************************/

#define   	SW_HSI_MASK     ((u32)0x00000000)
#define   	SW_HSE_MASK     ((u32)0X00000001)
#define   	SW_PLL_MASK     ((u32)0X00000002)

#define   	SWS_HSI_MASK    ((u32)0X00000000)
#define   	SWS_HSE_MASK    ((u32)0X00000004)
#define   	SWS_PLL_MASK    ((u32)0X00000008)

#define   	PLLSRC_HSE_MASK                  ((u32)0x00010000)
#define   	PLLSRC_HSI_MASK                  ((u32)0x00000000)

#define   	PLLXTPRE_HSE_DIV2_MASK           ((u32)0x00020000)
#define   	PLLXTPRE_HSE_DIV1_MASK           ((u32)0x00000000)

#define   	PLLMULX2_MASK       ((u32)0x00000000)
#define   	PLLMULX3_MASK       ((u32)0x00040000)
#define   	PLLMULX4_MASK       ((u32)0x00080000)
#define   	PLLMULX5_MASK       ((u32)0x000C0000)
#define   	PLLMULX6_MASK       ((u32)0x00100000)
#define   	PLLMULX7_MASK       ((u32)0x00140000)
#define   	PLLMULX8_MASK       ((u32)0x00180000)
#define   	PLLMULX9_MASK       ((u32)0X001C0000)
#define   	PLLMULX10_MASK      ((u32)0x00200000)
#define   	PLLMULX11_MASK      ((u32)0x00240000)
#define   	PLLMULX12_MASK      ((u32)0x00280000)
#define   	PLLMULX13_MASK      ((u32)0x002C0000)
#define   	PLLMULX14_MASK      ((u32)0x00300000)
#define   	PLLMULX15_MASK      ((u32)0x00340000)
#define   	PLLMULX16_MASK      ((u32)0x00380000)

#define   	HPRE_DIV1_MASK      ((u32)0x00000000)
#define   	HPRE_DIV2_MASK      ((u32)0x00000080)
#define   	HPRE_DIV4_MASK      ((u32)0x00000090)
#define   	HPRE_DIV8_MASK      ((u32)0x000000A0)
#define   	HPRE_DIV16_MASK     ((u32)0x000000B0)
#define   	HPRE_DIV64_MASK     ((u32)0x000000C0)
#define   	HPRE_DIV128_MASK    ((u32)0x000000D0)
#define   	HPRE_DIV256_MASK    ((u32)0x000000E0)
#define   	HPRE_DIV512_MASK    ((u32)0x000000F0)

#define   	PPRE1_DIV1_MASK     ((u32)0x00000000)
#define   	PPRE1_DIV2_MASK     ((u32)0x00000400)
#define   	PPRE1_DIV4_MASK     ((u32)0x00000500)
#define   	PPRE1_DIV8_MASK     ((u32)0x00000600)
#define   	PPRE1_DIV16_MASK    ((u32)0x00000700)

#define   	PPRE2_DIV1_MASK     ((u32)0x00000000)
#define   	PPRE2_DIV2_MASK     ((u32)0x00002000)
#define   	PPRE2_DIV4_MASK     ((u32)0x00002800)
#define   	PPRE2_DIV8_MASK     ((u32)0x00003000)
#define   	PPRE2_DIV16_MASK    ((u32)0x00003800)

#define   	ADCPRE_DIV2_MASK    ((u32)0x00000000)
#define   	ADCPRE_DIV4_MASK    ((u32)0x00004000)
#define   	ADCPRE_DIV6_MASK    ((u32)0x00008000)
#define   	ADCPRE_DIV8_MASK    ((u32)0x0000C000)

#define   	USBPRE_MASK         ((u32)0x00400000)  // PLL clock is not divided

#define   	MCO_NOCLK_MASK      ((u32)0x00000000)
#define   	MCO_SYSCLK_MASK     ((u32)0x04000000)
#define   	MCO_HSI_MASK        ((u32)0x05000000)
#define   	MCO_HSE_MASK        ((u32)0x06000000)
#define   	MCO_PLL_MASK        ((u32)0x07000000)

/****************************RCC_AHBENR_REG*****************************************/

#define   	DMA1EN_AHBENR_MASK         ((u32)0x00000001)
#define   	DMA2EN_AHBENR_MASK         ((u32)0x00000002)
#define   	SRAMEN_AHBENR_MASK         ((u32)0x00000004)
#define   	FLITFEN_AHBENR_MASK        ((u32)0x00000010)
#define     CRCEN_AHBENR_MASK          ((u32)0x00000040)
#define     FSMCEN_AHBENR_MASK         ((u32)0x00000100)
#define     SDIOEN_AHBENR_MASK         ((u32)0x00000400)

/****************************RCC_APB1ENR_REG************************************/

#define    	TIM2EN_APB1ENR_MASK         ((u32)0x00000001)
#define    	TIM3EN_APB1ENR_MASK         ((u32)0x00000002)
#define    	TIM4EN_APB1ENR_MASK         ((u32)0x00000004)
#define    	TIM5EN_APB1ENR_MASK         ((u32)0x00000008)
#define    	TIM6EN_APB1ENR_MASK         ((u32)0x00000010)
#define    	TIM7EN_APB1ENR_MASK         ((u32)0x00000020)
#define    	TIM12EN_APB1ENR_MASK        ((u32)0x00000040)
#define    	TIM13EN_APB1ENR_MASK        ((u32)0x00000080)
#define    	TIM14EN_APB1ENR_MASK        ((u32)0x00000100)
#define    	WWDGEN_APB1ENR_MASK         ((u32)0x00000800)
#define    	SPI2EN_APB1ENR_MASK         ((u32)0x00004000)
#define    	SPI3EN_APB1ENR_MASK         ((u32)0x00008000)
#define    	USART2EN_APB1ENR_MASK       ((u32)0x00020000)
#define    	USART3EN_APB1ENR_MASK       ((u32)0x00040000)
#define    	USART4EN_APB1ENR_MASK       ((u32)0x00080000)
#define    	USART5EN_APB1ENR_MASK       ((u32)0x00100000)
#define    	I2C1EN_APB1ENR_MASK         ((u32)0x00200000)
#define    	I2C2EN_APB1ENR_MASK         ((u32)0x00400000)
#define    	USBEN_APB1ENR_MASK          ((u32)0x00800000)
#define    	CANEN_APB1ENR_MASK          ((u32)0x02000000)
#define    	BKPEN_APB1ENR_MASK          ((u32)0x08000000)
#define    	PWREN_APB1ENR_MASK          ((u32)0x10000000)
#define    	DACEN_APB1ENR_MASK          ((u32)0x20000000)

/*********************************RCC_APB2ENR_REG*****************************************/

#define    	AFIOEN_APB2ENR_MASK         ((u32)0x00000001)
#define    	IOPAEN_APB2ENR_MASK         ((u32)0x00000004)
#define    	IOPBEN_APB2ENR_MASK         ((u32)0x00000008)
#define    	IOPCEN_APB2ENR_MASK         ((u32)0x00000010)
#define    	IOPDEN_APB2ENR_MASK         ((u32)0x00000020)
#define    	IOPEEN_APB2ENR_MASK         ((u32)0x00000040)
#define    	IOPFEN_APB2ENR_MASK         ((u32)0x00000080)
#define    	IOPGEN_APB2ENR_MASK         ((u32)0x00000100)
#define     ADC1EN_APB2ENR_MASK         ((u32)0x00000200)
#define    	ADC2EN_APB2ENR_MASK         ((u32)0x00000400)
#define    	TIM1EN_APB2ENR_MASK         ((u32)0x00000800)
#define     SPI1EN_APB2ENR_MASK         ((u32)0x00001000)
#define    	TIM8EN_APB2ENR_MASK         ((u32)0x00002000)
#define    	USART1EN_APB2ENR_MASK       ((u32)0x00004000)
#define    	ADC3EN_APB2ENR_MASK         ((u32)0x00008000)
#define    	TIM9EN_APB2ENR_MASK         ((u32)0x00080000)
#define    	TIM10EN_APB2ENR_MASK        ((u32)0x00100000)
#define    	TIM11EN_APB2ENR_MASK        ((u32)0x00200000)

/****************************************************************************************/

#define    	AHB                  0
#define    	APB1                 1
#define    	APB2                 2

/***********************PROTOTYPES*****************************************************/
/*
-choose one as input clock :
----------------------------
HSION_MASK
HSEON_MASK
PLLON_MASK

-choose  input state :  [  ON or OFF  ]
*/
extern void select_clock_state(u32 clock , u8 state);

/****************************************************************************************/
/*
-choose one as input clock :
----------------------------
SW_HSI_MASK
SW_HSE_MASK
SW_PLL_MASK

-choose input state : [ ON or OFF ]
*/
extern  u8  switch_clock(u32 clock );

/****************************************************************************************/
/*
-choose one as input clock :
----------------------------
MCO_NOCLK_MASK
MCO_SYSCLK_MASK
MCO_HSI_MASK
MCO_HSE_MASK
MCO_PLL_MASK
*/
extern void  Config_MCO(u32 MCO_clock);

/****************************************************************************************/

/*
-FOR pllScr choose:
-------------------
PLLSRC_HSE_MASK  (HSE oscillator clock selected as PLL input clock)
PLLSRC_HSI_MASK  (HSI oscillator clock / 2 selected as PLL input clock)

-FOR pllXtpre choose:
---------------------
PLLXTPRE_HSE_DIV2_MASK  (HSE clock divided by 2)
PLLXTPRE_HSE_DIV1_MASK  (HSE clock not divided)

-choose one as input pllMull :
-----------------------------------
PLLMULX2_MASK
PLLMULX3_MASK
PLLMULX4_MASK
PLLMULX5_MASK
PLLMULX6_MASK
PLLMULX7_MASK
PLLMULX8_MASK
PLLMULX9_MASK
PLLMULX10_MASK
PLLMULX11_MASK
PLLMULX12_MASK
PLLMULX13_MASK
PLLMULX14_MASK
PLLMULX15_MASK
PLLMULX16_MASK

*/
extern void config_PLL(u32 pllScr, u32 pllXtpre , u32 pllMull);

/****************************************************************************************/
/*
-choose on as input AHP  prescaler :
-----------------------------------
HPRE_DIV1_MASK
HPRE_DIV2_MASK
HPRE_DIV4_MASK
HPRE_DIV8_MASK
HPRE_DIV16_MASK
HPRE_DIV64_MASK
HPRE_DIV128_MASK
HPRE_DIV256_MASK
HPRE_DIV512_MASK
*/
extern void select_AHP_prescaler(u32 prescaler);

/****************************************************************************************/
/*
-choose on as input APB1 prescaler :
-----------------------------------
PPRE1_DIV1_MASK
PPRE1_DIV2_MASK
PPRE1_DIV4_MASK
PPRE1_DIV8_MASK
PPRE1_DIV16_MASK
*/
extern void select_APB1_prescaler(u32 prescaler);

/****************************************************************************************/

/*
-choose on as input APB2 prescaler :
-----------------------------------
PPRE2_DIV1_MASK
PPRE2_DIV2_MASK
PPRE2_DIV4_MASK
PPRE2_DIV8_MASK
PPRE2_DIV16_MASK
*/
extern void select_APB2_prescaler(u32 prescaler);

/****************************************************************************************/

/*
-choose input state : [ ON or OFF ]
-----------------------------------------------------------------------------------
-choose  input  BUS: [ AHP , APB1  , APB2 ]
-----------------------------------------------------------------------------------------------
-choose  input  peripheral :                                                                    |
-----------------------------------------------------------------------------------------------|
AHB BUS:              |            APB1 BUS :             |         APB2 BUS :                 |
----------------------|-----------------------------------|------------------------------------|
DMA1EN_AHBENR_MASK    |     TIM2EN_APB1ENR_MASK           |       	AFIOEN_APB2ENR_MASK        |
DMA2EN_AHBENR_MASK    |     TIM3EN_APB1ENR_MASK           |       	IOPAEN_APB2ENR_MASK        |
SRAMEN_AHBENR_MASK    |     TIM4EN_APB1ENR_MASK           |       	IOPBEN_APB2ENR_MASK        |
FLITFEN_AHBENR_MASK   |     TIM5EN_APB1ENR_MASK           |       	IOPCEN_APB2ENR_MASK        |
CRCEN_AHBENR_MASK     |     TIM6EN_APB1ENR_MASK           |       	IOPDEN_APB2ENR_MASK        |
FSMCEN_AHBENR_MASK    |     TIM7EN_APB1ENR_MASK           |       	IOPEEN_APB2ENR_MASK        |
SDIOEN_AHBENR_MASK    |     TIM12EN_APB1ENR_MASK          |       	IOPFEN_APB2ENR_MASK        |
                      |     TIM13EN_APB1ENR_MASK          |       	IOPGEN_APB2ENR_MASK        |
                      |     TIM14EN_APB1ENR_MASK          |         ADC1EN_APB2ENR_MASK        |
                      |     WWDGEN_APB1ENR_MASK           |       	ADC2EN_APB2ENR_MASK        |
                      |     SPI2EN_APB1ENR_MASK           |       	TIM1EN_APB2ENR_MASK        |
                      |     SPI3EN_APB1ENR_MASK           |         SPI1EN_APB2ENR_MASK        |
                      |     USART2EN_APB1ENR_MASK         |       	TIM8EN_APB2ENR_MASK        |
                      |     USART3EN_APB1ENR_MASK         |       	USART1EN_APB2ENR_MASK      |
                      |     USART4EN_APB1ENR_MASK         |       	ADC3EN_APB2ENR_MASK        |
                      |     USART5EN_APB1ENR_MASK         |       	TIM9EN_APB2ENR_MASK        |
                      |     I2C1EN_APB1ENR_MASK           |       	TIM10EN_APB2ENR_MASK       |
                      |     I2C2EN_APB1ENR_MASK           |       	TIM11EN_APB2ENR_MASK       |
                      |     USBEN_APB1ENR_MASK            |                                    |
                      |     CANEN_APB1ENR_MASK            |                                    |
                      |     BKPEN_APB1ENR_MASK            |                                    |
                      |     PWREN_APB1ENR_MASK            |                                    |
                      |     DACEN_APB1ENR_MASK            |                                    |
------------------------------------------------------------------------------------------------
*/
extern void Enable_peripheralClock(u8 bus ,u32 prephiral );
extern void Disable_peripheralClock(u8 bus ,u32 prephiral );





#endif
