#include "lcd2x16db8.h"

char *empty_line = "                        ";

void lcd_db8_write(unsigned char, unsigned char);
unsigned char lcd_db8_read(unsigned char);
void lcd_db8_write_instruction(unsigned char);
void lcd_db8_write_data(unsigned char);
void lcd_db8_wait_until_bussy(void);

void lcd_db8_init(void) {
    //Based on https://web.alfredstate.edu/faculty/weimandn/lcd/lcd_initialization/lcd_initialization_index.html
    __delay_us(15000);                      
    lcd_db8_write(0x30, LCD_RS_INSTRUCTION); //function set: 8bit buss, 2 line display, 5x8 dots 
    __delay_us(4100);
    lcd_db8_write(0x30, LCD_RS_INSTRUCTION); //function set: 8bit buss, 2 line display, 5x8 dots 
    __delay_us(100);
    lcd_db8_write(0x38, LCD_RS_INSTRUCTION); //function set: 8bit buss, 2 line display, 5x8 dots 
    //from now on, we can start checking BF insted of using fixed delay
    lcd_db8_write_instruction(0xC);         // display on, cursor off, blink off
    lcd_db8_write_instruction(0x1);         //move cursor home 
}

void lcd_db8_write(unsigned char data, unsigned char select_lcd_reg) {
    unsigned int portb;
    TRISB &= LCD_DB_TRIS_OUTPUT;
    LCD_RSPin = select_lcd_reg;
    LCD_RWPin = LCD_RW_WRITE;
    portb = LCD_DB_PORT;
    portb &= LCD_DB_CLEAR_PORT_PINS;
    portb |= (data << 8);
    LCD_DB_LAT = portb;
    LCD_EPin = LCD_E_HIGH;
    __delay_us(LCD_E_PULSE_WIDTH_US);
    LCD_EPin = LCD_E_LOW; //Set Enable bit
    __delay_us(LCD_E_PULSE_WIDTH_US);
}

unsigned char lcd_db8_read(unsigned char lcd_reg) {
    unsigned char data_address = 0x1;
    TRISB |= LCD_DB_TRIS_INPUT;
    LCD_RSPin = lcd_reg;
    LCD_RWPin = LCD_RW_READ;
    LCD_EPin = LCD_E_HIGH;
    __delay_us(LCD_E_PULSE_WIDTH_US);
    data_address = (LCD_DB_PORT >> 8);
    LCD_EPin = LCD_E_LOW;
    __delay_us(LCD_E_PULSE_WIDTH_US);
    return data_address;
}

void lcd_db8_write_instruction(unsigned char instruction) {
    lcd_db8_wait_until_bussy();
    lcd_db8_write(instruction, LCD_RS_INSTRUCTION);
}

void lcd_db8_write_data(unsigned char data) {
    lcd_db8_wait_until_bussy();
    lcd_db8_write(data, LCD_RS_DATA);
}

void lcd_db8_wait_until_bussy(void) {
    unsigned char bf = 0x1;
    while (bf) {
        bf = (lcd_db8_read(LCD_RS_INSTRUCTION) & 0x80);
    }
}

void lcd_db8_set_display_set_cursor(unsigned char display_onoff, unsigned char cursor_onoff, unsigned char cursor_blink_onoff) {
    unsigned char display_configuration = 0x8;
    display_configuration |= display_onoff;
    display_configuration |= cursor_onoff;
    display_configuration |= cursor_blink_onoff;
    lcd_db8_write_instruction(display_configuration);
}

void lcd_db8_set_ddram_adress(unsigned char ddram_address) {
    unsigned char address = 0x80;
    address |= ddram_address;
    lcd_db8_write_instruction(address);
}

void lcd_db8_go_home(void) {
    lcd_db8_write_instruction(0x2);
}

void lcd_db8_go_line1_home(void){
    lcd_db8_go_home();
}

void lcd_db8_go_line2_home(void){
    lcd_db8_set_ddram_adress(LCD_SECOND_LINE_START);
}

void lcd_db8_go_to_position(unsigned char position){
    lcd_db8_set_ddram_adress(position);
}

void lcd_db8_clear_screen(void) {
    lcd_db8_write_instruction(0x1);
}

void lcd_db8_clear_line1(void){
    lcd_db8_go_home();
    lcd_db8_print_string(empty_line);
    lcd_db8_go_home();
}
void lcd_db8_clear_line2(void){
    lcd_db8_go_line2_home();
    lcd_db8_print_string(empty_line);
    lcd_db8_go_line2_home();    
}

void lcd_db8_print_character(char var){
    lcd_db8_write_data(var);
}

void lcd_db8_print_string(char *var) {
    while (*var) {
        lcd_db8_write_data(*var++);
    }
}