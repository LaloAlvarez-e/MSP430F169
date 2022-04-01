/**
 *
 * @file FLASH_Divider.h
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
 * @verbatim 1 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 1 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_DIVIDER_H_
#define DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_DIVIDER_H_

#include "DriverLib/FLASH/Peripheral/Header/FLASH_Enum.h"

#pragma CODE_SECTION(FLASH__vSetClockDivider_RAM, ".TI.ramfunc")
#pragma CODE_SECTION(FLASH__u8GetClockDivider_RAM, ".TI.ramfunc")

void FLASH__vSetClockDivider_RAM(uint8_t u8DividerArg);
uint8_t FLASH__u8GetClockDivider_RAM(void);

void FLASH__vSetClockDivider(uint8_t u8DividerArg);
uint8_t FLASH__u8GetClockDivider(void);

#endif /* DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_DIVIDER_H_ */
