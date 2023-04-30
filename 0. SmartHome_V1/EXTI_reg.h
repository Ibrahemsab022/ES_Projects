#ifndef EXTI_REG_H_
#define EXTI_REG_H_

#define GICR			*((volatile uint8 *) 0x5B)			/*@brief General Interrupt control register*/
#define GICR_INT1		7u									/*@brief INT0	control bit*/
#define GICR_INT0		6u                                  /*@brief INT1	control bit*/
#define GICR_INT2		5u                                  /*@brief INT2	control bit*/


#define MCUCR			*((volatile uint8 *) 0x55)		  /*@brief MCU control Register*/
#define MCUCR_ISC00		0u                                /*@brief Interrupt sense control 0 bit 0*/
#define MCUCR_ISC01		1u                                /*@brief Interrupt sense control 0 bit 1*/
#define MCUCR_ISC10		2u                                /*@brief Interrupt sense control 1 bit 0*/
#define MCUCR_ISC11		3u                               /*@brief Interrupt sense control 1 bit 1*/


#define MCUCSR			*((volatile uint8 *) 0x54)			/*@brief MCU control Status Register*/
#define MCUCSR_ISC2		6u									/*@brief Interrupt sense control 2*/



#endif



