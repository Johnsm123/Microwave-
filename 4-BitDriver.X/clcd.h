/* 
 * File:   clcd.h
 */

#ifndef CLCD_H
#define	CLCD_H

#include <xc.h>
#include <stdint.h>   // For standard integer types
#include <stdbool.h>  // For boolean types

#define _XTAL_FREQ                  20000000  // 20 MHz Crystal Frequency

// Define Data Direction Registers (DDR)
#define CLCD_DATA_PORT_DDR          TRISD       // Data port direction (PORTD)
#define CLCD_RS_DDR                 TRISEbits.TRISE2  // Control pin RE2
#define CLCD_EN_DDR                 TRISEbits.TRISE1  // Control pin RE1

// Define Output Port Control Pins
#define CLCD_DATA_PORT              PORTD       // Data port (PORTD)
#define CLCD_RS                     PORTEbits.RE2  // Control pin RE2
#define CLCD_EN                     PORTEbits.RE1  // Control pin RE1

// Define Command and Data Modes
#define INST_MODE                   0  // Instruction mode
#define DATA_MODE                   1  // Data mode

#define HI                          1
#define LOW                         0

// LCD Address Macros
#define LINE1(x)                    (0x80 + (x))  // Address for Line 1
#define LINE2(x)                    (0xC0 + (x))  // Address for Line 2
#define LINE3(x)                    (0x90 + (x))  // Address for Line 3
#define LINE4(x)                    (0xD0 + (x))  // Address for Line 4

// LCD Commands
#define EIGHT_BIT_MODE              0x33
#define FOUR_BIT_MODE               0x02
#define TWO_LINES_5x8_4_BIT_MODE    0x28
#define CLEAR_DISP_SCREEN           0x01
#define DISP_ON_AND_CURSOR_OFF      0x0C

// Function Declarations
void init_clcd(void);
void clcd_putch(const char data, unsigned char addr);
void clcd_print(const char *str, unsigned char addr);
void clcd_write(unsigned char byte, unsigned char mode);

#endif	/* CLCD_H */
