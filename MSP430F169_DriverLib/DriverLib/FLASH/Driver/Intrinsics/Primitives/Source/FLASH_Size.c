/**
 *
 * @file FLASH_Size.c
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
#include "DriverLib/FLASH/Driver/Intrinsics/Primitives/Header/FLASH_Size.h"

#include "DriverLib/FLASH/Peripheral/FLASH_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

uint16_t FLASH__u16GetBlockSize(void)
{
    return (FLASH_BLOCK_SIZE);
}

uint16_t FLASH__u16GetMainSectionSize(void)
{
    return (FLASH_MAIN_SIZE);
}

uint16_t FLASH__u16GetInfoSectionSize(void)
{
    return (FLASH_INFO_SIZE);
}

uint16_t FLASH__u16GetMainSegmentSize(void)
{
    return (FLASH_MAIN_SEGMENT_SIZE);
}

uint16_t FLASH__u16GetInfoSegmentSize(void)
{
    return (FLASH_INFO_SEGMENT_SIZE);
}


uint16_t FLASH__u16GetBlockSize_RAM(void)
{
    return (FLASH_BLOCK_SIZE);
}

uint16_t FLASH__u16GetMainSectionSize_RAM(void)
{
    return (FLASH_MAIN_SIZE);
}

uint16_t FLASH__u16GetInfoSectionSize_RAM(void)
{
    return (FLASH_INFO_SIZE);
}

uint16_t FLASH__u16GetMainSegmentSize_RAM(void)
{
    return (FLASH_MAIN_SEGMENT_SIZE);
}

uint16_t FLASH__u16GetInfoSegmentSize_RAM(void)
{
    return (FLASH_INFO_SEGMENT_SIZE);
}



