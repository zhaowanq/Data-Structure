/**************************************************
*									        	                      *
*	文件夹: 02_LinearList/08_DualCycleLinkedList    * 
*									   			                        *							
*	文件名: DualCycleLinkedList.c 		   		        *
*									  	 		                        *
*	内  容:	算法2.18、2.19						              *
*									   			                        *
**************************************************/

#ifndef DUALCYCLELINKEDLIST_C
#define DUALCYCLELINKEDLIST_C

#include "DualCycleLinkedList.h"	/* 02 线性表 */

/*(01)初始化双链表L。*/
Status InitList_DuL(DuLinkList *L)		// L 实际上为(DuLNode **) 类型
{
	(*L) = (DuLinkList)malloc(sizeof(DuLNode));
		//printf("%#x\n",L);	// 输出 L 的内容 
		//printf("%#x\n",*L);	// 输出以 L 的内容为地址的那块内存单元中的内容
	if(!(*L))
		exit(OVERFLOW);
		
	(*L)->prior = (*L)->next = *L;
	
	return OK;	
}

/*(02)置空L。*/
Status ClearList_DuL(DuLinkList L)
{
	DuLinkList p;
	
	while(L->next!=L && L->prior!= L)
	{
		p = L->next;
		p->prior->next = p->next;
		p->next->prior = p->prior;
		free(p);
	}
	
	return OK;	
}

/*(03)销毁L。*/
void DestroyList_DuL(DuLinkList *L)
{
	ClearList_DuL(*L);
	
	free(*L);
	
	*L = NULL;
}

/*(04)判断L是否为空。*/
Status ListEmpty_DuL(DuLinkList L)
{
	if(L && L->next==L && L->prior==L) 
		return TRUE;
	else
		return FALSE;	
}

/*(05)返回L中元素个数。*/
int ListLength_DuL(DuLinkList L)
{
	DuLinkList p;
	int count;
	
	if(L)
	{
		p = L;			//p指向头结点 
		count = 0;
		
		while(p->next!=L)	//p没到表头 
		{
			count++;
			p = p->next;
		}
	}	
		
	return count;
}

/*(06)用e接收L中第i个结点的元素值。*/
Status GetElem_DuL(DuLinkList L, int i, LElemType_DC *e)
{
	DuLinkList p;
	
	if(!(p=GetElemPtr_DuL(L,i)))	//i值不合法	
		return ERROR;
	else
	{
		*e = p->data;
		return OK;
	}	
}

/*(07)返回L中第一个与e满足Compare关系的元素位序。*/
int LocateElem_DuL(DuLinkList L, LElemType_DC e, Status (Compare)(LElemType_DC, LElemType_DC))
{
	DuLinkList p;
	int count;
	
	if(L)
	{
		count=1;
		p = L->next;
		
		while(p!=L && (!Compare(e,p->data)))
		{
			p = p->next;
			count++;
		}
		
		if(p!=L)
			return count;
	}
	
	return 0;
}

/*(08)用pre_e接收cur_e的前驱。*/
Status PriorElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *pre_e)
{
	DuLinkList p;
	
	if(L)
	{
		p = L->next;
		
		while(p!=L && p->data!=cur_e)
			p = p->next;
		
		if(p!=L && p->prior!=L)		//第1个结点无前驱 
		{
			*pre_e = p->prior->data;
			return OK;
		}	
	}
	
	return ERROR;
}

/*(09)用next_e接收cur_e的后继。*/
Status NextElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *next_e)
{
	DuLinkList p;
	
	if(L)
	{
		p = L->next;
		
		while(p!=L && p->data!=cur_e)
			p = p->next;
		
		if(p!=L && p->next!=L)		//最后一个结点无后继 
		{
			*next_e = p->next->data;
			return OK;
		}	
	}
	
	return ERROR;
}

/*(10)返回L中指向第i个结点的指针。*/
DuLinkList GetElemPtr_DuL(DuLinkList L, int i)	//空表也返回NULL 
{
	DuLinkList p;
	int count;
	
	if(L && i>0)
	{
		count = 1;
		p = L->next;
		
		while(p!=L && count<i)
		{
			count++;
			p = p->next;
		}
		
		if(p!=L)
			return p;	
	}
	
	return NULL;
}

/*(11)算法2.18：在L第i个位置之前插入e。*/
/* 与课本双链表插入算法略有不同，根源在于GetElemP_DuL不同 */
Status ListInsert_DuL(DuLinkList L, int i, LElemType_DC e)
{
	// 在带头结点的双循环链表L中第i个位置之前插入元素e。
	// i的合法值为1<=i<=表长+1 
	DuLinkList p, s;
	
	if(i<1 || i>ListLength_DuL(L)+1)	//先对i做出限制
		return ERROR;
	
	p = GetElemPtr_DuL(L,i);		//确定第i个结点指针
	if(!p)							//此处若p=NULL，说明i = ListLength_DuL(L)+1
		p = L;						//令p指向头指针
	
	s = (DuLinkList)malloc(sizeof(DuLNode));
	if(!s)
		exit(OVERFLOW); 
	s->data = e;
	
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	
	return OK;
}

/*(12)算法2.19：删除L第i个位置的值，并用e接收。*/
Status ListDelete_DuL(DuLinkList L, int i, LElemType_DC *e)
{
	DuLinkList p, s;
	
	if(!(p=GetElemPtr_DuL(L,i)))	//i值不合法	
		return ERROR;
	
	*e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	
	free(p);
	p = NULL; 
	
	return OK;
}

/*(13)用Visit函数访问L。*/
void ListTraverse_DuL(DuLinkList L, void(Visit)(LElemType_DC))
{
	DuLinkList p;
	
	p = L->next;		//p指向首结点，正向访问链表
	
	while(p!=L)
	{
		Visit(p->data);
		p = p->next;
	}
}

#endif 
