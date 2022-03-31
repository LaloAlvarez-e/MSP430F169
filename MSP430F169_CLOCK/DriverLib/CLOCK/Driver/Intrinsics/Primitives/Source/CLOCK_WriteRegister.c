/**
 *
 * @file CLOCK_WriteRegister.c
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
#include "DriverLib/CLOCK/Driver/Intrinsics/Primitives/Header/CLOCK_WriteRegister.h"

#include "DriverLib/CLOCK/Peripheral/CLOCK_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

void CLOCK__vWriteRegister(uintptr_t uptrRegisterAddress,
                          uint8_t u8RegisterValue,
                          uint8_t u8RegisterMask,
                          uint8_t u8RegisterShift)
{
    uintptr_t ptrAddressBase = CLOCK_BASE;
    ptrAddressBase += uptrRegisterAddress;
    MCU__vWriteRegister_8bits(ptrAddressBase,
                              u8RegisterValue,
                              u8RegisterMask,
                              u8RegisterShift);
}




