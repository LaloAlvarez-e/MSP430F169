/**
 *
 * @file DAC12_RegisterAddress.h
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

#ifndef DAC12_PERIPHERAL_HEADER_DAC12_REGISTERADDRESS_H_
#define DAC12_PERIPHERAL_HEADER_DAC12_REGISTERADDRESS_H_

#define DAC12_BASE (0x1C0U)

#define DAC12_CH0_BASE (0x1C0U)
#define DAC12_CH1_BASE (0x1C2U)

#define DAC12_CH0_OFFSET (DAC12_CH0_BASE - DAC12_BASE)
#define DAC12_CH1_OFFSET (DAC12_CH1_BASE - DAC12_BASE)

#define DAC12_CH_CTL_OFFSET (0x00U)
#define DAC12_CH_DAT_OFFSET (0x08U)

#endif /* DAC12_PERIPHERAL_HEADER_DAC12_REGISTERADDRESS_H_ */
