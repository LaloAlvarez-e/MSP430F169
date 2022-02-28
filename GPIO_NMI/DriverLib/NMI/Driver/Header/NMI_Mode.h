/**
 *
 * @file NMI_Mode.h
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
 * @verbatim 26 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 26 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_NMI_DRIVER_HEADER_NMI_MODE_H_
#define DRIVERLIB_NMI_DRIVER_HEADER_NMI_MODE_H_

#include "DriverLib/NMI/Peripheral/Header/NMI_Enum.h"

void NMI__vSetMode(NMI_nMODE enMode);
NMI_nMODE NMI__enGetMode(void);

#endif /* DRIVERLIB_NMI_DRIVER_HEADER_NMI_MODE_H_ */
