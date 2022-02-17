/**
 *
 * @file GPIO_InterruptSource_Enable.c
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
#include "DriverLib/GPIO/Driver/Intrinsics/Interrupt/Header/GPIO_InterruptSource_Enable.h"

#include "DriverLib/GPIO/Driver/Intrinsics/Primitives/GPIO_Primitives.h"
#include "DriverLib/GPIO/Peripheral/GPIO_Peripheral.h"

void GPIO__vSetEnableInterruptSource(GPIO_nPORT enPortArg,
                                     GPIO_nPIN enPinMask,
                                     GPIO_nINT_ENABLE enState)
{
    uint8_t u8Value = 0U;
    if((GPIO_enPORT1 == enPortArg) || (GPIO_enPORT2 == enPortArg))
    {
        if(GPIO_enINT_ENABLE_DIS != enState)
        {
            u8Value = (uint8_t) enPinMask;
        }
        GPIO__vWriteRegister(enPortArg,
                             PORT_IE_OFFSET,
                             u8Value,
                             (uint8_t) enPinMask,
                             PORT_IE_R_PIN0_BIT);
    }
}

void GPIO__vEnaInterruptSource(GPIO_nPORT enPortArg,
                               GPIO_nPIN enPinMask)
{
    GPIO__vSetEnableInterruptSource(enPortArg, enPinMask, GPIO_enINT_ENABLE_ENA);
}

void GPIO__vDisInterruptSource(GPIO_nPORT enPortArg,
                               GPIO_nPIN enPinMask)
{
    GPIO__vSetEnableInterruptSource(enPortArg, enPinMask, GPIO_enINT_ENABLE_DIS);
}

void GPIO__vSetEnableInterruptSourceByNumber(GPIO_nPORT enPortArg,
                                             GPIO_nPIN_NUMBER enPinNumber,
                                             GPIO_nINT_ENABLE enState)
{
    if((GPIO_enPORT1 == enPortArg) || (GPIO_enPORT2 == enPortArg))
    {
        GPIO__vWriteRegister(enPortArg,
                             PORT_IE_OFFSET,
                             (uint8_t) enState,
                             PORT_IE_PIN0_MASK,
                             (uint8_t) enPinNumber);
    }
}

void GPIO__vEnaInterruptSourceByNumber(GPIO_nPORT enPortArg,
                                       GPIO_nPIN_NUMBER enPinNumber)
{
    GPIO__vSetEnableInterruptSourceByNumber(enPortArg, enPinNumber, GPIO_enINT_ENABLE_ENA);
}

void GPIO__vDisInterruptSourceByNumber(GPIO_nPORT enPortArg,
                                       GPIO_nPIN_NUMBER enPinNumber)
{
    GPIO__vSetEnableInterruptSourceByNumber(enPortArg, enPinNumber, GPIO_enINT_ENABLE_DIS);
}


GPIO_nPIN GPIO__enGetEnableInterruptSource(GPIO_nPORT enPortArg,
                                           GPIO_nPIN enPinMask)
{
    GPIO_nPIN enEnable = GPIO_enPIN_NONE;
    if((GPIO_enPORT1 == enPortArg) || (GPIO_enPORT2 == enPortArg))
    {
        enEnable = (GPIO_nPIN) GPIO__u8ReadRegister(enPortArg,
                                                    PORT_IE_OFFSET,
                                                    (uint8_t) enPinMask,
                                                    PORT_IE_R_PIN0_BIT);
    }
    return (enEnable);
}

GPIO_nINT_ENABLE GPIO__enGetEnableInterruptSourceByNumber(GPIO_nPORT enPortArg,
                                           GPIO_nPIN_NUMBER enPinNumber)
{
    GPIO_nINT_ENABLE enEnable = GPIO_enINT_ENABLE_DIS;
    if((GPIO_enPORT1 == enPortArg) || (GPIO_enPORT2 == enPortArg))
    {
        enEnable = (GPIO_nINT_ENABLE) GPIO__u8ReadRegister(enPortArg,
                                                    PORT_IE_OFFSET,
                                                    PORT_IE_PIN0_MASK,
                                                    (uint8_t) enPinNumber);
    }
    return (enEnable);
}
