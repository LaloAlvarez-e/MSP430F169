/**
 *
 * @file FLASH_Enum.h
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

#ifndef DRIVERLIB_FLASH_PERIPHERAL_HEADER_FLASH_ENUM_H_
#define DRIVERLIB_FLASH_PERIPHERAL_HEADER_FLASH_ENUM_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

typedef enum
{
    FLASH_enSTATUS_OK = 0U,
    FLASH_enSTATUS_ERROR = 1U,
}FLASH_nSTATUS;

typedef enum
{
    FLASH_enSECTION_MAIN = 0U,
    FLASH_enSECTION_INFO = 1U,
}FLASH_nSECTION;

typedef enum
{
    FLASH_enINT_ENABLE_DIS = 0U,
    FLASH_enINT_ENABLE_ENA = 1U,
}FLASH_nINT_ENABLE;

typedef enum
{
    FLASH_enINT_STATUS_NOOCCUR = 0U,
    FLASH_enINT_STATUS_OCCUR = 1U,
}FLASH_nINT_STATUS;

typedef enum
{
    FLASH_enERASE_OFF = 0U,
    FLASH_enERASE_SEGMENT = 1U,
    FLASH_enERASE_MAIN = 2U,
    FLASH_enERASE_MAIN_INFO = 3U,
}FLASH_nERASE;

typedef enum
{
    FLASH_enWRITE_OFF = 0x0U,
    FLASH_enWRITE_SINGLE = 0x1U,
    FLASH_enWRITE_BLOCK = 0x3U,
}FLASH_nWRITE;

typedef enum
{
    FLASH_enWORDSIZE_BYTE = 0x0U,
    FLASH_enWORDSIZE_WORD = 0x1U,
}FLASH_nWORDSIZE;


typedef enum
{
    FLASH_enCLOCK_ACLK = 0U,
    FLASH_enCLOCK_MCLK = 1U,
    FLASH_enCLOCK_SMCLK = 2U,
}FLASH_nCLOCK;

typedef enum
{
    FLASH_enBUSY_NOBUSY = 0U,
    FLASH_enBUSY_BUSY = 1U,
}FLASH_nBUSY;

typedef enum
{
    FLASH_enREADY_NOREADY = 0U,
    FLASH_enREADY_READY = 1U,
}FLASH_nREADY;

typedef enum
{
    FLASH_enLOCK_UNLOCK = 0U,
    FLASH_enLOCK_LOCK = 1U,
}FLASH_nLOCK;

typedef enum
{
    FLASH_enEMERGENCY_NA = 0U,
    FLASH_enEMERGENCY_STOP = 1U,
}FLASH_nEMERGENCY;


typedef struct
{
    uintptr_t (*uptrGetStartAddress)(void);
    uintptr_t (*uptrGetEndAddress)(void);
    uint16_t (*u16GetSegmentSize)(void);
    void (*vStartProcess)(uint8_t u8Value);
}FLASH_Segment_t;



typedef MCU_Register8Bits_t FLASH_Register8Bits_t;
typedef MCU_Register16Bits_t FLASH_Register16Bits_t;

#endif /* DRIVERLIB_FLASH_PERIPHERAL_HEADER_FLASH_ENUM_H_ */
