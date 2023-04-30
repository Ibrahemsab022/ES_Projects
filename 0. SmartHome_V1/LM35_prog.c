/**
 * @brief 	This file is used to implement LM35 getTemp Function.
 * @author	Ibrahim Saber
 * @version	1.0
 * @date 	29-4-2023
 */

#include "STD_TYPES.h"
#include "LM35_interface.h"

uint8 LM35_u8GetTempreature(uint8 Copy_u8DigitalReading)
{

	return ((uint8)(((uint32)Copy_u8DigitalReading * 500UL) / 256UL));

}
