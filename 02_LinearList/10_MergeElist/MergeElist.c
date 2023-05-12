/****************************************
 *							                        *
 * 文件夹: 02_LinearList/10_MergeElist  *
 * 							                        *
 * 文件名: MergeEList.c                 *
 * 							                        *
 * 内  容: 算法2.21						          *
 *                                      *
 ****************************************/
 
#ifndef MERGEELIST_C
#define MERGEELIST_C

#include "MergeElist.h"			/*02 线性表*/

/*(01)算法2.21：La与Lb均非递减排列，将其归并为一个非递减排列的单链表Lc。*/
/*算法2.21有没有释放La和Lb的结点的内存。*/
Status MergeEList_L(ELinkList La, ELinkList Lb, ELinkList *Lc, int(Compare)(LElemType_E c1, LElemType_E c2))
{
	Link ha, hb, pa, pb, q;
	LElemType_E c1, c2;
	
	if(!InitList_E(Lc))
		return ERROR;
	
	ha = GetHead_E(La);		//ha和hb分别指向La和Lb的头结点 
	hb = GetHead_E(Lb);
	pa = NextPos_E(ha);		//pa和pb分别指向La和Lb中当前结点 
	pb = NextPos_E(hb);
	
	while(pa&&pb)
	{
		c1 = GetCurElem_E(pa);	//c1和c2为两表中当前比较元素 
		c2 = GetCurElem_E(pb);
		if(Compare(c1,c2) <= 0)
		{
			DelFirst_E(&La, ha, &q);
			//Append_E(Lc, q);		//这里不能用Append_E函数，否则会把整个La表链接到Lc表上，这里只要链接一个结点。
			InsFirst_E(Lc,(*Lc).tail,q); 
			pa = NextPos_E(ha);
		}
		else
		{
			DelFirst_E(&Lb, hb, &q);
			InsFirst_E(Lc,(*Lc).tail,q);
			pb = NextPos_E(hb);
		}
	}
	if(pa)
		Append_E(Lc, pa);		//链接La中剩余结点
	else
		Append_E(Lc, pb);		//链接Lb中剩余结点
		
	FreeNode_E(&ha);			//释放La和Lb的头结点 
	FreeNode_E(&hb);
	
	return OK; 
}

/*(02)比较c1、c2大小，返回c1-c2。*/
int Cmp(LElemType_E c1, LElemType_E c2)
{
	return c1-c2;
}

/*(03)按非降序序列创建元素个数为count的扩展单链表L。*/
Status CreateList_ascend(FILE *fp, ELinkList *L, int count)
{
	int i;
	LElemType_E e;
	
	InitList_E(L);
	if(!L)
		return ERROR;
	
	for(i=1; i<=count; i++)
	{
		Scanf(fp, "%d", &e);
		ListInsert_L_E(L, i, e);
	}
	
	return OK;	 
}


#endif
