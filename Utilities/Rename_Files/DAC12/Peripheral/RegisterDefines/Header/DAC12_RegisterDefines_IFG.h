/**
 *
 * @file DAC12_RegisterDefines_IFG.h
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

#ifndef DRIVERLIB_DAC12_PERIPHERAL_REGISTERDEFINES_HEADER_DAC12_REGISTERDEFINES_IFG_H_
#define DRIVERLIB_DAC12_PERIPHERAL_REGISTERDEFINES_HEADER_DAC12_REGISTERDEFINES_IFG_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

/******************************************************************************************
 ************************************ 4 IFG *********************************************
 ******************************************************************************************/
/*-----------*/
#define DAC12_IFG_R_CH0_BIT ((uint16_t) 0U)

#define DAC12_IFG_CH0_MASK ((uint16_t) 0x01U)
#define DAC12_IFG_CH0_NOOCCUR ((uint16_t) 0x00U)
#define DAC12_IFG_CH0_OCCUR ((uint16_t) 0x01U)

#define DAC12_IFG_R_CH0_MASK (DAC12_IFG_CH0_MASK << DAC12_IFG_R_CH0_BIT)
#define DAC12_IFG_R_CH0_NOOCCUR (DAC12_IFG_CH0_NOOCCUR << DAC12_IFG_R_CH0_BIT)
#define DAC12_IFG_R_CH0_OCCUR (DAC12_IFG_CH0_OCCUR << DAC12_IFG_R_CH0_BIT)
/*-----------*/

/*-----------*/
#define DAC12_IFG_R_CH1_BIT ((uint16_t) 1U)

#define DAC12_IFG_CH1_MASK ((uint16_t) 0x01U)
#define DAC12_IFG_CH1_NOOCCUR ((uint16_t) 0x00U)
#define DAC12_IFG_CH1_OCCUR ((uint16_t) 0x01U)

#define DAC12_IFG_R_CH1_MASK (DAC12_IFG_CH1_MASK << DAC12_IFG_R_CH1_BIT)
#define DAC12_IFG_R_CH1_NOOCCUR (DAC12_IFG_CH1_NOOCCUR << DAC12_IFG_R_CH1_BIT)
#define DAC12_IFG_R_CH1_OCCUR (DAC12_IFG_CH1_OCCUR << DAC12_IFG_R_CH1_BIT)
/*-----------*/

/*-----------*/
#define DAC12_IFG_R_CH2_BIT ((uint16_t) 2U)

#define DAC12_IFG_CH2_MASK ((uint16_t) 0x01U)
#define DAC12_IFG_CH2_NOOCCUR ((uint16_t) 0x00U)
#define DAC12_IFG_CH2_OCCUR ((uint16_t) 0x01U)

#define DAC12_IFG_R_CH2_MASK (DAC12_IFG_CH2_MASK << DAC12_IFG_R_CH2_BIT)
#define DAC12_IFG_R_CH2_NOOCCUR (DAC12_IFG_CH2_NOOCCUR << DAC12_IFG_R_CH2_BIT)
#define DAC12_IFG_R_CH2_OCCUR (DAC12_IFG_CH2_OCCUR << DAC12_IFG_R_CH2_BIT)
/*-----------*/

/*-----------*/
#define DAC12_IFG_R_CH3_BIT ((uint16_t) 3U)

#define DAC12_IFG_CH3_MASK ((uint16_t) 0x01U)
#define DAC12_IFG_CH3_NOOCCUR ((uint16_t) 0x00U)
#define DAC12_IFG_CH3_OCCUR ((uint16_t) 0x01U)

#define DAC12_IFG_R_CH3_MASK (DAC12_IFG_CH3_MASK << DAC12_IFG_R_CH3_BIT)
#define DAC12_IFG_R_CH3_NOOCCUR (DAC12_IFG_CH3_NOOCCUR << DAC12_IFG_R_CH3_BIT)
#define DAC12_IFG_R_CH3_OCCUR (DAC12_IFG_CH3_OCCUR << DAC12_IFG_R_CH3_BIT)
/*-----------*/

/*-----------*/
#define DAC12_IFG_R_CH4_BIT ((uint16_t) 4U)

#define DAC12_IFG_CH4_MASK ((uint16_t) 0x01U)
#define DAC12_IFG_CH4_NOOCCUR ((uint16_t) 0x00U)
#define DAC12_IFG_CH4_OCCUR ((uint16_t) 0x01U)

#define DAC12_IFG_R_CH4_MASK (DAC12_IFG_CH4_MASK << DAC12_IFG_R_CH4_BIT)
#define DAC12_IFG_R_CH4_NOOCCUR (DAC12_IFG_CH4_NOOCCUR << DAC12_IFG_R_CH4_BIT)
#define DAC12_IFG_R_CH4_OCCUR (DAC12_IFG_CH4_OCCUR << DAC12_IFG_R_CH4_BIT)
/*-----------*/

