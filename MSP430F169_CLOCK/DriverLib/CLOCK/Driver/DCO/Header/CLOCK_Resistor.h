/**
 *
 * @file CLOCK_Resistor.h
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

#ifndef CLOCK_DRIVER_DCO_HEADER_CLOCK_RESISTOR_H_
#define CLOCK_DRIVER_DCO_HEADER_CLOCK_RESISTOR_H_

#include "DriverLib/CLOCK/Peripheral/Header/CLOCK_Enum.h"

void CLOCK__vSetDCOResistorSelect(CLOCK_nRESISTOR enResistorSelect);
CLOCK_nRESISTOR CLOCK__enGetDCOResistorSelect(void);

#endif /* CLOCK_DRIVER_DCO_HEADER_CLOCK_RESISTOR_H_ */
