/**
 *
 * @file TIMERA_InterruptSource_Status.c
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
#include "DriverLib/TIMERA/Driver/Intrinsics/Interrupt/Header/TIMERA_InterruptSource_Status.h"

#include "DriverLib/TIMERA/Driver/Intrinsics/Primitives/TIMERA_Primitives.h"
#include "DriverLib/TIMERA/Peripheral/TIMERA_Peripheral.h"

void TIMERA_CC__vSetStatusInterruptSource(TIMERA_nCC enModuleArg,
                                    TIMERA_nINT_STATUS enStatus)
{
    TIMERA_Register_t pstRegisterData;

    pstRegisterData.uptrAddress = TIMERA_CC_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enStatus;
    pstRegisterData.u16Mask = TIMERA_CC_CTL_IFG_MASK;
    pstRegisterData.u8Shift = TIMERA_CC_CTL_R_IFG_BIT;
    TIMERA_CC__vWriteRegister(enModuleArg,
                         &pstRegisterData);
}

TIMERA_nINT_STATUS TIMERA_CC__enGetStatusInterruptSource(TIMERA_nCC enModuleArg)
{
    TIMERA_Register_t pstRegisterData;
    TIMERA_nINT_STATUS enStatus = TIMERA_enINT_STATUS_NOOCCUR;

    pstRegisterData.uptrAddress = TIMERA_CC_CTL_OFFSET;
    pstRegisterData.u16Mask = TIMERA_CC_CTL_IFG_MASK;
    pstRegisterData.u8Shift = TIMERA_CC_CTL_R_IFG_BIT;

    enStatus = (TIMERA_nINT_STATUS) TIMERA_CC__u16ReadRegister(enModuleArg,
                                                &pstRegisterData);
    return (enStatus);
}


void TIMERA__vSetStatusInterruptSource(TIMERA_nINT_STATUS enStatus)
{
    TIMERA_Register_t pstRegisterData;

    pstRegisterData.uptrAddress = TIMERA_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enStatus;
    pstRegisterData.u16Mask = TIMERA_CTL_IFG_MASK;
    pstRegisterData.u8Shift = TIMERA_CTL_R_IFG_BIT;
    TIMERA__vWriteRegister( &pstRegisterData);
}

TIMERA_nINT_STATUS TIMERA__enGetStatusInterruptSource(void)
{
    TIMERA_Register_t pstRegisterData;
    TIMERA_nINT_STATUS enStatus = TIMERA_enINT_STATUS_NOOCCUR;

    pstRegisterData.uptrAddress = TIMERA_CTL_OFFSET;
    pstRegisterData.u16Mask = TIMERA_CTL_IFG_MASK;
    pstRegisterData.u8Shift = TIMERA_CTL_R_IFG_BIT;

    enStatus = (TIMERA_nINT_STATUS) TIMERA__u16ReadRegister(&pstRegisterData);
    return (enStatus);
}


