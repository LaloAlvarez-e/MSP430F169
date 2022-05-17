/**
 *
 * @file SLinkedList_Remove.h
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
#ifndef XUTILS_DATASTRUCTURE_SINGLELINKEDLIST_XHEADER_SLINKEDLIST_REMOVE_H_
#define XUTILS_DATASTRUCTURE_SINGLELINKEDLIST_XHEADER_SLINKEDLIST_REMOVE_H_

#include <xUtils/DataStructure/LinkedList/SingleLinkedList/Intrinsics/xHeader/SLinkedList_Struct.h>

SLinkedList_nSTATUS SLinkedList__enRemoveNextInList_GetData(SLinkedList_t* pstList, SLinkedListItem_t* pstItem, void** pvData);
SLinkedList_nSTATUS SLinkedList__enRemoveNextInList(SLinkedList_t* pstList, SLinkedListItem_t* pstItem);
SLinkedList_nSTATUS SLinkedList__enRemoveNext_GetData(SLinkedListItem_t* pstItem, void** pvData);
SLinkedList_nSTATUS SLinkedList__enRemoveNext(SLinkedListItem_t* pstItem);

SLinkedList_nSTATUS SLinkedList__enRemoveInList_GetData(SLinkedList_t* pstList, SLinkedListItem_t* pstItem, void** pvData);
SLinkedList_nSTATUS SLinkedList__enRemoveInList(SLinkedList_t* pstList, SLinkedListItem_t* pstItem);
SLinkedList_nSTATUS SLinkedList__enRemove_GetData(SLinkedListItem_t* pstItem, void** pvData);
SLinkedList_nSTATUS SLinkedList__enRemove(SLinkedListItem_t* pstItem);

SLinkedList_nSTATUS  SLinkedList__enRemoveTail_GetData(SLinkedList_t* pstList, void** pvData);
SLinkedList_nSTATUS  SLinkedList__enRemoveTail(SLinkedList_t* pstList);

SLinkedList_nSTATUS  SLinkedList__enRemoveHead_GetData(SLinkedList_t* pstList, void** pvData);
SLinkedList_nSTATUS  SLinkedList__enRemoveHead(SLinkedList_t* pstList);

SLinkedList_nSTATUS  SLinkedList__enRemovePos_GetData(SLinkedList_t* pstList, uint32_t u32Position, void** pvData);
SLinkedList_nSTATUS  SLinkedList__enRemovePos(SLinkedList_t* pstList, uint32_t u32Position);


#endif /* XUTILS_DATASTRUCTURE_SINGLELINKEDLIST_XHEADER_SLINKEDLIST_REMOVE_H_ */
