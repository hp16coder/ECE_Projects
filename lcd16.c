/* Keypad Interfacing  with Microcontroller                                
Embedded Systems - Ravi kiran Bolla (YouTube Channel) */

#include <REGX51.H>
#define keypad   P1
#define LCD_dat P2
sbit rs =P3^0;
sbit en =P3^1;

unsigned int LCD_Cur_pos;

void dely(unsigned int dly);
void lcd_cmd(unsigned char ch);
void lcd_data(unsigned char ch);
void lcd_str(unsigned char *str);
char get_keypad_key(void);

void main(void)
{
	char KeyVal =0;
	lcd_cmd(0x38);
	lcd_cmd(0x0C);
	
      while(1)
      {			
				if(LCD_Cur_pos < 16)
				lcd_cmd(0x80+LCD_Cur_pos);
				if(LCD_Cur_pos >= 16)
				lcd_cmd(0xc0+LCD_Cur_pos-16);
				if(LCD_Cur_pos >= 32)
				{
				lcd_cmd(0x01);
				LCD_Cur_pos = 0;
				}
				
				KeyVal = get_keypad_key();
				
				lcd_data(KeyVal);	
				dely(20);				
       }
}

char get_keypad_key(void)
{
	char key_val =0;
	       keypad = 0xFE; //ROW1 =0			
          if(keypad == 0xee) // button 1
					{
           key_val = '1';
					LCD_Cur_pos++;
					}	
          if(keypad == 0xde) // button 2
					{
           key_val = '2';
						LCD_Cur_pos++;
					}	
					 if(keypad == 0xbe) // button 3
					{
           key_val = '3';
						LCD_Cur_pos++;
					}	
					
					keypad = 0xFD; //ROW2 =0
					if(keypad == 0xED) // button 4
					{
					key_val = '4';
						LCD_Cur_pos++;
					}	
					if(keypad == 0xDD) // button 5
					{
					key_val = '5';
						LCD_Cur_pos++;
					}	
					 if(keypad == 0xBD) // button 6
					{
					key_val = '6';
						LCD_Cur_pos++;
					}	
					
					keypad = 0xFB; //ROW3 =0
					if(keypad == 0xEB) // button 7
					{
					key_val = '7';
						LCD_Cur_pos++;
					}	
					if(keypad == 0xDB) // button 8
					{
					key_val = '8';
						LCD_Cur_pos++;
					}	
					 if(keypad == 0xBB) // button 9
					{
					key_val = '9';
						LCD_Cur_pos++;
					}	
					
						keypad = 0xF7; //ROW3 =0
					if(keypad == 0xE7) // button *
					{
					key_val = '*';
						LCD_Cur_pos++;
					}	
					if(keypad == 0xD7) // button 0
					{
					key_val = '0';
						LCD_Cur_pos++;
					}	
					 if(keypad == 0xB7) // button #
					{
					key_val = '#';
						LCD_Cur_pos++;
					}	
	return key_val;
}


void lcd_str(unsigned char *str)
{
	unsigned int loop =0;
	for(loop =0; str[loop]!= '\0'; loop++)
	{
		lcd_data(str[loop]);
	}
}
void lcd_data(unsigned char ch)
{
	LCD_dat = ch;
	rs = 1;  // data
	en = 1;
	dely(10);
	en = 0;
}

void lcd_cmd(unsigned char ch)
{
	LCD_dat = ch;
	rs = 0;  // cmd
	en = 1;
	dely(10);
	en = 0;
}
void dely(unsigned int dly)
{
	unsigned int loop =0;
	unsigned int delay_gen =0;
	for(loop =0; loop < dly; loop++)
	for(delay_gen =0; delay_gen < 1000; delay_gen++); /* delay */
}



