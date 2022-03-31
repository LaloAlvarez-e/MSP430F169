/**
 *
 * @file GPIO_InterruptSource_Enable.h
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

#ifndef GPIO_DRIVER_INTRINSICS_INTERRUPT_HEADER_GPIO_INTERRUPTSOURCE_ENABLE_H_
#define GPIO_DRIVER_INTRINSICS_INTERRUPT_HEADER_GPIO_INTERRUPTSOURCE_ENABLE_H_

#include "GPIO/Peripheral/Header/GPIO_Enum.h"

void GPIO__vSetEnableInterruptSource(GPIO_nPORT enPortArg,
                                     GPIO_nPIN enPinMask,
                                     GPIO_nINT_ENABLE enState);
void GPIO__vEnaInterruptSource(GPIO_nPORT enPortArg,
                               GPIO_nPIN enPinMask);
void GPIO__vDisInterruptSource(GPIO_nPORT enPortArg,
                               GPIO_nPIN enPinMask);

void GPIO__vSetEnableInterruptSourceByNumber(GPIO_nPORT enPortArg,
                                             GPIO_nPIN_NUMBER enPinNumber,
                                             GPIO_nINT_ENABLE enState);
void GPIO__vEnaInterruptSourceByNumber(GPIO_nPORT enPortArg,
                                       GPIO_nPIN_NUMBER enPinNumber);
void GPIO__vDisInterruptSourceByNumber(GPIO_nPORT enPortArg,
                                       GPIO_nPIN_NUMBER enPinNumber);

GPIO_nPIN GPIO__enGetEnableInterruptSource(GPIO_nPORT enPortArg,
                                           GPIO_nPIN enPinMask);
GPIO_nINT_ENABLE GPIO__enGetEnableInterruptSourceByNumber(GPIO_nPORT enPortArg,
                                           GPIO_nPIN_NUMBER enPinNumber);

#endif /* GPIO_DRIVER_INTRINSICS_INTERRUPT_HEADER_GPIO_INTERRUPTSOURCE_ENABLE_H_ */
