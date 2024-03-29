/**
 *
 * @file SVS_Flag.c
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
#include "DriverLib/SVS/Driver/Header/SVS_Flag.h"

#include "DriverLib/SVS/Driver/Intrinsics/Primitives/SVS_Primitives.h"
#include "DriverLib/SVS/Peripheral/SVS_Peripheral.h"


void SVS__vSetFlagStatus(SVS_nFLAG enFlagStatusArg)
{
    SVS_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = SVS_CTL_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enFlagStatusArg;
    pstRegisterData.u8Mask = SVS_CTL_FG_MASK;
    pstRegisterData.u8Shift = SVS_CTL_R_FG_BIT;

    SVS__vWriteRegister(&pstRegisterData);
}

void SVS__vClearFlagStatus(void)
{
    SVS__vSetFlagStatus(SVS_enFLAG_CLEAR);
}

SVS_nFLAG SVS__enGetFlagStatus(void)
{
    SVS_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = SVS_CTL_OFFSET;
    pstRegisterData.u8Value = (uint8_t) SVS_enFLAG_CLEAR;
    pstRegisterData.u8Mask = SVS_CTL_FG_MASK;
    pstRegisterData.u8Shift = SVS_CTL_R_FG_BIT;
    (void) SVS__u8ReadRegister(&pstRegisterData);

    return ((SVS_nFLAG) pstRegisterData.u8Value);
}

