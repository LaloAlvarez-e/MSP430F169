/**
 *
 * @file CDLinkedList_Item.h
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
#ifndef XUTILS_DATASTRUCTURE_CIRCULARDOUBLELINKEDLIST_XHEADER_CIRCULARDLINKEDLIST_ITEM_H_
#define XUTILS_DATASTRUCTURE_CIRCULARDOUBLELINKEDLIST_XHEADER_CIRCULARDLINKEDLIST_ITEM_H_


#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/Intrinsics/xHeader/CDLinkedList_Struct.h>

uint32_t CDLinkedList__u32GetAllItem(const CDLinkedList_t* pstList, const void** pvData, uint32_t u32MaxLength);
uint32_t CDLinkedList__u32GetAllItem_Value(const CDLinkedList_t* pstList, uint32_t* pu32ValueItem, uint32_t u32MaxLength);

uint32_t CDLinkedList__u32GetAllItemBackward(const CDLinkedList_t* pstList, void** pvData, uint32_t u32MaxLength);
uint32_t CDLinkedList__u32GetAllItemBackward_Value(const CDLinkedList_t* pstList, uint32_t* pu32ValueItem, uint32_t u32MaxLength);

uint32_t CDLinkedList__u32GetNItem(const CDLinkedList_t* pstList, void** pvData, uint32_t u32Items, uint32_t u32MaxLength);
uint32_t CDLinkedList__u32GetNItem_Value(const CDLinkedList_t* pstList, uint32_t* pu32ValueItem, uint32_t u32Items, uint32_t u32MaxLength);

uint32_t CDLinkedList__u32GetNItemBackward(const CDLinkedList_t* pstList, void** pvData, uint32_t u32Items, uint32_t u32MaxLength);
uint32_t CDLinkedList__u32GetNItemBackward_Value(const CDLinkedList_t* pstList, uint32_t* pu32ValueItem, uint32_t u32Items, uint32_t u32MaxLength);

CDLinkedListItem_t*  CDLinkedList__pstGetItemPos(const CDLinkedList_t* pstList, uint32_t u32Position);

#endif /* XUTILS_DATASTRUCTURE_CIRCULARDOUBLELINKEDLIST_XHEADER_CIRCULARDLINKEDLIST_ITEM_H_ */
