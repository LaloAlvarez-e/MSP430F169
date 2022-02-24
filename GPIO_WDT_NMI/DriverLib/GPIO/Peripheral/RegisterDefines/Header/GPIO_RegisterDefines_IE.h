/**
 *
 * @file GPIO_RegisterDefines_IE.h
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

#ifndef GPIO_PERIPHERAL_REGISTERDEFINES_HEADER_GPIO_REGISTERDEFINES_IE_H_
#define GPIO_PERIPHERAL_REGISTERDEFINES_HEADER_GPIO_REGISTERDEFINES_IE_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

/******************************************************************************************
 ************************************ 8 IE *********************************************
 ******************************************************************************************/
/*-----------*/
#define PORT_IE_R_PIN_ALL_BIT ((uint8_t) 0U)

#define PORT_IE_PIN_ALL_MASK ((uint8_t) 0xFFU)
#define PORT_IE_PIN_ALL_DIS ((uint8_t) 0x00U)
#define PORT_IE_PIN_ALL_ENA ((uint8_t) 0xFFU)

#define PORT_IE_R_PIN_ALL_MASK (PORT_IE_PIN_ALL_MASK << PORT_IE_R_PIN0_BIT)
#define PORT_IE_R_PIN_ALL_DIS (PORT_IE_PIN_ALL_DIS << PORT_IE_R_PIN0_BIT)
#define PORT_IE_R_PIN_ALL_ENA (PORT_IE_PIN_ALL_ENA << PORT_IE_R_PIN0_BIT)
/*-----------*/

/*-----------*/
#define PORT_IE_R_PIN0_BIT ((uint8_t) 0U)

#define PORT_IE_PIN0_MASK ((uint8_t) 0x01U)
#define PORT_IE_PIN0_DIS ((uint8_t) 0x00U)
#define PORT_IE_PIN0_ENA ((uint8_t) 0x01U)

#define PORT_IE_R_PIN0_MASK (PORT_IE_PIN0_MASK << PORT_IE_R_PIN0_BIT)
#define PORT_IE_R_PIN0_DIS (PORT_IE_PIN0_DIS << PORT_IE_R_PIN0_BIT)
#define PORT_IE_R_PIN0_ENA (PORT_IE_PIN0_ENA << PORT_IE_R_PIN0_BIT)
/*-----------*/

/*-----------*/
#define PORT_IE_R_PIN1_BIT ((uint8_t) 1U)

#define PORT_IE_PIN1_MASK ((uint8_t) 0x01U)
#define PORT_IE_PIN1_DIS ((uint8_t) 0x00U)
#define PORT_IE_PIN1_ENA ((uint8_t) 0x01U)

#define PORT_IE_R_PIN1_MASK (PORT_IE_PIN1_MASK << PORT_IE_R_PIN1_BIT)
#define PORT_IE_R_PIN1_DIS (PORT_IE_PIN1_DIS << PORT_IE_R_PIN1_BIT)
#define PORT_IE_R_PIN1_ENA (PORT_IE_PIN1_ENA << PORT_IE_R_PIN1_BIT)
/*-----------*/

/*-----------*/
#define PORT_IE_R_PIN2_BIT ((uint8_t) 2U)

#define PORT_IE_PIN2_MASK ((uint8_t) 0x01U)
#define PORT_IE_PIN2_DIS ((uint8_t) 0x00U)
#define PORT_IE_PIN2_ENA ((uint8_t) 0x01U)

#define PORT_IE_R_PIN2_MASK (PORT_IE_PIN2_MASK << PORT_IE_R_PIN2_BIT)
#define PORT_IE_R_PIN2_DIS (PORT_IE_PIN2_DIS << PORT_IE_R_PIN2_BIT)
#define PORT_IE_R_PIN2_ENA (PORT_IE_PIN2_ENA << PORT_IE_R_PIN2_BIT)
/*-----------*/

/*-----------*/
#define PORT_IE_R_PIN3_BIT ((uint8_t) 3U)

