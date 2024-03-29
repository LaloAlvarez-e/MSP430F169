/**
 *
 * @file WDT_Mode.h
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

#ifndef DRIVERLIB_WDT_DRIVER_HEADER_WDT_MODE_H_
#define DRIVERLIB_WDT_DRIVER_HEADER_WDT_MODE_H_

#include "DriverLib/WDT/Peripheral/Header/WDT_Enum.h"

#pragma CODE_SECTION(WDT__enGetMode_RAM, ".TI.ramfunc")
#pragma CODE_SECTION(WDT__vSetMode_RAM, ".TI.ramfunc")

void WDT__vSetMode(WDT_nMODE enMode);
WDT_nMODE WDT__enGetMode(void);

WDT_nMODE WDT__enGetMode_RAM(void);
void WDT__vSetMode_RAM(WDT_nMODE enModeArg);


#endif /* DRIVERLIB_WDT_DRIVER_HEADER_WDT_MODE_H_ */
