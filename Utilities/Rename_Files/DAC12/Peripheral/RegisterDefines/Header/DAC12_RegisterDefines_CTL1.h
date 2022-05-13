/**
 *
 * @file DAC12_RegisterDefines_CTL1.h
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

#ifndef DAC12_PERIPHERAL_REGISTERDEFINES_HEADER_DAC12_REGISTERDEFINES_CTL1_H_
#define DAC12_PERIPHERAL_REGISTERDEFINES_HEADER_DAC12_REGISTERDEFINES_CTL1_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

/******************************************************************************************
 ************************************ 2 CTL1 *********************************************
 ******************************************************************************************/
/*-----------*/
#define DAC12_CTL1_R_BUSY_BIT ((uint16_t) 0U)

#define DAC12_CTL1_BUSY_MASK ((uint16_t) 0x01U)
#define DAC12_CTL1_BUSY_IDLE ((uint16_t) 0x00U)
#define DAC12_CTL1_BUSY_BUSY ((uint16_t) 0x01U)

#define DAC12_CTL1_R_BUSY_MASK (DAC12_CTL1_BUSY_MASK << DAC12_CTL1_R_BUSY_BIT)
#define DAC12_CTL1_R_BUSY_IDLE (DAC12_CTL1_BUSY_IDLE << DAC12_CTL1_R_BUSY_BIT)
#define DAC12_CTL1_R_BUSY_BUSY (DAC12_CTL1_BUSY_BUSY << DAC12_CTL1_R_BUSY_BIT)
/*-----------*/

/*-----------*/
#define DAC12_CTL1_R_CONSEQ_BIT ((uint16_t) 1U)

#define DAC12_CTL1_CONSEQ_MASK ((uint16_t) 0x03U)
#define DAC12_CTL1_CONSEQ_SINGLE ((uint16_t) 0x00U)
#define DAC12_CTL1_CONSEQ_SEQUENCE ((uint16_t) 0x01U)
#define DAC12_CTL1_CONSEQ_REPEAT_SINGLE ((uint16_t) 0x02U)
#define DAC12_CTL1_CONSEQ_REPEAT_SEQUENCE ((uint16_t) 0x03U)

#define DAC12_CTL1_R_CONSEQ_MASK (DAC12_CTL1_CONSEQ_MASK << DAC12_CTL1_R_CONSEQ_BIT)
#define DAC12_CTL1_R_CONSEQ_SINGLE (DAC12_CTL1_CONSEQ_SINGLE << DAC12_CTL1_R_CONSEQ_BIT)
#define DAC12_CTL1_R_CONSEQ_SEQUENCE (DAC12_CTL1_CONSEQ_SEQUENCE << DAC12_CTL1_R_CONSEQ_BIT)
#define DAC12_CTL1_R_CONSEQ_REPEAT_SINGLE (DAC12_CTL1_CONSEQ_REPEAT_SINGLE << DAC12_CTL1_R_CONSEQ_BIT)
#define DAC12_CTL1_R_CONSEQ_REPEAT_SEQUENCE (DAC12_CTL1_CONSEQ_REPEAT_SEQUENCE << DAC12_CTL1_R_CONSEQ_BIT)
/*-----------*/

/*-----------*/
#define DAC12_CTL1_R_SSEL_BIT ((uint16_t) 3U)

#define DAC12_CTL1_SSEL_MASK ((uint16_t) 0x03U)
#define DAC12_CTL1_SSEL_DAC12OSC ((uint16_t) 0x00U)
#define DAC12_CTL1_SSEL_ACLK ((uint16_t) 0x01U)
#define DAC12_CTL1_SSEL_MCLK ((uint16_t) 0x02U)
#define DAC12_CTL1_SSEL_SMCLK ((uint16_t) 0x03U)

#define DAC12_CTL1_R_SSEL_MASK (DAC12_CTL1_SSEL_MASK << DAC12_CTL1_R_SSEL_BIT)
#define DAC12_CTL1_R_SSEL_DAC12OSC (DAC12_CTL1_SSEL_DAC12OSC << DAC12_CTL1_R_SSEL_BIT)
#define DAC12_CTL1_R_SSEL_ACLK (DAC12_CTL1_SSEL_ACLK << DAC12_CTL1_R_SSEL_BIT)
#define DAC12_CTL1_R_SSEL_MCLK (DAC12_CTL1_SSEL_MCLK << DAC12_CTL1_R_SSEL_BIT)
#define DAC12_CTL1_R_SSEL_SMCLK (DAC12_CTL1_SSEL_SMCLK << DAC12_CTL1_R_SSEL_BIT)
/*-----------*/

/*-----------*/
#define DAC12_CTL1_R_DIV_BIT ((uint16_t) 5U)

