/**
 *
 * @file DAC12_BusyState.c
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
#include <DriverLib/DAC12/Driver/Global/Header/DAC12_BusyState.h>
#include "DriverLib/DAC12/Driver/Intrinsics/DAC12_Intrinsics.h"
#include "DriverLib/DAC12/Peripheral/DAC12_Peripheral.h"

DAC12_nBUSY DAC12__enGetBusyState(void)
{
    DAC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = DAC12_CTL1_OFFSET;
    pstRegisterData.u16Value = (uint16_t) DAC12_enBUSY_IDLE;
    pstRegisterData.u16Mask = DAC12_CTL1_BUSY_MASK;
    pstRegisterData.u8Shift = DAC12_CTL1_R_BUSY_BIT;
    (void) DAC12__u16ReadRegister(&pstRegisterData);
    return ((DAC12_nBUSY) pstRegisterData.u16Value);
}

