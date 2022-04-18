/**
 *
 * @file SLinkedList_Head.h
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
 * @verbatim 6 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 6 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */
#ifndef XUTILS_DATASTRUCTURE_SINGLELINKEDLIST_INTRINSICS_LIST_XHEADER_SLINKEDLIST_HEAD_H_
#define XUTILS_DATASTRUCTURE_SINGLELINKEDLIST_INTRINSICS_LIST_XHEADER_SLINKEDLIST_HEAD_H_

#include <xUtils/DataStructure/LinkedList/SingleLinkedList/Intrinsics/xHeader/SLinkedList_Struct.h>

SLinkedListItem_t* SLinkedList__pstGetHead(const SLinkedList_t*  const pstList);
void SLinkedList__vSetHead(SLinkedList_t* pstList, SLinkedListItem_t* pstHeadArg);
SLinkedList_nSTATUS SLinkedList__enIsHead(const SLinkedList_t* const pstList, const SLinkedListItem_t* const pstItem);

#endif /* XUTILS_DATASTRUCTURE_SINGLELINKEDLIST_INTRINSICS_LIST_XHEADER_SLINKEDLIST_HEAD_H_ */
