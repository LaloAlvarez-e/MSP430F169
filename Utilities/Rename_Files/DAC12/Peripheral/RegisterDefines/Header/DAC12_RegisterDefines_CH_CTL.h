/**
 *
 * @file DAC12_RegisterDefines_CH_CTL.h
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

#ifndef DAC12_PERIPHERAL_REGISTERDEFINES_HEADER_DAC12_REGISTERDEFINES_CH_CTL_H_
#define DAC12_PERIPHERAL_REGISTERDEFINES_HEADER_DAC12_REGISTERDEFINES_CH_CTL_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

/******************************************************************************************
 ************************************ 6 CH_CTL *********************************************
 ******************************************************************************************/
/*-----------*/
#define DAC12_CH_CTL_R_INCH_BIT ((uint8_t) 0U)

#define DAC12_CH_CTL_INCH_MASK ((uint8_t) 0x0FU)
#define DAC12_CH_CTL_INCH_A0 ((uint8_t) 0x00U)
#define DAC12_CH_CTL_INCH_A1 ((uint8_t) 0x01U)
#define DAC12_CH_CTL_INCH_A2 ((uint8_t) 0x02U)
#define DAC12_CH_CTL_INCH_A3 ((uint8_t) 0x03U)
#define DAC12_CH_CTL_INCH_A4 ((uint8_t) 0x04U)
#define DAC12_CH_CTL_INCH_A5 ((uint8_t) 0x05U)
#define DAC12_CH_CTL_INCH_A6 ((uint8_t) 0x06U)
#define DAC12_CH_CTL_INCH_A7 ((uint8_t) 0x07U)
#define DAC12_CH_CTL_INCH_VeREF_P ((uint8_t) 0x08U)
#define DAC12_CH_CTL_INCH_VeREF_N ((uint8_t) 0x09U)
#define DAC12_CH_CTL_INCH_VREF_N ((uint8_t) 0x09U)
#define DAC12_CH_CTL_INCH_TEMP ((uint8_t) 0x0AU)
#define DAC12_CH_CTL_INCH_VCC_2 ((uint8_t) 0x0BU)

#define DAC12_CH_CTL_R_INCH_MASK (DAC12_CH_CTL_INCH_MASK << DAC12_CH_CTL_R_INCH_BIT)
#define DAC12_CH_CTL_R_INCH_A0 (DAC12_CH_CTL_INCH_A0 << DAC12_CH_CTL_R_INCH_BIT)
#define DAC12_CH_CTL_R_INCH_A1 (DAC12_CH_CTL_INCH_A1 << DAC12_CH_CTL_R_INCH_BIT)
#define DAC12_CH_CTL_R_INCH_A2 (DAC12_CH_CTL_INCH_A2 << DAC12_CH_CTL_R_INCH_BIT)
#define DAC12_CH_CTL_R_INCH_A3 (DAC12_CH_CTL_INCH_A3 << DAC12_CH_CTL_R_INCH_BIT)
#define DAC12_CH_CTL_R_INCH_A4 (DAC12_CH_CTL_INCH_A4 << DAC12_CH_CTL_R_INCH_BIT)
#define DAC12_CH_CTL_R_INCH_A5 (DAC12_CH_CTL_INCH_A5 << DAC12_CH_CTL_R_INCH_BIT)
#define DAC12_CH_CTL_R_INCH_A6 (DAC12_CH_CTL_INCH_A6 << DAC12_CH_CTL_R_INCH_BIT)
#define DAC12_CH_CTL_R_INCH_A7 (DAC12_CH_CTL_INCH_A7 << DAC12_CH_CTL_R_INCH_BIT)
#define DAC12_CH_CTL_R_INCH_VeREF_P (DAC12_CH_CTL_INCH_VeREF_P << DAC12_CH_CTL_R_INCH_BIT)
#define DAC12_CH_CTL_R_INCH_VeREF_N (DAC12_CH_CTL_INCH_VeREF_N << DAC12_CH_CTL_R_INCH_BIT)
#define DAC12_CH_CTL_R_INCH_VREF_N (DAC12_CH_CTL_INCH_VREF_N << DAC12_CH_CTL_R_INCH_BIT)
#define DAC12_CH_CTL_R_INCH_TEMP (DAC12_CH_CTL_INCH_TEMP << DAC12_CH_CTL_R_INCH_BIT)
#define DAC12_CH_CTL_R_INCH_VCC_2 (DAC12_CH_CTL_INCH_VCC_2 << DAC12_CH_CTL_R_INCH_BIT)
/*-----------*/

