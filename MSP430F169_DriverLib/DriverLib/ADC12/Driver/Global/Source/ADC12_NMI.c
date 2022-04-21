/**
 *
 * @file ADC12_NMI.c
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
#include <DriverLib/ADC12/Driver/Global/Header/ADC12_NMI.h>
#include "DriverLib/ADC12/Driver/Intrinsics/ADC12_Intrinsics.h"
#include "DriverLib/ADC12/Peripheral/ADC12_Peripheral.h"

void ADC12__vSetNMITranferStop(ADC12_nENABLE enNMIEnableArg)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL1_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enNMIEnableArg;
    pstRegisterData.u16Mask = ADC12_CTL1_ENNMI_MASK;
    pstRegisterData.u8Shift = ADC12_CTL1_R_ENNMI_BIT;
    ADC12__vWriteRegister(&pstRegisterData);
}

ADC12_nENABLE ADC12__enGetNMITranferStop(void)
{
    ADC12_Register16Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = ADC12_CTL1_OFFSET;
    pstRegisterData.u16Value = 0U;
    pstRegisterData.u16Mask = ADC12_CTL1_ENNMI_MASK;
    pstRegisterData.u8Shift = ADC12_CTL1_R_ENNMI_BIT;
    (void) ADC12__u16ReadRegister(&pstRegisterData);
    return ((ADC12_nENABLE) pstRegisterData.u16Value);
}





