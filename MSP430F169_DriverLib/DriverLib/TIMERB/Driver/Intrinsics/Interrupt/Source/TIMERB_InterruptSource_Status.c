/**
 *
 * @file TIMERB_InterruptSource_Status.c
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
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 7 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/TIMERB/Driver/Intrinsics/Interrupt/Header/TIMERB_InterruptSource_Status.h"

#include "DriverLib/TIMERB/Driver/Intrinsics/Primitives/TIMERB_Primitives.h"
#include "DriverLib/TIMERB/Peripheral/TIMERB_Peripheral.h"

void TIMERB_CC__vSetStatusInterruptSource(TIMERB_nCC enModuleArg,
                                    TIMERB_nINT_STATUS enStatus)
{
    TIMERB_Register_t pstRegisterData;

    pstRegisterData.uptrAddress = TIMERB_CC_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enStatus;
    pstRegisterData.u16Mask = TIMERB_CC_CTL_IFG_MASK;
    pstRegisterData.u8Shift = TIMERB_CC_CTL_R_IFG_BIT;
    TIMERB_CC__vWriteRegister(enModuleArg,
                         &pstRegisterData);
}

TIMERB_nINT_STATUS TIMERB_CC__enGetStatusInterruptSource(TIMERB_nCC enModuleArg)
{
    TIMERB_Register_t pstRegisterData;
    TIMERB_nINT_STATUS enStatus;

    pstRegisterData.uptrAddress = TIMERB_CC_CTL_OFFSET;
    pstRegisterData.u16Mask = TIMERB_CC_CTL_IFG_MASK;
    pstRegisterData.u8Shift = TIMERB_CC_CTL_R_IFG_BIT;

    enStatus = (TIMERB_nINT_STATUS) TIMERB_CC__u16ReadRegister(enModuleArg,
                                                &pstRegisterData);
    return (enStatus);
}


void TIMERB__vSetStatusInterruptSource(TIMERB_nINT_STATUS enStatus)
{
    TIMERB_Register_t pstRegisterData;

    pstRegisterData.uptrAddress = TIMERB_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enStatus;
    pstRegisterData.u16Mask = TIMERB_CTL_IFG_MASK;
    pstRegisterData.u8Shift = TIMERB_CTL_R_IFG_BIT;
    TIMERB__vWriteRegister( &pstRegisterData);
}

TIMERB_nINT_STATUS TIMERB__enGetStatusInterruptSource(void)
{
    TIMERB_Register_t pstRegisterData;
    TIMERB_nINT_STATUS enStatus;

    pstRegisterData.uptrAddress = TIMERB_CTL_OFFSET;
    pstRegisterData.u16Mask = TIMERB_CTL_IFG_MASK;
    pstRegisterData.u8Shift = TIMERB_CTL_R_IFG_BIT;

    enStatus = (TIMERB_nINT_STATUS) TIMERB__u16ReadRegister(&pstRegisterData);
    return (enStatus);
}


