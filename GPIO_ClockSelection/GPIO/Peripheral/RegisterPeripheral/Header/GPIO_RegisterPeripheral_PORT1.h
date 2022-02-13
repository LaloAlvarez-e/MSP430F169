/**
 *
 * @file GPIO_RegisterPeripheral_PORT1.h
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

#ifndef GPIO_PERIPHERAL_REGISTERPERIPHERAL_HEADER_GPIO_REGISTERPERIPHERAL_PORT1_H_
#define GPIO_PERIPHERAL_REGISTERPERIPHERAL_HEADER_GPIO_REGISTERPERIPHERAL_PORT1_H_

#include "GPIO/Peripheral/Header/GPIO_RegisterAddress.h"
#include "GPIO/Peripheral/Header/GPIO_StructPeripheral.h"
#include "MCU/Header/MCU_Common.h"

#define PORT1 ((PORT_EXT_t*) PORT1_BASE)

/******************************************************************************************
 ************************************ 1 IN *********************************************
 ******************************************************************************************/
#define PORT1_IN_R  (*(volatile const uint8_t*) (PORT1_BASE + PORT_IN_OFFSET))
#define PORT1_IN    ((PORT_REG_CONST_t*) (PORT1_BASE + PORT_IN_OFFSET))

/******************************************************************************************
 ************************************ 2 OUT *********************************************
 ******************************************************************************************/
#define PORT1_OUT_R (*(volatile uint8_t*) (PORT1_BASE + PORT_OUT_OFFSET))
#define PORT1_OUT ((PORT_REG_t*) (PORT1_BASE + PORT_OUT_OFFSET))

/******************************************************************************************
 ************************************ 3 DIR *********************************************
 ******************************************************************************************/
#define PORT1_DIR_R (*(volatile uint8_t*) (PORT1_BASE + PORT_DIR_OFFSET))
#define PORT1_DIR ((PORT_REG_t*) (PORT1_BASE + PORT_DIR_OFFSET))

/******************************************************************************************
 ************************************ 3 SEL *********************************************
 ******************************************************************************************/
#define PORT1_SEL_R (*(volatile uint8_t*) (PORT1_BASE + PORT_EXT_SEL_OFFSET))
#define PORT1_SEL ((PORT_REG_t*) (PORT1_BASE + PORT_EXT_SEL_OFFSET))

/******************************************************************************************
 ************************************ 4 IFG *********************************************
 ******************************************************************************************/
#define PORT1_IFG_R (*(volatile uint8_t*) (PORT1_BASE + PORT_IFG_OFFSET))
#define PORT1_IFG ((PORT_REG_t*) (PORT1_BASE + PORT_IFG_OFFSET))

/******************************************************************************************
 ************************************ 5 IES *********************************************
 ******************************************************************************************/
#define PORT1_IES_R (*(volatile uint8_t*) (PORT1_BASE + PORT_IES_OFFSET))
#define PORT1_IES ((PORT_REG_t*) (PORT1_BASE + PORT_IES_OFFSET))


/******************************************************************************************
 ************************************ 6 IE *********************************************
 ******************************************************************************************/
#define PORT1_IE_R (*(volatile uint8_t*) (PORT1_BASE + PORT_IE_OFFSET))
#define PORT1_IE ((PORT_REG_t*) (PORT1_BASE + PORT_IE_OFFSET))


#endif /* GPIO_PERIPHERAL_REGISTERPERIPHERAL_HEADER_GPIO_REGISTERPERIPHERAL_PORT1_H_ */
