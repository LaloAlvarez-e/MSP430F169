/**
 *
 * @file CDLinkedList_ItemPreviousNode.c
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
#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/Intrinsics/Item/xHeader/CDLinkedList_ItemPreviousNode.h>

CDLinkedListItem_t* CDLinkedList_Item__pstGetPreviousItem(const CDLinkedListItem_t* const pstItem)
{
    CDLinkedListItem_t* pstPreviousItemReg = (CDLinkedListItem_t*) 0UL;
    if(0UL != (uint32_t) pstItem)
    {
        pstPreviousItemReg = pstItem->pstPreviousItem;
    }
    return (pstPreviousItemReg);
}

void CDLinkedList_Item__vSetPreviousItem(CDLinkedListItem_t* pstItem, CDLinkedListItem_t* pstPreviousItemArg)
{
    if(0UL != (uint32_t) pstItem)
    {
        pstItem->pstPreviousItem = pstPreviousItemArg;
    }
}
