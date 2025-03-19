#include <xc.h>
#include "clcd.h"

void clcd_write(unsigned char byte, unsigned char mode)
{
    CLCD_RS = mode;

    CLCD_DATA_PORT = byte & 0xF0;
    CLCD_EN = HI;
    __delay_us(100);
    CLCD_EN = LOW;

    CLCD_DATA_PORT = (byte & 0x0F) << 4;
    CLCD_EN = HI;
    __delay_us(100);
    CLCD_EN = LOW;
    
    __delay_us(4100); // 4.1ms
}

static void init_display_controller(void)
{
    /* Startup Time for the CLCD controller */
    __delay_ms(30);
    
    /* The CLCD Startup Sequence */
    clcd_write(EIGHT_BIT_MODE, INST_MODE); //0x33
    __delay_us(4100);
    clcd_write(EIGHT_BIT_MODE, INST_MODE);  //0x3
    __delay_us(100);
    clcd_write(EIGHT_BIT_MODE, INST_MODE); //0x3
    __delay_us(1); 
    
    clcd_write(FOUR_BIT_MODE, INST_MODE); //0x20
    __delay_us(100);
    clcd_write(TWO_LINES_5x8_4_BIT_MODE, INST_MODE); // 0x28
    __delay_us(100);
    clcd_write(CLEAR_DISP_SCREEN, INST_MODE);
    __delay_us(500);
    clcd_write(DISP_ON_AND_CURSOR_OFF, INST_MODE);
    __delay_us(100);
}

void init_clcd(void)
{
    /* Setting the CLCD Data Port as Output */
    CLCD_DATA_PORT_DDR = CLCD_DATA_PORT_DDR & 0x0F; //TRISD = TRISD & 0X0F
    
    /* Setting the RS and EN lines as Output */
    CLCD_RS_DDR = 0;  // TRISE2
    CLCD_EN_DDR = 0;  // TRISE1
    
    init_display_controller();
}

void clcd_putch(const char data, unsigned char addr)
{
    clcd_write(addr, INST_MODE); // 0x80 as instruction
    clcd_write(data, DATA_MODE); // A as data
}

void clcd_print(const char *str, unsigned char addr)
{
    clcd_write(addr, INST_MODE); // 0xc0
    
    while (*str != '\0')
    {
        clcd_write(*str, DATA_MODE); // h , e , l , l , o , \0
        str++;
    }
}
