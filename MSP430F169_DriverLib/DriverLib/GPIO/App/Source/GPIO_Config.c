/**
 *
 * @file GPIO_Config.c
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
 * @verbatim 3 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 3 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#include "DriverLib/GPIO/App/Header/GPIO_Config.h"

#include "DriverLib/GPIO/Driver/GPIO_Driver.h"

void GPIO__vSetConfig(GPIO_nDIGITAL_FUNCTION enFunctionArg)
{
    uint16_t u16PinNumberReg = 0U;
    uint16_t u16PortReg = 0U;
    uint16_t u16SelectionReg = 0U;
    uint16_t u16DirectionReg = 0U;

    u16PinNumberReg = (uint16_t) enFunctionArg;
    u16PinNumberReg >>= GPIO_PIN_OFFSET;
    u16PinNumberReg &= GPIO_PIN_MASK;

    u16PortReg = (uint16_t) enFunctionArg;
    u16PortReg >>= GPIO_PORT_OFFSET;
    u16PortReg &= GPIO_PORT_MASK;

    u16SelectionReg = (uint16_t) enFunctionArg;
    u16SelectionReg >>= GPIO_SEL_OFFSET;
    u16SelectionReg &= GPIO_SEL_MASK;

    u16DirectionReg = (uint16_t) enFunctionArg;
    u16DirectionReg >>= GPIO_DIR_OFFSET;
    u16DirectionReg &= GPIO_DIR_MASK;

    GPIO__vSetDirectionByNumber((GPIO_nPORT) u16PortReg,
                                 (GPIO_nPIN_NUMBER) u16PinNumberReg,
                                 (GPIO_nDIR) u16DirectionReg);
    GPIO__vSetSelectionByNumber((GPIO_nPORT) u16PortReg,
                                 (GPIO_nPIN_NUMBER) u16PinNumberReg,
                                 (GPIO_nSEL) u16SelectionReg);
}

