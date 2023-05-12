/************************************************
 *							                                *
 * 文件夹: 06_Tree_and_BinTree/02_BinaryTree    *
 * 							                                *
 * 文件名: BinaryTree.c                         *
 *    	    				                            *
 * 算  法: 6.1、6.2、6.3、6.4			              *
 *                                              *
 ************************************************/
 
#ifndef BINARYTREE_C
#define BINARYTREE_C

#include "BinaryTree.h"						/*06 树和二叉树*/

/*(01)构造空二叉树T（初始化二叉树）。*/
void InitBiTree(BiTree *T)
{
	*T = NULL;
}

/*(02)清空二叉树T。*/
void ClearBiTree(BiTree *T)
{
	if(*T)											//二叉树不为空 
	{
		if((*T)->lchild)							//清空左树 
			ClearBiTree(&((*T)->lchild));
		if((*T)->rchild)							//清空右树 
			ClearBiTree(&((*T)->rchild));
			
		free(*T);									//释放结点 
		
		*T = NULL;									//置空树指针 
	}	
}

/*(03)销毁二叉树T。*/
void DestroyBiTree(BiTree *T)
{
	//二叉树无法销毁 
}

/*(04)判断二叉树T是否为空。*/
Status BiTreeEmpty(BiTree T)
{
	return T==NULL ? TRUE : FALSE; 
} 

/*(05)算法6.4：按先序序列构造二叉树。*/
Status CreateBiTree(FILE *fp, BiTree *T)		//对于递归操作，难以理解，可以通过调试观察其执行过程 
{
	char ch;
	
	Scanf(fp, "%c", &ch);
	
	if(ch == '^')
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if(!(*T))
			exit(OVERFLOW);
		
		(*T)->data = ch;							//生成根节点 
		CreateBiTree(fp, &(*T)->lchild);			//构造左子树 
		CreateBiTree(fp, &(*T)->rchild);			//构造右子树 
	}
	
	return OK; 
}

/*(06)返回二叉树长度（按完全二叉树计算）。*/
int BiTreeLength(BiTree T)
{
	Node node[100];							//存储结点信息
	int i, len;
	
	i = len = 0;
	
	if(T)
	{
		node[i].left = T->lchild;
		node[i].right = T->rchild;
		node[i].n = 1;
		if(node[i].n>len)
			len = node[i].n;
			
		while(i>=0)
		{
			while(node[i].left)								//访问左子树
			{
				node[i+1].left = node[i].left->lchild;
				node[i+1].right = node[i].left->rchild;
				node[i+1].n= 2*node[i].n;
				node[i].left = NULL;
				i++;
				if(node[i].n>len)
					len = node[i].n;	
			}
		
			if(node[i].right)								//左子树为空时访问右子树
			{
				node[i+1].left = node[i].right->lchild;
				node[i+1].right = node[i].right->rchild;
				node[i+1].n= 2*node[i].n+1;
				node[i].right = NULL;
				i++;
				if(node[i].n>len)
					len = node[i].n;
			}
			
			if(node[i].left==NULL && node[i].right==NULL)
				i--;	
		}
	}
	
	return len; 
}

/*(07)返回二叉树深度（层数）。*/			//debug，结合调用栈观察 
int BiTreeDepth(BiTree T)
{
	int LD, RD;
	
	if(T==NULL)
		return 0;							//空树深度为0 
	else
	{
		LD = BiTreeDepth(T->lchild);		//求左子树深度 
		RD = BiTreeDepth(T->rchild);		//求右子树深度 
		
		return (LD>=RD?LD:RD)+1;		
	}
}

/*(08)用e返回二叉树的根结点值。*/
Status Root(BiTree T, TElemType *e)
{
	if(!T)
		return ERROR;
	else
	{
		*e = T->data;
		return OK;
	}
}

/*(09)返回某结点的值，p为结点指针。*/
TElemType Value(BiTree p)
{
	return p->data;
}

/*(10)为某结点赋值，p为结点指针。*/
void Assign(BiTree p, TElemType value)
{
	p->data = value;
}

