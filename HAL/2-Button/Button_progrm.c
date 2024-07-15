/*
 * Button_progrm.c
 *
 *  Created on: Jul 15, 2024
 *      Author: Osama
 */

#include "STD_TYPES.h"
#include "ERROR_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>

#include "DIO_interface.h"

#include "Button_config.h"
#include "Button_interface.h"
#include "Button_private.h"


uint8 Button_u8Read(const Button_config_t* Button_Obj, uint8 *Copy_pu8State)
{
	uint8 Local_u8ErrorState = OK;

	if((Button_Obj != NULL) && (Copy_pu8State != NULL))
	{
		DIO_u8ReadPinValue(Button_Obj->Button_Port, Button_Obj->Button_Pin, Copy_pu8State);
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}

