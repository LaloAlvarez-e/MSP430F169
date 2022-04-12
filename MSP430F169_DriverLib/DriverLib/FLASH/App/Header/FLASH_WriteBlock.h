/**
 *
 * @file FLASH_WriteBlock.h
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
 * @verbatim 8 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 8 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_FLASH_APP_HEADER_FLASH_WRITEBLOCK_H_
#define DRIVERLIB_FLASH_APP_HEADER_FLASH_WRITEBLOCK_H_

#include "DriverLib/FLASH/Peripheral/Header/FLASH_Enum.h"

FLASH_nSTATUS FLASH__enMainWriteBlock(uint16_t* pu16DataArg, uint16_t u16DataCountArg,
                                      uintptr_t uptrAddressArg);
FLASH_nSTATUS FLASH__enInfoWriteBlock(uint16_t* pu16DataArg, uint16_t u16DataCountArg,
                                      uintptr_t uptrAddressArg);
FLASH_nSTATUS FLASH__enWriteBlock(uint16_t* pu16DataArg, uint16_t u16DataCountArg,
                                  uintptr_t uptrAddressArg);

#endif /* DRIVERLIB_FLASH_APP_HEADER_FLASH_WRITEBLOCK_H_ */
