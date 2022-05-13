/**
 *
 * @file DAC12_ClockDivider.c
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
#include <DriverLib/DAC12/Driver/Global/Header/DAC12_ClockDivider.h>
#include "DriverLib/DAC12/Driver/Intrinsics/DAC12_Intrinsics.h"
#include "DriverLib/DAC12/Peripheral/DAC12_Peripheral.h"

void DAC12__vSetClockDivider(DAC12_nCLOCKDIV enClockDivArg)
{
    DAC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CTL1_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enClockDivArg;
    pstRegisterData.u16Mask = DAC12_CTL1_DIV_MASK;
    pstRegisterData.u8Shift = DAC12_CTL1_R_DIV_BIT;
    DAC12__vWriteRegister(&pstRegisterData);
}

void DAC12__vSetClockDividerByNumber(uint8_t u8ClockDivArg)
{
    if(0U != u8ClockDivArg)
    {
        u8ClockDivArg--;
        DAC12__vSetClockDivider((DAC12_nCLOCKDIV) u8ClockDivArg);
    }
}

DAC12_nCLOCKDIV DAC12__enGetClockDivider(void)
{
    DAC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CTL1_OFFSET;
    pstRegisterData.u16Value = (uint16_t) DAC12_enCLOCKDIV_1;
    pstRegisterData.u16Mask = DAC12_CTL1_DIV_MASK;
    pstRegisterData.u8Shift = DAC12_CTL1_R_DIV_BIT;
    (void) DAC12__u16ReadRegister(&pstRegisterData);
    return ((DAC12_nCLOCKDIV) pstRegisterData.u16Value);
}

uint8_t DAC12__u8SetClockDividerByNumber(void)
{
    DAC12_nCLOCKDIV enClockDiReg = DAC12_enCLOCKDIV_1;
    uint8_t u8ClockDivReg = 0U;

    enClockDiReg = DAC12__enGetClockDivider();
    u8ClockDivReg = (uint8_t) enClockDiReg;
    u8ClockDivReg++;
    return (u8ClockDivReg);
}



