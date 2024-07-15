#ifndef CLCD_PRV_H_
#define CLCD_PRV_H_

#define FOUR_BIT_MODE    1
#define EIGHT_BIT_MODE   2

#if CLCD_u8BIT_MODE == FOUR_BIT_MODE

static void voidSetHalfDataPort(uint8 Copy_u8Data);

#endif
static void voidSetCtrlPins(uint8 Copy_u8RsValue, uint8 Copy_u8RwValue);

static void voidSendEnablePulse(void);


#endif
