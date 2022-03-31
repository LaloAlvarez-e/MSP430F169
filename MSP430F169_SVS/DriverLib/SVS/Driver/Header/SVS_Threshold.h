/**
 *
 * @file SVS_Threshold.h
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
 * @verbatim 12 mar. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 12 mar. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_SVS_DRIVER_HEADER_SVS_THRESHOLD_H_
#define DRIVERLIB_SVS_DRIVER_HEADER_SVS_THRESHOLD_H_

#include "DriverLib/SVS/Peripheral/Header/SVS_Enum.h"

void SVS__vSetThreshold(SVS_nTHRESHOLD enthresholdArg);
void SVS__vSetThreshold_mV(uint16_t u16ThresholdArg);
SVS_nTHRESHOLD SVS__enGetThreshold(void);
uint16_t SVS__u16GetThreshold_mV(void);

#endif /* DRIVERLIB_SVS_DRIVER_HEADER_SVS_THRESHOLD_H_ */
