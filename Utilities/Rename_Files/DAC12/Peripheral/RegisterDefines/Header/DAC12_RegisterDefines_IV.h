/**
 *
 * @file DAC12_RegisterDefines_IV.h
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
 * @verbatim 20 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 20 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_DAC12_PERIPHERAL_REGISTERDEFINES_HEADER_DAC12_REGISTERDEFINES_IV_H_
#define DRIVERLIB_DAC12_PERIPHERAL_REGISTERDEFINES_HEADER_DAC12_REGISTERDEFINES_IV_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

/******************************************************************************************
 ************************************ 5 IV *********************************************
 ******************************************************************************************/
/*-----------*/
#define DAC12_IV_R_IV_BIT ((uint16_t) 0U)

#define DAC12_IV_IV_MASK ((uint16_t) 0xFFFFU)
#define DAC12_IV_IV_NONE ((uint16_t) 0x0000U)
#define DAC12_IV_IV_OV ((uint16_t) 0x0002U)
#define DAC12_IV_IV_TOV ((uint16_t) 0x0004U)
#define DAC12_IV_IV_CH0 ((uint16_t) 0x0006U)
#define DAC12_IV_IV_CH1 ((uint16_t) 0x0008U)
#define DAC12_IV_IV_CH2 ((uint16_t) 0x000AU)
#define DAC12_IV_IV_CH3 ((uint16_t) 0x000CU)
#define DAC12_IV_IV_CH4 ((uint16_t) 0x000EU)
#define DAC12_IV_IV_CH5 ((uint16_t) 0x0010U)
#define DAC12_IV_IV_CH6 ((uint16_t) 0x0012U)
#define DAC12_IV_IV_CH7 ((uint16_t) 0x0014U)
#define DAC12_IV_IV_CH8 ((uint16_t) 0x0016U)
#define DAC12_IV_IV_CH9 ((uint16_t) 0x0018U)
#define DAC12_IV_IV_CH10 ((uint16_t) 0x001AU)
#define DAC12_IV_IV_CH11 ((uint16_t) 0x001CU)
#define DAC12_IV_IV_CH12 ((uint16_t) 0x001EU)
#define DAC12_IV_IV_CH13 ((uint16_t) 0x0020U)
#define DAC12_IV_IV_CH14 ((uint16_t) 0x0022U)
#define DAC12_IV_IV_CH15 ((uint16_t) 0x0024U)

#define DAC12_IV_R_IV_MASK (DAC12_IV_IV_MASK << DAC12_IV_R_IV_BIT)
#define DAC12_IV_R_IV_OV (DAC12_IV_IV_OV << DAC12_IV_R_IV_BIT)
#define DAC12_IV_R_IV_TOV (DAC12_IV_IV_TOV << DAC12_IV_R_IV_BIT)
#define DAC12_IV_R_IV_CH0 (DAC12_IV_IV_CH0 << DAC12_IV_R_IV_BIT)
#define DAC12_IV_R_IV_CH1 (DAC12_IV_IV_CH1 << DAC12_IV_R_IV_BIT)
#define DAC12_IV_R_IV_CH2 (DAC12_IV_IV_CH2 << DAC12_IV_R_IV_BIT)
#define DAC12_IV_R_IV_CH3 (DAC12_IV_IV_CH3 << DAC12_IV_R_IV_BIT)
#define DAC12_IV_R_IV_CH4 (DAC12_IV_IV_CH4 << DAC12_IV_R_IV_BIT)
#define DAC12_IV_R_IV_CH5 (DAC12_IV_IV_CH5 << DAC12_IV_R_IV_BIT)
#define DAC12_IV_R_IV_CH6 (DAC12_IV_IV_CH6 << DAC12_IV_R_IV_BIT)
#define DAC12_IV_R_IV_CH7 (DAC12_IV_IV_CH7 << DAC12_IV_R_IV_BIT)
#define DAC12_IV_R_IV_CH8 (DAC12_IV_IV_CH8 << DAC12_IV_R_IV_BIT)
#define DAC12_IV_R_IV_CH9 (DAC12_IV_IV_CH9 << DAC12_IV_R_IV_BIT)
#define DAC12_IV_R_IV_CH10 (DAC12_IV_IV_CH10 << DAC12_IV_R_IV_BIT)
#define DAC12_IV_R_IV_CH11 (DAC12_IV_IV_CH11 << DAC12_IV_R_IV_BIT)
#define DAC12_IV_R_IV_CH12 (DAC12_IV_IV_CH12 << DAC12_IV_R_IV_BIT)
#define DAC12_IV_R_IV_CH13 (DAC12_IV_IV_CH13 << DAC12_IV_R_IV_BIT)
#define DAC12_IV_R_IV_CH14 (DAC12_IV_IV_CH14 << DAC12_IV_R_IV_BIT)
#define DAC12_IV_R_IV_CH15 (DAC12_IV_IV_CH15 << DAC12_IV_R_IV_BIT)
/*-----------*/




#endif /* DRIVERLIB_DAC12_PERIPHERAL_REGISTERDEFINES_HEADER_DAC12_REGISTERDEFINES_IV_H_ */
