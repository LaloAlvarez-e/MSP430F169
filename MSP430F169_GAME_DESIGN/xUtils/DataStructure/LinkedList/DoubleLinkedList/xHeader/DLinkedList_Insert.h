/**
 *
 * @file DLinkedList_Insert.h
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
#ifndef XUTILS_DATASTRUCTURE_DOUBLELINKEDLIST_XHEADER_DLINKEDLIST_INSERT_H_
#define XUTILS_DATASTRUCTURE_DOUBLELINKEDLIST_XHEADER_DLINKEDLIST_INSERT_H_

#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/Intrinsics/xHeader/DLinkedList_Struct.h>

DLinkedList_nSTATUS DLinkedList__enInsertNext_WithData(DLinkedList_t* pstList,
                                            DLinkedListItem_t* pstPreviousItemArg,
                                            DLinkedListItem_t* pstNewItem,
                                            void* pvData);
DLinkedList_nSTATUS DLinkedList__enInsertNext(DLinkedList_t* pstList,
                                            DLinkedListItem_t* pstPreviousItemArg,
                                            DLinkedListItem_t* pstNewItem);
DLinkedListItem_t* DLinkedList__pstInsertNext_WithData(DLinkedList_t* pstList,
                                             DLinkedListItem_t* pstPreviousItemArg,
                                             void* pvData);
DLinkedListItem_t* DLinkedList__pstInsertNext(DLinkedList_t* pstList,
                                             DLinkedListItem_t* pstPreviousItemArg);




DLinkedList_nSTATUS DLinkedList__enInsertPrevious_WithData(DLinkedList_t* pstList,
                                                       DLinkedListItem_t* pstNextItemArg,
                                                       DLinkedListItem_t* pstNewItem,
                                                       void* pvData);
DLinkedList_nSTATUS DLinkedList__enInsertPrevious(DLinkedList_t* pstList,
                                                       DLinkedListItem_t* pstNextItemArg,
                                                       DLinkedListItem_t* pstNewItem);
DLinkedListItem_t* DLinkedList__pstInsertPrevious_WithData(DLinkedList_t* pstList,
                                                        DLinkedListItem_t* pstNextItemArg,
                                                        void* pvData);
DLinkedListItem_t* DLinkedList__pstInsertPrevious(DLinkedList_t* pstList,
                                                        DLinkedListItem_t* pstNextItemArg);



DLinkedList_nSTATUS  DLinkedList__enInsertPreviousLastItemRead_WithData(DLinkedList_t* pstList,
                                           DLinkedListItem_t* pstNewItem,
                                           void* pvData);
DLinkedList_nSTATUS  DLinkedList__enInsertPreviousLastItemRead(DLinkedList_t* pstList,
                                           DLinkedListItem_t* pstNewItem);
DLinkedListItem_t*  DLinkedList__pstInsertPreviousLastItemRead_WithData(DLinkedList_t* pstList, void* pvData);
DLinkedListItem_t*  DLinkedList__pstInsertPreviousLastItemRead(DLinkedList_t* pstList);




DLinkedList_nSTATUS  DLinkedList__enInsertNextLastItemRead_WithData(DLinkedList_t* pstList,
                                           DLinkedListItem_t* pstNewItem,
                                           void* pvData);
DLinkedList_nSTATUS  DLinkedList__enInsertNextLastItemRead(DLinkedList_t* pstList,
                                           DLinkedListItem_t* pstNewItem);
DLinkedListItem_t*  DLinkedList__pstInsertNextLastItemRead_WithData(DLinkedList_t* pstList, void* pvData);
DLinkedListItem_t*  DLinkedList__pstInsertNextLastItemRead(DLinkedList_t* pstList);





DLinkedList_nSTATUS  DLinkedList__enInsertAtTail_WithData(DLinkedList_t* pstList,
                                           DLinkedListItem_t* pstNewItem,
                                           void* pvData);
DLinkedList_nSTATUS  DLinkedList__enInsertAtTail(DLinkedList_t* pstList,
                                           DLinkedListItem_t* pstNewItem);
DLinkedListItem_t*  DLinkedList__pstInsertAtTail_WithData(DLinkedList_t* pstList,
                                                    void* pvData);
DLinkedListItem_t*  DLinkedList__pstInsertAtTail(DLinkedList_t* pstList);




DLinkedList_nSTATUS DLinkedList__enInsertAtHead_WithData(DLinkedList_t* pstList,
                                            DLinkedListItem_t* pstNewItem,
                                            void* pvData);
DLinkedList_nSTATUS DLinkedList__enInsertAtHead(DLinkedList_t* pstList,
                                            DLinkedListItem_t* pstNewItem);
DLinkedListItem_t* DLinkedList__pstInsertAtHead_WithData(DLinkedList_t* pstList, void* pvData);
DLinkedListItem_t* DLinkedList__pstInsertAtHead(DLinkedList_t* pstList);



DLinkedList_nSTATUS  DLinkedList__enInsertPos_WithData(DLinkedList_t* pstList,
                                            DLinkedListItem_t* pstNewItem,
                                             uint32_t u32Position,
                                             void* pvData);
DLinkedList_nSTATUS  DLinkedList__enInsertPos(DLinkedList_t* pstList,
                                            DLinkedListItem_t* pstNewItem,
                                             uint32_t u32Position);
DLinkedListItem_t*  DLinkedList__pstInsertPos_WithData(DLinkedList_t* pstList,
                                                     uint32_t u32Position, void* pvData);
DLinkedListItem_t*  DLinkedList__pstInsertPos(DLinkedList_t* pstList,
                                                     uint32_t u32Position);
#endif /* XUTILS_DATASTRUCTURE_DOUBLELINKEDLIST_XHEADER_DLINKEDLIST_INSERT_H_ */
