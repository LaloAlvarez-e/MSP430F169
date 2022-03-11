/**
 *
 * @file GPIO_InterruptEdge.h
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
 * @verbatim 10 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 10 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef GPIO_DRIVER_HEADER_GPIO_INTERRUPTEDGE_H_
#define GPIO_DRIVER_HEADER_GPIO_INTERRUPTEDGE_H_

#include "DriverLib/GPIO/Peripheral/Header/GPIO_Enum.h"

void GPIO__vSetInterruptEdge(GPIO_nPORT enPortArg,
                         GPIO_nPIN enPinMask,
                         GPIO_nINT_EDGE enInterruptEdge);
void GPIO__vSetInterruptEdgeByNumber(GPIO_nPORT enPortArg,
                             GPIO_nPIN_NUMBER enPinNumber,
                             GPIO_nINT_EDGE enInterruptEdge);

GPIO_nPIN GPIO__enGetInterruptEdge(GPIO_nPORT enPortArg,
                               GPIO_nPIN enPinMask);
GPIO_nINT_EDGE GPIO__enGetInterruptEdgeByNumber(GPIO_nPORT enPortArg,
                                       GPIO_nPIN_NUMBER enPinNumber);

#endif /* GPIO_DRIVER_HEADER_GPIO_INTERRUPTEDGE_H_ */
