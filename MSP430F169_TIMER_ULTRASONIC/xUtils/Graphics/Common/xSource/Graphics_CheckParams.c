/**
 *
 * @file Graphics_CheckParams.c
 * @copyright
 * @verbatim InDeviceMex 2020 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 19 feb. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 19 feb. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xUtils/Graphics/Common/xHeader/Graphics_CheckParams.h>

Graphics_nSTATUS Graphics__enCheckParams(uint32_t u32PosStart, uint32_t u32PosOffset, uint32_t u32ValueMax)
{
    Graphics_nSTATUS enStatus = Graphics_enSTATUS_OK;
    uint32_t u32PosReg = 0UL;
    u32PosReg = u32PosStart;
    u32PosReg += u32PosOffset;
    if(u32PosReg > u32ValueMax)
    {
        enStatus = Graphics_enSTATUS_ERROR;
    }

    return (enStatus);
}




