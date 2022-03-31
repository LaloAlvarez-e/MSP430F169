/**
 *
 * @file CLOCK_RegisterDefines_IE1.h
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

#ifndef CLOCK_PERIPHERAL_REGISTERDEFINES_HEADER_CLOCK_REGISTERDEFINES_IE1_H_
#define CLOCK_PERIPHERAL_REGISTERDEFINES_HEADER_CLOCK_REGISTERDEFINES_IE1_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

/******************************************************************************************
 ************************************ 1 IE1 *********************************************
 ******************************************************************************************/
/*-----------*/
#define CLOCK_IE1_R_OFIE_BIT ((uint8_t) 1U)

#define CLOCK_IE1_OFIE_MASK ((uint8_t) 0x01U)
#define CLOCK_IE1_OFIE_DIS ((uint8_t) 0x00U)
#define CLOCK_IE1_OFIE_ENA ((uint8_t) 0x01U)

#define CLOCK_IE1_R_OFIE_MASK (CLOCK_IE1_OFIE_MASK<< CLOCK_IE1_R_OFIE_BIT)
#define CLOCK_IE1_R_OFIE_DIS (CLOCK_IE1_OFIE_DIS << CLOCK_IE1_R_OFIE_BIT)
#define CLOCK_IE1_R_OFIE_ENA (CLOCK_IE1_OFIE_ENA << CLOCK_IE1_R_OFIE_BIT)
/*-----------*/



#endif /* CLOCK_PERIPHERAL_REGISTERDEFINES_HEADER_CLOCK_REGISTERDEFINES_IE1_H_ */
