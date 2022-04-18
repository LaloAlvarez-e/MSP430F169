/**
 *
 * @file DLinkedList_Item.h
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
#ifndef XUTILS_DATASTRUCTURE_DOUBLELINKEDLIST_XHEADER_DLINKEDLIST_ITEM_H_
#define XUTILS_DATASTRUCTURE_DOUBLELINKEDLIST_XHEADER_DLINKEDLIST_ITEM_H_

#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/Intrinsics/xHeader/DLinkedList_Struct.h>

uint32_t DLinkedList__u32GetAllItem(const DLinkedList_t* pstList, void** pvData, uint32_t u32MaxLength);
uint32_t DLinkedList__u32GetAllItem_Value(const DLinkedList_t* pstList, uint32_t* pu32ValueItem, uint32_t u32MaxLength);

uint32_t DLinkedList__u32GetAllItemBackward(const DLinkedList_t* pstList, void** pvData, uint32_t u32MaxLength);
uint32_t DLinkedList__u32GetAllItemBackward_Value(const DLinkedList_t* pstList, uint32_t* pu32ValueItem, uint32_t u32MaxLength);

uint32_t DLinkedList__u32GetNItem(const DLinkedList_t* pstList, void** pvData, uint32_t u32Items, uint32_t u32MaxLength);
uint32_t DLinkedList__u32GetNItem_Value(const DLinkedList_t* pstList, uint32_t* pu32ValueItem, uint32_t u32Items, uint32_t u32MaxLength);

uint32_t DLinkedList__u32GetNItemBackward(const DLinkedList_t* pstList, void** pvData, uint32_t u32Items, uint32_t u32MaxLength);
uint32_t DLinkedList__u32GetNItemBackward_Value(const DLinkedList_t* pstList, uint32_t* pu32ValueItem, uint32_t u32Items, uint32_t u32MaxLength);

DLinkedListItem_t*  DLinkedList__pstGetItemPos(const DLinkedList_t* pstList, uint32_t u32Position);

#endif /* XUTILS_DATASTRUCTURE_DOUBLELINKEDLIST_XHEADER_DLINKEDLIST_ITEM_H_ */
