/*****************************************************************/
/*****************************************************************/
/****************	Authour: Ibrahim Saber	**********************/ 
/****************	File: PORT_prv.h		**********************/
/****************	Version: 1.00	        **********************/
/*****************************************************************/
/*****************************************************************/


#ifndef PORT_PRV_H_
#define PORT_PRV_H_


#define INPUT		0
#define OUTPUT		1

#define FLOATING		0
#define PULLED_UP		1
#define LOW				0
#define HIGH			1


#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)					CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)			0b##b7##b6##b5##b4##b3##b2##b1##b0


#define PORTA_DIR		CONC(PORTA_PIN7_DIR,PORTA_PIN6_DIR,PORTA_PIN5_DIR,PORTA_PIN4_DIR,PORTA_PIN3_DIR,PORTA_PIN2_DIR,PORTA_PIN1_DIR,PORTA_PIN0_DIR)
#define PORTB_DIR		CONC(PORTB_PIN7_DIR,PORTB_PIN6_DIR,PORTB_PIN5_DIR,PORTB_PIN4_DIR,PORTB_PIN3_DIR,PORTB_PIN2_DIR,PORTB_PIN1_DIR,PORTB_PIN0_DIR)
#define PORTC_DIR		CONC(PORTC_PIN7_DIR,PORTC_PIN6_DIR,PORTC_PIN5_DIR,PORTC_PIN4_DIR,PORTC_PIN3_DIR,PORTC_PIN2_DIR,PORTC_PIN1_DIR,PORTC_PIN0_DIR)
#define PORTD_DIR		CONC(PORTD_PIN7_DIR,PORTD_PIN6_DIR,PORTD_PIN5_DIR,PORTD_PIN4_DIR,PORTD_PIN3_DIR,PORTD_PIN2_DIR,PORTD_PIN1_DIR,PORTD_PIN0_DIR)


#define PORTA_InValue		CONC(PORTA_PIN7_InValue,PORTA_PIN6_InValue,PORTA_PIN5_InValue,PORTA_PIN4_InValue,PORTA_PIN3_InValue,PORTA_PIN2_InValue,PORTA_PIN1_InValue,PORTA_PIN0_InValue)
#define PORTB_InValue		CONC(PORTB_PIN7_InValue,PORTB_PIN6_InValue,PORTB_PIN5_InValue,PORTB_PIN4_InValue,PORTB_PIN3_InValue,PORTB_PIN2_InValue,PORTB_PIN1_InValue,PORTB_PIN0_InValue)
#define PORTC_InValue		CONC(PORTC_PIN7_InValue,PORTC_PIN6_InValue,PORTC_PIN5_InValue,PORTC_PIN4_InValue,PORTC_PIN3_InValue,PORTC_PIN2_InValue,PORTC_PIN1_InValue,PORTC_PIN0_InValue)
#define PORTD_InValue		CONC(PORTD_PIN7_InValue,PORTD_PIN6_InValue,PORTD_PIN5_InValue,PORTD_PIN4_InValue,PORTD_PIN3_InValue,PORTD_PIN2_InValue,PORTD_PIN1_InValue,PORTD_PIN0_InValue)

#endif