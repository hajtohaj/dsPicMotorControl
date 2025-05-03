#include "uart.h"

void setup_uart(void)
{
    //TX RX PIN Selection
    //UART1 Receive U1RX RPINR18 U1RXR<4:0>
    //RPnR<4:0> U1TX 00011 RPn tied to UART1 Transmit
    //RPINR18bits.U1RXR = 7;     //RX on RP7
    //RPOR3bits.RP6R = 3;        //TX on RP6
    
    // https://ww1.microchip.com/downloads/aemDocuments/documents/OTH/ProductDocuments/ReferenceManuals/70000582e.pdf
    //UART Configure
    //The most common data format is eight bits, no parity and one Stop bit (denoted as 8, N, 1), which is the default (POR) setting
    //The number of data bits, Stop bits and the parity are specified in the PDSEL<1:0> (UxMODE<2:1>) and STSEL (UxMODE<0>) bits
    //BRGH=0, U1BRG = 252 dla baudrate 9600 przy FOSC/2)=Fp=Fcy=38860000
    //BRGVAL ((FP/BAUDRATE)/16)-1
    U1MODEbits.STSEL = 0; // 1-Stop bit
    U1MODEbits.PDSEL = 0; // No Parity, 8-Data bits
    U1MODEbits.ABAUD = 0; // Auto-Baud disabled
    U1MODEbits.BRGH = 0; // Standard-Speed mode
    U1BRG = BRGVAL; // Baud Rate setting for BAUDRATE=9600 and Fp=38860000

////    //Interrupt 
//    U1STAbits.UTXISEL0 = 0; // Interrupt after one TX character is transmitted
//    //U1STAbits.UTXISEL1 = 0;
//    IEC0bits.U1TXIE = 1; // Enable UART TX interrupt
    
    //UART enable
    //    The UART module is enabled by setting the UARTEN (UxMODE<15>) and UTXEN
    //(UxSTA<10>) bits. Once enabled, the UxTX pin is configured as an output and the UxRX pin as
    //an input, overriding the TRISx and PORTx register bit settings for the corresponding I/O port
    //pins. The UxTX pin is at logic ?1? when no transmission is taking place
    //        Note: The UTXEN bit is set after the UARTEN bit has been set; otherwise, UART
    //transmissions will not be enabled.
    U1MODEbits.UARTEN = 1; // Enable UART
    U1STAbits.UTXEN = 1; // Enable UART TX
    //DELAY_105uS;            
}

//void __attribute__((__interrupt__)) _U1TXInterrupt(void)
//{
//    IFS0bits.U1TXIF = 0; // Clear TX Interrupt flag
//}

void UART1_Write(uint8_t txData)
{
    while(1==U1STAbits.UTXBF){
        asm volatile ("REPEAT, #3"); Nop(); //wait two clock cicles
    };
    U1TXREG = txData; // Write the data byte to the UART.
}
int write(int handle, void *buffer, unsigned int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        UART1_Write(*(char*) buffer++);
    }
    return (len);
}