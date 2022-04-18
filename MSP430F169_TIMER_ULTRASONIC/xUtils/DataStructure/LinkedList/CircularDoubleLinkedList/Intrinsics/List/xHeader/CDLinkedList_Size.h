/**
 *
 * @file CDLinkedList_Size.h
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
#ifndef XUTILS_DATASTRUCTURE_CIRCULARDOUBLELINKEDLIST_INTRINSICS_LIST_XHEADER_CIRCULARDLINKEDLIST_SIZE_H_
#define XUTILS_DATASTRUCTURE_CIRCULARDOUBLELINKEDLIST_INTRINSICS_LIST_XHEADER_CIRCULARDLINKEDLIST_SIZE_H_

#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/Intrinsics/xHeader/CDLinkedList_Struct.h>

uint32_t CDLinkedList__u32GetSize(const CDLinkedList_t* const pstList);
void CDLinkedList__vSetSize(CDLinkedList_t*  pstList, uint32_t u32SizeArg);
CDLinkedList_nSTATUS CDLinkedList__enIsEmpty(const CDLinkedList_t*  pstList);

#endif /* XUTILS_DATASTRUCTURE_CIRCULARDOUBLELINKEDLIST_INTRINSICS_LIST_XHEADER_CIRCULARDLINKEDLIST_SIZE_H_ */
