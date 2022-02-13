/**
 *
 * @file GPIO_RegisterDefines_DIR.h
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

#ifndef GPIO_PERIPHERAL_REGISTERDEFINES_HEADER_GPIO_REGISTERDEFINES_DIR_H_
#define GPIO_PERIPHERAL_REGISTERDEFINES_HEADER_GPIO_REGISTERDEFINES_DIR_H_

#include "MCU/Header/MCU_Common.h"

/******************************************************************************************
 ************************************ 3 DIR *********************************************
 ******************************************************************************************/
/*-----------*/
#define PORT_DIR_R_PIN_ALL_BIT ((uint8_t) 0U)

#define PORT_DIR_PIN_ALL_MASK ((uint8_t) 0xFFU)
#define PORT_DIR_PIN_ALL_INPUT ((uint8_t) 0x00U)
#define PORT_DIR_PIN_ALL_OUTPUT ((uint8_t) 0xFFU)

#define PORT_DIR_R_PIN_ALL_MASK (PORT_DIR_PIN_ALL_MASK << PORT_DIR_R_PIN0_BIT)
#define PORT_DIR_R_PIN_ALL_INPUT (PORT_DIR_PIN_ALL_INPUT << PORT_DIR_R_PIN0_BIT)
#define PORT_DIR_R_PIN_ALL_OUTPUT (PORT_DIR_PIN_ALL_OUTPUT << PORT_DIR_R_PIN0_BIT)
/*-----------*/

/*-----------*/
#define PORT_DIR_R_PIN0_BIT ((uint8_t) 0U)

#define PORT_DIR_PIN0_MASK ((uint8_t) 0x01U)
#define PORT_DIR_PIN0_INPUT ((uint8_t) 0x00U)
#define PORT_DIR_PIN0_OUTPUT ((uint8_t) 0x01U)

#define PORT_DIR_R_PIN0_MASK (PORT_DIR_PIN0_MASK << PORT_DIR_R_PIN0_BIT)
#define PORT_DIR_R_PIN0_INPUT (PORT_DIR_PIN0_INPUT << PORT_DIR_R_PIN0_BIT)
#define PORT_DIR_R_PIN0_OUTPUT (PORT_DIR_PIN0_OUTPUT << PORT_DIR_R_PIN0_BIT)
/*-----------*/

/*-----------*/
#define PORT_DIR_R_PIN1_BIT ((uint8_t) 1U)

#define PORT_DIR_PIN1_MASK ((uint8_t) 0x01U)
#define PORT_DIR_PIN1_INPUT ((uint8_t) 0x00U)
#define PORT_DIR_PIN1_OUTPUT ((uint8_t) 0x01U)

#define PORT_DIR_R_PIN1_MASK (PORT_DIR_PIN1_MASK << PORT_DIR_R_PIN1_BIT)
#define PORT_DIR_R_PIN1_INPUT (PORT_DIR_PIN1_INPUT << PORT_DIR_R_PIN1_BIT)
#define PORT_DIR_R_PIN1_OUTPUT (PORT_DIR_PIN1_OUTPUT << PORT_DIR_R_PIN1_BIT)
/*-----------*/

/*-----------*/
#define PORT_DIR_R_PIN2_BIT ((uint8_t) 2U)

#define PORT_DIR_PIN2_MASK ((uint8_t) 0x01U)
#define PORT_DIR_PIN2_INPUT ((uint8_t) 0x00U)
#define PORT_DIR_PIN2_OUTPUT ((uint8_t) 0x01U)

#define PORT_DIR_R_PIN2_MASK (PORT_DIR_PIN2_MASK << PORT_DIR_R_PIN2_BIT)
#define PORT_DIR_R_PIN2_INPUT (PORT_DIR_PIN2_INPUT << PORT_DIR_R_PIN2_BIT)
#define PORT_DIR_R_PIN2_OUTPUT (PORT_DIR_PIN2_OUTPUT << PORT_DIR_R_PIN2_BIT)
/*-----------*/

/*-----------*/
#define PORT_DIR_R_PIN3_BIT ((uint8_t) 3U)

