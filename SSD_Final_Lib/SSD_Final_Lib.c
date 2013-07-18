/*
 * SSD_Final_Lib.c
 *
 * Created: 7/12/2013 11:32:06 AM
 *  Author: mfolz
 */ 
	
#include "Libs/AtmegaLibs/AtmegaPins.h"
#include "Libs/AtmegaLibs/Serial_Atmel328p.h"
#include "Libs/AtmegaLibs/SPI.h"
#include "Libs/AtmegaLibs/Functions.h"

#include "Libs/LCD_Libs/LCD_Draw.h"
#include "Libs/LCD_Libs/LCD_Config.h"
#include "Libs/LCD_Libs/Draw_Bitmap.h"

#include "Libs/Application/Demo_App.h"
#include "Libs/Application/Terminal.h"

#include <avr/io.h>
#include <avr/pgmspace.h>
#define F_CPU 16000000
#include <util/delay.h>


const char hello[] PROGMEM =  "hello world";

/* For the most part everything is great with the exception of the following.
	- need to add support for terminal on both displays 
	- need to fix the rotation algorithms! 
	-----------------------------------------------------------------
	
	ALL Work with The ST7735 
	
	Fix The Following: 
		Draw  bitmap 
*/


int main(void)
{
	struct LCD_Geometry *pointCurrent= &Current;
	struct LCD_Properties *pointProperties= &Properties;
	FILE lcd_str = FDEV_SETUP_STREAM(TerminalChar, NULL, _FDEV_SETUP_RW);
	//FILE lcd_str = FDEV_SETUP_STREAM(USART_send, NULL, _FDEV_SETUP_RW);
	char *hellow = "hello";
	stdout = &lcd_str;

	USART_init();
	SPI_MasterInit();
	SSD1289_Initalize();
	

	
	testLibrary(); 

		
	//ReadBMP_ARRAY(40,40,BMP_IMAGE);
}
