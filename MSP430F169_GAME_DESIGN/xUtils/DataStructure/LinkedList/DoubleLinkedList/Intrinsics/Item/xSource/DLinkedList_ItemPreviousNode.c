/**
 *
 * @file DLinkedList_ItemPreviousNode.c
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
#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/Intrinsics/Item/xHeader/DLinkedList_ItemPreviousNode.h>

DLinkedListItem_t* DLinkedList_Item__pstGetPreviousItem(const DLinkedListItem_t* const pstItem)
{
    DLinkedListItem_t* pstPreviousItemReg = (DLinkedListItem_t*) 0UL;
    pstPreviousItemReg = pstItem->pstPreviousItem;
    return (pstPreviousItemReg);
}

void DLinkedList_Item__vSetPreviousItem(DLinkedListItem_t* pstItem, DLinkedListItem_t* pstPreviousItemArg)
{
    if(0UL != (uint32_t) pstItem)
    {
        pstItem->pstPreviousItem = pstPreviousItemArg;
    }
}
