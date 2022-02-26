/**
 *
 * @file WDT_InterruptSource_Enable.h
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
 * @verbatim 25 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 25 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_WDT_DRIVER_INTRINSICS_INTERRUPT_HEADER_WDT_INTERRUPTSOURCE_ENABLE_H_
#define DRIVERLIB_WDT_DRIVER_INTRINSICS_INTERRUPT_HEADER_WDT_INTERRUPTSOURCE_ENABLE_H_

#include "DriverLib/WDT/Peripheral/Header/WDT_Enum.h"

void WDT__vSetEnableInterruptSource(WDT_nINT_ENABLE enState);
void WDT__vEnaInterruptSource(void);
void WDT__vDisInterruptSource(void);
WDT_nINT_ENABLE WDT__enGetEnableInterruptSource(void);

#endif /* DRIVERLIB_WDT_DRIVER_INTRINSICS_INTERRUPT_HEADER_WDT_INTERRUPTSOURCE_ENABLE_H_ */
