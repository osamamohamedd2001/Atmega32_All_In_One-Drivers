/*
 * SSD_interface.h
 *
 *  Created on: Jul 10, 2024
 *      Author: Osama
 */

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#include "STD_TYPES.h"  // Ensure standard types are included

#define COM_ANODE    1u
#define COM_CATHODE  2u

// Configuration structure for SSD
typedef struct
{
    uint8 Port;         // Port where SSD is connected
    uint8 Type;         // SSD type: COM_ANODE or COM_CATHODE
    uint8 EnablePort;   // Port for the enable pin
    uint8 EnablePin;    // Pin for enabling/disabling the SSD
    uint8 StartPin;     // Starting pin for SSD segments (0-6 or 0-7)
} SSD_config_t;

/**
 * @brief Turn ON the SSD.
 *
 * @param SSD_obj Pointer to the SSD configuration structure.
 * @return Error status: OK or an error code.
 */
uint8 SSD_u8ON(const SSD_config_t *SSD_obj);

/**
 * @brief Turn OFF the SSD.
 *
 * @param SSD_obj Pointer to the SSD configuration structure.
 * @return Error status: OK or an error code.
 */
uint8 SSD_u8OFF(const SSD_config_t *SSD_obj);

/**
 * @brief Display a number on the SSD.
 *
 * @param SSD_obj Pointer to the SSD configuration structure.
 * @param Copy_u8Number Number to be displayed (0-9).
 * @return Error status: OK or an error code.
 */
uint8 SSD_u8SetNumber(const SSD_config_t *SSD_obj, uint8 Copy_u8Number);

#endif /* SSD_INTERFACE_H_ */
