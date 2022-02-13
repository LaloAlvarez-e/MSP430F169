/**
 *
 * @file GPIO_RegisterDefines_SEL.h
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

#ifndef GPIO_PERIPHERAL_REGISTERDEFINES_HEADER_GPIO_REGISTERDEFINES_SEL_H_
#define GPIO_PERIPHERAL_REGISTERDEFINES_HEADER_GPIO_REGISTERDEFINES_SEL_H_

#include <stdint.h>

/******************************************************************************************
 ************************************ 4 SEL *********************************************
 ******************************************************************************************/
/*-----------*/
#define PORT_SEL_R_PIN_ALL_BIT ((uint8_t) 0U)

#define PORT_SEL_PIN_ALL_MASK ((uint8_t) 0xFFU)
#define PORT_SEL_PIN_ALL_IO ((uint8_t) 0x00U)
#define PORT_SEL_PIN_ALL_PERIPHERAL ((uint8_t) 0xFFU)

#define PORT_SEL_R_PIN_ALL_MASK (PORT_SEL_PIN_ALL_MASK << PORT_SEL_R_PIN0_BIT)
#define PORT_SEL_R_PIN_ALL_IO (PORT_SEL_PIN_ALL_IO << PORT_SEL_R_PIN0_BIT)
#define PORT_SEL_R_PIN_ALL_PERIPHERAL (PORT_SEL_PIN_ALL_PERIPHERAL << PORT_SEL_R_PIN0_BIT)
/*-----------*/

/*-----------*/
#define PORT_SEL_R_PIN0_BIT ((uint8_t) 0U)

#define PORT_SEL_PIN0_MASK ((uint8_t) 0x01U)
#define PORT_SEL_PIN0_IO ((uint8_t) 0x00U)
#define PORT_SEL_PIN0_PERIPHERAL ((uint8_t) 0x01U)

#define PORT_SEL_R_PIN0_MASK (PORT_SEL_PIN0_MASK << PORT_SEL_R_PIN0_BIT)
#define PORT_SEL_R_PIN0_IO (PORT_SEL_PIN0_IO << PORT_SEL_R_PIN0_BIT)
#define PORT_SEL_R_PIN0_PERIPHERAL (PORT_SEL_PIN0_PERIPHERAL << PORT_SEL_R_PIN0_BIT)
/*-----------*/

/*-----------*/
#define PORT_SEL_R_PIN1_BIT ((uint8_t) 1U)

#define PORT_SEL_PIN1_MASK ((uint8_t) 0x01U)
#define PORT_SEL_PIN1_IO ((uint8_t) 0x00U)
#define PORT_SEL_PIN1_PERIPHERAL ((uint8_t) 0x01U)

#define PORT_SEL_R_PIN1_MASK (PORT_SEL_PIN1_MASK << PORT_SEL_R_PIN1_BIT)
#define PORT_SEL_R_PIN1_IO (PORT_SEL_PIN1_IO << PORT_SEL_R_PIN1_BIT)
#define PORT_SEL_R_PIN1_PERIPHERAL (PORT_SEL_PIN1_PERIPHERAL << PORT_SEL_R_PIN1_BIT)
/*-----------*/

/*-----------*/
#define PORT_SEL_R_PIN2_BIT ((uint8_t) 2U)

#define PORT_SEL_PIN2_MASK ((uint8_t) 0x01U)
#define PORT_SEL_PIN2_IO ((uint8_t) 0x00U)
#define PORT_SEL_PIN2_PERIPHERAL ((uint8_t) 0x01U)

#define PORT_SEL_R_PIN2_MASK (PORT_SEL_PIN2_MASK << PORT_SEL_R_PIN2_BIT)
#define PORT_SEL_R_PIN2_IO (PORT_SEL_PIN2_IO << PORT_SEL_R_PIN2_BIT)
#define PORT_SEL_R_PIN2_PERIPHERAL (PORT_SEL_PIN2_PERIPHERAL << PORT_SEL_R_PIN2_BIT)
/*-----------*/

/*-----------*/
#define PORT_SEL_R_PIN3_BIT ((uint8_t) 3U)

