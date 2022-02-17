/**
 *
 * @file Segments_Defines.h
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

#ifndef MODULES_SEGMENTS_HEADER_SEGMENTS_DEFINES_H_
#define MODULES_SEGMENTS_HEADER_SEGMENTS_DEFINES_H_

#include "Modules/Segments/Header/Segments_Enum.h"
#include "DriverLib/GPIO/GPIO.h"

#define SEGMENTS_DIGIT1_PORT (GPIO_enPORT5)
#define SEGMENTS_DIGIT2_PORT (GPIO_enPORT5)
#define SEGMENTS_DIGIT3_PORT (GPIO_enPORT5)
#define SEGMENTS_DIGIT4_PORT (GPIO_enPORT5)

#define SEGMENTS_DIGIT1_PIN (GPIO_enPIN_NUMBER0)
#define SEGMENTS_DIGIT2_PIN (GPIO_enPIN_NUMBER1)
#define SEGMENTS_DIGIT3_PIN (GPIO_enPIN_NUMBER2)
#define SEGMENTS_DIGIT4_PIN (GPIO_enPIN_NUMBER3)

#define SEGMENTS_SEGA_PORT (GPIO_enPORT6)
#define SEGMENTS_SEGB_PORT (GPIO_enPORT6)
#define SEGMENTS_SEGC_PORT (GPIO_enPORT6)
#define SEGMENTS_SEGD_PORT (GPIO_enPORT6)
#define SEGMENTS_SEGE_PORT (GPIO_enPORT6)
#define SEGMENTS_SEGF_PORT (GPIO_enPORT6)
#define SEGMENTS_SEGG_PORT (GPIO_enPORT6)
#define SEGMENTS_DOT_PORT (GPIO_enPORT6)

#define SEGMENTS_SEGA_PIN (GPIO_enPIN_NUMBER0)
#define SEGMENTS_SEGB_PIN (GPIO_enPIN_NUMBER1)
#define SEGMENTS_SEGC_PIN (GPIO_enPIN_NUMBER2)
#define SEGMENTS_SEGD_PIN (GPIO_enPIN_NUMBER3)
#define SEGMENTS_SEGE_PIN (GPIO_enPIN_NUMBER4)
#define SEGMENTS_SEGF_PIN (GPIO_enPIN_NUMBER5)
#define SEGMENTS_SEGG_PIN (GPIO_enPIN_NUMBER6)
#define SEGMENTS_DOT_PIN (GPIO_enPIN_NUMBER7)



#endif /* MODULES_SEGMENTS_HEADER_SEGMENTS_DEFINES_H_ */
