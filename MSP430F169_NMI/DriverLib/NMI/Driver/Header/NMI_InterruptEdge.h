/**
 *
 * @file NMI_InterruptEdge.h
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
 * @verbatim 28 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 28 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_NMI_DRIVER_HEADER_NMI_INTERRUPTEDGE_H_
#define DRIVERLIB_NMI_DRIVER_HEADER_NMI_INTERRUPTEDGE_H_

#include "DriverLib/NMI/Peripheral/Header/NMI_Enum.h"

void NMI__vSetInterruptEdge(NMI_nINT_EDGE enInterruptEdgeArg);
NMI_nINT_EDGE NMI__enGetInterruptEdge(void);

#endif /* DRIVERLIB_NMI_DRIVER_HEADER_NMI_INTERRUPTEDGE_H_ */
