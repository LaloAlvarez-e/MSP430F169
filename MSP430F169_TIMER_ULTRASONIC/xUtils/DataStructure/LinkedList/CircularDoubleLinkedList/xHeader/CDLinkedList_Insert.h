/**
 *
 * @file CDLinkedList_Insert.h
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
#ifndef XUTILS_DATASTRUCTURE_CIRCULARDOUBLELINKEDLIST_XHEADER_CIRCULARDLINKEDLIST_INSERT_H_
#define XUTILS_DATASTRUCTURE_CIRCULARDOUBLELINKEDLIST_XHEADER_CIRCULARDLINKEDLIST_INSERT_H_

#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/Intrinsics/xHeader/CDLinkedList_Struct.h>

CDLinkedList_nSTATUS CDLinkedList__enInsertNext_WithData(CDLinkedList_t* pstList,
                                                      CDLinkedListItem_t* pstItem,
                                                      CDLinkedListItem_t* pstNewItem,
                                                      void* pvData);
CDLinkedList_nSTATUS CDLinkedList__enInsertNext(CDLinkedList_t* pstList,
                                                      CDLinkedListItem_t* pstItem,
                                                      CDLinkedListItem_t* pstNewItem);
CDLinkedListItem_t* CDLinkedList__pstInsertNext_WithData(CDLinkedList_t* pstList, CDLinkedListItem_t* pstItem, void* pvData);
CDLinkedListItem_t* CDLinkedList__pstInsertNext(CDLinkedList_t* pstList, CDLinkedListItem_t* pstItem);


CDLinkedList_nSTATUS CDLinkedList__enInsertPrevious_WithData(CDLinkedList_t* pstList,
                                                      CDLinkedListItem_t* pstItem,
                                                      CDLinkedListItem_t* pstNewItem,
                                                      void* pvData);
CDLinkedList_nSTATUS CDLinkedList__enInsertPrevious(CDLinkedList_t* pstList,
                                                      CDLinkedListItem_t* pstItem,
                                                      CDLinkedListItem_t* pstNewItem);
CDLinkedListItem_t* CDLinkedList__pstInsertPrevious_WithData(CDLinkedList_t* pstList, CDLinkedListItem_t* pstItem, void* pvData);
CDLinkedListItem_t* CDLinkedList__pstInsertPrevious(CDLinkedList_t* pstList, CDLinkedListItem_t* pstItem);



CDLinkedList_nSTATUS  CDLinkedList__enInsertPreviousLastItemRead_WithData(CDLinkedList_t* pstList,
                                           CDLinkedListItem_t* pstNewItem,
                                           void* pvData);
CDLinkedList_nSTATUS  CDLinkedList__enInsertPreviousLastItemRead(CDLinkedList_t* pstList,
                                           CDLinkedListItem_t* pstNewItem);
CDLinkedListItem_t*  CDLinkedList__pstInsertPreviousLastItemRead_WithData(CDLinkedList_t* pstList, void* pvData);
CDLinkedListItem_t*  CDLinkedList__pstInsertPreviousLastItemRead(CDLinkedList_t* pstList);



CDLinkedList_nSTATUS  CDLinkedList__enInsertNextLastItemRead_WithData(CDLinkedList_t* pstList,
                                           CDLinkedListItem_t* pstNewItem,
                                           void* pvData);
CDLinkedList_nSTATUS  CDLinkedList__enInsertNextLastItemRead(CDLinkedList_t* pstList,
                                           CDLinkedListItem_t* pstNewItem);
CDLinkedListItem_t*  CDLinkedList__pstInsertNextLastItemRead_WithData(CDLinkedList_t* pstList, void* pvData);
CDLinkedListItem_t*  CDLinkedList__pstInsertNextLastItemRead(CDLinkedList_t* pstList);


CDLinkedList_nSTATUS  CDLinkedList__enInsertAtTail_WithData(CDLinkedList_t* pstList,
                                           CDLinkedListItem_t* pstNewItem,
                                           void* pvData);
CDLinkedList_nSTATUS  CDLinkedList__enInsertAtTail(CDLinkedList_t* pstList,
                                           CDLinkedListItem_t* pstNewItem);
CDLinkedListItem_t*  CDLinkedList__pstInsertAtTail_WithData(CDLinkedList_t* pstList, void* pvData);
CDLinkedListItem_t*  CDLinkedList__pstInsertAtTail(CDLinkedList_t* pstList);



CDLinkedList_nSTATUS CDLinkedList__enInsertAtHead_WithData(CDLinkedList_t* pstList,
                                            CDLinkedListItem_t* pstNewItem,
                                            void* pvData);
CDLinkedList_nSTATUS CDLinkedList__enInsertAtHead(CDLinkedList_t* pstList,
                                            CDLinkedListItem_t* pstNewItem);
CDLinkedListItem_t*  CDLinkedList__pstInsertAtHead_WithData(CDLinkedList_t* pstList, void* pvData);
CDLinkedListItem_t*  CDLinkedList__pstInsertAtHead(CDLinkedList_t* pstList);




CDLinkedList_nSTATUS  CDLinkedList__enInsertPos_WithData(CDLinkedList_t* pstList,
                                           CDLinkedListItem_t* pstNewItem,
                                            uint32_t u32Position,
                                            void* pvData);
CDLinkedList_nSTATUS  CDLinkedList__enInsertPos(CDLinkedList_t* pstList,
                                           CDLinkedListItem_t* pstNewItem,
                                            uint32_t u32Position);
CDLinkedListItem_t*  CDLinkedList__pstInsertPos_WithData(CDLinkedList_t* pstList, uint32_t u32Position, void* pvData);
CDLinkedListItem_t*  CDLinkedList__pstInsertPos(CDLinkedList_t* pstList, uint32_t u32Position);


CDLinkedList_nSTATUS  CDLinkedList__enInsertInDescendingOrderByValue(CDLinkedList_t* pstList,
                                           CDLinkedListItem_t* pstNewItem);

CDLinkedList_nSTATUS  CDLinkedList__enInsertInAscendingOrderByValue(CDLinkedList_t* pstList,
                                           CDLinkedListItem_t* pstNewItem);
#endif /* XUTILS_DATASTRUCTURE_CIRCULARDOUBLELINKEDLIST_XHEADER_CIRCULARDLINKEDLIST_INSERT_H_ */
