/**
 *
 * @file DLinkedList_ItemValue.h
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

#ifndef XUTILS_DATASTRUCTURE_LINKEDLIST_DOUBLELINKEDLIST_INTRINSICS_ITEM_XHEADER_DLINKEDLIST_ITEMVALUE_H_
#define XUTILS_DATASTRUCTURE_LINKEDLIST_DOUBLELINKEDLIST_INTRINSICS_ITEM_XHEADER_DLINKEDLIST_ITEMVALUE_H_

#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/Intrinsics/xHeader/DLinkedList_Struct.h>

uint32_t DLinkedList_Item__u32GetValue(const DLinkedListItem_t* const pstItem);
void DLinkedList_Item__vSetValue(DLinkedListItem_t* pstItem, uint32_t u32ValueItemArg);

#endif /* XUTILS_DATASTRUCTURE_LINKEDLIST_DOUBLELINKEDLIST_INTRINSICS_ITEM_XHEADER_DLINKEDLIST_ITEMVALUE_H_ */
