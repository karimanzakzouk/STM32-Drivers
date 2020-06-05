/*
 * LED_cfg.c
 *
 *  Created on: Mar 23, 2020
 *      Author: kariman
 */

#include"GPIO.h"
#include"LED_cfg.h"


/*   CONFIGERATION OF EACH LED :                                                 *
 *                                                                               *
 *   {  LED_PIN, LED_PORT ,LED_MODE , LED_SPEED, LED_ON , LED_OFF    }           *
 *                                                                               */


const GPIO_InitTypeDef  LEDS[LEDS_NUM] = {

		{LED1_PIN, LED1_PORT ,LED1_MODE , LED1_SPEED, LED1_ON , LED1_OFF},
		{LED2_PIN, LED2_PORT ,LED2_MODE , LED2_SPEED, LED2_ON , LED2_OFF},

};
