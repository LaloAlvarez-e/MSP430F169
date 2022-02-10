/**
 *
 * @file GPIO_Selection.c
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
#include "GPIO/Driver/Header/GPIO_Selection.h"

#include "GPIO/Driver/Intrinsics/GPIO_Intrinsics.h"
#include "GPIO/Peripheral/GPIO_Peripheral.h"

void GPIO__vSetSelection(GPIO_nPORT enPortArg,
                         GPIO_nPIN enPinMask,
                         GPIO_nSEL enSelection)
{
    uint8_t u8Value = 0U;
    if(GPIO_enSEL_IO != enSelection)
    {
        u8Value = (uint8_t) enPinMask;
    }
    GPIO__vWriteRegister(enPortArg,
                         PORT_SEL_OFFSET,
                         u8Value,
                         (uint8_t) enPinMask,
                         PORT_SEL_R_PIN0_BIT);
}


void GPIO__vSetSelectionByNumber(GPIO_nPORT enPortArg,
                             GPIO_nPIN_NUMBER enPinNumber,
                             GPIO_nSEL enSelection)
{
    GPIO__vWriteRegister(enPortArg,
                         PORT_SEL_OFFSET,
                         (uint8_t) enSelection,
                         PORT_SEL_PIN0_MASK,
                         (uint8_t) enPinNumber);
}

GPIO_nPIN GPIO__enGetSelection(GPIO_nPORT enPortArg,
                               GPIO_nPIN enPinMask)
{
    GPIO_nPIN enSelectionReg = GPIO_enPIN_NONE;
    enSelectionReg = (GPIO_nPIN) GPIO__u8ReadRegister(enPortArg,
                                                PORT_SEL_OFFSET,
                                                (uint8_t) enPinMask,
                                                PORT_SEL_R_PIN0_BIT);
    return (enSelectionReg);
}

GPIO_nSEL GPIO__enGetSelectionByNumber(GPIO_nPORT enPortArg,
                                       GPIO_nPIN_NUMBER enPinNumber)
{
    GPIO_nSEL enSelectionReg = GPIO_enSEL_IO;
    enSelectionReg = (GPIO_nSEL) GPIO__u8ReadRegister(enPortArg,
                                                PORT_SEL_OFFSET,
                                                PORT_SEL_PIN0_MASK,
                                                (uint8_t) enPinNumber);
    return (enSelectionReg);
}



