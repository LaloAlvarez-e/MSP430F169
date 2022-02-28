/**
 *
 * @file NMI_WriteRegister.c
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
#include "DriverLib/NMI/Driver/Intrinsics/Primitives/Header/NMI_WriteRegister.h"

#include "DriverLib/NMI/Peripheral/NMI_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

void NMI__vWriteRegister_8bits(uintptr_t uptrRegisterAddress,
                          uint8_t u8RegisterValue,
                          uint8_t u8RegisterMask,
                          uint8_t u8RegisterShift)
{
    uintptr_t ptrAddressBase = NMI_BASE;
    ptrAddressBase += uptrRegisterAddress;
    MCU__vWriteRegister_8bits(ptrAddressBase,
                              u8RegisterValue,
                              u8RegisterMask,
                              u8RegisterShift);
}


void NMI__vWriteRegister_16bits(uintptr_t uptrRegisterAddress,
                          uint16_t u16RegisterValue,
                          uint16_t u16RegisterMask,
                          uint8_t u8RegisterShift)
{
    uintptr_t ptrAddressBase = NMI_BASE;
    ptrAddressBase += uptrRegisterAddress;
    MCU__vWriteRegister_16bits(ptrAddressBase,
                               u16RegisterValue,
                               u16RegisterMask,
                               u8RegisterShift);
}
