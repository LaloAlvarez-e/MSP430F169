/**
 *
 * @file TIMERA_CaptureOverflow.c
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
#include <DriverLib/TIMERA/Driver/Module/Header/TIMERA_CaptureOverflow.h>

#include "DriverLib/TIMERA/Driver/Intrinsics/TIMERA_Intrinsics.h"
#include "DriverLib/TIMERA/Peripheral/TIMERA_Peripheral.h"

void TIMERA__vSetCaptureOverflow(TIMERA_nCC enModuleArg,
                                 TIMERA_nINT_STATUS enCaptureOverflowArg)
{
    TIMERA_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERA_CC_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enCaptureOverflowArg;
    pstRegisterData.u16Mask = TIMERA_CC_CTL_COV_MASK;
    pstRegisterData.u8Shift = TIMERA_CC_CTL_R_COV_BIT;
    TIMERA_CC__vWriteRegister(enModuleArg,
                         &pstRegisterData);
}

void TIMERA__vClearCaptureOverflow(TIMERA_nCC enModuleArg)
{
    TIMERA__vSetCaptureOverflow(enModuleArg, TIMERA_enINT_STATUS_NOOCCUR);
}

TIMERA_nINT_STATUS TIMERA__enGetCaptureOverflow(TIMERA_nCC enModuleArg)
{
    TIMERA_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERA_CC_CTL_OFFSET;
    pstRegisterData.u16Value = 0U;
    pstRegisterData.u16Mask = TIMERA_CC_CTL_COV_MASK;
    pstRegisterData.u8Shift = TIMERA_CC_CTL_R_COV_BIT;
    (void) TIMERA_CC__u16ReadRegister(enModuleArg, &pstRegisterData);
    return ((TIMERA_nINT_STATUS) pstRegisterData.u16Value);
}



