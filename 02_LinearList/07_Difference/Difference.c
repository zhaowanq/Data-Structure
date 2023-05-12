/******************************************
*									                        *
*	文件夹:02_LinearList/07_Difference		  * 
*									   	                    *							
*	文件名: Difference.c	 		   	          *
*									  	                    *
*	内  容:	算法2.17					              *
*									   	                    *
******************************************/

#ifndef DIFFERENCE_C
#define DIFFERENCE_C

#include "Difference.h"


/* 算法2.17：在一维数组中建立集合(A-B)∪(B-A)。 */
void difference(SLinkList *S, LElemType_S A[] ,int len_A, LElemType_S B[], int len_B)
{
	//依次输入集合A和B的元素，在一维数组SPACE中建立表示集合(A-B)∪(B-A)
	//的静态链表，S为其头指针。假设备用空间足够大，SPACE[0].cur为其头指针
	int r, p, k;
	int i, j;
	LElemType_S b;
	InitSpace_SL();		//初始化备用空间
	*S = Malloc_SL();	//生成S的头结点
	r = *S;				//r指向S的当前最后结点
	SPACE[r].cur = 0;
	
	for(j=1; j<=len_A;j++)		//建立集合A的链表 
	{
		i = Malloc_SL();		//分配结点 
		SPACE[i].data = A[j-1];		//输入A的元素值 
		SPACE[r].cur = i;			//插入到表尾 
		r = i;	
	}
	SPACE[r].cur = 0;
	
	for(j=1; j<=len_B; j++)		 
	{				//依次输入B的元素，若不在当前表中，则插入，否则删除。
		b = B[j-1];
		p = *S;
		k = SPACE[*S].cur;		//k指向集合A中第一个结点
		
		while(k!=SPACE[r].cur && SPACE[k].data!=b)	//在当前表中查找
		{
			p = k;
			k = SPACE[k].cur;
		}
		if(k == SPACE[r].cur)	//当前表中不存在该元素，插入在r所指结点之后，且r的位置不变(那就要保证B中无重复元素) 
		{
			i = Malloc_SL();
			SPACE[i].data = b;
			SPACE[i].cur = SPACE[r].cur;
			SPACE[r].cur = i;	
		}
		else					//该元素已在表中，删除之 
		{
			SPACE[p].cur = SPACE[k].cur;
			Free_SL(k);
			if(r==k)
				r = p;
		}
	}	
}

#endif 
