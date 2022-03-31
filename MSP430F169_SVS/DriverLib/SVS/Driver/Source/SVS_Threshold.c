/**
 *
 * @file SVS_Threshold.c
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
 * @verbatim 12 mar. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 12 mar. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/SVS/Driver/Header/SVS_Threshold.h"

#include "DriverLib/SVS/Driver/Intrinsics/Primitives/SVS_Primitives.h"
#include "DriverLib/SVS/Peripheral/SVS_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

#define THRESHOLD_VALUES (16U)

static const uint16_t SVS_pu16Threshold[THRESHOLD_VALUES] =
{
    0U,
    1200U,
    1900U,
    2100U,
    2200U,
    2300U,
    2400U,
    2500U,
    2650U,
    2800U,
    2900U,
    3050U,
    3200U,
    3350U,
    3500U,
    3700U,
};


void SVS__vSetThreshold(SVS_nTHRESHOLD enthresholdArg)
{
    SVS_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = SVS_CTL_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enthresholdArg;
    pstRegisterData.u8Mask = SVS_CTL_VLD_MASK;
    pstRegisterData.u8Shift = SVS_CTL_R_VLD_BIT;

    SVS__vWriteRegister(&pstRegisterData);
}

SVS_nTHRESHOLD SVS__enGetThreshold(void)
{
    SVS_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = SVS_CTL_OFFSET;
    pstRegisterData.u8Value = (uint8_t) SVS_enTHRESHOLD_OFF;
    pstRegisterData.u8Mask = SVS_CTL_VLD_MASK;
    pstRegisterData.u8Shift = SVS_CTL_R_VLD_BIT;
    (void) SVS__u8ReadRegister(&pstRegisterData);

    return ((SVS_nTHRESHOLD) pstRegisterData.u8Value);
}


void SVS__vSetThreshold_mV(uint16_t u16ThresholdArg)
{
    uint16_t u16Index = 0U;
    SVS_nTHRESHOLD enThresholdReg = SVS_enTHRESHOLD_OFF;
    u16Index = MCU__u16GetNearArrayIndex_16Bits(SVS_pu16Threshold, u16ThresholdArg, THRESHOLD_VALUES);

    if(1U == u16Index)
    {
        u16Index = SVS_enTHRESHOLD_1_2V_EXT;
    }
    else if(0U != u16Index)
    {
        u16Index--;
        enThresholdReg = (SVS_nTHRESHOLD) u16Index;
    }
    SVS__vSetThreshold(enThresholdReg);
}


uint16_t SVS__u16GetThreshold_mV(void)
{
    uint16_t u16ThresholdReg = 0U;
    uint16_t u16Index = 0U;
    SVS_nTHRESHOLD enThresholdReg = SVS_enTHRESHOLD_OFF;

    enThresholdReg = SVS__enGetThreshold();

    if(SVS_enTHRESHOLD_1_2V_EXT == enThresholdReg)
    {
        u16Index = 1U;
    }
    else if(SVS_enTHRESHOLD_OFF != enThresholdReg)
    {
        u16Index = (uint16_t) enThresholdReg;
        u16Index++;
    }
    u16ThresholdReg = SVS_pu16Threshold[u16Index];
    return (u16ThresholdReg);

}

