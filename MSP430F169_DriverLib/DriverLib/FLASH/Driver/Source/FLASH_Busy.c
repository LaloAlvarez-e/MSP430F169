/**
 *
 * @file FLASH_Busy.c
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
#include "DriverLib/FLASH/Driver/Header/FLASH_Busy.h"

#include "DriverLib/FLASH/Driver/Intrinsics/Primitives/FLASH_Primitives.h"
#include "DriverLib/FLASH/Peripheral/FLASH_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

FLASH_nBUSY FLASH__enGetBusyState(void)
{
    FLASH_Register16Bits_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = FLASH_CTL3_OFFSET;
    pstRegisterData.u16Value = (uint16_t) FLASH_enBUSY_NOBUSY;
    pstRegisterData.u16Mask = FLASH_CTL3_BUSY_MASK;
    pstRegisterData.u8Shift = FLASH_CTL3_R_BUSY_BIT;
    (void) FLASH__u16ReadRegister(&pstRegisterData);

    return ((FLASH_nBUSY) pstRegisterData.u16Value);
}

FLASH_nBUSY FLASH__enGetBusyState_RAM(void)
{
    FLASH_Register16Bits_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = FLASH_CTL3_OFFSET;
    pstRegisterData.u16Value = (uint16_t) FLASH_enBUSY_NOBUSY;
    pstRegisterData.u16Mask = FLASH_CTL3_BUSY_MASK;
    pstRegisterData.u8Shift = FLASH_CTL3_R_BUSY_BIT;
    (void) FLASH__u16ReadRegister_RAM(&pstRegisterData);

    return ((FLASH_nBUSY) pstRegisterData.u16Value);
}




