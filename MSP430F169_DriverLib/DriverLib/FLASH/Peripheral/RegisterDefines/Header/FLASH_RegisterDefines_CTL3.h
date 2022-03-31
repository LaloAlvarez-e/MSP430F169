/**
 *
 * @file FLASH_RegisterDefines_CTL3.h
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

#ifndef DRIVERLIB_FLASH_PERIPHERAL_REGISTERDEFINES_HEADER_FLASH_REGISTERDEFINES_CTL3_H_
#define DRIVERLIB_FLASH_PERIPHERAL_REGISTERDEFINES_HEADER_FLASH_REGISTERDEFINES_CTL3_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

/******************************************************************************************
 ************************************ 4 CTL3 *********************************************
 ******************************************************************************************/
/*-----------*/
#define FLASH_CTL3_R_BUSY_BIT ((uint16_t) 0U)

#define FLASH_CTL3_BUSY_MASK ((uint16_t) 0x01U)
#define FLASH_CTL3_BUSY_NOBUSY ((uint16_t) 0x00U)
#define FLASH_CTL3_BUSY_BUSY ((uint16_t) 0x01U)

#define FLASH_CTL3_R_BUSY_MASK (FLASH_CTL3_BUSY_MASK<< FLASH_CTL3_R_BUSY_BIT)
#define FLASH_CTL3_R_BUSY_NOBUSY (FLASH_CTL3_BUSY_NOBUSY << FLASH_CTL3_R_BUSY_BIT)
#define FLASH_CTL3_R_BUSY_BUSY (FLASH_CTL3_BUSY_BUSY << FLASH_CTL3_R_BUSY_BIT)
/*-----------*/

/*-----------*/
#define FLASH_CTL3_R_KEYV_BIT ((uint16_t) 1U)

#define FLASH_CTL3_KEYV_MASK ((uint16_t) 0x01U)
#define FLASH_CTL3_KEYV_NOOCCUR ((uint16_t) 0x00U)
#define FLASH_CTL3_KEYV_OCCUR ((uint16_t) 0x01U)

#define FLASH_CTL3_R_KEYV_MASK (FLASH_CTL3_KEYV_MASK<< FLASH_CTL3_R_KEYV_BIT)
#define FLASH_CTL3_R_KEYV_NOOCCUR (FLASH_CTL3_KEYV_NOOCCUR << FLASH_CTL3_R_KEYV_BIT)
#define FLASH_CTL3_R_KEYV_OCCUR (FLASH_CTL3_KEYV_OCCUR << FLASH_CTL3_R_KEYV_BIT)
/*-----------*/

/*-----------*/
#define FLASH_CTL3_R_ACCVIFG_BIT ((uint16_t) 2U)

#define FLASH_CTL3_ACCVIFG_MASK ((uint16_t) 0x01U)
#define FLASH_CTL3_ACCVIFG_NOOCCUR ((uint16_t) 0x00U)
#define FLASH_CTL3_ACCVIFG_OCCUR ((uint16_t) 0x01U)

#define FLASH_CTL3_R_ACCVIFG_MASK (FLASH_CTL3_ACCVIFG_MASK<< FLASH_CTL3_R_ACCVIFG_BIT)
#define FLASH_CTL3_R_ACCVIFG_NOOCCUR (FLASH_CTL3_ACCVIFG_NOOCCUR << FLASH_CTL3_R_ACCVIFG_BIT)
#define FLASH_CTL3_R_ACCVIFG_OCCUR (FLASH_CTL3_ACCVIFG_OCCUR << FLASH_CTL3_R_ACCVIFG_BIT)
/*-----------*/

/*-----------*/
#define FLASH_CTL3_R_WAIT_BIT ((uint16_t) 3U)

#define FLASH_CTL3_WAIT_MASK ((uint16_t) 0x01U)
#define FLASH_CTL3_WAIT_NOREADY ((uint16_t) 0x00U)
#define FLASH_CTL3_WAIT_READY ((uint16_t) 0x01U)

#define FLASH_CTL3_R_WAIT_MASK (FLASH_CTL3_WAIT_MASK<< FLASH_CTL3_R_WAIT_BIT)
#define FLASH_CTL3_R_WAIT_NOREADY (FLASH_CTL3_WAIT_NOREADY << FLASH_CTL3_R_WAIT_BIT)
#define FLASH_CTL3_R_WAIT_READY (FLASH_CTL3_WAIT_READY << FLASH_CTL3_R_WAIT_BIT)
/*-----------*/

/*-----------*/
#define FLASH_CTL3_R_LOCK_BIT ((uint16_t) 4U)

#define FLASH_CTL3_LOCK_MASK ((uint16_t) 0x01U)
#define FLASH_CTL3_LOCK_UNLOCK ((uint16_t) 0x00U)
#define FLASH_CTL3_LOCK_LOCK ((uint16_t) 0x01U)

#define FLASH_CTL3_R_LOCK_MASK (FLASH_CTL3_LOCK_MASK<< FLASH_CTL3_R_LOCK_BIT)
#define FLASH_CTL3_R_LOCK_UNLOCK (FLASH_CTL3_LOCK_UNLOCK << FLASH_CTL3_R_LOCK_BIT)
#define FLASH_CTL3_R_LOCK_LOCK (FLASH_CTL3_LOCK_LOCK << FLASH_CTL3_R_LOCK_BIT)
/*-----------*/

/*-----------*/
#define FLASH_CTL3_R_EMEX_BIT ((uint16_t) 4U)

#define FLASH_CTL3_EMEX_MASK ((uint16_t) 0x01U)
#define FLASH_CTL3_EMEX_NA ((uint16_t) 0x00U)
#define FLASH_CTL3_EMEX_STOP ((uint16_t) 0x01U)

#define FLASH_CTL3_R_EMEX_MASK (FLASH_CTL3_EMEX_MASK<< FLASH_CTL3_R_EMEX_BIT)
#define FLASH_CTL3_R_EMEX_NA (FLASH_CTL3_EMEX_NA << FLASH_CTL3_R_EMEX_BIT)
#define FLASH_CTL3_R_EMEX_STOP (FLASH_CTL3_EMEX_STOP << FLASH_CTL3_R_EMEX_BIT)
/*-----------*/

/*-----------*/
#define FLASH_CTL3_R_KEY_BIT ((uint16_t) 8U)

#define FLASH_CTL3_KEY_MASK ((uint16_t) 0xFFU)
#define FLASH_CTL3_KEY_READ ((uint16_t) 0x96U)
#define FLASH_CTL3_KEY_WRITE ((uint16_t) 0xA5U)

#define FLASH_CTL3_R_KEY_MASK (FLASH_CTL3_KEY_MASK<< FLASH_CTL3_R_KEY_BIT)
#define FLASH_CTL3_R_KEY_READ (FLASH_CTL3_KEY_READ << FLASH_CTL3_R_KEY_BIT)
#define FLASH_CTL3_R_KEY_WRITE (FLASH_CTL3_KEY_WRITE << FLASH_CTL3_R_KEY_BIT)
/*-----------*/


#endif /* DRIVERLIB_FLASH_PERIPHERAL_REGISTERDEFINES_HEADER_FLASH_REGISTERDEFINES_CTL3_H_ */
