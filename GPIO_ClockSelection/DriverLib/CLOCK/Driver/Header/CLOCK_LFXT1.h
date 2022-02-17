/**
 *
 * @file CLOCK_LFXT1.h
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

#ifndef CLOCK_DRIVER_HEADER_CLOCK_LFXT1_H_
#define CLOCK_DRIVER_HEADER_CLOCK_LFXT1_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

uint32_t CLOCK__u32GetLFXT1Frequency(void);
uint32_t CLOCK__u32GetXT1Frequency(void);
uint32_t CLOCK__u32GetLFFrequency(void);

#endif /* CLOCK_DRIVER_HEADER_CLOCK_LFXT1_H_ */
