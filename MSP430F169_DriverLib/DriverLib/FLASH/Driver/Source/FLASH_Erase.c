/**
 *
 * @file FLASH_Erase.c
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
#include "DriverLib/FLASH/Driver/Header/FLASH_Erase.h"

#include "DriverLib/FLASH/Driver/Intrinsics/Primitives/FLASH_Primitives.h"
#include "DriverLib/FLASH/Peripheral/FLASH_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

void FLASH__vStartEraseProcess(FLASH_nERASE enEraseProcessArg)
{
    FLASH_Register16Bits_t pstRegisterData;
    uint16_t u16Value = 0U;
    u16Value = (uint16_t) enEraseProcessArg;
    u16Value <<= FLASH_CTL1_R_ERASE_BIT;
    u16Value |= FLASH_CTL1_R_KEY_WRITE;
    pstRegisterData.uptrAddress = FLASH_CTL1_OFFSET;
    pstRegisterData.u16Value = u16Value;
    pstRegisterData.u16Mask = FLASH_CTL1_R_KEY_MASK | FLASH_CTL1_R_ERASE_MASK;
    pstRegisterData.u8Shift = 0UL;

    FLASH__vWriteRegister_16bits(&pstRegisterData);
}

FLASH_nERASE FLASH__enGetEraseProcess(void)
{
    FLASH_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = FLASH_CTL1_OFFSET;
    pstRegisterData.u16Value = (uint16_t) FLASH_enERASE_OFF;
    pstRegisterData.u16Mask = FLASH_CTL1_ERASE_MASK;
    pstRegisterData.u8Shift = FLASH_CTL1_R_ERASE_BIT;
    (void) FLASH__u16ReadRegister(&pstRegisterData);

    return ((FLASH_nERASE) pstRegisterData.u16Value);
}


void FLASH__vStartEraseProcess_RAM(FLASH_nERASE enEraseProcessArg)
{
    FLASH_Register16Bits_t pstRegisterData;
    uint16_t u16Value = 0U;
    u16Value = (uint16_t) enEraseProcessArg;
    u16Value <<= FLASH_CTL1_R_ERASE_BIT;
    u16Value |= FLASH_CTL1_R_KEY_WRITE;
    pstRegisterData.uptrAddress = FLASH_CTL1_OFFSET;
    pstRegisterData.u16Value = u16Value;
    pstRegisterData.u16Mask = FLASH_CTL1_R_KEY_MASK | FLASH_CTL1_R_ERASE_MASK;
    pstRegisterData.u8Shift = 0UL;

    FLASH__vWriteRegister_16bits_RAM(&pstRegisterData);
}

FLASH_nERASE FLASH__enGetEraseProcess_RAM(void)
{
    FLASH_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = FLASH_CTL1_OFFSET;
    pstRegisterData.u16Value = (uint16_t) FLASH_enERASE_OFF;
    pstRegisterData.u16Mask = FLASH_CTL1_ERASE_MASK;
    pstRegisterData.u8Shift = FLASH_CTL1_R_ERASE_BIT;
    (void) FLASH__u16ReadRegister_RAM(&pstRegisterData);

    return ((FLASH_nERASE) pstRegisterData.u16Value);
}




