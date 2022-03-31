/**
 *
 * @file Segments_Global.c
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
#include "Modules/Segments/Header/Segments_Global.h"

static const GPIO_nPORT SEGMENTS_enDigitPort[SEGMENTS_enDIGIT_MAX] =
{
 SEGMENTS_DIGIT1_PORT, SEGMENTS_DIGIT2_PORT, SEGMENTS_DIGIT3_PORT, SEGMENTS_DIGIT4_PORT
};

static const GPIO_nPIN_NUMBER SEGMENTS_enDigitPin[SEGMENTS_enDIGIT_MAX] =
{
 SEGMENTS_DIGIT1_PIN, SEGMENTS_DIGIT2_PIN, SEGMENTS_DIGIT3_PIN, SEGMENTS_DIGIT4_PIN
};

static const GPIO_nPORT SEGMENTS_enSegPort[SEGMENTS_enSEG_MAX] =
{
 SEGMENTS_SEGA_PORT, SEGMENTS_SEGB_PORT, SEGMENTS_SEGC_PORT, SEGMENTS_SEGD_PORT,
 SEGMENTS_SEGE_PORT, SEGMENTS_SEGF_PORT, SEGMENTS_SEGG_PORT, SEGMENTS_DOT_PORT,
};

static const GPIO_nPIN_NUMBER SEGMENTS_enSegPin[SEGMENTS_enSEG_MAX] =
{
 SEGMENTS_SEGA_PIN, SEGMENTS_SEGB_PIN, SEGMENTS_SEGC_PIN, SEGMENTS_SEGD_PIN,
 SEGMENTS_SEGE_PIN, SEGMENTS_SEGF_PIN, SEGMENTS_SEGG_PIN, SEGMENTS_DOT_PIN,
};

GPIO_nPORT SEGMENTS__enGetDigitPort(SEGMENTS_nDIGIT enDigitNumber)
{
    GPIO_nPORT enDigitPortReg = GPIO_enPORT1;

    enDigitPortReg = SEGMENTS_enDigitPort[(uint8_t) enDigitNumber];
    return (enDigitPortReg);
}

GPIO_nPORT SEGMENTS__enGetSegPort(SEGMENTS_nSEG enSegNumber)
{
    GPIO_nPORT enSegPortReg = GPIO_enPORT1;

    enSegPortReg = SEGMENTS_enSegPort[(uint8_t) enSegNumber];
    return (enSegPortReg);
}

GPIO_nPIN_NUMBER SEGMENTS__enGetDigitPin(SEGMENTS_nDIGIT enDigitNumber)
{
    GPIO_nPIN_NUMBER enDigitPinReg = GPIO_enPIN_NUMBER0;

    enDigitPinReg = SEGMENTS_enDigitPin[(uint8_t) enDigitNumber];
    return (enDigitPinReg);
}

GPIO_nPIN_NUMBER SEGMENTS__enGetSegPin(SEGMENTS_nSEG enSegNumber)
{
    GPIO_nPIN_NUMBER enSegPinReg = GPIO_enPIN_NUMBER0;

    enSegPinReg = SEGMENTS_enSegPin[(uint8_t) enSegNumber];
    return (enSegPinReg);
}
