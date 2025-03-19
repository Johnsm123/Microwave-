/*
 * File:   main.c
 * Author: Lenovo
 *
 * Created on January 31, 2025, 7:57 PM
 */


#include <xc.h>
#include "timers.h"

#pragma config WDTE = OFF

void init_config(void) 
{
    //config LED PORT as output PORT
    TRISD = 0x00;
    
    //config timer2
    init_timer2();
    
    // enable global and peripheral int
    GIE = 1;
    PEIE = 1;

}

void main(void) 
{
    init_config();
    while (1) 
    {

    }

}
