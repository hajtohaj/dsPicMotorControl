/* 
 * File:   uart.h
 * Author: tomas
 *
 * Created on 3 maja 2025, 20:08
 */

#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "xc.h"
#ifndef FCY
#define FCY 38860000
#endif
    
#define FP FCY
    
#ifndef BAUDRATE
#define BAUDRATE 115200
#endif
    
#define BRGVAL ((FP/BAUDRATE)/16)-1

void setup_uart(void);
void UART1_Write(uint8_t);
int write(int, void *, unsigned int);


#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

