/*****************************************************************/
/*****************************************************************/
/****************	Authour: Ibrahim Saber	**********************/
/****************	File: SSD_prog.c		**********************/
/****************	Version: 1.00	        **********************/
/*****************************************************************/
/*****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"

#include "DIO_interface.h"

#include "SSD_prv.h"
#include "SSD_interface.h"










uint8 ssd[10] = {0b0111111, 0b0000110, 0b1011011, 0b1001111, 0b1100110, 0b1101101, 0b1111101, 0b0000111, 0b1111111, 0b1101111};



uint8 SSD_u8SSD_ON(const SSD_T* Copy_pSSD)
{
	uint8 Local_u8ErrorState = OK;

	if (Copy_pSSD != NULL)
	{
		if ((Copy_pSSD -> Type) == ANODE)
		{
			DIO_u8SetPinValue(Copy_pSSD->Enable_PORT, Copy_pSSD->Enable_Pin, DIO_u8PIN_HIGH);
		}

		else if ((Copy_pSSD -> Type) == CATHODE)
		{

			DIO_u8SetPinValue(Copy_pSSD->Enable_PORT, Copy_pSSD->Enable_Pin, DIO_u8PIN_LOW);

		}

		else if ((Copy_pSSD -> Type) == ETA_KIT)
		{

			DIO_u8SetPinValue(Copy_pSSD->Enable_PORT, Copy_pSSD->Enable_Pin, DIO_u8PIN_HIGH);
		}


		Local_u8ErrorState = OK;
	}

	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}


uint8 SSD_u8SSD_OFF(const SSD_T* Copy_pSSD)
{
	uint8 Local_u8ErrorState = OK;

	if (Copy_pSSD != NULL)
	{
		if ((Copy_pSSD -> Type) == ANODE)
		{
			DIO_u8SetPinValue(Copy_pSSD->Enable_PORT, Copy_pSSD->Enable_Pin, DIO_u8PIN_LOW);
		}

		else if ((Copy_pSSD -> Type) == CATHODE)
		{

			DIO_u8SetPinValue(Copy_pSSD->Enable_PORT, Copy_pSSD->Enable_Pin, DIO_u8PIN_HIGH);

		}

		else if ((Copy_pSSD -> Type) == ETA_KIT)
		{

			DIO_u8SetPinValue(Copy_pSSD->Enable_PORT, Copy_pSSD->Enable_Pin, DIO_u8PIN_LOW);
		}


		Local_u8ErrorState = OK;
	}

	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}


	return Local_u8ErrorState;
}




uint8 SSD_u8SetNumber(const SSD_T* Copy_pSSD, uint8 Copy_u8Number)
{
	uint8 Local_u8ErrorState = OK;

	if(Copy_pSSD != NULL)
	{
		if ((Copy_pSSD -> Type) == ANODE)
		{
			DIO_u8SetPinValue((Copy_pSSD->PORT) , (Copy_pSSD->LEDA ) , ~(GET_BIT(ssd[Copy_u8Number], 0)));
			DIO_u8SetPinValue((Copy_pSSD->PORT) , (Copy_pSSD->LEDA+1), ~(GET_BIT(ssd[Copy_u8Number], 1)));
			DIO_u8SetPinValue((Copy_pSSD->PORT) , (Copy_pSSD->LEDA+2), ~(GET_BIT(ssd[Copy_u8Number], 2)));
			DIO_u8SetPinValue((Copy_pSSD->PORT) , (Copy_pSSD->LEDA+3), ~(GET_BIT(ssd[Copy_u8Number], 3)));
			DIO_u8SetPinValue((Copy_pSSD->PORT) , (Copy_pSSD->LEDA+4), ~(GET_BIT(ssd[Copy_u8Number], 4)));
			DIO_u8SetPinValue((Copy_pSSD->PORT) , (Copy_pSSD->LEDA+5), ~(GET_BIT(ssd[Copy_u8Number], 5)));
			DIO_u8SetPinValue((Copy_pSSD->PORT) , (Copy_pSSD->LEDA+6), ~(GET_BIT(ssd[Copy_u8Number], 6)));
		}

		else if ((Copy_pSSD -> Type) == CATHODE)
		{
			DIO_u8SetPinValue((Copy_pSSD->PORT) , (Copy_pSSD->LEDA ) , (GET_BIT(ssd[Copy_u8Number], 0)));
			DIO_u8SetPinValue((Copy_pSSD->PORT) , (Copy_pSSD->LEDA+1), (GET_BIT(ssd[Copy_u8Number], 1)));
			DIO_u8SetPinValue((Copy_pSSD->PORT) , (Copy_pSSD->LEDA+2), (GET_BIT(ssd[Copy_u8Number], 2)));
			DIO_u8SetPinValue((Copy_pSSD->PORT) , (Copy_pSSD->LEDA+3), (GET_BIT(ssd[Copy_u8Number], 3)));
			DIO_u8SetPinValue((Copy_pSSD->PORT) , (Copy_pSSD->LEDA+4), (GET_BIT(ssd[Copy_u8Number], 4)));
			DIO_u8SetPinValue((Copy_pSSD->PORT) , (Copy_pSSD->LEDA+5), (GET_BIT(ssd[Copy_u8Number], 5)));
			DIO_u8SetPinValue((Copy_pSSD->PORT) , (Copy_pSSD->LEDA+6), (GET_BIT(ssd[Copy_u8Number], 6)));
		}

		else if ((Copy_pSSD -> Type) == ETA_KIT)
		{
			DIO_u8SetPinValue((Copy_pSSD->PORT) , (Copy_pSSD->LEDA ) , (GET_BIT(ssd[Copy_u8Number], 0)));
			DIO_u8SetPinValue((Copy_pSSD->PORT) , (Copy_pSSD->LEDA+1), (GET_BIT(ssd[Copy_u8Number], 1)));
			DIO_u8SetPinValue((Copy_pSSD->PORT) , (Copy_pSSD->LEDA+2), (GET_BIT(ssd[Copy_u8Number], 2)));
			DIO_u8SetPinValue((Copy_pSSD->PORT) , (Copy_pSSD->LEDA+3), (GET_BIT(ssd[Copy_u8Number], 3)));
			DIO_u8SetPinValue((Copy_pSSD->PORT) , (Copy_pSSD->LEDA+4), (GET_BIT(ssd[Copy_u8Number], 4)));
			DIO_u8SetPinValue((Copy_pSSD->PORT) , (Copy_pSSD->LEDA+5), (GET_BIT(ssd[Copy_u8Number], 5)));
			DIO_u8SetPinValue((Copy_pSSD->PORT) , (Copy_pSSD->LEDA+6), (GET_BIT(ssd[Copy_u8Number], 6)));
		}


		Local_u8ErrorState = OK;
	}

	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}





