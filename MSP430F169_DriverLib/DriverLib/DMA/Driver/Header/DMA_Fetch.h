/**
 *
 * @file DMA_Fetch.h
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

#ifndef DRIVERLIB_DMA_DRIVER_HEADER_DMA_FETCH_H_
#define DRIVERLIB_DMA_DRIVER_HEADER_DMA_FETCH_H_

#include "DriverLib/DMA/Peripheral/Header/DMA_Enum.h"

void DMA__vSetFetchMode(DMA_nFETCH enFetchModeArg);
DMA_nFETCH DMA__enGetFetchMode(void);

#endif /* DRIVERLIB_DMA_DRIVER_HEADER_DMA_FETCH_H_ */
