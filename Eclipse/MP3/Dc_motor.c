/******************************************************************************
 *
 * Module: DC_MOTOR
 *
 * File Name: Dc_motor.c
 *
 * Description: Source file for the DC MOTOR
 *
 * Author: Ahmed Hassabou
 *
 *******************************************************************************/

#include "std_types.h"
#include "dc_motor.h"
#include "gpio.h"
#include "pwm.h"


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/



void DcMotor_Init(void){
	/* setting PIN0, PIN1, and PIN3 in PortB to be output
	 * so that IN1, IN2, and ENABLE could be written with
	 * LOGICAL_HIGH or LOGICAL_LOW */
	GPIO_setupPinDirection(IN1_PORT, IN1_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(IN2_PORT, IN2_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(ENABLE_PORT, ENABLE_PIN, PIN_OUTPUT);

	/* Initializing the motor to be off at the beginning by writing
	 * a logical-low to PIN0 and PIN1 and logical-high to PIN3 */
	GPIO_writePin(IN1_PORT, IN1_PIN, LOGIC_LOW);
	GPIO_writePin(IN2_PORT, IN2_PIN, LOGIC_LOW);
	GPIO_writePin(ENABLE_PORT, ENABLE_PIN, LOGIC_HIGH);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	if(state==STOP)
	{
		GPIO_writePin(IN1_PORT, IN1_PIN, LOGIC_LOW);
		GPIO_writePin(IN2_PORT, IN2_PIN, LOGIC_LOW);
	}
	else if (state==CW)
	{
		GPIO_writePin(IN1_PORT, IN1_PIN, LOGIC_HIGH);
		GPIO_writePin(IN2_PORT, IN2_PIN, LOGIC_LOW);
	}
	else if(state==ACW)
	{
		GPIO_writePin(IN1_PORT, IN1_PIN, LOGIC_LOW);
		GPIO_writePin(IN2_PORT, IN2_PIN, LOGIC_HIGH);
	}
	PWM_Timer0_Start(speed);
}
