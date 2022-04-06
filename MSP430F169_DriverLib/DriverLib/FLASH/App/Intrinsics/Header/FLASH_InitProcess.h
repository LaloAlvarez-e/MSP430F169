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

FLASH_nSTATUS FLASH__enInitProcess(FLASH_Segment_t* pstSegmentCallback ,
                                         uint8_t u8ModeArg,
                                         uint16_t u16DataArg,
                                         uintptr_t uptrAddressArg);



#endif /* DRIVERLIB_FLASH_APP_INTRINSICS_HEADER_FLASH_INITPROCESS_H_ */
