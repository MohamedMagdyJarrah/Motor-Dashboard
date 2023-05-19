/*****************************************************************/
/*****************************************************************/
/*****************		Author: Mohamed Magdy	******************/
/*****************		Layer:  HAL				******************/
/*****************		SWC:    DC MOTOR		******************/
/*****************		Version:1.00 			******************/
/*****************************************************************/
/*****************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO Driver/DIO_interface.h"
#include "DCMOTOR_config.h"
#include "DCMOTOR_interface.h"
#include "DCMOTOR_private.h"


void DCMOTOR_voidClockWise(void)
{
	DIO_u8SetPinValue(DCMOTOR_PORT,DCMOTOR_M1_PIN,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DCMOTOR_PORT,DCMOTOR_M2_PIN,DIO_u8PIN_LOW);
}

void DCMOTOR_voidAntiClockWise(void)
{
	DIO_u8SetPinValue(DCMOTOR_PORT,DCMOTOR_M1_PIN,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DCMOTOR_PORT,DCMOTOR_M2_PIN,DIO_u8PIN_HIGH);
}

void DCMOTOR_voidStop(void)
{
	DIO_u8SetPinValue(DCMOTOR_PORT,DCMOTOR_M1_PIN,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DCMOTOR_PORT,DCMOTOR_M2_PIN,DIO_u8PIN_LOW);
}
