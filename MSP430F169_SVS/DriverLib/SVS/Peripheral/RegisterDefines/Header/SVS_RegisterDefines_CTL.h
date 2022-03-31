/**
 *
 * @file SVS_RegisterDefines_CTL.h
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

#ifndef DRIVERLIB_SVS_PERIPHERAL_REGISTERDEFINES_HEADER_SVS_REGISTERDEFINES_CTL_H_
#define DRIVERLIB_SVS_PERIPHERAL_REGISTERDEFINES_HEADER_SVS_REGISTERDEFINES_CTL_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

/******************************************************************************************
 ************************************ 1 SVSCTL *********************************************
 ******************************************************************************************/
/*-----------*/
#define SVS_CTL_R_FG_BIT ((uint16_t) 0U)

#define SVS_CTL_FG_MASK ((uint16_t) 0x01U)
#define SVS_CTL_FG_NOOCCUR ((uint16_t) 0x00U)
#define SVS_CTL_FG_OCCUR ((uint16_t) 0x01U)

#define SVS_CTL_R_FG_MASK (SVS_CTL_FG_MASK<< SVS_CTL_R_FG_BIT)
#define SVS_CTL_R_FG_NOOCCUR (SVS_CTL_FG_NOOCCUR << SVS_CTL_R_FG_BIT)
#define SVS_CTL_R_FG_OCCUR (SVS_CTL_FG_OCCUR << SVS_CTL_R_FG_BIT)
/*-----------*/

/*-----------*/
#define SVS_CTL_R_OP_BIT ((uint16_t) 1U)

#define SVS_CTL_OP_MASK ((uint16_t) 0x01U)
#define SVS_CTL_OP_LOW ((uint16_t) 0x00U)
#define SVS_CTL_OP_HIGH ((uint16_t) 0x01U)

#define SVS_CTL_R_OP_MASK (SVS_CTL_OP_MASK<< SVS_CTL_R_OP_BIT)
#define SVS_CTL_R_OP_LOW (SVS_CTL_OP_LOW << SVS_CTL_R_OP_BIT)
#define SVS_CTL_R_OP_HIGH (SVS_CTL_OP_HIGH << SVS_CTL_R_OP_BIT)
/*-----------*/

/*-----------*/
#define SVS_CTL_R_ON_BIT ((uint16_t) 2U)

#define SVS_CTL_ON_MASK ((uint16_t) 0x01U)
#define SVS_CTL_ON_OFF ((uint16_t) 0x00U)
#define SVS_CTL_ON_ON ((uint16_t) 0x01U)

#define SVS_CTL_R_ON_MASK (SVS_CTL_ON_MASK<< SVS_CTL_R_ON_BIT)
#define SVS_CTL_R_ON_OFF (SVS_CTL_ON_OFF << SVS_CTL_R_ON_BIT)
#define SVS_CTL_R_ON_ON (SVS_CTL_ON_ON << SVS_CTL_R_ON_BIT)
/*-----------*/

/*-----------*/
#define SVS_CTL_R_PORON_BIT ((uint16_t) 3U)

#define SVS_CTL_PORON_MASK ((uint16_t) 0x01U)
#define SVS_CTL_PORON_NOTHING ((uint16_t) 0x00U)
#define SVS_CTL_PORON_RESET ((uint16_t) 0x01U)

#define SVS_CTL_R_PORON_MASK (SVS_CTL_PORON_MASK<< SVS_CTL_R_PORON_BIT)
#define SVS_CTL_R_PORON_NOTHING (SVS_CTL_PORON_NOTHING << SVS_CTL_R_PORON_BIT)
#define SVS_CTL_R_PORON_RESET (SVS_CTL_PORON_RESET << SVS_CTL_R_PORON_BIT)
/*-----------*/

/*-----------*/
#define SVS_CTL_R_VLD_BIT ((uint16_t) 4U)

