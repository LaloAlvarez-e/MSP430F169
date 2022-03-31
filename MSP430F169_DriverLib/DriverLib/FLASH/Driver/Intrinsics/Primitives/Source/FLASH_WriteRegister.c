/**
 *
 * @file FLASH_WriteRegister.c
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
#include "DriverLib/FLASH/Driver/Intrinsics/Primitives/Header/FLASH_WriteRegister.h"

#include "DriverLib/FLASH/Peripheral/FLASH_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

void FLASH__vWriteRegister_8bits(FLASH_Register8Bits_t* pstRegisterData)
{
    const uintptr_t ptrAddressBase = FLASH_BASE;

    pstRegisterData->uptrAddress += ptrAddressBase;
    MCU__vWriteRegister_8bits(pstRegisterData);
}


void FLASH__vWriteRegister_16bits(FLASH_Register16Bits_t* pstRegisterData)
{
    const uintptr_t ptrAddressBase = FLASH_BASE;

    pstRegisterData->uptrAddress += ptrAddressBase;
    MCU__vWriteRegister_16bits(pstRegisterData);
}
