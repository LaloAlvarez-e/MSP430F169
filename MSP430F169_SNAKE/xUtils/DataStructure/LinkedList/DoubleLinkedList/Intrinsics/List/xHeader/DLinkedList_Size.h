/**
 *
 * @file DLinkedList_Size.h
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
#ifndef XUTILS_DATASTRUCTURE_DOUBLELINKEDLIST_INTRINSICS_LIST_XHEADER_DLINKEDLIST_SIZE_H_
#define XUTILS_DATASTRUCTURE_DOUBLELINKEDLIST_INTRINSICS_LIST_XHEADER_DLINKEDLIST_SIZE_H_

#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/Intrinsics/xHeader/DLinkedList_Struct.h>

uint32_t DLinkedList__u32GetSize(const DLinkedList_t* const pstList);
void DLinkedList__vSetSize(DLinkedList_t*  pstList, uint32_t u32SizeArg);
DLinkedList_nSTATUS DLinkedList__enIsEmpty(const DLinkedList_t*  pstList);

#endif /* XUTILS_DATASTRUCTURE_DOUBLELINKEDLIST_INTRINSICS_LIST_XHEADER_DLINKEDLIST_SIZE_H_ */
