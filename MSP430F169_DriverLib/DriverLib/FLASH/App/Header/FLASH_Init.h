/**
 *
 * @file FLASH_Init.h
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

#ifndef DRIVERLIB_FLASH_APP_HEADER_FLASH_INIT_H_
#define DRIVERLIB_FLASH_APP_HEADER_FLASH_INIT_H_

#include "DriverLib/FLASH/Peripheral/Header/FLASH_Enum.h"

#pragma CODE_SECTION(FLASH__u32Frequency_RAM, ".TI.ramfunc")

uint32_t FLASH__u32Init(FLASH_nCLOCK enClockSourceArg);
uint32_t FLASH__u32Frequency(void);
uint32_t FLASH__u32Frequency_RAM(void);

#endif /* DRIVERLIB_FLASH_APP_HEADER_FLASH_INIT_H_ */
