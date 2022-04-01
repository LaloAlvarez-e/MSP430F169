/**
 *
 * @file FLASH_Divider.c
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
#include "DriverLib/FLASH/Driver/Header/FLASH_Divider.h"

#include "DriverLib/FLASH/Driver/Intrinsics/Primitives/FLASH_Primitives.h"
#include "DriverLib/FLASH/Peripheral/FLASH_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

void FLASH__vSetClockDivider(uint8_t u8DividerArg)
{
    FLASH_Register16Bits_t pstRegisterData = {0UL};
    uint16_t u16Value = 0U;
    u16Value = (uint16_t) u8DividerArg;
    u16Value <<= FLASH_CTL2_R_FN_BIT;
    u16Value |= FLASH_CTL2_R_KEY_WRITE;
    pstRegisterData.uptrAddress = FLASH_CTL2_OFFSET;
    pstRegisterData.u16Value = u16Value;
    pstRegisterData.u16Mask = FLASH_CTL2_R_KEY_MASK | FLASH_CTL2_R_FN_MASK;
    pstRegisterData.u8Shift = 0UL;

    FLASH__vWriteRegister_16bits(&pstRegisterData);
}

uint8_t FLASH__enGetClockDivider(void)
{
    FLASH_Register16Bits_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = FLASH_CTL2_OFFSET;
    pstRegisterData.u16Value = (uint16_t) FLASH_enCLOCK_SMCLK;
    pstRegisterData.u16Mask = FLASH_CTL2_FN_MASK;
    pstRegisterData.u8Shift = FLASH_CTL2_R_FN_BIT;
    (void) FLASH__u16ReadRegister(&pstRegisterData);

    return ((uint8_t) pstRegisterData.u16Value);
}


void FLASH__vSetClockDivider_RAM(uint8_t u8DividerArg)
{
    FLASH_Register16Bits_t pstRegisterData = {0UL};
    uint16_t u16Value = 0U;
    u16Value = (uint16_t) u8DividerArg;
    u16Value <<= FLASH_CTL2_R_FN_BIT;
    u16Value |= FLASH_CTL2_R_KEY_WRITE;
    pstRegisterData.uptrAddress = FLASH_CTL2_OFFSET;
    pstRegisterData.u16Value = u16Value;
    pstRegisterData.u16Mask = FLASH_CTL2_R_KEY_MASK | FLASH_CTL2_R_FN_MASK;
    pstRegisterData.u8Shift = 0UL;

    FLASH__vWriteRegister_16bits_RAM(&pstRegisterData);
}

uint8_t FLASH__enGetClockDivider_RAM(void)
{
    FLASH_Register16Bits_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = FLASH_CTL2_OFFSET;
    pstRegisterData.u16Value = (uint16_t) FLASH_enCLOCK_SMCLK;
    pstRegisterData.u16Mask = FLASH_CTL2_FN_MASK;
    pstRegisterData.u8Shift = FLASH_CTL2_R_FN_BIT;
    (void) FLASH__u16ReadRegister_RAM(&pstRegisterData);

    return ((uint8_t) pstRegisterData.u16Value);
}

