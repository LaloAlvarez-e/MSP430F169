/**
 *
 * @file WDT_ReadRegister.c
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
#include "DriverLib/WDT/Driver/Intrinsics/Primitives/Header/WDT_ReadRegister.h"

#include "DriverLib/WDT/Peripheral/WDT_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

uint8_t WDT__u8ReadRegister(uintptr_t uptrRegisterAddress,
                             uint8_t u8RegisterMask,
                             uint8_t u8RegisterShift)
{
    uintptr_t ptrAddressBase = WDT_BASE;
    uint8_t u8RegisterValue = 0U;

    ptrAddressBase += uptrRegisterAddress;
    u8RegisterValue = MCU__u8ReadRegister(ptrAddressBase,
                                         u8RegisterMask,
                                         u8RegisterShift);
    return (u8RegisterValue);
}

uint16_t WDT__u16ReadRegister(uintptr_t uptrRegisterAddress,
                             uint16_t u16RegisterMask,
                             uint8_t u8RegisterShift)
{
    uintptr_t ptrAddressBase = WDT_BASE;
    uint16_t u16RegisterValue = 0U;

    ptrAddressBase += uptrRegisterAddress;
    u16RegisterValue = MCU__u16ReadRegister(ptrAddressBase,
                                         u16RegisterMask,
                                         u8RegisterShift);
    return (u16RegisterValue);
}

