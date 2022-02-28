/**
 *
 * @file NMI_InterruptRegister_Source.h
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

#ifndef DRIVERLIB_NMI_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_HEADER_NMI_INTERRUPTREGISTER_SOURCE_H_
#define DRIVERLIB_NMI_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_HEADER_NMI_INTERRUPTREGISTER_SOURCE_H_

#include "DriverLib/NMI/Peripheral/Header/NMI_Enum.h"
#include "DriverLib/MCU/Header/MCU_Common.h"

void NMI__vRegisterIRQSourceHandler(MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler);


#endif /* DRIVERLIB_NMI_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_HEADER_NMI_INTERRUPTREGISTER_SOURCE_H_ */
