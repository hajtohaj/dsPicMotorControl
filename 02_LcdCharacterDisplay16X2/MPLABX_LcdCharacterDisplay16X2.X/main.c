/*
 * File:   main.c
 * Author: tomas
 *
 * Created on 12 grudnia 2024, 15:53
 */

//Non defaults configuration bits
#pragma config FNOSC = FRC              // Oscillator Mode (Internal Fast RC (FRC))
#pragma config IESO = ON                // Internal External Switch Over Mode (Start-up device with FRC, then automatically switch to user-selected oscillator source when ready)
#pragma config OSCIOFNC = ON            // OSC2 Pin Function (OSC2 pin has digital I/O function)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (Watchdog timer enabled/disabled by user software)
#pragma config ICS = PGD3               // ICD Communication Channel Select Bits (Communicate on PGEC3 and PGED3)

#include <xc.h>

#ifndef FCY
#define FCY 3574000UL  // Fosc(FRC)= 7.37Mhz(7370000Hz) -> Fcy = Fosc/2 = 3685000
#include <libpic30.h>   //to use __delay_us, FCY must be defined before include
#endif

#include "lcd2x16db8.h"

void init_all_io_pins_digital_outputs(void);


int main(void) {
    all_io_pins_digital_outputs();
    lcd_db8_init();

    while (1){
        lcd_db8_go_home();
        lcd_db8_print_string("Ho ho ho ho");
        lcd_db8_print_string("\x20\x2A\x2A\x2A");
        __delay_ms(3000);
        lcd_db8_go_line2_home();
        lcd_db8_print_string("Santa Santa\x20\x2A\x2A\x2A");
        __delay_ms(3000);
        lcd_db8_clear_screen();
        __delay_ms(3000);
    }
    return 0;
}

void all_io_pins_digital_outputs(void) {
    ANSELA = 0x0; // Disabling AN module 
    ANSELB = 0x0; // Disabling AN module 
    TRISA &= 0x0; // Make all lcd pins outputs
    TRISB &= 0x0; // Make all lcd pins outputs
}