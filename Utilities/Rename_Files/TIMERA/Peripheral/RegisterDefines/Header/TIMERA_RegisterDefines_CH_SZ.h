/**
 *
 * @file DMA_RegisterDefines_CH_SZ.h
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
 * @verbatim 6 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 6 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DMA_PERIPHERAL_REGISTERDEFINES_HEADER_DMA_REGISTERDEFINES_CH_SZ_H_
#define DMA_PERIPHERAL_REGISTERDEFINES_HEADER_DMA_REGISTERDEFINES_CH_SZ_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

/******************************************************************************************
 ************************************ 6 CH_SZ *********************************************
 ******************************************************************************************/
/*-----------*/
#define DMA_CH_SZ_R_SZ_BIT ((uint16_t) 0U)

#define DMA_CH_SZ_SZ_MASK ((uint16_t) 0xFFFFU)

#define DMA_CH_SZ_R_SZ_MASK (DMA_CH_SZ_SZ_MASK << DMA_CH_SZ_R_SZ_BIT)
/*-----------*/

#endif /* DMA_PERIPHERAL_REGISTERDEFINES_HEADER_DMA_REGISTERDEFINES_CH_SZ_H_ */
