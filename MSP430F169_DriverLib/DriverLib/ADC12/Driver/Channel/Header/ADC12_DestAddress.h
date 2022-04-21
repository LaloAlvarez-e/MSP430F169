/**
 *
 * @file ADC12_DestAddress.h
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
 * @verbatim 25 mar. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 25 mar. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_ADC12_DRIVER_HEADER_ADC12_DESTADDRESS_H_
#define DRIVERLIB_ADC12_DRIVER_HEADER_ADC12_DESTADDRESS_H_

#include "DriverLib/ADC12/Peripheral/Header/ADC12_Enum.h"

void ADC12__vSetDestAddress(ADC12_nCH enChannelArg,
                         uint16_t u16AddressArg);

uint16_t ADC12__u16GetDestAddress(ADC12_nCH enChannelArg);

#endif /* DRIVERLIB_ADC12_DRIVER_HEADER_ADC12_DESTADDRESS_H_ */
