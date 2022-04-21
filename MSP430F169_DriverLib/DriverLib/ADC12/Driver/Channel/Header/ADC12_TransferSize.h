/**
 *
 * @file ADC12_TransferSize.h
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

#ifndef DRIVERLIB_ADC12_DRIVER_HEADER_ADC12_TRANSFERSIZE_H_
#define DRIVERLIB_ADC12_DRIVER_HEADER_ADC12_TRANSFERSIZE_H_

#include "DriverLib/ADC12/Peripheral/Header/ADC12_Enum.h"

void ADC12__vSetTransferSize(ADC12_nCH enChannelArg,
                         uint16_t u16SizeArg);

uint16_t ADC12__u16GetTransferSize(ADC12_nCH enChannelArg);

#endif /* DRIVERLIB_ADC12_DRIVER_HEADER_ADC12_TRANSFERSIZE_H_ */
