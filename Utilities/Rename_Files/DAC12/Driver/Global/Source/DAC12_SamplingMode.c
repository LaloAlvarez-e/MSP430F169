/**
 *
 * @file DAC12_SamplingMode.c
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
 * @verbatim 22 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 22 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <DriverLib/DAC12/Driver/Global/Header/DAC12_SamplingMode.h>
#include "DriverLib/DAC12/Driver/Intrinsics/DAC12_Intrinsics.h"
#include "DriverLib/DAC12/Peripheral/DAC12_Peripheral.h"

void DAC12__vSetSamplingMode(DAC12_nSAMPLEMODE enModeArg)
{
    DAC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CTL1_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enModeArg;
    pstRegisterData.u16Mask = DAC12_CTL1_SHP_MASK;
    pstRegisterData.u8Shift = DAC12_CTL1_R_SHP_BIT;
    DAC12__vWriteRegister(&pstRegisterData);
}


DAC12_nSAMPLEMODE DAC12__enGetSamplingMode(void)
{
    DAC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CTL1_OFFSET;
    pstRegisterData.u16Value = (uint16_t) DAC12_enSAMPLEMODE_TRIGGER;
    pstRegisterData.u16Mask = DAC12_CTL1_SHP_MASK;
    pstRegisterData.u8Shift = DAC12_CTL1_R_SHP_BIT;
    (void) DAC12__u16ReadRegister(&pstRegisterData);
    return ((DAC12_nSAMPLEMODE) pstRegisterData.u16Value);
}