#define PORT_SEL_PIN3_MASK ((uint8_t) 0x01U)
#define PORT_SEL_PIN3_IO ((uint8_t) 0x00U)
#define PORT_SEL_PIN3_PERIPHERAL ((uint8_t) 0x01U)

#define PORT_SEL_R_PIN3_MASK (PORT_SEL_PIN3_MASK << PORT_SEL_R_PIN3_BIT)
#define PORT_SEL_R_PIN3_IO (PORT_SEL_PIN3_IO << PORT_SEL_R_PIN3_BIT)
#define PORT_SEL_R_PIN3_PERIPHERAL (PORT_SEL_PIN3_PERIPHERAL << PORT_SEL_R_PIN3_BIT)
/*-----------*/

/*-----------*/
#define PORT_SEL_R_PIN4_BIT ((uint8_t) 4U)

#define PORT_SEL_PIN4_MASK ((uint8_t) 0x01U)
#define PORT_SEL_PIN4_IO ((uint8_t) 0x00U)
#define PORT_SEL_PIN4_PERIPHERAL ((uint8_t) 0x01U)

#define PORT_SEL_R_PIN4_MASK (PORT_SEL_PIN4_MASK << PORT_SEL_R_PIN4_BIT)
#define PORT_SEL_R_PIN4_IO (PORT_SEL_PIN4_IO << PORT_SEL_R_PIN4_BIT)
#define PORT_SEL_R_PIN4_PERIPHERAL (PORT_SEL_PIN4_PERIPHERAL << PORT_SEL_R_PIN4_BIT)
/*-----------*/

/*-----------*/
#define PORT_SEL_R_PIN5_BIT ((uint8_t) 5U)

#define PORT_SEL_PIN5_MASK ((uint8_t) 0x01U)
#define PORT_SEL_PIN5_IO ((uint8_t) 0x00U)
#define PORT_SEL_PIN5_PERIPHERAL ((uint8_t) 0x01U)

#define PORT_SEL_R_PIN5_MASK (PORT_SEL_PIN5_MASK << PORT_SEL_R_PIN5_BIT)
#define PORT_SEL_R_PIN5_IO (PORT_SEL_PIN5_IO << PORT_SEL_R_PIN5_BIT)
#define PORT_SEL_R_PIN5_PERIPHERAL (PORT_SEL_PIN5_PERIPHERAL << PORT_SEL_R_PIN5_BIT)
/*-----------*/

/*-----------*/
#define PORT_SEL_R_PIN6_BIT ((uint8_t) 6U)

#define PORT_SEL_PIN6_MASK ((uint8_t) 0x01U)
#define PORT_SEL_PIN6_IO ((uint8_t) 0x00U)
#define PORT_SEL_PIN6_PERIPHERAL ((uint8_t) 0x01U)

#define PORT_SEL_R_PIN6_MASK (PORT_SEL_PIN6_MASK << PORT_SEL_R_PIN6_BIT)
#define PORT_SEL_R_PIN6_IO (PORT_SEL_PIN6_IO << PORT_SEL_R_PIN6_BIT)
#define PORT_SEL_R_PIN6_PERIPHERAL (PORT_SEL_PIN6_PERIPHERAL << PORT_SEL_R_PIN6_BIT)
/*-----------*/

/*-----------*/
#define PORT_SEL_R_PIN7_BIT ((uint8_t) 7U)

#define PORT_SEL_PIN7_MASK ((uint8_t) 0x01U)
#define PORT_SEL_PIN7_IO ((uint8_t) 0x00U)
#define PORT_SEL_PIN7_PERIPHERAL ((uint8_t) 0x01U)

#define PORT_SEL_R_PIN7_MASK (PORT_SEL_PIN7_MASK << PORT_SEL_R_PIN7_BIT)
#define PORT_SEL_R_PIN7_IO (PORT_SEL_PIN7_IO << PORT_SEL_R_PIN7_BIT)
#define PORT_SEL_R_PIN7_PERIPHERAL (PORT_SEL_PIN7_PERIPHERAL << PORT_SEL_R_PIN7_BIT)
/*-----------*/


#endif /* GPIO_PERIPHERAL_REGISTERDEFINES_HEADER_GPIO_REGISTERDEFINES_SEL_H_ */
