/*
 * DcMotor_cfg.h
 *
 *  Created on: Jul 18, 2024
 *      Author: Osama
 */

#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_

typedef struct
{
	uint8 Port;
	uint8 Pin1;
	uint8 Pin2;
}DcMotor_config_t;

uint8 DcMotor_u8RotateCW(const DcMotor_config_t *DcMotorObj);

uint8 DcMotor_u8RotateCCW(const DcMotor_config_t *DcMotorObj);

uint8 DcMotor_u8Stop(const DcMotor_config_t *DcMotorObj);

#endif /* DCMOTOR_INTERFACE_H_ */
