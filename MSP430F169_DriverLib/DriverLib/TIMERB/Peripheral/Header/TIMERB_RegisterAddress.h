/**
 *
 * @file TIMERB_RegisterAddress.h
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

#ifndef TIMERB_PERIPHERAL_HEADER_TIMERB_REGISTERADDRESS_H_
#define TIMERB_PERIPHERAL_HEADER_TIMERB_REGISTERADDRESS_H_

#define TIMERB_BASE (0x11EU)

#define TIMERB_CC0_BASE (0x182U)
#define TIMERB_CC1_BASE (0x184U)
#define TIMERB_CC2_BASE (0x186U)
#define TIMERB_CC3_BASE (0x188U)
#define TIMERB_CC4_BASE (0x18AU)
#define TIMERB_CC5_BASE (0x18CU)
#define TIMERB_CC6_BASE (0x18EU)

#define TIMERB_CC0_OFFSET (0x64U)
#define TIMERB_CC1_OFFSET (0x66U)
#define TIMERB_CC2_OFFSET (0x68U)
#define TIMERB_CC3_OFFSET (0x6AU)
#define TIMERB_CC4_OFFSET (0x6CU)
#define TIMERB_CC5_OFFSET (0x6EU)
#define TIMERB_CC6_OFFSET (0x70U)

#define TIMERB_IV_OFFSET (0x00U)
#define TIMERB_CTL_OFFSET (0x62U)
#define TIMERB_R_OFFSET (0x82U)

#define TIMERB_CC_CTL_OFFSET (0x00U)
#define TIMERB_CC_R_OFFSET (0x10U)

#endif /* TIMERB_PERIPHERAL_HEADER_TIMERB_REGISTERADDRESS_H_ */
