/* 
 * File:   lcd2x16db8.h
 * Author: tomas
 *
 * Created on 22 grudnia 2024, 12:58
 */

#ifndef LCD2X16DB8_H
#define	LCD2X16DB8_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <xc.h>

#ifndef FCY
#define FCY 3574000UL  // Fosc(FRC)= 7.37Mhz(7370000Hz) -> Fcy = Fosc/2 = 3685000
#include <libpic30.h>   //to use __delay_us, FCY must be defined before include
#endif
    
// LCD Itf Signals (register initialization in init_lcd_itf()
#define LCD_RSPin LATBbits.LATB5        // RB5 (LCD RS, Pin4)Register Select H:Data Input L:Instruction Input
#define LCD_RS_INSTRUCTION  0           // LCD Instruction register 
#define LCD_RS_DATA  1                  // LCD Data register
#define LCD_RWPin LATBbits.LATB6        // RB6 (LCD R/W Pin 5) R/W select H:Read, L:Write  
#define LCD_RW_WRITE  0                 // 
#define LCD_RW_READ  1                  // LCD Data register
#define LCD_EPin  LATBbits.LATB7        // RB7 (LCD E Pin 6)Enable Signal
#define LCD_E_HIGH 1                    //
#define LCD_E_LOW 0                     //
#define LCD_E_PULSE_WIDTH_US 0x0001     //
#define LCD_BFBit PORTBbits.RB15        //
#define LCD_DB_TRIS  TRISB              //
#define LCD_DB_TRIS_INPUT 0xFF00        //
#define LCD_DB_TRIS_OUTPUT 0x001F       // 
#define LCD_DB_LAT  LATB                //               
#define LCD_DB_PORT  PORTB              //
#define LCD_DB_SET_PORT_PINS  0xFF00    //
#define LCD_DB_CLEAR_PORT_PINS  0x00FF  // 
#define LCD_DISPLAY_ON   0x0004         //
#define LCD_DISPLAY_OFF  0x0000         //            
#define LCD_CURSOR_ON  0x0002           //                  
#define LCD_CURSOR_OFF  0x0000          //
#define LCD_CURSOR_BLINK_ON  0x0001     //                  
#define LCD_CURSOR_BLINK_OFF  0x0000    //
#define LCD_FIRST_LINE_START 0x0000     //
#define LCD_SECOND_LINE_START 0x0040    //
#define LCD_LINE_LENGTH 24              //
#define LCD_LINE_LENGTH_VISIBLE 16      //

void lcd_db8_init(void);
void lcd_db8_print_character(char);
void lcd_db8_print_string(char*);
void lcd_db8_go_home(void);
void lcd_db8_go_line1_home(void);
void lcd_db8_go_line2_home(void);
void lcd_db8_go_to_position(unsigned char);
void lcd_db8_clear_screen(void);
void lcd_db8_clear_line1(void);
void lcd_db8_clear_line2(void);
void lcd_db8_set_display_set_cursor(unsigned char, unsigned char, unsigned char);

#ifdef	__cplusplus
}
#endif

#endif	/* LCD2X16DB8_H */

