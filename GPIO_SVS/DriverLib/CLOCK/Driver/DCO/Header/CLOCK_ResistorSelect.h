/**
 *
 * @file CLOCK_ResistorSelect.h
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

#ifndef CLOCK_DRIVER_DCO_HEADER_CLOCK_RESISTORSELECT_H_
#define CLOCK_DRIVER_DCO_HEADER_CLOCK_RESISTORSELECT_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

uint8_t CLOCK__u8GetResistorSelect(void);
void CLOCK__vSetResistorSelect(uint8_t u8ResistorSelect);



#endif /* CLOCK_DRIVER_DCO_HEADER_CLOCK_RESISTORSELECT_H_ */
