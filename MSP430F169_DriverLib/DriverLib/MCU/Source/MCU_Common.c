/**
 *
 * @file MCU_Common.c
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
 * @verbatim 12 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 12 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/MCU/Header/MCU_Common.h"

uint16_t MCU__u16IRQSourceHandler_Dummy(uintptr_t uptrModule,
                                       uint8_t u8IntSource)
{
    while(1U)
    {
    }
}



