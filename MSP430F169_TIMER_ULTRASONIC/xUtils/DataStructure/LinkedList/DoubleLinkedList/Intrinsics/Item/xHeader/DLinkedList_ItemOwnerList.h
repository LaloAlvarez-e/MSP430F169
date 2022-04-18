/**
 *
 * @file DLinkedList_ItemOwnerList.h
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
 * @verbatim 13 jul. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 13 jul. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XUTILS_DATASTRUCTURE_LINKEDLIST_DOUBLELINKEDLIST_INTRINSICS_ITEM_XHEADER_DLINKEDLIST_ITEMOWNERLIST_H_
#define XUTILS_DATASTRUCTURE_LINKEDLIST_DOUBLELINKEDLIST_INTRINSICS_ITEM_XHEADER_DLINKEDLIST_ITEMOWNERLIST_H_

#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/Intrinsics/xHeader/DLinkedList_Struct.h>

void* DLinkedList_Item__pvGetOwnerList(const DLinkedListItem_t* const pstItem);
void DLinkedList_Item__vSetOwnerList(DLinkedListItem_t* pstItem, void* pvOwnerListArg);

#endif /* XUTILS_DATASTRUCTURE_LINKEDLIST_DOUBLELINKEDLIST_INTRINSICS_ITEM_XHEADER_DLINKEDLIST_ITEMOWNERLIST_H_ */