/*(11)返回某结点的双亲结点值。*/
TElemType Parent(BiTree T, TElemType e)
{
	BiTNode  node[100];
	int i = 0;
	
	if(T==NULL || (T!=NULL && e==T->data))						//空树或者根结点无双亲 
		return '\0';
	
	node[i] = *T;
	
	while(i>=0)
	{
		while(node[i].lchild)									//访问左子树
		{
			if(node[i].lchild->data==e)
				return node[i].data;
			node[i+1] = *(node[i].lchild);
			node[i].lchild = NULL;								//置空代表此结点已访问过 
			i++;
		}
		
		if(node[i].rchild)										//左子树为空时访问右子树
		{
			if(node[i].rchild->data==e)
				return node[i].data;
			node[i+1] = *(node[i].rchild);
			node[i].rchild = NULL;
			i++;
		}
		
		if(node[i].lchild==NULL && node[i].rchild==NULL)		//回退 
			i--;
	}
	
	if(i<0)														//未找到 
		return '\0';
}

/*(12)返回某结点的左孩子结点值。*/
TElemType LeftChild(BiTree T, TElemType e)
{
	BiTNode  node[100];
	int i = 0;
	
	if(T==NULL)						//空树 
		return '\0';
	
	node[i] = *T;
	
	while(i>=0)
	{
		while(node[i].data!=e && node[i].lchild)									//访问左子树
		{
			node[i+1] = *(node[i].lchild);
			node[i].lchild = NULL;							//置空代表此结点已访问过 
			i++;
		}
		
		if(node[i].data==e)
		{
			if(node[i].lchild)
				return node[i].lchild->data;
			else
				return '\0';
		}
		
		if(node[i].rchild)									//左子树为空时访问右子树
		{
			node[i+1] = *(node[i].rchild);
			node[i].rchild = NULL;
			i++;
		}
		
		if(node[i].lchild==NULL && node[i].rchild==NULL && node[i].data!=e)	//回退 
			i--;
	}
	
	if(i<0)														//未找到 
		return '\0';
}

/*(13)返回某结点的右孩子结点值。*/
TElemType RightChild(BiTree T, TElemType e)
{
	BiTNode  node[100];
	int i = 0;
	
	if(T==NULL)						//空树 
		return '\0';
	
	node[i] = *T;
	
	while(i>=0)
	{
		while(node[i].data!=e && node[i].lchild)									//访问左子树
		{
			node[i+1] = *(node[i].lchild);
			node[i].lchild = NULL;							//置空代表此结点已访问过 
			i++;
		}
		
		if(node[i].data==e)
		{
			if(node[i].rchild)
				return node[i].rchild->data;
			else
				return '\0';
		}
		
		if(node[i].rchild)									//左子树为空时访问右子树
		{
			node[i+1] = *(node[i].rchild);
			node[i].rchild = NULL;
			i++;
		}
		
		if(node[i].lchild==NULL && node[i].rchild==NULL)	//回退 
			i--;
	}
	
	if(i<0)														//未找到 
		return '\0';
}

/*(14)返回某结点的左兄弟结点值。*/
TElemType LeftSibling(BiTree T, TElemType e)
{
	BiTNode node[100];
	int i = 0;
	
	if(T==NULL || (T!=NULL && e==T->data))					//树为空或者根结点无兄弟结点 
		return '\0';
	
	node[i] = *T;
	
	while(i>=0)
	{
		while(node[i].rchild)
		{
			if(node[i].rchild->data==e)
			{
				if(node[i].lchild)
					return node[i].lchild->data;
				else
					return '\0'; 
			}
			
			node[i+1] = *(node[i].rchild);
			node[i].rchild = NULL;
			i++;
		}
		
		if(node[i].lchild)
		{
			if(node[i].lchild->data==e)
				return '\0';
			node[i+1] = *(node[i].lchild);
			node[i].lchild = NULL;
			i++;
		}
		
		if(node[i].lchild==NULL && node[i].rchild==NULL)
			i--;
	}
	
	if(i<0)
		return '\0'; 
}

