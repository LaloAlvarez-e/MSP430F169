/**
 *
 * @file GPIO_StructRegister.h
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

#ifndef GPIO_PERIPHERAL_HEADER_GPIO_STRUCTREGISTER_H_
#define GPIO_PERIPHERAL_HEADER_GPIO_STRUCTREGISTER_H_

typedef volatile struct
{
    volatile const unsigned char P0 : 1;
    volatile const unsigned char P1 : 1;
    volatile const unsigned char P2 : 1;
    volatile const unsigned char P3 : 1;
    volatile const unsigned char P4 : 1;
    volatile const unsigned char P5 : 1;
    volatile const unsigned char P6 : 1;
    volatile const unsigned char P7 : 1;
}PORT_REG_CONST_t;

typedef volatile struct
{
    volatile unsigned char P0 : 1;
    volatile unsigned char P1 : 1;
    volatile unsigned char P2 : 1;
    volatile unsigned char P3 : 1;
    volatile unsigned char P4 : 1;
    volatile unsigned char P5 : 1;
    volatile unsigned char P6 : 1;
    volatile unsigned char P7 : 1;
}PORT_REG_t;


#endif /* GPIO_PERIPHERAL_HEADER_GPIO_STRUCTREGISTER_H_ */
