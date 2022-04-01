/**
 *
 * @file FLASH_Stop.c
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
#include "DriverLib/FLASH/Driver/Header/FLASH_Stop.h"

#include "DriverLib/FLASH/Driver/Intrinsics/Primitives/FLASH_Primitives.h"
#include "DriverLib/FLASH/Peripheral/FLASH_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

void FLASH__vStopProcess(void)
{
    FLASH_Register16Bits_t pstRegisterData = {0UL};
    uint16_t u16Value = 0U;
    u16Value = FLASH_CTL3_EMEX_STOP;
    u16Value <<= FLASH_CTL3_R_EMEX_BIT;
    u16Value |= FLASH_CTL3_R_KEY_WRITE;
    pstRegisterData.uptrAddress = FLASH_CTL3_OFFSET;
    pstRegisterData.u16Value = u16Value;
    pstRegisterData.u16Mask = FLASH_CTL3_R_KEY_MASK | FLASH_CTL3_R_EMEX_MASK;
    pstRegisterData.u8Shift = 0UL;

    FLASH__vWriteRegister_16bits(&pstRegisterData);
}

void FLASH__vStopProcess_RAM(void)
{
    FLASH_Register16Bits_t pstRegisterData = {0UL};
    uint16_t u16Value = 0U;
    u16Value = FLASH_CTL3_EMEX_STOP;
    u16Value <<= FLASH_CTL3_R_EMEX_BIT;
    u16Value |= FLASH_CTL3_R_KEY_WRITE;
    pstRegisterData.uptrAddress = FLASH_CTL3_OFFSET;
    pstRegisterData.u16Value = u16Value;
    pstRegisterData.u16Mask = FLASH_CTL3_R_KEY_MASK | FLASH_CTL3_R_EMEX_MASK;
    pstRegisterData.u8Shift = 0UL;

    FLASH__vWriteRegister_16bits_RAM(&pstRegisterData);
}



