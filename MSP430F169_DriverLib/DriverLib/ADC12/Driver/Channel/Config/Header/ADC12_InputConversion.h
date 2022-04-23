/**
 *
 * @file ADC12_InputConversion.h
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
 * @verbatim 23 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 23 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_ADC12_DRIVER_CHANNEL_CONFIG_HEADER_ADC12_INPUTCONVERSION_H_
#define DRIVERLIB_ADC12_DRIVER_CHANNEL_CONFIG_HEADER_ADC12_INPUTCONVERSION_H_

#include "DriverLib/ADC12/Peripheral/Header/ADC12_Enum.h"

void ADC12_CH__vSetInputConversion(ADC12_nCH enChannelArg,
                                   ADC12_nINPUT enInputArg);
ADC12_nINPUT ADC12_CH__enGetInputConversion(ADC12_nCH enChannelArg);

#endif /* DRIVERLIB_ADC12_DRIVER_CHANNEL_CONFIG_HEADER_ADC12_INPUTCONVERSION_H_ */
