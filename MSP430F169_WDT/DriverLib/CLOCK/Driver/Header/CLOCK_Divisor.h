/**
 *
 * @file CLOCK_Divisor.h
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
 * @verbatim 13 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 13 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef CLOCK_DRIVER_HEADER_CLOCK_DIVISOR_H_
#define CLOCK_DRIVER_HEADER_CLOCK_DIVISOR_H_

#include "DriverLib/CLOCK/Peripheral/Header/CLOCK_Enum.h"
#include "DriverLib/MCU/Header/MCU_Common.h"

void CLOCK__vSetDivider(CLOCK_nSIGNAL enClockSignal, CLOCK_nDIV enDivider);
void CLOCK__vSetACLKDivider(CLOCK_nDIV enDivider);
void CLOCK__vSetSMCLKDivider(CLOCK_nDIV enDivider);
void CLOCK__vSetMCLKDivider(CLOCK_nDIV enDivider);

void CLOCK__vSetDividerByNumber(CLOCK_nSIGNAL enClockSignal, uint8_t u8Divider);
void CLOCK__vSetACLKDividerByNumber(uint8_t u8Divider);
void CLOCK__vSetSMCLKDividerByNumber(uint8_t u8Divider);
void CLOCK__vSetMCLKDividerByNumber(uint8_t u8Divider);

CLOCK_nDIV CLOCK__enGetDivider(CLOCK_nSIGNAL enClockSignal);
CLOCK_nDIV CLOCK__enGetACLKDivider(void);
CLOCK_nDIV CLOCK__enGetSMCLKDivider(void);
CLOCK_nDIV CLOCK__enGetMCLKDivider(void);

uint8_t CLOCK__u8GetDivider(CLOCK_nSIGNAL enClockSignal);
uint8_t CLOCK__u8GetACLKDivider(void);
uint8_t CLOCK__u8GetSMCLKDivider(void);
uint8_t CLOCK__u8GetMCLKDivider(void);

#endif /* CLOCK_DRIVER_HEADER_CLOCK_DIVISOR_H_ */
