/**********************************************
*									                            *
*	文件夹: 02_LinearList/04_SinglyLinkedList   * 
*									   		                      *							
*	文件名: SinglyLinkedList.c 		   		        *
*									  	 	                      *
*	算  法: 2.8、2.9、2.10、2.11		   	        *
*									   		                      *
**********************************************/

#ifndef SINGLYLINKEDLIST_C
#define SINGLYLINKEDLIST_C

#include "SinglyLinkedList.h"		/* 02 线性表 */

/* (01)初始化单链表L */
Status InitList_L(LinkList *L)		// L 实际上为(LNode **) 类型
{
	(*L) = (LinkList)malloc(sizeof(LNode));
		//printf("%#x\n",L);	// 输出 L 的内容 
		//printf("%#x\n",*L);	// 输出以 L 的内容为地址的那块内存单元中的内容
	if(!(*L))
		exit(OVERFLOW);
	(*L)->next = NULL;
	
	return OK;
}

/* (02)置空单链表L，头结点保留。 */
Status ClearList_L(LinkList L)
{
	LinkList pre, p;
	
	if(!L)
		return ERROR;
	
	pre = L->next;
	while(pre)		//用pre依次释放每一个结点，释放之前 
	{				//将即将释放的结点的指针域赋给p 
		p = pre->next;
		free(pre);
		pre = p;
	}
	
	L->next = NULL;
	
	return OK;
}

/* (03)销毁单链表L，连同头结点一起销毁。*/
void DestroyList_L(LinkList *L)
{
	LinkList p = *L;
	
	while(p)
	{
		p = (*L)->next;
		free(*L);
		(*L) = p;
	}
}

/* (04)判断单链表L是否为空 */
Status ListEmpty_L(LinkList L)
{
	if(L!=NULL && L->next==NULL)	//链表存在且只有头结点
		return TRUE;
	else
		return FALSE;
}

/* (05)返回单链表L中元素个数。*/
int ListLength_L(LinkList L)
{
	int i;
	LinkList p;
	
	if(L)
	{
		i=0;
		p = L->next;
		while(p)
		{
			i++;
			p = p->next;
		}		
	}
	
	return i;	
}

/* (06)算法2.8：用e接收单链表L中第i个元素。*/
Status GetElem_L(LinkList L, int i, LElemType_L *e)
{
	// L为带头结点的单链表的头指针。
	// 当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR 
	LinkList p;
	int j;
	
	p = L->next;
	j = 1;	// 初始化，p指向第一个结点，j为计数器 
	
	while(p && j<i)		//顺指针向后查找，直到p指向第i个元素或p为空 
	{
		p = p->next;
		++j;	
	}
	if(!p || j>i)
		return ERROR;	//第i个元素不存在 
	*e = p->data;		//取第i个元素
	 
	return OK;				
}

/* (07)返回单链表L中第一个与e满足Compare关系的元素位序。*/
int LocateElem_L(LinkList L, LElemType_L e, Status(Compare)(LElemType_L,LElemType_L))
{
	LinkList p;
	int j;
	
	j = 1;
	p = L->next;
	while(p && (!Compare(e,p->data)))
	{
		p = p->next;
		++j;	
	}
	if(p)
		return j;
	else
		return 0;	
}

/* 银行排队算法中，此处两个函数不能直接使用，原因是结构不能直接比较 */
#ifndef BANKQUEUING_C

/* (08)用pre_e接收cur_e的前驱。*/
Status PriorElem_L(LinkList L, LElemType_L cur_e, LElemType_L *pre_e)
{
	LinkList p, suc;
	
	if(L)
	{
		p = L->next;
		
		if(p->data != cur_e)	//第1个结点无前驱
		{
			while(p->next)		//若p结点有后继
			{
				suc = p->next;
				if(suc->data == cur_e)
				{
					*pre_e = p->data;
					return OK;
				}
				p = suc;
			} 
		} 
	}
		
	return ERROR; 
}

