/**
 *
 * @file CLOCK_Selector.h
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
 * @verbatim 13 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 13 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef CLOCK_DRIVER_HEADER_CLOCK_SELECTOR_H_
#define CLOCK_DRIVER_HEADER_CLOCK_SELECTOR_H_

#include "DriverLib/CLOCK/Peripheral/Header/CLOCK_Enum.h"
#include "DriverLib/MCU/Header/MCU_Common.h"

CLOCK_nSTATUS CLOCK__enSetSource(CLOCK_nSIGNAL enClockSignal, CLOCK_nSOURCE enSourceClock);
CLOCK_nSTATUS CLOCK__enSetACLKSource(CLOCK_nSOURCE enSourceClock);
CLOCK_nSTATUS CLOCK__enSetMCLKSource(CLOCK_nSOURCE enSourceClock);
CLOCK_nSTATUS CLOCK__enSetSMCLKSource(CLOCK_nSOURCE enSourceClock);

CLOCK_nSOURCE CLOCK__enGetSource(CLOCK_nSIGNAL enClockSignal);
CLOCK_nSOURCE CLOCK__enGetACLKSource(void);
CLOCK_nSOURCE CLOCK__enGetSMCLKSource(void);
CLOCK_nSOURCE CLOCK__enGetMCLKSource(void);

#endif /* CLOCK_DRIVER_HEADER_CLOCK_SELECTOR_H_ */
