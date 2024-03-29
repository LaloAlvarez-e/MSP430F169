/**
 *
 * @file WDT_Enable.h
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

#ifndef DRIVERLIB_WDT_DRIVER_HEADER_WDT_ENABLE_H_
#define DRIVERLIB_WDT_DRIVER_HEADER_WDT_ENABLE_H_

#include "DriverLib/WDT/Peripheral/Header/WDT_Enum.h"

#pragma CODE_SECTION(WDT__vSetEnable_RAM, ".TI.ramfunc")
#pragma CODE_SECTION(WDT__enGetEnable_RAM, ".TI.ramfunc")

void WDT__vSetEnable(WDT_nENABLE enEnableArg);
WDT_nENABLE WDT__enGetEnable(void);

void WDT__vSetEnable_RAM(WDT_nENABLE enEnableArg);
WDT_nENABLE WDT__enGetEnable_RAM(void);

#endif /* DRIVERLIB_WDT_DRIVER_HEADER_WDT_ENABLE_H_ */
