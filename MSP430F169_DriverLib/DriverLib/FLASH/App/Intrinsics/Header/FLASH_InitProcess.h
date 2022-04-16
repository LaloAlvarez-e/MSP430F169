/**
 *
 * @file FLASH_InitProcess.h
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
 * @verbatim 5 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 5 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_FLASH_APP_INTRINSICS_HEADER_FLASH_INITPROCESS_H_
#define DRIVERLIB_FLASH_APP_INTRINSICS_HEADER_FLASH_INITPROCESS_H_

#include "DriverLib/FLASH/Peripheral/Header/FLASH_Enum.h"

#pragma CODE_SECTION(FLASH__u16WriteBlockProcess_RAM, ".TI.ramfunc")

uint16_t FLASH__u16WriteBlockProcess_RAM(void* pvDataArg,
                                       uint16_t* pu16DataCountArg,
                                       uintptr_t uptrAddressArg,
                                       uintptr_t uptrFlashEndAddressArg,
                                       uint16_t u16BlockMaskArg,
                                       FLASH_nWORDSIZE enWordSize);

FLASH_nSTATUS FLASH__enInitProcess(FLASH_Segment_t* pstSegmentCallback ,
                                 uint8_t u8ModeArg,
                                 void* pvDataArg,
                                 uint16_t* pu16DataCountArg,
                                 uintptr_t uptrAddressArg,
                                 FLASH_nWORDSIZE enWordSize);


#endif /* DRIVERLIB_FLASH_APP_INTRINSICS_HEADER_FLASH_INITPROCESS_H_ */
