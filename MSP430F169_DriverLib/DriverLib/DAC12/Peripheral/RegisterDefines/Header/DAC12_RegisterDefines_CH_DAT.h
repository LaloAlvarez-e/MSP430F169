/**
 *
 * @file DAC12_RegisterDefines_CH_DAT.h
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
 * @verbatim 7 may. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 7 may. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_DAC12_PERIPHERAL_REGISTERDEFINES_HEADER_DAC12_REGISTERDEFINES_CH_DAT_H_
#define DRIVERLIB_DAC12_PERIPHERAL_REGISTERDEFINES_HEADER_DAC12_REGISTERDEFINES_CH_DAT_H_
#include "DriverLib/MCU/Header/MCU_Common.h"

/******************************************************************************************
 ************************************ 2 CH_DAT *********************************************
 ******************************************************************************************/
/*-----------*/
#define DAC12_CH_DAT_R_DATA_BIT ((uint16_t) 0U)
#define DAC12_CH_DAT_R_DATA8_BIT ((uint16_t) 0U)
#define DAC12_CH_DAT_R_DATA12_BIT ((uint16_t) 0U)

#define DAC12_CH_DAT_DATA_MASK ((uint16_t) 0xFFFFU)
#define DAC12_CH_DAT_DATA8_MASK ((uint16_t) 0xFFU)
#define DAC12_CH_DAT_DATA12_MASK ((uint16_t) 0xFFFU)

#define DAC12_CH_DAT_R_DATA_MASK (DAC12_CH_DAT_DAT_MASK << DAC12_CH_DAT_R_DAT_BIT)
#define DAC12_CH_DAT_R_DATA8_MASK (DAC12_CH_DAT_DAT8_MASK << DAC12_CH_DAT_R_DAT8_BIT)
#define DAC12_CH_DAT_R_DATA12_MASK (DAC12_CH_DAT_DAT12_MASK << DAC12_CH_DAT_R_DAT12_BIT)
/*-----------*/






#endif /* DRIVERLIB_DAC12_PERIPHERAL_REGISTERDEFINES_HEADER_DAC12_REGISTERDEFINES_CH_DAT_H_ */