#define PORT_DIR_PIN3_MASK ((uint8_t) 0x01U)
#define PORT_DIR_PIN3_INPUT ((uint8_t) 0x00U)
#define PORT_DIR_PIN3_OUTPUT ((uint8_t) 0x01U)

#define PORT_DIR_R_PIN3_MASK (PORT_DIR_PIN3_MASK << PORT_DIR_R_PIN3_BIT)
#define PORT_DIR_R_PIN3_INPUT (PORT_DIR_PIN3_INPUT << PORT_DIR_R_PIN3_BIT)
#define PORT_DIR_R_PIN3_OUTPUT (PORT_DIR_PIN3_OUTPUT << PORT_DIR_R_PIN3_BIT)
/*-----------*/

/*-----------*/
#define PORT_DIR_R_PIN4_BIT ((uint8_t) 4U)

#define PORT_DIR_PIN4_MASK ((uint8_t) 0x01U)
#define PORT_DIR_PIN4_INPUT ((uint8_t) 0x00U)
#define PORT_DIR_PIN4_OUTPUT ((uint8_t) 0x01U)

#define PORT_DIR_R_PIN4_MASK (PORT_DIR_PIN4_MASK << PORT_DIR_R_PIN4_BIT)
#define PORT_DIR_R_PIN4_INPUT (PORT_DIR_PIN4_INPUT << PORT_DIR_R_PIN4_BIT)
#define PORT_DIR_R_PIN4_OUTPUT (PORT_DIR_PIN4_OUTPUT << PORT_DIR_R_PIN4_BIT)
/*-----------*/

/*-----------*/
#define PORT_DIR_R_PIN5_BIT ((uint8_t) 5U)

#define PORT_DIR_PIN5_MASK ((uint8_t) 0x01U)
#define PORT_DIR_PIN5_INPUT ((uint8_t) 0x00U)
#define PORT_DIR_PIN5_OUTPUT ((uint8_t) 0x01U)

#define PORT_DIR_R_PIN5_MASK (PORT_DIR_PIN5_MASK << PORT_DIR_R_PIN5_BIT)
#define PORT_DIR_R_PIN5_INPUT (PORT_DIR_PIN5_INPUT << PORT_DIR_R_PIN5_BIT)
#define PORT_DIR_R_PIN5_OUTPUT (PORT_DIR_PIN5_OUTPUT << PORT_DIR_R_PIN5_BIT)
/*-----------*/

/*-----------*/
#define PORT_DIR_R_PIN6_BIT ((uint8_t) 6U)

#define PORT_DIR_PIN6_MASK ((uint8_t) 0x01U)
#define PORT_DIR_PIN6_INPUT ((uint8_t) 0x00U)
#define PORT_DIR_PIN6_OUTPUT ((uint8_t) 0x01U)

#define PORT_DIR_R_PIN6_MASK (PORT_DIR_PIN6_MASK << PORT_DIR_R_PIN6_BIT)
#define PORT_DIR_R_PIN6_INPUT (PORT_DIR_PIN6_INPUT << PORT_DIR_R_PIN6_BIT)
#define PORT_DIR_R_PIN6_OUTPUT (PORT_DIR_PIN6_OUTPUT << PORT_DIR_R_PIN6_BIT)
/*-----------*/

/*-----------*/
#define PORT_DIR_R_PIN7_BIT ((uint8_t) 7U)

#define PORT_DIR_PIN7_MASK ((uint8_t) 0x01U)
#define PORT_DIR_PIN7_INPUT ((uint8_t) 0x00U)
#define PORT_DIR_PIN7_OUTPUT ((uint8_t) 0x01U)

#define PORT_DIR_R_PIN7_MASK (PORT_DIR_PIN7_MASK << PORT_DIR_R_PIN7_BIT)
#define PORT_DIR_R_PIN7_INPUT (PORT_DIR_PIN7_INPUT << PORT_DIR_R_PIN7_BIT)
#define PORT_DIR_R_PIN7_OUTPUT (PORT_DIR_PIN7_OUTPUT << PORT_DIR_R_PIN7_BIT)
/*-----------*/

#endif /* GPIO_PERIPHERAL_REGISTERDEFINES_HEADER_GPIO_REGISTERDEFINES_DIR_H_ */
