/**
 *
 * @file CLOCK_DCO.h
 * @copyright
 * @verbatim InDeviceMex 2021 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 15 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 15 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef CLOCK_DRIVER_DCO_CLOCK_DCO_H_
#define CLOCK_DRIVER_DCO_CLOCK_DCO_H_

#include "DriverLib/CLOCK/Driver/DCO/Header/CLOCK_FreqSelect.h"
#include "DriverLib/CLOCK/Driver/DCO/Header/CLOCK_Modulation.h"
#include "DriverLib/CLOCK/Driver/DCO/Header/CLOCK_Resistor.h"
#include "DriverLib/CLOCK/Driver/DCO/Header/CLOCK_ResistorSelect.h"

void CLOCK__vSetDCOFrequency(uint32_t u32FrequencyHz, CLOCK_nRESISTOR enResistorSelect);
uint32_t CLOCK__u32GetDCOFrequency(void);

#endif /* CLOCK_DRIVER_DCO_CLOCK_DCO_H_ */
