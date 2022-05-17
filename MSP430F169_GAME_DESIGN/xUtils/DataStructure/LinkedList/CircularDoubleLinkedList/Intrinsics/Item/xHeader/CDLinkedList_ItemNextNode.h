/**
 *
 * @file CDLinkedList_ItemNextNode.h
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
#ifndef XUTILS_DATASTRUCTURE_CIRCULARDOUBLELINKEDLIST_INTRINSICS_ITEM_XHEADER_CIRCULARDLINKEDLIST_ITEMNEXTITEM_H_
#define XUTILS_DATASTRUCTURE_CIRCULARDOUBLELINKEDLIST_INTRINSICS_ITEM_XHEADER_CIRCULARDLINKEDLIST_ITEMNEXTITEM_H_

#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/Intrinsics/xHeader/CDLinkedList_Struct.h>

CDLinkedListItem_t* CDLinkedList_Item__pstGetNextItem(const CDLinkedListItem_t* const pstItem);
void CDLinkedList_Item__vSetNextItem(CDLinkedListItem_t* pstItem, CDLinkedListItem_t* pstNextItemArg);

#endif /* XUTILS_DATASTRUCTURE_CIRCULARDOUBLELINKEDLIST_INTRINSICS_ITEM_XHEADER_CIRCULARDLINKEDLIST_ITEMNEXTITEM_H_ */
