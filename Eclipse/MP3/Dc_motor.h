/******************************************************************************
 *
 * Module: DC_MOTOR
 *
 * File Name: Dc_motor.h
 *
 * Description: header file for the DC MOTOR
 *
 * Author: Ahmed Hassabou
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define IN1_PORT           PORTB_ID
#define IN2_PORT           PORTB_ID
#define ENABLE_PORT        PORTB_ID

#define IN1_PIN            PIN0_ID
#define IN2_PIN            PIN1_ID
#define ENABLE_PIN         PIN3_ID


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum{
	STOP, CW, ACW
}DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for setup the direction for the two
 * motor pins through the GPIO driver.
 * stop the DC-Motor at the beginning through the GPIO driver
 */

/*
 * Description :
 * The function responsible for rotate the DC Motor CW/ or A-CW or
 * stop the motor based on the state input state value.
 * Send the required duty cycle to the PWM driver based on the
 * required speed value.
 */


void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* DC_MOTOR_H_ */
