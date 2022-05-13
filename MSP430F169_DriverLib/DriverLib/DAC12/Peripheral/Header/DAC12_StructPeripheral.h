/**
 *
 * @file DAC12_StructPeripheral.h
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

#ifndef DAC12_PERIPHERAL_HEADER_DAC12_STRUCTPERIPHERAL_H_
#define DAC12_PERIPHERAL_HEADER_DAC12_STRUCTPERIPHERAL_H_

#include "DriverLib/DAC12/Peripheral/Header/DAC12_StructRegister.h"

typedef volatile struct
{
    union
    {
        volatile unsigned char CH_CTL[2U];
        DAC12_CH_CTL_t CH_CTL_bits[2U];
    };
    const unsigned char reserved1[4U];
    union
    {
        volatile unsigned short CH_DAT[2U];
        DAC12_CH_DAT_t CH_DAT_bits[2U];
    };
}DAC12_t;


typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        DAC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[6U];
    union
    {
        volatile unsigned short DAT;
        DAC12_CH_DAT_t DAT_bits;
    };
}DAC12_CH_t;

#endif /* DAC12_PERIPHERAL_HEADER_DAC12_STRUCTPERIPHERAL_H_ */
