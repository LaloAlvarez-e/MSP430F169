/**
 *
 * @file CDLinkedList_Index.h
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

#ifndef XUTILS_DATASTRUCTURE_LINKEDLIST_CIRCULARDOUBLELINKEDLIST_INTRINSICS_LIST_XHEADER_CDLINKEDLIST_INDEX_H_
#define XUTILS_DATASTRUCTURE_LINKEDLIST_CIRCULARDOUBLELINKEDLIST_INTRINSICS_LIST_XHEADER_CDLINKEDLIST_INDEX_H_

#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/Intrinsics/xHeader/CDLinkedList_Struct.h>

CDLinkedListItem_t* CDLinkedList__pstGetLastItemRead(const CDLinkedList_t*  const pstList);
void CDLinkedList__vSetLastItemRead(CDLinkedList_t* pstList, CDLinkedListItem_t* pstLastItemReadArg);
CDLinkedList_nSTATUS CDLinkedList__enIsLastItemRead(const CDLinkedList_t* const pstList, const CDLinkedListItem_t* const pstItem);

#endif /* XUTILS_DATASTRUCTURE_LINKEDLIST_CIRCULARDOUBLELINKEDLIST_INTRINSICS_LIST_XHEADER_CDLINKEDLIST_INDEX_H_ */
