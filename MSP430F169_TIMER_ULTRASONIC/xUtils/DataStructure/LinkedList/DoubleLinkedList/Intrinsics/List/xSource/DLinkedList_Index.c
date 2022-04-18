/**
 *
 * @file DLinkedList_Index.c
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
 * @verbatim 14 jul. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 14 jul. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/Intrinsics/List/xHeader/DLinkedList_Index.h>

DLinkedListItem_t* DLinkedList__pstGetLastItemRead(const DLinkedList_t*  const pstList)
{
    DLinkedListItem_t* pstLastItemReadReg = (DLinkedListItem_t*) 0U;
    if(0UL != (uint32_t) pstList)
    {
        pstLastItemReadReg = pstList->pstLastItemRead;
    }
    return (pstLastItemReadReg);
}

void DLinkedList__vSetLastItemRead(DLinkedList_t* pstList, DLinkedListItem_t* pstLastItemReadArg)
{
    if(0UL != (uint32_t) pstList)
    {
        pstList->pstLastItemRead = pstLastItemReadArg;
    }
}

DLinkedList_nSTATUS DLinkedList__enIsLastItemRead(const DLinkedList_t* const pstList, const DLinkedListItem_t* const pstItem)
{
    DLinkedList_nSTATUS enStatus = DLinkedList_enSTATUS_ERROR;
    DLinkedListItem_t* pstListLastItemRead = (DLinkedListItem_t*)0UL;
    pstListLastItemRead= DLinkedList__pstGetLastItemRead(pstList);
    if ((uint32_t) pstItem == (uint32_t) (pstListLastItemRead))
    {
        enStatus = DLinkedList_enSTATUS_OK;
    }
    return (enStatus);
}
