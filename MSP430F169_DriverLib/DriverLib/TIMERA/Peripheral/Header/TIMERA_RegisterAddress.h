/**
 *
 * @file TIMERA_RegisterAddress.h
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
 * @verbatim 5 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 5 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef TIMERA_PERIPHERAL_HEADER_TIMERA_REGISTERADDRESS_H_
#define TIMERA_PERIPHERAL_HEADER_TIMERA_REGISTERADDRESS_H_

#define TIMERA_BASE (0x12EU)

#define TIMERA_CC0_BASE (0x162U)
#define TIMERA_CC1_BASE (0x164U)
#define TIMERA_CC2_BASE (0x166U)

#define TIMERA_CC0_OFFSET (TIMERA_CC0_BASE - TIMERA_BASE)
#define TIMERA_CC1_OFFSET (TIMERA_CC1_BASE - TIMERA_BASE)
#define TIMERA_CC2_OFFSET (TIMERA_CC2_BASE - TIMERA_BASE)

#define TIMERA_IV_OFFSET (0x00U)
#define TIMERA_CTL_OFFSET (0x32U)
#define TIMERA_R_OFFSET (0x42U)

#define TIMERA_CC_CTL_OFFSET (0x00U)
#define TIMERA_CC_R_OFFSET (0x10U)

#endif /* TIMERA_PERIPHERAL_HEADER_TIMERA_REGISTERADDRESS_H_ */
