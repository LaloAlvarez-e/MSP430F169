/**
 *
 * @file CLOCK_ReadRegister.c
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
 * @verbatim 12 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 12 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/CLOCK/Driver/Intrinsics/Primitives/Header/CLOCK_ReadRegister.h"

#include "DriverLib/CLOCK/Peripheral/CLOCK_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

uint8_t CLOCK__u8ReadRegister(CLOCK_Register_t* pstRegisterData)
{
    const uintptr_t ptrAddressBase = CLOCK_BASE;
    uint8_t u8RegisterValue = 0U;

    pstRegisterData->uptrAddress += ptrAddressBase;
    u8RegisterValue = MCU__u8ReadRegister(pstRegisterData);

    return (u8RegisterValue);
}
