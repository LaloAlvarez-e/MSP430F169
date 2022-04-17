/**
 *
 * @file TIMERB_RegisterDefines_CTL.h
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

#ifndef DRIVERLIB_TIMERB_PERIPHERAL_REGISTERDEFINES_HEADER_TIMERB_REGISTERDEFINES_CTL_H_
#define DRIVERLIB_TIMERB_PERIPHERAL_REGISTERDEFINES_HEADER_TIMERB_REGISTERDEFINES_CTL_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

/******************************************************************************************
 ************************************ 1 CTL *********************************************
 ******************************************************************************************/
/*-----------*/
#define TIMERB_CTL_R_IFG_BIT ((uint16_t) 0U)

#define TIMERB_CTL_IFG_MASK ((uint16_t) 0x01U)
#define TIMERB_CTL_IFG_NOOCCUR ((uint16_t) 0x00U)
#define TIMERB_CTL_IFG_OCCUR ((uint16_t) 0x01U)

#define TIMERB_CTL_R_IFG_MASK (TIMERB_CTL_IFG_MASK << TIMERB_CTL_R_IFG_BIT)
#define TIMERB_CTL_R_IFG_NOOCCUR (TIMERB_CTL_IFG_NOOCCUR << TIMERB_CTL_R_IFG_BIT)
#define TIMERB_CTL_R_IFG_OCCUR (TIMERB_CTL_IFG_OCCUR << TIMERB_CTL_R_IFG_BIT)
/*-----------*/

/*-----------*/
#define TIMERB_CTL_R_IE_BIT ((uint16_t) 1U)

#define TIMERB_CTL_IE_MASK ((uint16_t) 0x01U)
#define TIMERB_CTL_IE_DIS ((uint16_t) 0x00U)
#define TIMERB_CTL_IE_ENA ((uint16_t) 0x01U)

#define TIMERB_CTL_R_IE_MASK (TIMERB_CTL_IE_MASK << TIMERB_CTL_R_IE_BIT)
#define TIMERB_CTL_R_IE_DIS (TIMERB_CTL_IE_DIS << TIMERB_CTL_R_IE_BIT)
#define TIMERB_CTL_R_IE_ENA (TIMERB_CTL_IE_ENA << TIMERB_CTL_R_IE_BIT)
/*-----------*/

/*-----------*/
#define TIMERB_CTL_R_CLR_BIT ((uint16_t) 2U)

#define TIMERB_CTL_CLR_MASK ((uint16_t) 0x01U)
#define TIMERB_CTL_CLR_NA ((uint16_t) 0x00U)
#define TIMERB_CTL_CLR_CLEAR ((uint16_t) 0x01U)

#define TIMERB_CTL_R_CLR_MASK (TIMERB_CTL_CLR_MASK << TIMERB_CTL_R_CLR_BIT)
#define TIMERB_CTL_R_CLR_NA (TIMERB_CTL_CLR_NA << TIMERB_CTL_R_CLR_BIT)
#define TIMERB_CTL_R_CLR_CLEAR (TIMERB_CTL_CLR_CLEAR << TIMERB_CTL_R_CLR_BIT)
/*-----------*/

/*-----------*/
#define TIMERB_CTL_R_MC_BIT ((uint16_t) 4U)

#define TIMERB_CTL_MC_MASK ((uint16_t) 0x03U)
#define TIMERB_CTL_MC_STOP ((uint16_t) 0x00U)
#define TIMERB_CTL_MC_UP ((uint16_t) 0x01U)
#define TIMERB_CTL_MC_CONTINUOS ((uint16_t) 0x02U)
#define TIMERB_CTL_MC_UP_DOWN ((uint16_t) 0x03U)

#define TIMERB_CTL_R_MC_MASK (TIMERB_CTL_MC_MASK << TIMERB_CTL_R_MC_BIT)
#define TIMERB_CTL_R_MC_STOP (TIMERB_CTL_MC_STOP << TIMERB_CTL_R_MC_BIT)
#define TIMERB_CTL_R_MC_UP (TIMERB_CTL_MC_UP << TIMERB_CTL_R_MC_BIT)
#define TIMERB_CTL_R_MC_CONTINUOS (TIMERB_CTL_MC_CONTINUOS << TIMERB_CTL_R_MC_BIT)
#define TIMERB_CTL_R_MC_UP_DOWN (TIMERB_CTL_MC_UP_DOWN << TIMERB_CTL_R_MC_BIT)
/*-----------*/

/*-----------*/
#define TIMERB_CTL_R_ID_BIT ((uint16_t) 6U)

#define TIMERB_CTL_ID_MASK ((uint16_t) 0x03U)
#define TIMERB_CTL_ID_1 ((uint16_t) 0x00U)
#define TIMERB_CTL_ID_2 ((uint16_t) 0x01U)
#define TIMERB_CTL_ID_4 ((uint16_t) 0x02U)
#define TIMERB_CTL_ID_8 ((uint16_t) 0x03U)

