/*****************************************************************/
/*****************************************************************/
/****************	Authour: Ibrahim Saber	**********************/
/****************	File: SSD_interface.h	**********************/
/****************	Version: 1.00	        **********************/
/*****************************************************************/
/*****************************************************************/


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_




/*Defining macros for the type of the SSD*/
#define ANODE		0u
#define CATHODE		1u
#define ETA_KIT		2u


typedef struct
{
	uint8 Type;
	uint8 PORT;
	uint8 LEDA;
	uint8 Enable_PORT;
	uint8 Enable_Pin;

}SSD_T;



uint8 SSD_u8SSD_ON(const SSD_T* Copy_pSSD);
uint8 SSD_u8SSD_OFF(const SSD_T* Copy_pSSD);
uint8 SSD_u8SetNumber(const SSD_T* Copy_pSSD, uint8 Copy_u8Number);



#endif
