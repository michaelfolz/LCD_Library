/*
 * CFile1.c
 *
 * Created: 7/18/2013 11:16:42 AM
 *  Author: mfolz
 This piece of crap is a temp replacement for the _delay_ms and us the timing is off with them 
 */ 


#include "Functions.h"
#include <avr/io.h>

void Delay_s(int delays){
	while (delays != 0){
		Delay_ms(1000);
		delays--;
	}
}

void Delay_ms(int delayms){
	while (delayms != 0){
		Delay_us(1000);
		delayms--;
	}
}
void Delay_us(int delayus){
	while (delayus != 0){
		Delay();
		delayus--;
	}

}

void Delay(void){
	float usdelay = 0.0;
	usdelay = (1000/ ( (1.0 / MAIN_CLOCK) * 1000000000 ) )/4 ;
	
	for (;usdelay > 0; usdelay--){
		asm("NOP");
	}
}