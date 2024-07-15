#ifndef CLCD_CFG_H
#define CLCD_CFG_H

/*
 * Configure the LCD mode, The options are: 1- FOUR_BIT_MODE
 *                                          2- EIGHT_BIT_MODE
 */

#define CLCD_u8BIT_MODE         FOUR_BIT_MODE

#define CLCD_u8CTRL_PORT		DIO_u8PORTA

#define CLCD_u8RS_PIN			DIO_u8PIN0
#define CLCD_u8RW_PIN			DIO_u8PIN1
#define CLCD_u8E_PIN			DIO_u8PIN2

#define CLCD_u8DATA_PORT		DIO_u8PORTB

#if CLCD_u8BIT_MODE == FOUR_BIT_MODE

#define CLCD_u8D4_PIN     DIO_u8PIN0
#define CLCD_u8D5_PIN     DIO_u8PIN1
#define CLCD_u8D6_PIN     DIO_u8PIN2
#define CLCD_u8D7_PIN     DIO_u8PIN3

#endif

#endif
