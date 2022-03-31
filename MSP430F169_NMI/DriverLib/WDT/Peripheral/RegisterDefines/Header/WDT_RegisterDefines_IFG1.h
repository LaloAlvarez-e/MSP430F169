/**
 *
 * @file WDT_RegisterDefines_IFG1.h
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
 * @verbatim 24 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 24 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_WDT_PERIPHERAL_REGISTERDEFINES_HEADER_WDT_REGISTERDEFINES_IFG1_H_
#define DRIVERLIB_WDT_PERIPHERAL_REGISTERDEFINES_HEADER_WDT_REGISTERDEFINES_IFG1_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

/******************************************************************************************
 ************************************ 2 IFG1 *********************************************
 ******************************************************************************************/
/*-----------*/
#define WDT_IFG1_R_IFG_BIT ((uint8_t) 0U)

#define WDT_IFG1_IFG_MASK ((uint8_t) 0x01U)
#define WDT_IFG1_IFG_NOOCCUR ((uint8_t) 0x00U)
#define WDT_IFG1_IFG_OCCUR ((uint8_t) 0x01U)

#define WDT_IFG1_R_IFG_MASK (WDT_IFG1_IFG_MASK<< WDT_IFG1_R_IFG_BIT)
#define WDT_IFG1_R_IFG_NOOCCUR (WDT_IFG1_IFG_NOOCCUR << WDT_IFG1_R_IFG_BIT)
#define WDT_IFG1_R_IFG_OCCUR (WDT_IFG1_IFG_OCCUR << WDT_IFG1_R_IFG_BIT)
/*-----------*/

#endif /* DRIVERLIB_WDT_PERIPHERAL_REGISTERDEFINES_HEADER_WDT_REGISTERDEFINES_IFG1_H_ */
