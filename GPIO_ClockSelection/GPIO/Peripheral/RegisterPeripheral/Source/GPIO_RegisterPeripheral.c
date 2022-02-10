/**
 *
 * @file GPIO_RegisterPeripheral.c
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
 * @verbatim 6 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 6 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "GPIO/Peripheral/RegisterPeripheral/GPIO_RegisterPeripheral.h"
#include "GPIO/Peripheral/Header/GPIO_Enum.h"

uintptr_t GPIO__uptrBlockBaseAddress(GPIO_nPORT enPortArg)
{
    uintptr_t GPIO_BLOCK_BASE[(uint8_t) GPIO_enPORT_MAX] =
    {
         PORT1_BASE, PORT2_BASE, PORT3_BASE, PORT4_BASE,
         PORT5_BASE, PORT6_BASE
    };
    uintptr_t uptrReg = 0UL;
    uptrReg = GPIO_BLOCK_BASE[(uint8_t) enPortArg];
    return(uptrReg);
}



