/**
 *
 * @file FLASH_Lock.c
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
#include "DriverLib/FLASH/Driver/Header/FLASH_Lock.h"

#include "DriverLib/FLASH/Driver/Intrinsics/Primitives/FLASH_Primitives.h"
#include "DriverLib/FLASH/Peripheral/FLASH_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

void FLASH__vSetLockState(FLASH_nLOCK enLockArg)
{
    FLASH_Register16Bits_t pstRegisterData;
    uint16_t u16Value = 0U;
    u16Value = (uint16_t) enLockArg;
    u16Value <<= FLASH_CTL3_R_LOCK_BIT;
    u16Value |= FLASH_CTL3_R_KEY_WRITE;
    pstRegisterData.uptrAddress = FLASH_CTL3_OFFSET;
    pstRegisterData.u16Value = u16Value;
    pstRegisterData.u16Mask = FLASH_CTL3_R_KEY_MASK | FLASH_CTL3_R_LOCK_MASK;
    pstRegisterData.u8Shift = 0UL;

    FLASH__vWriteRegister_16bits(&pstRegisterData);
}


void FLASH__vLock(void)
{
    FLASH__vSetLockState(FLASH_enLOCK_LOCK);
}

void FLASH__vUnlock(void)
{
    FLASH__vSetLockState(FLASH_enLOCK_UNLOCK);
}

FLASH_nLOCK FLASH__enGetLockState(void)
{
    FLASH_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = FLASH_CTL3_OFFSET;
    pstRegisterData.u16Value = (uint16_t) FLASH_enLOCK_LOCK;
    pstRegisterData.u16Mask = FLASH_CTL3_LOCK_MASK;
    pstRegisterData.u8Shift = FLASH_CTL3_R_LOCK_BIT;
    (void) FLASH__u16ReadRegister(&pstRegisterData);

    return ((FLASH_nLOCK) pstRegisterData.u16Value);
}


void FLASH__vSetLockState_RAM(FLASH_nLOCK enLockArg)
{
    FLASH_Register16Bits_t pstRegisterData;
    uint16_t u16Value = 0U;
    u16Value = (uint16_t) enLockArg;
    u16Value <<= FLASH_CTL3_R_LOCK_BIT;
    u16Value |= FLASH_CTL3_R_KEY_WRITE;
    pstRegisterData.uptrAddress = FLASH_CTL3_OFFSET;
    pstRegisterData.u16Value = u16Value;
    pstRegisterData.u16Mask = FLASH_CTL3_R_KEY_MASK | FLASH_CTL3_R_LOCK_MASK;
    pstRegisterData.u8Shift = 0UL;

    FLASH__vWriteRegister_16bits_RAM(&pstRegisterData);
}

void FLASH__vLock_RAM(void)
{
    FLASH__vSetLockState_RAM(FLASH_enLOCK_LOCK);
}

void FLASH__vUnlock_RAM(void)
{
    FLASH__vSetLockState_RAM(FLASH_enLOCK_UNLOCK);
}

FLASH_nLOCK FLASH__enGetLockState_RAM(void)
{
    FLASH_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = FLASH_CTL3_OFFSET;
    pstRegisterData.u16Value = (uint16_t) FLASH_enLOCK_LOCK;
    pstRegisterData.u16Mask = FLASH_CTL3_LOCK_MASK;
    pstRegisterData.u8Shift = FLASH_CTL3_R_LOCK_BIT;
    (void) FLASH__u16ReadRegister_RAM(&pstRegisterData);

    return ((FLASH_nLOCK) pstRegisterData.u16Value);
}




