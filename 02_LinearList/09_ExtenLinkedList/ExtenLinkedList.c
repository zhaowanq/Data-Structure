/**********************************************
*									       	                    *
*	文件夹: 02_LinearList/09_ExtenLinkedList    * 
*									   		                      *							
*	文件名: ExtenLinkedList.c 		  		        *
*								  	 		                      *
*	内  容:	算法 2.20						                *
*									   		                      *
**********************************************/

#ifndef EXTENLINKEDLIST_C
#define EXTENLINKEDLIST_C

#include "ExtenLinkedList.h"		/*02 线性表*/

/*(01)分配由p指向e的结点。*/
Status MakeNode_E(Link *p, LElemType_E e)
{
	*p = (Link)malloc(sizeof(ELNode));		//申请结点空间
	if(!(*p))
		exit(OVERFLOW);
	
	(*p)->data = e;
	(*p)->next = NULL;
	
	return OK; 
}

/*(02)释放p指向的结点。*/
void FreeNode_E(Link *p)
{
	free(*p);
	(*p) = NULL;	
}

/*(03)初始化一个空的线性链表。*/
Status InitList_E(ELinkList *L)
{
	Link p;
	
	p = (Link)malloc(sizeof(ELNode));		//申请头结点 
	if(!p)
		exit(OVERFLOW);
	p->next = NULL;
	
	(*L).head = (*L).tail = p;				//空链表，头指针和尾指针都指向头结点 
	(*L).len = 0;
	
	return OK;
}

