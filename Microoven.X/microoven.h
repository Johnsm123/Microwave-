/* 
 * File:   microoven.h
 * Author: ASUS
 *
 * Created on 10 February, 2025, 6:09 PM
 */

#ifndef MICROOVEN_H
#define	MICROOVEN_H

void power_on_screen(void); // Renamed to avoid macro conflict
void clear_screen(void);
void display_menu_screen(void);
void set_time(unsigned char key, unsigned char reset_flag);
void set_temp(unsigned char key, unsigned char reset_flag);
void heat_food(void);
void time_display(void);
#endif	/* MICROOVEN_H */
