/*****************************************************************/
/*****************************************************************/
/****************	Author: Ibrahim Saber	**********************/
/****************	File: CLCD_program.c	**********************/
/****************	Version: 1.00	        **********************/
/*****************************************************************/
/*****************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"
#include <util/delay.h>

#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_prv.h"
#include "CLCD_cfg.h"


static void voidSendEnablePulse(void)
{
	/*Send enable pulse*/
		DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_HIGH);
		_delay_ms(2);
		DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_LOW);
}


static void voidSetLCDHalfDataPort(uint8 Copy_u8Nipple)
{
	DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_D4_PIN, GET_BIT(Copy_u8Nipple,0));
	DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_D5_PIN, GET_BIT(Copy_u8Nipple,1));
	DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_D6_PIN, GET_BIT(Copy_u8Nipple,2));
	DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_D7_PIN, GET_BIT(Copy_u8Nipple,3));
}

void CLCD_voidSendCmd(uint8 Copy_u8Cmd)
{

	/*Set RS pin to low for command mode*/
	DIO_u8SetPinValue(DIO_u8PORTA, CLCD_RS_PIN, DIO_u8PIN_LOW);

#if CLCD_RW_CTRL_EN == ENABLED
	/*Set RW pin to LOW for write mode*/
	DIO_u8SetPinValue(DIO_u8PORTA, CLCD_RW_PIN, DIO_u8PIN_LOW);
#endif

#if CLCD_OP_MODE == EIGHT_BIT_MODE
	/*Send The command on data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT, Copy_u8Cmd);
	CLCD_voidSendEnablePulse();

#elif CLCD_OP_MODE == FOUR_BIT_MODE
	voidSetLCDHalfDataPort(Copy_u8Cmd >> 4); /*Send the 4 most bits to the LCD*/
	voidSendEnablePulse();

	voidSetLCDHalfDataPort(Copy_u8Cmd);		/*Send the 4 least bits to the LCD*/
	voidSendEnablePulse();

#endif

}



void CLCD_voidSendData(uint8 Copy_u8Data)
{

	/*Set RS pin to HIGH for data mode*/
	DIO_u8SetPinValue(DIO_u8PORTA, CLCD_RS_PIN, DIO_u8PIN_HIGH);

	#if CLCD_RW_CTRL_EN == ENABLED
	/*Set RW pin to LOW for write mode*/
	DIO_u8SetPinValue(DIO_u8PORTA, CLCD_RW_PIN, DIO_u8PIN_LOW);
	#endif

#if CLCD_OP_MODE == EIGHT_BIT_MODE
	/*Send The Data on data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT, Copy_u8Data);
	CLCD_voidSendEnablePulse();

#elif CLCD_OP_MODE == FOUR_BIT_MODE
	voidSetLCDHalfDataPort(Copy_u8Data >> 4);
	voidSendEnablePulse();

	voidSetLCDHalfDataPort(Copy_u8Data);
	voidSendEnablePulse();

#endif


}


void CLCD_voidInit(void)
{
	/*wait for more than 30ms after power is on*/
	_delay_ms(40);

	/*Function Set command: 2 lines, 5*7 font size*/
#if CLCD_OP_MODE == EIGHT_BIT_MODE
	CLCD_voidSendCmd(0b00111000);

#elif CLCD_OP_MODE == FOUR_BIT_MODE
	voidSetLCDHalfDataPort(0b0010);
	voidSendEnablePulse();
	voidSetLCDHalfDataPort(0b0010);
	voidSendEnablePulse();
	voidSetLCDHalfDataPort(0b1000);
	voidSendEnablePulse();

#endif
	/*we don't need to make another delay, as CLCD_voidSendCmd have 2ms delay*/

	/*Display ON/OFF control: Display enable, Cursor and blink disable*/
	CLCD_voidSendCmd(0b00001100);

	/*Clearing The Display*/
	CLCD_voidSendCmd(1);

}


uint8 CLCD_u8SendString(const char* Copy_chString)
{
	uint8 Local_u8ErrorState = OK;
	if (Copy_chString != NULL)
	{
		uint8 Local_u8Itterator = 0u;
		while (Copy_chString[Local_u8Itterator] != '\0')
		{
			CLCD_voidSendData(Copy_chString[Local_u8Itterator]);
			Local_u8Itterator++;
		}
	}

	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}


	return Local_u8ErrorState;
}


void CLCD_voidSendNumber(sint32 Copy_s32Number)
{
/*
		sint32 Local_s32Digits = 1;
	    sint32 Local_s32Holder = Copy_s32Number;

	    if (Copy_s32Number == 0)
	    {
	    	CLCD_voidSendData(48); //ASCII of Zero = 48
	    	return;
	    }

	    else if(Copy_s32Number < 0)
	    {
	    	CLCD_voidSendData(45); //ASCII of minus sign = 45
	    	Copy_s32Number *= -1;
	    }

	    while (Local_s32Holder != 0)
	    {
	        Local_s32Holder /= 10;
	        Local_s32Digits *= 10;
	    }

	    Local_s32Digits /= 10;

	    while (Local_s32Digits != 0)
	    {
	        CLCD_voidSendData(((Copy_s32Number / Local_s32Digits) % 10) + '0');
	        Local_s32Digits /= 10;
	    }

*/
	    /*Another Implementation for the same function*/


	    char Local_chNumberArr[10];
	    uint8 Local_u8RightDigit;
	    uint8 Local_u8Counter1 = 0;
	    sint8 Local_s8Counter2;

	    if (Copy_s32Number == 0)
	    {
	    	CLCD_voidSendData('0');
	    	return;
	    }

	    else if (Copy_s32Number < 0)
	    {
	    	CLCD_voidSendData('-');
	    	Copy_s32Number *= -1;
	    }

	    while (Copy_s32Number != 0)
	    {
	    	Local_u8RightDigit = Copy_s32Number % 10;		//Extracts the right most digit
	    	Copy_s32Number /= 10;
	    	Local_chNumberArr[Local_u8Counter1] = Local_u8RightDigit + '0';		//Store that dig in array
	    	Local_u8Counter1++;
	    }

	    for (Local_s8Counter2 = Local_u8Counter1 - 1; Local_s8Counter2 >= 0; Local_s8Counter2--)
	    {
	    	CLCD_voidSendData(Local_chNumberArr[Local_s8Counter2]);
	    }

}


