/**
 *
 * @file SVS_Reset.c
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
 * @verbatim 10 mar. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 10 mar. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/SVS/Driver/Header/SVS_Reset.h"

#include "DriverLib/SVS/Driver/Intrinsics/Primitives/SVS_Primitives.h"
#include "DriverLib/SVS/Peripheral/SVS_Peripheral.h"


void SVS__vSetResetCause(SVS_nSTATE enResetStateArg)
{
    SVS_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = SVS_CTL_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enResetStateArg;
    pstRegisterData.u8Mask = SVS_CTL_PORON_MASK;
    pstRegisterData.u8Shift = SVS_CTL_R_PORON_BIT;

    SVS__vWriteRegister(&pstRegisterData);
}

SVS_nSTATE SVS__enGetResetCause(void)
{
    SVS_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = SVS_CTL_OFFSET;
    pstRegisterData.u8Value = (uint8_t) SVS_enSTATE_OFF;
    pstRegisterData.u8Mask = SVS_CTL_PORON_MASK;
    pstRegisterData.u8Shift = SVS_CTL_R_PORON_BIT;
    (void) SVS__u8ReadRegister(&pstRegisterData);

    return ((SVS_nFLAG) pstRegisterData.u8Value);
}



