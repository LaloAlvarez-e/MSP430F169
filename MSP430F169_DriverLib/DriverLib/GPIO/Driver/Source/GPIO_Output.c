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
    GPIO_Register_t pstRegisterData = {0UL};
    uint8_t u8Value = 0U;
    if(GPIO_enLEVEL_LOW != enOutput)
    {
        u8Value = (uint8_t) enPinMask;
    }
    pstRegisterData.uptrAddress = PORT_OUT_OFFSET;
    pstRegisterData.u8Value = u8Value;
    pstRegisterData.u8Mask = (uint8_t) enPinMask;
    pstRegisterData.u8Shift = PORT_OUT_R_PIN0_BIT;
    GPIO__vWriteRegister(enPortArg,
                         &pstRegisterData);
}


void GPIO__vSetOutputByNumber(GPIO_nPORT enPortArg,
                             GPIO_nPIN_NUMBER enPinNumber,
                             GPIO_nLEVEL enOutput)
{
    GPIO_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = PORT_OUT_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enOutput;
    pstRegisterData.u8Mask = PORT_OUT_PIN0_MASK;
    pstRegisterData.u8Shift = (uint8_t) enPinNumber;
    GPIO__vWriteRegister(enPortArg,
                         &pstRegisterData);
}

void GPIO__vSetOutputByMask(GPIO_nPORT enPortArg,
                         GPIO_nPIN enPinMask,
                         GPIO_nPIN enPinValue)
{
    GPIO_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = PORT_OUT_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enPinValue;
    pstRegisterData.u8Mask = (uint8_t) enPinMask;
    pstRegisterData.u8Shift = PORT_OUT_R_PIN0_BIT;
    GPIO__vWriteRegister(enPortArg,
                         &pstRegisterData);
}

void GPIO__vSetOutputByFunction(GPIO_nDIGITAL_FUNCTION enFunctionArg,
                                GPIO_nLEVEL enOutput)
{
    uint16_t u16PinNumberReg = 0U;
    uint16_t u16PortReg = 0U;

    u16PinNumberReg = (uint16_t) enFunctionArg;
    u16PinNumberReg >>= GPIO_PIN_OFFSET;
    u16PinNumberReg &= GPIO_PIN_MASK;

    u16PortReg = (uint16_t) enFunctionArg;
    u16PortReg >>= GPIO_PORT_OFFSET;
    u16PortReg &= GPIO_PORT_MASK;

    GPIO__vSetOutputByNumber((GPIO_nPORT) u16PortReg,
                                 (GPIO_nPIN_NUMBER) u16PinNumberReg,
                                 enOutput);
}



GPIO_nPIN GPIO__enGetOutput(GPIO_nPORT enPortArg,
                               GPIO_nPIN enPinMask)
{
    GPIO_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = PORT_OUT_OFFSET;
    pstRegisterData.u8Value = (uint8_t) GPIO_enPIN_NONE;
    pstRegisterData.u8Mask = (uint8_t) enPinMask;
    pstRegisterData.u8Shift = PORT_OUT_R_PIN0_BIT;
    (void) GPIO__u8ReadRegister(enPortArg, &pstRegisterData);
    return ((GPIO_nPIN) pstRegisterData.u8Value);
}

GPIO_nLEVEL GPIO__enGetOutputByNumber(GPIO_nPORT enPortArg,
                                       GPIO_nPIN_NUMBER enPinNumber)
{
    GPIO_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = PORT_OUT_OFFSET;
    pstRegisterData.u8Value = (uint8_t) GPIO_enLEVEL_LOW;
    pstRegisterData.u8Mask = PORT_OUT_PIN0_MASK;
    pstRegisterData.u8Shift = (uint8_t) enPinNumber;
    (void) GPIO__u8ReadRegister(enPortArg, &pstRegisterData);
    return ((GPIO_nLEVEL) pstRegisterData.u8Value);
}

GPIO_nLEVEL GPIO__enGetOutputByFunction(GPIO_nDIGITAL_FUNCTION enFunctionArg)
{
    GPIO_nLEVEL enOutputReg = GPIO_enLEVEL_LOW;
    uint16_t u16PinNumberReg = 0U;
    uint16_t u16PortReg = 0U;

    u16PinNumberReg = (uint16_t) enFunctionArg;
    u16PinNumberReg >>= GPIO_PIN_OFFSET;
    u16PinNumberReg &= GPIO_PIN_MASK;

    u16PortReg = (uint16_t) enFunctionArg;
    u16PortReg >>= GPIO_PORT_OFFSET;
    u16PortReg &= GPIO_PORT_MASK;

    enOutputReg = GPIO__enGetOutputByNumber((GPIO_nPORT) u16PortReg,
                                 (GPIO_nPIN_NUMBER) u16PinNumberReg);
    return (enOutputReg);
}

