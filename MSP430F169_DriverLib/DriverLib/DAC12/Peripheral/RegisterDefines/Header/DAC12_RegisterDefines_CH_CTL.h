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
 ************************************ 1 CH_CTL *********************************************
 ******************************************************************************************/
/*-----------*/
#define DAC12_CH_CTL_R_GRP_BIT ((uint8_t) 0U)

#define DAC12_CH_CTL_GRP_MASK ((uint8_t) 0x01U)
#define DAC12_CH_CTL_GRP_SINGLE ((uint8_t) 0x00U)
#define DAC12_CH_CTL_GRP_GROUP ((uint8_t) 0x01U)

#define DAC12_CH_CTL_R_GRP_MASK (DAC12_CH_CTL_GRP_MASK << DAC12_CH_CTL_R_GRP_BIT)
#define DAC12_CH_CTL_R_GRP_SINGLE (DAC12_CH_CTL_GRP_SINGLE << DAC12_CH_CTL_R_GRP_BIT)
#define DAC12_CH_CTL_R_GRP_GROUP (DAC12_CH_CTL_GRP_GROUP << DAC12_CH_CTL_R_GRP_BIT)
/*-----------*/

/*-----------*/
#define DAC12_CH_CTL_R_ENC_BIT ((uint8_t) 1U)

#define DAC12_CH_CTL_ENC_MASK ((uint8_t) 0x01U)
#define DAC12_CH_CTL_ENC_OFF ((uint8_t) 0x00U)
#define DAC12_CH_CTL_ENC_ON ((uint8_t) 0x01U)

#define DAC12_CH_CTL_R_ENC_MASK (DAC12_CH_CTL_ENC_MASK << DAC12_CH_CTL_R_ENC_BIT)
#define DAC12_CH_CTL_R_ENC_OFF (DAC12_CH_CTL_ENC_OFF << DAC12_CH_CTL_R_ENC_BIT)
#define DAC12_CH_CTL_R_ENC_ON (DAC12_CH_CTL_ENC_ON << DAC12_CH_CTL_R_ENC_BIT)
/*-----------*/

/*-----------*/
#define DAC12_CH_CTL_R_IFG_BIT ((uint8_t) 2U)

#define DAC12_CH_CTL_IFG_MASK ((uint8_t) 0x01U)
#define DAC12_CH_CTL_IFG_NOOCCUR ((uint8_t) 0x00U)
#define DAC12_CH_CTL_IFG_OCCUR ((uint8_t) 0x01U)

#define DAC12_CH_CTL_R_IFG_MASK (DAC12_CH_CTL_IFG_MASK << DAC12_CH_CTL_R_IFG_BIT)
#define DAC12_CH_CTL_R_IFG_NOOCCUR (DAC12_CH_CTL_IFG_NOOCCUR << DAC12_CH_CTL_R_IFG_BIT)
#define DAC12_CH_CTL_R_IFG_OCCUR (DAC12_CH_CTL_IFG_OCCUR << DAC12_CH_CTL_R_IFG_BIT)
/*-----------*/

/*-----------*/
#define DAC12_CH_CTL_R_IE_BIT ((uint8_t) 3U)

#define DAC12_CH_CTL_IE_MASK ((uint8_t) 0x01U)
#define DAC12_CH_CTL_IE_DIS ((uint8_t) 0x00U)
#define DAC12_CH_CTL_IE_ENA ((uint8_t) 0x01U)

#define DAC12_CH_CTL_R_IE_MASK (DAC12_CH_CTL_IE_MASK << DAC12_CH_CTL_R_IE_BIT)
#define DAC12_CH_CTL_R_IE_DIS (DAC12_CH_CTL_IE_DIS << DAC12_CH_CTL_R_IE_BIT)
#define DAC12_CH_CTL_R_IE_ENA (DAC12_CH_CTL_IE_ENA << DAC12_CH_CTL_R_IE_BIT)
/*-----------*/

/*-----------*/
#define DAC12_CH_CTL_R_DF_BIT ((uint8_t) 4U)

#define DAC12_CH_CTL_DF_MASK ((uint8_t) 0x01U)
#define DAC12_CH_CTL_DF_UNSIGNED ((uint8_t) 0x00U)
#define DAC12_CH_CTL_DF_SIGNED ((uint8_t) 0x01U)

