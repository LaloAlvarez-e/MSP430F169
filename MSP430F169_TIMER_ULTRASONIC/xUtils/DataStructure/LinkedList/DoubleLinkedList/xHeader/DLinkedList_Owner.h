/**
 *
 * @file DLinkedList_Owner.h
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

#ifndef XUTILS_DATASTRUCTURE_LINKEDLIST_DOUBLELINKEDLIST_XHEADER_DLINKEDLIST_OWNER_H_
#define XUTILS_DATASTRUCTURE_LINKEDLIST_DOUBLELINKEDLIST_XHEADER_DLINKEDLIST_OWNER_H_

#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/Intrinsics/xHeader/DLinkedList_Struct.h>

DLinkedList_nSTATUS DLinkedList__enIsItemOwnerList(const DLinkedList_t* pstList, const DLinkedListItem_t* const pstItem);

#endif /* XUTILS_DATASTRUCTURE_LINKEDLIST_DOUBLELINKEDLIST_XHEADER_DLINKEDLIST_OWNER_H_ */
