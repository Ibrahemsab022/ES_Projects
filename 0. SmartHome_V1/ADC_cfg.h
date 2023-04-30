/**
 * @file			ADC_cfg.h
 * @brief			This file configures the ADC driver
 * @author			Ibrahim Saber
 * @version			1.0
 * @date			19-4-2023
 */

#ifndef ADC_CFG_H_
#define ADC_CFG_H_


/*Please select the reference voltage mode from the following options:
 * 																		1- AVCC
 * 																		2- AREF
 * 																		3- INTERNAL_REF
 **/
#define REFERENCE_SELECTION			AVCC


/*Please select the Adjustment mode for the result from the following options:
 * 																			1- EIGHT_BITS
 * 																			2- TEN_BITS
 *
 **/
#define ADC_RESOLUTION				EIGHT_BITS


/*Please select the auto-trigger mode from the following options:
 * 																			1- ENABLED
 * 																			2- DISABLED
 *
 **/

#define ADC_AUTO_TRIGGER	 		DISABLED


/*Please select the Interrupt mode from the following options:
 * 																			1- ENABLED
 * 																			2- DISABLED
 *
 **/
#define ADC_INTERRUPT_ENABLE 		DISABLED


/*Please select the prescaler mode from the following options:
 * 																1- DIVISION_FACTOR_2
 * 																2- DIVISION_FACTOR_4
 * 																3- DIVISION_FACTOR_8
 * 																4- DIVISION_FACTOR_16
 * 																5- DIVISION_FACTOR_32
 * 																6- DIVISION_FACTOR_64
 * 																7- DIVISION_FACTOR_128
 *
 **/
#define PRESCALER_SELECTION			DIVISION_FACTOR_128


/*Please Configure the timeout time */

#define ADC_u32TIMEOUT			50000u


#endif
