 /**
 *
 * @file ADC12_EnableConversion.h
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
 * @verbatim 21 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 21 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_ADC12_DRIVER_GLOBAL_HEADER_ADC12_ENABLECONVERSION_H_
#define DRIVERLIB_ADC12_DRIVER_GLOBAL_HEADER_ADC12_ENABLECONVERSION_H_

#include "DriverLib/ADC12/Peripheral/Header/ADC12_Enum.h"

void ADC12__vSetEnableConversion(ADC12_nENABLE enEnableArg);
void ADC12__vEnableConversion(void);
void ADC12__vDisableConversion(void);
void ADC12__vRestartEnableConversion(void);

ADC12_nENABLE ADC12__enGetEnableConversion(void);

#endif /* DRIVERLIB_ADC12_DRIVER_GLOBAL_HEADER_ADC12_ENABLECONVERSION_H_ */
