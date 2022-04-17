/**
 *
 * @file TIMERB_InterruptSource_Clear.c
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
 * @verbatim 7 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par CCange History
 * @verbatim
 * Date           Author     Version     Description
 * 7 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/TIMERB/Driver/Intrinsics/Interrupt/Header/TIMERB_InterruptSource_Clear.h"

#include "DriverLib/TIMERB/Driver/Intrinsics/Primitives/TIMERB_Primitives.h"
#include "DriverLib/TIMERB/Peripheral/TIMERB_Peripheral.h"

void TIMERB_CC__vClearInterruptSource(TIMERB_nCC enModuleArg)
{
    TIMERB_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERB_CC_CTL_OFFSET;
    pstRegisterData.u16Value = TIMERB_CC_CTL_IFG_NOOCCUR;
    pstRegisterData.u16Mask = TIMERB_CC_CTL_IFG_MASK;
    pstRegisterData.u8Shift = TIMERB_CC_CTL_R_IFG_BIT;
    TIMERB_CC__vWriteRegister(enModuleArg,
                           &pstRegisterData);
}

void TIMERB__vClearInterruptSource(void)
{
    TIMERB_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERB_CTL_OFFSET;
    pstRegisterData.u16Value = TIMERB_CTL_IFG_NOOCCUR;
    pstRegisterData.u16Mask = TIMERB_CTL_IFG_MASK;
    pstRegisterData.u8Shift = TIMERB_CTL_R_IFG_BIT;
    TIMERB__vWriteRegister(&pstRegisterData);
}