#define DAC12_CTL1_DIV_MASK ((uint16_t) 0x07U)
#define DAC12_CTL1_DIV_1 ((uint16_t) 0x00U)
#define DAC12_CTL1_DIV_2 ((uint16_t) 0x01U)
#define DAC12_CTL1_DIV_3 ((uint16_t) 0x02U)
#define DAC12_CTL1_DIV_4 ((uint16_t) 0x03U)
#define DAC12_CTL1_DIV_5 ((uint16_t) 0x00U)
#define DAC12_CTL1_DIV_6 ((uint16_t) 0x01U)
#define DAC12_CTL1_DIV_7 ((uint16_t) 0x02U)
#define DAC12_CTL1_DIV_8 ((uint16_t) 0x03U)

#define DAC12_CTL1_R_DIV_MASK (DAC12_CTL1_DIV_MASK << DAC12_CTL1_R_DIV_BIT)
#define DAC12_CTL1_R_DIV_1 (DAC12_CTL1_DIV_1 << DAC12_CTL1_R_DIV_BIT)
#define DAC12_CTL1_R_DIV_2 (DAC12_CTL1_DIV_2 << DAC12_CTL1_R_DIV_BIT)
#define DAC12_CTL1_R_DIV_3 (DAC12_CTL1_DIV_3 << DAC12_CTL1_R_DIV_BIT)
#define DAC12_CTL1_R_DIV_4 (DAC12_CTL1_DIV_4 << DAC12_CTL1_R_DIV_BIT)
#define DAC12_CTL1_R_DIV_5 (DAC12_CTL1_DIV_5 << DAC12_CTL1_R_DIV_BIT)
#define DAC12_CTL1_R_DIV_6 (DAC12_CTL1_DIV_6 << DAC12_CTL1_R_DIV_BIT)
#define DAC12_CTL1_R_DIV_7 (DAC12_CTL1_DIV_7 << DAC12_CTL1_R_DIV_BIT)
#define DAC12_CTL1_R_DIV_8 (DAC12_CTL1_DIV_8 << DAC12_CTL1_R_DIV_BIT)
/*-----------*/

/*-----------*/
#define DAC12_CTL1_R_ISSH_BIT ((uint16_t) 8U)

#define DAC12_CTL1_ISSH_MASK ((uint16_t) 0x01U)
#define DAC12_CTL1_ISSH_BYSPASS ((uint16_t) 0x00U)
#define DAC12_CTL1_ISSH_INVERTED ((uint16_t) 0x01U)

#define DAC12_CTL1_R_ISSH_MASK (DAC12_CTL1_ISSH_MASK << DAC12_CTL1_R_ISSH_BIT)
#define DAC12_CTL1_R_ISSH_BYSPASS (DAC12_CTL1_ISSH_BYSPASS << DAC12_CTL1_R_ISSH_BIT)
#define DAC12_CTL1_R_ISSH_INVERTED (DAC12_CTL1_ISSH_INVERTED << DAC12_CTL1_R_ISSH_BIT)
/*-----------*/

/*-----------*/
#define DAC12_CTL1_R_SHP_BIT ((uint16_t) 9U)

#define DAC12_CTL1_SHP_MASK ((uint16_t) 0x01U)
#define DAC12_CTL1_SHP_SAMPLE_INPUT ((uint16_t) 0x00U)
#define DAC12_CTL1_SHP_SAMPLE_TIMER ((uint16_t) 0x01U)

#define DAC12_CTL1_R_SHP_MASK (DAC12_CTL1_SHP_MASK << DAC12_CTL1_R_SHP_BIT)
#define DAC12_CTL1_R_SHP_SAMPLE_INPUT (DAC12_CTL1_SHP_SAMPLE_INPUT << DAC12_CTL1_R_SHP_BIT)
#define DAC12_CTL1_R_SHP_SAMPLE_TIMER (DAC12_CTL1_SHP_SAMPLE_TIMER << DAC12_CTL1_R_SHP_BIT)
/*-----------*/

/*-----------*/
#define DAC12_CTL1_R_SHS_BIT ((uint16_t) 10U)

#define DAC12_CTL1_SHS_MASK ((uint16_t) 0x03U)
#define DAC12_CTL1_SHS_SOFTWARE ((uint16_t) 0x00U)
#define DAC12_CTL1_SHS_TA_CCR1 ((uint16_t) 0x01U)
#define DAC12_CTL1_SHS_TB_CCR0 ((uint16_t) 0x02U)
#define DAC12_CTL1_SHS_TB_CCR1 ((uint16_t) 0x03U)

#define DAC12_CTL1_R_SHS_MASK (DAC12_CTL1_SHS_MASK << DAC12_CTL1_R_SHS_BIT)
#define DAC12_CTL1_R_SHS_SOFTWARE (DAC12_CTL1_SHS_SOFTWARE << DAC12_CTL1_R_SHS_BIT)
#define DAC12_CTL1_R_SHS_TA_CCR1 (DAC12_CTL1_SHS_TA_CCR1 << DAC12_CTL1_R_SHS_BIT)
#define DAC12_CTL1_R_SHS_TB_CCR0 (DAC12_CTL1_SHS_TB_CCR0 << DAC12_CTL1_R_SHS_BIT)
#define DAC12_CTL1_R_SHS_TB_CCR1 (DAC12_CTL1_SHS_TB_CCR1 << DAC12_CTL1_R_SHS_BIT)
/*-----------*/

