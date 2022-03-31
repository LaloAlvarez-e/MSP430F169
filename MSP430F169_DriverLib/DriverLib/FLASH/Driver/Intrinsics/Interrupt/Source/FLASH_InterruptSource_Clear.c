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
    FLASH_Register8Bits_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = FLASH_IFG1_OFFSET;
    pstRegisterData.u8Value = FLASH_IFG1_IFG_NOOCCUR;
    pstRegisterData.u8Mask = FLASH_IFG1_IFG_MASK;
    pstRegisterData.u8Shift = FLASH_IFG1_R_IFG_BIT;

    FLASH__vWriteRegister_8bits(&pstRegisterData);
}
