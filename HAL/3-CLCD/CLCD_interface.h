#ifndef CLCD_INTERFACE_H
#define CLCD_INTERFACE_H

void CLCD_voidSendCmd(uint8 Copy_u8Cmd);

void CLCD_voidSendData(uint8 Copy_u8Data);

void CLCD_voidInit(void);

void CLCD_voidSendNumber(sint32 Copy_s32Number);

uint8 CLCD_u8SendString(const char* Copy_pchString);

void CLCD_voidSetCursorToXY(uint8 Copy_u8XPos, uint8 Copy_u8YPos);

uint8 CLCD_u8DisplaySpecialCharacter(uint8 Copy_u8LocationNum, uint8 *Copy_pu8Pattern, uint8 Copy_u8XPos, uint8 Copy_u8YPos);

void CLCD_u8ClearDisplay(void);

void CLCD_voidEnableBlinkingCursor(uint8 Copy_u8State);


#endif
