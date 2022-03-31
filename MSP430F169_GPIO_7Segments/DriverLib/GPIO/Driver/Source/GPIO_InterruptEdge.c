/**
 *
 * @file GPIO_InterruptEdge.c
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
#include "DriverLib/GPIO/Driver/Header/GPIO_InterruptEdge.h"

#include "DriverLib/GPIO/Driver/Intrinsics/GPIO_Intrinsics.h"
#include "DriverLib/GPIO/Peripheral/GPIO_Peripheral.h"

void GPIO__vSetInterruptEdge(GPIO_nPORT enPortArg,
                         GPIO_nPIN enPinMask,
                         GPIO_nINT_EDGE enInterruptEdge)
{
    uint8_t u8Value = 0U;
    if(GPIO_enINT_EDGE_RISING != enInterruptEdge)
    {
        u8Value = (uint8_t) enPinMask;
    }
    GPIO__vWriteRegister(enPortArg,
                         PORT_IES_OFFSET,
                         u8Value,
                         (uint8_t) enPinMask,
                         PORT_IES_R_PIN0_BIT);
}


void GPIO__vSetInterruptEdgeByNumber(GPIO_nPORT enPortArg,
                             GPIO_nPIN_NUMBER enPinNumber,
                             GPIO_nINT_EDGE enInterruptEdge)
{
    GPIO__vWriteRegister(enPortArg,
                         PORT_IES_OFFSET,
                         (uint8_t) enInterruptEdge,
                         PORT_IES_PIN0_MASK,
                         (uint8_t) enPinNumber);
}

GPIO_nPIN GPIO__enGetInterruptEdge(GPIO_nPORT enPortArg,
                               GPIO_nPIN enPinMask)
{
    GPIO_nPIN enInterruptEdgeReg = GPIO_enPIN_NONE;
    enInterruptEdgeReg = (GPIO_nPIN) GPIO__u8ReadRegister(enPortArg,
                                                PORT_IES_OFFSET,
                                                (uint8_t) enPinMask,
                                                PORT_IES_R_PIN0_BIT);
    return (enInterruptEdgeReg);
}

GPIO_nINT_EDGE GPIO__enGetInterruptEdgeByNumber(GPIO_nPORT enPortArg,
                                       GPIO_nPIN_NUMBER enPinNumber)
{
    GPIO_nINT_EDGE enInterruptEdgeReg = GPIO_enINT_EDGE_RISING;
    enInterruptEdgeReg = (GPIO_nINT_EDGE) GPIO__u8ReadRegister(enPortArg,
                                                PORT_IES_OFFSET,
                                                PORT_IES_PIN0_MASK,
                                                (uint8_t) enPinNumber);
    return (enInterruptEdgeReg);
}



