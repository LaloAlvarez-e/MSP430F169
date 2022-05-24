/**
 *
 * @file Conversion_Wrapper.h
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
 * @verbatim 6 dic. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 6 dic. 2020     vyldram    1.0         initial Version@endverbatim
 */
#ifndef XUTILS_CONVERSION_CONVERSION_NUMBER2STRING_CONVERSION_PRIMITIVES_XHEADER_CONVERSION_WRAPPER_H_
#define XUTILS_CONVERSION_CONVERSION_NUMBER2STRING_CONVERSION_PRIMITIVES_XHEADER_CONVERSION_WRAPPER_H_


#include <xUtils/Standard/Standard.h>


#define CONV_DEFAULT_FLOAT_PRECISION ((uint32_t) 6U)
#define CONV_MAX_VALUE_FLOAT    (1e9)

typedef enum
{
    CONV_enBUFFER_SIZE_NUMBER = 32U,
    CONV_enBUFFER_SIZE_FLOAT = 32U,
}CONV_nBUFFER_SIZE;

typedef enum
{

    CONV_enFLAGS_ZEROPAD = ( (uint32_t) 1U << (uint32_t) 0U),
    CONV_enFLAGS_LEFT = ( (uint32_t) 1U << (uint32_t) 1U),
    CONV_enFLAGS_PLUS = ( (uint32_t) 1U << (uint32_t) 2U),
    CONV_enFLAGS_SPACE = ( (uint32_t) 1U << (uint32_t) 3U),
    CONV_enFLAGS_HASH = ( (uint32_t) 1U << (uint32_t) 4U),
    CONV_enFLAGS_UPPERCASE = ( (uint32_t) 1U << (uint32_t) 5U),
    CONV_enFLAGS_CHAR = ( (uint32_t) 1U << (uint32_t) 6U),
    CONV_enFLAGS_SHORT = ( (uint32_t) 1U << (uint32_t) 7U),
    CONV_enFLAGS_LONG = ( (uint32_t) 1U << (uint32_t) 8U),
    CONV_enFLAGS_LONG_LONG = ( (uint32_t) 1U << (uint32_t) 9U),
    CONV_enFLAGS_PRECISION = ( (uint32_t) 1U << (uint32_t) 10U),
    CONV_enFLAGS_ADAPT_EXP = ( (uint32_t) 1U << (uint32_t) 11U),

}CONV_nFLAGS;

/* determine the decimal exponent
 based on the algorithm by David Gay (https://www.ampl.com/netlib/fp/dtoa.c)*/
typedef union {
  uint64_t UNSIGNED;
  float64_t   FLOAT;
} CONV_FLOAT_UNION_t;

typedef void (*CONV_FUNCTION_t) (char cCharacter, void* pvFuncArguments);
typedef void (*CONV_OUT_t) (char cCharacter, void* pvBuffer, uint32_t u32Index, uint32_t u32MaxLenght);

typedef struct {
  CONV_FUNCTION_t  pvfFunction;
  void* pvArguments;
} CONV_OUT_WRAPPER_t;

void Conv__vOutBuffer(char cCharacter, void* pvBuffer, uint32_t u32Index, uint32_t u32MaxLenght);
void Conv__vOutNull(char cCharacter, void* pvBuffer, uint32_t u32Index, uint32_t u32MaxLenght);
void Conv__vOutFunction(char cCharacter, void* pvBuffer, uint32_t u32Index, uint32_t u32MaxLenght);

void Conv__vOutChar(char cCharacter, void* pvBuffer, uint32_t u32Index, uint32_t u32MaxLenght);


#endif /* XUTILS_CONVERSION_CONVERSION_NUMBER2STRING_CONVERSION_PRIMITIVES_XHEADER_CONVERSION_WRAPPER_H_ */
