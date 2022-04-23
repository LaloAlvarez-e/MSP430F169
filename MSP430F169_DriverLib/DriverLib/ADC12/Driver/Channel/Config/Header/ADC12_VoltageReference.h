/**
 *
 * @file ADC12_VoltageReference.h
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

#ifndef DRIVERLIB_ADC12_DRIVER_CHANNEL_CONFIG_HEADER_ADC12_VOLTAGEREFERENCE_H_
#define DRIVERLIB_ADC12_DRIVER_CHANNEL_CONFIG_HEADER_ADC12_VOLTAGEREFERENCE_H_

#include "DriverLib/ADC12/Peripheral/Header/ADC12_Enum.h"

void ADC12_CH__vSetVoltageRefPositive(ADC12_nCH enChannelArg,
                                             ADC12_nVREFP enVoltageRefArg);
ADC12_nVREFP ADC12_CH__enGetVoltageRefPositive(ADC12_nCH enChannelArg);

void ADC12_CH__vSetVoltageRefNegative(ADC12_nCH enChannelArg,
                                             ADC12_nVREFN enVoltageRefArg);
ADC12_nVREFN ADC12_CH__enGetVoltageRefNegative(ADC12_nCH enChannelArg);

#endif /* DRIVERLIB_ADC12_DRIVER_CHANNEL_CONFIG_HEADER_ADC12_VOLTAGEREFERENCE_H_ */
