/*****************************************************************/
/*****************************************************************/
/****************	Authour: Ibrahim Saber	**********************/
/****************	File: DCMOTOR_prog.c	**********************/
/****************	Version: 1.00	        **********************/
/*****************************************************************/
/*****************************************************************/

#include "STD_TYPES.h"
#include "defines.h"

#include "DIO_interface.h"


#include "DCMOTOR_interface.h"




uint8 DCMOTOR_u8RotateCW(const DCMOTOR_T* Copy_pDCMOTOR)
{
	uint8 Local_u8ErrorState = OK;

	if (Copy_pDCMOTOR != NULL)
	{
		Local_u8ErrorState = OK;

		DIO_u8SetPinValue(Copy_pDCMOTOR->PORT, Copy_pDCMOTOR->PIN1_4, DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Copy_pDCMOTOR->PORT, Copy_pDCMOTOR->PIN2_3, DIO_u8PIN_HIGH);
	}

	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}



uint8 DCMOTOR_u8RotateCCW(const DCMOTOR_T* Copy_pDCMOTOR)
{
	uint8 Local_u8ErrorState = OK;

	if (Copy_pDCMOTOR != NULL)
	{
		Local_u8ErrorState = OK;

		DIO_u8SetPinValue(Copy_pDCMOTOR->PORT, Copy_pDCMOTOR->PIN2_3, DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Copy_pDCMOTOR->PORT, Copy_pDCMOTOR->PIN1_4, DIO_u8PIN_HIGH);
	}

	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;

}



uint8 DCMOTOR_u8Stop(const DCMOTOR_T* Copy_pDCMOTOR)
{
	uint8 Local_u8ErrorState = OK;

	if (Copy_pDCMOTOR != NULL)
	{
		Local_u8ErrorState = OK;

		DIO_u8SetPinValue(Copy_pDCMOTOR->PORT, Copy_pDCMOTOR->PIN2_3, DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Copy_pDCMOTOR->PORT, Copy_pDCMOTOR->PIN1_4, DIO_u8PIN_LOW);
	}

	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;

}

