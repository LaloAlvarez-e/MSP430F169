/**
 *
 * @file GPIO_RegisterDefines_IES.h
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

#ifndef GPIO_PERIPHERAL_REGISTERDEFINES_HEADER_GPIO_REGISTERDEFINES_IES_H_
#define GPIO_PERIPHERAL_REGISTERDEFINES_HEADER_GPIO_REGISTERDEFINES_IES_H_

#include <stdint.h>

/******************************************************************************************
 ************************************ 7 IES *********************************************
 ******************************************************************************************/
/*-----------*/
#define PORT_IES_R_PIN_ALL_BIT ((uint8_t) 0U)
#define PORT_IES_R_PIN_ALL_MASK ((uint8_t) 0xFFU << PORT_IES_R_PIN0_BIT)
#define PORT_IES_R_PIN_ALL_RISING ((uint8_t) 0x00U << PORT_IES_R_PIN0_BIT)
#define PORT_IES_R_PIN_ALL_FALLING ((uint8_t) 0xFFU << PORT_IES_R_PIN0_BIT)

#define PORT_IES_PIN_ALL_MASK ((uint8_t) 0xFFU)
#define PORT_IES_PIN_ALL_RISING ((uint8_t) 0x00U)
#define PORT_IES_PIN_ALL_FALLING ((uint8_t) 0xFFU)
/*-----------*/

/*-----------*/
#define PORT_IES_R_PIN0_BIT ((uint8_t) 0U)
#define PORT_IES_R_PIN0_MASK ((uint8_t) 0x01U << PORT_IES_R_PIN0_BIT)
#define PORT_IES_R_PIN0_RISING ((uint8_t) 0x00U << PORT_IES_R_PIN0_BIT)
#define PORT_IES_R_PIN0_FALLING ((uint8_t) 0x01U << PORT_IES_R_PIN0_BIT)

#define PORT_IES_PIN0_MASK ((uint8_t) 0x01U)
#define PORT_IES_PIN0_RISING ((uint8_t) 0x00U)
#define PORT_IES_PIN0_FALLING ((uint8_t) 0x01U)
/*-----------*/

/*-----------*/
#define PORT_IES_R_PIN1_BIT ((uint8_t) 1U)
#define PORT_IES_R_PIN1_MASK ((uint8_t) 0x01U << PORT_IES_R_PIN1_BIT)
#define PORT_IES_R_PIN1_RISING ((uint8_t) 0x00U << PORT_IES_R_PIN1_BIT)
#define PORT_IES_R_PIN1_FALLING ((uint8_t) 0x01U << PORT_IES_R_PIN1_BIT)

#define PORT_IES_PIN1_MASK ((uint8_t) 0x01U)
#define PORT_IES_PIN1_RISING ((uint8_t) 0x00U)
#define PORT_IES_PIN1_FALLING ((uint8_t) 0x01U)
/*-----------*/

/*-----------*/
#define PORT_IES_R_PIN2_BIT ((uint8_t) 2U)
#define PORT_IES_R_PIN2_MASK ((uint8_t) 0x01U << PORT_IES_R_PIN2_BIT)
#define PORT_IES_R_PIN2_RISING ((uint8_t) 0x00U << PORT_IES_R_PIN2_BIT)
#define PORT_IES_R_PIN2_FALLING ((uint8_t) 0x01U << PORT_IES_R_PIN2_BIT)

#define PORT_IES_PIN2_MASK ((uint8_t) 0x01U)
#define PORT_IES_PIN2_RISING ((uint8_t) 0x00U)
#define PORT_IES_PIN2_FALLING ((uint8_t) 0x01U)
/*-----------*/

/*-----------*/
#define PORT_IES_R_PIN3_BIT ((uint8_t) 3U)
#define PORT_IES_R_PIN3_MASK ((uint8_t) 0x01U << PORT_IES_R_PIN3_BIT)
#define PORT_IES_R_PIN3_RISING ((uint8_t) 0x00U << PORT_IES_R_PIN3_BIT)
#define PORT_IES_R_PIN3_FALLING ((uint8_t) 0x01U << PORT_IES_R_PIN3_BIT)

#define PORT_IES_PIN3_MASK ((uint8_t) 0x01U)
#define PORT_IES_PIN3_RISING ((uint8_t) 0x00U)
#define PORT_IES_PIN3_FALLING ((uint8_t) 0x01U)
/*-----------*/

/*-----------*/
#define PORT_IES_R_PIN4_BIT ((uint8_t) 4U)
#define PORT_IES_R_PIN4_MASK ((uint8_t) 0x01U << PORT_IES_R_PIN4_BIT)
#define PORT_IES_R_PIN4_RISING ((uint8_t) 0x00U << PORT_IES_R_PIN4_BIT)
#define PORT_IES_R_PIN4_FALLING ((uint8_t) 0x01U << PORT_IES_R_PIN4_BIT)

#define PORT_IES_PIN4_MASK ((uint8_t) 0x01U)
#define PORT_IES_PIN4_RISING ((uint8_t) 0x00U)
#define PORT_IES_PIN4_FALLING ((uint8_t) 0x01U)
/*-----------*/

/*-----------*/
#define PORT_IES_R_PIN5_BIT ((uint8_t) 5U)
#define PORT_IES_R_PIN5_MASK ((uint8_t) 0x01U << PORT_IES_R_PIN5_BIT)
#define PORT_IES_R_PIN5_RISING ((uint8_t) 0x00U << PORT_IES_R_PIN5_BIT)
#define PORT_IES_R_PIN5_FALLING ((uint8_t) 0x01U << PORT_IES_R_PIN5_BIT)

#define PORT_IES_PIN5_MASK ((uint8_t) 0x01U)
#define PORT_IES_PIN5_RISING ((uint8_t) 0x00U)
#define PORT_IES_PIN5_FALLING ((uint8_t) 0x01U)
/*-----------*/

/*-----------*/
#define PORT_IES_R_PIN6_BIT ((uint8_t) 6U)
#define PORT_IES_R_PIN6_MASK ((uint8_t) 0x01U << PORT_IES_R_PIN6_BIT)
#define PORT_IES_R_PIN6_RISING ((uint8_t) 0x00U << PORT_IES_R_PIN6_BIT)
#define PORT_IES_R_PIN6_FALLING ((uint8_t) 0x01U << PORT_IES_R_PIN6_BIT)

#define PORT_IES_PIN6_MASK ((uint8_t) 0x01U)
#define PORT_IES_PIN6_RISING ((uint8_t) 0x00U)
#define PORT_IES_PIN6_FALLING ((uint8_t) 0x01U)
/*-----------*/

/*-----------*/
#define PORT_IES_R_PIN7_BIT ((uint8_t) 7U)
#define PORT_IES_R_PIN7_MASK ((uint8_t) 0x01U << PORT_IES_R_PIN7_BIT)
#define PORT_IES_R_PIN7_RISING ((uint8_t) 0x00U << PORT_IES_R_PIN7_BIT)
#define PORT_IES_R_PIN7_FALLING ((uint8_t) 0x01U << PORT_IES_R_PIN7_BIT)

#define PORT_IES_PIN7_MASK ((uint8_t) 0x01U)
#define PORT_IES_PIN7_RISING ((uint8_t) 0x00U)
#define PORT_IES_PIN7_FALLING ((uint8_t) 0x01U)
/*-----------*/

#endif /* GPIO_PERIPHERAL_REGISTERDEFINES_HEADER_GPIO_REGISTERDEFINES_IES_H_ */
