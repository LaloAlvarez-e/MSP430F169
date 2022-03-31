/**
 *
 * @file GPIO_Output.h
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

#ifndef GPIO_DRIVER_HEADER_GPIO_OUTPUT_H_
#define GPIO_DRIVER_HEADER_GPIO_OUTPUT_H_

#include "GPIO/Peripheral/Header/GPIO_Enum.h"

void GPIO__vSetOutput(GPIO_nPORT enPortArg,
                         GPIO_nPIN enPinMask,
                         GPIO_nLEVEL enOutput);
void GPIO__vSetOutputByNumber(GPIO_nPORT enPortArg,
                             GPIO_nPIN_NUMBER enPinNumber,
                             GPIO_nLEVEL enOutput);

GPIO_nPIN GPIO__enGetOutput(GPIO_nPORT enPortArg,
                               GPIO_nPIN enPinMask);
GPIO_nLEVEL GPIO__enGetOutputByNumber(GPIO_nPORT enPortArg,
                                       GPIO_nPIN_NUMBER enPinNumber);

#endif /* GPIO_DRIVER_HEADER_GPIO_OUTPUT_H_ */
