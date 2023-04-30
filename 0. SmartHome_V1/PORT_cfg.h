/*****************************************************************/
/*****************************************************************/
/****************	Authour: Ibrahim Saber	**********************/ 
/****************	File: PORT_cfg.h		**********************/
/****************	Version: 1.00	        **********************/
/*****************************************************************/
/*****************************************************************/


#ifndef PORT_CFG_H_
#define PORT_CFG_H_


/*Configuring pins direction, options: 1- INPUT
									   2- OUTPUT */				   
#define PORTA_PIN0_DIR			INPUT	
#define PORTA_PIN1_DIR			OUTPUT
#define PORTA_PIN2_DIR			OUTPUT
#define PORTA_PIN3_DIR			OUTPUT
#define PORTA_PIN4_DIR			OUTPUT
#define PORTA_PIN5_DIR			OUTPUT
#define PORTA_PIN6_DIR			OUTPUT
#define PORTA_PIN7_DIR			INPUT	

#define PORTB_PIN0_DIR			INPUT	
#define PORTB_PIN1_DIR			INPUT	
#define PORTB_PIN2_DIR			INPUT	
#define PORTB_PIN3_DIR			INPUT	
#define PORTB_PIN4_DIR			INPUT	
#define PORTB_PIN5_DIR			INPUT	
#define PORTB_PIN6_DIR			INPUT	
#define PORTB_PIN7_DIR			INPUT	


#define PORTC_PIN0_DIR			OUTPUT
#define PORTC_PIN1_DIR			OUTPUT
#define PORTC_PIN2_DIR			OUTPUT
#define PORTC_PIN3_DIR			OUTPUT
#define PORTC_PIN4_DIR			OUTPUT
#define PORTC_PIN5_DIR			OUTPUT
#define PORTC_PIN6_DIR			OUTPUT
#define PORTC_PIN7_DIR			OUTPUT


#define PORTD_PIN0_DIR			OUTPUT
#define PORTD_PIN1_DIR			OUTPUT
#define PORTD_PIN2_DIR			OUTPUT
#define PORTD_PIN3_DIR			OUTPUT
#define PORTD_PIN4_DIR			OUTPUT
#define PORTD_PIN5_DIR			OUTPUT
#define PORTD_PIN6_DIR			OUTPUT
#define PORTD_PIN7_DIR			INPUT


/*Configuring pins initial values, options for input pins:  1- FLOATING
*															2- PULLED_UP 
*								   options for output pins: 1- LOW
*															2- HIGH
*															
*															*/
								   
#define PORTA_PIN0_InValue		FLOATING
#define PORTA_PIN1_InValue		LOW
#define PORTA_PIN2_InValue		LOW
#define PORTA_PIN3_InValue		LOW
#define PORTA_PIN4_InValue		LOW
#define PORTA_PIN5_InValue		LOW
#define PORTA_PIN6_InValue		LOW
#define PORTA_PIN7_InValue		FLOATING
								
#define PORTB_PIN0_InValue		FLOATING
#define PORTB_PIN1_InValue		FLOATING
#define PORTB_PIN2_InValue		PULLED_UP
#define PORTB_PIN3_InValue		FLOATING
#define PORTB_PIN4_InValue		PULLED_UP
#define PORTB_PIN5_InValue		PULLED_UP
#define PORTB_PIN6_InValue		PULLED_UP
#define PORTB_PIN7_InValue		PULLED_UP
								
#define PORTC_PIN0_InValue		LOW
#define PORTC_PIN1_InValue		LOW
#define PORTC_PIN2_InValue		LOW
#define PORTC_PIN3_InValue		LOW
#define PORTC_PIN4_InValue		LOW
#define PORTC_PIN5_InValue		LOW
#define PORTC_PIN6_InValue		LOW
#define PORTC_PIN7_InValue		LOW
								
#define PORTD_PIN0_InValue		LOW
#define PORTD_PIN1_InValue		LOW
#define PORTD_PIN2_InValue		HIGH
#define PORTD_PIN3_InValue		HIGH
#define PORTD_PIN4_InValue		HIGH
#define PORTD_PIN5_InValue		HIGH
#define PORTD_PIN6_InValue		LOW
#define PORTD_PIN7_InValue		FLOATING




#endif


