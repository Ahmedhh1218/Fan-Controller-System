 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega32 ADC driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */

typedef enum{
	AREF,AVCC=0x40,RESERVED=0x80,INTERNAL_AREF=0xC0
}ADC_ReferenceVoltage;
typedef enum{
	FCPU_2,FCPU_2_1,FCPU_4,FCPU_8,FCPU_16,FCPU_32,FCPU_64,FCPU_128
}ADC_Prescaler;
typedef struct{
 ADC_ReferenceVoltage ref_volt;
 ADC_Prescaler prescaler;
}ADC_ConfigType;

void ADC_init(const ADC_ConfigType * Config_Ptr);
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
