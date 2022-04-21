/**
 *
 * @file ADC12_RegisterDefines_IFG.h
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

#ifndef DRIVERLIB_ADC12_PERIPHERAL_REGISTERDEFINES_HEADER_ADC12_REGISTERDEFINES_IFG_H_
#define DRIVERLIB_ADC12_PERIPHERAL_REGISTERDEFINES_HEADER_ADC12_REGISTERDEFINES_IFG_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

/******************************************************************************************
 ************************************ 4 IFG *********************************************
 ******************************************************************************************/
/*-----------*/
#define ADC12_IFG_R_CH0_BIT ((uint16_t) 0U)

#define ADC12_IFG_CH0_MASK ((uint16_t) 0x01U)
#define ADC12_IFG_CH0_NOOCCUR ((uint16_t) 0x00U)
#define ADC12_IFG_CH0_OCCUR ((uint16_t) 0x01U)

#define ADC12_IFG_R_CH0_MASK (ADC12_IFG_CH0_MASK << ADC12_IFG_R_CH0_BIT)
#define ADC12_IFG_R_CH0_NOOCCUR (ADC12_IFG_CH0_NOOCCUR << ADC12_IFG_R_CH0_BIT)
#define ADC12_IFG_R_CH0_OCCUR (ADC12_IFG_CH0_OCCUR << ADC12_IFG_R_CH0_BIT)
/*-----------*/

/*-----------*/
#define ADC12_IFG_R_CH1_BIT ((uint16_t) 1U)

#define ADC12_IFG_CH1_MASK ((uint16_t) 0x01U)
#define ADC12_IFG_CH1_NOOCCUR ((uint16_t) 0x00U)
#define ADC12_IFG_CH1_OCCUR ((uint16_t) 0x01U)

#define ADC12_IFG_R_CH1_MASK (ADC12_IFG_CH1_MASK << ADC12_IFG_R_CH1_BIT)
#define ADC12_IFG_R_CH1_NOOCCUR (ADC12_IFG_CH1_NOOCCUR << ADC12_IFG_R_CH1_BIT)
#define ADC12_IFG_R_CH1_OCCUR (ADC12_IFG_CH1_OCCUR << ADC12_IFG_R_CH1_BIT)
/*-----------*/

/*-----------*/
#define ADC12_IFG_R_CH2_BIT ((uint16_t) 2U)

#define ADC12_IFG_CH2_MASK ((uint16_t) 0x01U)
#define ADC12_IFG_CH2_NOOCCUR ((uint16_t) 0x00U)
#define ADC12_IFG_CH2_OCCUR ((uint16_t) 0x01U)

#define ADC12_IFG_R_CH2_MASK (ADC12_IFG_CH2_MASK << ADC12_IFG_R_CH2_BIT)
#define ADC12_IFG_R_CH2_NOOCCUR (ADC12_IFG_CH2_NOOCCUR << ADC12_IFG_R_CH2_BIT)
#define ADC12_IFG_R_CH2_OCCUR (ADC12_IFG_CH2_OCCUR << ADC12_IFG_R_CH2_BIT)
/*-----------*/

/*-----------*/
#define ADC12_IFG_R_CH3_BIT ((uint16_t) 3U)

#define ADC12_IFG_CH3_MASK ((uint16_t) 0x01U)
#define ADC12_IFG_CH3_NOOCCUR ((uint16_t) 0x00U)
#define ADC12_IFG_CH3_OCCUR ((uint16_t) 0x01U)

#define ADC12_IFG_R_CH3_MASK (ADC12_IFG_CH3_MASK << ADC12_IFG_R_CH3_BIT)
#define ADC12_IFG_R_CH3_NOOCCUR (ADC12_IFG_CH3_NOOCCUR << ADC12_IFG_R_CH3_BIT)
#define ADC12_IFG_R_CH3_OCCUR (ADC12_IFG_CH3_OCCUR << ADC12_IFG_R_CH3_BIT)
/*-----------*/

/*-----------*/
#define ADC12_IFG_R_CH4_BIT ((uint16_t) 4U)

#define ADC12_IFG_CH4_MASK ((uint16_t) 0x01U)
#define ADC12_IFG_CH4_NOOCCUR ((uint16_t) 0x00U)
#define ADC12_IFG_CH4_OCCUR ((uint16_t) 0x01U)

#define ADC12_IFG_R_CH4_MASK (ADC12_IFG_CH4_MASK << ADC12_IFG_R_CH4_BIT)
#define ADC12_IFG_R_CH4_NOOCCUR (ADC12_IFG_CH4_NOOCCUR << ADC12_IFG_R_CH4_BIT)
#define ADC12_IFG_R_CH4_OCCUR (ADC12_IFG_CH4_OCCUR << ADC12_IFG_R_CH4_BIT)
/*-----------*/