/*-----------*/
#define DAC12_CH_CTL_R_SREFP_BIT ((uint8_t) 4U)

#define DAC12_CH_CTL_SREFP_MASK ((uint8_t) 0x03U)
#define DAC12_CH_CTL_SREFP_VCC ((uint8_t) 0x00U)
#define DAC12_CH_CTL_SREFP_VREF_P ((uint8_t) 0x01U)
#define DAC12_CH_CTL_SREFP_VeREF_P ((uint8_t) 0x02U)

#define DAC12_CH_CTL_R_SREFP_MASK (DAC12_CH_CTL_SREFP_MASK << DAC12_CH_CTL_R_SREFP_BIT)
#define DAC12_CH_CTL_R_SREFP_VCC (DAC12_CH_CTL_SREFP_VCC << DAC12_CH_CTL_R_SREFP_BIT)
#define DAC12_CH_CTL_R_SREFP_VREF_P (DAC12_CH_CTL_SREFP_VREF_P << DAC12_CH_CTL_R_SREFP_BIT)
#define DAC12_CH_CTL_R_SREFP_VeREF_P (DAC12_CH_CTL_SREFP_VeREF_P << DAC12_CH_CTL_R_SREFP_BIT)
/*-----------*/

/*-----------*/
#define DAC12_CH_CTL_R_SREFN_BIT ((uint8_t) 6U)

#define DAC12_CH_CTL_SREFN_MASK ((uint8_t) 0x01U)
#define DAC12_CH_CTL_SREFN_GND ((uint8_t) 0x00U)
#define DAC12_CH_CTL_SREFN_VREF_N ((uint8_t) 0x01U)
#define DAC12_CH_CTL_SREFN_VeREF_N ((uint8_t) 0x01U)

#define DAC12_CH_CTL_R_SREFN_MASK (DAC12_CH_CTL_SREFN_MASK << DAC12_CH_CTL_R_SREFN_BIT)
#define DAC12_CH_CTL_R_SREFN_GND (DAC12_CH_CTL_SREFN_GND << DAC12_CH_CTL_R_SREFN_BIT)
#define DAC12_CH_CTL_R_SREFN_VREF_N (DAC12_CH_CTL_SREFN_VREF_N << DAC12_CH_CTL_R_SREFN_BIT)
#define DAC12_CH_CTL_R_SREFN_VeREF_N (DAC12_CH_CTL_SREFN_VeREF_N << DAC12_CH_CTL_R_SREFN_BIT)
/*-----------*/

/*-----------*/
#define DAC12_CH_CTL_R_EOS_BIT ((uint8_t) 7U)

#define DAC12_CH_CTL_EOS_MASK ((uint8_t) 0x01U)
#define DAC12_CH_CTL_EOS_NA ((uint8_t) 0x00U)
#define DAC12_CH_CTL_EOS_END ((uint8_t) 0x01U)

#define DAC12_CH_CTL_R_EOS_MASK (DAC12_CH_CTL_EOS_MASK << DAC12_CH_CTL_R_EOS_BIT)
#define DAC12_CH_CTL_R_EOS_NA (DAC12_CH_CTL_EOS_NA << DAC12_CH_CTL_R_EOS_BIT)
#define DAC12_CH_CTL_R_EOS_END (DAC12_CH_CTL_EOS_END << DAC12_CH_CTL_R_EOS_BIT)
/*-----------*/

#endif /* DAC12_PERIPHERAL_REGISTERDEFINES_HEADER_DAC12_REGISTERDEFINES_CH_CTL_H_ */
