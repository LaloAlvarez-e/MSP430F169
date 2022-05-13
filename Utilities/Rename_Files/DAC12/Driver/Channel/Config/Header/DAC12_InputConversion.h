/**
 *
 * @file DAC12_InputConversion.h
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

#ifndef DRIVERLIB_DAC12_DRIVER_CHANNEL_CONFIG_HEADER_DAC12_INPUTCONVERSION_H_
#define DRIVERLIB_DAC12_DRIVER_CHANNEL_CONFIG_HEADER_DAC12_INPUTCONVERSION_H_

#include "DriverLib/DAC12/Peripheral/Header/DAC12_Enum.h"

void DAC12_CH__vSetInputConversion(DAC12_nCH enChannelArg,
                                   DAC12_nINPUT enInputArg);
DAC12_nINPUT DAC12_CH__enGetInputConversion(DAC12_nCH enChannelArg);

#endif /* DRIVERLIB_DAC12_DRIVER_CHANNEL_CONFIG_HEADER_DAC12_INPUTCONVERSION_H_ */
