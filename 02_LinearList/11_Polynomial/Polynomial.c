/*****************************************
 *						                           *
 * 文件夹: 02_LinearList/11_Polynomial   *
 * 							                         *
 * 文件名: Polynomial.c                  *
 * 							                         *
 * 内  容: 算法2.22、2.23		             *
 *                                       *
 *****************************************/
 
#ifndef POLYNOMIAL_C
#define POLYNOMIAL_C

#include "Polynomial.h"


/*(01)算法2.22：创建项数为m的一元多项式。*/
void CreatPolyn_P(FILE *fp, Polynomial *P, int m)
{
	PositionPtr h;
	int i;
	ElemType_P e;
	Link p;
	
	InitList_E(P);			//初始化一个扩展的单链表存放多项式 
	h = GetHead_E(*P);		//获取多项式头指针 
	
	e.coef = 0.0;
	e.expn = -1;
	SetCurElem_E(h, e);		//设置头结点的数据元素
	h->next = NULL;
		
	for(i=1; i<=m; i++)		//依次录入n个非0项 
	{
		Scanf(fp, "%f%d", &(e.coef), &(e.expn));
		MakeNode_E(&p, e);
		p->next = NULL;
		InsFirst_E(P, h, p);
		h = h->next;
	}
}

/*(02)销毁一元多项式。*/
void DestroyPolyn_P(Polynomial *P)
{
	DestroyList_E(P);
}

/*(03)返回一元多项式的项数。*/
int PolynLength_P(Polynomial P)
{
	return ListLength_E(P);
}

/*(04)算法2.23：一元多项式加法Pa=Pa+Pb，销毁Pb。*/
void AddPolyn_P(Polynomial *Pa, Polynomial *Pb)		//多项式加法：Pa=Pa+Pb，利用两个多项式的结点构成“和多项式”。
{
	PositionPtr ha, hb;
	PositionPtr qa, qb;
	ElemType_P a, b;
	float sum;
	
	ha = GetHead_E(*Pa);	//ha指向Pa的头结点 
	hb = GetHead_E(*Pb);	//hb指向Pb的头结点
	qa = NextPos_E(ha);		//qa指向Pa中当前结点 
	qb = NextPos_E(hb);		//qb指向Pb中当前结点
	
	while(qa && qb)		//qa和qb均非空 
	{
		a = GetCurElem_E(qa);	//a和b为两表中当前比较元素 
		b = GetCurElem_E(qb);
		
		switch(Cmp_exp(a,b))
		{
			case -1:	//多项式Pa中当前结点的指数值小
				ha = qa;
				qa = NextPos_E(ha);
				break;
			case 0:		//两者的指数值相等						 
				sum = a.coef + b.coef;
				if(sum != 0.0)		//修改多项式Pa中的当前结点的系数值 
				{
					qa->data.coef = sum;
					SetCurElem_E(qa,qa->data);
					ha = qa;	
				}
				else		//删除多项式Pa中当前结点 
				{
					DelFirst_E(Pa, ha, &qa);
					FreeNode_E(&qa);
				}
				DelFirst_E(Pb, hb, &qb);	//删除Pb中扫描过的结点
				FreeNode_E(&qb);
				qb = NextPos_E(hb);
				qa = NextPos_E(ha);
				break;
				
			case 1:							//多项式Pb中当前结点的指数值较小
				DelFirst_E(Pb, hb, &qb);	//摘下Pb当前结点
				InsFirst_E(Pa, ha, qb);		//将摘下结点链入Pa中
				qb = NextPos_E(hb);
				ha = NextPos_E(ha);
				break;			 	 		
		}
	}
	if(!ListEmpty_E(*Pb))	//链接Pb中剩余结点 
		Append_E(Pa, qb);
	FreeNode_E(&hb);		//释放Pb的头结点，合并完成多项式Pb本身还有一些残留信息。	
}

/*(07)比较c1项和c2项指数大小。*/
int Cmp_exp(ElemType_P c1, ElemType_P c2)
{
	int i = c1.expn - c2.expn;
	if(i<0)
		return -1;
	else if(i==0)
		return 0;
	else
		return 1;
}

/*(08)打印输出一元多项式。*/
void PrintPolyn_P(Polynomial P)
{
	int i;
	Link p;
	
	p = P.head->next;
	for(i=1; i<=P.len; i++)
	{
		if(i==1)
			printf("%g",p->data.coef);	//%g是根据结果自动选择科学记数法还是一般的小数记数法
		else
		{
			if(p->data.coef>0)
			{
				printf(" + ");
				printf("%g",p->data.coef);
			}
			else
			{
				printf(" - ");
				printf("%g",-p->data.coef);
			}
		}
		
		if(p->data.expn)
		{
			printf("x");
			
			if(p->data.expn!=1)
				printf("^%d",p->data.expn);
		}
		
		p = p->next;
	}
}

#endif
