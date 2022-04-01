/**
 *
 * @file FLASH_Size.h
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

#ifndef DRIVERLIB_FLASH_DRIVER_INTRINSICS_PRIMITIVES_HEADER_FLASH_SIZE_H_
#define DRIVERLIB_FLASH_DRIVER_INTRINSICS_PRIMITIVES_HEADER_FLASH_SIZE_H_

#include "DriverLib/FLASH/Peripheral/Header/FLASH_Enum.h"

#pragma CODE_SECTION(FLASH__u16GetBlockSize_RAM, ".TI.ramfunc")
#pragma CODE_SECTION(FLASH__u16GetMainSectionSize_RAM, ".TI.ramfunc")
#pragma CODE_SECTION(FLASH__u16GetInfoSectionSize_RAM, ".TI.ramfunc")
#pragma CODE_SECTION(FLASH__u16GetMainSegmentSize_RAM, ".TI.ramfunc")
#pragma CODE_SECTION(FLASH__u16GetInfoSegmentSize_RAM, ".TI.ramfunc")

uint16_t FLASH__u16GetBlockSize_RAM(void);
uint16_t FLASH__u16GetMainSectionSize_RAM(void);
uint16_t FLASH__u16GetInfoSectionSize_RAM(void);
uint16_t FLASH__u16GetMainSegmentSize_RAM(void);
uint16_t FLASH__u16GetInfoSegmentSize_RAM(void);

uint16_t FLASH__u16GetBlockSize(void);
uint16_t FLASH__u16GetMainSectionSize(void);
uint16_t FLASH__u16GetInfoSectionSize(void);
uint16_t FLASH__u16GetMainSegmentSize(void);
uint16_t FLASH__u16GetInfoSegmentSize(void);



#endif /* DRIVERLIB_FLASH_DRIVER_INTRINSICS_PRIMITIVES_HEADER_FLASH_SIZE_H_ */
