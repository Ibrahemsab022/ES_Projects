/**
 * @file			ADC_reg.h
 * @brief			This file contains the addresses of the registers of the ADC
 * @author			Ibrahim Saber
 * @version			1.0
 * @date			19-4-2023
 */


#ifndef ADC_REG_H_
#define ADC_REG_H_

#define ACSR				*((volatile uint8 *) 0x28)



#define ADMUX				*((volatile uint8 *) 0x27)
#define ADMUX_MUX0			0u			/*@brief from ADMUX_MUX0 to MUX4 are the channel selection bits */
#define ADMUX_MUX1			1u
#define ADMUX_MUX2			2u
#define ADMUX_MUX3			3u
#define ADMUX_MUX4			4u
#define ADMUX_ADLAR			5u			/*Left/Right Adjustment bit*/
#define ADMUX_REFS0			6u			/*@brief REFS0 is the bit0 of the reference voltage select*/
#define ADMUX_REFS1			7u			/*@brief REFS1 is the bit1 of the reference voltage select*/


#define ADCSRA				*((volatile uint8 *) 0x26)
#define ADCSRA_ADPS0		0u			/*@brief ADPS0,1,2 are the prescaler bits*/
#define ADCSRA_ADPS1		1u
#define ADCSRA_ADPS2		2u
#define ADCSRA_ADIE			3u			/*@brief is the ADC interrupt enable bit*/
#define ADCSRA_ADIF			4u			/*@brief is the ADC interrupt flag bit*/
#define ADCSRA_ADATE		5u			/*@brief is the Auto trigger enable bit*/
#define ADCSRA_ADSC			6u			/*@brief is the ADC Start conversion bit*/
#define ADCSRA_ADEN			7u			/*@brief is the ADC enable bit*/


#define ADCH			*((volatile uint8 *) 0x25)
#define ADCL			*((volatile uint8 *) 0x24)
#define ADC				*((volatile uint16 *) 0x24)		/*ADC Data register*/


#define SFIOR			*((volatile uint8 *) 0x50)
#define ADTS0			5u			/*those three bits selects the mood of operation of the ADC*/
#define ADTS1			6u
#define ADTS2			7u


#endif