/* (09)用next_e接收cur_e的后继。*/
Status NextElem_L(LinkList L, LElemType_L cur_e, LElemType_L *next_e)
{
	LinkList p, suc;
	
	if(L)
	{
		p = L->next;
		
		while(p && p->next)	
		{
			suc = p->next;
			if(p->data == cur_e)
			{
				*next_e = suc->data;
				return OK;
			}
			p = suc;
		} 
		 
	}
		
	return ERROR;
}

#endif

/* (10)算法2.9：在单链表L第i个位置之前插入e。 */
Status ListInsert_L(LinkList L, int i, LElemType_L e)
{
	LinkList p, s;
	int j;
	
	p = L;
	j = 0;
	
	while(p && j<i-1)	//寻找第i-1个结点 
	{
		p = p->next;
		++j; 
	}
	
	if(!p || j>i-1)
		return ERROR;
	
	s = (LinkList)malloc(sizeof(LNode));
	if(!s)
		exit(ERROR);
	s->data = e;
	s->next = p->next;
	p->next = s;
	
	return OK;
}

/* (11)算法2.10：删除单链表L第i个位置的值，并用e接收。 */
Status ListDelete_L(LinkList L, int i, LElemType_L *e)
{
	LinkList p, q;
	int j;
	
	p = L;
	j = 1;
	
	while(p->next && j<i)		//寻找第i个结点，并令p指向其前驱
	{
		p = p->next;
		++j;	
	}
	if(!(p->next) || j>i)
		return ERROR;		//删除位置不合理
		
	q = p->next;
	p->next = q->next;		//删除并释放结点
	*e = q->data;
	free(q);
	
	return OK; 
}

/* (12)用Visit函数访问单链表L。*/
Status ListTraverse_L(LinkList L, void(Visit)(LElemType_L))
{
	LinkList p;
	
	if(!L)
		return ERROR;
	else
		p = L->next;
	while(p)
	{
		Visit(p->data);
		p = p->next;	
	}
	
	return OK;	
}

/* (13)算法2.11：头插法建立单链表L1（逆序输入）。 */
Status CreateList_HL(FILE *fp, LinkList *L, int n)
{
	//逆位序输入n个元素的值，建立带表头结点的单链线性表L1。
	int i;
	LinkList p;
	LElemType_L tmp;
	
	(*L) = (LinkList)malloc(sizeof(LNode));
	if(!(*L))
		exit(OVERFLOW);
	(*L)->next = NULL;		//建立头结点
		
	for(i=n; i>0; --i)
	{
		if(1 == Scanf(fp, "%d",&tmp))
		{
			p = (LinkList)malloc(sizeof(LNode));	//生成新结点
			if(!p)
				exit(OVERFLOW);
			p->data = tmp;				//录入数据	 
			p->next = (*L)->next;		//插入到表头 
			(*L)->next = p; 
		}
		else
			return ERROR; 
	}
	
	return OK;
}

/* (14)尾插法建立单链表L2（顺序输入）。 */
Status CreateList_TL(FILE *fp, LinkList *L, int n)
{
	//顺序输入n个元素的值，建立带表头结点的单链线性表L2。
	int i;
	LinkList p, q;
	LElemType_L tmp;
	
	(*L) = (LinkList)malloc(sizeof(LNode));
	if(!(*L))
		exit(OVERFLOW);
	(*L)->next = NULL;		//建立头结点
			
	for(i=n; i>0; --i)
	{
		if(1 == Scanf(fp, "%d",&tmp))
		{
			//寻找尾结点
			p = *L;
			while(p->next)
			{
				p = p->next;		
			}
			
			q = (LinkList)malloc(sizeof(LNode));	//生成新结点
			if(!q)
				exit(OVERFLOW);
			q->data = tmp;				//录入数据	 
			q->next = p->next;			//插入到表尾 
			p->next = q;
		}
		else
			return ERROR; 
	}
	
	return OK;
}


#endif
