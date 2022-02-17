/**
 *
 * @file CLOCK_Frequency.h
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
 * @verbatim 16 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 16 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef CLOCK_DRIVER_HEADER_CLOCK_FREQUENCY_H_
#define CLOCK_DRIVER_HEADER_CLOCK_FREQUENCY_H_

#include "DriverLib/CLOCK/Peripheral/Header/CLOCK_Enum.h"
#include "DriverLib/MCU/Header/MCU_Common.h"

uint32_t CLOCK__u32GetFrequency(CLOCK_nSIGNAL enClockSignal);
uint32_t CLOCK__u32GetMCLKFrequency(void);
uint32_t CLOCK__u32GetSMCLKFrequency(void);
uint32_t CLOCK__u32GetACLKFrequency(void);

#endif /* CLOCK_DRIVER_HEADER_CLOCK_FREQUENCY_H_ */
