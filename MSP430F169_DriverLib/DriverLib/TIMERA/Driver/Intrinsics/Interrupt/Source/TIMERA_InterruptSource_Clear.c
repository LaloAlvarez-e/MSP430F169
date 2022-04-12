/**
 *
 * @file TIMERA_InterruptSource_Clear.c
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
#include "DriverLib/TIMERA/Driver/Intrinsics/Interrupt/Header/TIMERA_InterruptSource_Clear.h"

#include "DriverLib/TIMERA/Driver/Intrinsics/Primitives/TIMERA_Primitives.h"
#include "DriverLib/TIMERA/Peripheral/TIMERA_Peripheral.h"

void TIMERA_CC__vClearInterruptSource(TIMERA_nCC enModuleArg)
{
    TIMERA_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERA_CC_CTL_OFFSET;
    pstRegisterData.u16Value = TIMERA_CC_CTL_IFG_NOOCCUR;
    pstRegisterData.u16Mask = TIMERA_CC_CTL_IFG_MASK;
    pstRegisterData.u8Shift = TIMERA_CC_CTL_R_IFG_BIT;
    TIMERA_CC__vWriteRegister(enModuleArg,
                           &pstRegisterData);
}

void TIMERA__vClearInterruptSource(void)
{
    TIMERA_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERA_CTL_OFFSET;
    pstRegisterData.u16Value = TIMERA_CTL_IFG_NOOCCUR;
    pstRegisterData.u16Mask = TIMERA_CTL_IFG_MASK;
    pstRegisterData.u8Shift = TIMERA_CTL_R_IFG_BIT;
    TIMERA__vWriteRegister(&pstRegisterData);
}