/*-----------*/
#define DAC12_IFG_R_CH5_BIT ((uint16_t) 5U)

#define DAC12_IFG_CH5_MASK ((uint16_t) 0x01U)
#define DAC12_IFG_CH5_NOOCCUR ((uint16_t) 0x00U)
#define DAC12_IFG_CH5_OCCUR ((uint16_t) 0x01U)

#define DAC12_IFG_R_CH5_MASK (DAC12_IFG_CH5_MASK << DAC12_IFG_R_CH5_BIT)
#define DAC12_IFG_R_CH5_NOOCCUR (DAC12_IFG_CH5_NOOCCUR << DAC12_IFG_R_CH5_BIT)
#define DAC12_IFG_R_CH5_OCCUR (DAC12_IFG_CH5_OCCUR << DAC12_IFG_R_CH5_BIT)
/*-----------*/

/*-----------*/
#define DAC12_IFG_R_CH6_BIT ((uint16_t) 6U)

#define DAC12_IFG_CH6_MASK ((uint16_t) 0x01U)
#define DAC12_IFG_CH6_NOOCCUR ((uint16_t) 0x00U)
#define DAC12_IFG_CH6_OCCUR ((uint16_t) 0x01U)

#define DAC12_IFG_R_CH6_MASK (DAC12_IFG_CH6_MASK << DAC12_IFG_R_CH6_BIT)
#define DAC12_IFG_R_CH6_NOOCCUR (DAC12_IFG_CH6_NOOCCUR << DAC12_IFG_R_CH6_BIT)
#define DAC12_IFG_R_CH6_OCCUR (DAC12_IFG_CH6_OCCUR << DAC12_IFG_R_CH6_BIT)
/*-----------*/

/*-----------*/
#define DAC12_IFG_R_CH7_BIT ((uint16_t) 7U)

#define DAC12_IFG_CH7_MASK ((uint16_t) 0x01U)
#define DAC12_IFG_CH7_NOOCCUR ((uint16_t) 0x00U)
#define DAC12_IFG_CH7_OCCUR ((uint16_t) 0x01U)

#define DAC12_IFG_R_CH7_MASK (DAC12_IFG_CH7_MASK << DAC12_IFG_R_CH7_BIT)
#define DAC12_IFG_R_CH7_NOOCCUR (DAC12_IFG_CH7_NOOCCUR << DAC12_IFG_R_CH7_BIT)
#define DAC12_IFG_R_CH7_OCCUR (DAC12_IFG_CH7_OCCUR << DAC12_IFG_R_CH7_BIT)
/*-----------*/

/*-----------*/
#define DAC12_IFG_R_CH8_BIT ((uint16_t) 8U)

#define DAC12_IFG_CH8_MASK ((uint16_t) 0x01U)
#define DAC12_IFG_CH8_NOOCCUR ((uint16_t) 0x00U)
#define DAC12_IFG_CH8_OCCUR ((uint16_t) 0x01U)

#define DAC12_IFG_R_CH8_MASK (DAC12_IFG_CH8_MASK << DAC12_IFG_R_CH8_BIT)
#define DAC12_IFG_R_CH8_NOOCCUR (DAC12_IFG_CH8_NOOCCUR << DAC12_IFG_R_CH8_BIT)
#define DAC12_IFG_R_CH8_OCCUR (DAC12_IFG_CH8_OCCUR << DAC12_IFG_R_CH8_BIT)
/*-----------*/

/*-----------*/
#define DAC12_IFG_R_CH9_BIT ((uint16_t) 9U)

#define DAC12_IFG_CH9_MASK ((uint16_t) 0x01U)
#define DAC12_IFG_CH9_NOOCCUR ((uint16_t) 0x00U)
#define DAC12_IFG_CH9_OCCUR ((uint16_t) 0x01U)

#define DAC12_IFG_R_CH9_MASK (DAC12_IFG_CH9_MASK << DAC12_IFG_R_CH9_BIT)
#define DAC12_IFG_R_CH9_NOOCCUR (DAC12_IFG_CH9_NOOCCUR << DAC12_IFG_R_CH9_BIT)
#define DAC12_IFG_R_CH9_OCCUR (DAC12_IFG_CH9_OCCUR << DAC12_IFG_R_CH9_BIT)
/*-----------*/

/*-----------*/
#define DAC12_IFG_R_CH10_BIT ((uint16_t) 10U)

#define DAC12_IFG_CH10_MASK ((uint16_t) 0x01U)
#define DAC12_IFG_CH10_NOOCCUR ((uint16_t) 0x00U)
#define DAC12_IFG_CH10_OCCUR ((uint16_t) 0x01U)

