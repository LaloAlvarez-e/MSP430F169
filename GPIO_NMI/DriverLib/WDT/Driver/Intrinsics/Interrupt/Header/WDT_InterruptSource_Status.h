/**
 *
 * @file WDT_InterruptSource_Status.h
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

#ifndef DRIVERLIB_WDT_DRIVER_INTRINSICS_INTERRUPT_HEADER_WDT_INTERRUPTSOURCE_STATUS_H_
#define DRIVERLIB_WDT_DRIVER_INTRINSICS_INTERRUPT_HEADER_WDT_INTERRUPTSOURCE_STATUS_H_

#include "DriverLib/WDT/Peripheral/Header/WDT_Enum.h"

void WDT__vSetStatusInterruptSource(WDT_nINT_STATUS enStatus);
WDT_nINT_STATUS WDT__enGetStatusInterruptSource(void);

#endif /* DRIVERLIB_WDT_DRIVER_INTRINSICS_INTERRUPT_HEADER_WDT_INTERRUPTSOURCE_STATUS_H_ */
