/**
 *
 * @file GPIO_Direction.c
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
#include "GPIO/Driver/Header/GPIO_Direction.h"

#include "GPIO/Driver/Intrinsics/GPIO_Intrinsics.h"
#include "GPIO/Peripheral/GPIO_Peripheral.h"

void GPIO__vSetDirection(GPIO_nPORT enPortArg,
                         GPIO_nPIN enPinMask,
                         GPIO_nDIR enDirection)
{
    uint8_t u8Value = 0U;
    if(GPIO_enDIR_INPUT != enDirection)
    {
        u8Value = (uint8_t) enPinMask;
    }
    GPIO__vWriteRegister(enPortArg,
                         PORT_DIR_OFFSET,
                         u8Value,
                         (uint8_t) enPinMask,
                         PORT_DIR_R_PIN0_BIT);
}


void GPIO__vSetDirectionByNumber(GPIO_nPORT enPortArg,
                                 GPIO_nPIN_NUMBER enPinNumber,
                                 GPIO_nDIR enDirection)
{
    GPIO__vWriteRegister(enPortArg,
                         PORT_DIR_OFFSET,
                         (uint8_t) enDirection,
                         PORT_DIR_PIN0_MASK,
                         (uint8_t) enPinNumber);
}

GPIO_nPIN GPIO__enGetDirection(GPIO_nPORT enPortArg,
                               GPIO_nPIN enPinMask)
{
    GPIO_nPIN enDirectionReg = GPIO_enPIN_NONE;
    enDirectionReg = (GPIO_nPIN) GPIO__u8ReadRegister(enPortArg,
                                                PORT_DIR_OFFSET,
                                                (uint8_t) enPinMask,
                                                PORT_DIR_R_PIN0_BIT);
    return (enDirectionReg);
}

GPIO_nDIR GPIO__enGetDirectionByNumber(GPIO_nPORT enPortArg,
                                       GPIO_nPIN_NUMBER enPinNumber)
{
    GPIO_nDIR enDirectionReg = GPIO_enDIR_INPUT;
    enDirectionReg = (GPIO_nDIR) GPIO__u8ReadRegister(enPortArg,
                                                PORT_DIR_OFFSET,
                                                PORT_DIR_PIN0_MASK,
                                                (uint8_t) enPinNumber);
    return (enDirectionReg);
}

