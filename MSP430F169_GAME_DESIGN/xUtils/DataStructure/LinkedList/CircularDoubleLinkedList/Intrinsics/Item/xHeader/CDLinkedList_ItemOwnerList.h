/**
 *
 * @file CDLinkedList_ItemOwnerList.h
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

#ifndef XUTILS_DATASTRUCTURE_LINKEDLIST_CIRCULARDOUBLELINKEDLIST_INTRINSICS_ITEM_XHEADER_CDLINKEDLIST_ITEMOWNERLIST_H_
#define XUTILS_DATASTRUCTURE_LINKEDLIST_CIRCULARDOUBLELINKEDLIST_INTRINSICS_ITEM_XHEADER_CDLINKEDLIST_ITEMOWNERLIST_H_

#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/Intrinsics/xHeader/CDLinkedList_Struct.h>

void* CDLinkedList_Item__pvGetOwnerList(const CDLinkedListItem_t* const pstItem);
void CDLinkedList_Item__vSetOwnerList(CDLinkedListItem_t* pstItem, void* pvOwnerListArg);

#endif /* XUTILS_DATASTRUCTURE_LINKEDLIST_CIRCULARDOUBLELINKEDLIST_INTRINSICS_ITEM_XHEADER_CDLINKEDLIST_ITEMOWNERLIST_H_ */
