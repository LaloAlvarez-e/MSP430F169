/**
 *
 * @file FLASH_RegisterAddress.h
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

#ifndef DRIVERLIB_FLASH_PERIPHERAL_HEADER_FLASH_REGISTERADDRESS_H_
#define DRIVERLIB_FLASH_PERIPHERAL_HEADER_FLASH_REGISTERADDRESS_H_

#define FLASH_BASE (0x0000U)

#define FLASH_BLOCK_SIZE (64U)

#define FLASH_MAIN_SIZE (8192U)
#define FLASH_INFO_SIZE (256U)

#define FLASH_MAIN_START_ADDRESS (0x1100U)
#define FLASH_MAIN_END_ADDRESS (FLASH_MAIN_START_ADDRESS + FLASH_MAIN_SIZE)

#define FLASH_INFO_START_ADDRESS (0x1000U)
#define FLASH_INFO_END_ADDRESS (FLASH_INFO_START_ADDRESS + FLASH_INFO_SIZE)

#define FLASH_MAIN_SEGMENT_SIZE (512U)
#define FLASH_INFO_SEGMENT_SIZE (128U)

#define FLASH_MAIN_BLOCK_NUMBER_BY_SEGMENT (FLASH_MAIN_SEGMENT_SIZE / FLASH_BLOCK_SIZE)
#define FLASH_INFO_BLOCK_NUMBER_BY_SEGMENT (FLASH_INFO_SEGMENT_SIZE / FLASH_BLOCK_SIZE)

#define FLASH_MAIN_SEGMENT_NUMBER (FLASH_MAIN_SIZE / FLASH_MAIN_SEGMENT_SIZE)
#define FLASH_INFO_SEGMENT_NUMBER (FLASH_INFO_SIZE / FLASH_INFO_SEGMENT_SIZE)

#define FLASH_IE1_OFFSET (0x0000U)
#define FLASH_CTL1_OFFSET (0x0128U)
#define FLASH_CTL2_OFFSET (0x012AU)
#define FLASH_CTL3_OFFSET (0x012CU)

#endif /* DRIVERLIB_FLASH_PERIPHERAL_HEADER_FLASH_REGISTERADDRESS_H_ */
