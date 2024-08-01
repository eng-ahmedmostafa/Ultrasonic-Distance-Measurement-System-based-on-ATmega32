/*
 ============================================================================
 Name        : ultrasonic.c
 Author      : Ahmed Mostafa
 Date        : 23 Oct 2023
 Description : Ultrasonic Distance Measurement System based on ATmega32
 ============================================================================
 */

#include"icu.h"
#include"gpio.h"
#include"Utrasonic.h"
#include<util/delay.h>


ICU_ConfigType ICU_Configurations = { F_CPU_8, RAISING };
uint8 g_edgeCount = 0;
uint16 g_timeHigh = 0;


void Ultrasonic_edgeProcessing(void){

	g_edgeCount++;

	if(g_edgeCount == 1)
	{
		/*
		 * Clear timer counter register to start measurements from the
		 * next detected rising edge
		 */

		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(FALLING);/* Detect falling edge */
	}
	else if(g_edgeCount == 2)
	{
		/* Store the High time value */
		g_timeHigh = ICU_getInputCaptureValue();
		g_edgeCount=0;
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(RAISING);


	}
}

/*
 * Description:
 * This function initializes the ultrasonic module.
 * 1. Initialization of the Input Capture Unit (ICU) involves sending a structure with the necessary prescaler and initial edge settings.
 * 2. Setting the callback function for event handling.
 * 3. Configuring the trigger pin as an output pin.
 */
void Ultrasonic_init(void)
{

	ICU_init(&ICU_Configurations);
	/*
 * This function receives a structure as input.
 * It uses the information within the structure to configure the bits associated with the prescaler and edge settings.
 */
	ICU_setCallBack(Ultrasonic_edgeProcessing);
	/*
 * In this section, the address of the 'Ultrasonic_edgeProcessing' function is provided to 'ICU_setCallBack'.
 * This ensures that the 'edge_processing' function is invoked during the Interrupt Service Routine (ISR) routine.
 */
	GPIO_setupPinDirection(TR_PORT,TR_PIN,PIN_OUTPUT);

/*
 * Description:
 * This section involves setting the trigger pin to a high state and waiting until the high time value is achieved.
 */
}
void Ultrasonic_Trigger(void)
{
	GPIO_writePin(TR_PORT,TR_PIN , LOGIC_HIGH);
	_delay_us(10);



}

/*
 * Description:
 * The timer is initiated after transmitting the pulse trigger, and upon obtaining the high time value,
 * the trigger pin is then set to a low state.
 */
uint16 Ultrasonic_readDistance(void)
{
	uint16 UTRRASONIC_distance=0;
	Ultrasonic_Trigger();
	/*
 * In this segment, a trigger pulse is dispatched to the ultrasonic module. Subsequently, ultrasound waves are emitted towards the designated object,
 * for which the aim is to measure the distance.
 */

	GPIO_writePin(PORTB_ID, PIN5_ID, LOGIC_LOW); /* Setting it to a low state after obtaining the high time value */
 UTRRASONIC_distance = (g_timeHigh / 58 )+ 1; /* Calculations are performed here to derive the distance in centimeters */
return UTRRASONIC_distance; /* Returning the calculated distance for subsequent display on the LCD */

}
