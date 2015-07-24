/** @file main.c
 * @auther Jithin M Das
 *
 * @brief Main file of Morse_Code_Generator
 * 
 */
 
#include <stdint.h>
#include <string.h>
#include "nordic_common.h"
#include "app_timer.h"
#include "app_uart.h"
#include "bsp.h"
#include "led_handler.h"
#include "morse.h"
#include "app_timer_appsh.h"
#include "app_scheduler.h"
#include "timer_handler.h"

#define UART_TX_BUF_SIZE                256                                         /**< UART TX buffer size. */
#define UART_RX_BUF_SIZE                256                                         /**< UART RX buffer size. */
#define SCHED_QUEUE_SIZE                10                                          /**< Maximum number of events in the scheduler queue. */

/**@brief   Function for handling app_uart events.
 *
 * @details This function will receive a single character from the app_uart module and append it to 
 *          a string. The string will be converted to Morse Code
 */
void uart_event_handle(app_uart_evt_t * p_event)
{
    static uint8_t data_array[100];
    static uint8_t index = 0;
        
    switch (p_event->evt_type)
    {
        case APP_UART_DATA_READY:
            UNUSED_VARIABLE(app_uart_get(&data_array[index]));
            if (data_array[index] == '\n')
            {
                printf("%s \n",data_array);
                printf("index = %d\n", index);
                morse_generate((char*)data_array, index);
            }
            index++;
            break;    
        case APP_UART_COMMUNICATION_ERROR:
            APP_ERROR_HANDLER(p_event->data.error_communication);
            break;

        case APP_UART_FIFO_ERROR:
            APP_ERROR_HANDLER(p_event->data.error_code);
            break;

        default:
            break;
    }
}

/**@brief  Function for initializing the UART module.
 */
static void uart_init(void)
{
    uint32_t                     err_code;
    const app_uart_comm_params_t comm_params =
    {
        RX_PIN_NUMBER,
        TX_PIN_NUMBER,
        RTS_PIN_NUMBER,
        CTS_PIN_NUMBER,
        APP_UART_FLOW_CONTROL_DISABLED,
        false,
        UART_BAUDRATE_BAUDRATE_Baud38400
    };

    APP_UART_FIFO_INIT( &comm_params,
                       UART_RX_BUF_SIZE,
                       UART_TX_BUF_SIZE,
                       uart_event_handle,
                       APP_IRQ_PRIORITY_LOW,
                       err_code);
    APP_ERROR_CHECK(err_code);
}

/**@brief Function for the Event Scheduler initialization.
 */
static void scheduler_init(void)
{
    APP_SCHED_INIT(APP_TIMER_SCHED_EVT_SIZE, SCHED_QUEUE_SIZE);
}

/**@brief Application main function.
 */
int main(void)
{
    // Initialize.
    uart_init();
    scheduler_init();
    timer_init();
    led_init();
    
    printf("Hi please enter the string to be converted to morse code.\nOnly alphabets supported\n");
    
    // Enter main loop.
    for (;;)
    {
        app_sched_execute();
    }
}


/** 
 * @}
 */
