/**
 *
 * @file CSLinkedList_Tail.h
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
#ifndef XUTILS_DATASTRUCTURE_CIRCULARSINGLELINKEDLIST_INTRINSICS_LIST_XHEADER_CIRCULARSLINKEDLIST_TAIL_H_
#define XUTILS_DATASTRUCTURE_CIRCULARSINGLELINKEDLIST_INTRINSICS_LIST_XHEADER_CIRCULARSLINKEDLIST_TAIL_H_

#include <xUtils/DataStructure/LinkedList/CircularSingleLinkedList/Intrinsics/xHeader/CSLinkedList_Struct.h>

CSLinkedListItem_t* CSLinkedList__pstGetTail(const CSLinkedList_t*  const pstList);
void CSLinkedList__vSetTail(CSLinkedList_t* pstList, CSLinkedListItem_t* pstTailArg);
CSLinkedList_nSTATUS CSLinkedList__enIsTail(const CSLinkedList_t*  const pstList, const CSLinkedListItem_t* const pstItem);

#endif /* XUTILS_DATASTRUCTURE_CIRCULARSINGLELINKEDLIST_INTRINSICS_LIST_XHEADER_CIRCULARSLINKEDLIST_TAIL_H_ */
