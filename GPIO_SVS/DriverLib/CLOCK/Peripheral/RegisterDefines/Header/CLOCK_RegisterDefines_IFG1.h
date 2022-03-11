/**
 *
 * @file CLOCK_RegisterDefines_IFG1.h
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
 * @verbatim 12 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 12 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef CLOCK_PERIPHERAL_REGISTERDEFINES_HEADER_CLOCK_REGISTERDEFINES_IFG1_H_
#define CLOCK_PERIPHERAL_REGISTERDEFINES_HEADER_CLOCK_REGISTERDEFINES_IFG1_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

/******************************************************************************************
 ************************************ 2 IFG1 *********************************************
 ******************************************************************************************/
/*-----------*/
#define CLOCK_IFG1_R_IFG_BIT ((uint8_t) 1U)

#define CLOCK_IFG1_IFG_MASK ((uint8_t) 0x01U)
#define CLOCK_IFG1_IFG_NOOCCUR ((uint8_t) 0x00U)
#define CLOCK_IFG1_IFG_OCCUR ((uint8_t) 0x01U)

#define CLOCK_IFG1_R_IFG_MASK (CLOCK_IFG1_IFG_MASK<< CLOCK_IFG1_R_IFG_BIT)
#define CLOCK_IFG1_R_IFG_NOOCCUR (CLOCK_IFG1_IFG_NOOCCUR << CLOCK_IFG1_R_IFG_BIT)
#define CLOCK_IFG1_R_IFG_OCCUR (CLOCK_IFG1_IFG_OCCUR << CLOCK_IFG1_R_IFG_BIT)
/*-----------*/

#endif /* CLOCK_PERIPHERAL_REGISTERDEFINES_HEADER_CLOCK_REGISTERDEFINES_IFG1_H_ */
