/**
 *
 * @file ADC12_RegisterAddress.h
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

#ifndef ADC12_PERIPHERAL_HEADER_ADC12_REGISTERADDRESS_H_
#define ADC12_PERIPHERAL_HEADER_ADC12_REGISTERADDRESS_H_

#define ADC12_BASE (0x80U)

#define ADC12_CH0_BASE (0x80U)
#define ADC12_CH1_BASE (0x81U)
#define ADC12_CH2_BASE (0x82U)
#define ADC12_CH3_BASE (0x83U)
#define ADC12_CH4_BASE (0x84U)
#define ADC12_CH5_BASE (0x85U)
#define ADC12_CH6_BASE (0x86U)
#define ADC12_CH7_BASE (0x87U)
#define ADC12_CH8_BASE (0x88U)
#define ADC12_CH9_BASE (0x89U)
#define ADC12_CH10_BASE (0x8AU)
#define ADC12_CH11_BASE (0x8BU)
#define ADC12_CH12_BASE (0x8CU)
#define ADC12_CH13_BASE (0x8DU)
#define ADC12_CH14_BASE (0x8EU)
#define ADC12_CH15_BASE (0x8FU)

#define ADC12_CH0_OFFSET (ADC12_CH0_BASE - ADC12_BASE)
#define ADC12_CH1_OFFSET (ADC12_CH1_BASE - ADC12_BASE)
#define ADC12_CH2_OFFSET (ADC12_CH2_BASE - ADC12_BASE)
#define ADC12_CH3_OFFSET (ADC12_CH3_BASE - ADC12_BASE)
#define ADC12_CH4_OFFSET (ADC12_CH4_BASE - ADC12_BASE)
#define ADC12_CH5_OFFSET (ADC12_CH5_BASE - ADC12_BASE)
#define ADC12_CH6_OFFSET (ADC12_CH6_BASE - ADC12_BASE)
#define ADC12_CH7_OFFSET (ADC12_CH7_BASE - ADC12_BASE)
#define ADC12_CH8_OFFSET (ADC12_CH8_BASE - ADC12_BASE)
#define ADC12_CH9_OFFSET (ADC12_CH9_BASE - ADC12_BASE)
#define ADC12_CH10_OFFSET (ADC12_CH10_BASE - ADC12_BASE)
#define ADC12_CH11_OFFSET (ADC12_CH11_BASE - ADC12_BASE)
#define ADC12_CH12_OFFSET (ADC12_CH12_BASE - ADC12_BASE)
#define ADC12_CH13_OFFSET (ADC12_CH13_BASE - ADC12_BASE)
#define ADC12_CH14_OFFSET (ADC12_CH14_BASE - ADC12_BASE)
#define ADC12_CH15_OFFSET (ADC12_CH15_BASE - ADC12_BASE)

#define ADC12_CTL0_OFFSET (0x120U)
#define ADC12_CTL1_OFFSET (0x122U)
#define ADC12_IFG_OFFSET (0x124U)
#define ADC12_IE_OFFSET (0x126U)
#define ADC12_IV_OFFSET (0x128U)

#define ADC12_CH_CTL_OFFSET (0x00U)
#define ADC12_CH_MEM_OFFSET (0x192U)

#endif /* ADC12_PERIPHERAL_HEADER_ADC12_REGISTERADDRESS_H_ */
