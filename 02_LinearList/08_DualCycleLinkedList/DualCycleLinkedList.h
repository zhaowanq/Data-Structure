/**************************************************
*									        	                      *
*	文件夹: 02_LinearList/08_DualCycleLinkedList    * 
*									   			                        *							
*	文件名: DualCycleLinkedList.h 		   		        *
*									  	 		                        *
*	内  容:	双向循环链表相关操作列表			          *
*									   			                        *
**************************************************/

#ifndef DUALCYCLELINKEDLIST_H
#define DUALCYCLELINKEDLIST_H

#include <stdlib.h>					//提供malloc、realloc、free、exit原型
#include "../../01_Preface/Status.h"	/* 01 绪论 */

/* 双向循环链表类型定义 */
typedef int LElemType_DC;
typedef struct DuLNode
{
	LElemType_DC data;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode;
typedef DuLNode* DuLinkList;		//指向双循环链表结构的指针

/* 双循环链表函数列表 */
/*(01)初始化双链表L。*/
Status InitList_DuL(DuLinkList *L);

/*(02)置空L。*/
Status ClearList_DuL(DuLinkList L);

/*(03)销毁L。*/
void DestroyList_DuL(DuLinkList *L);

/*(04)判断L是否为空。*/
Status ListEmpty_DuL(DuLinkList L);

/*(05)返回L中元素个数。*/
int ListLength_DuL(DuLinkList L);

/*(06)用e接收L中第i个结点的元素值。*/
Status GetElem_DuL(DuLinkList L, int i, LElemType_DC *e);

/*(07)返回L中第一个与e满足Compare关系的元素位序。*/
int LocateElem_DuL(DuLinkList L, LElemType_DC e, Status (Compare)(LElemType_DC, LElemType_DC));

/*(08)用pre_e接收cur_e的前驱。*/
Status PriorElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *pre_e);

/*(09)用next_e接收cur_e的后继。*/
Status NextElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *next_e);

/*(10)返回L中指向第i个结点的指针。*/
DuLinkList GetElemPtr_DuL(DuLinkList L, int i);

/*(11)算法2.18：在L第i个位置之前插入e。*/
Status ListInsert_DuL(DuLinkList L, int i, LElemType_DC e);

/*(12)算法2.19：删除L第i个位置的值，并用e接收。*/
Status ListDelete_DuL(DuLinkList L, int i, LElemType_DC *e);

/*(13)用Visit函数访问L。*/
void ListTraverse_DuL(DuLinkList L, void(Visit)(LElemType_DC));

#endif 
