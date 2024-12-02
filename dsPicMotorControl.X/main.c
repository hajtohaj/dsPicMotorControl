/*
 * File:   main.c
 * Author: tomas
 *
 * Created on November 28, 2024, 9:27 PM
 */

//Configuration Bits
#pragma config FNOSC = FRCPLL  // Oscillator Mode (Internal Fast RC (FRC) w/ PLL)
#pragma config FWDTEN = OFF    // Watchdog Timer Enable (Watchdog timer enabled/disabled by user software)

#include <xc.h>
#include "setup_oscilator_35MIPS_FRCPLL.h"

int main(void) {
    
    setup_oscilator_35MIPS_FRCPLL();
    
    _TRISB5 = 0; //set port pin as output
    
    while (1){
        _RB5 = (_LATB5) ? 0:1; //togle PORTB Pin nr 5 
        __delay_us(500000);
    }
    return 0;
}
