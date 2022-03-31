/**
 *
 * @file MCU_ArrayCompare.h
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
 * @verbatim 11 mar. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 11 mar. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_MCU_HEADER_MCU_ARRAYCOMPARE_H_
#define DRIVERLIB_MCU_HEADER_MCU_ARRAYCOMPARE_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

uint16_t MCU__u16GetNearArrayIndex_32Bits(const uint32_t* pu32ArrayValues,
                                uint32_t u32ValueCompare,
                                uint16_t u16Length);
uint16_t MCU__u16GetNearArrayIndex_16Bits(const uint16_t* pu16ArrayValues,
                                uint16_t u16ValueCompare,
                                uint16_t u16Length);
uint16_t MCU__u16GetNearArrayIndex_8Bits(const uint8_t* pu8ArrayValues,
                                uint8_t u8ValueCompare,
                                uint16_t u16Length);

uint16_t MCU__u16GetNearArrayIndex(const void* pvArrayValues,
                                uint8_t u8ValueCompare,
                                uint16_t u16Length,
                                uint8_t u8ByteLength);


#endif /* DRIVERLIB_MCU_HEADER_MCU_ARRAYCOMPARE_H_ */
