/**
 *
 * @file CSLinkedList_ItemNextNode.c
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
#include <xUtils/DataStructure/LinkedList/CircularSingleLinkedList/Intrinsics/Item/xHeader/CSLinkedList_ItemNextNode.h>

CSLinkedListItem_t* CSLinkedList_Item__pstGetNextItem(const CSLinkedListItem_t* const pstItem)
{
    CSLinkedListItem_t* pstNextItemReg = (CSLinkedListItem_t*)0UL;
    if(0UL != (uint32_t) pstItem)
    {
        pstNextItemReg = pstItem->pstNextItem;
    }
    return (pstNextItemReg);
}

void CSLinkedList_Item__vSetNextItem(CSLinkedListItem_t* pstItem, CSLinkedListItem_t* pstNextItemArg)
{
    if(0UL != (uint32_t) pstItem)
    {
        pstItem->pstNextItem = pstNextItemArg;
    }
}
