/**
 *
 * @file GPIO_Input.h
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

#ifndef GPIO_DRIVER_HEADER_GPIO_INPUT_H_
#define GPIO_DRIVER_HEADER_GPIO_INPUT_H_

#include "DriverLib/GPIO/Peripheral/Header/GPIO_Enum.h"

GPIO_nPIN GPIO__enGetInput(GPIO_nPORT enPortArg,
                               GPIO_nPIN enPinMask);
GPIO_nLEVEL GPIO__enGetInputByNumber(GPIO_nPORT enPortArg,
                                       GPIO_nPIN_NUMBER enPinNumber);
GPIO_nLEVEL GPIO__enGetInputByFunction(GPIO_nDIGITAL_FUNCTION enFunctionArg);

#endif /* GPIO_DRIVER_HEADER_GPIO_INPUT_H_ */
