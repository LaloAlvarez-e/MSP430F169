/**
 *
 * @file DMA_StructPeripheral.h
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

#ifndef DMA_PERIPHERAL_HEADER_DMA_STRUCTPERIPHERAL_H_
#define DMA_PERIPHERAL_HEADER_DMA_STRUCTPERIPHERAL_H_

#include "DriverLib/DMA/Peripheral/Header/DMA_StructRegister.h"

typedef volatile struct
{
    union
    {
        volatile unsigned short CTL;
        DMA_CH_CTL_t CTL_bits;
    };
    union
    {
        volatile unsigned short SA;
        DMA_CH_SA_t SA_bits;
    };
    union
    {
        volatile unsigned short DA;
        DMA_CH_DA_t DA_bits;
    };
    union
    {
        volatile unsigned short SZ;
        DMA_CH_SZ_t SZ_bits;
    };
}DMA_CH_t;

typedef volatile struct
{
    union
    {
        volatile unsigned short CTL0;
        DMA_CTL0_t CTL0_bits;
    };
    union
    {
        volatile unsigned short CTL1;
        DMA_CTL1_t CTL1_bits;
    };

    const unsigned char reserved1[186U];

    DMA_CH_t CH[3UL];
}DMA_t;

#endif /* DMA_PERIPHERAL_HEADER_DMA_STRUCTPERIPHERAL_H_ */
