/*
 * Button_interface.h
 *
 *  Created on: Jul 15, 2024
 *      Author: Osama
 */

#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_

#include "STD_TYPES.h"

typedef struct
{
	uint8 Button_Port;
	uint8 Button_Pin;

}Button_config_t;


uint8 Button_u8Read(const Button_config_t* Button_Obj, uint8 *Copy_pu8State);

#endif /* BUTTON_INTERFACE_H_ */
