/**
 *
 * @file ADC12_ClockSource.c
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
#include <DriverLib/ADC12/Driver/Global/Header/ADC12_ClockSource.h>
#include "DriverLib/ADC12/Driver/Intrinsics/ADC12_Intrinsics.h"
#include "DriverLib/ADC12/Peripheral/ADC12_Peripheral.h"

void ADC12__vSetClockSource(ADC12_nCLOCK enClockArg)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL1_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enClockArg;
    pstRegisterData.u16Mask = ADC12_CTL1_SSEL_MASK;
    pstRegisterData.u8Shift = ADC12_CTL1_R_SSEL_BIT;
    ADC12__vWriteRegister(&pstRegisterData);
}


ADC12_nCLOCK ADC12__enGetClockSource(void)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL1_OFFSET;
    pstRegisterData.u16Value = (uint16_t) ADC12_enCLOCK_ADC12OSC;
    pstRegisterData.u16Mask = ADC12_CTL1_SSEL_MASK;
    pstRegisterData.u8Shift = ADC12_CTL1_R_SSEL_BIT;
    (void) ADC12__u16ReadRegister(&pstRegisterData);
    return ((ADC12_nCLOCK) pstRegisterData.u16Value);
}



