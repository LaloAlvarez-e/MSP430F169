/**
 *
 * @file GPIO_RegisterPeripheral_PORT2.h
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
 * @verbatim 5 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 5 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef GPIO_PERIPHERAL_REGISTERPERIPHERAL_HEADER_GPIO_REGISTERPERIPHERAL_PORT2_H_
#define GPIO_PERIPHERAL_REGISTERPERIPHERAL_HEADER_GPIO_REGISTERPERIPHERAL_PORT2_H_

#include "GPIO/Peripheral/Header/GPIO_RegisterAddress.h"
#include "GPIO/Peripheral/Header/GPIO_StructPeripheral.h"
#include <stdint.h>

#define PORT2 ((PORT_EXT_t*) PORT2_BASE)

/******************************************************************************************
 ************************************ 1 IN *********************************************
 ******************************************************************************************/
#define PORT2_IN_R  (*(volatile const uint8_t*) (PORT2_BASE + PORT_IN_OFFSET))
#define PORT2_IN    ((PORT_REG_CONST_t*) (PORT2_BASE + PORT_IN_OFFSET))

/******************************************************************************************
 ************************************ 2 OUT *********************************************
 ******************************************************************************************/
#define PORT2_OUT_R (*(volatile uint8_t*) (PORT2_BASE + PORT_OUT_OFFSET))
#define PORT2_OUT ((PORT_REG_t*) (PORT2_BASE + PORT_OUT_OFFSET))

/******************************************************************************************
 ************************************ 3 DIR *********************************************
 ******************************************************************************************/
#define PORT2_DIR_R (*(volatile uint8_t*) (PORT2_BASE + PORT_DIR_OFFSET))
#define PORT2_DIR ((PORT_REG_t*) (PORT2_BASE + PORT_DIR_OFFSET))

/******************************************************************************************
 ************************************ 3 SEL *********************************************
 ******************************************************************************************/
#define PORT2_SEL_R (*(volatile uint8_t*) (PORT2_BASE + PORT_EXT_SEL_OFFSET))
#define PORT2_SEL ((PORT_REG_t*) (PORT2_BASE + PORT_EXT_SEL_OFFSET))

/******************************************************************************************
 ************************************ 4 IFG *********************************************
 ******************************************************************************************/
#define PORT2_IFG_R (*(volatile uint8_t*) (PORT2_BASE + PORT_IFG_OFFSET))
#define PORT2_IFG ((PORT_REG_t*) (PORT2_BASE + PORT_IFG_OFFSET))

/******************************************************************************************
 ************************************ 5 IES *********************************************
 ******************************************************************************************/
#define PORT2_IES_R (*(volatile uint8_t*) (PORT2_BASE + PORT_IES_OFFSET))
#define PORT2_IES ((PORT_REG_t*) (PORT2_BASE + PORT_IES_OFFSET))


/******************************************************************************************
 ************************************ 6 IE *********************************************
 ******************************************************************************************/
#define PORT2_IE_R (*(volatile uint8_t*) (PORT2_BASE + PORT_IE_OFFSET))
#define PORT2_IE ((PORT_REG_t*) (PORT2_BASE + PORT_IE_OFFSET))

#endif /* GPIO_PERIPHERAL_REGISTERPERIPHERAL_HEADER_GPIO_REGISTERPERIPHERAL_PORT2_H_ */
