/**
 *
 * @file DAC12_InterruptRoutine_Vector.h
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

#ifndef DAC12_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_HEADER_DAC12_INTERRUPTROUTINE_VECTOR_H_
#define DAC12_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_HEADER_DAC12_INTERRUPTROUTINE_VECTOR_H_

#include "DriverLib/DAC12/Peripheral/Header/DAC12_Enum.h"

__interrupt void DAC12_IRQVectorHandler(void);

#endif /* DAC12_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_HEADER_DAC12_INTERRUPTROUTINE_VECTOR_H_ */
