/**
 *
 * @file TIMERB_InterruptSource_Clear.h
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

#ifndef TIMERB_DRIVER_INTRINSICS_INTERRUPT_HEADER_TIMERB_INTERRUPTSOURCE_CLEAR_H_
#define TIMERB_DRIVER_INTRINSICS_INTERRUPT_HEADER_TIMERB_INTERRUPTSOURCE_CLEAR_H_

#include "DriverLib/TIMERB/Peripheral/Header/TIMERB_Enum.h"

void TIMERB_CC__vClearInterruptSource(TIMERB_nCC enModuleArg);
void TIMERB__vClearInterruptSource(void);

#endif /* TIMERB_DRIVER_INTRINSICS_INTERRUPT_HEADER_TIMERB_INTERRUPTSOURCE_CLEAR_H_ */
