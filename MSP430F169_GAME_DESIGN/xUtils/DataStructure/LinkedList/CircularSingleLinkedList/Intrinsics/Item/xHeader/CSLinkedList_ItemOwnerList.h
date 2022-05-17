/**
 *
 * @file CSLinkedList_ItemOwnerList.h
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
 * @verbatim 13 jul. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 13 jul. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XUTILS_DATASTRUCTURE_LINKEDLIST_CIRCULARSINGLELINKEDLIST_INTRINSICS_ITEM_XHEADER_CSLINKEDLIST_ITEMOWNERLIST_H_
#define XUTILS_DATASTRUCTURE_LINKEDLIST_CIRCULARSINGLELINKEDLIST_INTRINSICS_ITEM_XHEADER_CSLINKEDLIST_ITEMOWNERLIST_H_

#include <xUtils/DataStructure/LinkedList/CircularSingleLinkedList/Intrinsics/xHeader/CSLinkedList_Struct.h>

void* CSLinkedList_Item__pvGetOwnerList(const CSLinkedListItem_t* const pstItem);
void CSLinkedList_Item__vSetOwnerList(CSLinkedListItem_t* pstItem, void* pvOwnerListArg);

#endif /* XUTILS_DATASTRUCTURE_LINKEDLIST_CIRCULARSINGLELINKEDLIST_INTRINSICS_ITEM_XHEADER_CSLINKEDLIST_ITEMOWNERLIST_H_ */
