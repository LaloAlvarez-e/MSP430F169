/**
 *
 * @file GPIO_Selection.h
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

#ifndef GPIO_DRIVER_HEADER_GPIO_SELECTION_H_
#define GPIO_DRIVER_HEADER_GPIO_SELECTION_H_

#include "GPIO/Peripheral/Header/GPIO_Enum.h"

void GPIO__vSetSelection(GPIO_nPORT enPortArg,
                         GPIO_nPIN enPinMask,
                         GPIO_nSEL enSelection);
void GPIO__vSetSelectionByNumber(GPIO_nPORT enPortArg,
                             GPIO_nPIN_NUMBER enPinNumber,
                             GPIO_nSEL enSelection);

GPIO_nPIN GPIO__enGetSelection(GPIO_nPORT enPortArg,
                               GPIO_nPIN enPinMask);
GPIO_nSEL GPIO__enGetSelectionByNumber(GPIO_nPORT enPortArg,
                                       GPIO_nPIN_NUMBER enPinNumber);

#endif /* GPIO_DRIVER_HEADER_GPIO_SELECTION_H_ */