#define TIMERB_CTL_R_ID_MASK (TIMERB_CTL_ID_MASK << TIMERB_CTL_R_ID_BIT)
#define TIMERB_CTL_R_ID_1 (TIMERB_CTL_ID_1 << TIMERB_CTL_R_ID_BIT)
#define TIMERB_CTL_R_ID_2 (TIMERB_CTL_ID_2 << TIMERB_CTL_R_ID_BIT)
#define TIMERB_CTL_R_ID_4 (TIMERB_CTL_ID_4 << TIMERB_CTL_R_ID_BIT)
#define TIMERB_CTL_R_ID_8 (TIMERB_CTL_ID_8 << TIMERB_CTL_R_ID_BIT)
/*-----------*/

/*-----------*/
#define TIMERB_CTL_R_SSEL_BIT ((uint16_t) 8U)

#define TIMERB_CTL_SSEL_MASK ((uint16_t) 0x03U)
#define TIMERB_CTL_SSEL_TBCLK ((uint16_t) 0x00U)
#define TIMERB_CTL_SSEL_ACLK ((uint16_t) 0x01U)
#define TIMERB_CTL_SSEL_SMCLK ((uint16_t) 0x02U)
#define TIMERB_CTL_SSEL_nTBCLK ((uint16_t) 0x03U)

#define TIMERB_CTL_R_SSEL_MASK (TIMERB_CTL_SSEL_MASK << TIMERB_CTL_R_SSEL_BIT)
#define TIMERB_CTL_R_SSEL_TBCLK (TIMERB_CTL_SSEL_TBCLK << TIMERB_CTL_R_SSEL_BIT)
#define TIMERB_CTL_R_SSEL_ACLK (TIMERB_CTL_SSEL_ACLK << TIMERB_CTL_R_SSEL_BIT)
#define TIMERB_CTL_R_SSEL_SMCLK (TIMERB_CTL_SSEL_SMCLK << TIMERB_CTL_R_SSEL_BIT)
#define TIMERB_CTL_R_SSEL_nTBCLK (TIMERB_CTL_SSEL_nTBCLK << TIMERB_CTL_R_SSEL_BIT)
/*-----------*/

/*-----------*/
#define TIMERB_CTL_R_CNTL_BIT ((uint16_t) 11U)

#define TIMERB_CTL_CNTL_MASK ((uint16_t) 0x03U)
#define TIMERB_CTL_CNTL_16BITS ((uint16_t) 0x00U)
#define TIMERB_CTL_CNTL_12BITS ((uint16_t) 0x01U)
#define TIMERB_CTL_CNTL_10BITS ((uint16_t) 0x02U)
#define TIMERB_CTL_CNTL_8BITS ((uint16_t) 0x03U)

#define TIMERB_CTL_R_CNTL_MASK (TIMERB_CTL_CNTL_MASK << TIMERB_CTL_R_CNTL_BIT)
#define TIMERB_CTL_R_CNTL_16BITS (TIMERB_CTL_CNTL_16BITS << TIMERB_CTL_R_CNTL_BIT)
#define TIMERB_CTL_R_CNTL_12BITS (TIMERB_CTL_CNTL_12BITS << TIMERB_CTL_R_CNTL_BIT)
#define TIMERB_CTL_R_CNTL_10BITS (TIMERB_CTL_CNTL_10BITS << TIMERB_CTL_R_CNTL_BIT)
#define TIMERB_CTL_R_CNTL_8BITS (TIMERB_CTL_CNTL_8BITS << TIMERB_CTL_R_CNTL_BIT)
/*-----------*/

/*-----------*/
#define TIMERB_CTL_R_CLGRP_BIT ((uint16_t) 13U)

#define TIMERB_CTL_CLGRP_MASK ((uint16_t) 0x03U)
#define TIMERB_CTL_CLGRP_INDEPENDENT ((uint16_t) 0x00U)
#define TIMERB_CTL_CLGRP_PAIRS ((uint16_t) 0x01U)
#define TIMERB_CTL_CLGRP_THIRDS ((uint16_t) 0x02U)
#define TIMERB_CTL_CLGRP_ALL ((uint16_t) 0x03U)

#define TIMERB_CTL_R_CLGRP_MASK (TIMERB_CTL_CLGRP_MASK << TIMERB_CTL_R_CLGRP_BIT)
#define TIMERB_CTL_R_CLGRP_INDEPENDENT (TIMERB_CTL_CLGRP_INDEPENDENT << TIMERB_CTL_R_CLGRP_BIT)
#define TIMERB_CTL_R_CLGRP_PAIRS (TIMERB_CTL_CLGRP_PAIRS << TIMERB_CTL_R_CLGRP_BIT)
#define TIMERB_CTL_R_CLGRP_THIRDS (TIMERB_CTL_CLGRP_THIRDS << TIMERB_CTL_R_CLGRP_BIT)
#define TIMERB_CTL_R_CLGRP_ALL (TIMERB_CTL_CLGRP_ALL << TIMERB_CTL_R_CLGRP_BIT)
/*-----------*/


#endif /* DRIVERLIB_TIMERB_PERIPHERAL_REGISTERDEFINES_HEADER_TIMERB_REGISTERDEFINES_CTL_H_ */
