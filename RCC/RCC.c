#include "STD_TYPES.h"
#include "MACROS.h"
#include "RCC.h"

/************************************REGISTRES************************************/

typedef struct
{
   u32  RCC_CR ;
   u32  RCC_CFGR  ;
   u32  RCC_CIR    ;
   u32  RCC_APB2RSTR;
   u32  RCC_APB1RSTR;
   u32  RCC_AHBENR  ;
   u32  RCC_APB2ENR ;
   u32  RCC_APB1ENR ;
   u32  RCC_BDCR    ;
   u32  RCC_CSR     ;

}RCC_REGISTERS;


volatile RCC_REGISTERS*  const RCC  = (RCC_REGISTERS*)0x40021000  ;


/******************************** RCC_CFGR_REG_CLEAR MASKS ************************************/

#define   	SW_CLR_MASK           ((u32)0xfffffffc)

#define   	HPRE_CLR_MASK         ((u32)0xffffff0f)

#define   	PPRE1_CLR_MASK        ((u32)0xfffff8ff)

#define   	PPRE2_CLR_MASK        ((u32)0xffffc7ff)

#define   	ADCPRE_CLR_MASK       ((u32)0xffff3fff)

#define   	MCO_CLR_MASK          ((u32)0xf8ffffff)

#define   	PLLMUL_CLR_MASK       ((u32)0xffc3ffff)



/*********************************FUNCTIONS***********************************************/

void  select_clock_state(u32 clock, u8 state)
{
      switch(state)
      {
        case ON:
             RCC-> RCC_CR |= clock;
             break;

        case OFF:
             RCC-> RCC_CR &=~ clock ;
             break;
      }

}

/****************************************************************************************/
u8 switch_clock(u32 clock)
{
    u8 returnType = NOK;
    u32 local ;

    local  = RCC->RCC_CFGR;
    local &= SW_CLR_MASK;
    local |= clock;
    RCC->RCC_CFGR = local;

         /* check status */
         switch(clock)
         {
           case SW_HSI_MASK:
               if( (RCC->RCC_CFGR & SWS_HSI_MASK) == SWS_HSI_MASK )
                  returnType = OK ;
               else
                 returnType = NOK ;
               break;

           case SW_HSE_MASK:
               if( (RCC->RCC_CFGR & SWS_HSE_MASK) == SWS_HSE_MASK)
                  returnType = OK ;
               else
                  returnType = NOK ;
               break;

           case SW_PLL_MASK:
               if( (RCC->RCC_CFGR & SWS_PLL_MASK) ==SWS_PLL_MASK )
                  returnType = OK ;
               else
                  returnType = NOK ;
               break;
         }

     return returnType;
}

/****************************************************************************************/

void Config_MCO(u32 MCO_clock)
{
   u32 local;
   local =  RCC->RCC_CFGR;
   local &= MCO_CLR_MASK;
   local |= MCO_clock;
   RCC-> RCC_CFGR  = local;

}

/****************************************************************************************/

void config_PLL(u32 pllScr, u32 pllXtpre , u32 pllMull)//only when  PLL is disabled.
{
      u32 local;
      local = RCC-> RCC_CFGR;

      switch(pllScr)
      {
        case PLLSRC_HSE_MASK:
           local |= PLLSRC_HSE_MASK ;
           break;
        case PLLSRC_HSI_MASK:
           local |= PLLSRC_HSI_MASK ;
           break;
      }

      switch(pllXtpre)
      {
        case PLLXTPRE_HSE_DIV2_MASK:
           local |= PLLXTPRE_HSE_DIV2_MASK ;
           break;
        case PLLXTPRE_HSE_DIV1_MASK:
           local |= PLLXTPRE_HSE_DIV1_MASK ;
           break;
      }

      local &= PLLMUL_CLR_MASK;
      local |= pllMull ;
      RCC-> RCC_CFGR = local;

}

/****************************************************************************************/

void select_AHP_prescaler(u32 prescaler)
{
   RCC-> RCC_CFGR &=  HPRE_CLR_MASK ;
   RCC-> RCC_CFGR |=  prescaler ;

}

/****************************************************************************************/

void select_APB1_prescaler(u32 prescaler)
{
  RCC-> RCC_CFGR &=  PPRE1_CLR_MASK;
  RCC-> RCC_CFGR |=  prescaler ;

}

/****************************************************************************************/

void select_APB2_prescaler(u32 prescaler)
{
  RCC-> RCC_CFGR &=  PPRE2_CLR_MASK;
  RCC-> RCC_CFGR |=  prescaler ;

}

/****************************************************************************************/

void Enable_peripheralClock(u8 bus ,u32 peripheral )
{
        switch(bus)
        {
          case AHB:
                      RCC->RCC_AHBENR  |= peripheral;
                      break;
          case APB1:
                      RCC->RCC_APB1ENR |= peripheral;
                      break;
          case APB2:
                      RCC->RCC_APB2ENR |= peripheral;
                      break;
        }
}

/****************************************************************************************/

void Disable_peripheralClock(u8 bus ,u32 peripheral )
{
    switch(bus)
    {
      case AHB:
                  RCC->RCC_AHBENR   &= ~peripheral;
                  break;
      case APB1:
                  RCC->RCC_APB1ENR  &= ~peripheral;
                  break;
      case APB2:
                  RCC->RCC_APB2ENR  &= ~peripheral;
                  break;
    }
}

