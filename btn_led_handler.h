#include <stdint.h>
#include "bsp.h"
#include "app_timer.h"

#ifdef BSP_LED_0
    #define LED_ADV BSP_LED_0
    #define LED_ADV_MASK BSP_LED_0_MASK
#endif
#ifndef LED_ADV
    #error "Please indicate output pin"
#endif

#ifdef BSP_LED_1
    #define LED_MORSE BSP_LED_1
    #define LED_MORSE_MASK BSP_LED_1_MASK
#endif
#ifndef LED_MORSE
    #error "Please indicate output pin"
#endif

void btn_led_init(uint32_t prescaler);
void morse_led_indication(void * p_variable);
