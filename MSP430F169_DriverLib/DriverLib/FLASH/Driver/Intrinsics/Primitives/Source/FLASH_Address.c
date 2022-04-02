/**
 *
 * @file FLASH_Address.c
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
 * @verbatim 1 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 1 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/FLASH/Driver/Intrinsics/Primitives/Header/FLASH_Address.h"

#include "DriverLib/FLASH/Peripheral/FLASH_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

uintptr_t FLASH__uptrGetMainStartAddress_RAM(void)
{
    return (FLASH_MAIN_START_ADDRESS);
}

uintptr_t FLASH__uptrGetInfoStartAddress_RAM(void)
{
    return (FLASH_INFO_START_ADDRESS);
}
uintptr_t FLASH__uptrGetMainEndAddress_RAM(void)
{
    return (FLASH_MAIN_END_ADDRESS);
}
uintptr_t FLASH__uptrGetInfoEndAddress_RAM(void)
{
    return (FLASH_INFO_END_ADDRESS);
}

uintptr_t FLASH__uptrGetMainStartAddress(void)
{
    return (FLASH_MAIN_START_ADDRESS);
}

uintptr_t FLASH__uptrGetInfoStartAddress(void)
{
    return (FLASH_INFO_START_ADDRESS);
}
uintptr_t FLASH__uptrGetMainEndAddress(void)
{
    return (FLASH_MAIN_END_ADDRESS);
}
uintptr_t FLASH__uptrGetInfoEndAddress(void)
{
    return (FLASH_INFO_END_ADDRESS);
}

