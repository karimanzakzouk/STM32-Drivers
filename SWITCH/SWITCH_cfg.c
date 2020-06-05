
#include"GPIO_interface.h"
#include"SWITCH_int.h"
#include"SWITCH_cfg.h"



/*   CONFIGERATION OF EACH SWITCH :                                              *
 *                                                                               *
 *   {  SWITCH_PIN, SWITCH_PORT ,SWITCH_MODE }                                   *
 *                                                                               */

const SWITCH_InitTypeDef  SWITCHES[SWITCHES_NUM] =
{

		{SWITCH1_PIN, SWITCH1_PORT ,SWITCH1_MODE },
		{SWITCH2_PIN, SWITCH2_PORT ,SWITCH2_MODE },


};
