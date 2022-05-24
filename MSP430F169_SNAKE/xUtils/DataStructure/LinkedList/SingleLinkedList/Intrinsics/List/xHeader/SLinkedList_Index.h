/**
 *
 * @file SLinkedList_Index.h
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

#ifndef XUTILS_DATASTRUCTURE_LINKEDLIST_SINGLELINKEDLIST_INTRINSICS_LIST_XHEADER_SLINKEDLIST_INDEX_H_
#define XUTILS_DATASTRUCTURE_LINKEDLIST_SINGLELINKEDLIST_INTRINSICS_LIST_XHEADER_SLINKEDLIST_INDEX_H_

#include <xUtils/DataStructure/LinkedList/SingleLinkedList/Intrinsics/xHeader/SLinkedList_Struct.h>

SLinkedListItem_t* SLinkedList__pstGetLastItemRead(const SLinkedList_t*  const pstList);
void SLinkedList__vSetLastItemRead(SLinkedList_t* pstList, SLinkedListItem_t* pstLastItemReadArg);
SLinkedList_nSTATUS SLinkedList__enIsLastItemRead(const SLinkedList_t* const pstList, const SLinkedListItem_t* const pstItem);

#endif /* XUTILS_DATASTRUCTURE_LINKEDLIST_SINGLELINKEDLIST_INTRINSICS_LIST_XHEADER_SLINKEDLIST_INDEX_H_ */
