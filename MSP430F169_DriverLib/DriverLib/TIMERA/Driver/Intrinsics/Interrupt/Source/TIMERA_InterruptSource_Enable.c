/**
 *
 * @file TIMERA_InterruptSource_Enable.c
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
#include "DriverLib/TIMERA/Driver/Intrinsics/Interrupt/Header/TIMERA_InterruptSource_Enable.h"

#include "DriverLib/TIMERA/Driver/Intrinsics/Primitives/TIMERA_Primitives.h"
#include "DriverLib/TIMERA/Peripheral/TIMERA_Peripheral.h"

void TIMERA_CC__vSetEnableInterruptSource(TIMERA_nCC enModuleArg,
                                    TIMERA_nINT_ENABLE enState)
{
    TIMERA_Register_t pstRegisterData;

    pstRegisterData.uptrAddress = TIMERA_CC_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enState;
    pstRegisterData.u16Mask = (uint16_t) TIMERA_CC_CTL_IE_MASK;
    pstRegisterData.u8Shift = TIMERA_CC_CTL_R_IE_BIT;
    TIMERA_CC__vWriteRegister(enModuleArg,
                         &pstRegisterData);
}

void TIMERA_CC__vEnaInterruptSource(TIMERA_nCC enModuleArg)
{
    TIMERA_CC__vSetEnableInterruptSource(enModuleArg, TIMERA_enINT_ENABLE_ENA);
}

void TIMERA_CC__vDisInterruptSource(TIMERA_nCC enModuleArg)
{
    TIMERA_CC__vSetEnableInterruptSource(enModuleArg, TIMERA_enINT_ENABLE_DIS);
}

TIMERA_nINT_ENABLE TIMERA_CC__enGetEnableInterruptSource(TIMERA_nCC enModuleArg)
{
    TIMERA_Register_t pstRegisterData;
    TIMERA_nINT_ENABLE enEnable = TIMERA_enINT_ENABLE_DIS;

    pstRegisterData.uptrAddress = TIMERA_CC_CTL_OFFSET;
    pstRegisterData.u16Mask = TIMERA_CC_CTL_IE_MASK;
    pstRegisterData.u8Shift = TIMERA_CC_CTL_R_IE_BIT;
    enEnable = (TIMERA_nINT_ENABLE) TIMERA_CC__u16ReadRegister(enModuleArg,
                                                &pstRegisterData);
    return (enEnable);
}



void TIMERA__vSetEnableInterruptSource(TIMERA_nINT_ENABLE enState)
{
    TIMERA_Register_t pstRegisterData;

    pstRegisterData.uptrAddress = TIMERA_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enState;
    pstRegisterData.u16Mask = (uint16_t) TIMERA_CTL_IE_MASK;
    pstRegisterData.u8Shift = TIMERA_CTL_R_IE_BIT;
    TIMERA__vWriteRegister(&pstRegisterData);
}

void TIMERA__vEnaInterruptSource(void)
{
    TIMERA__vSetEnableInterruptSource(TIMERA_enINT_ENABLE_ENA);
}

void TIMERA__vDisInterruptSource(void)
{
    TIMERA__vSetEnableInterruptSource(TIMERA_enINT_ENABLE_DIS);
}

TIMERA_nINT_ENABLE TIMERA__enGetEnableInterruptSource(void)
{
    TIMERA_Register_t pstRegisterData;
    TIMERA_nINT_ENABLE enEnable = TIMERA_enINT_ENABLE_DIS;

    pstRegisterData.uptrAddress = TIMERA_CTL_OFFSET;
    pstRegisterData.u16Mask = TIMERA_CTL_IE_MASK;
    pstRegisterData.u8Shift = TIMERA_CTL_R_IE_BIT;
    enEnable = (TIMERA_nINT_ENABLE) TIMERA__u16ReadRegister(&pstRegisterData);
    return (enEnable);
}
