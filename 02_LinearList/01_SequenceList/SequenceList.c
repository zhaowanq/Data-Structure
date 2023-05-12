/******************************************
*									                        *
*	文件夹: 02_LinearList/01_SequenceList   * 
*									                        *
*	文件名: SequenceList.c			            *
*									                        *
*									                        *
******************************************/

#ifndef SEQUENCELIST_C
#define SEQUENCELIST_C

#include "SequenceList.h"

/* 初始化顺序表 */
Status InitList_Sq(SqList *L)
{
	(*L).elem = (LElemType_Sq*)malloc(LIST_INIT_SIZE*sizeof(LElemType_Sq));
	if (!(*L).elem)
		exit(OVERFLOW);		//分配内存失败
	(*L).length = 0;		//初始顺序表长度为0 
	(*L).listsize = LIST_INIT_SIZE;	 //顺序表初始内存的分配量
	
	return OK;
}

/* 判断顺序表L是否为空。 */ 
Status ListEmpty_Sq(SqList L)
{
	return 0== L.length ? TRUE : FALSE; 
}

/* 清空顺序表L */
void ClearList_Sq(SqList *L)
{
	L->length = 0;
}

/* 销毁顺序表L */
void DestroyList_Sq(SqList *L)
{
	free(L->elem);
	(*L).elem = NULL;		//释放内存后置空指针 
	(*L).length = 0;
	(*L).listsize = 0;
}

/* 返回顺序表L中元素个数。*/
int ListLength_Sq(SqList L)
{
	return L.length;
}

/* 用e接收顺序表L中第i个元素 */
Status GetElem_Sq(SqList L, int i, LElemType_Sq *e)
{
	if(i<1 || i>L.length)
		return FALSE;
	
	*e = *(L.elem+i-1);
	return TRUE;	
}

/* 返回顺序表L中首个与e满足Compare关系的元素位序。 */
int LocateElem_Sq(SqList L, LElemType_Sq e, Status (Compare)(LElemType_Sq e, LElemType_Sq data))
{
	int i; 
	for(i=0;i<L.length;i++)
	{
		if(Compare(e,L.elem[i]))
			return i+1;
	}
	if(i==L.length || i==0)
		return 0;			
}

/* 用pre_e接收cur_e的前驱 */
Status PriorElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *pre_e)
{
	int i=1;
	if(L.elem[0]!=cur_e)	// 第1个结点无前驱 
	{
		while(i<L.length)
		{
			if(L.elem[i] == cur_e)
			{
				*pre_e = L.elem[i-1];
				return OK;	
			}
			i++;
		}	
	}	
	return ERROR;
	
}
/* 用next_e接收cur_e的后继 */
Status NextElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *next_e)
{
	int i=0;
	if(L.elem[L.length-1]!=cur_e)	// 最后一个结点无后继 
	{
		while(i<L.length)
		{
			if(L.elem[i] == cur_e)
			{
				*next_e = L.elem[i+1];
				return OK;	
			}
			i++;
		}	
	}	
	return ERROR;	
}

/* 在顺序表L的第i个位置上插入e。 */
Status ListInsert_Sq(SqList *L, int i, LElemType_Sq e)
{
	LElemType_Sq *newbase;
	LElemType_Sq *p, *q;
	
 	if(i<1 || i>(*L).length+1)
		return ERROR;		//i值不合法
		
	if((*L).length >= (*L).listsize) 	//若存储空间已满，需开辟新空间
	{
		newbase = (LElemType_Sq *)realloc((*L).elem,((*L).listsize+LISTINCREMENT)*sizeof(LElemType_Sq));
		if(!newbase)
			exit(OVERFLOW);
			
		(*L).elem = newbase;
		(*L).listsize += LISTINCREMENT;	
	}
 	q = (*L).elem+i-1; 
	for(p=(*L).length-1+(*L).elem; p>=q; p--)
		*(p+1) = *p;
		
	*q = e;
	(*L).length++;		//表长增1 
	
	return OK;
}

/* 删除顺序表L的第i个元素，并将删除后的元素放入e中。 */
Status ListDelete_Sq(SqList *L, int i, LElemType_Sq *e)
{
	LElemType_Sq *p, *q;
	
 	if(i<1 || i>(*L).length)
		return ERROR;		//i值不合法
		
	p=(*L).elem+i-1;				//p指向待删除的元素
	*e = *p;			//保存
 	q = (*L).elem+(*L).length-1;	//q指向最后一个元素的位置 
  
	for(p=(*L).elem+i-1; p<q; p++)	
		*p = *(p+1);				//被删元素之后的元素左移
			
	(*L).length--;		//表长增1 
	
	return OK;	
}

/* 用Visit函数访问顺序表L */
Status ListTraverse_Sq(SqList L, void (Visit)(LElemType_Sq))
{
	for(int i = 0; i < L.length; i++)
		Visit(L.elem[i]);
	
	return OK;
}

#endif