/*(04)重置线性链表L为空。*/
void ClearList_E(ELinkList *L)
{
	Link p, q;
	
	p = (*L).head->next;
	
	while(p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	
	(*L).head->next = NULL;
	(*L).tail = (*L).head;
	(*L).len = 0;
}

/*(05)销毁线性链表L。*/
void DestroyList_E(ELinkList *L)
{
	ClearList_E(L);
	free((*L).head);
	(*L).head = (*L).tail = NULL;
	
}

/*(06)h指向L中的一个结点，将h当做头结点，将s插入到“第一个结点”之前。*/
void InsFirst_E(ELinkList *L, Link h, Link s)
{
	s->next = h->next;
	h->next = s;
	
	if(h==(*L).tail)
		(*L).tail = h->next;
		
	(*L).len++;
}

/*(07)h指向L中的一个结点，将h当做头结点，删除“第一个结点”，并用q接收。*/
Status DelFirst_E(ELinkList *L, Link h, Link *q)
{
	*q = h->next;
	
	if(*q)				//h不是最后一个结点 
	{
		h->next = (*q)->next;		
		if(!h->next)				//h后只有一个结点
			(*L).tail = h;
			
		(*L).len--;				//并不释放被删结点所占空间
		
		return OK;
	}
	
	return ERROR;
}

/*(08)将s所指向的一串结点链接在L的最后一个结点之后，并改变L的尾指针。*/
void Append_E(ELinkList *L, Link s)
{
	int count;
	
	count = 0;
	
	(*L).tail->next = s;
	
	while(s)					//考虑s为空的情况
	{
		(*L).tail = s;
		s = s->next;
		count++;	
	}
		
	(*L).len+=count;
}

/*(09)删除L的尾结点并用q接收，改变尾指针。*/
Status Remove_E(ELinkList *L, Link *q)
{
	if(!(*L).len)
	{
		*q = NULL;
		return ERROR;
	}
	
	*q = (*L).tail;
	
	(*L).tail = PriorPos_E(*L,(*q));
	(*L).tail->next = NULL;			//将新尾结点的next域置为空。 
	(*L).len--;
	
	//FreeNode_E(q);		//注意内存泄露，这里不予考虑。 
			 
	 return OK;
}

/*(10)将s所指向结点插入p所指向结点之前，并将p指向新插入的结点。*/
void InsBefore_E(ELinkList *L, Link *p, Link s)
{
	Link q;
	
	q = PriorPos_E(*L,*p);		//寻找p的前驱
	if(!q)						//首结点的前驱为头结点 
		q = (*L).head;
	
	s->next = *p;
	q->next = s;
	*p = s;
	
	(*L).len++;
}

/*(11)将s所指向结点插入p所指向结点之后，并将p指向新插入的结点。*/
void InsAfter_E(ELinkList *L, Link *p, Link s)
{
	if(*p==(*L).tail)		//若在尾结点后插入s，需要调整尾指针
		(*L).tail = s;

	s->next = (*p)->next;
	(*p)->next = s;
	*p = s;
		 
	(*L).len++;
}

/*(12)用e更新p指向的结点中的值。*/
void SetCurElem_E(Link p, LElemType_E e)
{
	p->data = e;
}

/*(13)返回p结点中的值。*/
LElemType_E GetCurElem_E(Link p)
{
	return p->data;
}

/*(14)判空。*/
Status ListEmpty_E(ELinkList L)
{
	if(L.len)
		return FALSE;
	else
		return TRUE;	
}

/*(15)求长。*/
int ListLength_E(ELinkList L)
{
	return L.len;
}

/*(16)以指针形式返回L头结点的位置。*/
PositionPtr GetHead_E(ELinkList L)
{
	return L.head;
}

/*(17)以指针形式返回L尾结点的位置。*/
PositionPtr GetLast_E(ELinkList L)
{
	return L.tail;
}

/*(18)返回p指向的结点的前驱。*/
PositionPtr PriorPos_E(ELinkList L, Link p)
{
	Link q;
	
	q = L.head->next;
	if(q==p)				//首结点无前驱
		return NULL;
	else
	{
		while(q->next!=p)	//寻找p的前驱
			q = q->next;
		
		return q;
	}	
}

/*(19)返回p指向的结点的后继。*/
PositionPtr NextPos_E(Link p)
{								//如果p是最后一个结点，那么p->next就是NULL，
	return p->next;				//也就是说，最后一个结点无后继。 
}						

/*(20)将*p指向L中第i个结点，i=0时为头结点。*/
Status LocatePos_E(ELinkList L, int i, Link *p)
{
	int count;
	
	count = 0;
	*p = L.head;
	
	if(i<0 || i>L.len)
		return ERROR;
		
	while(count<i)
	{
		count++;
		*p = (*p)->next;
	}
	
	return OK;	
}

/*(21)返回L中指向第一个与e满足Compare关系的元素的指针。*/
PositionPtr LocateElem_E(ELinkList L, LElemType_E e, Status(Compare)(LElemType_E e, LElemType_E data))
{
	Link p;
	
	p = L.head->next;
	
	while(p && !(Compare(e, p->data)))
		p = p->next;
	
	return p;		
} 

/*(22)访问。*/
Status ListTraverse_E(ELinkList L, void(Visit)(LElemType_E))
{
	Link p;
	
	p = L.head->next;
	
	while(p)
	{
		Visit(p->data);
		p = p->next;
	}
	return OK;	
}

/*(23)算法2.20：在L第i个元素之前插入e。*/
/* 算法2.9的改写 */
Status ListInsert_L_E(ELinkList *L, int i, LElemType_E e)
{
	Link h, s;
	
	if(!LocatePos_E(*L,i-1,&h))		//定位第i-1个结点位置
		return ERROR;				//i值不合法
	if(!MakeNode_E(&s,e))			//创建结点 
		return ERROR;				//内存申请失败
	InsFirst_E(L, h, s);	//对于从第i个结点开始的链表，第i-1个结点是它的头结点
	
	return OK; 
}

/*(24)删除L第i个位置的元素，并用e接收。*/
Status ListDelete_L_E(ELinkList *L, int i, LElemType_E *e)
{
	Link p, q;
	
	if(i<1 || i>(*L).len)
		return ERROR;
	
	LocatePos_E(*L, i-1, &p);	//p不可能指向最后一个元素，因为上面对i进行限制。 
	DelFirst_E(L, p, &q);		//p最多指向最后一个元素的前一个元素。 
	
	*e = q->data;
	free(q);
	q = NULL;
	
	return  OK;
	
}

#endif
