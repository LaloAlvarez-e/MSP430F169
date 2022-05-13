/**
 *
 * @file DAC12_SamplingCycles.h
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

#ifndef DRIVERLIB_DAC12_DRIVER_GLOBAL_HEADER_DAC12_SAMPLINGCYCLES_H_
#define DRIVERLIB_DAC12_DRIVER_GLOBAL_HEADER_DAC12_SAMPLINGCYCLES_H_

#include "DriverLib/DAC12/Peripheral/Header/DAC12_Enum.h"

void DAC12__vSetTimerSamplingCycles_LowChannels(DAC12_nSAMPLECYCLES enValueArg);
DAC12_nSAMPLECYCLES DAC12__enGetTimerSamplingCycles_LowChannels(void);

void DAC12__vSetTimerSamplingCycles_HighChannels(DAC12_nSAMPLECYCLES enValueArg);
DAC12_nSAMPLECYCLES DAC12__enGetTimerSamplingCycles_HighChannels(void);

#endif /* DRIVERLIB_DAC12_DRIVER_GLOBAL_HEADER_DAC12_SAMPLINGCYCLES_H_ */
