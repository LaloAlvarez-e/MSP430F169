/**
 *
 * @file ADC12_BusyState.c
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
#include <DriverLib/ADC12/Driver/Global/Header/ADC12_BusyState.h>
#include "DriverLib/ADC12/Driver/Intrinsics/ADC12_Intrinsics.h"
#include "DriverLib/ADC12/Peripheral/ADC12_Peripheral.h"

ADC12_nBUSY ADC12__enGetBusyState(void)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL1_OFFSET;
    pstRegisterData.u16Value = (uint16_t) ADC12_enBUSY_IDLE;
    pstRegisterData.u16Mask = ADC12_CTL1_BUSY_MASK;
    pstRegisterData.u8Shift = ADC12_CTL1_R_BUSY_BIT;
    (void) ADC12__u16ReadRegister(&pstRegisterData);
    return ((ADC12_nBUSY) pstRegisterData.u16Value);
}

