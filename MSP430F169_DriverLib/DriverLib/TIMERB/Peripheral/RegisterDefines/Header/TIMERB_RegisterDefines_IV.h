/**
 *
 * @file TIMERB_RegisterDefines_IV.h
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
 * @verbatim 9 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 9 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_TIMERB_PERIPHERAL_REGISTERDEFINES_HEADER_TIMERB_REGISTERDEFINES_IV_H_
#define DRIVERLIB_TIMERB_PERIPHERAL_REGISTERDEFINES_HEADER_TIMERB_REGISTERDEFINES_IV_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

/******************************************************************************************
 ************************************ 5 IV *********************************************
 ******************************************************************************************/

/*-----------*/
#define TIMERB_IV_R_IV_BIT ((uint16_t) 0U)

#define TIMERB_IV_IV_MASK ((uint16_t) 0xFFFFU)
#define TIMERB_IV_IV_CC1 ((uint16_t) 0x02U)
#define TIMERB_IV_IV_CC2 ((uint16_t) 0x04U)
#define TIMERB_IV_IV_CC3 ((uint16_t) 0x06U)
#define TIMERB_IV_IV_CC4 ((uint16_t) 0x08U)
#define TIMERB_IV_IV_CC5 ((uint16_t) 0x0AU)
#define TIMERB_IV_IV_CC6 ((uint16_t) 0x0CU)
#define TIMERB_IV_IV_OV ((uint16_t) 0x0EU)

#define TIMERB_IV_R_IV_MASK (TIMERB_IV_IV_MASK << TIMERB_IV_R_IV_BIT)
#define TIMERB_IV_R_IV_CC1 (TIMERB_IV_IV_CC1 << TIMERB_IV_R_IV_BIT)
#define TIMERB_IV_R_IV_CC2 (TIMERB_IV_IV_CC2 << TIMERB_IV_R_IV_BIT)
#define TIMERB_IV_R_IV_CC3 (TIMERB_IV_IV_CC3 << TIMERB_IV_R_IV_BIT)
#define TIMERB_IV_R_IV_CC4 (TIMERB_IV_IV_CC4 << TIMERB_IV_R_IV_BIT)
#define TIMERB_IV_R_IV_CC5 (TIMERB_IV_IV_CC5 << TIMERB_IV_R_IV_BIT)
#define TIMERB_IV_R_IV_CC6 (TIMERB_IV_IV_CC6 << TIMERB_IV_R_IV_BIT)
#define TIMERB_IV_R_IV_OV (TIMERB_IV_IV_OV << TIMERB_IV_R_IV_BIT)
/*-----------*/


#endif /* DRIVERLIB_TIMERB_PERIPHERAL_REGISTERDEFINES_HEADER_TIMERB_REGISTERDEFINES_IV_H_ */
