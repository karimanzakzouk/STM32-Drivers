
#ifndef LED_CFG_H_
#define LED_CFG_H_


/* NO OF LEDS  */
#define   LEDS_NUM     2


/* ADD  LED CONFIGURATION HERE  :  NUMBER , PIN , PORT , MODE , SPEED , ON VALUE  , OFF VALUE **********************/

/*******NO OF LED SHOULD BE STARTED FROM ZERO **********************/

#define   LED1         0
#define   LED1_PIN     PIN_13
#define   LED1_PORT    PORTC
#define   LED1_MODE    GPIO_MODE_OUTPUT_PUSH_PULL
#define   LED1_SPEED   GPIO_SPEED_10_MHZ
#define   LED1_ON      BIT_RESET
#define   LED1_OFF     BIT_SET


#define   LED2         1
#define   LED2_PIN     PIN_1
#define   LED2_PORT    PORTB
#define   LED2_MODE    GPIO_MODE_OUTPUT_PUSH_PULL
#define   LED2_SPEED   GPIO_SPEED_10_MHZ
#define   LED2_ON      BIT_SET
#define   LED2_OFF     BIT_RESET







#endif /* LED_CFG_H_ */
