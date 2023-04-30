/**
 * @brief		this file used to Implement the LDR function.
 * @author		Ibrahim Saber
 * @version		1.0
 * @date		29-4-2023
 */

#include "STD_TYPES.h"

#include "LDR_cfg.h"
#include "LDR_interface.h"


uint8 LDR_u8GetAnalogVolt(uint8 Copy_u8DigitalReading)
{
	uint8 Local_u8AnalogVolt;


	Local_u8AnalogVolt = (uint8) Copy_u8DigitalReading;


	return Local_u8AnalogVolt;


}
