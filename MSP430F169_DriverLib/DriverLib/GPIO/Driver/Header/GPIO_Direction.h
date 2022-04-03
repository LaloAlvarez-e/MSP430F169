/**
 *
 * @file GPIO_Direction.h
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
 * @verbatim 9 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 9 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef GPIO_DRIVER_HEADER_GPIO_DIRECTION_H_
#define GPIO_DRIVER_HEADER_GPIO_DIRECTION_H_

#include "DriverLib/GPIO/Peripheral/Header/GPIO_Enum.h"

void GPIO__vSetDirection(GPIO_nPORT enPortArg,
                         GPIO_nPIN enPinMask,
                         GPIO_nDIR enDirection);
void GPIO__vSetDirectionByNumber(GPIO_nPORT enPortArg,
                                 GPIO_nPIN_NUMBER enPinNumber,
                                 GPIO_nDIR enDirection);
void GPIO__vSetDirectionByMask(GPIO_nPORT enPortArg,
                         GPIO_nPIN enPinMask,
                         GPIO_nPIN enPinValue);
void GPIO__vSetDirectionByFunction(GPIO_nDIGITAL_FUNCTION enFunctionArg,
                                   GPIO_nDIR enDirection);

GPIO_nPIN GPIO__enGetDirection(GPIO_nPORT enPortArg,
                               GPIO_nPIN enPinMask);
GPIO_nDIR GPIO__enGetDirectionByNumber(GPIO_nPORT enPortArg,
                                       GPIO_nPIN_NUMBER enPinNumber);
GPIO_nDIR GPIO__enGetDirectionByFunction(GPIO_nDIGITAL_FUNCTION enFunctionArg);

#endif /* GPIO_DRIVER_HEADER_GPIO_DIRECTION_H_ */
