/**
 *
 * @file Math_Map.c
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
 #include <xUtils/Math/xHeader/Math_Map.h>

int32_t Math__s32Map(int32_t s32ValueInput, int32_t s32MaxValueInput, int32_t s32MinValueInput, int32_t s32MaxValueOutput, int32_t s32MinValueOutput)
{
    int32_t s32DiffValuesInput = 0UL;
    int32_t s32DiffValuesOutput = 0UL;
    int32_t s32ValueOutput = 0UL;

    s32DiffValuesOutput = s32MaxValueOutput - s32MinValueOutput;
    s32DiffValuesInput = s32MaxValueInput - s32MinValueInput;

    s32ValueOutput = s32ValueInput;
    s32ValueOutput -= s32MinValueInput;
    s32ValueOutput *= s32DiffValuesOutput;
    s32ValueOutput /= s32DiffValuesInput;
    s32ValueOutput += s32MinValueOutput;

    return (s32ValueOutput);
}

uint32_t Math__u32Map(uint32_t u32ValueInput, uint32_t u32MaxValueInput, uint32_t u32MinValueInput, uint32_t u32MaxValueOutput, uint32_t u32MinValueOutput)
{
    uint32_t u32DiffValuesInput = 0UL;
    uint32_t u32DiffValuesOutput = 0UL;
    uint32_t u32ValueOutput = 0UL;

    u32DiffValuesOutput = u32MaxValueOutput - u32MinValueOutput;
    u32DiffValuesInput = u32MaxValueInput - u32MinValueInput;

    u32ValueOutput = u32ValueInput;
    u32ValueOutput -= u32MinValueInput;
    u32ValueOutput *= u32DiffValuesOutput;
    u32ValueOutput /= u32DiffValuesInput;
    u32ValueOutput += u32MinValueOutput;

    return (u32ValueOutput);
}

