/**
 *
 * @file TIMERA_Count.c
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
 * @verbatim 9 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 9 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <DriverLib/TIMERA/Driver/Global/Header/TIMERA_Count.h>

#include "DriverLib/TIMERA/Driver/Intrinsics/TIMERA_Intrinsics.h"
#include "DriverLib/TIMERA/Peripheral/TIMERA_Peripheral.h"

void TIMERA__vSetCount(uint16_t u16CountArg)
{
    TIMERA_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERA_R_OFFSET;
    pstRegisterData.u16Value = u16CountArg;
    pstRegisterData.u16Mask = TIMERA_R_R_MASK;
    pstRegisterData.u8Shift = TIMERA_R_R_R_BIT;
    TIMERA__vWriteRegister(&pstRegisterData);
}

void TIMERA__vClearCount(void)
{
    TIMERA_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERA_R_OFFSET;
    pstRegisterData.u16Value = 0U;
    pstRegisterData.u16Mask = TIMERA_R_R_MASK;
    pstRegisterData.u8Shift = TIMERA_R_R_R_BIT;
    TIMERA__vWriteRegister(&pstRegisterData);
}

uint16_t TIMERA__enGetCount(void)
{
    TIMERA_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERA_R_OFFSET;
    pstRegisterData.u16Value = 0U;
    pstRegisterData.u16Mask = TIMERA_R_R_MASK;
    pstRegisterData.u8Shift = TIMERA_R_R_R_BIT;
    (void) TIMERA__u16ReadRegister(&pstRegisterData);
    return (pstRegisterData.u16Value);
}



