/*
 * File:   main.c
 * Author: tomas
 * Chip: dsPIC33FJ64MC802
 * Created on 5 lutego 2025, 21:42
 */

//Configuration Bits
#pragma config FNOSC = FRCPLL  // Oscillator Mode (Internal Fast RC (FRC) w/ PLL)
#pragma config OSCIOFNC = OFF  // OSC2 Pin Function (OSC2 pin has clock out function)
#pragma config FWDTEN = OFF    // Watchdog Timer Enable (Watchdog timer enabled/disabled by user software)

#define FCY 38860000

#include "xc.h"
#include "libpic30.h"
#include "stdio.h"
#include "uart.h"

void setup_oscilator_39MIPS_FRCPLL(void);

int main(void) {
    setup_oscilator_39MIPS_FRCPLL();
    //Select UART1 pins and initialize UART1 
    RPINR18bits.U1RXR = 7;     //RX on RP7
    RPOR3bits.RP6R = 3;        //TX on RP6
    setup_uart(); //BAUDRATE 115200 , 8 bit, no parity, 1-stop, no flow control
    
    _TRISB5 = 0; //set port pin as output - GREEN
    _TRISA4 = 0; //set port pin as output - RED
    _RA4 = 1;
    _RB5 = 1;
    __delay_ms(5000);

    int i = 1;
    while(1)
    {
        if (i>100) i=0;
       _RB5 = (_LATB5) ? 0:1; //togle PORTB Pin nr 5 - on
       __delay_ms(1000);
       printf("Moge sobie tu liczyc co chce: %u \r\n", i++);
    }
}

void setup_oscilator_39MIPS_FRCPLL(void){
    
    //set PLL to have Fosc=77720000 -> Fcy=Fosc/2=38860000 (Fosc=FRC/N1/N2*M: 7370000/22/2*464=~77720000))
    _PLLPRE = 20; //N1=2+20=22
    _PLLPOST = 0; //N2=2+0=2
    _PLLDIV = 461; //M=3+461=464
}

