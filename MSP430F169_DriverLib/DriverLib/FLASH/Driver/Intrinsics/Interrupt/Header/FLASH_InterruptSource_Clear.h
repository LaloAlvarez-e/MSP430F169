/**
 *
 * @file FLASH_InterruptSource_Clear.h
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
 * @verbatim 25 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 25 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_FLASH_DRIVER_INTRINSICS_INTERRUPT_HEADER_FLASH_INTERRUPTSOURCE_CLEAR_H_
#define DRIVERLIB_FLASH_DRIVER_INTRINSICS_INTERRUPT_HEADER_FLASH_INTERRUPTSOURCE_CLEAR_H_

#pragma CODE_SECTION(FLASH__vClearInterruptSource_RAM, ".TI.ramfunc")

void FLASH__vClearInterruptSource_RAM(void);
void FLASH__vClearInterruptSource(void);

#endif /* DRIVERLIB_FLASH_DRIVER_INTRINSICS_INTERRUPT_HEADER_FLASH_INTERRUPTSOURCE_CLEAR_H_ */
