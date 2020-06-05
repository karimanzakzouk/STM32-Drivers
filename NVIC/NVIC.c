#include "STD_TYPES.h"
#include "NVIC_config.h"
#include "NVIC.h"


/************************************REGISTRES************************************/

#define NVIC_SETENA                        ((volatile u32*)( 0xE000E100 ) )
#define NVIC_CLRENA                        ((volatile u32*)( 0xE000E180 ) )

#define NVIC_SETPEND                       ((volatile u32*)( 0xE000E200 ) )
#define NVIC_CLRPEND                       ((volatile u32*)( 0xE000E280 ) )

#define NVIC_ACTIVE                        ((volatile u32*)( 0xE000E300 ) )

#define NVIC_PRI                           ((volatile u8*) ( 0xE000E400 ) )

#define	NVIC_SHCSR			                   *((volatile u32*)0xE000ED24)
#define	NVIC_STIR				                   *((volatile u32*)0xE000EF00)
                                       
#define SCB_AIRCR				                   *((volatile u32*)0xE000ED0C)


#define NVIC_BUS_FAULT_ENABLE					    	0x00020000
#define NVIC_BUS_FAULT_DISABLE				    	0xFFFDFFFF
                                          
#define NVIC_MEMORY_FAULT_ENABLE			    	0x00010000
#define NVIC_MEMORY_FAULT_DISABLE			    	0xFFFEFFFF
                                          
#define NVIC_USAGE_FAULT_ENABLE				    	0x00040000
#define NVIC_USAGE_FAULT_DISABLE			    	0xFFFBFFFF

/*********************************FUNCTIONS***********************************************/

void NVIC_voidEnableExternalInt(u8 InterruptNo )
{
   u8 offset , shift;
   offset  =  (InterruptNo / 32 )  ;//* 4
   shift   = (InterruptNo % 32)  ;
   NVIC_SETENA [offset] |= ( 1 << shift )  ;
}

void NVIC_voidDisableExternalInt(u8 InterruptNo )
{
	   u8 offset , shift;
	   offset  =  (InterruptNo / 32 )  ;
	   shift   = (InterruptNo % 32)  ;
	   NVIC_CLRENA [offset]  |= ( 1 << shift )  ;
}

void NVIC_voidSetPendingFlag(u8 InterruptNo )
{
	   u8 offset , shift;
	   offset  =  (InterruptNo / 32 )  ;
	   shift   = (InterruptNo % 32)  ;
	   NVIC_SETPEND [offset]   |= ( 1 << shift )  ;
}

void NVIC_voidClearPendingFlag(u8 InterruptNo )
{
	   u8 offset , shift;
	   offset  =  (InterruptNo / 32 )  ;
	   shift   = (InterruptNo % 32)  ;
	   NVIC_CLRPEND [offset]   |= ( 1 << shift )  ;
}

u8 NVIC_u8GetActiveFlag(u8 InterruptNo )
{
   u8 ActiveFlag;
   u8 offset , shift;
   offset  =  (InterruptNo / 32 )  ;
   shift   =  (InterruptNo % 32)  ;
   ActiveFlag  =  ( NVIC_ACTIVE [offset]   >>  shift  )    &   0x01 ;
  
  return ActiveFlag;
}
/***********************************************************************************/

void NVIC_voidInitPriority(void)
{
	SCB_AIRCR  =  0x05FA0000;
  SCB_AIRCR   |= (NVIC_GROUP_SUBGROUP_RATIO << 8);
}

void NVIC_voidSetPriority(u8 InterruptNo, u8 Group, u8 SubGroup)
{
  NVIC_PRI[InterruptNo] = 0x00 ;
  
  if(NVIC_GROUP_SUBGROUP_RATIO ==  NVIC_GROUPS_16_SUBGROUPS_0)
  {
     NVIC_PRI[InterruptNo] =  Group << (NVIC_GROUP_SUBGROUP_RATIO+1) ;
     
  }
  else if (NVIC_GROUP_SUBGROUP_RATIO ==  NVIC_GROUPS_0_SUBGROUPS_16)
  {
     NVIC_PRI[InterruptNo] =   SubGroup << 4 ;
     
  }
  else
  {
     NVIC_PRI[InterruptNo] = (( Group << (NVIC_GROUP_SUBGROUP_RATIO +1)) |  SubGroup << 4);
  
  }
  
}

/***********************************************************************************/

void NVIC_voidEnableAllExceptions(void)
{
	asm("MOV R5,#0");
	asm("MSR FAULTMASK, R5");
}

void NVIC_voidDisableAllExceptions(void)
{
	asm("MOV R5,#1");
	asm("MSR FAULTMASK, R5");
}

void NVIC_voidEnableAllExternalInterrupt(void)
{
  asm("MOV R5,#0");
	asm("MSR PRIMASK, R5");
}

void NVIC_voidDisableAllExternalInterrupt(void)
{
  asm("MOV R5,#1");
	asm("MSR PRIMASK, R5");
}

/***********************************************************************************/

void NVIC_voidEnableBusFaultException(void)
{
	 NVIC_SHCSR |= NVIC_BUS_FAULT_ENABLE;
}
void NVIC_voidDisableBusFaultException(void)
{
	 NVIC_SHCSR &= NVIC_BUS_FAULT_DISABLE;
}

void NVIC_voidEnableUsageFaultException(void)
{
	NVIC_SHCSR |= NVIC_USAGE_FAULT_ENABLE;
}
void NVIC_voidDisableUsageFaultException(void)
{
	NVIC_SHCSR &= NVIC_USAGE_FAULT_DISABLE;
}

void NVIC_voidEnableMemoryFaultException(void)
{
	NVIC_SHCSR |= NVIC_MEMORY_FAULT_ENABLE;
}
void NVIC_voidDisableMemoryFaultException(void)
{
	NVIC_SHCSR  &= NVIC_MEMORY_FAULT_DISABLE;
}


/***********************************************************************************/

