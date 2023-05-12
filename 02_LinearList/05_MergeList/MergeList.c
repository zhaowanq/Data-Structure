/******************************************
*									                        *
*	文件夹: 02_LinearList/05_MergeList		  * 
*									   	                    *							
*	文件名: MergeList.c 		   		          *
*									  	                    *
*	内  容:	算法2.12		  			            *
*									   	                    *
******************************************/

#ifndef MERGELIST_C
#define MERGELIST_C

#include "MergeList.h"

/* (01)算法2.12：C=A+B，且保持元素相对位置不变。
	Lc利用La的头结点，Lb中结点均插入新链表Lc中。*/
void MergeList_L(LinkList La, LinkList *Lb, LinkList *Lc)
{
	//已知单链线性表La和Lb的元素按值非递减排列。
	//归并La和Lb得到新的单链线性表Lc，Lc的元素也按值非递减排列。
	LinkList pa, pb, pc;
	
	pa = La->next;
	pb = (*Lb)->next;
	(*Lc) = pc = La;	//用La的头结点作为Lc的头结点
	
	while(pa && pb)
	{
		if(pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	
	pc->next = pa ? pa : pb;	//插入剩余段
	free(*Lb);					//释放Lb的头结点
	*Lb = NULL;	
}

#endif
