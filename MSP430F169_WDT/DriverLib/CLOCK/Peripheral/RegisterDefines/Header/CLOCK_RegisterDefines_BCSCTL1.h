/**
 *
 * @file CLOCK_RegisterDefines_BCSCTL1.h
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
 * @verbatim 12 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 12 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef CLOCK_PERIPHERAL_REGISTERDEFINES_HEADER_CLOCK_REGISTERDEFINES_BCSCTL1_H_
#define CLOCK_PERIPHERAL_REGISTERDEFINES_HEADER_CLOCK_REGISTERDEFINES_BCSCTL1_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

/******************************************************************************************
 ************************************ 4 BCSCTL1 *********************************************
 ******************************************************************************************/
/*-----------*/
#define CLOCK_BCSCTL1_R_RSEL_BIT ((uint8_t) 0U)

#define CLOCK_BCSCTL1_RSEL_MASK ((uint8_t) 0x07U)
#define CLOCK_BCSCTL1_RSEL_0 ((uint8_t) 0x00U)
#define CLOCK_BCSCTL1_RSEL_1 ((uint8_t) 0x01U)
#define CLOCK_BCSCTL1_RSEL_2 ((uint8_t) 0x02U)
#define CLOCK_BCSCTL1_RSEL_3 ((uint8_t) 0x03U)
#define CLOCK_BCSCTL1_RSEL_4 ((uint8_t) 0x04U)
#define CLOCK_BCSCTL1_RSEL_5 ((uint8_t) 0x05U)
#define CLOCK_BCSCTL1_RSEL_6 ((uint8_t) 0x06U)
#define CLOCK_BCSCTL1_RSEL_7 ((uint8_t) 0x07U)

#define CLOCK_BCSCTL1_R_RSEL_MASK (CLOCK_BCSCTL1_RSEL_MASK<< CLOCK_BCSCTL1_R_RSEL_BIT)
#define CLOCK_BCSCTL1_R_RSEL_0 (CLOCK_BCSCTL1_RSEL_0 << CLOCK_BCSCTL1_R_RSEL_BIT)
#define CLOCK_BCSCTL1_R_RSEL_1 (CLOCK_BCSCTL1_RSEL_1 << CLOCK_BCSCTL1_R_RSEL_BIT)
#define CLOCK_BCSCTL1_R_RSEL_2 (CLOCK_BCSCTL1_RSEL_2 << CLOCK_BCSCTL1_R_RSEL_BIT)
#define CLOCK_BCSCTL1_R_RSEL_3 (CLOCK_BCSCTL1_RSEL_3 << CLOCK_BCSCTL1_R_RSEL_BIT)
#define CLOCK_BCSCTL1_R_RSEL_4 (CLOCK_BCSCTL1_RSEL_4 << CLOCK_BCSCTL1_R_RSEL_BIT)
#define CLOCK_BCSCTL1_R_RSEL_5 (CLOCK_BCSCTL1_RSEL_5 << CLOCK_BCSCTL1_R_RSEL_BIT)
#define CLOCK_BCSCTL1_R_RSEL_6 (CLOCK_BCSCTL1_RSEL_6 << CLOCK_BCSCTL1_R_RSEL_BIT)
#define CLOCK_BCSCTL1_R_RSEL_7 (CLOCK_BCSCTL1_RSEL_7 << CLOCK_BCSCTL1_R_RSEL_BIT)
/*-----------*/

/*-----------*/
#define CLOCK_BCSCTL1_R_XT5V_BIT ((uint8_t) 3U)

#define CLOCK_BCSCTL1_XT5V_MASK ((uint8_t) 0x01U)
#define CLOCK_BCSCTL1_XT5V_RESET ((uint8_t) 0x00U)

#define CLOCK_BCSCTL1_R_XT5V_MASK (CLOCK_BCSCTL1_XT5V_MASK<< CLOCK_BCSCTL1_R_XT5V_BIT)
#define CLOCK_BCSCTL1_R_XT5V_RESET (CLOCK_BCSCTL1_XT5V_RESET << CLOCK_BCSCTL1_R_XT5V_BIT)
/*-----------*/

