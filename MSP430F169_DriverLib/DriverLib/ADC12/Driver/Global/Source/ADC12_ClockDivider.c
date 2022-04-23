/**
 *
 * @file ADC12_ClockDivider.c
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
#include <DriverLib/ADC12/Driver/Global/Header/ADC12_ClockDivider.h>
#include "DriverLib/ADC12/Driver/Intrinsics/ADC12_Intrinsics.h"
#include "DriverLib/ADC12/Peripheral/ADC12_Peripheral.h"

void ADC12__vSetClockDivider(ADC12_nCLOCKDIV enClockDivArg)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL1_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enClockDivArg;
    pstRegisterData.u16Mask = ADC12_CTL1_DIV_MASK;
    pstRegisterData.u8Shift = ADC12_CTL1_R_DIV_BIT;
    ADC12__vWriteRegister(&pstRegisterData);
}

void ADC12__vSetClockDividerByNumber(uint8_t u8ClockDivArg)
{
    if(0U != u8ClockDivArg)
    {
        u8ClockDivArg--;
        ADC12__vSetClockDivider((ADC12_nCLOCKDIV) u8ClockDivArg);
    }
}

ADC12_nCLOCKDIV ADC12__enGetClockDivider(void)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL1_OFFSET;
    pstRegisterData.u16Value = (uint16_t) ADC12_enCLOCKDIV_1;
    pstRegisterData.u16Mask = ADC12_CTL1_DIV_MASK;
    pstRegisterData.u8Shift = ADC12_CTL1_R_DIV_BIT;
    (void) ADC12__u16ReadRegister(&pstRegisterData);
    return ((ADC12_nCLOCKDIV) pstRegisterData.u16Value);
}

uint8_t ADC12__u8SetClockDividerByNumber(void)
{
    ADC12_nCLOCKDIV enClockDiReg = ADC12_enCLOCKDIV_1;
    uint8_t u8ClockDivReg = 0U;

    enClockDiReg = ADC12__enGetClockDivider();
    u8ClockDivReg = (uint8_t) enClockDiReg;
    u8ClockDivReg++;
    return (u8ClockDivReg);
}



