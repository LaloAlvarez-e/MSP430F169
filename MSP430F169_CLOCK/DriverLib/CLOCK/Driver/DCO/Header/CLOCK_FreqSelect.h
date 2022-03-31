/**
 *
 * @file CLOCK_FreqSelect.h
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
 * @verbatim 15 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 15 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef CLOCK_DRIVER_DCO_HEADER_CLOCK_FREQSELECT_H_
#define CLOCK_DRIVER_DCO_HEADER_CLOCK_FREQSELECT_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

void CLOCK__vSetDCOFreqSelect(uint8_t u8FreqSelection);
uint8_t CLOCK__u8GetDCOFreqSelect(void);

#endif /* CLOCK_DRIVER_DCO_HEADER_CLOCK_FREQSELECT_H_ */
