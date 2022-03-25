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
#include "DriverLib/GPIO/Driver/Intrinsics/Interrupt/Header/GPIO_InterruptSource_Status.h"

#include "DriverLib/GPIO/Driver/Intrinsics/Primitives/GPIO_Primitives.h"
#include "DriverLib/GPIO/Peripheral/GPIO_Peripheral.h"

void GPIO__vSetStatusInterruptSource(GPIO_nPORT enPortArg,
                                     GPIO_nPIN enPinMask,
                                     GPIO_nINT_STATUS enStatus)
{
    GPIO_Register_t pstRegisterData = {0UL};
    uint8_t u8Value = 0U;
    if((GPIO_enPORT1 == enPortArg) || (GPIO_enPORT2 == enPortArg))
    {
        if(GPIO_enINT_STATUS_NOOCCUR != enStatus)
        {
            u8Value = (uint8_t) enPinMask;
        }
        pstRegisterData.uptrAddress = PORT_IFG_OFFSET;
        pstRegisterData.u8Value = u8Value;
        pstRegisterData.u8Mask = (uint8_t) enPinMask;
        pstRegisterData.u8Shift = PORT_IFG_R_PIN0_BIT;
        GPIO__vWriteRegister(enPortArg,
                             &pstRegisterData);
    }
}

void GPIO__vSetStatusInterruptSourceByNumber(GPIO_nPORT enPortArg,
                                             GPIO_nPIN_NUMBER enPinNumber,
                                             GPIO_nINT_STATUS enStatus)
{
    GPIO_Register_t pstRegisterData = {0UL};
    if((GPIO_enPORT1 == enPortArg) || (GPIO_enPORT2 == enPortArg))
    {
        pstRegisterData.uptrAddress = PORT_IFG_OFFSET;
        pstRegisterData.u8Value = (uint8_t) enStatus;
        pstRegisterData.u8Mask = PORT_IFG_PIN0_MASK;
        pstRegisterData.u8Shift = (uint8_t) enPinNumber;
        GPIO__vWriteRegister(enPortArg,
                             &pstRegisterData);
    }
}

GPIO_nPIN GPIO__enGetStatusInterruptSource(GPIO_nPORT enPortArg,
                                           GPIO_nPIN enPinMask)
{
    GPIO_Register_t pstRegisterData = {0UL};
    GPIO_nPIN enStatus = GPIO_enPIN_NONE;
    if((GPIO_enPORT1 == enPortArg) || (GPIO_enPORT2 == enPortArg))
    {
        pstRegisterData.uptrAddress = PORT_IFG_OFFSET;
        pstRegisterData.u8Mask = (uint8_t) enPinMask;
        pstRegisterData.u8Shift = PORT_IFG_R_PIN0_BIT;
        enStatus = (GPIO_nPIN) GPIO__u8ReadRegister(enPortArg,
                                                    &pstRegisterData);
    }
    return (enStatus);
}

GPIO_nINT_STATUS GPIO__enGetStatusInterruptSourceByNumber(GPIO_nPORT enPortArg,
                                           GPIO_nPIN_NUMBER enPinNumber)
{
    GPIO_Register_t pstRegisterData = {0UL};
    GPIO_nINT_STATUS enStatus = GPIO_enINT_STATUS_NOOCCUR;
    if((GPIO_enPORT1 == enPortArg) || (GPIO_enPORT2 == enPortArg))
    {
        pstRegisterData.uptrAddress = PORT_IFG_OFFSET;
        pstRegisterData.u8Mask = PORT_IFG_PIN0_MASK;
        pstRegisterData.u8Shift = (uint8_t) enPinNumber;
        enStatus = (GPIO_nINT_STATUS) GPIO__u8ReadRegister(enPortArg,
                                                    &pstRegisterData);
    }
    return (enStatus);
}

