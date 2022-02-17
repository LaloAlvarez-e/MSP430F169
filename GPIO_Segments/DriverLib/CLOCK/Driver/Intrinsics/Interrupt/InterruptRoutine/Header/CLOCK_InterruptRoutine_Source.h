/**
 *
 * @file CLOCK_InterruptRoutine_Source.h
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

#ifndef CLOCK_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_HEADER_CLOCK_INTERRUPTROUTINE_SOURCE_H_
#define CLOCK_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_HEADER_CLOCK_INTERRUPTROUTINE_SOURCE_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

MCU__pu16fIRQSourceHandler_t CLOCK__pu16fGetIRQSourceHandler(void);
void CLOCK__vSetIRQSourceHandler(MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler);



#endif /* CLOCK_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_HEADER_CLOCK_INTERRUPTROUTINE_SOURCE_H_ */
