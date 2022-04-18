/**
 *
 * @file SLinkedList_Size.h
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
#ifndef XUTILS_DATASTRUCTURE_SINGLELINKEDLIST_INTRINSICS_LIST_XHEADER_SLINKEDLIST_SIZE_H_
#define XUTILS_DATASTRUCTURE_SINGLELINKEDLIST_INTRINSICS_LIST_XHEADER_SLINKEDLIST_SIZE_H_

#include <xUtils/DataStructure/LinkedList/SingleLinkedList/Intrinsics/xHeader/SLinkedList_Struct.h>

uint32_t SLinkedList__u32GetSize(const SLinkedList_t* const pstList);
void SLinkedList__vSetSize(SLinkedList_t*  pstList, uint32_t u32SizeArg);
SLinkedList_nSTATUS SLinkedList__enIsEmpty(const SLinkedList_t*  pstList);

#endif /* XUTILS_DATASTRUCTURE_SINGLELINKEDLIST_INTRINSICS_LIST_XHEADER_SLINKEDLIST_SIZE_H_ */
