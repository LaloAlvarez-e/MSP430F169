/**
 *
 * @file NMI_InterruptSource_Enable.h
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

#ifndef DRIVERLIB_NMI_DRIVER_INTRINSICS_INTERRUPT_HEADER_NMI_INTERRUPTSOURCE_ENABLE_H_
#define DRIVERLIB_NMI_DRIVER_INTRINSICS_INTERRUPT_HEADER_NMI_INTERRUPTSOURCE_ENABLE_H_

#include "DriverLib/NMI/Peripheral/Header/NMI_Enum.h"

void NMI__vSetEnableInterruptSource(NMI_nINT_ENABLE enState);
void NMI__vEnaInterruptSource(void);
void NMI__vDisInterruptSource(void);
NMI_nINT_ENABLE NMI__enGetEnableInterruptSource(void);

#endif /* DRIVERLIB_NMI_DRIVER_INTRINSICS_INTERRUPT_HEADER_NMI_INTERRUPTSOURCE_ENABLE_H_ */
