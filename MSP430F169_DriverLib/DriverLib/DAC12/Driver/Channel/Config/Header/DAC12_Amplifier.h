/**
 *
 * @file DAC12_Amplifier.h
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
 * @verbatim 11 may. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 11 may. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_DAC12_DRIVER_CHANNEL_CONFIG_HEADER_DAC12_AMPLIFIER_H_
#define DRIVERLIB_DAC12_DRIVER_CHANNEL_CONFIG_HEADER_DAC12_AMPLIFIER_H_

#include "DriverLib/DAC12/Peripheral/Header/DAC12_Enum.h"

void DAC12_CH__vSetAmplifier(DAC12_nCH enChannelArg,
                              DAC12_nAMPLIFIER enAmplifierArg);
DAC12_nAMPLIFIER DAC12_CH__enGetAmplifier(DAC12_nCH enChannelArg);

#endif /* DRIVERLIB_DAC12_DRIVER_CHANNEL_CONFIG_HEADER_DAC12_AMPLIFIER_H_ */
