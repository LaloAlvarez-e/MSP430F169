/**
 *
 * @file TIMERB_InterruptSource_Enable.c
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
#include "DriverLib/TIMERB/Driver/Intrinsics/Interrupt/Header/TIMERB_InterruptSource_Enable.h"

#include "DriverLib/TIMERB/Driver/Intrinsics/Primitives/TIMERB_Primitives.h"
#include "DriverLib/TIMERB/Peripheral/TIMERB_Peripheral.h"

void TIMERB_CC__vSetEnableInterruptSource(TIMERB_nCC enModuleArg,
                                    TIMERB_nINT_ENABLE enState)
{
    TIMERB_Register_t pstRegisterData;

    pstRegisterData.uptrAddress = TIMERB_CC_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enState;
    pstRegisterData.u16Mask = (uint16_t) TIMERB_CC_CTL_IE_MASK;
    pstRegisterData.u8Shift = TIMERB_CC_CTL_R_IE_BIT;
    TIMERB_CC__vWriteRegister(enModuleArg,
                         &pstRegisterData);
}

void TIMERB_CC__vEnaInterruptSource(TIMERB_nCC enModuleArg)
{
    TIMERB_CC__vSetEnableInterruptSource(enModuleArg, TIMERB_enINT_ENABLE_ENA);
}

void TIMERB_CC__vDisInterruptSource(TIMERB_nCC enModuleArg)
{
    TIMERB_CC__vSetEnableInterruptSource(enModuleArg, TIMERB_enINT_ENABLE_DIS);
}

TIMERB_nINT_ENABLE TIMERB_CC__enGetEnableInterruptSource(TIMERB_nCC enModuleArg)
{
    TIMERB_Register_t pstRegisterData;
    TIMERB_nINT_ENABLE enEnable = TIMERB_enINT_ENABLE_DIS;

    pstRegisterData.uptrAddress = TIMERB_CC_CTL_OFFSET;
    pstRegisterData.u16Mask = TIMERB_CC_CTL_IE_MASK;
    pstRegisterData.u8Shift = TIMERB_CC_CTL_R_IE_BIT;
    enEnable = (TIMERB_nINT_ENABLE) TIMERB_CC__u16ReadRegister(enModuleArg,
                                                &pstRegisterData);
    return (enEnable);
}



void TIMERB__vSetEnableInterruptSource(TIMERB_nINT_ENABLE enState)
{
    TIMERB_Register_t pstRegisterData;

    pstRegisterData.uptrAddress = TIMERB_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enState;
    pstRegisterData.u16Mask = (uint16_t) TIMERB_CTL_IE_MASK;
    pstRegisterData.u8Shift = TIMERB_CTL_R_IE_BIT;
    TIMERB__vWriteRegister(&pstRegisterData);
}

void TIMERB__vEnaInterruptSource(void)
{
    TIMERB__vSetEnableInterruptSource(TIMERB_enINT_ENABLE_ENA);
}

void TIMERB__vDisInterruptSource(void)
{
    TIMERB__vSetEnableInterruptSource(TIMERB_enINT_ENABLE_DIS);
}

TIMERB_nINT_ENABLE TIMERB__enGetEnableInterruptSource(void)
{
    TIMERB_Register_t pstRegisterData;
    TIMERB_nINT_ENABLE enEnable = TIMERB_enINT_ENABLE_DIS;

    pstRegisterData.uptrAddress = TIMERB_CTL_OFFSET;
    pstRegisterData.u16Mask = TIMERB_CTL_IE_MASK;
    pstRegisterData.u8Shift = TIMERB_CTL_R_IE_BIT;
    enEnable = (TIMERB_nINT_ENABLE) TIMERB__u16ReadRegister(&pstRegisterData);
    return (enEnable);
}
