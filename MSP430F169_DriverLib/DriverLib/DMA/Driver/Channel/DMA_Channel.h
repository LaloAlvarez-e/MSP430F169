/**
 *
 * @file DMA_Channel.h
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

#ifndef DRIVERLIB_DMA_DRIVER_CHANNEL_DMA_CHANNEL_H_
#define DRIVERLIB_DMA_DRIVER_CHANNEL_DMA_CHANNEL_H_

#include "DriverLib/DMA/Driver/Channel/Config/DMA_Config.h"
#include "DriverLib/DMA/Driver/Channel/Header/DMA_DestAddress.h"
#include "DriverLib/DMA/Driver/Channel/Header/DMA_SourceAddress.h"
#include "DriverLib/DMA/Driver/Channel/Header/DMA_TransferSize.h"
#include "DriverLib/DMA/Driver/Channel/Header/DMA_Trigger.h"


void DMA__vSetChannelConfig(DMA_nCH enChannelArg,
                         DMA_CH_Config_t* pstConfigArg);
void DMA__vSetChannelExtendedConfig(DMA_nCH enChannelArg,
                                 DMA_CH_ConfigExt_t* pstConfigArg);


void DMA__vGetChannelConfig(DMA_nCH enChannelArg,
                         DMA_CH_Config_t* pstConfigArg);
void DMA__vGetChannelExtendedConfig(DMA_nCH enChannelArg,
                         DMA_CH_ConfigExt_t* pstConfigArg);

#endif /* DRIVERLIB_DMA_DRIVER_CHANNEL_DMA_CHANNEL_H_ */
