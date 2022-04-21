/**
 *
 * @file ADC12_Abort.c
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
 * @verbatim 28 mar. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 28 mar. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <DriverLib/ADC12/Driver/Channel/Config/Header/ADC12_Abort.h>
#include "DriverLib/ADC12/Driver/Intrinsics/ADC12_Intrinsics.h"
#include "DriverLib/ADC12/Peripheral/ADC12_Peripheral.h"

void ADC12__vSetAbort(ADC12_nCH enChannelArg,
                      ADC12_nCH_ABORT enAbortArg)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CH_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enAbortArg;
    pstRegisterData.u16Mask = ADC12_CH_CTL_ABORT_MASK;
    pstRegisterData.u8Shift = ADC12_CH_CTL_R_ABORT_BIT;
    ADC12_CH__vWriteRegister_16bits(enChannelArg,
                         &pstRegisterData);
}

void ADC12__vClearAbort(ADC12_nCH enChannelArg)
{
    ADC12__vSetAbort(enChannelArg, ADC12_enCH_ABORT_CLEAR);
}

ADC12_nCH_ABORT ADC12__enGetAbort(ADC12_nCH enChannelArg)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CH_CTL_OFFSET;
    pstRegisterData.u16Value = 0U;
    pstRegisterData.u16Mask = ADC12_CH_CTL_ABORT_MASK;
    pstRegisterData.u8Shift = ADC12_CH_CTL_R_ABORT_BIT;
    (void) ADC12_CH__u16ReadRegister(enChannelArg, &pstRegisterData);
    return ((ADC12_nCH_ABORT) pstRegisterData.u16Value);
}



