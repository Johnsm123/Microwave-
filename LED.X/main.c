/*
 * File:   main.c
 * Author: ASUS
 *
 * Created on 23 January, 2025, 7:49 PM
 */

#include <xc.h>
#pragma config WDTE = OFF

void init_config(void) 
{
    //cofig portb as output
    TRISB = 0x00;

}

void main(void) 
{
    init_config();
    while (1) 
    {
        PORTB = 0xFF;
        for(unsigned int wait = 50000; wait--;);
        PORTB = 0x00;
        for(unsigned int wait = 50000; wait--;);

    }

}

