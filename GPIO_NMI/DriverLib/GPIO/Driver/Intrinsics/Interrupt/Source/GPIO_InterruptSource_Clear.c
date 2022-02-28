/**
 *
 * @file GPIO_InterruptSource_Clear.c
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
#include "DriverLib/GPIO/Driver/Intrinsics/Interrupt/Header/GPIO_InterruptSource_Clear.h"

#include "DriverLib/GPIO/Driver/Intrinsics/Primitives/GPIO_Primitives.h"
#include "DriverLib/GPIO/Peripheral/GPIO_Peripheral.h"


void GPIO__vClearInterruptSource(GPIO_nPORT enPortArg,
                                 GPIO_nPIN enPinMask)
{
    if((GPIO_enPORT1 == enPortArg) || (GPIO_enPORT2 == enPortArg))
    {
        GPIO__vWriteRegister(enPortArg,
                             PORT_IFG_OFFSET,
                             PORT_IFG_PIN0_NOOCCUR,
                             (uint8_t) enPinMask,
                             PORT_IFG_R_PIN0_BIT);
    }
}

void GPIO__vClearInterruptSourceByNumber(GPIO_nPORT enPortArg,
                                 GPIO_nPIN_NUMBER enPinNumber)
{
    if((GPIO_enPORT1 == enPortArg) || (GPIO_enPORT2 == enPortArg))
    {
        GPIO__vWriteRegister(enPortArg,
                             PORT_IFG_OFFSET,
                             PORT_IFG_PIN0_NOOCCUR,
                             PORT_IFG_PIN0_MASK,
                             (uint8_t) enPinNumber);
    }
}
