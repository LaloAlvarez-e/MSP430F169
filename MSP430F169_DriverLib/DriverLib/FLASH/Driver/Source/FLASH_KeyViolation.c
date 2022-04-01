/**
 *
 * @file FLASH_KeyViolation.c
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
#include "DriverLib/FLASH/Driver/Header/FLASH_KeyViolation.h"

#include "DriverLib/FLASH/Driver/Intrinsics/Primitives/FLASH_Primitives.h"
#include "DriverLib/FLASH/Peripheral/FLASH_Peripheral.h"
#include "DriverLib/MCU/MCU.h"


void FLASH__vClearKeyViolation(void)
{
    MCU_Register16Bits_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = FLASH_CTL3_OFFSET;
    pstRegisterData.u16Value = FLASH_CTL3_R_KEY_WRITE | FLASH_CTL3_R_KEYV_NOOCCUR;
    pstRegisterData.u16Mask = FLASH_CTL3_R_KEY_MASK | FLASH_CTL3_R_KEYV_MASK;
    pstRegisterData.u8Shift = 0U;

    FLASH__vWriteRegister_16bits(&pstRegisterData);
}

void FLASH__vClearKeyViolation_RAM(void)
{
    MCU_Register16Bits_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = FLASH_CTL3_OFFSET;
    pstRegisterData.u16Value = FLASH_CTL3_KEYV_NOOCCUR;
    pstRegisterData.u16Mask = FLASH_CTL3_R_KEY_MASK | FLASH_CTL3_R_KEYV_MASK;
    pstRegisterData.u8Shift = 0U;

    FLASH__vWriteRegister_16bits_RAM(&pstRegisterData);
}

void FLASH__vSetKeyViolation(FLASH_nINT_STATUS enStatus)
{
    FLASH_Register16Bits_t pstRegisterData = {0UL};
    uint16_t u16Value = 0U;
    u16Value = (uint16_t) enStatus;
    u16Value <<= FLASH_CTL3_R_KEYV_BIT;
    u16Value |= FLASH_CTL3_R_KEY_WRITE;

    pstRegisterData.uptrAddress = FLASH_CTL3_OFFSET;
    pstRegisterData.u16Value = u16Value;
    pstRegisterData.u16Mask = FLASH_CTL3_R_KEY_MASK |  FLASH_CTL3_R_KEYV_MASK;
    pstRegisterData.u8Shift = 0U;

    FLASH__vWriteRegister_16bits(&pstRegisterData);
}

FLASH_nINT_STATUS FLASH__enGetKeyViolation(void)
{
    FLASH_Register16Bits_t pstRegisterData = {0UL};

    pstRegisterData.uptrAddress = FLASH_CTL3_OFFSET;
    pstRegisterData.u16Value = (uint16_t) FLASH_enINT_STATUS_NOOCCUR;
    pstRegisterData.u16Mask = FLASH_CTL3_KEYV_MASK;
    pstRegisterData.u8Shift = FLASH_CTL3_R_KEYV_BIT;

    (void) FLASH__u16ReadRegister(&pstRegisterData);
    return ((FLASH_nINT_STATUS) pstRegisterData.u16Value);
}

void FLASH__vSetKeyViolation_RAM(FLASH_nINT_STATUS enStatus)
{
    FLASH_Register16Bits_t pstRegisterData = {0UL};
    uint16_t u16Value = 0U;
    u16Value = (uint16_t) enStatus;
    u16Value <<= FLASH_CTL3_R_KEYV_BIT;
    u16Value |= FLASH_CTL3_R_KEY_WRITE;

    pstRegisterData.uptrAddress = FLASH_CTL3_OFFSET;
    pstRegisterData.u16Value = u16Value;
    pstRegisterData.u16Mask = FLASH_CTL3_R_KEY_MASK |  FLASH_CTL3_R_KEYV_MASK;
    pstRegisterData.u8Shift = 0U;

    FLASH__vWriteRegister_16bits_RAM(&pstRegisterData);
}

FLASH_nINT_STATUS FLASH__enGetKeyViolation_RAM(void)
{
    FLASH_Register16Bits_t pstRegisterData = {0UL};

    pstRegisterData.uptrAddress = FLASH_CTL3_OFFSET;
    pstRegisterData.u16Value = (uint16_t) FLASH_enINT_STATUS_NOOCCUR;
    pstRegisterData.u16Mask = FLASH_CTL3_KEYV_MASK;
    pstRegisterData.u8Shift = FLASH_CTL3_R_KEYV_BIT;

    (void) FLASH__u16ReadRegister_RAM(&pstRegisterData);
    return ((FLASH_nINT_STATUS) pstRegisterData.u16Value);
}

