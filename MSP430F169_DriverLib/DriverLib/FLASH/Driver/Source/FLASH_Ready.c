/**
 *
 * @file FLASH_Ready.c
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
#include "DriverLib/FLASH/Driver/Header/FLASH_Ready.h"

#include "DriverLib/FLASH/Driver/Intrinsics/Primitives/FLASH_Primitives.h"
#include "DriverLib/FLASH/Peripheral/FLASH_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

FLASH_nREADY FLASH__enGetReadyState(void)
{
    FLASH_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = FLASH_CTL3_OFFSET;
    pstRegisterData.u16Value = (uint16_t) FLASH_enREADY_NOREADY;
    pstRegisterData.u16Mask = FLASH_CTL3_WAIT_MASK;
    pstRegisterData.u8Shift = FLASH_CTL3_R_WAIT_BIT;
    (void) FLASH__u16ReadRegister(&pstRegisterData);

    return ((FLASH_nREADY) pstRegisterData.u16Value);
}

FLASH_nREADY FLASH__enGetReadyState_RAM(void)
{
    FLASH_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = FLASH_CTL3_OFFSET;
    pstRegisterData.u16Value = (uint16_t) FLASH_enREADY_NOREADY;
    pstRegisterData.u16Mask = FLASH_CTL3_WAIT_MASK;
    pstRegisterData.u8Shift = FLASH_CTL3_R_WAIT_BIT;
    (void) FLASH__u16ReadRegister_RAM(&pstRegisterData);

    return ((FLASH_nREADY) pstRegisterData.u16Value);
}





