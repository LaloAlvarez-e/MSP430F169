/**
 *
 * @file FLASH_RegisterDefines_CTL2.h
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

#ifndef DRIVERLIB_FLASH_PERIPHERAL_REGISTERDEFINES_HEADER_FLASH_REGISTERDEFINES_CTL2_H_
#define DRIVERLIB_FLASH_PERIPHERAL_REGISTERDEFINES_HEADER_FLASH_REGISTERDEFINES_CTL2_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

/******************************************************************************************
 ************************************ 3 CTL2 *********************************************
 ******************************************************************************************/

/*-----------*/
#define FLASH_CTL2_R_FN_BIT ((uint16_t) 0U)

#define FLASH_CTL2_FN_MASK ((uint16_t) 0x3FU)

#define FLASH_CTL2_R_FN_MASK (FLASH_CTL2_FN_MASK<< FLASH_CTL2_R_FN_BIT)
/*-----------*/

/*-----------*/
#define FLASH_CTL2_R_SSEL_BIT ((uint16_t) 6U)

#define FLASH_CTL2_SSEL_MASK ((uint16_t) 0x03U)
#define FLASH_CTL2_SSEL_ACLK ((uint16_t) 0x00U)
#define FLASH_CTL2_SSEL_MCLK ((uint16_t) 0x01U)
#define FLASH_CTL2_SSEL_SMCLK ((uint16_t) 0x02U)
#define FLASH_CTL2_SSEL_SMCLK_ ((uint16_t) 0x03U)

#define FLASH_CTL2_R_SSEL_MASK (FLASH_CTL2_SSEL_MASK<< FLASH_CTL2_R_SSEL_BIT)
#define FLASH_CTL2_R_SSEL_ACLK (FLASH_CTL2_SSEL_ACLK << FLASH_CTL2_R_SSEL_BIT)
#define FLASH_CTL2_R_SSEL_MCLK (FLASH_CTL2_SSEL_MCLK << FLASH_CTL2_R_SSEL_BIT)
#define FLASH_CTL2_R_SSEL_SMCLK (FLASH_CTL2_SSEL_SMCLK << FLASH_CTL2_R_SSEL_BIT)
#define FLASH_CTL2_R_SSEL_SMCLK_ (FLASH_CTL2_SSEL_SMCLK_ << FLASH_CTL2_R_SSEL_BIT)
/*-----------*/

/*-----------*/
#define FLASH_CTL2_R_KEY_BIT ((uint16_t) 8U)

#define FLASH_CTL2_KEY_MASK ((uint16_t) 0xFFU)
#define FLASH_CTL2_KEY_READ ((uint16_t) 0x96U)
#define FLASH_CTL2_KEY_WRITE ((uint16_t) 0xA5U)

#define FLASH_CTL2_R_KEY_MASK (FLASH_CTL2_KEY_MASK<< FLASH_CTL2_R_KEY_BIT)
#define FLASH_CTL2_R_KEY_READ (FLASH_CTL2_KEY_READ << FLASH_CTL2_R_KEY_BIT)
#define FLASH_CTL2_R_KEY_WRITE (FLASH_CTL2_KEY_WRITE << FLASH_CTL2_R_KEY_BIT)
/*-----------*/


#endif /* DRIVERLIB_FLASH_PERIPHERAL_REGISTERDEFINES_HEADER_FLASH_REGISTERDEFINES_CTL2_H_ */
