/**
 *
 * @file CLOCK_InterruptSource_Enable.h
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
 * @verbatim 12 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 12 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef CLOCK_DRIVER_INTRINSICS_INTERRUPT_HEADER_CLOCK_INTERRUPTSOURCE_ENABLE_H_
#define CLOCK_DRIVER_INTRINSICS_INTERRUPT_HEADER_CLOCK_INTERRUPTSOURCE_ENABLE_H_

#include "DriverLib/CLOCK/Peripheral/Header/CLOCK_Enum.h"

void CLOCK__vSetEnableInterruptSource(CLOCK_nINT_ENABLE enState);
void CLOCK__vEnaInterruptSource(void);
void CLOCK__vDisInterruptSource(void);
CLOCK_nINT_ENABLE CLOCK__enGetEnableInterruptSource(void);

#endif /* CLOCK_DRIVER_INTRINSICS_INTERRUPT_HEADER_CLOCK_INTERRUPTSOURCE_ENABLE_H_ */
