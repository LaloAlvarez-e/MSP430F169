/**
 *
 * @file TIMERA_CaptureSyncMode.c
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
 * @verbatim 12 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 12 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <DriverLib/TIMERA/Driver/Module/Header/TIMERA_CaptureSyncMode.h>

#include "DriverLib/TIMERA/Driver/Intrinsics/TIMERA_Intrinsics.h"
#include "DriverLib/TIMERA/Peripheral/TIMERA_Peripheral.h"

void TIMERA_CC__vSetCaptureSyncMode(TIMERA_nCC enModuleArg,
                             TIMERA_nCC_CAPTURESYNC enCaptureSyncModeArg)
{
    TIMERA_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERA_CC_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enCaptureSyncModeArg;
    pstRegisterData.u16Mask = TIMERA_CC_CTL_SCS_MASK;
    pstRegisterData.u8Shift = TIMERA_CC_CTL_R_SCS_BIT;
    TIMERA_CC__vWriteRegister(enModuleArg,
                         &pstRegisterData);
}

TIMERA_nCC_CAPTURESYNC TIMERA_CC__enGetCaptureSyncMode(TIMERA_nCC enModuleArg)
{
    TIMERA_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERA_CC_CTL_OFFSET;
    pstRegisterData.u16Value = 0U;
    pstRegisterData.u16Mask = TIMERA_CC_CTL_SCS_MASK;
    pstRegisterData.u8Shift = TIMERA_CC_CTL_R_SCS_BIT;
    (void) TIMERA_CC__u16ReadRegister(enModuleArg, &pstRegisterData);
    return ((TIMERA_nCC_CAPTURESYNC) pstRegisterData.u16Value);
}




