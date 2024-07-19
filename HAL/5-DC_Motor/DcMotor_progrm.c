/*
 * DcMotor_prog.c
 *
 *  Created on: Jul 18, 2024
 *      Author: Osama
 */

#include "STD_TYPES.h"
#include "ERROR_TYPES.h"

#include "DIO_interface.h"

#include "DcMotor_private.h"
#include "DcMotor_interface.h"
#include "DcMotor_cfg.h"


uint8 DcMotor_u8RotateCW(const DcMotor_config_t *DcMotorObj)
{
	uint8 Local_u8ErrorState = OK;

	if(DcMotorObj != NULL)
	{
		DIO_u8SetPinValue(DcMotorObj->Port, DcMotorObj->Pin2, DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DcMotorObj->Port, DcMotorObj->Pin1, DIO_u8PIN_HIGH);
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}

uint8 DcMotor_u8RotateCCW(const DcMotor_config_t *DcMotorObj)
{
	uint8 Local_u8ErrorState = OK;

	if(DcMotorObj != NULL)
	{
		DIO_u8SetPinValue(DcMotorObj->Port, DcMotorObj->Pin1, DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DcMotorObj->Port, DcMotorObj->Pin2, DIO_u8PIN_HIGH);
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}

uint8 DcMotor_u8Stop(const DcMotor_config_t *DcMotorObj)
{
	uint8 Local_u8ErrorState = OK;

	if(DcMotorObj != NULL)
	{
		DIO_u8SetPinValue(DcMotorObj->Port, DcMotorObj->Pin1, DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DcMotorObj->Port, DcMotorObj->Pin2, DIO_u8PIN_LOW);
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}
