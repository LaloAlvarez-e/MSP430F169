/**
 *
 * @file WDT_RegisterDefines_CTL.h
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

#ifndef DRIVERLIB_WDT_PERIPHERAL_REGISTERDEFINES_HEADER_WDT_REGISTERDEFINES_CTL_H_
#define DRIVERLIB_WDT_PERIPHERAL_REGISTERDEFINES_HEADER_WDT_REGISTERDEFINES_CTL_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

/******************************************************************************************
 ************************************ 3 WDTCTL *********************************************
 ******************************************************************************************/
/*-----------*/
#define WDT_CTL_R_IS_BIT ((uint16_t) 0U)

#define WDT_CTL_IS_MASK ((uint16_t) 0x03U)
#define WDT_CTL_IS_32768 ((uint16_t) 0x00U)
#define WDT_CTL_IS_8192 ((uint16_t) 0x01U)
#define WDT_CTL_IS_512 ((uint16_t) 0x02U)
#define WDT_CTL_IS_64 ((uint16_t) 0x03U)

#define WDT_CTL_R_IS_MASK (WDT_CTL_IS_MASK<< WDT_CTL_R_IS_BIT)
#define WDT_CTL_R_IS_32768 (WDT_CTL_IS_32768 << WDT_CTL_R_IS_BIT)
#define WDT_CTL_R_IS_8192 (WDT_CTL_IS_8192 << WDT_CTL_R_IS_BIT)
#define WDT_CTL_R_IS_512 (WDT_CTL_IS_512 << WDT_CTL_R_IS_BIT)
#define WDT_CTL_R_IS_64 (WDT_CTL_IS_64 << WDT_CTL_R_IS_BIT)
/*-----------*/

/*-----------*/
#define WDT_CTL_R_SSEL_BIT ((uint16_t) 2U)

#define WDT_CTL_SSEL_MASK ((uint16_t) 0x01U)
#define WDT_CTL_SSEL_SMCLK ((uint16_t) 0x00U)
#define WDT_CTL_SSEL_ACLK ((uint16_t) 0x01U)

#define WDT_CTL_R_SSEL_MASK (WDT_CTL_SSEL_MASK<< WDT_CTL_R_SSEL_BIT)
#define WDT_CTL_R_SSEL_SMCLK (WDT_CTL_SSEL_SMCLK << WDT_CTL_R_SSEL_BIT)
#define WDT_CTL_R_SSEL_ACLK (WDT_CTL_SSEL_ACLK << WDT_CTL_R_SSEL_BIT)
/*-----------*/

/*-----------*/
#define WDT_CTL_R_CNTCL_BIT ((uint16_t) 3U)

#define WDT_CTL_CNTCL_MASK ((uint16_t) 0x01U)
#define WDT_CTL_CNTCL_NOACTION ((uint16_t) 0x00U)
#define WDT_CTL_CNTCL_CLEAR ((uint16_t) 0x01U)

#define WDT_CTL_R_CNTCL_MASK (WDT_CTL_CNTCL_MASK<< WDT_CTL_R_CNTCL_BIT)
#define WDT_CTL_R_CNTCL_NOACTION (WDT_CTL_CNTCL_NOACTION << WDT_CTL_R_CNTCL_BIT)
#define WDT_CTL_R_CNTCL_CLEAR (WDT_CTL_CNTCL_CLEAR << WDT_CTL_R_CNTCL_BIT)
/*-----------*/

/*-----------*/
#define WDT_CTL_R_TMSEL_BIT ((uint16_t) 4U)

#define WDT_CTL_TMSEL_MASK ((uint16_t) 0x01U)
#define WDT_CTL_TMSEL_WDT ((uint16_t) 0x00U)
#define WDT_CTL_TMSEL_INTERVAL ((uint16_t) 0x01U)

#define WDT_CTL_R_TMSEL_MASK (WDT_CTL_TMSEL_MASK<< WDT_CTL_R_TMSEL_BIT)
#define WDT_CTL_R_TMSEL_WDT (WDT_CTL_TMSEL_WDT << WDT_CTL_R_TMSEL_BIT)
#define WDT_CTL_R_TMSEL_INTERVAL (WDT_CTL_TMSEL_INTERVAL << WDT_CTL_R_TMSEL_BIT)
/*-----------*/

/*-----------*/
#define WDT_CTL_R_HOLD_BIT ((uint16_t) 7U)

#define WDT_CTL_HOLD_MASK ((uint16_t) 0x01U)
#define WDT_CTL_HOLD_RUN ((uint16_t) 0x00U)
#define WDT_CTL_HOLD_STOP ((uint16_t) 0x01U)

#define WDT_CTL_R_HOLD_MASK (WDT_CTL_HOLD_MASK<< WDT_CTL_R_HOLD_BIT)
#define WDT_CTL_R_HOLD_RUN (WDT_CTL_HOLD_RUN << WDT_CTL_R_HOLD_BIT)
#define WDT_CTL_R_HOLD_STOP (WDT_CTL_HOLD_STOP << WDT_CTL_R_HOLD_BIT)
/*-----------*/

/*-----------*/
#define WDT_CTL_R_PW_BIT ((uint16_t) 8U)

#define WDT_CTL_PW_MASK ((uint16_t) 0xFFU)
#define WDT_CTL_PW_READ ((uint16_t) 0x69U)
#define WDT_CTL_PW_WRITE ((uint16_t) 0x5AU)

#define WDT_CTL_R_PW_MASK (WDT_CTL_PW_MASK<< WDT_CTL_R_PW_BIT)
#define WDT_CTL_R_PW_READ (WDT_CTL_PW_READ << WDT_CTL_R_PW_BIT)
#define WDT_CTL_R_PW_WRITE (WDT_CTL_PW_WRITE << WDT_CTL_R_PW_BIT)
/*-----------*/

#endif /* DRIVERLIB_WDT_PERIPHERAL_REGISTERDEFINES_HEADER_WDT_REGISTERDEFINES_CTL_H_ */
