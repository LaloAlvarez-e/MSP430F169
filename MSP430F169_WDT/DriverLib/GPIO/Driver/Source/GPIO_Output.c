/**
 *
 * @file GPIO_Output.c
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
#include "DriverLib/GPIO/Driver/Header/GPIO_Output.h"

#include "DriverLib/GPIO/Driver/Intrinsics/GPIO_Intrinsics.h"
#include "DriverLib/GPIO/Peripheral/GPIO_Peripheral.h"

void GPIO__vSetOutput(GPIO_nPORT enPortArg,
                         GPIO_nPIN enPinMask,
                         GPIO_nLEVEL enOutput)
{
    uint8_t u8Value = 0U;
    if(GPIO_enLEVEL_LOW != enOutput)
    {
        u8Value = (uint8_t) enPinMask;
    }
    GPIO__vWriteRegister(enPortArg,
                         PORT_OUT_OFFSET,
                         u8Value,
                         (uint8_t) enPinMask,
                         PORT_OUT_R_PIN0_BIT);
}


void GPIO__vSetOutputByNumber(GPIO_nPORT enPortArg,
                             GPIO_nPIN_NUMBER enPinNumber,
                             GPIO_nLEVEL enOutput)
{
    GPIO__vWriteRegister(enPortArg,
                         PORT_OUT_OFFSET,
                         (uint8_t) enOutput,
                         PORT_OUT_PIN0_MASK,
                         (uint8_t) enPinNumber);
}

GPIO_nPIN GPIO__enGetOutput(GPIO_nPORT enPortArg,
                               GPIO_nPIN enPinMask)
{
    GPIO_nPIN enOutputReg = GPIO_enPIN_NONE;
    enOutputReg = (GPIO_nPIN) GPIO__u8ReadRegister(enPortArg,
                                                PORT_OUT_OFFSET,
                                                (uint8_t) enPinMask,
                                                PORT_OUT_R_PIN0_BIT);
    return (enOutputReg);
}

GPIO_nLEVEL GPIO__enGetOutputByNumber(GPIO_nPORT enPortArg,
                                       GPIO_nPIN_NUMBER enPinNumber)
{
    GPIO_nLEVEL enOutputReg = GPIO_enLEVEL_LOW;
    enOutputReg = (GPIO_nLEVEL) GPIO__u8ReadRegister(enPortArg,
                                                PORT_OUT_OFFSET,
                                                PORT_OUT_PIN0_MASK,
                                                (uint8_t) enPinNumber);
    return (enOutputReg);
}
