/**
 *
 * @file DMA_Abort.h
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

#ifndef DRIVERLIB_DMA_DRIVER_CHANNEL_CONFIG_HEADER_DMA_ABORT_H_
#define DRIVERLIB_DMA_DRIVER_CHANNEL_CONFIG_HEADER_DMA_ABORT_H_

#include "DriverLib/DMA/Peripheral/Header/DMA_Enum.h"

void DMA_CH__vSetAbort(DMA_nCH enChannelArg,
                     DMA_nCH_ABORT enAbortArg);

void DMA_CH__vClearAbort(DMA_nCH enChannelArg);

DMA_nCH_ABORT DMA_CH__enGetAbort(DMA_nCH enChannelArg);

#endif /* DRIVERLIB_DMA_DRIVER_CHANNEL_CONFIG_HEADER_DMA_ABORT_H_ */
