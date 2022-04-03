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
    GPIO_Register_t pstRegisterData = {0UL};
    uint8_t u8Value = 0U;
    if(GPIO_enINT_EDGE_RISING != enInterruptEdge)
    {
        u8Value = (uint8_t) enPinMask;
    }
    pstRegisterData.uptrAddress = PORT_IES_OFFSET;
    pstRegisterData.u8Value = u8Value;
    pstRegisterData.u8Mask = (uint8_t) enPinMask;
    pstRegisterData.u8Shift = PORT_IES_R_PIN0_BIT;
    GPIO__vWriteRegister(enPortArg,
                         &pstRegisterData);
}


void GPIO__vSetInterruptEdgeByNumber(GPIO_nPORT enPortArg,
                             GPIO_nPIN_NUMBER enPinNumber,
                             GPIO_nINT_EDGE enInterruptEdge)
{
    GPIO_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = PORT_IES_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enInterruptEdge;
    pstRegisterData.u8Mask = PORT_IES_PIN0_MASK;
    pstRegisterData.u8Shift = (uint8_t) enPinNumber;
    GPIO__vWriteRegister(enPortArg,
                         &pstRegisterData);
}

void GPIO__vSetInterruptEdgeByMask(GPIO_nPORT enPortArg,
                         GPIO_nPIN enPinMask,
                         GPIO_nPIN enPinValue)
{
    GPIO_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = PORT_IES_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enPinValue;
    pstRegisterData.u8Mask = (uint8_t) enPinMask;
    pstRegisterData.u8Shift = PORT_IES_R_PIN0_BIT;
    GPIO__vWriteRegister(enPortArg,
                         &pstRegisterData);
}

void GPIO__vSetInterruptEdgeByFunction(GPIO_nDIGITAL_FUNCTION enFunctionArg,
                                       GPIO_nINT_EDGE enInterruptEdge)
{
    uint16_t u16PinNumberReg = 0U;
    uint16_t u16PortReg = 0U;

    u16PinNumberReg = (uint16_t) enFunctionArg;
    u16PinNumberReg >>= GPIO_PIN_OFFSET;
    u16PinNumberReg &= GPIO_PIN_MASK;

    u16PortReg = (uint16_t) enFunctionArg;
    u16PortReg >>= GPIO_PORT_OFFSET;
    u16PortReg &= GPIO_PORT_MASK;

    GPIO__vSetInterruptEdgeByNumber((GPIO_nPORT) u16PortReg,
                                 (GPIO_nPIN_NUMBER) u16PinNumberReg,
                                 enInterruptEdge);
}


GPIO_nPIN GPIO__enGetInterruptEdge(GPIO_nPORT enPortArg,
                               GPIO_nPIN enPinMask)
{
    GPIO_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = PORT_IES_OFFSET;
    pstRegisterData.u8Value = (uint8_t) GPIO_enPIN_NONE;
    pstRegisterData.u8Mask = (uint8_t) enPinMask;
    pstRegisterData.u8Shift = PORT_IES_R_PIN0_BIT;
    (void) GPIO__u8ReadRegister(enPortArg, &pstRegisterData);
    return ((GPIO_nPIN) pstRegisterData.u8Value);
}

GPIO_nINT_EDGE GPIO__enGetInterruptEdgeByNumber(GPIO_nPORT enPortArg,
                                       GPIO_nPIN_NUMBER enPinNumber)
{
    GPIO_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = PORT_IES_OFFSET;
    pstRegisterData.u8Value = (uint8_t) GPIO_enINT_EDGE_RISING;
    pstRegisterData.u8Mask = PORT_IES_PIN0_MASK;
    pstRegisterData.u8Shift = (uint8_t) enPinNumber;
    (void) GPIO__u8ReadRegister(enPortArg, &pstRegisterData);
    return ((GPIO_nINT_EDGE) pstRegisterData.u8Value);
}

GPIO_nINT_EDGE GPIO__enGetInterruptEdgeByFunction(GPIO_nDIGITAL_FUNCTION enFunctionArg)
{
    GPIO_nINT_EDGE enInterruptEdgeReg = GPIO_enINT_EDGE_RISING;
    uint16_t u16PinNumberReg = 0U;
    uint16_t u16PortReg = 0U;

    u16PinNumberReg = (uint16_t) enFunctionArg;
    u16PinNumberReg >>= GPIO_PIN_OFFSET;
    u16PinNumberReg &= GPIO_PIN_MASK;

    u16PortReg = (uint16_t) enFunctionArg;
    u16PortReg >>= GPIO_PORT_OFFSET;
    u16PortReg &= GPIO_PORT_MASK;

    enInterruptEdgeReg = GPIO__enGetInterruptEdgeByNumber((GPIO_nPORT) u16PortReg,
                                 (GPIO_nPIN_NUMBER) u16PinNumberReg);
    return (enInterruptEdgeReg);
}




