/**
 *
 * @file ADC12_SamplingCycles.h
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

#ifndef DRIVERLIB_ADC12_DRIVER_GLOBAL_HEADER_ADC12_SAMPLINGCYCLES_H_
#define DRIVERLIB_ADC12_DRIVER_GLOBAL_HEADER_ADC12_SAMPLINGCYCLES_H_

#include "DriverLib/ADC12/Peripheral/Header/ADC12_Enum.h"

void ADC12__vSetTimerSamplingCycles_LowChannels(ADC12_nSAMPLECYCLES enValueArg);
ADC12_nSAMPLECYCLES ADC12__enGetTimerSamplingCycles_LowChannels(void);

void ADC12__vSetTimerSamplingCycles_HighChannels(ADC12_nSAMPLECYCLES enValueArg);
ADC12_nSAMPLECYCLES ADC12__enGetTimerSamplingCycles_HighChannels(void);

#endif /* DRIVERLIB_ADC12_DRIVER_GLOBAL_HEADER_ADC12_SAMPLINGCYCLES_H_ */
