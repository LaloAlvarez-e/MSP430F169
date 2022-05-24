/**
 *
 * @file CDLinkedList_Owner.h
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
 * @verbatim 14 jul. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 14 jul. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XUTILS_DATASTRUCTURE_LINKEDLIST_CIRCULARDOUBLELINKEDLIST_XHEADER_CDLINKEDLIST_OWNER_H_
#define XUTILS_DATASTRUCTURE_LINKEDLIST_CIRCULARDOUBLELINKEDLIST_XHEADER_CDLINKEDLIST_OWNER_H_

#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/Intrinsics/xHeader/CDLinkedList_Struct.h>

CDLinkedList_nSTATUS CDLinkedList__enIsItemOwnerList(const CDLinkedList_t* pstList, const CDLinkedListItem_t* const pstItem);

#endif /* XUTILS_DATASTRUCTURE_LINKEDLIST_CIRCULARDOUBLELINKEDLIST_XHEADER_CDLINKEDLIST_OWNER_H_ */