/*-----------*/
#define ADC12_IFG_R_CH5_BIT ((uint16_t) 5U)

#define ADC12_IFG_CH5_MASK ((uint16_t) 0x01U)
#define ADC12_IFG_CH5_NOOCCUR ((uint16_t) 0x00U)
#define ADC12_IFG_CH5_OCCUR ((uint16_t) 0x01U)

#define ADC12_IFG_R_CH5_MASK (ADC12_IFG_CH5_MASK << ADC12_IFG_R_CH5_BIT)
#define ADC12_IFG_R_CH5_NOOCCUR (ADC12_IFG_CH5_NOOCCUR << ADC12_IFG_R_CH5_BIT)
#define ADC12_IFG_R_CH5_OCCUR (ADC12_IFG_CH5_OCCUR << ADC12_IFG_R_CH5_BIT)
/*-----------*/

/*-----------*/
#define ADC12_IFG_R_CH6_BIT ((uint16_t) 6U)

#define ADC12_IFG_CH6_MASK ((uint16_t) 0x01U)
#define ADC12_IFG_CH6_NOOCCUR ((uint16_t) 0x00U)
#define ADC12_IFG_CH6_OCCUR ((uint16_t) 0x01U)

#define ADC12_IFG_R_CH6_MASK (ADC12_IFG_CH6_MASK << ADC12_IFG_R_CH6_BIT)
#define ADC12_IFG_R_CH6_NOOCCUR (ADC12_IFG_CH6_NOOCCUR << ADC12_IFG_R_CH6_BIT)
#define ADC12_IFG_R_CH6_OCCUR (ADC12_IFG_CH6_OCCUR << ADC12_IFG_R_CH6_BIT)
/*-----------*/

/*-----------*/
#define ADC12_IFG_R_CH7_BIT ((uint16_t) 7U)

#define ADC12_IFG_CH7_MASK ((uint16_t) 0x01U)
#define ADC12_IFG_CH7_NOOCCUR ((uint16_t) 0x00U)
#define ADC12_IFG_CH7_OCCUR ((uint16_t) 0x01U)

#define ADC12_IFG_R_CH7_MASK (ADC12_IFG_CH7_MASK << ADC12_IFG_R_CH7_BIT)
#define ADC12_IFG_R_CH7_NOOCCUR (ADC12_IFG_CH7_NOOCCUR << ADC12_IFG_R_CH7_BIT)
#define ADC12_IFG_R_CH7_OCCUR (ADC12_IFG_CH7_OCCUR << ADC12_IFG_R_CH7_BIT)
/*-----------*/

/*-----------*/
#define ADC12_IFG_R_CH8_BIT ((uint16_t) 8U)

#define ADC12_IFG_CH8_MASK ((uint16_t) 0x01U)
#define ADC12_IFG_CH8_NOOCCUR ((uint16_t) 0x00U)
#define ADC12_IFG_CH8_OCCUR ((uint16_t) 0x01U)

#define ADC12_IFG_R_CH8_MASK (ADC12_IFG_CH8_MASK << ADC12_IFG_R_CH8_BIT)
#define ADC12_IFG_R_CH8_NOOCCUR (ADC12_IFG_CH8_NOOCCUR << ADC12_IFG_R_CH8_BIT)
#define ADC12_IFG_R_CH8_OCCUR (ADC12_IFG_CH8_OCCUR << ADC12_IFG_R_CH8_BIT)
/*-----------*/

/*-----------*/
#define ADC12_IFG_R_CH9_BIT ((uint16_t) 9U)

#define ADC12_IFG_CH9_MASK ((uint16_t) 0x01U)
#define ADC12_IFG_CH9_NOOCCUR ((uint16_t) 0x00U)
#define ADC12_IFG_CH9_OCCUR ((uint16_t) 0x01U)

#define ADC12_IFG_R_CH9_MASK (ADC12_IFG_CH9_MASK << ADC12_IFG_R_CH9_BIT)
#define ADC12_IFG_R_CH9_NOOCCUR (ADC12_IFG_CH9_NOOCCUR << ADC12_IFG_R_CH9_BIT)
#define ADC12_IFG_R_CH9_OCCUR (ADC12_IFG_CH9_OCCUR << ADC12_IFG_R_CH9_BIT)
/*-----------*/

/*-----------*/
#define ADC12_IFG_R_CH10_BIT ((uint16_t) 10U)

#define ADC12_IFG_CH10_MASK ((uint16_t) 0x01U)
#define ADC12_IFG_CH10_NOOCCUR ((uint16_t) 0x00U)
#define ADC12_IFG_CH10_OCCUR ((uint16_t) 0x01U)

