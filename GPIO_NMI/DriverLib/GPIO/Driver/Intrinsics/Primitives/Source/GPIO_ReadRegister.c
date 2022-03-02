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
#include "DriverLib/GPIO/Driver/Intrinsics/Primitives/Header/GPIO_ReadRegister.h"

#include "DriverLib/GPIO/Peripheral/GPIO_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

uint8_t GPIO__u8ReadRegister(GPIO_nPORT enPortArg,
                             GPIO_Register_t* pstRegisterData)
{
    uintptr_t ptrPortBase = 0U;
    uint8_t u8RegisterValue = 0U;

    ptrPortBase = GPIO__uptrBlockBaseAddress(enPortArg);
    pstRegisterData->uptrAddress += ptrPortBase;
    u8RegisterValue = MCU__u8ReadRegister(pstRegisterData);

    return (u8RegisterValue);
}


