/**
 *
 * @file DLinkedList_ItemNextNode.c
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
 * @verbatim 8 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 8 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/Intrinsics/Item/xHeader/DLinkedList_ItemNextNode.h>

DLinkedListItem_t* DLinkedList_Item__pstGetNextItem(const DLinkedListItem_t* const pstItem)
{
    DLinkedListItem_t* pstNextItemReg = (DLinkedListItem_t*)0UL;
    if(0UL != (uint32_t) pstItem)
    {
        pstNextItemReg = pstItem->pstNextItem;
    }
    return (pstNextItemReg);
}

void DLinkedList_Item__vSetNextItem(DLinkedListItem_t* pstItem, DLinkedListItem_t* pstNextItemArg)
{
    if(0UL != (uint32_t) pstItem)
    {
        pstItem->pstNextItem = pstNextItemArg;
    }
}
