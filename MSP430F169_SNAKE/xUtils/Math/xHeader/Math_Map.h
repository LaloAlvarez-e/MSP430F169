/**
 *
 * @file Math_Map.h
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
 * @verbatim 11 feb. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 11 feb. 2021     vyldram    1.0         initial Version@endverbatim
 */

#ifndef XUTILS_MATH_XHEADER_MATH_MAP_H_
#define XUTILS_MATH_XHEADER_MATH_MAP_H_

#include <xUtils/Standard/Standard.h>

int32_t Math__s32Map(int32_t s32ValueInput, int32_t s32MaxValueInput, int32_t s32MinValueInput, int32_t s32MaxValueOutput, int32_t s32MinValueOutput);
uint32_t Math__u32Map(uint32_t u32ValueInput, uint32_t u32MaxValueInput, uint32_t u32MinValueInput, uint32_t u32MaxValueOutput, uint32_t u32MinValueOutput);

#endif /* XUTILS_MATH_XHEADER_MATH_MAP_H_ */
