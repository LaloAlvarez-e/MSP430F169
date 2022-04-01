/**
 *
 * @file FLASH_RegisterDefines_CTL1.h
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
 * @verbatim 31 mar. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 31 mar. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_FLASH_PERIPHERAL_REGISTERDEFINES_HEADER_FLASH_REGISTERDEFINES_CTL1_H_
#define DRIVERLIB_FLASH_PERIPHERAL_REGISTERDEFINES_HEADER_FLASH_REGISTERDEFINES_CTL1_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

/******************************************************************************************
 ************************************ 2 CTL1 *********************************************
 ******************************************************************************************/
/*-----------*/
#define FLASH_CTL1_R_ERASE_BIT ((uint16_t) 1U)

#define FLASH_CTL1_ERASE_MASK ((uint16_t) 0x03U)
#define FLASH_CTL1_ERASE_NOERASE ((uint16_t) 0x00U)
#define FLASH_CTL1_ERASE_SEGMENT ((uint16_t) 0x01U)
#define FLASH_CTL1_ERASE_MAIN ((uint16_t) 0x02U)
#define FLASH_CTL1_ERASE_MAIN_INFO ((uint16_t) 0x03U)

#define FLASH_CTL1_R_ERASE_MASK (FLASH_CTL1_ERASE_MASK<< FLASH_CTL1_R_ERASE_BIT)
#define FLASH_CTL1_R_ERASE_NOERASE (FLASH_CTL1_ERASE_NOERASE << FLASH_CTL1_R_ERASE_BIT)
#define FLASH_CTL1_R_ERASE_SEGMENT (FLASH_CTL1_ERASE_SEGMENT << FLASH_CTL1_R_ERASE_BIT)
#define FLASH_CTL1_R_ERASE_MAIN (FLASH_CTL1_ERASE_MAIN << FLASH_CTL1_R_ERASE_BIT)
#define FLASH_CTL1_R_ERASE_MAIN_INFO (FLASH_CTL1_ERASE_MAIN_INFO << FLASH_CTL1_R_ERASE_BIT)
/*-----------*/

/*-----------*/
#define FLASH_CTL1_R_WRITE_BIT ((uint16_t) 6U)

#define FLASH_CTL1_WRITE_MASK ((uint16_t) 0x03U)
#define FLASH_CTL1_WRITE_OFF ((uint16_t) 0x00U)
#define FLASH_CTL1_WRITE_SINGLE ((uint16_t) 0x01U)
#define FLASH_CTL1_WRITE_BLOCK ((uint16_t) 0x03U)

#define FLASH_CTL1_R_WRITE_MASK (FLASH_CTL1_WRITE_MASK<< FLASH_CTL1_R_WRITE_BIT)
#define FLASH_CTL1_R_WRITE_OFF (FLASH_CTL1_WRITE_OFF << FLASH_CTL1_R_WRITE_BIT)
#define FLASH_CTL1_R_WRITE_SINGLE (FLASH_CTL1_WRITE_SINGLE << FLASH_CTL1_R_WRITE_BIT)
#define FLASH_CTL1_R_WRITE_BLOCK (FLASH_CTL1_WRITE_BLOCK << FLASH_CTL1_R_WRITE_BIT)
/*-----------*/

/*-----------*/
#define FLASH_CTL1_R_KEY_BIT ((uint16_t) 8U)

#define FLASH_CTL1_KEY_MASK ((uint16_t) 0xFFU)
#define FLASH_CTL1_KEY_READ ((uint16_t) 0x96U)
#define FLASH_CTL1_KEY_WRITE ((uint16_t) 0xA5U)

#define FLASH_CTL1_R_KEY_MASK (FLASH_CTL1_KEY_MASK<< FLASH_CTL1_R_KEY_BIT)
#define FLASH_CTL1_R_KEY_READ (FLASH_CTL1_KEY_READ << FLASH_CTL1_R_KEY_BIT)
#define FLASH_CTL1_R_KEY_WRITE (FLASH_CTL1_KEY_WRITE << FLASH_CTL1_R_KEY_BIT)
/*-----------*/

#endif /* DRIVERLIB_FLASH_PERIPHERAL_REGISTERDEFINES_HEADER_FLASH_REGISTERDEFINES_CTL1_H_ */
