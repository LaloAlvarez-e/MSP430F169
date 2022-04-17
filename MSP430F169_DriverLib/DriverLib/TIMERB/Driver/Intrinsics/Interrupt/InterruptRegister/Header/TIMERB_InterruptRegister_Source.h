/**
 *
 * @file TIMERB_InterruptRegister_Source.h
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

#ifndef TIMERB_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_HEADER_TIMERB_INTERRUPTREGISTER_SOURCE_H_
#define TIMERB_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_HEADER_TIMERB_INTERRUPTREGISTER_SOURCE_H_

#include "DriverLib/TIMERB/Peripheral/Header/TIMERB_Enum.h"
#include "DriverLib/MCU/Header/MCU_Common.h"

void TIMERB_CC__vRegisterIRQSourceHandler(TIMERB_nCC enModuleArg, TIMERB_nCC_MODE enMODE,
         MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler);
void TIMERB__vRegisterIRQSourceHandler(MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler);

#endif /* TIMERB_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_HEADER_TIMERB_INTERRUPTREGISTER_SOURCE_H_ */
