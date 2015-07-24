/** @file led_handler.c
 * @auther Jithin M Das
 *
 * @brief Handles LED indications
 * 
 */
 
#include <stdio.h>
#include "nrf_drv_gpiote.h"
#include "led_handler.h"
#include "nrf_delay.h"
#include "bsp.h"
#include "nordic_common.h"
#include "morse.h"
#include "app_timer.h"

void morse_led_indication(void * index_pointer);

/**@brief   Function for initializing LED.
 *
 * @details This function will configure GPIO for LED
 */
void led_init()
{
    ret_code_t err_code;
        
    err_code = nrf_drv_gpiote_init();
    APP_ERROR_CHECK(err_code);
    
    nrf_drv_gpiote_out_config_t out_config = GPIOTE_CONFIG_OUT_SIMPLE(true);    
    err_code = nrf_drv_gpiote_out_init(LED_ADV, &out_config);
    APP_ERROR_CHECK(err_code);
}

/**@brief   Function for Morse code indication.
 *
 * @details This function will indicate the Morse code through LED for the data from UART
 */
void morse_led_indication(void * index_pointer)
{
    printf("morse code = ");
    
    for(int j = 0; j<(morse_data.index); j++)
    {
        uint16_t deviser = 1000;
        
        for(int i = morse_data.data[j]; (i>0)&(deviser>0); )
        {
            uint16_t reminder = i % deviser;
            uint8_t result = i / deviser;           
            i = reminder;
            deviser /= 10;
            
            if(result == 1)
            {
                printf("%d", result);
                nrf_drv_gpiote_out_clear(LED_ADV);
                nrf_delay_ms(300);
                nrf_drv_gpiote_out_set(LED_ADV);
            }
            else if(result == 2)
            {
                printf("%d", result);
                nrf_drv_gpiote_out_clear(LED_ADV);
                nrf_delay_ms(1000);
                nrf_drv_gpiote_out_set(LED_ADV);
            }
            else
            {
                continue;
            }
            
            nrf_delay_ms(400);
        }
        printf(" ");
        nrf_delay_ms(1500);
    }
    printf("\n");
}
