/**
 *
 * @file NMI_RegisterDefines_CTL.h
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

#ifndef DRIVERLIB_NMI_PERIPHERAL_REGISTERDEFINES_HEADER_NMI_REGISTERDEFINES_CTL_H_
#define DRIVERLIB_NMI_PERIPHERAL_REGISTERDEFINES_HEADER_NMI_REGISTERDEFINES_CTL_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

/******************************************************************************************
 ************************************ 3 NMICTL *********************************************
 ******************************************************************************************/
/*-----------*/
#define NMI_CTL_R_NMI_BIT ((uint16_t) 5U)

#define NMI_CTL_NMI_MASK ((uint16_t) 0x01U)
#define NMI_CTL_NMI_RESET ((uint16_t) 0x00U)
#define NMI_CTL_NMI_NMI ((uint16_t) 0x01U)

#define NMI_CTL_R_NMI_MASK (NMI_CTL_NMI_MASK<< NMI_CTL_R_NMI_BIT)
#define NMI_CTL_R_NMI_RESET (NMI_CTL_NMI_RESET << NMI_CTL_R_NMI_BIT)
#define NMI_CTL_R_NMI_NMI (NMI_CTL_NMI_NMI << NMI_CTL_R_NMI_BIT)
/*-----------*/

/*-----------*/
#define NMI_CTL_R_NMIES_BIT ((uint16_t) 6U)

#define NMI_CTL_NMIES_MASK ((uint16_t) 0x01U)
#define NMI_CTL_NMIES_RISING ((uint16_t) 0x00U)
#define NMI_CTL_NMIES_FALLING ((uint16_t) 0x01U)

#define NMI_CTL_R_NMIES_MASK (NMI_CTL_NMIES_MASK<< NMI_CTL_R_NMIES_BIT)
#define NMI_CTL_R_NMIES_RISING (NMI_CTL_NMIES_RISING << NMI_CTL_R_NMIES_BIT)
#define NMI_CTL_R_NMIES_FALLING (NMI_CTL_NMIES_FALLING << NMI_CTL_R_NMIES_BIT)
/*-----------*/

/*-----------*/
#define NMI_CTL_R_PW_BIT ((uint16_t) 8U)

#define NMI_CTL_PW_MASK ((uint16_t) 0xFFU)
#define NMI_CTL_PW_READ ((uint16_t) 0x69U)
#define NMI_CTL_PW_WRITE ((uint16_t) 0x5AU)

#define NMI_CTL_R_PW_MASK (NMI_CTL_PW_MASK<< NMI_CTL_R_PW_BIT)
#define NMI_CTL_R_PW_READ (NMI_CTL_PW_READ << NMI_CTL_R_PW_BIT)
#define NMI_CTL_R_PW_WRITE (NMI_CTL_PW_WRITE << NMI_CTL_R_PW_BIT)
/*-----------*/

#endif /* DRIVERLIB_NMI_PERIPHERAL_REGISTERDEFINES_HEADER_NMI_REGISTERDEFINES_CTL_H_ */
