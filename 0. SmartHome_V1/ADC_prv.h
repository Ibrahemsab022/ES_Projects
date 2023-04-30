/**
 * @file			ADC_prv.h
 * @brief			This file contains private macros for the ADC driver
 * @author			Ibrahim Saber
 * @version			1.0
 * @date			19-4-2023
 */

#ifndef ADC_PRV_H_
#define ADC_PRV_H_

#define PRESCALER_MASK			0b11111000
#define CHANNEL_MASK			0b11100000


#define AVCC					1u
#define AREF					2u
#define INTERNAL_REF			3u


#define EIGHT_BITS				1u
#define TEN_BITS				2u


#define DIVISION_FACTOR_2  		1u
#define	DIVISION_FACTOR_4  		2u
#define	DIVISION_FACTOR_8  		3u
#define	DIVISION_FACTOR_16 		4u
#define	DIVISION_FACTOR_32 		5u
#define	DIVISION_FACTOR_64 		6u
#define	DIVISION_FACTOR_128		7u

#endif
