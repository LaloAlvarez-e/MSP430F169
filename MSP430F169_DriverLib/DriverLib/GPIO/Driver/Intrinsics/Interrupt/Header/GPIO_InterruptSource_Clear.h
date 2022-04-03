/**
 *
 * @file GPIO_InterruptSource_Clear.h
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

#ifndef GPIO_DRIVER_INTRINSICS_INTERRUPT_HEADER_GPIO_INTERRUPTSOURCE_CLEAR_H_
#define GPIO_DRIVER_INTRINSICS_INTERRUPT_HEADER_GPIO_INTERRUPTSOURCE_CLEAR_H_

#include "DriverLib/GPIO/Peripheral/Header/GPIO_Enum.h"

void GPIO__vClearInterruptSource(GPIO_nPORT enPortArg,
                                 GPIO_nPIN enPinMask);
void GPIO__vClearInterruptSourceByNumber(GPIO_nPORT enPortArg,
                                 GPIO_nPIN_NUMBER enPinNumber);
void GPIO__vClearInterruptSourceByFunction(GPIO_nDIGITAL_FUNCTION enFunctionArg);

#endif /* GPIO_DRIVER_INTRINSICS_INTERRUPT_HEADER_GPIO_INTERRUPTSOURCE_CLEAR_H_ */
