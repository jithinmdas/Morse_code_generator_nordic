/** @file timer_handler.h
 * @auther Jithin M Das
 *
 * @brief Hex file of timer_handler.c
 * 
 */

#ifndef TIMER_HANDLER_H
#define TIMER_HANDLER_H

#include "bsp.h"
#include "app_timer.h"

#define APP_TIMER_PRESCALER             0                                           /**< Value of the RTC1 PRESCALER register. */
#define APP_TIMER_MAX_TIMERS            (2 + BSP_APP_TIMERS_NUMBER)                 /**< Maximum number of simultaneously created timers. */
#define APP_TIMER_OP_QUEUE_SIZE         4 

static app_timer_id_t  morse_timer_id;

/**@brief   Function for initializing timers.
 *
 * @details This function will initialize timer needed for LED indication
 */
void timer_init(void);

#endif // TIMER_HANDLER_H
