/**
 *
 * @file GPIO_InterruptSource_Status.c
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
 * @verbatim 7 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 7 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "GPIO/Driver/Intrinsics/Interrupt/Header/GPIO_InterruptSource_Status.h"

#include "GPIO/Driver/Intrinsics/Primitives/GPIO_Primitives.h"
#include "GPIO/Peripheral/GPIO_Peripheral.h"

void GPIO__vSetStatusInterruptSource(GPIO_nPORT enPortArg,
                                     GPIO_nPIN enPinMask,
                                     GPIO_nINT_STATUS enStatus)
{
    uint8_t u8Value = 0U;
    if((GPIO_enPORT1 == enPortArg) || (GPIO_enPORT2 == enPortArg))
    {
        if(GPIO_enINT_STATUS_NOOCCUR != enStatus)
        {
            u8Value = (uint8_t) enPinMask;
        }
        GPIO__vWriteRegister(enPortArg,
                             PORT_IFG_OFFSET,
                             u8Value,
                             (uint8_t) enPinMask,
                             PORT_IFG_R_PIN0_BIT);
    }
}

void GPIO__vSetStatusInterruptSourceByNumber(GPIO_nPORT enPortArg,
                                             GPIO_nPIN_NUMBER enPinNumber,
                                             GPIO_nINT_STATUS enStatus)
{
    if((GPIO_enPORT1 == enPortArg) || (GPIO_enPORT2 == enPortArg))
    {
        GPIO__vWriteRegister(enPortArg,
                             PORT_IFG_OFFSET,
                             (uint8_t) enStatus,
                             PORT_IFG_PIN0_MASK,
                             (uint8_t) enPinNumber);
    }
}

GPIO_nPIN GPIO__enGetStatusInterruptSource(GPIO_nPORT enPortArg,
                                           GPIO_nPIN enPinMask)
{
    GPIO_nPIN enStatus = GPIO_enPIN_NONE;
    if((GPIO_enPORT1 == enPortArg) || (GPIO_enPORT2 == enPortArg))
    {
        enStatus = (GPIO_nPIN) GPIO__u8ReadRegister(enPortArg,
                                                    PORT_IFG_OFFSET,
                                                    (uint8_t) enPinMask,
                                                    PORT_IFG_R_PIN0_BIT);
    }
    return (enStatus);
}

GPIO_nINT_STATUS GPIO__enGetStatusInterruptSourceByNumber(GPIO_nPORT enPortArg,
                                           GPIO_nPIN_NUMBER enPinNumber)
{
    GPIO_nINT_STATUS enStatus = GPIO_enINT_STATUS_NOOCCUR;
    if((GPIO_enPORT1 == enPortArg) || (GPIO_enPORT2 == enPortArg))
    {
        enStatus = (GPIO_nINT_STATUS) GPIO__u8ReadRegister(enPortArg,
                                                    PORT_IFG_OFFSET,
                                                    PORT_IFG_PIN0_MASK,
                                                    (uint8_t) enPinNumber);
    }
    return (enStatus);
}


