#include <stdio.h>
#include "nrf_drv_gpiote.h"
#include "btn_led_handler.h"
#include "nrf_delay.h"
#include "bsp.h"
#include "nordic_common.h"
#include "morse.h"

static bsp_indication_t m_stable_state;
static uint32_t m_prescaler;

void morse_led_indication(void * p_variable);
    
void btn_led_init(uint32_t prescaler)
{
    ret_code_t err_code;
    
    m_prescaler = prescaler;
    
    err_code = nrf_drv_gpiote_init();
    APP_ERROR_CHECK(err_code);
    
    nrf_drv_gpiote_out_config_t out_config = GPIOTE_CONFIG_OUT_SIMPLE(false);    
    err_code = nrf_drv_gpiote_out_init(LED_ADV, &out_config);
    APP_ERROR_CHECK(err_code);
}

void morse_led_indication(void * p_variable)
{
    printf("im here");
    for(int j = 0; j<sizeof(morse_data.data); j++)
    {
        for(int i = morse_data.data[j]; i>0; )
        {
            printf("%d\n", i);
            uint8_t reminder = i%10;
            
            if(reminder == 1)
            {
                printf("1\n");
            }
            else if(reminder == 2)
            {
                printf("2\n");
            }
        }
    }
}
