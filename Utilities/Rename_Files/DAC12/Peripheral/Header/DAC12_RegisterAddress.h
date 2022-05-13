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

#define DAC12_BASE (0x80U)

#define DAC12_CH0_BASE (0x80U)
#define DAC12_CH1_BASE (0x81U)
#define DAC12_CH2_BASE (0x82U)
#define DAC12_CH3_BASE (0x83U)
#define DAC12_CH4_BASE (0x84U)
#define DAC12_CH5_BASE (0x85U)
#define DAC12_CH6_BASE (0x86U)
#define DAC12_CH7_BASE (0x87U)
#define DAC12_CH8_BASE (0x88U)
#define DAC12_CH9_BASE (0x89U)
#define DAC12_CH10_BASE (0x8AU)
#define DAC12_CH11_BASE (0x8BU)
#define DAC12_CH12_BASE (0x8CU)
#define DAC12_CH13_BASE (0x8DU)
#define DAC12_CH14_BASE (0x8EU)
#define DAC12_CH15_BASE (0x8FU)

#define DAC12_CH0_OFFSET (DAC12_CH0_BASE - DAC12_BASE)
#define DAC12_CH1_OFFSET (DAC12_CH1_BASE - DAC12_BASE)
#define DAC12_CH2_OFFSET (DAC12_CH2_BASE - DAC12_BASE)
#define DAC12_CH3_OFFSET (DAC12_CH3_BASE - DAC12_BASE)
#define DAC12_CH4_OFFSET (DAC12_CH4_BASE - DAC12_BASE)
#define DAC12_CH5_OFFSET (DAC12_CH5_BASE - DAC12_BASE)
#define DAC12_CH6_OFFSET (DAC12_CH6_BASE - DAC12_BASE)
#define DAC12_CH7_OFFSET (DAC12_CH7_BASE - DAC12_BASE)
#define DAC12_CH8_OFFSET (DAC12_CH8_BASE - DAC12_BASE)
#define DAC12_CH9_OFFSET (DAC12_CH9_BASE - DAC12_BASE)
#define DAC12_CH10_OFFSET (DAC12_CH10_BASE - DAC12_BASE)
#define DAC12_CH11_OFFSET (DAC12_CH11_BASE - DAC12_BASE)
#define DAC12_CH12_OFFSET (DAC12_CH12_BASE - DAC12_BASE)
#define DAC12_CH13_OFFSET (DAC12_CH13_BASE - DAC12_BASE)
#define DAC12_CH14_OFFSET (DAC12_CH14_BASE - DAC12_BASE)
#define DAC12_CH15_OFFSET (DAC12_CH15_BASE - DAC12_BASE)

#define DAC12_CTL0_OFFSET (0x120U)
#define DAC12_CTL1_OFFSET (0x122U)
#define DAC12_IFG_OFFSET (0x124U)
#define DAC12_IE_OFFSET (0x126U)
#define DAC12_IV_OFFSET (0x128U)

#define DAC12_CH_CTL_OFFSET (0x00U)
#define DAC12_CH_MEM_OFFSET (0xC0U)

#endif /* DAC12_PERIPHERAL_HEADER_DAC12_REGISTERADDRESS_H_ */