/*-----------*/
#define DAC12_CTL1_R_CSTARTADD_BIT ((uint16_t) 12U)

#define DAC12_CTL1_CSTARTADD_MASK ((uint16_t) 0x0FU)
#define DAC12_CTL1_CSTARTADD_CH0 ((uint16_t) 0U)
#define DAC12_CTL1_CSTARTADD_CH1 ((uint16_t) 1U)
#define DAC12_CTL1_CSTARTADD_CH2 ((uint16_t) 2U)
#define DAC12_CTL1_CSTARTADD_CH3 ((uint16_t) 3U)
#define DAC12_CTL1_CSTARTADD_CH4 ((uint16_t) 4U)
#define DAC12_CTL1_CSTARTADD_CH5 ((uint16_t) 5U)
#define DAC12_CTL1_CSTARTADD_CH6 ((uint16_t) 6U)
#define DAC12_CTL1_CSTARTADD_CH7 ((uint16_t) 7U)
#define DAC12_CTL1_CSTARTADD_CH8 ((uint16_t) 8U)
#define DAC12_CTL1_CSTARTADD_CH9 ((uint16_t) 9U)
#define DAC12_CTL1_CSTARTADD_CH10 ((uint16_t) 10U)
#define DAC12_CTL1_CSTARTADD_CH11 ((uint16_t) 11U)
#define DAC12_CTL1_CSTARTADD_CH12 ((uint16_t) 12U)
#define DAC12_CTL1_CSTARTADD_CH13 ((uint16_t) 13U)
#define DAC12_CTL1_CSTARTADD_CH14 ((uint16_t) 14U)
#define DAC12_CTL1_CSTARTADD_CH15 ((uint16_t) 15U)

#define DAC12_CTL1_R_CSTARTADD_MASK (DAC12_CTL1_CSTARTADD_MASK << DAC12_CTL1_R_CSTARTADD_BIT)
#define DAC12_CTL1_R_CSTARTADD_CH0 (DAC12_CTL1_CSTARTADD_CH0 << DAC12_CTL1_R_CSTARTADD_BIT)
#define DAC12_CTL1_R_CSTARTADD_CH1 (DAC12_CTL1_CSTARTADD_CH1 << DAC12_CTL1_R_CSTARTADD_BIT)
#define DAC12_CTL1_R_CSTARTADD_CH2 (DAC12_CTL1_CSTARTADD_CH2 << DAC12_CTL1_R_CSTARTADD_BIT)
#define DAC12_CTL1_R_CSTARTADD_CH3 (DAC12_CTL1_CSTARTADD_CH3 << DAC12_CTL1_R_CSTARTADD_BIT)
#define DAC12_CTL1_R_CSTARTADD_CH4 (DAC12_CTL1_CSTARTADD_CH4 << DAC12_CTL1_R_CSTARTADD_BIT)
#define DAC12_CTL1_R_CSTARTADD_CH5 (DAC12_CTL1_CSTARTADD_CH5 << DAC12_CTL1_R_CSTARTADD_BIT)
#define DAC12_CTL1_R_CSTARTADD_CH6 (DAC12_CTL1_CSTARTADD_CH6 << DAC12_CTL1_R_CSTARTADD_BIT)
#define DAC12_CTL1_R_CSTARTADD_CH7 (DAC12_CTL1_CSTARTADD_CH7 << DAC12_CTL1_R_CSTARTADD_BIT)
#define DAC12_CTL1_R_CSTARTADD_CH8 (DAC12_CTL1_CSTARTADD_CH8 << DAC12_CTL1_R_CSTARTADD_BIT)
#define DAC12_CTL1_R_CSTARTADD_CH9 (DAC12_CTL1_CSTARTADD_CH9 << DAC12_CTL1_R_CSTARTADD_BIT)
#define DAC12_CTL1_R_CSTARTADD_CH10 (DAC12_CTL1_CSTARTADD_CH10 << DAC12_CTL1_R_CSTARTADD_BIT)
#define DAC12_CTL1_R_CSTARTADD_CH11 (DAC12_CTL1_CSTARTADD_CH11 << DAC12_CTL1_R_CSTARTADD_BIT)
#define DAC12_CTL1_R_CSTARTADD_CH12 (DAC12_CTL1_CSTARTADD_CH12 << DAC12_CTL1_R_CSTARTADD_BIT)
#define DAC12_CTL1_R_CSTARTADD_CH13 (DAC12_CTL1_CSTARTADD_CH13 << DAC12_CTL1_R_CSTARTADD_BIT)
#define DAC12_CTL1_R_CSTARTADD_CH14 (DAC12_CTL1_CSTARTADD_CH14 << DAC12_CTL1_R_CSTARTADD_BIT)
#define DAC12_CTL1_R_CSTARTADD_CH15 (DAC12_CTL1_CSTARTADD_CH15 << DAC12_CTL1_R_CSTARTADD_BIT)
/*-----------*/




#endif /* DAC12_PERIPHERAL_REGISTERDEFINES_HEADER_DAC12_REGISTERDEFINES_CTL1_H_ */
