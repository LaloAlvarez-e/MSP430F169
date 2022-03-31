/**
 *
 * @file CLOCK_InterruptRegister_Source.h
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
 * @verbatim 13 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 13 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef CLOCK_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_HEADER_CLOCK_INTERRUPTREGISTER_SOURCE_H_
#define CLOCK_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_HEADER_CLOCK_INTERRUPTREGISTER_SOURCE_H_

#include "DriverLib/CLOCK/Peripheral/Header/CLOCK_Enum.h"
#include "DriverLib/MCU/Header/MCU_Common.h"

void CLOCK__vRegisterIRQSourceHandler(MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler);

#endif /* CLOCK_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_HEADER_CLOCK_INTERRUPTREGISTER_SOURCE_H_ */
