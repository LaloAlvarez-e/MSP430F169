/**
 *
 * @file DMA_InterruptRoutine_Vector.h
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

#ifndef DMA_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_HEADER_DMA_INTERRUPTROUTINE_VECTOR_H_
#define DMA_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_HEADER_DMA_INTERRUPTROUTINE_VECTOR_H_

#include "DriverLib/DMA/Peripheral/Header/DMA_Enum.h"

__interrupt void PORT1_IRQVectorHandler(void);
__interrupt void PORT2_IRQVectorHandler(void);

#endif /* DMA_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_HEADER_DMA_INTERRUPTROUTINE_VECTOR_H_ */
