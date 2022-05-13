/**
 *
 * @file DAC12_ClockDivider.h
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
 * @verbatim 22 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 22 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_DAC12_DRIVER_GLOBAL_HEADER_DAC12_CLOCKDIVIDER_H_
#define DRIVERLIB_DAC12_DRIVER_GLOBAL_HEADER_DAC12_CLOCKDIVIDER_H_

#include "DriverLib/DAC12/Peripheral/Header/DAC12_Enum.h"

void DAC12__vSetClockDivider(DAC12_nCLOCKDIV enClockDivArg);
DAC12_nCLOCKDIV DAC12__enGetClockDivider(void);


void DAC12__vSetClockDividerByNumber(uint8_t u8ClockDivArg);
uint8_t DAC12__u8GetClockDividerByNumber(void);

#endif /* DRIVERLIB_DAC12_DRIVER_GLOBAL_HEADER_DAC12_CLOCKDIVIDER_H_ */
