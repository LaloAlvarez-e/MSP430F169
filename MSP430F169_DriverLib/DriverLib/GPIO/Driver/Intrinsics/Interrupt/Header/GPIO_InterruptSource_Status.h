/**
 *
 * @file GPIO_InterruptSource_Status.h
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

#ifndef GPIO_DRIVER_INTRINSICS_INTERRUPT_HEADER_GPIO_INTERRUPTSOURCE_STATUS_H_
#define GPIO_DRIVER_INTRINSICS_INTERRUPT_HEADER_GPIO_INTERRUPTSOURCE_STATUS_H_

#include "DriverLib/GPIO/Peripheral/Header/GPIO_Enum.h"

void GPIO__vSetStatusInterruptSource(GPIO_nPORT enPortArg,
                                     GPIO_nPIN enPinMask,
                                     GPIO_nINT_STATUS enStatus);
void GPIO__vSetStatusInterruptSourceByNumber(GPIO_nPORT enPortArg,
                                             GPIO_nPIN_NUMBER enPinNumber,
                                             GPIO_nINT_STATUS enStatus);
void GPIO__vSetStatusInterruptSourceByMask(GPIO_nPORT enPortArg,
                                     GPIO_nPIN enPinMask,
                                     GPIO_nPIN enPinValue);
void GPIO__vSetStatusInterruptSourceByFunction(GPIO_nDIGITAL_FUNCTION enFunctionArg,
                                               GPIO_nINT_STATUS enStatus);

GPIO_nINT_STATUS GPIO__enGetStatusInterruptSourceByNumber(GPIO_nPORT enPortArg,
                                           GPIO_nPIN_NUMBER enPinNumber);
GPIO_nPIN GPIO__enGetStatusInterruptSource(GPIO_nPORT enPortArg,
                                           GPIO_nPIN enPinMask);
GPIO_nINT_STATUS GPIO__enGetStatusInterruptSourceByFunction(GPIO_nDIGITAL_FUNCTION enFunctionArg);

#endif /* GPIO_DRIVER_INTRINSICS_INTERRUPT_HEADER_GPIO_INTERRUPTSOURCE_STATUS_H_ */
