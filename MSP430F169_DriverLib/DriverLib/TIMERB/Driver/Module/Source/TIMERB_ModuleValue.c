/**
 *
 * @file TIMERB_ModuleValue.c
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
#include <DriverLib/TIMERB/Driver/Module/Header/TIMERB_ModuleValue.h>

#include "DriverLib/TIMERB/Driver/Intrinsics/TIMERB_Intrinsics.h"
#include "DriverLib/TIMERB/Peripheral/TIMERB_Peripheral.h"

void TIMERB__vSetModuleValue(TIMERB_nCC enModuleArg,
                            uint16_t u16ModuleValueArg)
{
    TIMERB_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERB_CC_R_OFFSET;
    pstRegisterData.u16Value = (uint16_t) u16ModuleValueArg;
    pstRegisterData.u16Mask = TIMERB_CC_R_R_MASK;
    pstRegisterData.u8Shift = TIMERB_CC_R_R_R_BIT;
    TIMERB_CC__vWriteRegister(enModuleArg,
                         &pstRegisterData);
}

uint16_t TIMERB__u16GetModuleValue(TIMERB_nCC enModuleArg)
{
    TIMERB_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERB_CC_R_OFFSET;
    pstRegisterData.u16Value = 0U;
    pstRegisterData.u16Mask = TIMERB_CC_R_R_MASK;
    pstRegisterData.u8Shift = TIMERB_CC_R_R_R_BIT;
    (void) TIMERB_CC__u16ReadRegister(enModuleArg, &pstRegisterData);
    return ((uint16_t) pstRegisterData.u16Value);
}
