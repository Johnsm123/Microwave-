/*
 * File:   main.c
 */

#include <xc.h>
#include "clcd.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

static void init_config(void) 
{
    init_clcd(); //port 
}

void main(void) 
{
    init_config();

    while (1) 
    {
        clcd_putch('A', LINE1(5));
        clcd_print("hello", LINE2(0));
        clcd_print("hi", LINE3(0));
        clcd_print("how r u ", LINE4(0));
    }
}
