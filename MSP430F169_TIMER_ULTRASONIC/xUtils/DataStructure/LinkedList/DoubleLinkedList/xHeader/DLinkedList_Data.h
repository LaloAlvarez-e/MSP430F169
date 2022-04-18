/**
 *
 * @file DLinkedList_Data.h
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
#ifndef XUTILS_DATASTRUCTURE_DOUBLELINKEDLIST_XHEADER_DLINKEDLIST_DATA_H_
#define XUTILS_DATASTRUCTURE_DOUBLELINKEDLIST_XHEADER_DLINKEDLIST_DATA_H_

#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/Intrinsics/xHeader/DLinkedList_Struct.h>

void*  DLinkedList__pvGetDataItemPos(const DLinkedList_t* pstList, uint32_t u32Position);
void*  DLinkedList__pvGetDataTail(const DLinkedList_t* pstList);
void*  DLinkedList__pvGetDataHead(const DLinkedList_t* pstList);

uint32_t  DLinkedList__u32GetValueItemPos(const DLinkedList_t* pstList, uint32_t u32Position);
uint32_t  DLinkedList__u32GetValueTail(const DLinkedList_t* pstList);
uint32_t  DLinkedList__u32GetValueHead(const DLinkedList_t* pstList);

void* DLinkedList__pvGetDataNextItem(DLinkedList_t* pstList);
void* DLinkedList__pvGetDataPreviousItem(DLinkedList_t* pstList);

#endif /* XUTILS_DATASTRUCTURE_DOUBLELINKEDLIST_XHEADER_DLINKEDLIST_DATA_H_ */
