/**
 *
 * @file ADC12_IncrementMode.h
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

#ifndef DRIVERLIB_ADC12_DRIVER_CHANNEL_CONFIG_HEADER_ADC12_INCREMENTMODE_H_
#define DRIVERLIB_ADC12_DRIVER_CHANNEL_CONFIG_HEADER_ADC12_INCREMENTMODE_H_

#include "DriverLib/ADC12/Peripheral/Header/ADC12_Enum.h"

void ADC12__vSetSourceIncrementMode(ADC12_nCH enChannelArg,
                            ADC12_nCH_INCMODE enIncModeArg);
void ADC12__vSetDestIncrementMode(ADC12_nCH enChannelArg,
                            ADC12_nCH_INCMODE enIncModeArg);

ADC12_nCH_INCMODE ADC12__enGetSourceIncrementMode(ADC12_nCH enChannelArg);
ADC12_nCH_INCMODE ADC12__enGetDestIncrementMode(ADC12_nCH enChannelArg);

#endif /* DRIVERLIB_ADC12_DRIVER_CHANNEL_CONFIG_HEADER_ADC12_INCREMENTMODE_H_ */
