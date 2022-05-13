/**
 *
 * @file DAC12_ConversionTrigger.c
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
#include <DriverLib/DAC12/Driver/Global/Header/DAC12_ConversionTrigger.h>
#include "DriverLib/DAC12/Driver/Intrinsics/DAC12_Intrinsics.h"
#include "DriverLib/DAC12/Peripheral/DAC12_Peripheral.h"

void DAC12__vSetConversionTrigger(DAC12_nTRIGGER enTriggerArg)
{
    DAC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CTL1_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enTriggerArg;
    pstRegisterData.u16Mask = DAC12_CTL1_SHS_MASK;
    pstRegisterData.u8Shift = DAC12_CTL1_R_SHS_BIT;
    DAC12__vWriteRegister(&pstRegisterData);
}

DAC12_nTRIGGER DAC12__enGetConversionTrigger(void)
{
    DAC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CTL1_OFFSET;
    pstRegisterData.u16Value = (uint16_t) DAC12_enTRIGGER_SW;
    pstRegisterData.u16Mask = DAC12_CTL1_SHS_MASK;
    pstRegisterData.u8Shift = DAC12_CTL1_R_SHS_BIT;
    (void) DAC12__u16ReadRegister(&pstRegisterData);
    return ((DAC12_nTRIGGER) pstRegisterData.u16Value);
}


void DAC12__vSetConversionTriggerEdge(DAC12_nEDGE enEdgeArg)
{
    DAC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CTL1_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enEdgeArg;
    pstRegisterData.u16Mask = DAC12_CTL1_ISSH_MASK;
    pstRegisterData.u8Shift = DAC12_CTL1_R_ISSH_BIT;
    DAC12__vWriteRegister(&pstRegisterData);
}

DAC12_nEDGE DAC12__enGetConversionTriggerEdge(void)
{
    DAC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CTL1_OFFSET;
    pstRegisterData.u16Value = (uint16_t) DAC12_enEDGE_RISING;
    pstRegisterData.u16Mask = DAC12_CTL1_ISSH_MASK;
    pstRegisterData.u8Shift = DAC12_CTL1_R_ISSH_BIT;
    (void) DAC12__u16ReadRegister(&pstRegisterData);
    return ((DAC12_nEDGE) pstRegisterData.u16Value);
}




