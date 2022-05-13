/**
 *
 * @file DAC12_ClockSource.c
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
#include <DriverLib/DAC12/Driver/Global/Header/DAC12_ClockSource.h>
#include "DriverLib/DAC12/Driver/Intrinsics/DAC12_Intrinsics.h"
#include "DriverLib/DAC12/Peripheral/DAC12_Peripheral.h"

void DAC12__vSetClockSource(DAC12_nCLOCK enClockArg)
{
    DAC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CTL1_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enClockArg;
    pstRegisterData.u16Mask = DAC12_CTL1_SSEL_MASK;
    pstRegisterData.u8Shift = DAC12_CTL1_R_SSEL_BIT;
    DAC12__vWriteRegister(&pstRegisterData);
}


DAC12_nCLOCK DAC12__enGetClockSource(void)
{
    DAC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CTL1_OFFSET;
    pstRegisterData.u16Value = (uint16_t) DAC12_enCLOCK_DAC12OSC;
    pstRegisterData.u16Mask = DAC12_CTL1_SSEL_MASK;
    pstRegisterData.u8Shift = DAC12_CTL1_R_SSEL_BIT;
    (void) DAC12__u16ReadRegister(&pstRegisterData);
    return ((DAC12_nCLOCK) pstRegisterData.u16Value);
}



