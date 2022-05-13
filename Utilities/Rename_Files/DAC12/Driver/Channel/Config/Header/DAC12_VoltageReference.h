/**
 *
 * @file DAC12_VoltageReference.h
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

#ifndef DRIVERLIB_DAC12_DRIVER_CHANNEL_CONFIG_HEADER_DAC12_VOLTAGEREFERENCE_H_
#define DRIVERLIB_DAC12_DRIVER_CHANNEL_CONFIG_HEADER_DAC12_VOLTAGEREFERENCE_H_

#include "DriverLib/DAC12/Peripheral/Header/DAC12_Enum.h"

void DAC12_CH__vSetVoltageRefPositive(DAC12_nCH enChannelArg,
                                             DAC12_nVREFP enVoltageRefArg);
DAC12_nVREFP DAC12_CH__enGetVoltageRefPositive(DAC12_nCH enChannelArg);

void DAC12_CH__vSetVoltageRefNegative(DAC12_nCH enChannelArg,
                                             DAC12_nVREFN enVoltageRefArg);
DAC12_nVREFN DAC12_CH__enGetVoltageRefNegative(DAC12_nCH enChannelArg);

#endif /* DRIVERLIB_DAC12_DRIVER_CHANNEL_CONFIG_HEADER_DAC12_VOLTAGEREFERENCE_H_ */
