#include <stdio.h>
#include <string.h>
#include "morse.h"
#include "btn_led_handler.h"
#include "nrf_drv_gpiote.h"
#include "nrf_delay.h"

morse_code_t morse_code = INVALID;
morse_data_t morse_data;
uint16_t get_char_morse(char data);

void morse_generate(char * data_array, uint32_t m_prescaler)
{
    for(int i=0 ; i<(strlen(data_array)-1) ; i++)
    {
        morse_data.data[i] = get_char_morse(data_array[i]);
        printf("%c = %d\n", data_array[i], morse_data.data[i]);
    }
    uint32_t err_code = app_timer_start(morse_timer_id, APP_TIMER_TICKS(25, m_prescaler) , &morse_data.data);
    printf("error = %d\n",err_code);
//    for(int i = morse_code; i>0; )
//    {
//        printf("%d\n", i);
//        uint8_t reminder = i%10;
//        
//        if(reminder == 1)
//        {
//            printf("1\n");
//        }
//        else if(reminder == 2)
//        {
//            printf("2\n");
//        }
//    }
}

void morse_init()
{
    app_timer_create(&morse_timer_id, APP_TIMER_MODE_SINGLE_SHOT, morse_led_indication);
}
uint16_t get_char_morse(char data)
{
    switch(data)
    {
        case 'a':
        case 'A':
            return A;
            
        case 'b':
        case 'B':
            return B;
            
        case 'c':
        case 'C':
            return C;
            
        case 'd':
        case 'D':
            return D;
            
        case 'e':
        case 'E':
            return E;
            
        case 'f':
        case 'F':
            return F;
            
        case 'g':
        case 'G':
            return G;
            
        case 'h':
        case 'H':
            return H;
            
        case 'i':
        case 'I':
            return I;
            
        case 'j':
        case 'J':
            return J;
            
        case 'k':
        case 'K':
            return K;
            
        case 'l':
        case 'L':
            return L;
            
        case 'm':
        case 'M':
            return M;
            
        case 'n':
        case 'N':
            return N;
            
        case 'o':
        case 'O':
            return O;
            
        case 'p':
        case 'P':
            return P;
            
        case 'q':
        case 'Q':
            return Q;
            
        case 'r':
        case 'R':
            return R;
            
        case 's':
        case 'S':
            return S;
            
        case 't':
        case 'T':
            return T;
            
        case 'u':
        case 'U':
            return U;
            
        case 'v':
        case 'V':
            return V;
            
        case 'W':
        case 'w':
            return W;
            
        case 'x':
        case 'X':
            return X;
            
        case 'y':
        case 'Y':
            return Y;
            
        case 'z':
        case 'Z':
            return Z;
            
        default :
            return INVALID;
            
    }
}
