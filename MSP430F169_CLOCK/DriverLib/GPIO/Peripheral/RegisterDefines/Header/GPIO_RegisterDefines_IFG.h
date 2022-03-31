/**
 *
 * @file GPIO_RegisterDefines_IFG.h
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

#ifndef GPIO_PERIPHERAL_REGISTERDEFINES_HEADER_GPIO_REGISTERDEFINES_IFG_H_
#define GPIO_PERIPHERAL_REGISTERDEFINES_HEADER_GPIO_REGISTERDEFINES_IFG_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

/******************************************************************************************
 ************************************ 5 IFG *********************************************
 ******************************************************************************************/
/*-----------*/
#define PORT_IFG_R_PIN_ALL_BIT ((uint8_t) 0U)

#define PORT_IFG_PIN_ALL_MASK ((uint8_t) 0xFFU)
#define PORT_IFG_PIN_ALL_NOOCCUR ((uint8_t) 0x00U)
#define PORT_IFG_PIN_ALL_OCCUR ((uint8_t) 0xFFU)

#define PORT_IFG_R_PIN_ALL_MASK (PORT_IFG_PIN_ALL_MASK << PORT_IFG_R_PIN0_BIT)
#define PORT_IFG_R_PIN_ALL_NOOCCUR (PORT_IFG_PIN_ALL_NOOCCUR << PORT_IFG_R_PIN0_BIT)
#define PORT_IFG_R_PIN_ALL_OCCUR (PORT_IFG_PIN_ALL_OCCUR << PORT_IFG_R_PIN0_BIT)
/*-----------*/

/*-----------*/
#define PORT_IFG_R_PIN0_BIT ((uint8_t) 0U)

#define PORT_IFG_PIN0_MASK ((uint8_t) 0x01U)
#define PORT_IFG_PIN0_NOOCCUR ((uint8_t) 0x00U)
#define PORT_IFG_PIN0_OCCUR ((uint8_t) 0x01U)

#define PORT_IFG_R_PIN0_MASK (PORT_IFG_PIN0_MASK << PORT_IFG_R_PIN0_BIT)
#define PORT_IFG_R_PIN0_NOOCCUR (PORT_IFG_PIN0_NOOCCUR << PORT_IFG_R_PIN0_BIT)
#define PORT_IFG_R_PIN0_OCCUR (PORT_IFG_PIN0_OCCUR << PORT_IFG_R_PIN0_BIT)
/*-----------*/

/*-----------*/
#define PORT_IFG_R_PIN1_BIT ((uint8_t) 1U)

#define PORT_IFG_PIN1_MASK ((uint8_t) 0x01U)
#define PORT_IFG_PIN1_NOOCCUR ((uint8_t) 0x00U)
#define PORT_IFG_PIN1_OCCUR ((uint8_t) 0x01U)

#define PORT_IFG_R_PIN1_MASK (PORT_IFG_PIN1_MASK << PORT_IFG_R_PIN1_BIT)
#define PORT_IFG_R_PIN1_NOOCCUR (PORT_IFG_PIN1_NOOCCUR << PORT_IFG_R_PIN1_BIT)
#define PORT_IFG_R_PIN1_OCCUR (PORT_IFG_PIN1_OCCUR << PORT_IFG_R_PIN1_BIT)
/*-----------*/

/*-----------*/
#define PORT_IFG_R_PIN2_BIT ((uint8_t) 2U)

#define PORT_IFG_PIN2_MASK ((uint8_t) 0x01U)
#define PORT_IFG_PIN2_NOOCCUR ((uint8_t) 0x00U)
#define PORT_IFG_PIN2_OCCUR ((uint8_t) 0x01U)

#define PORT_IFG_R_PIN2_MASK (PORT_IFG_PIN2_MASK << PORT_IFG_R_PIN2_BIT)
#define PORT_IFG_R_PIN2_NOOCCUR (PORT_IFG_PIN2_NOOCCUR << PORT_IFG_R_PIN2_BIT)
#define PORT_IFG_R_PIN2_OCCUR (PORT_IFG_PIN2_OCCUR << PORT_IFG_R_PIN2_BIT)
/*-----------*/

/*-----------*/
#define PORT_IFG_R_PIN3_BIT ((uint8_t) 3U)

