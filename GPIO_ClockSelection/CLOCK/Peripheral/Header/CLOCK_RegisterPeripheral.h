/**
 *
 * @file CLOCK_RegisterPeripheral.h
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
 * @verbatim 12 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 12 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef CLOCK_PERIPHERAL_HEADER_CLOCK_REGISTERPERIPHERAL_H_
#define CLOCK_PERIPHERAL_HEADER_CLOCK_REGISTERPERIPHERAL_H_

#include "CLOCK/Peripheral/Header/CLOCK_RegisterAddress.h"
#include "CLOCK/Peripheral/Header/CLOCK_StructPeripheral.h"
#include "MCU/Header/MCU_Common.h"

#define CLOCK ((CLOCK_t*) CLOCK_BASE)

/******************************************************************************************
 ************************************ 1 IE1 *********************************************
 ******************************************************************************************/
#define CLOCK_IE1_R  (*(volatile uint8_t*) (CLOCK_BASE + CLOCK_IE1_OFFSET))
#define CLOCK_IE1    ((CLOCK_IE1_t*) (CLOCK_BASE + CLOCK_IE1_OFFSET))

/******************************************************************************************
 ************************************ 2 IFG1 *********************************************
 ******************************************************************************************/
#define CLOCK_IFG1_R (*(volatile uint8_t*) (CLOCK_BASE + CLOCK_IFG1_OFFSET))
#define CLOCK_IFG1 ((CLOCK_IFG1_t*) (CLOCK_BASE + CLOCK_IFG1_OFFSET))

/******************************************************************************************
 ************************************ 3 DCOCTL *********************************************
 ******************************************************************************************/
#define CLOCK_DCOCTL_R (*(volatile uint8_t*) (CLOCK_BASE + CLOCK_DCOCTL_OFFSET))
#define CLOCK_DCOCTL ((CLOCK_DCOCTL_t*) (CLOCK_BASE + CLOCK_DCOCTL_OFFSET))

/******************************************************************************************
 ************************************ 4 BCSCTL1 *********************************************
 ******************************************************************************************/
#define CLOCK_BCSCTL1_R (*(volatile uint8_t*) (CLOCK_BASE + CLOCK_BCSCTL1_OFFSET))
#define CLOCK_BCSCTL1 ((CLOCK_BCSCTL1_t*) (CLOCK_BASE + CLOCK_BCSCTL1_OFFSET))

/******************************************************************************************
 ************************************ 5 BCSCTL2 *********************************************
 ******************************************************************************************/
#define CLOCK_BCSCTL2_R (*(volatile uint8_t*) (CLOCK_BASE + CLOCK_BCSCTL2_OFFSET))
#define CLOCK_BCSCTL2 ((CLOCK_BCSCTL2_t*) (CLOCK_BASE + CLOCK_BCSCTL2_OFFSET))

#endif /* CLOCK_PERIPHERAL_HEADER_CLOCK_REGISTERPERIPHERAL_H_ */
