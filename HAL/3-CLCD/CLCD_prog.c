#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_TYPES.h"

#include <util/delay.h>

#include "DIO_interface.h"

#include "CLCD_interface.h"
#include "CLCD_prv.h"
#include "CLCD_cfg.h"

#if CLCD_u8BIT_MODE == FOUR_BIT_MODE

static void voidSetHalfDataPort(uint8 Copy_u8Data)
{
	DIO_u8SetPinValue(CLCD_u8DATA_PORT, CLCD_u8D4_PIN, GET_BIT(Copy_u8Data,0));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT, CLCD_u8D5_PIN, GET_BIT(Copy_u8Data,1));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT, CLCD_u8D6_PIN, GET_BIT(Copy_u8Data,2));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT, CLCD_u8D7_PIN, GET_BIT(Copy_u8Data,3));
}

#endif

static void voidSendEnablePulse(void)
{
	/*Send enable pulse*/
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN, DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN, DIO_u8PIN_LOW);
}

static void voidSetCtrlPins(uint8 Copy_u8RsValue, uint8 Copy_u8RwValue)
{

	DIO_u8SetPinValue(CLCD_u8CTRL_PORT, CLCD_u8RS_PIN, Copy_u8RsValue);

	DIO_u8SetPinValue(CLCD_u8CTRL_PORT, CLCD_u8RW_PIN, Copy_u8RwValue);
}

void CLCD_voidSendCmd(uint8 Copy_u8Cmd)
{
	/*Set Rs pin to low for command & Set Rw pin to low for writing*/
	voidSetCtrlPins(DIO_u8PIN_LOW,DIO_u8PIN_LOW);

#if CLCD_u8BIT_MODE == EIGHT_BIT_MODE

	/* Send the command*/
	DIO_u8SetPortValue(CLCD_u8DATA_PORT,Copy_u8Cmd);
	voidSendEnablePulse();

#elif CLCD_u8BIT_MODE == FOUR_BIT_MODE

	/* Send the most significant 4-bits the command */
	voidSetHalfDataPort(Copy_u8Cmd >> 4);
	voidSendEnablePulse();
	/* Send the least significant 4-bits the command */
	voidSetHalfDataPort(Copy_u8Cmd);
	voidSendEnablePulse();

#else
#error wrong CLCD_u8BIT_MODE configuration option
#endif

}

void CLCD_voidSendData(uint8 Copy_u8Data)
{
	/*Set Rs pin to high for data & Set Rw pin to low for writing*/
	voidSetCtrlPins(DIO_u8PIN_HIGH,DIO_u8PIN_LOW);

#if CLCD_u8BIT_MODE == EIGHT_BIT_MODE

	/* Send the command*/
	DIO_u8SetPortValue(CLCD_u8DATA_PORT,Copy_u8Data);
	voidSendEnablePulse();

#elif CLCD_u8BIT_MODE == FOUR_BIT_MODE

	/* Send the most significant 4-bits the command */
	voidSetHalfDataPort(Copy_u8Data >> 4);
	voidSendEnablePulse();
	/* Send the least significant 4-bits the command */
	voidSetHalfDataPort(Copy_u8Data);
	voidSendEnablePulse();

#else
#error wrong CLCD_u8BIT_MODE configuration option
#endif


}

void CLCD_voidInit(void)
{
	/*Wait for more than 30 ms after power on*/
	_delay_ms(40);

#if CLCD_u8BIT_MODE == EIGHT_BIT_MODE

	/*Function set command: 2 lines, Font size: 5x7*/
	CLCD_voidSendCmd(0b00111000);

#endif

#if CLCD_u8BIT_MODE == FOUR_BIT_MODE

	voidSetHalfDataPort(0b0010);
	voidSendEnablePulse();
	voidSetHalfDataPort(0b0010);
	voidSendEnablePulse();
	voidSetHalfDataPort(0b1000);
	voidSendEnablePulse();

#endif
	/*Display on/off control : Display on, cursor off, blink cursor off*/
	CLCD_voidSendCmd(0b00001100);

	/*Clear display*/
	CLCD_voidSendCmd(1);

}


