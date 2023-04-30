/**
 * @brief 		this is a semi-smart home using AVR atmega32
 * @author		Ibrahim Saber.
 * @version		1.0
 * @date		30-4-2023
 * @details		The project includes the following hardware:
 * 													1- AVR atmega32 microcontroller.
 * 													2- LM016L LCD 16*2.
 * 													3- LM35 temperature sensor.
 * 													4- LDR.
 * 													5- Keypad.
 * 													6- 7-Segment Display.
 * 													8- Buzzer.
 * 													9- DC Motor.
 * 													10- LEDs.
 * 				- it has a login page that asks the user to enter an ID, and password, checks if the password
 * 				  checks if the password == the ID entered but in reverse it logs the user in.
 *
 * 				- if not the 7segment already showing 3, refers to the number of attempts available, with each
 * 				  wrong trial the 7segment is decremented, a beep sound outputs from the buzzer and the user
 * 				  is asked to enter the credentials again.
 *
 * 				- after 3 wrong trials user is blocked and system shuts down.
 *
 * 				- if the login is successful, the user is directed to the dashboard, showing the current temp.
 * 				   the state of the fan and how many leds are on at the moment.
 *
 */


#include "STD_TYPES.h"
#include "defines.h"
#include <util/delay.h>

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"
#include "ADC_Interface.h"

#include "CLCD_interface.h"
#include "KPD_interface.h"
#include "SSD_interface.h"
#include "DCMOTOR_interface.h"
#include "LM35_interface.h"


void WelcomeScreen(void);
void LoginHandler(void);
void Dashboard(void);
void FanControl(void);
void LightsControl(void);
void ShutDown(void);


SSD_T SSD = {ETA_KIT, DIO_u8PORTC, DIO_u8PIN0, DIO_u8PORTC, DIO_u8PIN7};
const SSD_T* ptrToSSD = &SSD;



uint8 Local_u8AttemptsLeft = 3;		/*to be passed to the SSD function to show number of trials*/


void main(void)
{

	PORT_voidInit();
	ADC_voidInit();
	CLCD_voidInit();
	EXTI_voidInitInt2();

	EXTI_u8SetCallBack(EXTI_u8INT2, &ShutDown);

	GIE_voidEnableGlobal();


	WelcomeScreen();

	LoginHandler();


	while(1)
	{
		FanControl();
		LightsControl();
	}

}




void WelcomeScreen(void)
{
	CLCD_voidGoToXY(2,0);
	CLCD_u8SendString("Welcome Home");
	_delay_ms(1400);
	CLCD_voidSendCmd(1);

}




void LoginHandler(void)
{

	uint8 Local_u8UserArr[4];			/*to containg the user numbers and make it easy to compare it with password later on*/
	uint8 Local_u8PasswordArr[4];
	uint8 Local_u8Itterator = 0;
	uint8 Local_u8PressedKey = 0xff;

	/*user id screen*/
	CLCD_u8SendString("Enter ID: ");


	CLCD_voidGoToXY(0,1);

	for (Local_u8Itterator = 0; Local_u8Itterator < 4; Local_u8Itterator++)
	{
		while (Local_u8PressedKey == 0xff)
		{
			Local_u8PressedKey = KPD_u8GetPressedKey();
		}

		Local_u8UserArr[Local_u8Itterator] = Local_u8PressedKey;

		CLCD_voidSendNumber(Local_u8PressedKey);

		Local_u8PressedKey = 0xff;
	}

	CLCD_voidSendCmd(1);

	/*Turnning on the SSD and sending the initial number of trials which is three*/
	SSD_u8SSD_OFF(ptrToSSD);
	SSD_u8SetNumber(ptrToSSD, Local_u8AttemptsLeft);

	/*Password screen*/
	CLCD_u8SendString("Enter Password: ");

	CLCD_voidGoToXY(0,1);

	for (Local_u8Itterator = 0; Local_u8Itterator < 4; Local_u8Itterator++)
		{
			while (Local_u8PressedKey == 0xff)
			{
				Local_u8PressedKey = KPD_u8GetPressedKey();
			}

			Local_u8PasswordArr[Local_u8Itterator] = Local_u8PressedKey;

			CLCD_voidSendNumber(Local_u8PressedKey);
			_delay_ms(100);
			CLCD_voidGoToXY(Local_u8Itterator, 1);
			CLCD_voidSendData('*');

			Local_u8PressedKey = 0xff;
		}


		if( (Local_u8PasswordArr[0] == Local_u8UserArr[3]) && (Local_u8PasswordArr[1] == Local_u8UserArr[2]) && (Local_u8PasswordArr[2] == Local_u8UserArr[1]) && (Local_u8PasswordArr[3] == Local_u8UserArr[0]))
		{
			CLCD_voidSendCmd(1);
			Dashboard();
		}

		else
		{
			CLCD_voidSendCmd(1);

			CLCD_u8SendString("Wrong ID/Pass");
			CLCD_voidGoToXY(0,1);
			CLCD_u8SendString("Try again!");

			DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN0,DIO_u8PIN_HIGH);
			_delay_ms(200);
			DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN0,DIO_u8PIN_LOW);

			Local_u8AttemptsLeft--;

			SSD_u8SetNumber(ptrToSSD, Local_u8AttemptsLeft);

			if(Local_u8AttemptsLeft == 0)
			{
				CLCD_voidSendCmd(1);
				CLCD_voidGoToXY(1,0);
				CLCD_u8SendString("Unaouthorized");
				CLCD_voidGoToXY(6,1);
				CLCD_u8SendString("Login");
				_delay_ms(1400);

				CLCD_voidSendCmd(1);
				CLCD_u8SendString("Shutting Down");
				CLCD_voidSendData('.');
				_delay_ms(450);
				CLCD_voidSendData('.');
				_delay_ms(450);
				CLCD_voidSendData('.');
			}

			else
			{
				CLCD_voidSendCmd(1);
				LoginHandler();
			}


		}









}







