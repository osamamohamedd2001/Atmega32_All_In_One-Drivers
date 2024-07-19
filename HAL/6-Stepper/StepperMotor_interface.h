/*
 * StepperMotor_interface.h
 *
 *  Created on: Jul 19, 2024
 *      Author: Osama
 */

#ifndef STEPPERMOTOR_INTERFACE_H_
#define STEPPERMOTOR_INTERFACE_H_

typedef struct
{
	uint8 Port;
	uint8 BlueWirePin;
	uint8 PinkWirePin;
	uint8 YellowWirePin;
	uint8 OrangeWirePin;
}Stepper_cfg_t;

uint8 StepperRotateCW(const Stepper_cfg_t* Obj, uint16 Copy_u8Angle);

uint8 StepperRotateCCW(const Stepper_cfg_t* Obj, uint16 Copy_u8Angle);

#endif /* STEPPERMOTOR_INTERFACE_H_ */
