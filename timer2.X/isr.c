#include <xc.h>

unsigned int count ;
__interrupt() isr( void )
{
    if(TMR2IF)
    {
        if( ++count == 20000) // 250 , 200ns 8 bit timer for 1 sec
        {
            count = 0;
            
            PORTD = ~PORTD;
        }
        
        TMR2IF = 0; // clear interrupt flag 
        
    }
    
    
}

