/**
 *
 * @file NMI_RegisterPeripheral.h
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

#ifndef DRIVERLIB_NMI_PERIPHERAL_HEADER_NMI_REGISTERPERIPHERAL_H_
#define DRIVERLIB_NMI_PERIPHERAL_HEADER_NMI_REGISTERPERIPHERAL_H_

#include "DriverLib/NMI/Peripheral/Header/NMI_RegisterAddress.h"
#include "DriverLib/NMI/Peripheral/Header/NMI_StructPeripheral.h"
#include "DriverLib/MCU/Header/MCU_Common.h"

#define NMI ((NMI_t*) NMI_BASE)

/******************************************************************************************
 ************************************ 1 IE1 *********************************************
 ******************************************************************************************/
#define NMI_IE1_R  (*(volatile uint8_t*) (NMI_BASE + NMI_IE1_OFFSET))
#define NMI_IE1    ((NMI_IE1_t*) (NMI_BASE + NMI_IE1_OFFSET))

/******************************************************************************************
 ************************************ 2 IFG1 *********************************************
 ******************************************************************************************/
#define NMI_IFG1_R (*(volatile uint8_t*) (NMI_BASE + NMI_IFG1_OFFSET))
#define NMI_IFG1 ((NMI_IFG1_t*) (NMI_BASE + NMI_IFG1_OFFSET))

/******************************************************************************************
 ************************************ 3 CTL *********************************************
 ******************************************************************************************/
#define NMI_CTL_R (*(volatile uint16_t*) (NMI_BASE + NMI_CTL_OFFSET))
#define NMI_CTL ((NMI_CTL_t*) (NMI_BASE + NMI_CTL_OFFSET))

#endif /* DRIVERLIB_NMI_PERIPHERAL_HEADER_NMI_REGISTERPERIPHERAL_H_ */
