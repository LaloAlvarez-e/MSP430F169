/**
 *
 * @file WDT_Clock.h
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
 * @verbatim 26 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 26 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_WDT_DRIVER_HEADER_WDT_CLOCK_H_
#define DRIVERLIB_WDT_DRIVER_HEADER_WDT_CLOCK_H_

#include "DriverLib/WDT/Peripheral/Header/WDT_Enum.h"

void WDT__vSetClock(WDT_nCLOCK enClockArg);
WDT_nCLOCK WDT__enGetClock(void);

#endif /* DRIVERLIB_WDT_DRIVER_HEADER_WDT_CLOCK_H_ */
