/**
 *
 * @file ADC12_RegisterDefines_CH_MEM.h
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
 * @verbatim 20 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 20 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRCH_MEMERLIB_ADC12_PERIPHERAL_REGISTERDEFINES_HEADER_ADC12_REGISTERDEFINES_CH_MEM_H_
#define DRCH_MEMERLIB_ADC12_PERIPHERAL_REGISTERDEFINES_HEADER_ADC12_REGISTERDEFINES_CH_MEM_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

/******************************************************************************************
 ************************************ 7 CH_MEM *********************************************
 ******************************************************************************************/
/*-----------*/
#define ADC12_CH_MEM_R_MEM_BIT ((uint16_t) 0U)

#define ADC12_CH_MEM_MEM_MASK ((uint16_t) 0xFFFFU)

#define ADC12_CH_MEM_R_MEM_MASK (ADC12_CH_MEM_MEM_MASK << ADC12_CH_MEM_R_MEM_BIT)
/*-----------*/






#endif /* DRCH_MEMERLIB_ADC12_PERIPHERAL_REGISTERDEFINES_HEADER_ADC12_REGISTERDEFINES_CH_MEM_H_ */
