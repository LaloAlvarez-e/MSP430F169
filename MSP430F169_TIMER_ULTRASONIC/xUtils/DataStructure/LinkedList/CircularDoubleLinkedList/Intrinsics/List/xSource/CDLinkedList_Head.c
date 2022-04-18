/**
 *
 * @file CDLinkedList_Head.c
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
 * @verbatim 11 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 11 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/Intrinsics/List/xHeader/CDLinkedList_Head.h>

CDLinkedListItem_t* CDLinkedList__pstGetHead(const CDLinkedList_t*  const pstList)
{
    CDLinkedListItem_t* pstHeadReg = (CDLinkedListItem_t*) 0U;
    if(0UL != (uint32_t) pstList)
    {
        pstHeadReg = pstList->pstHead;
    }
    return (pstHeadReg);
}

void CDLinkedList__vSetHead(CDLinkedList_t* pstList, CDLinkedListItem_t* pstHeadArg)
{
    if(0UL != (uint32_t) pstList)
    {
        pstList->pstHead = pstHeadArg;
    }
}

CDLinkedList_nSTATUS CDLinkedList__enIsHead(const CDLinkedList_t* const pstList, const CDLinkedListItem_t* const pstItem)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    CDLinkedListItem_t* pstListHead = (CDLinkedListItem_t*)0UL;
    pstListHead = CDLinkedList__pstGetHead(pstList);
    if ((uint32_t) pstItem == (uint32_t) (pstListHead))
    {
        enStatus = CDLinkedList_enSTATUS_OK;
    }
    return (enStatus);
}
