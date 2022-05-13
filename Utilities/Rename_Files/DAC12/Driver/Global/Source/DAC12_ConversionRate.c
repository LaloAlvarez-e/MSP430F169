/**
 *
 * @file DAC12_ConversionRate.c
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
#include <DriverLib/DAC12/Driver/Global/Header/DAC12_ConversionRate.h>
#include "DriverLib/DAC12/Driver/Intrinsics/DAC12_Intrinsics.h"
#include "DriverLib/DAC12/Peripheral/DAC12_Peripheral.h"

void DAC12__vSetConversionRate(DAC12_nRATE enRateArg)
{
    DAC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enRateArg;
    pstRegisterData.u16Mask = DAC12_CTL0_MSC_MASK;
    pstRegisterData.u8Shift = DAC12_CTL0_R_MSC_BIT;
    DAC12__vWriteRegister(&pstRegisterData);
}

DAC12_nRATE DAC12__enGetConversionRate(void)
{
    DAC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CTL0_OFFSET;
    pstRegisterData.u16Value = (uint16_t) DAC12_enRATE_TRIGGER;
    pstRegisterData.u16Mask = DAC12_CTL0_MSC_MASK;
    pstRegisterData.u8Shift = DAC12_CTL0_R_MSC_BIT;
    (void) DAC12__u16ReadRegister(&pstRegisterData);
    return ((DAC12_nRATE) pstRegisterData.u16Value);
}





