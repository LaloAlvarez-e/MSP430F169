/**
 *
 * @file DMA_DataSize.h
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

#ifndef DRIVERLIB_DMA_DRIVER_CHANNEL_CONFIG_HEADER_DMA_DATASIZE_H_
#define DRIVERLIB_DMA_DRIVER_CHANNEL_CONFIG_HEADER_DMA_DATASIZE_H_

#include "DriverLib/DMA/Peripheral/Header/DMA_Enum.h"

void DMA_CH__vSetSourceDataSize(DMA_nCH enChannelArg,
                            DMA_nCH_DATASIZE enSizeArg);
void DMA_CH__vSetDestDataSize(DMA_nCH enChannelArg,
                            DMA_nCH_DATASIZE enSizeArg);

DMA_nCH_DATASIZE DMA_CH__enGetSourceDataSize(DMA_nCH enChannelArg);
DMA_nCH_DATASIZE DMA_CH__enGetDestDataSize(DMA_nCH enChannelArg);


#endif /* DRIVERLIB_DMA_DRIVER_CHANNEL_CONFIG_HEADER_DMA_DATASIZE_H_ */
