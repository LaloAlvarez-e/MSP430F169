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
#include "DriverLib/GPIO/Driver/Header/GPIO_Direction.h"

#include "DriverLib/GPIO/Driver/Intrinsics/GPIO_Intrinsics.h"
#include "DriverLib/GPIO/Peripheral/GPIO_Peripheral.h"

void GPIO__vSetDirection(GPIO_nPORT enPortArg,
                         GPIO_nPIN enPinMask,
                         GPIO_nDIR enDirection)
{
    GPIO_Register_t pstRegisterData;
    uint8_t u8Value = 0U;
    if(GPIO_enDIR_INPUT != enDirection)
    {
        u8Value = (uint8_t) enPinMask;
    }
    pstRegisterData.uptrAddress = PORT_DIR_OFFSET;
    pstRegisterData.u8Value = u8Value;
    pstRegisterData.u8Mask = (uint8_t) enPinMask;
    pstRegisterData.u8Shift = PORT_DIR_R_PIN0_BIT;
    GPIO__vWriteRegister(enPortArg,
                         &pstRegisterData);
}


void GPIO__vSetDirectionByNumber(GPIO_nPORT enPortArg,
                                 GPIO_nPIN_NUMBER enPinNumber,
                                 GPIO_nDIR enDirection)
{
    GPIO_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = PORT_DIR_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enDirection;
    pstRegisterData.u8Mask = PORT_DIR_PIN0_MASK;
    pstRegisterData.u8Shift = (uint8_t) enPinNumber;
    GPIO__vWriteRegister(enPortArg,
                         &pstRegisterData);
}

void GPIO__vSetDirectionByMask(GPIO_nPORT enPortArg,
                         GPIO_nPIN enPinMask,
                         GPIO_nPIN enPinValue)
{
    GPIO_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = PORT_DIR_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enPinValue;
    pstRegisterData.u8Mask = (uint8_t) enPinMask;
    pstRegisterData.u8Shift = PORT_DIR_R_PIN0_BIT;
    GPIO__vWriteRegister(enPortArg,
                         &pstRegisterData);
}

void GPIO__vSetDirectionByFunction(GPIO_nDIGITAL_FUNCTION enFunctionArg,
                                   GPIO_nDIR enDirection)
{
    uint16_t u16PinNumberReg = 0U;
    uint16_t u16PortReg = 0U;

    u16PinNumberReg = (uint16_t) enFunctionArg;
    u16PinNumberReg >>= GPIO_PIN_OFFSET;
    u16PinNumberReg &= GPIO_PIN_MASK;

    u16PortReg = (uint16_t) enFunctionArg;
    u16PortReg >>= GPIO_PORT_OFFSET;
    u16PortReg &= GPIO_PORT_MASK;

    GPIO__vSetDirectionByNumber((GPIO_nPORT) u16PortReg,
                                 (GPIO_nPIN_NUMBER) u16PinNumberReg,
                                 enDirection);
}



GPIO_nPIN GPIO__enGetDirection(GPIO_nPORT enPortArg,
                               GPIO_nPIN enPinMask)
{
    GPIO_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = PORT_DIR_OFFSET;
    pstRegisterData.u8Value = (uint8_t) GPIO_enPIN_NONE;
    pstRegisterData.u8Mask = (uint8_t) enPinMask;
    pstRegisterData.u8Shift = PORT_DIR_R_PIN0_BIT;
    (void) GPIO__u8ReadRegister(enPortArg, &pstRegisterData);
    return ((GPIO_nPIN) pstRegisterData.u8Value);
}

GPIO_nDIR GPIO__enGetDirectionByNumber(GPIO_nPORT enPortArg,
                                       GPIO_nPIN_NUMBER enPinNumber)
{
    GPIO_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = PORT_DIR_OFFSET;
    pstRegisterData.u8Value = (uint8_t) GPIO_enDIR_INPUT;
    pstRegisterData.u8Mask = PORT_DIR_PIN0_MASK;
    pstRegisterData.u8Shift = (uint8_t) enPinNumber;
    (void) GPIO__u8ReadRegister(enPortArg, &pstRegisterData);
    return ((GPIO_nDIR) pstRegisterData.u8Value);
}

GPIO_nDIR GPIO__enGetDirectionByFunction(GPIO_nDIGITAL_FUNCTION enFunctionArg)
{
    GPIO_nDIR enDirectionReg = GPIO_enDIR_INPUT;
    uint16_t u16PinNumberReg = 0U;
    uint16_t u16PortReg = 0U;

    u16PinNumberReg = (uint16_t) enFunctionArg;
    u16PinNumberReg >>= GPIO_PIN_OFFSET;
    u16PinNumberReg &= GPIO_PIN_MASK;

    u16PortReg = (uint16_t) enFunctionArg;
    u16PortReg >>= GPIO_PORT_OFFSET;
    u16PortReg &= GPIO_PORT_MASK;

    enDirectionReg = GPIO__enGetDirectionByNumber((GPIO_nPORT) u16PortReg,
                                 (GPIO_nPIN_NUMBER) u16PinNumberReg);
    return (enDirectionReg);
}


