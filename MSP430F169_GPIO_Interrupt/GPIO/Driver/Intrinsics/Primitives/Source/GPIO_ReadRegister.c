/**
 *
 * @file GPIO_ReadRegister.c
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
#include "GPIO/Driver/Intrinsics/Primitives/Header/GPIO_ReadRegister.h"

#include "GPIO/Peripheral/GPIO_Peripheral.h"
#include "MCU/MCU.h"

uint8_t GPIO__u8ReadRegister(GPIO_nPORT enPortArg,
                             uintptr_t uptrRegisterAddress,
                             uint8_t u8RegisterMask,
                             uint8_t u8RegisterShift)
{
    uintptr_t ptrPortBase = 0U;
    uint8_t u8RegisterValue = 0U;

    ptrPortBase = GPIO__uptrBlockBaseAddress(enPortArg);
    ptrPortBase += uptrRegisterAddress;

    u8RegisterValue = MCU__u8ReadRegister(uptrRegisterAddress,
                                         u8RegisterMask,
                                         u8RegisterShift);

    return (u8RegisterValue);
}


