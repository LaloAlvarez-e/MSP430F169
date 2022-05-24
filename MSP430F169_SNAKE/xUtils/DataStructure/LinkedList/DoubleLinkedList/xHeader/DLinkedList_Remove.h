/**
 *
 * @file DLinkedList_Remove.h
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
#ifndef XUTILS_DATASTRUCTURE_DOUBLELINKEDLIST_XHEADER_DLINKEDLIST_REMOVE_H_
#define XUTILS_DATASTRUCTURE_DOUBLELINKEDLIST_XHEADER_DLINKEDLIST_REMOVE_H_

#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/Intrinsics/xHeader/DLinkedList_Struct.h>

DLinkedList_nSTATUS DLinkedList__enRemoveInList_GetData(DLinkedList_t* pstList, DLinkedListItem_t* pstItem, void** pvData);
DLinkedList_nSTATUS DLinkedList__enRemoveInList(DLinkedList_t* pstList, DLinkedListItem_t* pstItem);
DLinkedList_nSTATUS DLinkedList__enRemove_GetData(DLinkedListItem_t* pstItem, void** pvData);
DLinkedList_nSTATUS DLinkedList__enRemove(DLinkedListItem_t* pstItem);

DLinkedList_nSTATUS DLinkedList__enRemoveNextInList_GetData(DLinkedList_t* pstList, const DLinkedListItem_t* pstItem, void** pvData);
DLinkedList_nSTATUS DLinkedList__enRemoveNextInList(DLinkedList_t* pstList, const DLinkedListItem_t* pstItem);
DLinkedList_nSTATUS DLinkedList__enRemoveNext_GetData(const DLinkedListItem_t* pstItem, void** pvData);
DLinkedList_nSTATUS DLinkedList__enRemoveNext(const DLinkedListItem_t* pstItem);

DLinkedList_nSTATUS DLinkedList__enRemovePreviousInList_GetData(DLinkedList_t* pstList, const DLinkedListItem_t* pstItem, void** pvData);
DLinkedList_nSTATUS DLinkedList__enRemovePreviousInList(DLinkedList_t* pstList, const DLinkedListItem_t* pstItem);
DLinkedList_nSTATUS DLinkedList__enRemovePrevious_GetData(const DLinkedListItem_t* pstItem, void** pvData);
DLinkedList_nSTATUS DLinkedList__enRemovePrevious(const DLinkedListItem_t* pstItem);

DLinkedList_nSTATUS  DLinkedList__enRemoveHead_GetData(DLinkedList_t* pstList, void** pvData);
DLinkedList_nSTATUS  DLinkedList__enRemoveHead(DLinkedList_t* pstList);

DLinkedList_nSTATUS  DLinkedList__enRemoveTail_GetData(DLinkedList_t* pstList, void** pvData);
DLinkedList_nSTATUS  DLinkedList__enRemoveTail(DLinkedList_t* pstList);

 DLinkedList_nSTATUS  DLinkedList__enRemovePos_GetData(DLinkedList_t* pstList, uint32_t u32Position, void** pvData);
 DLinkedList_nSTATUS  DLinkedList__enRemovePos(DLinkedList_t* pstList, uint32_t u32Position);

#endif /* XUTILS_DATASTRUCTURE_DOUBLELINKEDLIST_XHEADER_DLINKEDLIST_REMOVE_H_ */
