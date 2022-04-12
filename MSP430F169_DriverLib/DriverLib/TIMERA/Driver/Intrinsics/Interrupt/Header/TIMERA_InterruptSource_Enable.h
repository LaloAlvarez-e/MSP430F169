/**
 *
 * @file TIMERA_InterruptSource_Enable.h
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
 * @verbatim 7 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 7 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef TIMERA_DRIVER_INTRINSICS_INTERRUPT_HEADER_TIMERA_INTERRUPTSOURCE_ENABLE_H_
#define TIMERA_DRIVER_INTRINSICS_INTERRUPT_HEADER_TIMERA_INTERRUPTSOURCE_ENABLE_H_

#include "DriverLib/TIMERA/Peripheral/Header/TIMERA_Enum.h"

void TIMERA_CC__vSetEnableInterruptSource(TIMERA_nCC enModuleArg,
                                    TIMERA_nINT_ENABLE enState);
void TIMERA_CC__vEnaInterruptSource(TIMERA_nCC enModuleArg);
void TIMERA_CC__vDisInterruptSource(TIMERA_nCC enModuleArg);
TIMERA_nINT_ENABLE TIMERA_CC__enGetEnableInterruptSource(TIMERA_nCC enModuleArg);

void TIMERA__vSetEnableInterruptSource(TIMERA_nINT_ENABLE enState);
void TIMERA__vEnaInterruptSource(void);
void TIMERA__vDisInterruptSource(void);
TIMERA_nINT_ENABLE TIMERA__enGetEnableInterruptSource(void);


#endif /* TIMERA_DRIVER_INTRINSICS_INTERRUPT_HEADER_TIMERA_INTERRUPTSOURCE_ENABLE_H_ */
