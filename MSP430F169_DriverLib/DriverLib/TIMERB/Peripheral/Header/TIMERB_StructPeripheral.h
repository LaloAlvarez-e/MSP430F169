/**
 *
 * @file TIMERB_StructPeripheral.h
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

#ifndef TIMERB_PERIPHERAL_HEADER_TIMERB_STRUCTPERIPHERAL_H_
#define TIMERB_PERIPHERAL_HEADER_TIMERB_STRUCTPERIPHERAL_H_

#include "DriverLib/TIMERB/Peripheral/Header/TIMERB_StructRegister.h"

typedef volatile struct
{
    union
    {
        volatile const unsigned short IV;
        TIMERB_IV_t IV_bits;
    };
    const unsigned char reserved1[96U];
    union
    {
        volatile unsigned short CTL;
        TIMERB_CTL_t CTL_bits;
    };
    union
    {
        volatile unsigned short CC_CTL[7U];
        TIMERB_CC_CTL_t CC_CTL_bits[7UL];
    };
    union
    {
        volatile unsigned short R;
        TIMERB_R_t R_bits;
    };
    union
    {
        volatile unsigned short CC_R[7U];
        TIMERB_CC_R_t CC_R_bits[7UL];
    };
}TIMERB_t;


typedef volatile struct
{
    union
    {
        volatile unsigned short CTL;
        TIMERB_CC_CTL_t CTL_bits;
    };
    const unsigned char reserved2[14U];
    union
    {
        volatile unsigned short R;
        TIMERB_CC_R_t R_bits;
    };
}TIMERB_CC_t;


#endif /* TIMERB_PERIPHERAL_HEADER_TIMERB_STRUCTPERIPHERAL_H_ */
