/**
 *
 * @file DMA_RegisterAddress.h
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

#ifndef DMA_PERIPHERAL_HEADER_DMA_REGISTERADDRESS_H_
#define DMA_PERIPHERAL_HEADER_DMA_REGISTERADDRESS_H_

#define DMA_BASE (0x122U)

#define DMA_CH0_BASE (0x1E0U)
#define DMA_CH1_BASE (0x1E8U)
#define DMA_CH2_BASE (0x1F0U)

#define DMA_CH0_OFFSET (0xBEU)
#define DMA_CH1_OFFSET (0xC6U)
#define DMA_CH2_OFFSET (0xCEU)

#define DMA_CTL0_OFFSET (0x00U)
#define DMA_CTL1_OFFSET (0x02U)

#define DMA_CH_CTL_OFFSET (0x00U)
#define DMA_CH_SA_OFFSET (0x02U)
#define DMA_CH_DA_OFFSET (0x04U)
#define DMA_CH_SZ_OFFSET (0x06U)

#endif /* DMA_PERIPHERAL_HEADER_DMA_REGISTERADDRESS_H_ */
