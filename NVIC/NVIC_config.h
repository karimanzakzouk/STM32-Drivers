#ifndef _NVIC_CONFIG_H
#define _NVIC_CONFIG_H

/*
NVIC_GROUP_SUBGROUP_RATIO  can be one of these options:
-------------------------------------------------------
      NVIC_GROUPS_16_SUBGROUPS_0
      NVIC_GROUPS_8_SUBGROUPS_2 
      NVIC_GROUPS_4_SUBGROUPS_4 
      NVIC_GROUPS_2_SUBGROUPS_8 
      NVIC_GROUPS_0_SUBGROUPS_16
*/
#define		  NVIC_GROUP_SUBGROUP_RATIO			  NVIC_GROUPS_0_SUBGROUPS_16

/************************************* for STM32F10 ***************************************************/

#define			NVIC_MAX_NUMBER_OF_Interrupts	  (u8)60  

#define 		NVIC_WWDG												NVIC_INT0 
#define 		NVIC_PVD												NVIC_INT1 
#define 		NVIC_TAMPER											NVIC_INT2 
#define 		NVIC_RTC												NVIC_INT3 
#define 		NVIC_FLASH											NVIC_INT4 
#define 		NVIC_RCC												NVIC_INT5 
#define 		NVIC_EXTI0											NVIC_INT6 
#define 		NVIC_EXTI1											NVIC_INT7 
#define 		NVIC_EXTI2											NVIC_INT8 
#define 		NVIC_EXTI3											NVIC_INT9 
#define 		NVIC_EXTI4											NVIC_INT10
#define 		NVIC_DMA1_Channel1							NVIC_INT11
#define 		NVIC_DMA1_Channel2							NVIC_INT12
#define 		NVIC_DMA1_Channel3							NVIC_INT13
#define 		NVIC_DMA1_Channel4							NVIC_INT14
#define 		NVIC_DMA1_Channel5							NVIC_INT15
#define 		NVIC_DMA1_Channel6							NVIC_INT16
#define 		NVIC_DMA1_Channel7							NVIC_INT17
#define 		NVIC_ADC1_2											NVIC_INT18
#define 		NVIC_USB_HP_CAN_TX							NVIC_INT19
#define 		NVIC_USB_LP_CAN_RX0							NVIC_INT20
#define 		NVIC_CAN_RX1										NVIC_INT21
#define 		NVIC_CAN_SCE										NVIC_INT22
#define 		NVIC_EXTI9_5										NVIC_INT23
#define 		NVIC_TIM1_BRK										NVIC_INT24
#define 		NVIC_TIM1_UP										NVIC_INT25
#define 		NVIC_TIM1_TRG_COM								NVIC_INT26
#define 		NVIC_TIM1_CC										NVIC_INT27
#define 		NVIC_TIM2												NVIC_INT28
#define 		NVIC_TIM3												NVIC_INT29
#define 		NVIC_TIM4												NVIC_INT30
#define 		NVIC_I2C1_EV										NVIC_INT31
#define 		NVIC_I2C1_ER										NVIC_INT32
#define 		NVIC_I2C2_EV										NVIC_INT33
#define 		NVIC_I2C2_ER										NVIC_INT34
#define 		NVIC_SPI1												NVIC_INT35
#define 		NVIC_SPI2												NVIC_INT36
#define 		NVIC_USART1											NVIC_INT37
#define 		NVIC_USART2											NVIC_INT38
#define 		NVIC_USART3											NVIC_INT39
#define 		NVIC_EXTI15_10									NVIC_INT40
#define 		NVIC_RTCAlarm										NVIC_INT41
#define 		NVIC_USBWakeup									NVIC_INT42
#define 		NVIC_TIM8_BRK										NVIC_INT43
#define 		NVIC_TIM8_UP										NVIC_INT44
#define 		NVIC_TIM8_TRG_COM								NVIC_INT45
#define 		NVIC_TIM8_CC										NVIC_INT46
#define 		NVIC_ADC3												NVIC_INT47
#define 		NVIC_FSMC												NVIC_INT48
#define 		NVIC_SDIO												NVIC_INT49
#define 		NVIC_TIM5												NVIC_INT50
#define 		NVIC_SPI3												NVIC_INT51
#define 		NVIC_UART4											NVIC_INT52
#define 		NVIC_UART5											NVIC_INT53
#define 		NVIC_TIM6												NVIC_INT54
#define 		NVIC_TIM7												NVIC_INT55
#define 		NVIC_DMA2_Channel1							NVIC_INT56
#define 		NVIC_DMA2_Channel2							NVIC_INT57
#define 		NVIC_DMA2_Channel3							NVIC_INT58
#define 		NVIC_DMA2_Channel4_5						NVIC_INT59


#endif
