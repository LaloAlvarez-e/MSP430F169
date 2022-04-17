/**
 *
 * @file TIMERB_InterruptSource_Enable.h
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

#ifndef TIMERB_DRIVER_INTRINSICS_INTERRUPT_HEADER_TIMERB_INTERRUPTSOURCE_ENABLE_H_
#define TIMERB_DRIVER_INTRINSICS_INTERRUPT_HEADER_TIMERB_INTERRUPTSOURCE_ENABLE_H_

#include "DriverLib/TIMERB/Peripheral/Header/TIMERB_Enum.h"

void TIMERB_CC__vSetEnableInterruptSource(TIMERB_nCC enModuleArg,
                                    TIMERB_nINT_ENABLE enState);
void TIMERB_CC__vEnaInterruptSource(TIMERB_nCC enModuleArg);
void TIMERB_CC__vDisInterruptSource(TIMERB_nCC enModuleArg);
TIMERB_nINT_ENABLE TIMERB_CC__enGetEnableInterruptSource(TIMERB_nCC enModuleArg);

void TIMERB__vSetEnableInterruptSource(TIMERB_nINT_ENABLE enState);
void TIMERB__vEnaInterruptSource(void);
void TIMERB__vDisInterruptSource(void);
TIMERB_nINT_ENABLE TIMERB__enGetEnableInterruptSource(void);


#endif /* TIMERB_DRIVER_INTRINSICS_INTERRUPT_HEADER_TIMERB_INTERRUPTSOURCE_ENABLE_H_ */
