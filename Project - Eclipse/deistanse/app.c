/*
 * app.c
 *
 *      Author: Ahmed Mostafa
 */


#include "lcd.h"
#include "avr/io.h"
#include "Utrasonic.h"
uint16   g_distance = 0 ;
int main()
{
	LCD_init();
	Ultrasonic_init();
	LCD_displayString("DISTANCE= ");


	while(1)
	{
		SREG |= (1<<7);
		g_distance  = Ultrasonic_readDistance() ;
		LCD_moveCursor(0,10);
		LCD_intgerToString(g_distance);
		LCD_displayString("cm ");

	}
}
