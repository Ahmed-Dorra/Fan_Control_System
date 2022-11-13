/******************************************************************************
 *
*>>>>>>>>>>>>>>>>>		Temperature Sensor Driver		<<<<<<<<<<<<<<<<<<<<<<<
 *
 * File Name: Temp_Sensor.h
 *
 * Description: Header file for the temperature sensor driver
 *
 * Author: Ahmed_Dorra
 *
 *******************************************************************************/


#ifndef TEMP_SENSOR_H_
#define TEMP_SENSOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/*-->>	STATIC CONFIGURATION	<<--*/
#define LM35_PIN					2
#define MAX_TEMP_MEASURED			150
#define SENSOR_MAX_OUTPUT_VOLT		1.5

/*******************************************************************************
 *------->>>>>>>>>>           Functions Prototypes             <<<<<<--------- *
*******************************************************************************/

/*
 * Description :
 * Function responsible for initializing ADC with required parameters and then
 * initializing it to start.
 */
void LM35_init(void);

/*
 * Description :
 * Function responsible for calculate the temperature
 */
uint8 LM35_getTemprature(void);


#endif /* TEMP_SENSOR_H_ */
