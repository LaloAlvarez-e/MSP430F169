/**
 *
 * @file TIMERB_InterruptRoutine_Vector.h
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

#ifndef TIMERB_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_HEADER_TIMERB_INTERRUPTROUTINE_VECTOR_H_
#define TIMERB_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_HEADER_TIMERB_INTERRUPTROUTINE_VECTOR_H_

#include "DriverLib/TIMERB/Peripheral/Header/TIMERB_Enum.h"

__interrupt void TIMERB_CC0_IRQVectorHandler(void);
__interrupt void TIMERB_IRQVectorHandler(void);

#endif /* TIMERB_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_HEADER_TIMERB_INTERRUPTROUTINE_VECTOR_H_ */
