/*****************************************
*                                        *
*	文件夹: 02_LinearList/01_SequenceList  * 
*									                       *							
*	文件名: SequenceList.h                 *
*									                       *
*	内  容:	顺序表相关操作列表             *
*									                       *
*****************************************/

#ifndef SEQUENCELIST_H
#define SEQUENCELIST_H

#include <stdio.h>
#include <stdlib.h>		//提供malloc、realloc、free、exit原型
#include "../../01_Preface/Status.h"

/* 宏定义 */
#define LIST_INIT_SIZE 100		//顺序表存储空间的初始分配量 
#define LISTINCREMENT  10		//顺序表存储空间的分配增量

/* 顺序表类型定义 */
#ifndef LELEMTYPE_SQ
#define LELEMTYPE_SQ
typedef int LElemType_Sq;
#endif

typedef struct
{
	LElemType_Sq *elem;		//存储空间基址（指向第一个结点的指针） 
	int length;				//当前顺序表长度 
	int listsize;			//当前分配的存储容量 
}SqList;					//顺序表0号单元正常使用 
 
/* 顺序表操作的函数列表 */

/* 初始化空顺序表L。*/
Status InitList_Sq(SqList *L);

/*判断顺序表L是否为空。 */ 
Status ListEmpty_Sq(SqList L);

/* 清空顺序表L。 */
void ClearList_Sq(SqList *L);

/* 销毁顺序表L */
void DestroyList_Sq(SqList *L);

/* 返回顺序表L中元素个数。*/
int ListLength_Sq(SqList L);

/* 用e接收顺序表L中第i个元素 */
Status GetElem_Sq(SqList L, int i, LElemType_Sq *e);

/* 返回顺序表L中首个与e满足Compare关系的元素位序。 */
int LocateElem_Sq(SqList L, LElemType_Sq e, Status (Compare)(LElemType_Sq, LElemType_Sq));

/* 用pre_e接收cur_e的前驱 */
Status PriorElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *pre_e);

/* 用next_e接收cur_e的后继 */
Status NextElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *next_e);

/* 在顺序表L的第i个位置上插入e。 */
Status ListInsert_Sq(SqList *L, int i, LElemType_Sq e);

/* 删除顺序表L的第i个元素，并将删除后的元素放入e中。 */
Status ListDelete_Sq(SqList *L, int i, LElemType_Sq *e);

/* 用visit函数访问顺序表L。 */
Status ListTraverse_Sq(SqList L, void (Visit)(LElemType_Sq));

#endif 
