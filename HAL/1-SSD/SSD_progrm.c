/*
 * SSD_progrm.c
 *
 *  Created on: Jul 10, 2024
 *      Author: Osama
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_TYPES.h"

#include <util/delay.h>

#include "DIO_interface.h"

#include "SSD_private.h"
#include "SSD_config.h"
#include "SSD_interface.h"


/* Array of values to represent numbers 0-9 on a common cathode seven-segment display */


/* Function to turn on the seven-segment display */
uint8 SSD_u8ON(const SSD_config_t *SSD_obj)
{
	uint8 Local_u8ErrorState = OK;

	if (SSD_obj != NULL)
	{
		if (SSD_obj->Type == COM_ANODE)
		{
			DIO_u8SetPinValue(SSD_obj->EnablePort, SSD_obj->EnablePin, DIO_u8PIN_HIGH);
		}
		else if (SSD_obj->Type == COM_CATHODE)
		{
			DIO_u8SetPinValue(SSD_obj->EnablePort, SSD_obj->EnablePin, DIO_u8PIN_LOW);
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

/* Function to turn off the seven-segment display */
uint8 SSD_u8OFF(const SSD_config_t *SSD_obj)
{
	uint8 Local_u8ErrorState = OK;

	if (SSD_obj != NULL)
	{
		if (SSD_obj->Type == COM_ANODE)
		{
			DIO_u8SetPinValue(SSD_obj->EnablePort, SSD_obj->EnablePin, DIO_u8PIN_LOW);
		}
		else if (SSD_obj->Type == COM_CATHODE)
		{
			DIO_u8SetPinValue(SSD_obj->EnablePort, SSD_obj->EnablePin, DIO_u8PIN_HIGH);
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

/* Function to display a number on the seven-segment display */
uint8 SSD_u8SetNumber(const SSD_config_t *SSD_obj, uint8 Copy_u8Number)
{
	uint8 Local_u8ErrorState = OK;
	uint8 Local_u8Iterator, Local_u8PinCounter;

	/* Defined with static keyword to save the satck memory */
	static uint8 SSD_NumbersArray[10] = {
			0x3F, // 0: a, b, c, d, e, f
			0x06, // 1: b, c
			0x5B, // 2: a, b, d, e, g
			0x4F, // 3: a, b, c, d, g
			0x66, // 4: b, c, f, g
			0x6D, // 5: a, c, d, f, g
			0x7D, // 6: a, c, d, e, f, g
			0x07, // 7: a, b, c
			0x7F, // 8: a, b, c, d, e, f, g
			0x6F  // 9: a, b, c, d, f, g
	};

	if (SSD_obj != NULL)
	{
		if (Copy_u8Number > 9)
		{
			return NOT_OK; // Return error if the number is out of range
		}

		Local_u8PinCounter = SSD_obj->StartPin;

		for (Local_u8Iterator = 0; Local_u8Iterator < 7; Local_u8Iterator++, Local_u8PinCounter++)
		{
			if (SSD_obj->Type == COM_CATHODE)
			{
				DIO_u8SetPinValue(SSD_obj->Port, Local_u8PinCounter, GET_BIT(SSD_NumbersArray[Copy_u8Number], Local_u8Iterator));
			}
			else if (SSD_obj->Type == COM_ANODE)
			{
				DIO_u8SetPinValue(SSD_obj->Port, Local_u8PinCounter, ~GET_BIT(SSD_NumbersArray[Copy_u8Number], Local_u8Iterator));
			}
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}
