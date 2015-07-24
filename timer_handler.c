#include "timer_handler.h"
#include "app_timer.h"
#include "app_timer_appsh.h"
#include "btn_led_handler.h"
#include "morse.h"

void timer_init()
{
    uint32_t err_code;
    
    NRF_CLOCK->TASKS_LFCLKSTART = 1;

	while (NRF_CLOCK->EVENTS_LFCLKSTARTED == 0){};
    
    APP_TIMER_APPSH_INIT(APP_TIMER_PRESCALER, APP_TIMER_MAX_TIMERS, APP_TIMER_OP_QUEUE_SIZE, true);
    
    err_code = app_timer_create(&morse_timer_id, APP_TIMER_MODE_SINGLE_SHOT, morse_led_indication);
    APP_ERROR_CHECK(err_code);
}
