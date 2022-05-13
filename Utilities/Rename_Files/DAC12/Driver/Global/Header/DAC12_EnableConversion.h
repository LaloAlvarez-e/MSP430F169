 /**
 *
 * @file DAC12_EnableConversion.h
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
 * @verbatim 21 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 21 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_DAC12_DRIVER_GLOBAL_HEADER_DAC12_ENABLECONVERSION_H_
#define DRIVERLIB_DAC12_DRIVER_GLOBAL_HEADER_DAC12_ENABLECONVERSION_H_

#include "DriverLib/DAC12/Peripheral/Header/DAC12_Enum.h"

void DAC12__vSetEnableConversion(DAC12_nENABLE enEnableArg);
void DAC12__vEnableConversion(void);
void DAC12__vDisableConversion(void);
void DAC12__vRestartEnableConversion(void);

DAC12_nENABLE DAC12__enGetEnableConversion(void);

#endif /* DRIVERLIB_DAC12_DRIVER_GLOBAL_HEADER_DAC12_ENABLECONVERSION_H_ */
