/****************************************************
 *							                                    *
 * 文件夹: 06_Tree_and_BinTree/04_ThreadBinaryTree  *
 *							                                    *
 * 文件名: ThreadBinaryTree.c                       *
 *							                                    *
 * 算  法: 6.5、6.6、6.7		                        *
 *                                                  *
 ****************************************************/
 
#ifndef THREADBINARYTREE_C 
#define THREADBINARYTREE_C

#include "ThreadBinaryTree.h"					/* 06 树和二叉树*/

/*(01)按先序序列构造二叉树，并建立孩子标志(无线索化)。*/
Status CreateBiTree_Thr(FILE *fp, ThrBiTree *T)
{
	TElemType_Thr ch;
	
	Scanf(fp, "%c", &ch);
	
	if(ch=='^')
		*T = NULL;
	else
	{
		*T = (ThrBiTree)malloc(sizeof(ThrBiNode));
		if(!(*T))
			exit(OVERFLOW);
		(*T)->data = ch;
		
		CreateBiTree_Thr(fp, &(*T)->lchild);			//递归构造左子树 
		if((*T)->lchild)
			(*T)->LTag = Link;							//有左孩子 
		else
			(*T)->LTag = Thread;
			
		CreateBiTree_Thr(fp, &(*T)->rchild);			//递归构造右子树 
		if((*T)->rchild)
			(*T)->RTag = Link;							//有右孩子 
		else
			(*T)->RTag = Thread;		
	}
	 
	return OK;
} 


/*(02)算法6.7：中序全线索化。*/
void InThreading_Thr(ThrBiTree p)
{
	if(p)
	{
		InThreading_Thr(p->lchild);			//左子树线索化
		if(!p->lchild)						//前驱线索 
		{
			p->LTag = Thread;
			p->lchild = pre;
		}
		if(!pre->rchild)					//后驱线索 
		{
			pre->RTag = Thread;
			pre->rchild = p;
		}
		pre = p;							//保持pre指向p的前驱
		InThreading_Thr(p->rchild);			//右子树线索化 
	}
}

/*(03)算法6.6：中序遍历二叉树T，并将其全线索化。*/
Status InOrderThreading_Thr(ThrBiTree *Thrt, ThrBiTree T)
{
	//中序遍历二叉树T，并将其中序线索化，Thrt指向头结点。
	*Thrt = (ThrBiTree)malloc(sizeof(ThrBiNode));
	if(!(*Thrt))
		exit(OVERFLOW);
	(*Thrt)->data = '\0';	
	(*Thrt)->LTag = Link;					//建立头结点 
	(*Thrt)->RTag = Thread;
	(*Thrt)->rchild = *Thrt;				//右指针回指
	
	if(!T)									//若二叉树为空，则左指针回指 
		(*Thrt)->lchild = *Thrt;
	else
	{
		(*Thrt)->lchild = T;
		pre = *Thrt;
		
		InThreading_Thr(T);					//中序遍历进行中序线索化
		
		pre->rchild = (*Thrt);				//最后一个结点指回头结点 
		pre->RTag = Thread;					//最后一个结点线索化 
		(*Thrt)->rchild = pre; 				//头结点指向最后一个结点，建立双向联系
	}
	 
	 return OK;
} 

/*(04)算法6.5：中序遍历中序全线索二叉树。（非递归算法）。*/
Status InOrderTraverse_Thr(ThrBiTree Thrt, void(Visit)(TElemType_Thr))
{
	//T指向头结点，头结点的左链lchild指向根结点，可参见线索化算法。
	//中序遍历二叉线索树T的非递归算法，对每个数据元素调用函数Visit。
	
	ThrBiTree p = Thrt->lchild;				//p指向根结点
	
	while(p!=Thrt)							//空树或遍历结束时，p==T 
	{
		while(p->LTag==Link)
			p = p->lchild;
		
		Visit(p->data);	
	
		while(p->RTag==Thread && p->rchild!=Thrt)
		{
			p = p->rchild;					//访问后继结点 
			Visit(p->data);
		}
		
		p = p->rchild; 	
	} 
	
	return OK; 
}

#endif
