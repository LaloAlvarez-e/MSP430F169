/**
 *
 * @file CLOCK_RegisterDefines_DCOCTL.h
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

#ifndef CLOCK_PERIPHERAL_REGISTERDEFINES_HEADER_CLOCK_REGISTERDEFINES_DCOCTL_H_
#define CLOCK_PERIPHERAL_REGISTERDEFINES_HEADER_CLOCK_REGISTERDEFINES_DCOCTL_H_

#include <stdint.h>

/******************************************************************************************
 ************************************ 3 DCOCTL *********************************************
 ******************************************************************************************/
/*-----------*/
#define CLOCK_DCOCTL_R_MOD_BIT ((uint8_t) 0U)
#define CLOCK_DCOCTL_MOD_MASK ((uint8_t) 0x1FU)
#define CLOCK_DCOCTL_R_MOD_MASK (CLOCK_DCOCTL_MOD_MASK<< CLOCK_DCOCTL_R_MOD_BIT)
/*-----------*/

/*-----------*/
#define CLOCK_DCOCTL_R_DCO_BIT ((uint8_t) 5U)

#define CLOCK_DCOCTL_DCO_MASK ((uint8_t) 0x07U)
#define CLOCK_DCOCTL_DCO_0 ((uint8_t) 0x00U)
#define CLOCK_DCOCTL_DCO_1 ((uint8_t) 0x01U)
#define CLOCK_DCOCTL_DCO_2 ((uint8_t) 0x02U)
#define CLOCK_DCOCTL_DCO_3 ((uint8_t) 0x03U)
#define CLOCK_DCOCTL_DCO_4 ((uint8_t) 0x04U)
#define CLOCK_DCOCTL_DCO_5 ((uint8_t) 0x05U)
#define CLOCK_DCOCTL_DCO_6 ((uint8_t) 0x06U)
#define CLOCK_DCOCTL_DCO_7 ((uint8_t) 0x07U)

#define CLOCK_DCOCTL_R_DCO_MASK (CLOCK_DCOCTL_DCO_MASK<< CLOCK_DCOCTL_R_DCO_BIT)
#define CLOCK_DCOCTL_R_DCO_0 (CLOCK_DCOCTL_DCO_0 << CLOCK_DCOCTL_R_DCO_BIT)
#define CLOCK_DCOCTL_R_DCO_1 (CLOCK_DCOCTL_DCO_1 << CLOCK_DCOCTL_R_DCO_BIT)
#define CLOCK_DCOCTL_R_DCO_2 (CLOCK_DCOCTL_DCO_2 << CLOCK_DCOCTL_R_DCO_BIT)
#define CLOCK_DCOCTL_R_DCO_3 (CLOCK_DCOCTL_DCO_3 << CLOCK_DCOCTL_R_DCO_BIT)
#define CLOCK_DCOCTL_R_DCO_4 (CLOCK_DCOCTL_DCO_4 << CLOCK_DCOCTL_R_DCO_BIT)
#define CLOCK_DCOCTL_R_DCO_5 (CLOCK_DCOCTL_DCO_5 << CLOCK_DCOCTL_R_DCO_BIT)
#define CLOCK_DCOCTL_R_DCO_6 (CLOCK_DCOCTL_DCO_6 << CLOCK_DCOCTL_R_DCO_BIT)
#define CLOCK_DCOCTL_R_DCO_7 (CLOCK_DCOCTL_DCO_7 << CLOCK_DCOCTL_R_DCO_BIT)
/*-----------*/


#endif /* CLOCK_PERIPHERAL_REGISTERDEFINES_HEADER_CLOCK_REGISTERDEFINES_DCOCTL_H_ */
