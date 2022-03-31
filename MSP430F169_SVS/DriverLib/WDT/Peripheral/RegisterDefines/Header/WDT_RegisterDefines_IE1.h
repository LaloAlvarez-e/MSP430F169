/**
 *
 * @file WDT_RegisterDefines_IE1.h
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

#ifndef DRIVERLIB_WDT_PERIPHERAL_REGISTERDEFINES_HEADER_WDT_REGISTERDEFINES_IE1_H_
#define DRIVERLIB_WDT_PERIPHERAL_REGISTERDEFINES_HEADER_WDT_REGISTERDEFINES_IE1_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

/******************************************************************************************
 ************************************ 1 IE1 *********************************************
 ******************************************************************************************/
/*-----------*/
#define WDT_IE1_R_IE_BIT ((uint8_t) 0U)

#define WDT_IE1_IE_MASK ((uint8_t) 0x01U)
#define WDT_IE1_IE_DIS ((uint8_t) 0x00U)
#define WDT_IE1_IE_ENA ((uint8_t) 0x01U)

#define WDT_IE1_R_IE_MASK (WDT_IE1_IE_MASK<< WDT_IE1_R_IE_BIT)
#define WDT_IE1_R_IE_DIS (WDT_IE1_IE_DIS << WDT_IE1_R_IE_BIT)
#define WDT_IE1_R_IE_ENA (WDT_IE1_IE_ENA << WDT_IE1_R_IE_BIT)
/*-----------*/

#endif /* DRIVERLIB_WDT_PERIPHERAL_REGISTERDEFINES_HEADER_WDT_REGISTERDEFINES_IE1_H_ */