#define PORT_IFG_PIN3_MASK ((uint8_t) 0x01U)
#define PORT_IFG_PIN3_NOOCCUR ((uint8_t) 0x00U)
#define PORT_IFG_PIN3_OCCUR ((uint8_t) 0x01U)

#define PORT_IFG_R_PIN3_MASK (PORT_IFG_PIN3_MASK << PORT_IFG_R_PIN3_BIT)
#define PORT_IFG_R_PIN3_NOOCCUR (PORT_IFG_PIN3_NOOCCUR << PORT_IFG_R_PIN3_BIT)
#define PORT_IFG_R_PIN3_OCCUR (PORT_IFG_PIN3_OCCUR << PORT_IFG_R_PIN3_BIT)
/*-----------*/

/*-----------*/
#define PORT_IFG_R_PIN4_BIT ((uint8_t) 4U)

#define PORT_IFG_PIN4_MASK ((uint8_t) 0x01U)
#define PORT_IFG_PIN4_NOOCCUR ((uint8_t) 0x00U)
#define PORT_IFG_PIN4_OCCUR ((uint8_t) 0x01U)

#define PORT_IFG_R_PIN4_MASK (PORT_IFG_PIN4_MASK << PORT_IFG_R_PIN4_BIT)
#define PORT_IFG_R_PIN4_NOOCCUR (PORT_IFG_PIN4_NOOCCUR << PORT_IFG_R_PIN4_BIT)
#define PORT_IFG_R_PIN4_OCCUR (PORT_IFG_PIN4_OCCUR << PORT_IFG_R_PIN4_BIT)
/*-----------*/

/*-----------*/
#define PORT_IFG_R_PIN5_BIT ((uint8_t) 5U)

#define PORT_IFG_PIN5_MASK ((uint8_t) 0x01U)
#define PORT_IFG_PIN5_NOOCCUR ((uint8_t) 0x00U)
#define PORT_IFG_PIN5_OCCUR ((uint8_t) 0x01U)

#define PORT_IFG_R_PIN5_MASK (PORT_IFG_PIN5_MASK << PORT_IFG_R_PIN5_BIT)
#define PORT_IFG_R_PIN5_NOOCCUR (PORT_IFG_PIN5_NOOCCUR << PORT_IFG_R_PIN5_BIT)
#define PORT_IFG_R_PIN5_OCCUR (PORT_IFG_PIN5_OCCUR << PORT_IFG_R_PIN5_BIT)
/*-----------*/

/*-----------*/
#define PORT_IFG_R_PIN6_BIT ((uint8_t) 6U)

#define PORT_IFG_PIN6_MASK ((uint8_t) 0x01U)
#define PORT_IFG_PIN6_NOOCCUR ((uint8_t) 0x00U)
#define PORT_IFG_PIN6_OCCUR ((uint8_t) 0x01U)

#define PORT_IFG_R_PIN6_MASK (PORT_IFG_PIN6_MASK << PORT_IFG_R_PIN6_BIT)
#define PORT_IFG_R_PIN6_NOOCCUR (PORT_IFG_PIN6_NOOCCUR << PORT_IFG_R_PIN6_BIT)
#define PORT_IFG_R_PIN6_OCCUR (PORT_IFG_PIN6_OCCUR << PORT_IFG_R_PIN6_BIT)
/*-----------*/

/*-----------*/
#define PORT_IFG_R_PIN7_BIT ((uint8_t) 7U)

#define PORT_IFG_PIN7_MASK ((uint8_t) 0x01U)
#define PORT_IFG_PIN7_NOOCCUR ((uint8_t) 0x00U)
#define PORT_IFG_PIN7_OCCUR ((uint8_t) 0x01U)

#define PORT_IFG_R_PIN7_MASK (PORT_IFG_PIN7_MASK << PORT_IFG_R_PIN7_BIT)
#define PORT_IFG_R_PIN7_NOOCCUR (PORT_IFG_PIN7_NOOCCUR << PORT_IFG_R_PIN7_BIT)
#define PORT_IFG_R_PIN7_OCCUR (PORT_IFG_PIN7_OCCUR << PORT_IFG_R_PIN7_BIT)
/*-----------*/

#endif /* GPIO_PERIPHERAL_REGISTERDEFINES_HEADER_GPIO_REGISTERDEFINES_IFG_H_ */
