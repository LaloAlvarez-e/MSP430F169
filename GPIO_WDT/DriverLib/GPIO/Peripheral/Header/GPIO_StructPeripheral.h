/**
 *
 * @file GPIO_StructPeripheral.h
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

#ifndef GPIO_PERIPHERAL_HEADER_GPIO_STRUCTPERIPHERAL_H_
#define GPIO_PERIPHERAL_HEADER_GPIO_STRUCTPERIPHERAL_H_

#include "DriverLib/GPIO/Peripheral/Header/GPIO_StructRegister.h"

typedef volatile struct
{
    union
    {
        volatile const unsigned char IN;
        PORT_REG_CONST_t IN_bits;
    };
    union
    {
        volatile unsigned char OUT;
        PORT_REG_t OUT_bits;
    };
    union
    {
        volatile unsigned char DIR;
        PORT_REG_t DIR_bits;
    };
    union
    {
        volatile unsigned char SEL;
        PORT_REG_t SEL_bits;
    };
}PORT_t;


typedef volatile struct
{
    union
    {
        volatile const unsigned char IN;
        PORT_REG_CONST_t IN_bits;
    };
    union
    {
        volatile unsigned char OUT;
        PORT_REG_t OUT_bits;
    };
    union
    {
        volatile unsigned char DIR;
        PORT_REG_t DIR_bits;
    };
    union
    {
        volatile unsigned char IFG;
        PORT_REG_t IFG_bits;
    };
    union
    {
        volatile unsigned char IES;
        PORT_REG_t IES_bits;
    };
    union
    {
        volatile unsigned char IE;
        PORT_REG_t IE_bits;
    };
    union
    {
        volatile unsigned char SEL;
        PORT_REG_t SEL_bits;
    };
    const unsigned char reserved;
}PORT_EXT_t;

typedef volatile struct
{
    PORT_t P3;
    PORT_t P4;
    PORT_EXT_t P1;
    PORT_EXT_t P2;
    PORT_t P5;
    PORT_t P6;
}GPIO_t;

#endif /* GPIO_PERIPHERAL_HEADER_GPIO_STRUCTPERIPHERAL_H_ */
