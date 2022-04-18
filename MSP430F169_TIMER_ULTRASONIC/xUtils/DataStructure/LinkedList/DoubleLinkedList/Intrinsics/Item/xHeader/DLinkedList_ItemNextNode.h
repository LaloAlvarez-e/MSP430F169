/**
 *
 * @file DLinkedList_ItemNextNode.h
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
#ifndef XUTILS_DATASTRUCTURE_DOUBLELINKEDLIST_INTRINSICS_ITEM_XHEADER_DLINKEDLIST_ITEMNEXTITEM_H_
#define XUTILS_DATASTRUCTURE_DOUBLELINKEDLIST_INTRINSICS_ITEM_XHEADER_DLINKEDLIST_ITEMNEXTITEM_H_

#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/Intrinsics/xHeader/DLinkedList_Struct.h>

DLinkedListItem_t* DLinkedList_Item__pstGetNextItem(const DLinkedListItem_t* const pstItem);
void DLinkedList_Item__vSetNextItem(DLinkedListItem_t* pstItem, DLinkedListItem_t* pstNextItemArg);

#endif /* XUTILS_DATASTRUCTURE_DOUBLELINKEDLIST_INTRINSICS_ITEM_XHEADER_DLINKEDLIST_ITEMNEXTITEM_H_ */
