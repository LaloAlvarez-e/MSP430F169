/**
 *
 * @file FLASH_Mode.c
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
 * @verbatim 26 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 26 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/FLASH/Driver/Header/FLASH_Mode.h"

#include "DriverLib/FLASH/Driver/Intrinsics/Primitives/FLASH_Primitives.h"
#include "DriverLib/FLASH/Peripheral/FLASH_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

void FLASH__vSetMode(FLASH_nMODE enModeArg)
{
    FLASH_Register16Bits_t pstRegisterData = {0UL};
    uint16_t u16Value = 0U;
    u16Value = (uint16_t) enModeArg;
    u16Value <<= FLASH_CTL_R_TMSEL_BIT;
    u16Value |= FLASH_CTL_R_PW_WRITE;
    pstRegisterData.uptrAddress = FLASH_CTL_OFFSET;
    pstRegisterData.u16Value = u16Value;
    pstRegisterData.u16Mask = FLASH_CTL_R_PW_MASK | FLASH_CTL_R_TMSEL_MASK;
    pstRegisterData.u8Shift = 0UL;

    FLASH__vWriteRegister_16bits(&pstRegisterData);
}

FLASH_nMODE FLASH__enGetMode(void)
{
    FLASH_Register16Bits_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = FLASH_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) FLASH_enMODE_FLASH;
    pstRegisterData.u16Mask = FLASH_CTL_TMSEL_MASK;
    pstRegisterData.u8Shift = FLASH_CTL_R_TMSEL_BIT;
    (void) FLASH__u16ReadRegister(&pstRegisterData);

    return ((FLASH_nMODE) pstRegisterData.u16Value);
}




