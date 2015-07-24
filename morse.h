/** @file morse.h
 * @auther Jithin M Das
 *
 * @brief Hex file of morse.c
 * 
 */
 
#ifndef MORSE_H
#define MORSE_H

#include <stdint.h>
#include "app_timer.h"

/**@brief Morse code for different alphabets. */
typedef enum
{
    A = 12,
    B =	2111,
    C =	2121,
    D =	211,
    E =	1,
    F =	1121,
    G =	221,
    H =	1111,
    I =	11,
    J =	1222,
    K =	212,
    L =	1211,
    M =	22,
    N = 21,
    O = 222,
    P = 1221,
    Q = 2212,
    R = 121,
    S = 111,
    T = 2,
    U = 112,
    V = 1112,
    W = 122,
    X = 2112,
    Y = 2122,
    Z = 2211,
    INVALID = 0
} morse_code_t;
extern morse_code_t morse_code;

/**@brief Data from UART. */
typedef struct
{
    uint16_t data[100];
    uint8_t index;
} morse_data_t;
extern morse_data_t morse_data;

/**@brief   Function for calculating morse code for the string.
 *
 * @details This function will receive a data array and converts it to morse code and triggers the indication
 * 
 * @param[in]   data    Character array of data from UART
 * @param[in]   index   Index of last character in the array
 */
void morse_generate(char * data, uint8_t index);

#endif // MORSE_H
