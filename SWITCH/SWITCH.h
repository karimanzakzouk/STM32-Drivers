#include"STD_TYPES.h"
#include"GPIO_interface.h"


typedef struct
{
	u32    pin ;
	void*  port;
	u8     mode;

}SWITCH_InitTypeDef;



extern void HSWITCH_Init(u8 switchNum);

extern u8  HSWITCH_getSwitchState(u8 switchNum );

extern void DebounceTask(void);

