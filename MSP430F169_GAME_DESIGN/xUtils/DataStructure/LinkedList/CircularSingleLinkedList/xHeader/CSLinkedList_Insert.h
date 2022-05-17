/**
 *
 * @file CSLinkedList_Insert.h
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
 * @verbatim 9 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 9 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */
#ifndef XUTILS_DATASTRUCTURE_CIRCULARSINGLELINKEDLIST_XHEADER_CIRCULARSLINKEDLIST_INSERT_H_
#define XUTILS_DATASTRUCTURE_CIRCULARSINGLELINKEDLIST_XHEADER_CIRCULARSLINKEDLIST_INSERT_H_

#include <xUtils/DataStructure/LinkedList/CircularSingleLinkedList/Intrinsics/xHeader/CSLinkedList_Struct.h>

CSLinkedList_nSTATUS CSLinkedList__enInsertNext_WithData(CSLinkedList_t* pstList,
                                            CSLinkedListItem_t* pstItem,
                                            CSLinkedListItem_t* pstNewItem,
                                            void* pvData);
CSLinkedList_nSTATUS CSLinkedList__enInsertNext(CSLinkedList_t* pstList,
                                            CSLinkedListItem_t* pstItem,
                                            CSLinkedListItem_t* pstNewItem);
CSLinkedListItem_t* CSLinkedList__pstInsertNext_WithData(CSLinkedList_t* pstList, CSLinkedListItem_t* pstItem, void* pvData);
CSLinkedListItem_t* CSLinkedList__pstInsertNext(CSLinkedList_t* pstList, CSLinkedListItem_t* pstItem);


CSLinkedList_nSTATUS  CSLinkedList__enInsertNextLastItemRead_WithData(CSLinkedList_t* pstList,
                                           CSLinkedListItem_t* pstNewItem,
                                           void* pvData);
CSLinkedList_nSTATUS  CSLinkedList__enInsertNextLastItemRead(CSLinkedList_t* pstList,
                                           CSLinkedListItem_t* pstNewItem);
CSLinkedListItem_t*  CSLinkedList__pstInsertNextLastItemRead_WithData(CSLinkedList_t* pstList, void* pvData);
CSLinkedListItem_t*  CSLinkedList__pstInsertNextLastItemRead(CSLinkedList_t* pstList);


CSLinkedList_nSTATUS CSLinkedList__enInsertAtTail_WithData(CSLinkedList_t* pstList,
                                           CSLinkedListItem_t* pstNewItem,
                                            void* pvData);
CSLinkedList_nSTATUS CSLinkedList__enInsertAtTail(CSLinkedList_t* pstList,
                                           CSLinkedListItem_t* pstNewItem);
CSLinkedListItem_t*  CSLinkedList__pstInsertAtTail_WithData(CSLinkedList_t* pstList, void* pvData);
CSLinkedListItem_t*  CSLinkedList__pstInsertAtTail(CSLinkedList_t* pstList);



CSLinkedList_nSTATUS CSLinkedList__enInsertAtHead_WithData(CSLinkedList_t* pstList,
                                                CSLinkedListItem_t* pstNewItem,
                                                void* pvData);
CSLinkedList_nSTATUS CSLinkedList__enInsertAtHead(CSLinkedList_t* pstList,
                                                CSLinkedListItem_t* pstNewItem);
CSLinkedListItem_t*  CSLinkedList__pstInsertAtHead_WithData(CSLinkedList_t* pstList, void* pvData);
CSLinkedListItem_t*  CSLinkedList__pstInsertAtHead(CSLinkedList_t* pstList);



CSLinkedList_nSTATUS CSLinkedList__enInsertPos_WithData(CSLinkedList_t* pstList,
                                            CSLinkedListItem_t* pstNewItem,
                                            uint32_t u32Position,
                                            void* pvData);
CSLinkedList_nSTATUS CSLinkedList__enInsertPos(CSLinkedList_t* pstList,
                                            CSLinkedListItem_t* pstNewItem,
                                            uint32_t u32Position);
CSLinkedListItem_t*  CSLinkedList__pstInsertPos_WithData(CSLinkedList_t* pstList, uint32_t u32Position, void* pvData);
CSLinkedListItem_t*  CSLinkedList__pstInsertPos(CSLinkedList_t* pstList, uint32_t u32Position);

#endif /* XUTILS_DATASTRUCTURE_CIRCULARSINGLELINKEDLIST_XHEADER_CIRCULARSLINKEDLIST_INSERT_H_ */