#define PORT_IE_PIN3_MASK ((uint8_t) 0x01U)
#define PORT_IE_PIN3_DIS ((uint8_t) 0x00U)
#define PORT_IE_PIN3_ENA ((uint8_t) 0x01U)

#define PORT_IE_R_PIN3_MASK (PORT_IE_PIN3_MASK << PORT_IE_R_PIN3_BIT)
#define PORT_IE_R_PIN3_DIS (PORT_IE_PIN3_DIS << PORT_IE_R_PIN3_BIT)
#define PORT_IE_R_PIN3_ENA (PORT_IE_PIN3_ENA << PORT_IE_R_PIN3_BIT)
/*-----------*/

/*-----------*/
#define PORT_IE_R_PIN4_BIT ((uint8_t) 4U)

#define PORT_IE_PIN4_MASK ((uint8_t) 0x01U)
#define PORT_IE_PIN4_DIS ((uint8_t) 0x00U)
#define PORT_IE_PIN4_ENA ((uint8_t) 0x01U)

#define PORT_IE_R_PIN4_MASK (PORT_IE_PIN4_MASK << PORT_IE_R_PIN4_BIT)
#define PORT_IE_R_PIN4_DIS (PORT_IE_PIN4_DIS << PORT_IE_R_PIN4_BIT)
#define PORT_IE_R_PIN4_ENA (PORT_IE_PIN4_ENA << PORT_IE_R_PIN4_BIT)
/*-----------*/

/*-----------*/
#define PORT_IE_R_PIN5_BIT ((uint8_t) 5U)

#define PORT_IE_PIN5_MASK ((uint8_t) 0x01U)
#define PORT_IE_PIN5_DIS ((uint8_t) 0x00U)
#define PORT_IE_PIN5_ENA ((uint8_t) 0x01U)

#define PORT_IE_R_PIN5_MASK (PORT_IE_PIN5_MASK << PORT_IE_R_PIN5_BIT)
#define PORT_IE_R_PIN5_DIS (PORT_IE_PIN5_DIS << PORT_IE_R_PIN5_BIT)
#define PORT_IE_R_PIN5_ENA (PORT_IE_PIN5_ENA << PORT_IE_R_PIN5_BIT)
/*-----------*/

/*-----------*/
#define PORT_IE_R_PIN6_BIT ((uint8_t) 6U)

#define PORT_IE_PIN6_MASK ((uint8_t) 0x01U)
#define PORT_IE_PIN6_DIS ((uint8_t) 0x00U)
#define PORT_IE_PIN6_ENA ((uint8_t) 0x01U)

#define PORT_IE_R_PIN6_MASK (PORT_IE_PIN6_MASK << PORT_IE_R_PIN6_BIT)
#define PORT_IE_R_PIN6_DIS (PORT_IE_PIN6_DIS << PORT_IE_R_PIN6_BIT)
#define PORT_IE_R_PIN6_ENA (PORT_IE_PIN6_ENA << PORT_IE_R_PIN6_BIT)
/*-----------*/

/*-----------*/
#define PORT_IE_R_PIN7_BIT ((uint8_t) 7U)

#define PORT_IE_PIN7_MASK ((uint8_t) 0x01U)
#define PORT_IE_PIN7_DIS ((uint8_t) 0x00U)
#define PORT_IE_PIN7_ENA ((uint8_t) 0x01U)

#define PORT_IE_R_PIN7_MASK (PORT_IE_PIN7_MASK << PORT_IE_R_PIN7_BIT)
#define PORT_IE_R_PIN7_DIS (PORT_IE_PIN7_DIS << PORT_IE_R_PIN7_BIT)
#define PORT_IE_R_PIN7_ENA (PORT_IE_PIN7_ENA << PORT_IE_R_PIN7_BIT)
/*-----------*/

#endif /* GPIO_PERIPHERAL_REGISTERDEFINES_HEADER_GPIO_REGISTERDEFINES_IE_H_ */