/*-----------*/
#define CLOCK_BCSCTL1_R_DIVA_BIT ((uint8_t) 4U)

#define CLOCK_BCSCTL1_DIVA_MASK ((uint8_t) 0x03U)
#define CLOCK_BCSCTL1_DIVA_1 ((uint8_t) 0x00U)
#define CLOCK_BCSCTL1_DIVA_2 ((uint8_t) 0x01U)
#define CLOCK_BCSCTL1_DIVA_4 ((uint8_t) 0x02U)
#define CLOCK_BCSCTL1_DIVA_8 ((uint8_t) 0x03U)

#define CLOCK_BCSCTL1_R_DIVA_MASK (CLOCK_BCSCTL1_DIVA_MASK<< CLOCK_BCSCTL1_R_DIVA_BIT)
#define CLOCK_BCSCTL1_R_DIVA_1 (CLOCK_BCSCTL1_DIVA_1 << CLOCK_BCSCTL1_R_DIVA_BIT)
#define CLOCK_BCSCTL1_R_DIVA_2 (CLOCK_BCSCTL1_DIVA_2 << CLOCK_BCSCTL1_R_DIVA_BIT)
#define CLOCK_BCSCTL1_R_DIVA_4 (CLOCK_BCSCTL1_DIVA_4 << CLOCK_BCSCTL1_R_DIVA_BIT)
#define CLOCK_BCSCTL1_R_DIVA_8 (CLOCK_BCSCTL1_DIVA_8 << CLOCK_BCSCTL1_R_DIVA_BIT)
/*-----------*/

/*-----------*/
#define CLOCK_BCSCTL1_R_XTS_BIT ((uint8_t) 6U)

#define CLOCK_BCSCTL1_XTS_MASK ((uint8_t) 0x01U)
#define CLOCK_BCSCTL1_XTS_LOW ((uint8_t) 0x00U)
#define CLOCK_BCSCTL1_XTS_HIGH ((uint8_t) 0x01U)

#define CLOCK_BCSCTL1_R_XTS_MASK (CLOCK_BCSCTL1_XTS_MASK<< CLOCK_BCSCTL1_R_XTS_BIT)
#define CLOCK_BCSCTL1_R_XTS_LOW (CLOCK_BCSCTL1_XTS_LOW << CLOCK_BCSCTL1_R_XTS_BIT)
#define CLOCK_BCSCTL1_R_XTS_HIGH (CLOCK_BCSCTL1_XTS_HIGH << CLOCK_BCSCTL1_R_XTS_BIT)
/*-----------*/

/*-----------*/
#define CLOCK_BCSCTL1_R_XT2OFF_BIT ((uint8_t) 7U)

#define CLOCK_BCSCTL1_XT2OFF_MASK ((uint8_t) 0x01U)
#define CLOCK_BCSCTL1_XT2OFF_ON ((uint8_t) 0x00U)
#define CLOCK_BCSCTL1_XT2OFF_OFF ((uint8_t) 0x01U)

#define CLOCK_BCSCTL1_R_XT2OFF_MASK (CLOCK_BCSCTL1_XT2OFF_MASK<< CLOCK_BCSCTL1_R_XT2OFF_BIT)
#define CLOCK_BCSCTL1_R_XT2OFF_ON (CLOCK_BCSCTL1_XT2OFF_ON << CLOCK_BCSCTL1_R_XT2OFF_BIT)
#define CLOCK_BCSCTL1_R_XT2OFF_OFF (CLOCK_BCSCTL1_XT2OFF_OFF << CLOCK_BCSCTL1_R_XT2OFF_BIT)
/*-----------*/


#endif /* CLOCK_PERIPHERAL_REGISTERDEFINES_HEADER_CLOCK_REGISTERDEFINES_BCSCTL1_H_ */
