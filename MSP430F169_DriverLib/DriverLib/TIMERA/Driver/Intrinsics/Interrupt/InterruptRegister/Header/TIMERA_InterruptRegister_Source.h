/**
 *
 * @file TIMERA_InterruptRegister_Source.h
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

#ifndef TIMERA_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_HEADER_TIMERA_INTERRUPTREGISTER_SOURCE_H_
#define TIMERA_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_HEADER_TIMERA_INTERRUPTREGISTER_SOURCE_H_

#include "DriverLib/TIMERA/Peripheral/Header/TIMERA_Enum.h"
#include "DriverLib/MCU/Header/MCU_Common.h"

void TIMERA_CC_vRegisterIRQSourceHandler(TIMERA_nCC enModuleArg, TIMERA_nCC_MODE enMODE,
         MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler);
void TIMERA__vRegisterIRQSourceHandler(MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler);

#endif /* TIMERA_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_HEADER_TIMERA_INTERRUPTREGISTER_SOURCE_H_ */
