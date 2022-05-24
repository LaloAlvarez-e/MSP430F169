/**
 *
 * @file DLinkedList_Index.h
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

#ifndef XUTILS_DATASTRUCTURE_LINKEDLIST_DOUBLELINKEDLIST_INTRINSICS_LIST_XHEADER_DLINKEDLIST_INDEX_H_
#define XUTILS_DATASTRUCTURE_LINKEDLIST_DOUBLELINKEDLIST_INTRINSICS_LIST_XHEADER_DLINKEDLIST_INDEX_H_

#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/Intrinsics/xHeader/DLinkedList_Struct.h>

DLinkedListItem_t* DLinkedList__pstGetLastItemRead(const DLinkedList_t*  const pstList);
void DLinkedList__vSetLastItemRead(DLinkedList_t* pstList, DLinkedListItem_t* pstLastItemReadArg);
DLinkedList_nSTATUS DLinkedList__enIsLastItemRead(const DLinkedList_t* const pstList, const DLinkedListItem_t* const pstItem);

#endif /* XUTILS_DATASTRUCTURE_LINKEDLIST_DOUBLELINKEDLIST_INTRINSICS_LIST_XHEADER_DLINKEDLIST_INDEX_H_ */