#define SVS_CTL_VLD_MASK ((uint16_t) 0x0FU)
#define SVS_CTL_VLD_OFF ((uint16_t) 0x00U)
#define SVS_CTL_VLD_1_9V ((uint16_t) 0x01U)
#define SVS_CTL_VLD_2_1V ((uint16_t) 0x02U)
#define SVS_CTL_VLD_2_2V ((uint16_t) 0x03U)
#define SVS_CTL_VLD_2_3V ((uint16_t) 0x04U)
#define SVS_CTL_VLD_2_4V ((uint16_t) 0x05U)
#define SVS_CTL_VLD_2_5V ((uint16_t) 0x06U)
#define SVS_CTL_VLD_2_65V ((uint16_t) 0x07U)
#define SVS_CTL_VLD_2_8V ((uint16_t) 0x08U)
#define SVS_CTL_VLD_2_9V ((uint16_t) 0x09U)
#define SVS_CTL_VLD_3_05V ((uint16_t) 0x0AU)
#define SVS_CTL_VLD_3_2V ((uint16_t) 0x0BU)
#define SVS_CTL_VLD_3_35V ((uint16_t) 0x0CU)
#define SVS_CTL_VLD_3_5V ((uint16_t) 0x0DU)
#define SVS_CTL_VLD_3_7V ((uint16_t) 0x0EU)
#define SVS_CTL_VLD_1_2V_EXT ((uint16_t) 0x0FU)

#define SVS_CTL_R_VLD_MASK (SVS_CTL_VLD_MASK<< SVS_CTL_R_VLD_BIT)
#define SVS_CTL_R_VLD_OFF (SVS_CTL_VLD_OFF << SVS_CTL_R_VLD_BIT)
#define SVS_CTL_R_VLD_1_9V (SVS_CTL_VLD_1_9V << SVS_CTL_R_VLD_BIT)
#define SVS_CTL_R_VLD_2_1V (SVS_CTL_VLD_2_1V << SVS_CTL_R_VLD_BIT)
#define SVS_CTL_R_VLD_2_2V (SVS_CTL_VLD_2_2V << SVS_CTL_R_VLD_BIT)
#define SVS_CTL_R_VLD_2_3V (SVS_CTL_VLD_2_3V << SVS_CTL_R_VLD_BIT)
#define SVS_CTL_R_VLD_2_4V (SVS_CTL_VLD_2_4V << SVS_CTL_R_VLD_BIT)
#define SVS_CTL_R_VLD_2_5V (SVS_CTL_VLD_2_5V << SVS_CTL_R_VLD_BIT)
#define SVS_CTL_R_VLD_2_65V (SVS_CTL_VLD_2_65V << SVS_CTL_R_VLD_BIT)
#define SVS_CTL_R_VLD_2_8V (SVS_CTL_VLD_2_8V << SVS_CTL_R_VLD_BIT)
#define SVS_CTL_R_VLD_2_9V (SVS_CTL_VLD_2_9V << SVS_CTL_R_VLD_BIT)
#define SVS_CTL_R_VLD_3_05V (SVS_CTL_VLD_3_05V << SVS_CTL_R_VLD_BIT)
#define SVS_CTL_R_VLD_3_2V (SVS_CTL_VLD_3_2V << SVS_CTL_R_VLD_BIT)
#define SVS_CTL_R_VLD_3_35V (SVS_CTL_VLD_3_35V << SVS_CTL_R_VLD_BIT)
#define SVS_CTL_R_VLD_3_5V (SVS_CTL_VLD_3_5V << SVS_CTL_R_VLD_BIT)
#define SVS_CTL_R_VLD_3_7V (SVS_CTL_VLD_3_7V << SVS_CTL_R_VLD_BIT)
#define SVS_CTL_R_VLD_1_2V_EXT (SVS_CTL_VLD_1_2V_EXT << SVS_CTL_R_VLD_BIT)
/*-----------*/

#endif /* DRIVERLIB_SVS_PERIPHERAL_REGISTERDEFINES_HEADER_SVS_REGISTERDEFINES_CTL_H_ */
