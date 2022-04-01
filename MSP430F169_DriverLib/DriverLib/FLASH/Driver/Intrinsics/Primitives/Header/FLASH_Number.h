/**
 *
 * @file FLASH_Number.h
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

#ifndef DRIVERLIB_FLASH_DRIVER_INTRINSICS_PRIMITIVES_HEADER_FLASH_NUMBER_H_
#define DRIVERLIB_FLASH_DRIVER_INTRINSICS_PRIMITIVES_HEADER_FLASH_NUMBER_H_

#include "DriverLib/FLASH/Peripheral/Header/FLASH_Enum.h"

#pragma CODE_SECTION(FLASH__u16GetMainBlockNumberBySegment_RAM, ".TI.ramfunc")
#pragma CODE_SECTION(FLASH__u16GetInfoBlockNumberBySegment_RAM, ".TI.ramfunc")
#pragma CODE_SECTION(FLASH__u16GetMainSegmentNumber_RAM, ".TI.ramfunc")
#pragma CODE_SECTION(FLASH__u16GetInfoSegmentNumber_RAM, ".TI.ramfunc")

uint16_t FLASH__u16GetMainBlockNumberBySegment_RAM(void);
uint16_t FLASH__u16GetInfoBlockNumberBySegment_RAM(void);
uint16_t FLASH__u16GetMainSegmentNumber_RAM(void);
uint16_t FLASH__u16GetInfoSegmentNumber_RAM(void);

uint16_t FLASH__u16GetMainBlockNumberBySegment(void);
uint16_t FLASH__u16GetInfoBlockNumberBySegment(void);
uint16_t FLASH__u16GetMainSegmentNumber(void);
uint16_t FLASH__u16GetInfoSegmentNumber(void);


#endif /* DRIVERLIB_FLASH_DRIVER_INTRINSICS_PRIMITIVES_HEADER_FLASH_NUMBER_H_ */
