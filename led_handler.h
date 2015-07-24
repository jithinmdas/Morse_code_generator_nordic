/** @file led_handler.h
 * @auther Jithin M Das
 *
 * @brief Hex file of led_handler.c
 * 
 */

#ifndef LED_HANDLER_H
#define LED_HANDLER_H

#include <stdint.h>
#include "bsp.h"

#ifdef BSP_LED_0
    #define LED_ADV BSP_LED_0
    #define LED_ADV_MASK BSP_LED_0_MASK
#endif
#ifndef LED_ADV
    #error "Please indicate output pin"
#endif

/**@brief   Function for initializing LED.
 *
 * @details This function will configure GPIO for LED
 */
void led_init(void);

/**@brief   Function for Morse code indication.
 *
 * @details This function will indicate the Morse code through LED for the data from UART
 */
void morse_led_indication(void * p_variable);

#endif // LED_HANDLER_H
