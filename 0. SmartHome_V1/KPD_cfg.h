/*****************************************************************/
/*****************************************************************/
/****************	Authour: Ibrahim Saber	**********************/
/****************	File: KPD_cfg.h		**********************/
/****************	Version: 1.00	        **********************/
/*****************************************************************/
/*****************************************************************/

#ifndef KPD_CFG_H_
#define KPD_CFG_H_

/*This to determine how many switches in the keypad, in terms of rows & columns*/
#define KPD_u8COL_NUM			4u
#define KPD_u8ROW_NUM			4u


/*hardware connection on Kit of rows*/
#define KPD_u8ROW_PORT			DIO_u8PORTB
#define KPD_u8ROW1_PIN			DIO_u8PIN4
#define KPD_u8ROW2_PIN			DIO_u8PIN5
#define KPD_u8ROW3_PIN			DIO_u8PIN6
#define KPD_u8ROW4_PIN			DIO_u8PIN7



/*hardware connection on Kit of columns*/
#define KPD_u8COL_PORT			DIO_u8PORTD
#define KPD_u8COL1_PIN			DIO_u8PIN2
#define KPD_u8COL2_PIN			DIO_u8PIN3
#define KPD_u8COL3_PIN			DIO_u8PIN4
#define KPD_u8COL4_PIN			DIO_u8PIN5

/*The corresponding values of the keys*/
#define KPD_u8BUTTON_ARR		{{1,2,3,'-'}, {4,5,6,'*'}, {7,8,9,'/'}, {'R',0,'=','+'}} /*The values of the keypad, may change according to the app*/


/*This to configure the return value, if there is no pressed key*/
#define KPD_u8NO_PRESSED_KEY_VAL		0xff

#endif
