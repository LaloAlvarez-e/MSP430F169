/**
 *
 * @file TIMERA_StructPeripheral.h
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

#ifndef TIMERA_PERIPHERAL_HEADER_TIMERA_STRUCTPERIPHERAL_H_
#define TIMERA_PERIPHERAL_HEADER_TIMERA_STRUCTPERIPHERAL_H_

#include "DriverLib/TIMERA/Peripheral/Header/TIMERA_StructRegister.h"

typedef volatile struct
{
    union
    {
        volatile const unsigned short IV;
        TIMERA_IV_t IV_bits;
    };
    const unsigned char reserved1[48U];
    union
    {
        volatile unsigned short CTL;
        TIMERA_CTL_t CTL_bits;
    };
    union
    {
        volatile unsigned short CC_CTL[3U];
        TIMERA_CC_CTL_t CC_CTL_bits[3UL];
    };
    const unsigned char reserved2[8U];
    union
    {
        volatile unsigned short R;
        TIMERA_R_t R_bits;
    };
    union
    {
        volatile unsigned short CC_R[3U];
        TIMERA_CC_R_t CC_R_bits[3UL];
    };
}TIMERA_t;


typedef volatile struct
{
    union
    {
        volatile unsigned short CTL;
        TIMERA_CC_CTL_t CTL_bits;
    };
    const unsigned char reserved2[14U];
    union
    {
        volatile unsigned short R;
        TIMERA_CC_R_t R_bits;
    };
}TIMERA_CC_t;


#endif /* TIMERA_PERIPHERAL_HEADER_TIMERA_STRUCTPERIPHERAL_H_ */