#define DAC12_IFG_R_CH10_MASK (DAC12_IFG_CH10_MASK << DAC12_IFG_R_CH10_BIT)
#define DAC12_IFG_R_CH10_NOOCCUR (DAC12_IFG_CH10_NOOCCUR << DAC12_IFG_R_CH10_BIT)
#define DAC12_IFG_R_CH10_OCCUR (DAC12_IFG_CH10_OCCUR << DAC12_IFG_R_CH10_BIT)
/*-----------*/

/*-----------*/
#define DAC12_IFG_R_CH11_BIT ((uint16_t) 11U)

#define DAC12_IFG_CH11_MASK ((uint16_t) 0x01U)
#define DAC12_IFG_CH11_NOOCCUR ((uint16_t) 0x00U)
#define DAC12_IFG_CH11_OCCUR ((uint16_t) 0x01U)

#define DAC12_IFG_R_CH11_MASK (DAC12_IFG_CH11_MASK << DAC12_IFG_R_CH11_BIT)
#define DAC12_IFG_R_CH11_NOOCCUR (DAC12_IFG_CH11_NOOCCUR << DAC12_IFG_R_CH11_BIT)
#define DAC12_IFG_R_CH11_OCCUR (DAC12_IFG_CH11_OCCUR << DAC12_IFG_R_CH11_BIT)
/*-----------*/

/*-----------*/
#define DAC12_IFG_R_CH12_BIT ((uint16_t) 12U)

#define DAC12_IFG_CH12_MASK ((uint16_t) 0x01U)
#define DAC12_IFG_CH12_NOOCCUR ((uint16_t) 0x00U)
#define DAC12_IFG_CH12_OCCUR ((uint16_t) 0x01U)

#define DAC12_IFG_R_CH12_MASK (DAC12_IFG_CH12_MASK << DAC12_IFG_R_CH12_BIT)
#define DAC12_IFG_R_CH12_NOOCCUR (DAC12_IFG_CH12_NOOCCUR << DAC12_IFG_R_CH12_BIT)
#define DAC12_IFG_R_CH12_OCCUR (DAC12_IFG_CH12_OCCUR << DAC12_IFG_R_CH12_BIT)
/*-----------*/

/*-----------*/
#define DAC12_IFG_R_CH13_BIT ((uint16_t) 13U)

#define DAC12_IFG_CH13_MASK ((uint16_t) 0x01U)
#define DAC12_IFG_CH13_NOOCCUR ((uint16_t) 0x00U)
#define DAC12_IFG_CH13_OCCUR ((uint16_t) 0x01U)

#define DAC12_IFG_R_CH13_MASK (DAC12_IFG_CH13_MASK << DAC12_IFG_R_CH13_BIT)
#define DAC12_IFG_R_CH13_NOOCCUR (DAC12_IFG_CH13_NOOCCUR << DAC12_IFG_R_CH13_BIT)
#define DAC12_IFG_R_CH13_OCCUR (DAC12_IFG_CH13_OCCUR << DAC12_IFG_R_CH13_BIT)
/*-----------*/

/*-----------*/
#define DAC12_IFG_R_CH14_BIT ((uint16_t) 14U)

#define DAC12_IFG_CH14_MASK ((uint16_t) 0x01U)
#define DAC12_IFG_CH14_NOOCCUR ((uint16_t) 0x00U)
#define DAC12_IFG_CH14_OCCUR ((uint16_t) 0x01U)

#define DAC12_IFG_R_CH14_MASK (DAC12_IFG_CH14_MASK << DAC12_IFG_R_CH14_BIT)
#define DAC12_IFG_R_CH14_NOOCCUR (DAC12_IFG_CH14_NOOCCUR << DAC12_IFG_R_CH14_BIT)
#define DAC12_IFG_R_CH14_OCCUR (DAC12_IFG_CH14_OCCUR << DAC12_IFG_R_CH14_BIT)
/*-----------*/

/*-----------*/
#define DAC12_IFG_R_CH15_BIT ((uint16_t) 15U)

#define DAC12_IFG_CH15_MASK ((uint16_t) 0x01U)
#define DAC12_IFG_CH15_NOOCCUR ((uint16_t) 0x00U)
#define DAC12_IFG_CH15_OCCUR ((uint16_t) 0x01U)

#define DAC12_IFG_R_CH15_MASK (DAC12_IFG_CH15_MASK << DAC12_IFG_R_CH15_BIT)
#define DAC12_IFG_R_CH15_NOOCCUR (DAC12_IFG_CH15_NOOCCUR << DAC12_IFG_R_CH15_BIT)
#define DAC12_IFG_R_CH15_OCCUR (DAC12_IFG_CH15_OCCUR << DAC12_IFG_R_CH15_BIT)
/*-----------*/

#endif /* DRIVERLIB_DAC12_PERIPHERAL_REGISTERDEFINES_HEADER_DAC12_REGISTERDEFINES_IFG_H_ */
