/**
 *
 * @file DAC12_EndOfSequence.h
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

#ifndef DRIVERLIB_DAC12_DRIVER_CHANNEL_CONFIG_HEADER_DAC12_ENDOFSEQUENCE_H_
#define DRIVERLIB_DAC12_DRIVER_CHANNEL_CONFIG_HEADER_DAC12_ENDOFSEQUENCE_H_

#include "DriverLib/DAC12/Peripheral/Header/DAC12_Enum.h"

void DAC12_CH__vSetEndOfSequence(DAC12_nCH enChannelArg,
                          DAC12_nENABLE enEnableArg);
DAC12_nENABLE DAC12_CH__enGetEndOfSequence(DAC12_nCH enChannelArg);

#endif /* DRIVERLIB_DAC12_DRIVER_CHANNEL_CONFIG_HEADER_DAC12_ENDOFSEQUENCE_H_ */
