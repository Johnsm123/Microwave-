/*
 * File:   main.c
 * Author: ASUS
 *
 * Created on 24 January, 2025, 8:27 PM
 */

#include <xc.h>
#pragma config WDTE = OFF
#include "main.h"


void init_config(void) 
{
  //config RB3 as input
    TRISB3 = 1;
    
  // cofig RD0 as output 
    TRISD0 = 0;
    
}

unsigned char once = 1;
void main(void) 
{
    init_config();
 /* while (1) 
    {
        // switch is pressed toggle LED
        //checking if switch is pressed
        if (SWITCH1== 0)
        {
            LED1 =  !LED1;
            for(unsigned int wait = 50000; wait--;);
        }  */
    
         //edge trigerring
    for(unsigned int wait = 500; wait--;);
    
    if(RB3 == 0 && once == 1)
    {
        once = 0;
        RD0 = !RD0;
    }
    
    //if switch is released
    if(RB3 == 1)
    {
        once = 1;
    }
    
}

