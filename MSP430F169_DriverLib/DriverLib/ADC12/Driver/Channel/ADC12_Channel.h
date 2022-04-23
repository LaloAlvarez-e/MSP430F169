/**
 *
 * @file ADC12_Channel.h
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

#ifndef DRIVERLIB_ADC12_DRIVER_CHANNEL_ADC12_CHANNEL_H_
#define DRIVERLIB_ADC12_DRIVER_CHANNEL_ADC12_CHANNEL_H_

#include "DriverLib/ADC12/Driver/Channel/Config/ADC12_Config.h"
#include "DriverLib/ADC12/Driver/Channel/Header/ADC12_ConversionValue.h"


void ADC12_CH__vSetConfig(ADC12_nCH enChannelArg,
                            ADC12_CH_Config_t* pstConfigArg);
void ADC12_CH__vSetConfigExt(ADC12_nCH enChannelArg,
                             ADC12_CH_ConfigExt_t* pstConfigArg);

void ADC12_CH__vGetConfig(ADC12_nCH enChannelArg,
                          ADC12_CH_Config_t* pstConfigArg);
void ADC12_CH__vGetConfigExt(ADC12_nCH enChannelArg,
                                ADC12_CH_ConfigExt_t* pstConfigArg);

#endif /* DRIVERLIB_ADC12_DRIVER_CHANNEL_ADC12_CHANNEL_H_ */
