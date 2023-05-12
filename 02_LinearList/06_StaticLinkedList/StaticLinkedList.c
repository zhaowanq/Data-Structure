/********************************************
*									                          *
*	文件夹: 02_LinearList/06_StaticLinkedList * 
*									   	                      *							
*	文件名: StaticLinkedList.c 		   	        *
*									  	                      *
*	算  法:	 2.13、2.14、2.15、2.16		        *
*									   	                      *
********************************************/

#ifndef STATICLINKEDLIST_C
#define STATICLINKEDLIST_C

#include "StaticLinkedList.h"		/* 02 线性表 */

/*(01)算法2.14：将一维数组SPACE中各分量链成一个大的备用空间。*/
void InitSpace_SL()
{
	int i;
									//0号单元做备用空间的起始结点 
	for(i = 0; i < MAXSIZE-1; ++i)
		SPACE[i].cur = i+1;
	SPACE[MAXSIZE-1].cur = 0;
}

/*(02)算法2.15：为插入数据申请空间。*/
int Malloc_SL()
{
	//若备用空间链表非空，则返回分配的结点下标，否则返回0
	//这里比较抽象，可以画图有助于理解。
	//对系统而言，在备用链表中分配结点相当于备用链表中减少一个结点。
	//对使用者而言，相当于申请得到一个可用的新结点。
	int i;
	i = SPACE[0].cur;
	if(SPACE[0].cur)
	{
		SPACE[0].cur = SPACE[i].cur;	//将申请到的空间从备用空间中删去
		return i;						//返回新申请结点下标
	}
	else
		return 0;		//申请失败返回0
} 

/*(03)算法2.16：将下标为k的空闲结点回收。*/
void Free_SL(int k)
{	//本函数只管回收结点，不管原静态链表是否断链。 
	SPACE[k].cur = SPACE[0].cur;
	SPACE[0].cur= k;
}

/* (04)初始化静态链表，建立头结点。*/
Status InitList_SL(SLinkList *H)		//H为头结点指针
{
	*H = Malloc_SL();		//创建头结点
	if(!(*H))
		exit(OVERFLOW);		//“内存”已满
	
	SPACE[*H].cur = 0;		//头结点游标置为0 
		
	return OK;
}

/* (05)置空。*/
Status ClearList_SL(SLinkList H)
{
	int p;
	
	if(H)
	{
		p = SPACE[H].cur;	//p指向第一个结点
		while(p)			//从链表首结点开始删除
		{
			SPACE[H].cur = SPACE[p].cur;
			Free_SL(p);
			p = SPACE[H].cur;
		}
		
		return OK;
	}
	else
	{
		return ERROR;
	}
}

/*(06)销毁。*/
void DestroyList_SL(SLinkList *H)
{
	ClearList_SL(*H);
	Free_SL(*H);
	*H = 0;	
}

/*(07)判空。*/
Status ListEmpty_SL(SLinkList H)
{
	if(H && !SPACE[H].cur)
		return TRUE;
	else
		return FALSE;
}

/*(08)求长。*/
int ListLength_SL(SLinkList H)
{
	int p;
	int count;		//计数器 
	
	if(!H)				//静态链表不存在
		exit(OVERFLOW);
		
	p = SPACE[H].cur;
	count = 0;
	
	while(p)
	{
		count++;
		p = SPACE[p].cur;
	}
	
	return count;
}

/*(09)取值。*/
Status GetElem_SL(SLinkList H, int i, LElemType_S *e)
{
	int count, p;
	count = 0;
	
	if(!H || i<1 || i>MAXSIZE-2)
		return ERROR;
	
	p = H;
	
	while(p && count<i)
	{
		count++;
		p = SPACE[p].cur;	
	}
	if(p)
	{
		*e = SPACE[p].data;
		return OK;
	}
	else
		return ERROR;
}

/*(10)算法2.13：返回元素e的位序。*/
int LocateElem_SL(SLinkList H, LElemType_S e)
{
	int k, count;
	
	count = 1;
	if(H && SPACE[H].cur)
	{
		k = SPACE[H].cur;
		
		while(k && SPACE[k].data!=e)
		{
			count++;
			k = SPACE[k].cur;
		}
		
		if(k)
			return count;
	}
	
	return 0;
}

/*(11)前驱。*/
Status PriorElem_SL(SLinkList H, LElemType_S cur_e, LElemType_S *pre_e)
{
	LElemType_S p, suc;
	
	if(H)
	{
		p = SPACE[H].cur;
		
		if(p && SPACE[p].data!=cur_e)				//第一个结点无前驱 
		{
			while(SPACE[p].cur)				//若p结点有后继 
			{
				suc = SPACE[p].cur;			//suc指向p的后继
				if(SPACE[suc].data==cur_e)
				{
					*pre_e = SPACE[p].data;
					return OK;
				}
				p = suc;
			}			
		}	
	}

	return ERROR;
}

/*(12)后继。*/
Status NextElem_SL(SLinkList H, LElemType_S cur_e, LElemType_S *next_e)
{
	LElemType_S p, suc;
	
	if(H)
	{
		p = SPACE[H].cur;
		
		while(p && SPACE[p].cur)	
		{
			suc = SPACE[p].cur;
			if(SPACE[p].data == cur_e)
			{
				*next_e = SPACE[suc].data;
				return OK;
			}
			p = suc;
		} 
		 
	}
		
	return ERROR;
}

/*(13)插入。*/
Status ListInsert_SL(SLinkList H, int i, LElemType_S e)
{
	int count, k, p;
	
	if(!H)				//链表不存在 
		return ERROR;
		
	if(i>0)
	{
		count = 0;
		k = H;			//k指向头结点 
	
		while(k && count<i-1)		//寻找插入位置的前一个位置，存放在k中 
		{
			count++;
			k = SPACE[k].cur;			
		}
		
		if(k)					//找到了第i-1个元素的位置
		{
			p = Malloc_SL();
			if(!p)				//申请空间失败
				return ERROR;
								
			SPACE[p].data = e;		//插入元素e 
			SPACE[p].cur = SPACE[k].cur;
			SPACE[k].cur = p;
			
			return OK;
		}	
	}
	
	return ERROR;	
}

/*(14)删除第i个结点。*/
Status ListDelete_SL(SLinkList H, int i, LElemType_S *e)
{
	int count, k, p, q;
	
	if(!H)				//链表不存在 
		return ERROR;
		
	if(i>0)
	{
		count = 0;
		k = H;			//k指向头结点 
	
		while(k && count<i-1)		//寻找插入位置的前一个位置，存放在k中 
		{
			count++;
			k = SPACE[k].cur;			
		}
		
		if(k && SPACE[k].cur)					//找到了第i-1个元素的位置
		{
			q = SPACE[k].cur;
			*e = SPACE[q].data;
			SPACE[k].cur = SPACE[q].cur;
			Free_SL(k+1);
			
			return OK;
		}
		else
			return ERROR;	
	}
	
	return ERROR;	
}

/*(15)访问。*/
Status ListTraverse_SL(SLinkList H, void(Visit)(LElemType_S))
{
	int p;
	
	if(!H)				//静态链表不存在或为空
		return ERROR;
		
	p = SPACE[H].cur;
	
	while(p)
	{
		Visit(SPACE[p].data);
		p = SPACE[p].cur;
	}
	
	return OK;	
}

#endif
