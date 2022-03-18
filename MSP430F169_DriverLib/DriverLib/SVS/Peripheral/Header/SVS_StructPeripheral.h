/**
 *
 * @file SVS_StructPeripheral.h
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

#ifndef DRIVERLIB_SVS_PERIPHERAL_HEADER_SVS_STRUCTPERIPHERAL_H_
#define DRIVERLIB_SVS_PERIPHERAL_HEADER_SVS_STRUCTPERIPHERAL_H_

#include "DriverLib/SVS/Peripheral/Header/SVS_StructRegister.h"

typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        SVS_CTL_t CTL_bits;
    };
}SVS_t;

#endif /* DRIVERLIB_SVS_PERIPHERAL_HEADER_SVS_STRUCTPERIPHERAL_H_ */
