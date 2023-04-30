#ifndef GIE_REG_H_
#define GIE_REG_H_


/*defineing a macro for the adress of the status register, at which Bit7 is the GIE bit*/
#define SREG			*((volatile uint8 *) 0x5F)
#define SREG_I			7u


#endif