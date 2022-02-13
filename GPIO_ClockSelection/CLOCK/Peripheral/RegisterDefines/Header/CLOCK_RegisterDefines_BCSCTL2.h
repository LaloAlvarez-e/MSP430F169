/**
 *
 * @file CLOCK_RegisterDefines_BCSCTL2.h
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

#ifndef CLOCK_PERIPHERAL_REGISTERDEFINES_HEADER_CLOCK_REGISTERDEFINES_BCSCTL2_H_
#define CLOCK_PERIPHERAL_REGISTERDEFINES_HEADER_CLOCK_REGISTERDEFINES_BCSCTL2_H_

#include <stdint.h>

/******************************************************************************************
 ************************************ 5 BCSCTL2 *********************************************
 ******************************************************************************************/
/*-----------*/
#define CLOCK_BCSCTL2_R_DCOR_BIT ((uint8_t) 0U)

#define CLOCK_BCSCTL2_DCOR_MASK ((uint8_t) 0x01U)
#define CLOCK_BCSCTL2_DCOR_INTERNAL ((uint8_t) 0x00U)
#define CLOCK_BCSCTL2_DCOR_EXTERNAL ((uint8_t) 0x01U)

#define CLOCK_BCSCTL2_R_DCOR_MASK (CLOCK_BCSCTL2_DCOR_MASK<< CLOCK_BCSCTL2_R_DCOR_BIT)
#define CLOCK_BCSCTL2_R_DCOR_INTERNAL (CLOCK_BCSCTL2_DCOR_INTERNAL << CLOCK_BCSCTL2_R_DCOR_BIT)
#define CLOCK_BCSCTL2_R_DCOR_EXTERNAL (CLOCK_BCSCTL2_DCOR_EXTERNAL << CLOCK_BCSCTL2_R_DCOR_BIT)
/*-----------*/

/*-----------*/
#define CLOCK_BCSCTL2_R_DIVS_BIT ((uint8_t) 1U)

#define CLOCK_BCSCTL2_DIVS_MASK ((uint8_t) 0x03U)
#define CLOCK_BCSCTL2_DIVS_1 ((uint8_t) 0x00U)
#define CLOCK_BCSCTL2_DIVS_2 ((uint8_t) 0x01U)
#define CLOCK_BCSCTL2_DIVS_4 ((uint8_t) 0x02U)
#define CLOCK_BCSCTL2_DIVS_8 ((uint8_t) 0x03U)

#define CLOCK_BCSCTL2_R_DIVS_MASK (CLOCK_BCSCTL2_DIVS_MASK<< CLOCK_BCSCTL2_R_DIVS_BIT)
#define CLOCK_BCSCTL2_R_DIVS_1 (CLOCK_BCSCTL2_DIVS_1 << CLOCK_BCSCTL2_R_DIVS_BIT)
#define CLOCK_BCSCTL2_R_DIVS_2 (CLOCK_BCSCTL2_DIVS_2 << CLOCK_BCSCTL2_R_DIVS_BIT)
#define CLOCK_BCSCTL2_R_DIVS_4 (CLOCK_BCSCTL2_DIVS_4 << CLOCK_BCSCTL2_R_DIVS_BIT)
#define CLOCK_BCSCTL2_R_DIVS_8 (CLOCK_BCSCTL2_DIVS_8 << CLOCK_BCSCTL2_R_DIVS_BIT)
/*-----------*/

/*-----------*/
#define CLOCK_BCSCTL2_R_SELS_BIT ((uint8_t) 3U)

#define CLOCK_BCSCTL2_SELS_MASK ((uint8_t) 0x01U)
#define CLOCK_BCSCTL2_SELS_DCO ((uint8_t) 0x00U)
#define CLOCK_BCSCTL2_SELS_XT2 ((uint8_t) 0x01U)

#define CLOCK_BCSCTL2_R_SELS_MASK (CLOCK_BCSCTL2_SELS_MASK<< CLOCK_BCSCTL2_R_SELS_BIT)
#define CLOCK_BCSCTL2_R_SELS_DCO (CLOCK_BCSCTL2_SELS_DCO << CLOCK_BCSCTL2_R_SELS_BIT)
#define CLOCK_BCSCTL2_R_SELS_XT2 (CLOCK_BCSCTL2_SELS_XT2 << CLOCK_BCSCTL2_R_SELS_BIT)
/*-----------*/

/*-----------*/
#define CLOCK_BCSCTL2_R_DIVM_BIT ((uint8_t) 4U)

#define CLOCK_BCSCTL2_DIVM_MASK ((uint8_t) 0x03U)
#define CLOCK_BCSCTL2_DIVM_1 ((uint8_t) 0x00U)
#define CLOCK_BCSCTL2_DIVM_2 ((uint8_t) 0x01U)
#define CLOCK_BCSCTL2_DIVM_4 ((uint8_t) 0x02U)
#define CLOCK_BCSCTL2_DIVM_8 ((uint8_t) 0x03U)

#define CLOCK_BCSCTL2_R_DIVM_MASK (CLOCK_BCSCTL2_DIVM_MASK<< CLOCK_BCSCTL2_R_DIVM_BIT)
#define CLOCK_BCSCTL2_R_DIVM_1 (CLOCK_BCSCTL2_DIVM_1 << CLOCK_BCSCTL2_R_DIVM_BIT)
#define CLOCK_BCSCTL2_R_DIVM_2 (CLOCK_BCSCTL2_DIVM_2 << CLOCK_BCSCTL2_R_DIVM_BIT)
#define CLOCK_BCSCTL2_R_DIVM_4 (CLOCK_BCSCTL2_DIVM_4 << CLOCK_BCSCTL2_R_DIVM_BIT)
#define CLOCK_BCSCTL2_R_DIVM_8 (CLOCK_BCSCTL2_DIVM_8 << CLOCK_BCSCTL2_R_DIVM_BIT)
/*-----------*/

/*-----------*/
#define CLOCK_BCSCTL2_R_SELM_BIT ((uint8_t) 6U)

#define CLOCK_BCSCTL2_SELM_MASK ((uint8_t) 0x03U)
#define CLOCK_BCSCTL2_SELM_DCO ((uint8_t) 0x01U)
#define CLOCK_BCSCTL2_SELM_XT2 ((uint8_t) 0x02U)
#define CLOCK_BCSCTL2_SELM_LFXT1 ((uint8_t) 0x03U)

#define CLOCK_BCSCTL2_R_SELM_MASK (CLOCK_BCSCTL2_SELM_MASK<< CLOCK_BCSCTL2_R_SELM_BIT)
#define CLOCK_BCSCTL2_R_SELM_DCO (CLOCK_BCSCTL2_SELM_DCO << CLOCK_BCSCTL2_R_SELM_BIT)
#define CLOCK_BCSCTL2_R_SELM_XT2 (CLOCK_BCSCTL2_SELM_XT2 << CLOCK_BCSCTL2_R_SELM_BIT)
#define CLOCK_BCSCTL2_R_SELM_LFXT1 (CLOCK_BCSCTL2_SELM_LFXT1 << CLOCK_BCSCTL2_R_SELM_BIT)
/*-----------*/

#endif /* CLOCK_PERIPHERAL_REGISTERDEFINES_HEADER_CLOCK_REGISTERDEFINES_BCSCTL2_H_ */
