/******************************************************************************
 *
 * Project: Fan Control System
 *
 * File Name: Application.c
 *
 * Description: Source file for the fan control system project
 *
 * Author: Ahmed_Dorra
 *
 *******************************************************************************/

#include "motor.h"
#include "lcd.h"
#include "Temp_Sensor.h"


int main (void)
{
	uint8 temperature;
	LCD_init();
	LM35_init();
	DcMotor_Init();
	LCD_sendCommand(LCD_CURSOR_OFF);
	LCD_displayString("Fan is : ");
	LCD_moveCursor(1,0);
	LCD_displayString("Temp is :    C");

	while (1)
	{
		temperature = LM35_getTemprature();
		LCD_moveCursor(1,10);
		if(temperature >= 100)
		{
			LCD_intgerToString(temperature);
			if(temperature < 120)
			{
				LCD_moveCursor(0,9);
				LCD_displayString("ON ");
				DcMotor_Rotate(CW,75);
			}
			else
			{
				LCD_moveCursor(0,9);
				LCD_displayString("ON ");
				DcMotor_Rotate(CW,100);
			}
		}
		else
		{
			LCD_intgerToString(temperature);
			/* In case the digital value is three or two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
			if(temperature < 30)
			{
				LCD_moveCursor(0,9);
				LCD_displayString("OFF");
				DcMotor_Rotate(STOP,0);
			}
			else if(temperature >= 30 && temperature < 60)
			{
				LCD_moveCursor(0,9);
				LCD_displayString("ON ");
				DcMotor_Rotate(CW,25);

			}
			else if(temperature >= 60 && temperature < 90)
			{
				LCD_moveCursor(0,9);
				LCD_displayString("ON ");
				DcMotor_Rotate(CW,50);
			}
			else if(temperature >= 90)
			{
				LCD_moveCursor(0,9);
				LCD_displayString("ON ");
				DcMotor_Rotate(CW,75);
			}

		}
	}
}