#define ADC12_IFG_R_CH10_MASK (ADC12_IFG_CH10_MASK << ADC12_IFG_R_CH10_BIT)
#define ADC12_IFG_R_CH10_NOOCCUR (ADC12_IFG_CH10_NOOCCUR << ADC12_IFG_R_CH10_BIT)
#define ADC12_IFG_R_CH10_OCCUR (ADC12_IFG_CH10_OCCUR << ADC12_IFG_R_CH10_BIT)
/*-----------*/

/*-----------*/
#define ADC12_IFG_R_CH11_BIT ((uint16_t) 11U)

#define ADC12_IFG_CH11_MASK ((uint16_t) 0x01U)
#define ADC12_IFG_CH11_NOOCCUR ((uint16_t) 0x00U)
#define ADC12_IFG_CH11_OCCUR ((uint16_t) 0x01U)

#define ADC12_IFG_R_CH11_MASK (ADC12_IFG_CH11_MASK << ADC12_IFG_R_CH11_BIT)
#define ADC12_IFG_R_CH11_NOOCCUR (ADC12_IFG_CH11_NOOCCUR << ADC12_IFG_R_CH11_BIT)
#define ADC12_IFG_R_CH11_OCCUR (ADC12_IFG_CH11_OCCUR << ADC12_IFG_R_CH11_BIT)
/*-----------*/

/*-----------*/
#define ADC12_IFG_R_CH12_BIT ((uint16_t) 12U)

#define ADC12_IFG_CH12_MASK ((uint16_t) 0x01U)
#define ADC12_IFG_CH12_NOOCCUR ((uint16_t) 0x00U)
#define ADC12_IFG_CH12_OCCUR ((uint16_t) 0x01U)

#define ADC12_IFG_R_CH12_MASK (ADC12_IFG_CH12_MASK << ADC12_IFG_R_CH12_BIT)
#define ADC12_IFG_R_CH12_NOOCCUR (ADC12_IFG_CH12_NOOCCUR << ADC12_IFG_R_CH12_BIT)
#define ADC12_IFG_R_CH12_OCCUR (ADC12_IFG_CH12_OCCUR << ADC12_IFG_R_CH12_BIT)
/*-----------*/

/*-----------*/
#define ADC12_IFG_R_CH13_BIT ((uint16_t) 13U)

#define ADC12_IFG_CH13_MASK ((uint16_t) 0x01U)
#define ADC12_IFG_CH13_NOOCCUR ((uint16_t) 0x00U)
#define ADC12_IFG_CH13_OCCUR ((uint16_t) 0x01U)

#define ADC12_IFG_R_CH13_MASK (ADC12_IFG_CH13_MASK << ADC12_IFG_R_CH13_BIT)
#define ADC12_IFG_R_CH13_NOOCCUR (ADC12_IFG_CH13_NOOCCUR << ADC12_IFG_R_CH13_BIT)
#define ADC12_IFG_R_CH13_OCCUR (ADC12_IFG_CH13_OCCUR << ADC12_IFG_R_CH13_BIT)
/*-----------*/

/*-----------*/
#define ADC12_IFG_R_CH14_BIT ((uint16_t) 14U)

#define ADC12_IFG_CH14_MASK ((uint16_t) 0x01U)
#define ADC12_IFG_CH14_NOOCCUR ((uint16_t) 0x00U)
#define ADC12_IFG_CH14_OCCUR ((uint16_t) 0x01U)

#define ADC12_IFG_R_CH14_MASK (ADC12_IFG_CH14_MASK << ADC12_IFG_R_CH14_BIT)
#define ADC12_IFG_R_CH14_NOOCCUR (ADC12_IFG_CH14_NOOCCUR << ADC12_IFG_R_CH14_BIT)
#define ADC12_IFG_R_CH14_OCCUR (ADC12_IFG_CH14_OCCUR << ADC12_IFG_R_CH14_BIT)
/*-----------*/

/*-----------*/
#define ADC12_IFG_R_CH15_BIT ((uint16_t) 15U)

#define ADC12_IFG_CH15_MASK ((uint16_t) 0x01U)
#define ADC12_IFG_CH15_NOOCCUR ((uint16_t) 0x00U)
#define ADC12_IFG_CH15_OCCUR ((uint16_t) 0x01U)

#define ADC12_IFG_R_CH15_MASK (ADC12_IFG_CH15_MASK << ADC12_IFG_R_CH15_BIT)
#define ADC12_IFG_R_CH15_NOOCCUR (ADC12_IFG_CH15_NOOCCUR << ADC12_IFG_R_CH15_BIT)
#define ADC12_IFG_R_CH15_OCCUR (ADC12_IFG_CH15_OCCUR << ADC12_IFG_R_CH15_BIT)
/*-----------*/

#endif /* DRIVERLIB_ADC12_PERIPHERAL_REGISTERDEFINES_HEADER_ADC12_REGISTERDEFINES_IFG_H_ */
