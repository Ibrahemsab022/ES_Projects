#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_reg.h"
#include "GIE_interface.h"

void  GIE_voidEnableGlobal(void)
{
	__asm__ volatile("SEI");			/*Assembly In-Line instruction to set the GIE_I bit*/
}


void GIE_voidDisbaleGlobal(void)
{
	__asm__ volatile("CLI");			/*Assembly In-Line instruction to clear the GIE_I bit*/
}
