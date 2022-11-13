/******************************************************************************
 *
 * >>>>>>>>>>>>>>>>>		Temperature Sensor Driver		<<<<<<<<<<<<<<<<<<<<<<<
 *
 * File Name: Temp_Sensor.c
 *
 * Description: Source file for the temperature sensor driver
 *
 * Author: Ahmed_Dorra
 *
 *******************************************************************************/


#include "adc.h"
#include "Temp_Sensor.h"


/*
 * Description :
 * Function responsible for initializing ADC with required parameters and then
 * initializing it to start.
 */
void LM35_init(void)
{
	ADC_ConfigType config;
	config.prescaler = PRESCALER_8;
	config.ref_volt = INTTERNAL_VREF;
	config.trigger_source  = FREE;
	ADC_init(&config);
}




/*
 * Description :
 * Function responsible for calculate the temperature from the digital value given by ADC
 * through the Equation below.
 */
uint8 LM35_getTemprature(void)
{
	uint8 temprature = 0;
	uint16 ADC_result = 0;

	ADC_result = ADC_readChannel(LM35_PIN);
	temprature = (uint8)(((uint32)ADC_result * MAX_TEMP_MEASURED * ADC_MAX_VOLT) /   \
			(SENSOR_MAX_OUTPUT_VOLT * ADC_MAX_DIGITAL_VALUE));

	return temprature;
}
