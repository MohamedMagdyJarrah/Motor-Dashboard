/*****************************************************************/
/*****************************************************************/
/*****************		Author: Mohamed Magdy	******************/
/*****************		Layer:  HAL				******************/
/*****************		SWC:    STEPPER MOTOR	******************/
/*****************		Version:1.00 			******************/
/*****************************************************************/
/*****************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO Driver/DIO_interface.h"
#include <util/delay.h>
#include "STEPPER_config.h"
#include "STEPPER_interface.h"
#include "STEPPER_private.h"

void STEPPER_voidClockwise(f32 Copy_u8Angle)
{
	u32 Local_u32No_Steps;
	Local_u32No_Steps = Copy_u8Angle / 0.175;
	u16 Local_u16Iterations = Local_u32No_Steps /4;
	u16 Local_u16Counter = 0;
	for (Local_u16Counter = 0 ; Local_u16Counter < Local_u16Iterations ; Local_u16Counter++)
	{
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN0,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN1,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN2,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN3,DIO_u8PIN_HIGH);
		_delay_ms(2);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN0,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN2,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN3,DIO_u8PIN_HIGH);
		_delay_ms(2);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN0,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN1,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN2,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN3,DIO_u8PIN_HIGH);
		_delay_ms(2);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN0,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN1,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN2,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN3,DIO_u8PIN_LOW);
		_delay_ms(2);
	}
}

void STEPPER_voidAntiClockwise(f32 Copy_u8Angle)
{
	u32 Local_u32No_Steps;
	Local_u32No_Steps = Copy_u8Angle / 0.175;
	u16 Local_u16Iterations = Local_u32No_Steps /4;
	u16 Local_u16Counter = 0;
	for (Local_u16Counter = 0 ; Local_u16Counter < Local_u16Iterations ; Local_u16Counter++)
	{
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN3,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN2,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN1,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN0,DIO_u8PIN_HIGH);
		_delay_ms(2);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN3,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN2,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN1,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN0,DIO_u8PIN_HIGH);
		_delay_ms(2);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN3,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN2,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN0,DIO_u8PIN_HIGH);
		_delay_ms(2);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN3,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN2,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN1,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN0,DIO_u8PIN_LOW);
		_delay_ms(2);
	}
}

void STEPPER_voidStop(void)
{
	DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN0,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PIN3,DIO_u8PIN_LOW);
}
