/**
 *
 * @file SVS_StructRegister.h
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
 * @verbatim 24 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 24 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_SVS_PERIPHERAL_HEADER_SVS_STRUCTREGISTER_H_
#define DRIVERLIB_SVS_PERIPHERAL_HEADER_SVS_STRUCTREGISTER_H_

typedef volatile struct
{
    volatile unsigned char FG : 1;
    volatile const unsigned char OP : 1;
    volatile const unsigned char ON : 1;
    volatile unsigned char PORON : 1;
    volatile unsigned char VLD : 4;
}SVS_CTL_t;

#endif /* DRIVERLIB_SVS_PERIPHERAL_HEADER_SVS_STRUCTREGISTER_H_ */
