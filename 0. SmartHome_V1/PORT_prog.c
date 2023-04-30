/*****************************************************************/
/*****************************************************************/
/****************	Authour: Ibrahim Saber	**********************/ 
/****************	File: PORT_prog.c		**********************/
/****************	Version: 1.00	        **********************/
/*****************************************************************/
/*****************************************************************/


#include "STD_TYPES.h"

#include "PORT_reg.h"
#include "PORT_interface.h"
#include "PORT_cfg.h"
#include "PORT_prv.h"


void PORT_voidInit(void)
{
	DDRA = PORTA_DIR;
	DDRB = PORTB_DIR;
	DDRC = PORTC_DIR;
	DDRD = PORTD_DIR;
	
	PORTA = PORTA_InValue;
	PORTB = PORTB_InValue;
	PORTC = PORTC_InValue;
	PORTD = PORTD_InValue;
}

