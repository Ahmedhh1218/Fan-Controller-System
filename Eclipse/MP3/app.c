/*
 ============================================================================
 Name        : app.c
 Author      : Ahmed Hassabou
 Description : Mini Project 3 application source file
 Date        : 11/OCT/2022
 ============================================================================
 */


#include "adc.h"
#include "lcd.h"
#include"dc_motor.h"
#include"pwm.h"
#include "lm35_sensor.h"

ADC_ConfigType ADC_Config = {INTERNAL_AREF,FCPU_8};

int main(void)
{
	/* Initializing all registers */
	uint8 temp;
	LCD_init();
	ADC_init(&ADC_Config);
	DcMotor_Init();
	LCD_moveCursor(0,3);
	LCD_displayString("Temp =    C");
	while(1)
	{

		temp = LM35_getTemperature();
		LCD_moveCursor(0,10);
		/* if the temperature is less than 30, turn fan off */
		if(temp<30){
			DcMotor_Rotate(STOP,0);
			LCD_moveCursor(1,3);
			LCD_displayString("FAN IS OFF");
		}
		/* if temperature is less than 60, open fan with 25% power */
		if(temp<60 && temp>=30){
			DcMotor_Rotate(CW,25);
			LCD_moveCursor(1,3);
			LCD_displayString("FAN IS ON");
			LCD_displayCharacter(' ');
		}

		/* if temperature is less than 90, open fan with 50% power */
		if(temp<90 && temp>=60){
			DcMotor_Rotate(CW,50);
			LCD_moveCursor(1,3);
			LCD_displayString("FAN IS ON");
			LCD_displayCharacter(' ');
		}

		/* if temperature is less than 120, open fan with 75% power */
		if(temp<120 && temp>=90){
			DcMotor_Rotate(CW,75);
			LCD_moveCursor(1,3);
			LCD_displayString("FAN IS ON");
			LCD_displayCharacter(' ');
		}

		/* if temperature is more than 120, open fan with 100% power */
		if(temp>120){
			DcMotor_Rotate(CW,100);
			LCD_moveCursor(1,3);
			LCD_displayString("FAN IS ON");
			LCD_displayCharacter(' ');
		}

		/* to avoid incorrect number in LCD */
		if(temp >= 100)
		{
			LCD_moveCursor(0,10);
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_moveCursor(0,10);
			LCD_intgerToString(temp);

			LCD_displayCharacter(' ');
		}
	}
}

