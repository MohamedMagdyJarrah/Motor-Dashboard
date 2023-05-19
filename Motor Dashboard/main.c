
#include "LIB/STD_TYPES.h"
#include "MCAL/PORT Driver/PORT_interface.h"
#include "MCAL/DIO Driver/DIO_interface.h"
#include "HAL/CLCD Driver/CLCD_interface.h"
#include "HAL/KEYPAD Driver/KPD_interface.h"
#include "HAL/DC MOTOR Driver/DCMOTOR_interface.h"
#include "HAL/STEPPER MOTOR Driver/STEPPER_interface.h"
#include <util/delay.h>

void main(void)
{
	/*Initialization and Variables*/
	PORT_voidInit();
	CLCD_voidInit();
	u8 Local_u8PressedKey = 0xff; //Key is not pressed in the beginning
	u8 DcMotorState = 0; // 0 (Motor is Turned off)  -  1 (Motor is Turned on)
	u8 StepperState;
	u16 rotationAngle = 0;
	u8 anglePosition = 13;

	/*Hamoksha*/
	u8 Local_u8BodyGreeting[] = {0b00010100,0b00011110,0b00000101,0b00000100,0b00000100,0b00000100,0b00001010,0b00001010};

	/*Welcome Screen*/
	CLCD_u8GoToXY(0,3);
	CLCD_voidSendString("Welcome to");
	CLCD_u8GoToXY(1,1);
	CLCD_voidSendString("Motor Dashboard");
	CLCD_u8GoToXY(0,0);
	CLCD_voidSendData('o');
	CLCD_voidWriteSpecialCharacter(Local_u8BodyGreeting,1,1,0);
	_delay_ms(2000);

	CLCD_voidClearDisplay();


	while(1)
	{
		/*Options Screen*/
		CLCD_u8GoToXY(0,0);
		CLCD_voidSendString("DC-Stepper-Exit");
		CLCD_u8GoToXY(1,0);
		CLCD_voidSendString("Press (1,2,3)");

		/*Choosing Option*/
		do
		{
			Local_u8PressedKey = KPD_u8GetPressedKey();
		}while(Local_u8PressedKey == 0xff);

		/*Clear Screen*/
		CLCD_voidClearDisplay();

		switch(Local_u8PressedKey)
		{
		/*DC Motor*/
		case 1:
			CLCD_u8GoToXY(0,0);
			CLCD_voidSendString("Rotate C.W(1)");
			CLCD_u8GoToXY(1,0);
			CLCD_voidSendString("Rotate C.C.W(2)");

			do
			{
				Local_u8PressedKey = KPD_u8GetPressedKey();
			}while(Local_u8PressedKey == 0xff);

			/*Clear Screen*/
			CLCD_voidClearDisplay();

			switch(Local_u8PressedKey)
			{
			case 1:
				DCMOTOR_voidClockWise();
				DcMotorState = 1;
				while (DcMotorState == 1)
				{
					CLCD_u8GoToXY(0,0);
					CLCD_voidSendString("To Stop Press");
					CLCD_u8GoToXY(1,0);
					CLCD_voidSendString("any Key");

					do
					{
						Local_u8PressedKey = KPD_u8GetPressedKey();
					}while(Local_u8PressedKey == 0xff);

					DcMotorState = 0;
					DCMOTOR_voidStop();
				}
				break;
			case 2:
				DCMOTOR_voidAntiClockWise();
				DcMotorState = 1;
				while (DcMotorState == 1)
				{
					CLCD_u8GoToXY(0,0);
					CLCD_voidSendString("To Stop Press");
					CLCD_u8GoToXY(1,0);
					CLCD_voidSendString("any Key");

					do
					{
						Local_u8PressedKey = KPD_u8GetPressedKey();
					}while(Local_u8PressedKey == 0xff);

					DcMotorState = 0;
					DCMOTOR_voidStop();
				}
				break;
			default:
				CLCD_u8GoToXY(0,0);
				CLCD_voidSendString("Please Press");
				CLCD_u8GoToXY(1,5);
				CLCD_voidSendString("1 or 2");
				_delay_ms(2000);
			}
			break;
			/*Stepper Motor*/
			case 2:
				CLCD_u8GoToXY(0,0);
				CLCD_voidSendString("Rotate C.W(1)");
				CLCD_u8GoToXY(1,0);
				CLCD_voidSendString("Rotate C.C.W(2)");

				do
				{
					Local_u8PressedKey = KPD_u8GetPressedKey();
				}while(Local_u8PressedKey == 0xff);

				StepperState = Local_u8PressedKey;
				/*Clear Screen*/
				CLCD_voidClearDisplay();

				if(StepperState == 1 || StepperState == 2)
				{
					/*Choosing Angle of Rotation*/
					CLCD_u8GoToXY(0,0);
					CLCD_voidSendString("Select Angle:");

					do
					{
						Local_u8PressedKey = KPD_u8GetPressedKey();
					}while(Local_u8PressedKey == 0xff);

					while(Local_u8PressedKey != KPD_ENTER_BUTTON)
					{
						CLCD_voidWriteNumber(Local_u8PressedKey,0,anglePosition,READ_FROM_LEFT);
						anglePosition++;

						rotationAngle = rotationAngle*10 + Local_u8PressedKey;

						do
						{
							Local_u8PressedKey = KPD_u8GetPressedKey();
						}while(Local_u8PressedKey == 0xff);
					}
				}
				switch(StepperState)
				{

				case 1:
					STEPPER_voidClockwise(rotationAngle);
					CLCD_voidClearDisplay();
					CLCD_u8GoToXY(0,0);
					CLCD_voidSendString("Angle Reached..");
					_delay_ms(2000);
					break;
				case 2:
					STEPPER_voidAntiClockwise(rotationAngle);
					CLCD_voidClearDisplay();
					CLCD_u8GoToXY(0,0);
					CLCD_voidSendString("Angle Reached..");
					_delay_ms(2000);
					break;
				default:
					CLCD_u8GoToXY(0,0);
					CLCD_voidSendString("Please Press");
					CLCD_u8GoToXY(1,5);
					CLCD_voidSendString("1 or 2");
					_delay_ms(2000);
				}
				break;

				case 3:
					CLCD_u8GoToXY(0,0);
					CLCD_voidSendString("Thanks for using");
					CLCD_u8GoToXY(1,0);
					CLCD_voidSendString("Motor Dashboard");
					_delay_ms(2000);
					return;
					break;
		}
		rotationAngle = 0;
		anglePosition = 13;
		CLCD_voidClearDisplay();
	}
}
