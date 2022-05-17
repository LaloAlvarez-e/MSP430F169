/**
 *
 * @file CSLinkedList_Head.c
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
#include <xUtils/DataStructure/LinkedList/CircularSingleLinkedList/Intrinsics/List/xHeader/CSLinkedList_Head.h>

CSLinkedListItem_t* CSLinkedList__pstGetHead(const CSLinkedList_t*  const pstList)
{
    CSLinkedListItem_t* pstHeadReg = (CSLinkedListItem_t*) 0U;
    if(0UL != (uint32_t) pstList)
    {
        pstHeadReg = pstList->pstHead;
    }
    return (pstHeadReg);
}

void CSLinkedList__vSetHead(CSLinkedList_t* pstList, CSLinkedListItem_t* pstHeadArg)
{
    if(0UL != (uint32_t) pstList)
    {
        pstList->pstHead = pstHeadArg;
    }
}

CSLinkedList_nSTATUS CSLinkedList__enIsHead(const CSLinkedList_t* const pstList, const CSLinkedListItem_t* const pstItem)
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;
    CSLinkedListItem_t* pstListHead = (CSLinkedListItem_t*)0UL;
    pstListHead = CSLinkedList__pstGetHead(pstList);
    if ((uint32_t) pstItem == (uint32_t) (pstListHead))
    {
        enStatus = CSLinkedList_enSTATUS_OK;
    }
    return (enStatus);
}
