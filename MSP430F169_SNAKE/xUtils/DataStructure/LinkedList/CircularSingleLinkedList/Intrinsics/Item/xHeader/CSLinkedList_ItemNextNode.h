/**
 *
 * @file CSLinkedList_ItemNextNode.h
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
#ifndef XUTILS_DATASTRUCTURE_CIRCULARSINGLELINKEDLIST_INTRINSICS_ITEM_XHEADER_CIRCULARSLINKEDLIST_ITEMNEXTITEM_H_
#define XUTILS_DATASTRUCTURE_CIRCULARSINGLELINKEDLIST_INTRINSICS_ITEM_XHEADER_CIRCULARSLINKEDLIST_ITEMNEXTITEM_H_

#include <xUtils/DataStructure/LinkedList/CircularSingleLinkedList/Intrinsics/xHeader/CSLinkedList_Struct.h>

CSLinkedListItem_t* CSLinkedList_Item__pstGetNextItem(const CSLinkedListItem_t* const pstItem);
void CSLinkedList_Item__vSetNextItem(CSLinkedListItem_t* pstItem, CSLinkedListItem_t* pstNextItemArg);

#endif /* XUTILS_DATASTRUCTURE_CIRCULARSINGLELINKEDLIST_INTRINSICS_ITEM_XHEADER_CIRCULARSLINKEDLIST_ITEMNEXTITEM_H_ */
