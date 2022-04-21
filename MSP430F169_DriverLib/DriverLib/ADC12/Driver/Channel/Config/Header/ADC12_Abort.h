/**
 *
 * @file ADC12_Abort.h
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
 * @verbatim 28 mar. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 28 mar. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_ADC12_DRIVER_CHANNEL_CONFIG_HEADER_ADC12_ABORT_H_
#define DRIVERLIB_ADC12_DRIVER_CHANNEL_CONFIG_HEADER_ADC12_ABORT_H_

#include "DriverLib/ADC12/Peripheral/Header/ADC12_Enum.h"

void ADC12__vSetAbort(ADC12_nCH enChannelArg,
                     ADC12_nCH_ABORT enAbortArg);

void ADC12__vClearAbort(ADC12_nCH enChannelArg);

ADC12_nCH_ABORT ADC12__enGetAbort(ADC12_nCH enChannelArg);

#endif /* DRIVERLIB_ADC12_DRIVER_CHANNEL_CONFIG_HEADER_ADC12_ABORT_H_ */
