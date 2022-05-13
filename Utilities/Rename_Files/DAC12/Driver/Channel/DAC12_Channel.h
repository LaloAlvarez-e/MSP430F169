/**
 *
 * @file DAC12_Channel.h
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

#ifndef DRIVERLIB_DAC12_DRIVER_CHANNEL_DAC12_CHANNEL_H_
#define DRIVERLIB_DAC12_DRIVER_CHANNEL_DAC12_CHANNEL_H_

#include "DriverLib/DAC12/Driver/Channel/Config/DAC12_Config.h"
#include "DriverLib/DAC12/Driver/Channel/Header/DAC12_ConversionValue.h"


void DAC12_CH__vSetConfig(DAC12_nCH enChannelArg,
                            DAC12_CH_Config_t* pstConfigArg);
void DAC12_CH__vSetConfigExt(DAC12_nCH enChannelArg,
                             DAC12_CH_ConfigExt_t* pstConfigArg);

void DAC12_CH__vGetConfig(DAC12_nCH enChannelArg,
                          DAC12_CH_Config_t* pstConfigArg);
void DAC12_CH__vGetConfigExt(DAC12_nCH enChannelArg,
                                DAC12_CH_ConfigExt_t* pstConfigArg);

#endif /* DRIVERLIB_DAC12_DRIVER_CHANNEL_DAC12_CHANNEL_H_ */
