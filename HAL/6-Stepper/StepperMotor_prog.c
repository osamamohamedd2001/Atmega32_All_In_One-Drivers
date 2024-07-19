/*
 * StepperMotor_prog.c
 *
 *  Created on: Jul 19, 2024
 *      Author: Osama
 */

#include "STD_TYPES.h"
#include "ERROR_TYPES.h"

#include <util/delay.h>

#include "DIO_interface.h"

#include "StepperMotor_cfg.h"
#include "StepperMotor_private.h"
#include "StepperMotor_interface.h"

uint8 StepperRotateCW(const Stepper_cfg_t* Obj, uint16 Copy_u16Angle)
{
	uint8 Local_u8ErrorState = OK;

    uint16 Local_u8Iterator;

	uint8 Local_u8CoilNumber;

	uint16 Local_u16Steps = (uint16)(((uint32)Copy_u16Angle * (uint32)STEPS_PER_REV) / (uint32)360);

	if(Obj != NULL)
	{
		if(Copy_u16Angle > 0u)
		{

			for(Local_u8Iterator = 0u; Local_u8Iterator < Local_u16Steps; Local_u8Iterator++)
			{

				Local_u8CoilNumber = Local_u8Iterator % 4u;

				switch(Local_u8CoilNumber)
				{
				case 0u:
					/* 1st coil activation */
					DIO_u8SetPinValue(Obj->Port, Obj->OrangeWirePin, DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Obj->Port, Obj->BlueWirePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Obj->Port, Obj->PinkWirePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Obj->Port, Obj->YellowWirePin, DIO_u8PIN_HIGH);
					_delay_us(1000);
					break;
				case 1u:
					/* 2nd coil activation */
					DIO_u8SetPinValue(Obj->Port, Obj->YellowWirePin, DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Obj->Port, Obj->BlueWirePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Obj->Port, Obj->PinkWirePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Obj->Port, Obj->OrangeWirePin, DIO_u8PIN_HIGH);
					_delay_us(1000);
					break;
				case 2u:
					/* 3rd coil activation */
					DIO_u8SetPinValue(Obj->Port, Obj->PinkWirePin, DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Obj->Port, Obj->BlueWirePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Obj->Port, Obj->YellowWirePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Obj->Port, Obj->OrangeWirePin, DIO_u8PIN_HIGH);
					_delay_us(1000);
					break;
				case 3u:
					/* 4th coil activation */
					DIO_u8SetPinValue(Obj->Port, Obj->BlueWirePin, DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Obj->Port, Obj->PinkWirePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Obj->Port, Obj->YellowWirePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Obj->Port, Obj->OrangeWirePin, DIO_u8PIN_HIGH);
					_delay_us(1000);
					break;
				}
			}
		}
		else
		{
			Local_u8ErrorState = NOT_OK;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}

uint8 StepperRotateCCW(const Stepper_cfg_t* Obj, uint16 Copy_u16Angle)
{
	uint8 Local_u8ErrorState = OK;

	uint16 Local_u8Iterator;

	uint16 Local_u16Steps = (uint16)(((uint32)Copy_u16Angle * (uint32)STEPS_PER_REV) / (uint32)360);

	if(Obj != NULL)
	{
		if(Copy_u16Angle > 0u)
		{

			for(Local_u8Iterator = 0u; Local_u8Iterator < Local_u16Steps; Local_u8Iterator++)
			{
				uint8 Local_u8CoilNumber;

				Local_u8CoilNumber = Local_u8Iterator % 4u;

				switch(Local_u8CoilNumber)
				{
				case 0u:
					/* 1st coil activation */
					DIO_u8SetPinValue(Obj->Port, Obj->BlueWirePin, DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Obj->Port, Obj->PinkWirePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Obj->Port, Obj->YellowWirePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Obj->Port, Obj->OrangeWirePin, DIO_u8PIN_HIGH);
					_delay_us(1000);
					break;
				case 1u:
					/* 2nd coil activation */
					DIO_u8SetPinValue(Obj->Port, Obj->PinkWirePin, DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Obj->Port, Obj->BlueWirePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Obj->Port, Obj->YellowWirePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Obj->Port, Obj->OrangeWirePin, DIO_u8PIN_HIGH);
					_delay_us(1000);
					break;
				case 2u:
					/* 3rd coil activation */
					DIO_u8SetPinValue(Obj->Port, Obj->YellowWirePin, DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Obj->Port, Obj->BlueWirePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Obj->Port, Obj->PinkWirePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Obj->Port, Obj->OrangeWirePin, DIO_u8PIN_HIGH);
					_delay_us(1000);
					break;
				case 3u:
					/* 4th coil activation */
					DIO_u8SetPinValue(Obj->Port, Obj->OrangeWirePin, DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Obj->Port, Obj->BlueWirePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Obj->Port, Obj->PinkWirePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Obj->Port, Obj->YellowWirePin, DIO_u8PIN_HIGH);
					_delay_us(1000);
					break;
				}
			}
		}
		else
		{
			Local_u8ErrorState = NOT_OK;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}
