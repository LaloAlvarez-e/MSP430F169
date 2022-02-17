/**
 *
 * @file Segments_Init.c
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
 * @verbatim 16 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 16 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "Modules/Segments/Header/Segments_Init.h"
#include "Modules/Segments/Header/Segments_Global.h"

void SEGMENTS__vInit(void)
{
    uint8_t u8Count = 0U;
    GPIO_nPORT enPort = GPIO_enPORT1;
    GPIO_nPIN_NUMBER enPin = GPIO_enPIN_NUMBER0;

    for(u8Count = 0U; u8Count < (uint8_t) SEGMENTS_enDIGIT_MAX; u8Count++)
    {
        enPort = SEGMENTS__enGetDigitPort((SEGMENTS_nDIGIT) u8Count);
        enPin = SEGMENTS__enGetDigitPin((SEGMENTS_nDIGIT) u8Count);
        GPIO__vSetSelectionByNumber(enPort, enPin, GPIO_enSEL_IO);
        GPIO__vSetDirectionByNumber(enPort, enPin, GPIO_enDIR_OUTPUT);
        GPIO__vSetOutputByNumber(enPort, enPin, GPIO_enLEVEL_LOW);
    }

    for(u8Count = 0U; u8Count < (uint8_t) SEGMENTS_enSEG_MAX; u8Count++)
    {
        enPort = SEGMENTS__enGetSegPort((SEGMENTS_nSEG) u8Count);
        enPin = SEGMENTS__enGetSegPin((SEGMENTS_nSEG) u8Count);
        GPIO__vSetSelectionByNumber(enPort, enPin, GPIO_enSEL_IO);
        GPIO__vSetDirectionByNumber(enPort, enPin, GPIO_enDIR_OUTPUT);
        GPIO__vSetOutputByNumber(enPort, enPin, GPIO_enLEVEL_LOW);
    }
}