void FanControl(void)
{
	uint8 Local_u8DigitalReading;
	uint8 Local_u8Tempereature;

	ADC_u8StartConversionSynch(ADC_SINGLE_ENDED_CH7, (uint16*)&Local_u8DigitalReading);

	Local_u8Tempereature = LM35_u8GetTempreature(Local_u8DigitalReading);

	CLCD_voidGoToXY(6,0);
	CLCD_voidSendNumber(Local_u8Tempereature);

	if (Local_u8Tempereature > 35)
	{
		DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN1, DIO_u8PIN_HIGH); /*coil of the relay activated so fan is on*/
		CLCD_voidGoToXY(15,0);
		CLCD_voidSendData('M');
	}

	else if (Local_u8Tempereature < 30)
	{
		DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN1, DIO_u8PIN_LOW); /*coil of the relay activated so fan is off*/
		CLCD_voidGoToXY(15,0);
		CLCD_voidSendData(' ');
	}
}




void LightsControl(void)
{

	uint8 Local_u8LEDsNum;
	uint8 Local_u8DigitalReading;

	/*if unclear, refer to the proteus -> 34_SemiSmartHome_v1*/
	DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN7, DIO_u8PIN_HIGH); /*closing the SSD by sending HIGH to the COM Cathode*/
	DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN6, DIO_u8PIN_LOW);  /*Activating LEDs by sending low to the COM cathode*/

	ADC_u8StartConversionSynch(ADC_SINGLE_ENDED_CH0, (uint16*)&Local_u8DigitalReading);

	if (Local_u8DigitalReading < 20)
	{
		DIO_u8SetPortValue(DIO_u8PORTC,-1);
		Local_u8LEDsNum = 7;
	}

	else if((Local_u8DigitalReading > 20) && (Local_u8DigitalReading < 40))
	{
		DIO_u8SetPortValue(DIO_u8PORTC, 0b11111110);
		Local_u8LEDsNum = 6;
	}

	else if((Local_u8DigitalReading > 50) && (Local_u8DigitalReading < 60))
	{
		DIO_u8SetPortValue(DIO_u8PORTC, 0b11111100);
		Local_u8LEDsNum = 5;
	}

	else if((Local_u8DigitalReading > 60) && (Local_u8DigitalReading < 70))
	{
		DIO_u8SetPortValue(DIO_u8PORTC, 0b11111000);
		Local_u8LEDsNum = 4;
	}

	else if((Local_u8DigitalReading > 70) && (Local_u8DigitalReading < 80))
	{
		DIO_u8SetPortValue(DIO_u8PORTC, 0b11110000);
		Local_u8LEDsNum = 3;
	}

	else if((Local_u8DigitalReading > 80) && (Local_u8DigitalReading < 90))
	{
		DIO_u8SetPortValue(DIO_u8PORTC, 0b11100000);
		Local_u8LEDsNum = 2;
	}

	else
	{
		DIO_u8SetPortValue(DIO_u8PORTC, 0b10000000);
		Local_u8LEDsNum = 0;
	}

	CLCD_voidGoToXY(6,1);
	CLCD_voidSendNumber(Local_u8LEDsNum);
}

void Dashboard(void)
{
	CLCD_u8SendString("Temp:   'C");

	CLCD_voidGoToXY(0,1);

	CLCD_u8SendString("LEDs: ");

}

void ShutDown(void)
{


	CLCD_voidSendCmd(1);
	CLCD_voidGoToXY(4,0);
	CLCD_u8SendString("Good Bye");
	_delay_ms(1500);

	CLCD_voidSendCmd(1);

	DIO_u8SetPortDirection(DIO_u8PORTA, DIO_u8PIN_INPUT);
	DIO_u8SetPortDirection(DIO_u8PORTB, DIO_u8PIN_INPUT);
	DIO_u8SetPortDirection(DIO_u8PORTC, DIO_u8PIN_INPUT);
	DIO_u8SetPortDirection(DIO_u8PORTD, DIO_u8PIN_INPUT);

	DIO_u8SetPortValue(DIO_u8PORTA, 0xff);
	DIO_u8SetPortValue(DIO_u8PORTB, 0);
	DIO_u8SetPortValue(DIO_u8PORTC, 0);
	DIO_u8SetPortValue(DIO_u8PORTD, 0);
}







