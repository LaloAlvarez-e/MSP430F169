/**
 *
 * @file NMI_InterruptSource_Status.h
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

#ifndef DRIVERLIB_NMI_DRIVER_INTRINSICS_INTERRUPT_HEADER_NMI_INTERRUPTSOURCE_STATUS_H_
#define DRIVERLIB_NMI_DRIVER_INTRINSICS_INTERRUPT_HEADER_NMI_INTERRUPTSOURCE_STATUS_H_

#include "DriverLib/NMI/Peripheral/Header/NMI_Enum.h"

void NMI__vSetStatusInterruptSource(NMI_nINT_STATUS enStatus);
NMI_nINT_STATUS NMI__enGetStatusInterruptSource(void);

#endif /* DRIVERLIB_NMI_DRIVER_INTRINSICS_INTERRUPT_HEADER_NMI_INTERRUPTSOURCE_STATUS_H_ */
