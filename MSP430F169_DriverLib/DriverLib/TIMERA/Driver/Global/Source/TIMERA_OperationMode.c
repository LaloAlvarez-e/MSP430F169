/**
 *
 * @file TIMERA_OperationMode.c
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
 * @verbatim 9 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 9 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <DriverLib/TIMERA/Driver/Global/Header/TIMERA_OperationMode.h>

#include "DriverLib/TIMERA/Driver/Intrinsics/TIMERA_Intrinsics.h"
#include "DriverLib/TIMERA/Peripheral/TIMERA_Peripheral.h"

void TIMERA__vSetOperationMode(TIMERA_nMODE enOperationModeArg)
{
    TIMERA_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERA_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enOperationModeArg;
    pstRegisterData.u16Mask = TIMERA_CTL_MC_MASK;
    pstRegisterData.u8Shift = TIMERA_CTL_R_MC_BIT;
    TIMERA__vWriteRegister(&pstRegisterData);
}

TIMERA_nMODE TIMERA__enGetOperationMode(void)
{
    TIMERA_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERA_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) TIMERA_enMODE_STOP;
    pstRegisterData.u16Mask = TIMERA_CTL_MC_MASK;
    pstRegisterData.u8Shift = TIMERA_CTL_R_MC_BIT;
    (void) TIMERA__u16ReadRegister(&pstRegisterData);
    return ((TIMERA_nMODE) pstRegisterData.u16Value);
}



