/**
 *
 * @file CDLinkedList_Remove.h
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
 * @verbatim 11 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 11 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */
#ifndef XUTILS_DATASTRUCTURE_CIRCULARDOUBLELINKEDLIST_XHEADER_CIRCULARDLINKEDLIST_REMOVE_H_
#define XUTILS_DATASTRUCTURE_CIRCULARDOUBLELINKEDLIST_XHEADER_CIRCULARDLINKEDLIST_REMOVE_H_

#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/Intrinsics/xHeader/CDLinkedList_Struct.h>

CDLinkedList_nSTATUS CDLinkedList__enRemoveInList_GetData(CDLinkedList_t* pstList, CDLinkedListItem_t* pstItem, void** pvData);
CDLinkedList_nSTATUS CDLinkedList__enRemoveInList(CDLinkedList_t* pstList, CDLinkedListItem_t* pstItem);
CDLinkedList_nSTATUS CDLinkedList__enRemove_GetData(CDLinkedListItem_t* pstItem, void** pvData);
CDLinkedList_nSTATUS CDLinkedList__enRemove(CDLinkedListItem_t* pstItem);

CDLinkedList_nSTATUS CDLinkedList__enRemoveNextInList_GetData(CDLinkedList_t* pstList, const CDLinkedListItem_t* pstItem, void** pvData);
CDLinkedList_nSTATUS CDLinkedList__enRemoveNextInList(CDLinkedList_t* pstList, const CDLinkedListItem_t* pstItem);
CDLinkedList_nSTATUS CDLinkedList__enRemoveNext_GetData(const CDLinkedListItem_t* pstItem, void** pvData);
CDLinkedList_nSTATUS CDLinkedList__enRemoveNext(const CDLinkedListItem_t* pstItem);

CDLinkedList_nSTATUS CDLinkedList__enRemovePreviousInList_GetData(CDLinkedList_t* pstList, const CDLinkedListItem_t* pstItem, void** pvData);
CDLinkedList_nSTATUS CDLinkedList__enRemovePreviousInList(CDLinkedList_t* pstList, const CDLinkedListItem_t* pstItem);
CDLinkedList_nSTATUS CDLinkedList__enRemovePrevious_GetData(const CDLinkedListItem_t* pstItem, void** pvData);
CDLinkedList_nSTATUS CDLinkedList__enRemovePrevious(const CDLinkedListItem_t* pstItem);

CDLinkedList_nSTATUS  CDLinkedList__enRemoveTail_GetData(CDLinkedList_t* pstList, void** pvData);
CDLinkedList_nSTATUS  CDLinkedList__enRemoveTail(CDLinkedList_t* pstList);

CDLinkedList_nSTATUS  CDLinkedList__enRemoveHead_GetData(CDLinkedList_t* pstList, void** pvData);
CDLinkedList_nSTATUS  CDLinkedList__enRemoveHead(CDLinkedList_t* pstList);

CDLinkedList_nSTATUS  CDLinkedList__enRemovePos_GetData(CDLinkedList_t* pstList, uint32_t u32Position, void** pvData);
CDLinkedList_nSTATUS  CDLinkedList__enRemovePos(CDLinkedList_t* pstList, uint32_t u32Position);

#endif /* XUTILS_DATASTRUCTURE_CIRCULARDOUBLELINKEDLIST_XHEADER_CIRCULARDLINKEDLIST_REMOVE_H_ */
