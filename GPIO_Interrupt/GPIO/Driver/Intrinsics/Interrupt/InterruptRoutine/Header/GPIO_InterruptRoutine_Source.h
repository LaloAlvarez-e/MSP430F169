/**
 *
 * @file GPIO_InterruptRoutine_Source.h
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

#ifndef GPIO_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_HEADER_GPIO_INTERRUPTROUTINE_SOURCE_H_
#define GPIO_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_HEADER_GPIO_INTERRUPTROUTINE_SOURCE_H_

#include "GPIO/Peripheral/Header/GPIO_Enum.h"
#include "GPIO/Peripheral/GPIO_Peripheral.h"

uint16_t (*GPIO__pu16fGetIRQSourceHandler(GPIO_nPORT enPortArg, GPIO_nPIN_NUMBER enPin))
(PORT_EXT_t* pstPortArg, GPIO_nPIN_NUMBER enPinNumberArg);
void GPIO__vSetIRQSourceHandler(GPIO_nPORT enPortArg, GPIO_nPIN_NUMBER enPin,
            uint16_t (*IRQSourceHandler)(PORT_EXT_t* pstPortArg, GPIO_nPIN_NUMBER enPinNumberArg));

#endif /* GPIO_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_HEADER_GPIO_INTERRUPTROUTINE_SOURCE_H_ */