void CLCD_voidGoToXY(uint8 Copy_u8XPos, uint8 Copy_u8YPos)
{
	uint8 Local_u8DDRamAdd;

	if (Copy_u8YPos == 0u)
	{
		Local_u8DDRamAdd = Copy_u8XPos;
	}

	else if (Copy_u8YPos == 1u)
	{
		Local_u8DDRamAdd = 0x40 + Copy_u8XPos;
	}

	/*Set bit 7, for setting DDRAM address command*/
	SET_BIT(Local_u8DDRamAdd, 7);

	CLCD_voidSendCmd(Local_u8DDRamAdd);
}

void CLCD_voidSendSpecialChar(uint8 *Copy_u8Pattern, uint8 Copy_u8PatternNumber, uint8 Copy_u8XPos, uint8 Copy_u8YPos)
{
	uint8 Local_u8CGRAMAdrs = Copy_u8PatternNumber * 8u;
	uint8 Local_u8LoopCounter;

	/*Set bit number6, for Set_Address of CG command from datasheet*/
	SET_BIT(Local_u8CGRAMAdrs, 6);

	/*select the address in CGRAM*/
	CLCD_voidSendCmd(Local_u8CGRAMAdrs);

	/*Write the patter into CGRAM*/
	for (Local_u8LoopCounter = 0; Local_u8LoopCounter < 8u; Local_u8LoopCounter++)
	{
		CLCD_voidSendData(Copy_u8Pattern[Local_u8LoopCounter]);
	}

	/*back to DDRAM, to display the patterns*/
	CLCD_voidGoToXY(Copy_u8XPos, Copy_u8YPos);

	/*Display the pattern written inside the CGRAM*/
	CLCD_voidSendData(Copy_u8PatternNumber);

}

void CLCD_voidSendBinary(sint32 Copy_s32DecimalNumber)
{
	uint8 Local_u8DigitsArr[14];
	sint8 Local_s8DigitIndex;

	for (Local_s8DigitIndex = 0; Local_s8DigitIndex < 14; Local_s8DigitIndex++)
	{
		Local_u8DigitsArr[Local_s8DigitIndex] = GET_BIT(Copy_s32DecimalNumber, Local_s8DigitIndex);
	}

	CLCD_voidSendNumber(Copy_s32DecimalNumber);
	CLCD_u8SendString(" to Binary:");
	CLCD_voidGoToXY(0,1);
	CLCD_u8SendString("0b");

	for (Local_s8DigitIndex = 13; Local_s8DigitIndex >= 0; Local_s8DigitIndex--)
	{
		CLCD_voidSendNumber(Local_u8DigitsArr[Local_s8DigitIndex]);
	}


}


void CLCD_voidSendHex(sint32 Copy_s32DecimalNumber)
{
		uint8 Local_u8DigitsArr[14];
		sint8 Local_s8DigitIndex;
		sint32 Local_s8Holder = Copy_s32DecimalNumber;

		for (Local_s8DigitIndex = 13; Local_s8DigitIndex >= 0;)
		{





			if (Copy_s32DecimalNumber % 16 == Copy_s32DecimalNumber)
			{
				Local_u8DigitsArr[Local_s8DigitIndex] = 0;
				Local_s8DigitIndex--;
				Copy_s32DecimalNumber /= 16;
			}

			if ((Copy_s32DecimalNumber / 16) < 16)
			{
				Local_u8DigitsArr[Local_s8DigitIndex] = Copy_s32DecimalNumber % 16;
				Local_u8DigitsArr[Local_s8DigitIndex - 1] = Copy_s32DecimalNumber / 16;
				Local_s8DigitIndex-= 2;
				Copy_s32DecimalNumber /= 16;
			}

			else if ((Copy_s32DecimalNumber / 16) > 16)
			{
				Local_u8DigitsArr[Local_s8DigitIndex] = Copy_s32DecimalNumber % 16;
				Copy_s32DecimalNumber /= 16;
				Local_s8DigitIndex--;
			}
		}

		CLCD_voidSendNumber(Local_s8Holder);
		CLCD_u8SendString(" to Hex:");
		CLCD_voidGoToXY(0,1);
		CLCD_u8SendString("0x");

		for (Local_s8DigitIndex = 0; Local_s8DigitIndex < 14; Local_s8DigitIndex++)
		{
			if (Local_u8DigitsArr[Local_s8DigitIndex] < 10)
			{
				CLCD_voidSendNumber(Local_u8DigitsArr[Local_s8DigitIndex]);
			}

			else
			{
				switch (Local_u8DigitsArr[Local_s8DigitIndex])
				{
					case 10: CLCD_voidSendData('A');	break;
					case 11: CLCD_voidSendData('B');	break;
					case 12: CLCD_voidSendData('C');	break;
					case 13: CLCD_voidSendData('D');	break;
					case 14: CLCD_voidSendData('E');	break;
					case 15: CLCD_voidSendData('F');	break;
				}
			}
		}


}



