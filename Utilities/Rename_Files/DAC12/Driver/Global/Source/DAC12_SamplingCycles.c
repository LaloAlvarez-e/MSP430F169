/**
 *
 * @file DAC12_SamplingCycles.c
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
#include <DriverLib/DAC12/Driver/Global/Header/DAC12_SamplingCycles.h>
#include "DriverLib/DAC12/Driver/Intrinsics/DAC12_Intrinsics.h"
#include "DriverLib/DAC12/Peripheral/DAC12_Peripheral.h"

void DAC12__vSetTimerSamplingCycles_LowChannels(DAC12_nSAMPLECYCLES enValueArg)
{
    DAC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enValueArg;
    pstRegisterData.u16Mask = DAC12_CTL0_SHT0_MASK;
    pstRegisterData.u8Shift = DAC12_CTL0_R_SHT0_BIT;
    DAC12__vWriteRegister(&pstRegisterData);
}


DAC12_nSAMPLECYCLES DAC12__enGetTimerSamplingCycles_LowChannels(void)
{
    DAC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) DAC12_enSAMPLECYCLES_4;
    pstRegisterData.u16Mask = DAC12_CTL0_SHT0_MASK;
    pstRegisterData.u8Shift = DAC12_CTL0_R_SHT0_BIT;
    (void) DAC12__u16ReadRegister(&pstRegisterData);
    return ((DAC12_nSAMPLECYCLES) pstRegisterData.u16Value);
}


void DAC12__vSetTimerSamplingCycles_HighChannels(DAC12_nSAMPLECYCLES enValueArg)
{
    DAC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enValueArg;
    pstRegisterData.u16Mask = DAC12_CTL0_SHT1_MASK;
    pstRegisterData.u8Shift = DAC12_CTL0_R_SHT1_BIT;
    DAC12__vWriteRegister(&pstRegisterData);
}


DAC12_nSAMPLECYCLES DAC12__enGetTimerSamplingCycles_HighChannels(void)
{
    DAC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) DAC12_enSAMPLECYCLES_4;
    pstRegisterData.u16Mask = DAC12_CTL0_SHT1_MASK;
    pstRegisterData.u8Shift = DAC12_CTL0_R_SHT1_BIT;
    (void) DAC12__u16ReadRegister(&pstRegisterData);
    return ((DAC12_nSAMPLECYCLES) pstRegisterData.u16Value);
}





