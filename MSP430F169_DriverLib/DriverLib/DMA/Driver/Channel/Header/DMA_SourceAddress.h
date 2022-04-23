/**
 *
 * @file DMA_SourceAddress.h
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

#ifndef DRIVERLIB_DMA_DRIVER_HEADER_DMA_SOURCEADDRESS_H_
#define DRIVERLIB_DMA_DRIVER_HEADER_DMA_SOURCEADDRESS_H_

#include "DriverLib/DMA/Peripheral/Header/DMA_Enum.h"

void DMA_CH__vSetSourceAddress(DMA_nCH enChannelArg,
                         uint16_t u16AddressArg);

uint16_t DMA_CH__u16GetSourceAddress(DMA_nCH enChannelArg);

#endif /* DRIVERLIB_DMA_DRIVER_HEADER_DMA_SOURCEADDRESS_H_ */
