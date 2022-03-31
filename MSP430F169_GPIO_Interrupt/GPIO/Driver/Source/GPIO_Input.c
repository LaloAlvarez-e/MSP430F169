/**
 *
 * @file GPIO_Input.c
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
#include "GPIO/Driver/Header/GPIO_Input.h"

#include "GPIO/Driver/Intrinsics/GPIO_Intrinsics.h"
#include "GPIO/Peripheral/GPIO_Peripheral.h"

GPIO_nPIN GPIO__enGetInput(GPIO_nPORT enPortArg,
                               GPIO_nPIN enPinMask)
{
    GPIO_nPIN enInputReg = GPIO_enPIN_NONE;
    enInputReg = (GPIO_nPIN) GPIO__u8ReadRegister(enPortArg,
                                                PORT_IN_OFFSET,
                                                (uint8_t) enPinMask,
                                                PORT_IN_R_PIN0_BIT);
    return (enInputReg);
}

GPIO_nLEVEL GPIO__enGetInputByNumber(GPIO_nPORT enPortArg,
                                       GPIO_nPIN_NUMBER enPinNumber)
{
    GPIO_nLEVEL enInputReg = GPIO_enLEVEL_LOW;
    enInputReg = (GPIO_nLEVEL) GPIO__u8ReadRegister(enPortArg,
                                                PORT_IN_OFFSET,
                                                PORT_IN_PIN0_MASK,
                                                (uint8_t) enPinNumber);
    return (enInputReg);
}