#define DAC12_CH_CTL_R_DF_MASK (DAC12_CH_CTL_DF_MASK << DAC12_CH_CTL_R_DF_BIT)
#define DAC12_CH_CTL_R_DF_UNSIGNED (DAC12_CH_CTL_DF_UNSIGNED << DAC12_CH_CTL_R_DF_BIT)
#define DAC12_CH_CTL_R_DF_SIGNED (DAC12_CH_CTL_DF_SIGNED << DAC12_CH_CTL_R_DF_BIT)
/*-----------*/

/*-----------*/
#define DAC12_CH_CTL_R_AMP_BIT ((uint8_t) 5U)

#define DAC12_CH_CTL_AMP_MASK ((uint8_t) 0x07U)
#define DAC12_CH_CTL_AMP_OFF_OFF ((uint8_t) 0x00U)
#define DAC12_CH_CTL_AMP_OFF_0V ((uint8_t) 0x01U)
#define DAC12_CH_CTL_AMP_LOW_LOW ((uint8_t) 0x02U)
#define DAC12_CH_CTL_AMP_LOW_MEDIUM ((uint8_t) 0x03U)
#define DAC12_CH_CTL_AMP_LOW_HIGH ((uint8_t) 0x04U)
#define DAC12_CH_CTL_AMP_MEDIUM_MEDIUM ((uint8_t) 0x05U)
#define DAC12_CH_CTL_AMP_MEDIUM_HIGH ((uint8_t) 0x06U)
#define DAC12_CH_CTL_AMP_HIGH_HIGH ((uint8_t) 0x07U)

#define DAC12_CH_CTL_R_AMP_MASK (DAC12_CH_CTL_AMP_MASK << DAC12_CH_CTL_R_AMP_BIT)
#define DAC12_CH_CTL_R_AMP_OFF_OFF (DAC12_CH_CTL_AMP_OFF_OFF << DAC12_CH_CTL_R_AMP_BIT)
#define DAC12_CH_CTL_R_AMP_OFF_0V (DAC12_CH_CTL_AMP_OFF_0V << DAC12_CH_CTL_R_AMP_BIT)
#define DAC12_CH_CTL_R_AMP_LOW_LOW (DAC12_CH_CTL_AMP_LOW_LOW << DAC12_CH_CTL_R_AMP_BIT)
#define DAC12_CH_CTL_R_AMP_LOW_MEDIUM (DAC12_CH_CTL_AMP_LOW_MEDIUM << DAC12_CH_CTL_R_AMP_BIT)
#define DAC12_CH_CTL_R_AMP_LOW_HIGH (DAC12_CH_CTL_AMP_LOW_HIGH << DAC12_CH_CTL_R_AMP_BIT)
#define DAC12_CH_CTL_R_AMP_MEDIUM_MEDIUM (DAC12_CH_CTL_AMP_MEDIUM_MEDIUM << DAC12_CH_CTL_R_AMP_BIT)
#define DAC12_CH_CTL_R_AMP_MEDIUM_HIGH (DAC12_CH_CTL_AMP_MEDIUM_HIGH << DAC12_CH_CTL_R_AMP_BIT)
#define DAC12_CH_CTL_R_AMP_HIGH_HIGH (DAC12_CH_CTL_AMP_HIGH_HIGH << DAC12_CH_CTL_R_AMP_BIT)
/*-----------*/

/*-----------*/
#define DAC12_CH_CTL_R_IR_BIT ((uint8_t) 8U)

#define DAC12_CH_CTL_IR_MASK ((uint8_t) 0x01U)
#define DAC12_CH_CTL_IR_3x ((uint8_t) 0x00U)
#define DAC12_CH_CTL_IR_1x ((uint8_t) 0x01U)

#define DAC12_CH_CTL_R_IR_MASK (DAC12_CH_CTL_IR_MASK << DAC12_CH_CTL_R_IR_BIT)
#define DAC12_CH_CTL_R_IR_3x (DAC12_CH_CTL_IR_3x << DAC12_CH_CTL_R_IR_BIT)
#define DAC12_CH_CTL_R_IR_1x (DAC12_CH_CTL_IR_1x << DAC12_CH_CTL_R_IR_BIT)
/*-----------*/

/*-----------*/
#define DAC12_CH_CTL_R_CALON_BIT ((uint8_t) 9U)

#define DAC12_CH_CTL_CALON_MASK ((uint8_t) 0x01U)
#define DAC12_CH_CTL_CALON_OFF ((uint8_t) 0x00U)
#define DAC12_CH_CTL_CALON_FINISHED ((uint8_t) 0x00U)
#define DAC12_CH_CTL_CALON_ACTIVE ((uint8_t) 0x01U)
#define DAC12_CH_CTL_CALON_ON ((uint8_t) 0x01U)

