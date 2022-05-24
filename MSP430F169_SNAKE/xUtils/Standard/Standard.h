/**
 *
 * @file Standard.h
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
 * @verbatim 5 sep. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 5 sep. 2020     vyldram    1.0         initial Version@endverbatim
 */
#ifndef XUTILS_STANDARD_STANDARD_H_
#define XUTILS_STANDARD_STANDARD_H_

#include <float.h>
#include <stdint.h>
#include <stddef.h>
/*Float standard typedef defines*/
typedef float float32_t;
typedef double float64_t;
typedef long double float128_t;

/*boolean variables*/
#ifndef boolean
#define boolean
    typedef enum
    {
        FALSE = 0UL,
        TRUE = 1UL,
    }boolean_t;
#endif

typedef unsigned int UBase_t;
typedef unsigned int pointer_t;
typedef int Base_t;

#endif /* XUTILS_STANDARD_STANDARD_H_ */
