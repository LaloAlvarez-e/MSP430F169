/**
 *
 * @file CSLinkedList_ItemData.h
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
#ifndef XUTILS_DATASTRUCTURE_CIRCULARSINGLELINKEDLIST_INTRINSICS_ITEM_XHEADER_CIRCULARSLINKEDLIST_ITEMDATA_H_
#define XUTILS_DATASTRUCTURE_CIRCULARSINGLELINKEDLIST_INTRINSICS_ITEM_XHEADER_CIRCULARSLINKEDLIST_ITEMDATA_H_

#include <xUtils/DataStructure/LinkedList/CircularSingleLinkedList/Intrinsics/xHeader/CSLinkedList_Struct.h>

void* CSLinkedList_Item__pvGetData(const CSLinkedListItem_t* const pstItem);
void CSLinkedList_Item__vSetData(CSLinkedListItem_t* pstItem, void* pvDataArg);

#endif /* XUTILS_DATASTRUCTURE_CIRCULARSINGLELINKEDLIST_INTRINSICS_ITEM_XHEADER_CIRCULARSLINKEDLIST_ITEMDATA_H_ */