/*(15)返回某结点的右兄弟结点值。*/
TElemType RightSibling(BiTree T, TElemType e)
{
	BiTNode node[100];
	int i = 0;
	
	if(T==NULL || (T!=NULL && e==T->data))					//树为空或者根结点无兄弟结点 
		return '\0';
	
	node[i] = *T;
	
	while(i>=0)
	{
		while(node[i].lchild)
		{
			if(node[i].lchild->data==e)
			{
				if(node[i].rchild)
					return node[i].rchild->data;
				else
					return '\0'; 
			}
			
			node[i+1] = *(node[i].lchild);
			node[i].lchild = NULL;
			i++;
		}
		
		if(node[i].rchild)
		{
			if(node[i].rchild->data==e)
				return '\0';
			node[i+1] = *(node[i].rchild);
			node[i].rchild = NULL;
			i++;
		}
		
		if(node[i].lchild==NULL && node[i].rchild==NULL)
			i--;
	}
	
	if(i<0)
		return '\0';
}

/*(16-1)获取指向结点e的指针。*/
BiTree LocationBiTree_1(BiTree T, TElemType e)
{
	BiTNode node[100];
	int i = 0;
	
	if(T==NULL)
		return NULL;
	
	if(T->data==e)
		return T;

	node[i] = *T;
	
	while(i>=0)
	{
		while(node[i].lchild)
		{
			if(node[i].lchild->data==e)
				return node[i].lchild;
			node[i+1] = *(node[i].lchild);
			node[i].lchild = NULL;
			i++;
		}
		
		if(node[i].rchild)
		{
			if(node[i].rchild->data==e)
				return node[i].rchild;
			node[i+1] = *(node[i].rchild);
			node[i].rchild = NULL;
			i++;
		}
		
		if(node[i].lchild==NULL && node[i].rchild==NULL)
			i--;		
	}
	
	if(i<0)
		return NULL;
}

/*(16-2)获取指向结点e的指针。*/
BiTree LocationBiTree_2(BiTree T, TElemType e)
{
	BiTree p = NULL;
	
	if(T)
	{
		if(T->data==e)
			p = T;
		else
		{
			if(p=LocationBiTree_2(T->lchild, e))
				return p;
			
			if(p=LocationBiTree_2(T->rchild, e))
				return p;	
		}	
	}
	
	return p;
}

/*(17)将树T0插入到树T中成为结点e的子树，LR为插入标记，T0只有左子树。*/
Status InsertBiTree(BiTree T, TElemType e, BiTree T0, int LR)
{
	BiTree p = LocationBiTree_1(T, e);
	
	if(p)
	{												//LR为0表示T0成为结点e的左子树，反之右子树 
		T0->rchild = LR ? p->rchild : p->lchild;			
		LR ? (p->rchild=T0) : (p->lchild=T0);		
		
		return OK;
	}
	
	return ERROR;
} 

/*(18)删除e结点的左子树或右子树，LR为删除标记。*/
Status DeleteBiTree(BiTree T, TElemType e, int LR)
{
	BiTree p = LocationBiTree_2(T, e);
	
	if(p)
	{
		LR ? ClearBiTree(&(p->rchild)) : ClearBiTree(&(p->lchild));	
		
		return OK;
	}
	
	return ERROR;
}

/*(19)层序遍历二叉树。*/
void LevelOrderTraverse(BiTree T, void(Visit)(TElemType))
{
	int i, j;
	BiTree p[100];				//树指针数组
	
	i = j = 0;
	
	if(T)
		p[j++] = T;
		
	while(i<j)
	{
		Visit(p[i]->data);
		if(p[i]->lchild)
			p[j++] = p[i]->lchild;
		if(p[i]->rchild)
			p[j++] = p[i]->rchild;
		i++;
	}
}

