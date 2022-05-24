/**
 *
 * @file SLinkedList_Size.c
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
 * @verbatim 6 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 6 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xUtils/DataStructure/LinkedList/SingleLinkedList/Intrinsics/List/xHeader/SLinkedList_Size.h>

uint32_t SLinkedList__u32GetSize(const SLinkedList_t* const pstList)
{
    uint32_t u32SizeReg = 0UL;
    if(0UL != (uint32_t) pstList)
    {
        u32SizeReg = pstList->u32Size;
    }
    return (u32SizeReg);

}

void SLinkedList__vSetSize(SLinkedList_t*  pstList, uint32_t u32SizeArg)
{
    if(0UL != (uint32_t) pstList)
    {
        pstList->u32Size = u32SizeArg;
    }
}

SLinkedList_nSTATUS SLinkedList__enIsEmpty(const SLinkedList_t*  pstList)
{
    SLinkedList_nSTATUS enStatus = SLinkedList_enSTATUS_ERROR;
    if(0UL  == pstList->u32Size)
    {
        enStatus = SLinkedList_enSTATUS_OK;
    }
    return (enStatus);
}


