/**
 *
 * @file FLASH_InterruptSource_Clear.c
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
#include "DriverLib/FLASH/Driver/Intrinsics/Interrupt/Header/FLASH_InterruptSource_Clear.h"

#include "DriverLib/FLASH/Driver/Intrinsics/Primitives/FLASH_Primitives.h"
#include "DriverLib/FLASH/Peripheral/FLASH_Peripheral.h"

void FLASH__vClearInterruptSource(void)
{
    MCU_Register16Bits_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = FLASH_CTL3_OFFSET;
    pstRegisterData.u16Value = FLASH_CTL3_R_KEY_WRITE | FLASH_CTL3_R_ACCVIFG_NOOCCUR;
    pstRegisterData.u16Mask = FLASH_CTL3_R_KEY_MASK | FLASH_CTL3_R_ACCVIFG_MASK;
    pstRegisterData.u8Shift = 0U;

    FLASH__vWriteRegister_16bits(&pstRegisterData);
}

void FLASH__vClearInterruptSource_RAM(void)
{
    MCU_Register16Bits_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = FLASH_CTL3_OFFSET;
    pstRegisterData.u16Value = FLASH_CTL3_ACCVIFG_NOOCCUR;
    pstRegisterData.u16Mask = FLASH_CTL3_R_KEY_MASK | FLASH_CTL3_R_ACCVIFG_MASK;
    pstRegisterData.u8Shift = 0U;

    FLASH__vWriteRegister_16bits_RAM(&pstRegisterData);
}