/*(20-1)先序遍历二叉树。*/
void PreOrderTraverse_1(BiTree T, void(Visit)(TElemType))
{
	if(T)
	{
		Visit(T->data);
		PreOrderTraverse_1(T->lchild, Visit);
		PreOrderTraverse_1(T->rchild, Visit);
	}
}

/*(20-2)算法6.1：先序遍历二叉树。*/
Status PreOrderTraverse_2(BiTree T, Status(Visit)(TElemType))
{
	if(T)
	{
		if(Visit(T->data))
		{
			PreOrderTraverse_2(T->lchild, Visit);
			PreOrderTraverse_2(T->rchild, Visit);	
		}
		return OK;
	}
	else
		return ERROR;
}

/*(21-1)中序遍历二叉树。*/
void InOrderTraverse_1(BiTree T, void(Visit)(TElemType))
{
	if(T)
	{
		InOrderTraverse_1(T->lchild, Visit);
		Visit(T->data);
		InOrderTraverse_1(T->rchild, Visit);
	}
}

/*(21-2)算法6.2：中序遍历二叉树。*/
Status InOrderTraverse_2(BiTree T, Status(Visit)(TElemType))
{
	SqStack S;
	BiTree p;
	
	InitStack_Sq(&S);
	Push_Sq(&S, T);						//根指针进栈 
	
	while(!StackEmpty_Sq(S))
	{
		while(GetTop_Sq(S,&p) && p)		//向左走到尽头 
			Push_Sq(&S, p->lchild);
			
		Pop_Sq(&S, &p);					//空指针退栈 
		
		if(!StackEmpty_Sq(S))			//访问结点，向右一步 
		{
			Pop_Sq(&S, &p);
			if(!Visit(p->data))
				return ERROR;
			Push_Sq(&S, p->rchild);
		}
	}
	return OK;
}

/*(21-3)算法6.3：中序遍历二叉树。*/
Status InOrderTraverse_3(BiTree T, Status(Visit)(TElemType))
{
	SqStack S;
	BiTree p;
	
	InitStack_Sq(&S);
	p = T;
	
	while(p || !StackEmpty_Sq(S))
	{
		if(p)						//根指针进栈，遍历左子树 
		{
			Push_Sq(&S, p);
			p = p->lchild;
		}
		else						//根指针退栈，访问根结点，遍历右子树 
		{
			Pop_Sq(&S, &p);
			if(!Visit(p->data))
				return ERROR;
			p = p->rchild;	
		} 
	}
	return OK;
}

/*(22)后序遍历二叉树。*/
void PostOrderTraverse(BiTree T, void(Visit)(TElemType))
{
	if(T)
	{
		PostOrderTraverse(T->lchild, Visit);
		PostOrderTraverse(T->rchild, Visit);
		Visit(T->data);		
	}
}

/*(23)按二叉树的结构打印树。*/
void PrintTree(BiTree T)
{
	int row, col;
	int i, j, m, l, r;
	BiTNode a[100][100] = {};					//用一个足够大的矩阵按原样存储树 
	
	if(T)
	{
		row = BiTreeDepth(T);					//总行数 
		col = pow(2, row)-1;					//总列数
		
		for(i=1; i<=row-1; i++)
		{
			for(j=1; j<=pow(2,i-1); j++)
			{
				m = (2*j-1)*pow(2, row-i);		//当前结点相对位序
				l = (4*j-3)*pow(2, row-i-1); 	//下一行结点相对位序
				r = (4*j-1)*pow(2, row-i-1);
				
				if(i==1)						//初始化
					a[i][m] = *T;
					
				if(a[i][m].lchild)				//下一行
					a[i+1][l] = *(a[i][m].lchild);
					
				if(a[i][m].rchild)				//下一行 
					a[i+1][r] = *(a[i][m].rchild); 
			}
		}
		
		for(i=1; i<=row; i++)
		{
			for(j=1; j<=col; j++)
			{
				if(a[i][j].data)
					printf("%c", a[i][j].data);
				else
					printf(" ");
			}
			printf("\n");
		} 
	}
}

#endif
