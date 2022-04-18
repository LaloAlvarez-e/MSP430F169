/**
 *
 * @file SLinkedList_ItemData.h
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
#ifndef XUTILS_DATASTRUCTURE_SINGLELINKEDLIST_INTRINSICS_ITEM_XHEADER_SLINKEDLIST_ITEMDATA_H_
#define XUTILS_DATASTRUCTURE_SINGLELINKEDLIST_INTRINSICS_ITEM_XHEADER_SLINKEDLIST_ITEMDATA_H_

#include <xUtils/DataStructure/LinkedList/SingleLinkedList/Intrinsics/xHeader/SLinkedList_Struct.h>

void* SLinkedList_Item__pvGetData(const SLinkedListItem_t* const pstItem);
void SLinkedList_Item__vSetData(SLinkedListItem_t* pstItem, void* pvDataArg);

#endif /* XUTILS_DATASTRUCTURE_SINGLELINKEDLIST_INTRINSICS_ITEM_XHEADER_SLINKEDLIST_ITEMDATA_H_ */
