/**
 *
 * @file WDT_InterruptRoutine_Vector.h
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
 * @verbatim 25 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 25 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_WDT_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_HEADER_WDT_INTERRUPTROUTINE_VECTOR_H_
#define DRIVERLIB_WDT_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_HEADER_WDT_INTERRUPTROUTINE_VECTOR_H_

#include "DriverLib/GPIO/Peripheral/Header/GPIO_Enum.h"

__interrupt void WDT_IRQVectorHandler(void);

#endif /* DRIVERLIB_WDT_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_HEADER_WDT_INTERRUPTROUTINE_VECTOR_H_ */
