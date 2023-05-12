/*****************************************
*																				 *
*	文件夹: 02_LinearList/03_MergeSqList	 * 
*																				 *							
*	文件名: MergeSqList.c									 *
*																				 *
*	算  法:	2.2、2.7		   		             *
*									                       *
*****************************************/

#ifndef MERGESQLIST_C
#define MERGESQLIST_C

#include "MergeSqList.h"		/* 02 线性表 */

/* 算法2.2 */
void MergeSqList_1(SqList La, SqList Lb, SqList *Lc)
{
	//已知线性表La和Lb中的数据元素按值非递减排列。
	//归并La和Lb得到新的线性表Lc，Lc的数据元素也按值非递减排列。
	int La_len,Lb_len;
	LElemType_Sq ai, bj;
	InitList_Sq(Lc);
	int i, j, k;
	i = j = 1; k = 0;
	
	La_len = ListLength_Sq(La);
	Lb_len = ListLength_Sq(Lb);
	
	while((i<=La_len) && (j<=Lb_len))	//La和Lb均非空 
	{
		GetElem_Sq(La,i,&ai);
		GetElem_Sq(Lb,j,&bj);
		if(ai <= bj)
		{
			ListInsert_Sq(Lc,++k,ai);
			++i;			
		}
		else
		{
			ListInsert_Sq(Lc,++k,bj);
			++j;
		}		
	}
	while(i <= La_len)
	{
		GetElem_Sq(La,i++,&ai);
		ListInsert_Sq(Lc,++k,ai);
	}
	while(j <= Lb_len)
	{
		GetElem_Sq(Lb,j++,&bj);
		ListInsert_Sq(Lc,++k,bj);
	}
}

/* 算法2.7 */
void MergeSqList_2(SqList La, SqList Lb, SqList *Lc)
{
	//已知线性表La和Lb中的数据元素按值非递减排列。
	//归并La和Lb得到新的线性表Lc，Lc的数据元素也按值非递减排列。
	LElemType_Sq *pa, *pb, *pc, *pa_last, *pb_last;
	pa = La.elem;
	pb = Lb.elem; 
	pc = Lc->elem = (LElemType_Sq *)malloc(LIST_INIT_SIZE*sizeof(LElemType_Sq));
	if(!Lc->elem)
		exit(OVERFLOW);		//存储分配失败
	(*Lc).length = La.length + Lb.length; 
	(*Lc).listsize = LIST_INIT_SIZE;
	pa_last = La.elem + La.length -1;
	pb_last = Lb.elem + Lb.length -1;
	while(pa <= pa_last && pb <= pb_last)
	{
		//归并
		if(*pa <= *pb)
			*pc++ = *pa++;
		else
			*pc++ = *pb++; 
	}
	while(pa <= pa_last)	//插入La的剩余元素 
		*pc++ = *pa++;
	while(pb <= pb_last)	//插入Lb的剩余元素
		*pc++ = *pb++;		
}


#endif
