/**
 *
 * @file TIMERB_InterruptRoutine_Source.h
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

#ifndef TIMERB_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_HEADER_TIMERB_INTERRUPTROUTINE_SOURCE_H_
#define TIMERB_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_HEADER_TIMERB_INTERRUPTROUTINE_SOURCE_H_

#include "DriverLib/MCU/Header/MCU_Common.h"
#include "DriverLib/TIMERB/Peripheral/Header/TIMERB_Enum.h"

MCU__pu16fIRQSourceHandler_t TIMERB_CC__pu16fGetIRQSourceHandler(TIMERB_nCC enModuleArg, TIMERB_nCC_MODE enMode);
void TIMERB_CC__vSetIRQSourceHandler(TIMERB_nCC enModuleArg, TIMERB_nCC_MODE enMode,
                               MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler);

MCU__pu16fIRQSourceHandler_t TIMERB__pu16fGetIRQSourceHandler(void);
void TIMERB__vSetIRQSourceHandler(MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler);

#endif /* TIMERB_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_HEADER_TIMERB_INTERRUPTROUTINE_SOURCE_H_ */