void CLCD_voidSendNumber(sint32 Copy_s32Number)
{
	/* Array to store each digit of the number as characters */
	uint8 Local_u8CharBuffer[11];
	uint8 Local_u8RightDigit, Local_u8Counter = 0;
	sint8 Local_u8Iterator;

	/* If the number is 0, send '0' and return */
	if(Copy_s32Number == 0)
	{
		CLCD_voidSendData('0');
		return;
	}
	/* If the number is negative, send '-' and make the number positive */
	else if(Copy_s32Number < 0)
	{
		Copy_s32Number *= -1;
		CLCD_voidSendData('-');
	}

	/* Extract each digit of the number and store in Local_u8CharBuffer */
	while(Copy_s32Number != 0)
	{
		Local_u8RightDigit = (uint8)((uint32)Copy_s32Number % (uint32)10);
		Copy_s32Number /= 10;
		*(Local_u8CharBuffer + Local_u8Counter) = Local_u8RightDigit;
		Local_u8Counter++;
	}

	/* Send each digit character from Local_u8CharBuffer in reverse order */
	for(Local_u8Iterator = (sint8)Local_u8Counter - 1; Local_u8Iterator >= 0; Local_u8Iterator--)
	{
		CLCD_voidSendData((*(Local_u8CharBuffer + (uint8)Local_u8Iterator)) + '0');
	}

	return;
}



uint8 CLCD_u8SendString(const char* Copy_pchString)
{
	uint8 Local_u8ErrorState = OK;

	/* Check if the input string pointer is not NULL */
	if (Copy_pchString != NULL)
	{
		/* Iterate through each character of the string until the null terminator */
		while (*(Copy_pchString) != '\0')
		{
			/* Send each character to the LCD */
			CLCD_voidSendData(*(Copy_pchString));
			/* Move to the next character in the string */
			Copy_pchString++;
		}
	}
	else
	{
		/* Set error state if the input string pointer is NULL */
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	/* Return the error state */
	return Local_u8ErrorState;
}


void CLCD_voidSetCursorToXY(uint8 Copy_u8XPos, uint8 Copy_u8YPos)
{
	uint8 Local_u8Address;


	Local_u8Address = 0x40 * Copy_u8YPos + Copy_u8XPos;

	/* Set bit 7 to set DDRAM address command */
	SET_BIT(Local_u8Address,7);

	/* Execute set DDRAM address command */
	CLCD_voidSendCmd(Local_u8Address);
}

uint8 CLCD_u8DisplaySpecialCharacter(uint8 Copy_u8LocationNum, uint8 *Copy_pu8Pattern, uint8 Copy_u8XPos, uint8 Copy_u8YPos)
{
	uint8 Local_u8ErrorState = OK;

	if(Copy_pu8Pattern != NULL)
	{
		uint8 Local_u8CGRAMAddress = (uint8)8 * Copy_u8LocationNum;

		uint8 Local_u8LoopCounter;

		/* Set bit 6 for CGRAM address command */
		SET_BIT(Local_u8CGRAMAddress,6);

		/* Execute set CGRAM address command */
		CLCD_voidSendCmd(Local_u8CGRAMAddress);

		for(Local_u8LoopCounter = (uint8)0; Local_u8LoopCounter <(uint8)8; Local_u8LoopCounter++)
		{
			/* Write the input pattarn inside the CGRAM */
			CLCD_voidSendData(*(Copy_pu8Pattern+Local_u8LoopCounter));
		}

		/* Go back to DDRAM */
		CLCD_voidSetCursorToXY(Copy_u8XPos, Copy_u8YPos);

		/* Display the special Pattern inside the CGRAM */
		CLCD_voidSendData(Copy_u8LocationNum);

	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}

void CLCD_u8ClearDisplay(void)
{
	CLCD_voidSendCmd(0x01);
}

void CLCD_voidEnableBlinkingCursor(uint8 Copy_u8State)
{
    if (Copy_u8State)
    {
        // Enable blinking cursor (display on, cursor on, blinking on)
        CLCD_voidSendCmd(0x0F);
    }
    else
    {
        // Disable blinking cursor (display on, cursor on, blinking off)
        CLCD_voidSendCmd(0x0E);
    }
}
