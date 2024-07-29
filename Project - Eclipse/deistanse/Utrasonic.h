/*
 * ultrasonic.h
 *
 *
 *      Author: Ahmed Mostafa
 */
#include "std_types.h"
#include "gpio.h"


#define TR_PORT  PORTB_ID
#define TR_PIN   PIN5_ID






void Ultrasonic_init(void);
/*
 * Description:
 * Sets the trigger pin to high and delays until obtaining the high time value.
 */

void Ultrasonic_Trigger(void);
/*
 * Description:
 * Initiates the timer after sending the pulse trigger. After obtaining the high time value,
 * sets the trigger pin to low.
 */

uint16 Ultrasonic_readDistance(void);
/*
 * Description:
 * Function to retrieve the high time value.
 */

void Ultrasonic_edgeProcessing(void);
/*
 * Description:
 * Function to process the edge and obtain relevant information.
 */
