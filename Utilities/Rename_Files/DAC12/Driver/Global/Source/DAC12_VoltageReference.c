/**
 *
 * @file DAC12_VoltageReference.c
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
 * @verbatim 21 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 21 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <DriverLib/DAC12/Driver/Global/Header/DAC12_VoltageReference.h>
#include "DriverLib/DAC12/Driver/Intrinsics/DAC12_Intrinsics.h"
#include "DriverLib/DAC12/Peripheral/DAC12_Peripheral.h"

void DAC12__vSetVREFState(DAC12_nSTATE enStateArg)
{
    DAC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enStateArg;
    pstRegisterData.u16Mask = DAC12_CTL0_REFON_MASK;
    pstRegisterData.u8Shift = DAC12_CTL0_R_REFON_BIT;
    DAC12__vWriteRegister(&pstRegisterData);
}

void DAC12__vPowerOnVREF(void)
{
    DAC12__vSetVREFState(DAC12_enSTATE_ON);
}

void DAC12__vPowerOffVREF(void)
{
    DAC12__vSetVREFState(DAC12_enSTATE_OFF);
}

DAC12_nSTATE DAC12__enGetVREFState(void)
{
    DAC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) DAC12_enSTATE_OFF;
    pstRegisterData.u16Mask = DAC12_CTL0_REFON_MASK;
    pstRegisterData.u8Shift = DAC12_CTL0_R_REFON_BIT;
    (void) DAC12__u16ReadRegister(&pstRegisterData);
    return ((DAC12_nSTATE) pstRegisterData.u16Value);
}


void DAC12__vSetVREFValue(DAC12_nVREF enValueArg)
{
    DAC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enValueArg;
    pstRegisterData.u16Mask = DAC12_CTL0_REF2_5V_MASK;
    pstRegisterData.u8Shift = DAC12_CTL0_R_REF2_5V_BIT;
    DAC12__vWriteRegister(&pstRegisterData);
}


DAC12_nVREF DAC12__enGetVREFValue(void)
{
    DAC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) DAC12_enVREF_1_5V;
    pstRegisterData.u16Mask = DAC12_CTL0_REF2_5V_MASK;
    pstRegisterData.u8Shift = DAC12_CTL0_R_REF2_5V_BIT;
    (void) DAC12__u16ReadRegister(&pstRegisterData);
    return ((DAC12_nVREF) pstRegisterData.u16Value);
}



