/**
 *
 * @file SVS_ReadRegister.c
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
 * @verbatim 25 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 25 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/SVS/Driver/Intrinsics/Primitives/Header/SVS_ReadRegister.h"

#include "DriverLib/SVS/Peripheral/SVS_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

uint8_t SVS__u8ReadRegister(SVS_Register_t* pstRegisterData)
{
    const uintptr_t ptrAddressBase = SVS_BASE;
    uint8_t u8RegisterValue = 0U;

    pstRegisterData->uptrAddress += ptrAddressBase;
    u8RegisterValue = MCU__u8ReadRegister(pstRegisterData);
    return (u8RegisterValue);
}

