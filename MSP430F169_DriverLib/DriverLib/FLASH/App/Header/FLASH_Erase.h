/**
 *
 * @file FLASH_Erase.h
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

#ifndef DRIVERLIB_FLASH_APP_HEADER_FLASH_ERASE_H_
#define DRIVERLIB_FLASH_APP_HEADER_FLASH_ERASE_H_

#include "DriverLib/FLASH/Peripheral/Header/FLASH_Enum.h"

FLASH_nSTATUS FLASH__enMassErase(void);
FLASH_nSTATUS FLASH__enFullErase(void);

FLASH_nSTATUS FLASH__enMainSegmentEraseByAddress(uintptr_t uptrAddressArg);
FLASH_nSTATUS FLASH__enInfoSegmentEraseByAddress(uintptr_t uptrAddressArg);
FLASH_nSTATUS FLASH__enSegmentEraseByAddress(uintptr_t uptrAddressArg);

FLASH_nSTATUS FLASH__enMainSegmentEraseByPosition(uint16_t u16SegmentPosArg);
FLASH_nSTATUS FLASH__enInfoSegmentEraseByPosition(uint16_t u16SegmentPosArg);
FLASH_nSTATUS FLASH__enSegmentEraseByPosition(FLASH_nSECTION enSectionArg,
                                              uint16_t u16SegmentPosArg);


#endif /* DRIVERLIB_FLASH_APP_HEADER_FLASH_ERASE_H_ */
