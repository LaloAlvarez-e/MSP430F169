/**
 *
 * @file CLOCK_Mode.h
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
 * @verbatim 14 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 14 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef CLOCK_DRIVER_HEADER_CLOCK_MODE_H_
#define CLOCK_DRIVER_HEADER_CLOCK_MODE_H_

#include "DriverLib/CLOCK/Peripheral/Header/CLOCK_Enum.h"

void CLOCK__vSetLFXT1FrequencyMode(CLOCK_nFREQMODE enFrequencyMode);
CLOCK_nFREQMODE CLOCK__enGetLFXT1FrequencyMode(void);

#endif /* CLOCK_DRIVER_HEADER_CLOCK_MODE_H_ */
