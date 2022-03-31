/**
 *
 * @file FLASH_RegisterDefines_IE1.h
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

#ifndef DRIVERLIB_FLASH_PERIPHERAL_REGISTERDEFINES_HEADER_FLASH_REGISTERDEFINES_IE1_H_
#define DRIVERLIB_FLASH_PERIPHERAL_REGISTERDEFINES_HEADER_FLASH_REGISTERDEFINES_IE1_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

/******************************************************************************************
 ************************************ 1 IE1 *********************************************
 ******************************************************************************************/
/*-----------*/
#define FLASH_IE1_R_ACCVIE_BIT ((uint8_t) 5U)

#define FLASH_IE1_ACCVIE_MASK ((uint8_t) 0x01U)
#define FLASH_IE1_ACCVIE_DIS ((uint8_t) 0x00U)
#define FLASH_IE1_ACCVIE_ENA ((uint8_t) 0x01U)

#define FLASH_IE1_R_ACCVIE_MASK (FLASH_IE1_ACCVIE_MASK<< FLASH_IE1_R_ACCVIE_BIT)
#define FLASH_IE1_R_ACCVIE_DIS (FLASH_IE1_ACCVIE_DIS << FLASH_IE1_R_ACCVIE_BIT)
#define FLASH_IE1_R_ACCVIE_ENA (FLASH_IE1_ACCVIE_ENA << FLASH_IE1_R_ACCVIE_BIT)
/*-----------*/

#endif /* DRIVERLIB_FLASH_PERIPHERAL_REGISTERDEFINES_HEADER_FLASH_REGISTERDEFINES_IE1_H_ */
