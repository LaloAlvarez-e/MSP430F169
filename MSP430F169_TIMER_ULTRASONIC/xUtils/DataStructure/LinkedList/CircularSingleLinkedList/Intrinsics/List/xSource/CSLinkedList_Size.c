/**
 *
 * @file CSLinkedList_Size.c
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
 * @verbatim 9 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 9 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xUtils/DataStructure/LinkedList/CircularSingleLinkedList/Intrinsics/List/xHeader/CSLinkedList_Size.h>

uint32_t CSLinkedList__u32GetSize(const CSLinkedList_t* const pstList)
{
    uint32_t u32SizeReg = 0UL;
    if(0UL != (uint32_t) pstList)
    {
        u32SizeReg = pstList->u32Size;
    }
    return (u32SizeReg);

}

void CSLinkedList__vSetSize(CSLinkedList_t*  pstList, uint32_t u32SizeArg)
{
    if(0UL != (uint32_t) pstList)
    {
        pstList->u32Size = u32SizeArg;
    }
}

CSLinkedList_nSTATUS CSLinkedList__enIsEmpty(const CSLinkedList_t*  pstList)
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;
    if(0UL  == pstList->u32Size)
    {
        enStatus = CSLinkedList_enSTATUS_OK;
    }
    return (enStatus);
}