#define DAC12_CH_CTL_R_CALON_MASK (DAC12_CH_CTL_CALON_MASK << DAC12_CH_CTL_R_CALON_BIT)
#define DAC12_CH_CTL_R_CALON_OFF (DAC12_CH_CTL_CALON_OFF << DAC12_CH_CTL_R_CALON_BIT)
#define DAC12_CH_CTL_R_CALON_FINISHED (DAC12_CH_CTL_CALON_FINISHED << DAC12_CH_CTL_R_CALON_BIT)
#define DAC12_CH_CTL_R_CALON_ACTIVE (DAC12_CH_CTL_CALON_ACTIVE << DAC12_CH_CTL_R_CALON_BIT)
#define DAC12_CH_CTL_R_CALON_ON (DAC12_CH_CTL_CALON_ON << DAC12_CH_CTL_R_CALON_BIT)
/*-----------*/

/*-----------*/
#define DAC12_CH_CTL_R_LSEL_BIT ((uint8_t) 10U)

#define DAC12_CH_CTL_LSEL_MASK ((uint8_t) 0x03U)
#define DAC12_CH_CTL_LSEL_IMMEDIATE ((uint8_t) 0x00U)
#define DAC12_CH_CTL_LSEL_GROUPED ((uint8_t) 0x01U)
#define DAC12_CH_CTL_LSEL_TA_CCR1 ((uint8_t) 0x02U)
#define DAC12_CH_CTL_LSEL_TB_CCR2 ((uint8_t) 0x03U)

#define DAC12_CH_CTL_R_LSEL_MASK (DAC12_CH_CTL_LSEL_MASK << DAC12_CH_CTL_R_LSEL_BIT)
#define DAC12_CH_CTL_R_LSEL_IMMEDIATE (DAC12_CH_CTL_LSEL_IMMEDIATE << DAC12_CH_CTL_R_LSEL_BIT)
#define DAC12_CH_CTL_R_LSEL_GROUPED (DAC12_CH_CTL_LSEL_GROUPED << DAC12_CH_CTL_R_LSEL_BIT)
#define DAC12_CH_CTL_R_LSEL_TA_CCR1 (DAC12_CH_CTL_LSEL_TA_CCR1 << DAC12_CH_CTL_R_LSEL_BIT)
#define DAC12_CH_CTL_R_LSEL_TB_CCR2 (DAC12_CH_CTL_LSEL_TB_CCR2 << DAC12_CH_CTL_R_LSEL_BIT)
/*-----------*/

/*-----------*/
#define DAC12_CH_CTL_R_RES_BIT ((uint8_t) 12U)

#define DAC12_CH_CTL_RES_MASK ((uint8_t) 0x01U)
#define DAC12_CH_CTL_RES_12BITS ((uint8_t) 0x00U)
#define DAC12_CH_CTL_RES_8BITS ((uint8_t) 0x01U)

#define DAC12_CH_CTL_R_RES_MASK (DAC12_CH_CTL_RES_MASK << DAC12_CH_CTL_R_RES_BIT)
#define DAC12_CH_CTL_R_RES_12BITS (DAC12_CH_CTL_RES_12BITS << DAC12_CH_CTL_R_RES_BIT)
#define DAC12_CH_CTL_R_RES_8BITS (DAC12_CH_CTL_RES_8BITS << DAC12_CH_CTL_R_RES_BIT)
/*-----------*/

/*-----------*/
#define DAC12_CH_CTL_R_SREF_BIT ((uint8_t) 14U)

#define DAC12_CH_CTL_SREF_MASK ((uint8_t) 0x01U)
#define DAC12_CH_CTL_SREF_VREF_P ((uint8_t) 0x00U)
#define DAC12_CH_CTL_SREF_VeREF_P ((uint8_t) 0x01U)

#define DAC12_CH_CTL_R_SREF_MASK (DAC12_CH_CTL_SREF_MASK << DAC12_CH_CTL_R_SREF_BIT)
#define DAC12_CH_CTL_R_SREF_VREF_P (DAC12_CH_CTL_SREF_VREF_P << DAC12_CH_CTL_R_SREF_BIT)
#define DAC12_CH_CTL_R_SREF_VeREF_P (DAC12_CH_CTL_SREF_VeREF_P << DAC12_CH_CTL_R_SREF_BIT)
/*-----------*/

#endif /* DAC12_PERIPHERAL_REGISTERDEFINES_HEADER_DAC12_REGISTERDEFINES_CH_CTL_H_ */
