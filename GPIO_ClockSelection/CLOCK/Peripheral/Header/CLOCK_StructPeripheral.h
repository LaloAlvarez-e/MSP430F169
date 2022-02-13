/**
 *
 * @file CLOCK_StructPeripheral.h
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
 * @verbatim 12 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 12 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef CLOCK_PERIPHERAL_HEADER_CLOCK_STRUCTPERIPHERAL_H_
#define CLOCK_PERIPHERAL_HEADER_CLOCK_STRUCTPERIPHERAL_H_

#include "CLOCK/Peripheral/Header/CLOCK_StructRegister.h"

typedef volatile struct
{
    union
    {
        volatile unsigned char IE1;
        CLOCK_IE1_t IE1_bits;
    };
    const unsigned char reserved1;
    union
    {
        volatile unsigned char IFG1;
        CLOCK_IFG1_t IFG1_bits;
    };
    const unsigned char reserved2 [83U];
    union
    {
        volatile unsigned char DCOCTL;
        CLOCK_DCOCTL_t DCOCTL_bits;
    };
    union
    {
        volatile unsigned char BCSCTL1;
        CLOCK_BCSCTL1_t BCSCTL1_bits;
    };
    union
    {
        volatile unsigned char BCSCTL2;
        CLOCK_BCSCTL2_t BCSCTL2_bits;
    };
}CLOCK_t;

#endif /* CLOCK_PERIPHERAL_HEADER_CLOCK_STRUCTPERIPHERAL_H_ */
