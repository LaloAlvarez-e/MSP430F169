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
    GPIO_Register_t pstRegisterData;
    uint8_t u8Value;
    if((GPIO_enPORT1 == enPortArg) || (GPIO_enPORT2 == enPortArg))
    {
        if(GPIO_enINT_ENABLE_DIS != enState)
        {
            u8Value = (uint8_t) enPinMask;
        }
        else
        {
            u8Value = 0U;
        }
        pstRegisterData.uptrAddress = PORT_IE_OFFSET;
        pstRegisterData.u8Value = u8Value;
        pstRegisterData.u8Mask = (uint8_t) enPinMask;
        pstRegisterData.u8Shift = PORT_IE_R_PIN0_BIT;

        GPIO__vWriteRegister(enPortArg,
                             &pstRegisterData);
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
    GPIO_Register_t pstRegisterData;
    if((GPIO_enPORT1 == enPortArg) || (GPIO_enPORT2 == enPortArg))
    {
        pstRegisterData.uptrAddress = PORT_IE_OFFSET;
        pstRegisterData.u8Value = (uint8_t) enState;
        pstRegisterData.u8Mask = PORT_IE_PIN0_MASK;
        pstRegisterData.u8Shift = (uint8_t) enPinNumber;
        GPIO__vWriteRegister(enPortArg,
                             &pstRegisterData);
    }
}

void GPIO__vSetEnableInterruptSourceByMask(GPIO_nPORT enPortArg,
                                     GPIO_nPIN enPinMask,
                                     GPIO_nPIN enPinValue)
{
    GPIO_Register_t pstRegisterData;
    if((GPIO_enPORT1 == enPortArg) || (GPIO_enPORT2 == enPortArg))
    {
        pstRegisterData.uptrAddress = PORT_IE_OFFSET;
        pstRegisterData.u8Value = (uint8_t) enPinValue;
        pstRegisterData.u8Mask = (uint8_t) enPinMask;
        pstRegisterData.u8Shift = PORT_IE_R_PIN0_BIT;

        GPIO__vWriteRegister(enPortArg,
                             &pstRegisterData);
    }
}

void GPIO__vSetEnableInterruptSourceByFunction(GPIO_nDIGITAL_FUNCTION enFunctionArg,
                                               GPIO_nINT_ENABLE enState)
{
    uint16_t u16PinNumberReg;
    uint16_t u16PortReg;

    u16PinNumberReg = (uint16_t) enFunctionArg;
    u16PinNumberReg >>= GPIO_PIN_OFFSET;
    u16PinNumberReg &= GPIO_PIN_MASK;

    u16PortReg = (uint16_t) enFunctionArg;
    u16PortReg >>= GPIO_PORT_OFFSET;
    u16PortReg &= GPIO_PORT_MASK;

    GPIO__vSetEnableInterruptSourceByNumber((GPIO_nPORT) u16PortReg,
                                 (GPIO_nPIN_NUMBER) u16PinNumberReg,
                                 enState);
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


void GPIO__vEnaInterruptSourceByFunction(GPIO_nDIGITAL_FUNCTION enFunctionArg)
{
    GPIO__vSetEnableInterruptSourceByFunction(enFunctionArg, GPIO_enINT_ENABLE_ENA);
}

void GPIO__vDisInterruptSourceByFunction(GPIO_nDIGITAL_FUNCTION enFunctionArg)
{
    GPIO__vSetEnableInterruptSourceByFunction(enFunctionArg, GPIO_enINT_ENABLE_DIS);
}



GPIO_nPIN GPIO__enGetEnableInterruptSource(GPIO_nPORT enPortArg,
                                           GPIO_nPIN enPinMask)
{
    GPIO_Register_t pstRegisterData;
    GPIO_nPIN enEnable;
    if((GPIO_enPORT1 == enPortArg) || (GPIO_enPORT2 == enPortArg))
    {
        pstRegisterData.uptrAddress = PORT_IE_OFFSET;
        pstRegisterData.u8Mask = (uint8_t) enPinMask;
        pstRegisterData.u8Shift = PORT_IE_R_PIN0_BIT;
        enEnable = (GPIO_nPIN) GPIO__u8ReadRegister(enPortArg,
                                                    &pstRegisterData);
    }
    else
    {
        enEnable = GPIO_enPIN_NONE;
    }
    return (enEnable);
}

GPIO_nINT_ENABLE GPIO__enGetEnableInterruptSourceByNumber(GPIO_nPORT enPortArg,
                                           GPIO_nPIN_NUMBER enPinNumber)
{
    GPIO_Register_t pstRegisterData;
    GPIO_nINT_ENABLE enEnable;
    if((GPIO_enPORT1 == enPortArg) || (GPIO_enPORT2 == enPortArg))
    {
        pstRegisterData.uptrAddress = PORT_IE_OFFSET;
        pstRegisterData.u8Mask = PORT_IE_PIN0_MASK;
        pstRegisterData.u8Shift = PORT_IE_R_PIN0_BIT;
        enEnable = (GPIO_nINT_ENABLE) GPIO__u8ReadRegister(enPortArg,
                                                    &pstRegisterData);
    }
    else
    {
        enEnable = GPIO_enINT_ENABLE_DIS;
    }
    return (enEnable);
}

GPIO_nINT_ENABLE GPIO__enGetEnableInterruptSourceByFunction(GPIO_nDIGITAL_FUNCTION enFunctionArg)
{
    GPIO_nINT_ENABLE enEnableInterruptSourceReg;
    uint16_t u16PinNumberReg;
    uint16_t u16PortReg;

    u16PinNumberReg = (uint16_t) enFunctionArg;
    u16PinNumberReg >>= GPIO_PIN_OFFSET;
    u16PinNumberReg &= GPIO_PIN_MASK;

    u16PortReg = (uint16_t) enFunctionArg;
    u16PortReg >>= GPIO_PORT_OFFSET;
    u16PortReg &= GPIO_PORT_MASK;

    enEnableInterruptSourceReg = GPIO__enGetEnableInterruptSourceByNumber((GPIO_nPORT) u16PortReg,
                                 (GPIO_nPIN_NUMBER) u16PinNumberReg);
    return (enEnableInterruptSourceReg);
}


