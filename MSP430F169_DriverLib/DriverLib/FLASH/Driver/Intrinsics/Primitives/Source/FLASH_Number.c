/**
 *
 * @file FLASH_Number.c
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
#include "DriverLib/FLASH/Driver/Intrinsics/Primitives/Header/FLASH_Number.h"

#include "DriverLib/FLASH/Peripheral/FLASH_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

uint16_t FLASH__u16GetMainBlockNumberBySegment_RAM(void)
{
    return (FLASH_MAIN_BLOCK_NUMBER_BY_SEGMENT);
}

uint16_t FLASH__u16GetInfoBlockNumberBySegment_RAM(void)
{
    return (FLASH_INFO_BLOCK_NUMBER_BY_SEGMENT);
}
uint16_t FLASH__u16GetMainSegmentNumber_RAM(void)
{
    return (FLASH_MAIN_SEGMENT_NUMBER);
}
uint16_t FLASH__u16GetInfoSegmentNumber_RAM(void)
{
    return (FLASH_INFO_SEGMENT_NUMBER);
}

uint16_t FLASH__u16GetMainBlockNumberBySegment(void)
{
    return (FLASH_MAIN_BLOCK_NUMBER_BY_SEGMENT);
}

uint16_t FLASH__u16GetInfoBlockNumberBySegment(void)
{
    return (FLASH_INFO_BLOCK_NUMBER_BY_SEGMENT);
}
uint16_t FLASH__u16GetMainSegmentNumber(void)
{
    return (FLASH_MAIN_SEGMENT_NUMBER);
}
uint16_t FLASH__u16GetInfoSegmentNumber(void)
{
    return (FLASH_INFO_SEGMENT_NUMBER);
}



