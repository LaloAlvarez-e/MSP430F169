/**
 *
 * @file GPIO_InterruprRegister_Source.c
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
 * @verbatim 7 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 7 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#include "GPIO/Driver/Intrinsics/Interrupt/InterruptRegister/Header/GPIO_InterruprRegister_Source.h"
#include "GPIO/Driver/Intrinsics/Interrupt/InterruptRoutine/Header/GPIO_InterruptRoutine_Source.h"

void GPIO__vRegisterIRQSourceHandler(GPIO_nPORT enPortArg,
         GPIO_nPIN_NUMBER enPinNumber,
         MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler)
{
    if(0U != (uintptr_t) pu16fIRQSourceHandler)
    {
        if((GPIO_enPORT1 == enPortArg) || (GPIO_enPORT2 == enPortArg))
        {
            GPIO__vSetIRQSourceHandler(enPortArg, enPinNumber, pu16fIRQSourceHandler);
        }
    }
}
