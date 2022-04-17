/**
 *
 * @file TIMERB_RegisterDefines_R.h
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

#ifndef DRIVERLIB_TIMERB_PERIPHERAL_REGISTERDEFINES_HEADER_TIMERB_REGISTERDEFINES_R_H_
#define DRIVERLIB_TIMERB_PERIPHERAL_REGISTERDEFINES_HEADER_TIMERB_REGISTERDEFINES_R_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

/******************************************************************************************
 ************************************ 2 R *********************************************
 ******************************************************************************************/
/*-----------*/
#define TIMERB_R_R_R_BIT ((uint16_t) 0U)

#define TIMERB_R_R_MASK ((uint16_t) 0xFFFFU)
#define TIMERB_R_R8_MASK ((uint16_t) 0xFFU)
#define TIMERB_R_R10_MASK ((uint16_t) 0x3FFU)
#define TIMERB_R_R12_MASK ((uint16_t) 0xFFFU)
#define TIMERB_R_R16_MASK ((uint16_t) 0xFFFFU)

#define TIMERB_R_R_R_MASK (TIMERB_R_R_MASK << TIMERB_R_R_R_BIT)
#define TIMERB_R_R_R8_MASK (TIMERB_R_R8_MASK << TIMERB_R_R_R_BIT)
#define TIMERB_R_R_R10_MASK (TIMERB_R_R10_MASK << TIMERB_R_R_R_BIT)
#define TIMERB_R_R_R12_MASK (TIMERB_R_R12_MASK << TIMERB_R_R_R_BIT)
#define TIMERB_R_R_R16_MASK (TIMERB_R_R16_MASK << TIMERB_R_R_R_BIT)
/*-----------*/





#endif /* DRIVERLIB_TIMERB_PERIPHERAL_REGISTERDEFINES_HEADER_TIMERB_REGISTERDEFINES_R_H_ */
