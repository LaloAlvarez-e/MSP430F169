/**
 *
 * @file FLASH_RegisterPeripheral.h
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
 * @verbatim 24 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 24 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_FLASH_PERIPHERAL_HEADER_FLASH_REGISTERPERIPHERAL_H_
#define DRIVERLIB_FLASH_PERIPHERAL_HEADER_FLASH_REGISTERPERIPHERAL_H_

#include "DriverLib/FLASH/Peripheral/Header/FLASH_RegisterAddress.h"
#include "DriverLib/FLASH/Peripheral/Header/FLASH_StructPeripheral.h"
#include "DriverLib/MCU/Header/MCU_Common.h"

#define FLASH ((FLASH_t*) FLASH_BASE)

/******************************************************************************************
 ************************************ 1 IE1 *********************************************
 ******************************************************************************************/
#define FLASH_IE1_R  (*(volatile uint8_t*) (FLASH_BASE + FLASH_IE1_OFFSET))
#define FLASH_IE1    ((FLASH_IE1_t*) (FLASH_BASE + FLASH_IE1_OFFSET))

/******************************************************************************************
 ************************************ 2 CTL1 *********************************************
 ******************************************************************************************/
#define FLASH_CTL1_R (*(volatile uint16_t*) (FLASH_BASE + FLASH_CTL1_OFFSET))
#define FLASH_CTL1 ((FLASH_CTL1_t*) (FLASH_BASE + FLASH_CTL1_OFFSET))

/******************************************************************************************
 ************************************ 3 CTL2 *********************************************
 ******************************************************************************************/
#define FLASH_CTL2_R (*(volatile uint16_t*) (FLASH_BASE + FLASH_CTL2_OFFSET))
#define FLASH_CTL2 ((FLASH_CTL2_t*) (FLASH_BASE + FLASH_CTL2_OFFSET))

/******************************************************************************************
 ************************************ 4 CTL3 *********************************************
 ******************************************************************************************/
#define FLASH_CTL3_R (*(volatile uint16_t*) (FLASH_BASE + FLASH_CTL3_OFFSET))
#define FLASH_CTL3 ((FLASH_CTL3_t*) (FLASH_BASE + FLASH_CTL3_OFFSET))

#endif /* DRIVERLIB_FLASH_PERIPHERAL_HEADER_FLASH_REGISTERPERIPHERAL_H_ */
