/*
 * File:   main.c
 * Author: tomas
 *
 * Created on November 28, 2024, 9:27 PM
 */

#include "xc.h"

#define FCY 40000000UL
#include <libpic30.h>   //to use __delay_us, FCY must be defined before include

//Configuration Bits
#pragma config FNOSC = FRCPLL  // Oscillator Mode (Internal Fast RC (FRC) w/ PLL)
#pragma config FWDTEN = OFF    // Watchdog Timer Enable (Watchdog timer enabled/disabled by user software)


int main(void) {
    
    //set PLL to have Fosc=80MHz -> Fcy=40MIPS
    _PLLPRE = 1; //N1=3
    _PLLPOST = 0; //N2=2
    _PLLDIV = 63; //M=65
    
    _TRISB5 = 0; //set port pin as output
    
    while (1){
        _RB5 = (_LATB5) ? 0:1; //togle PORTB Pin nr 5 
        __delay_us(500000);
    }
    return 0;
}
