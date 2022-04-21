/**
 *
 * @file ADC12_Priority.c
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
 * @verbatim 27 mar. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 27 mar. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <DriverLib/ADC12/Driver/Global/Header/ADC12_Priority.h>
#include "DriverLib/ADC12/Driver/Intrinsics/ADC12_Intrinsics.h"
#include "DriverLib/ADC12/Peripheral/ADC12_Peripheral.h"

void ADC12__vSetPriorityMode(ADC12_nPRIORITY enPriorityArg)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL1_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enPriorityArg;
    pstRegisterData.u16Mask = ADC12_CTL1_ROUNDROBIN_MASK;
    pstRegisterData.u8Shift = ADC12_CTL1_R_ROUNDROBIN_BIT;
    ADC12__vWriteRegister(&pstRegisterData);
}

ADC12_nPRIORITY ADC12__enGetPriorityMode(void)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL1_OFFSET;
    pstRegisterData.u16Value = 0U;
    pstRegisterData.u16Mask = ADC12_CTL1_ROUNDROBIN_MASK;
    pstRegisterData.u8Shift = ADC12_CTL1_R_ROUNDROBIN_BIT;
    (void) ADC12__u16ReadRegister(&pstRegisterData);
    return ((ADC12_nPRIORITY) pstRegisterData.u16Value);
}



