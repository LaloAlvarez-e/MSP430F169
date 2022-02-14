/**
 *
 * @file CLOCK_DCO.c
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
 * @verbatim 14 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 14 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#if 0
/*(RSEL << 4U) | DCO*/
static const uint32_t CLOCK_u32CodificationLUT[8U * 8U] =
{
 (0U << 4U) | 0U, (0U << 4U) | 1U, (0U << 4U) | 2U, (0U << 4U) | 3U,
 (1U << 4U) | 0U, (0U << 4U) | 4U, (1U << 4U) | 1U, (0U << 4U) | 5U,
 (1U << 4U) | 2U, (0U << 4U) | 6U, (1U << 4U) | 3U, (0U << 4U) | 7U,
 (1U << 4U) | 4U, (2U << 4U) | 0U, (1U << 4U) | 5U, (2U << 4U) | 1U,
 (1U << 4U) | 6U, (2U << 4U) | 2U, (1U << 4U) | 7U, (2U << 4U) | 3U,
 (2U << 4U) | 4U, (3U << 4U) | 0U, (2U << 4U) | 5U, (3U << 4U) | 1U,
 (2U << 4U) | 6U, (3U << 4U) | 2U, (2U << 4U) | 7U, (3U << 4U) | 3U,
 (3U << 4U) | 4U, (4U << 4U) | 0U, (3U << 4U) | 5U, (4U << 4U) | 1U,
 (3U << 4U) | 6U, (4U << 4U) | 2U, (3U << 4U) | 7U, (4U << 4U) | 3U,
 (4U << 4U) | 4U, (5U << 4U) | 0U, (4U << 4U) | 5U, (5U << 4U) | 1U,
 (4U << 4U) | 6U, (5U << 4U) | 2U, (4U << 4U) | 7U, (5U << 4U) | 3U,
 (5U << 4U) | 4U, (6U << 4U) | 0U, (5U << 4U) | 5U, (6U << 4U) | 1U,
 (5U << 4U) | 6U, (6U << 4U) | 2U, (5U << 4U) | 7U, (6U << 4U) | 3U,
 (6U << 4U) | 4U, (7U << 4U) | 0U, (6U << 4U) | 5U, (7U << 4U) | 1U,
 (6U << 4U) | 6U, (7U << 4U) | 2U, (6U << 4U) | 7U, (7U << 4U) | 3U,
 (7U << 4U) | 4U, (7U << 4U) | 5U, (7U << 4U) | 6U, (7U << 4U) | 7U,
};

static const uint32_t CLOCK_u32FrequencyLUT[8U * 8U] =
{
   93943UL,  104503UL,  116249UL,  129315UL,  130075UL,  143851UL,  144696UL,  160020UL,
  160960UL,  178006UL,  179052UL,  198014UL,  199178UL,  210325UL,  221566UL,  233965UL,
  246470UL,  260263UL,  274174UL,  289517UL,  322059UL,  340083UL,  358259UL,  378309UL,
  398528UL,  420831UL,  443323UL,  468133UL,  520752UL,  549895UL,  579286UL,  611704UL,
  644398UL,  680461UL,  716829UL,  756946UL,  842027UL,  889150UL,  936672UL,  989092UL,
 1041956UL, 1100267UL, 1159073UL, 1223939UL, 1361512UL, 1437707UL, 1514547UL, 1599307UL,
 1684785UL, 1779071UL, 1874157UL, 1979041UL, 2201488UL, 2324692UL, 2448939UL, 2585991UL,
 2724203UL, 2876659UL, 3030407UL, 3200000UL, 3559684UL, 3959798UL, 4404885UL, 4900000UL
};

#endif
