/************************************
 *                                  *
 * 文件夹: 09_Searching             *
 *                                  *
 * 文件名: BalancedBinarySortTree.c *
 *                                  *
 * 算  法: 9.9、9.10、9.11、9.12    *
 *                                  *
 ************************************/

#ifndef BALANCEDBINARYSORTTREE_C
#define BALANCEDBINARYSORTTREE_C

#include "BalancedBinarySortTree.h" 		/* 09_Searching */

/*(01)创建AVL树。*/
Status CreateAVL(BBSTree *BBST, Table T)
{
	int i, t;
	
	*BBST = NULL;
	t = FALSE;
	
	if(T.length)
	{
		for(i=1; i<=T.length; i++)
			InsertAVL(BBST, T.elem[i], &t);	
	}
	
	return OK;
}

/*(02)查找，返回指向key的指针，若不存在返回MULL。*/
BBSTree SearchAVL(BBSTree BBST, KeyType key)
{
	if(!BBST || EQ(key, BBST->data.key))
		return BBST;
	else if(LT(key, BBST->data.key))
		return SearchAVL(BBST->lchild, key);
	else
		return SearchAVL(BBST->rchild, key);
}

/*(03)算法9.11：插入。*/
Status InsertAVL(BBSTree *BBST, ElemType_Search e, Boolean *taller)
{
	// 若在平衡的二叉排序树BBST中不存在和e有相同关键字的结点，则插入一个数据元素
	// 为e的新结点，并返回1，否则返回0。若因插入而使二叉排序树失去平衡，则做平衡
	// 旋转处理，布尔变量taller反应BBST长高与否
	if(!(*BBST))								// 插入新结点，树“长高”，置taller为TRUE
	{
		*BBST = (BBSTree)malloc(sizeof(BBSTNode));
		(*BBST)->data = e;
		(*BBST)->lchild = (*BBST)->rchild = NULL;
		(*BBST)->bf = EH;
		*taller = TRUE;
	}
	else
	{
		if(EQ(e.key, (*BBST)->data.key))		// 树中已存在和e有相同关键字的结点，则不再插入 
		{
			*taller = FALSE;
			return 0;
		}
		else if(LT(e.key, (*BBST)->data.key))	  // 应继续在*BBST的左子树中进行搜索 
		{
			if(!InsertAVL(&(*BBST)->lchild, e, taller))
				return 0;						    // 未插入

			if(*taller)							  // 已插入到*BBST的左子树中且左子树“长高”
			{
				switch((*BBST)->bf)			// 检查*BBST的平衡度
				{
					case LH:					    // 原本左子树比右子树高，需要做左平衡处理 
						LeftBalance(BBST);
						*taller = FALSE;
						break;
					case EH:					    // 原本左、右子树等高，现因左子树增高而使树增高 
						(*BBST)->bf = LH;
						*taller = TRUE;
						break; 
					case RH:					    // 原本右子树比左子树高，现左、右子树等高 
						(*BBST)->bf = EH;
						*taller = FALSE;
						break;
				}
			} 
		}
		else									      // 应继续在*BBST的右子树中进行搜索 
		{
			if(!InsertAVL(&(*BBST)->rchild, e, taller))
				return 0;						    // 未插入 		

			if(*taller)							  // 已插入到*BBST的右子树中且右子树“长高”
			{
				switch((*BBST)->bf)			// 检查*BBST的平衡度
				{
					case LH:					    // 原本左子树比右子树高，现左、右子树等高 
						(*BBST)->bf = EH;
						*taller = FALSE;
						break;
					case EH:					    // 原本左、右子树等高，现因右子树增高而使树增高 
						(*BBST)->bf = RH;
						*taller = TRUE;
						break; 
					case RH:					    // 原本右子树比左子树高，需要做右平衡处理 
						RightBalance(BBST);
						*taller = FALSE;
						break;
				}
			}
		}
	}
	
	return 1;
}

/*(04)删除。*/
Status DeleteAVL(BBSTree *BBST, ElemType_Search e, BBSTree f, BBSTree p, Boolean *taller, int mark)
{
	//p指向当前结点，f指向p的父结点，初始化为空，*taller初始化为FALSE，mark代表f与p的关系，初始化为0 
	BBSTree r;
	ElemType_Search tmp;
	 
	if(!p)
		return ERROR;
	else
	{		
		if(LT(e.key, p->data.key))				// 关键字较小，搜寻左子树
		{			
			if(!DeleteAVL(BBST, e, p, p->lchild, taller, 0))
				return ERROR;
			
			if(*taller)
			{
				switch(p->bf)
				{
					case LH:
						p->bf = EH;
						*taller = TRUE;
						break;
					case EH:
						p->bf = RH;
						*taller = FALSE;
						break;
					case RH:
						if(!f)
							RightBalance(BBST);
						else
							RightBalance(&(f->lchild));
						*taller = TRUE;
						break;				
				}			
			}
		}			
		else if(RT(e.key, p->data.key))			// 关键字较大，搜寻右子树
		{	
			if(!DeleteAVL(BBST, e, p, p->rchild, taller, 1))
				return ERROR;	
						
			if(*taller)
			{
				switch(p->bf)
				{
					case LH:											// update on 20220921
						if(!f)
							LeftBalance(BBST);
						else
							LeftBalance(&(f->lchild));
						*taller = TRUE;
						break;
					case EH:
						p->bf = LH;
						*taller = FALSE;
						break;
					case RH:
						p->bf = EH;
						*taller = TRUE;
						break;				
				}
			}
		}
		else												// 找到关键字 
		{			
			if(p->lchild!=NULL && p->rchild==NULL)			// 只有左子树
			{
				if(!f)										// 根结点 
					*BBST = p->lchild;			
				else
				{
					if(mark==0)
						f->lchild = p->lchild;
					else
						f->rchild = p->lchild;
				}	
				
				free(p);
				p = NULL;
				
				*taller = TRUE;	
			}
			else if(p->lchild==NULL && p->rchild!=NULL)		// 只有右子树
			{
				if(!f)										// 根结点 
					*BBST = p->rchild;			
				else
				{
					if(mark==0)
						f->lchild = p->rchild;
					else
						f->rchild = p->rchild;
				}	
				
				free(p);
				p = NULL;
				
				*taller = TRUE;			
			}
			else if(p->lchild==NULL && p->rchild==NULL)		// 左右子树均为空
			{
				if(!f)										// 根结点 
					*BBST = NULL;			
				else
				{
					if(mark==0)
						f->lchild = NULL;
					else
						f->rchild = NULL;
				}	
				
				free(p);
				p = NULL;
				
				*taller = TRUE;
			} 
			else											// 左右子树均不空
			{
				r = p->lchild;
			
				while(r->rchild)
					r = r->rchild;
				
				tmp = r->data;
				
				*taller = FALSE;
				if(!f)
					DeleteAVL(BBST, tmp, NULL, p, taller, mark);
				else
				{
					if(mark==0)
						DeleteAVL(&(f->lchild), tmp, NULL, p, taller, mark);
					else								
						DeleteAVL(&(f->rchild), tmp, NULL, p, taller, mark);				
				}			
				p->data = tmp;
			} 
		}
	
		return OK;
	}
}

/*(05)右平衡处理。*/
void RightBalance(BBSTree *BBST)
{
	BBSTree rc, ld;
	
	rc = (*BBST)->rchild;
	
	switch(rc->bf)
	{
		case RH:					// 新结点插入在*BBST右孩子的右子树上
			(*BBST)->bf = rc->bf = EH;
			L_Rotate(BBST);			
			break;

		case LH: 					// 新结点插入在*BBST右孩子的左子树上
			ld = rc->lchild;			
			switch(ld->bf)		// 如何通过ld->bf(平衡因子)去修改其他结点的平衡因子，
												// 此处需详细思考，多作假设
			{
				case LH:
					(*BBST)->bf = EH;
					rc->bf = RH;
					break;
				case EH:
					(*BBST)->bf = rc->bf = EH;
					break;
				case RH:
					(*BBST)->bf = LH;
					rc->bf = EH;
					break;
			}			
			ld->bf = EH;
			R_Rotate(&(*BBST)->rchild);
			L_Rotate(BBST);
			break;
		
		case EH:		// 特殊情况,这种情况在添加时不可能出现，只在移除时可能出现
			L_Rotate(BBST);
			(*BBST)->bf = AVLDepth((*BBST)->lchild)-AVLDepth((*BBST)->rchild);
	}
}
/*
// 右平衡处理（原版）
void RightBalance(BBSTree *BBST)
{
	BBSTree rc, ld;
	
	rc = (*BBST)->rchild;
	
	switch(rc->bf)
	{
		case RH:					//新结点插入在*BBST右孩子的右子树上
			(*BBST)->bf = rc->bf = EH;
			L_Rotate(BBST);			
			break;

		case LH: 					//新结点插入在*BBST右孩子的左子树上
			ld = rc->lchild;			
			switch(ld->bf)
			{
				case LH:
					(*BBST)->bf = EH;
					rc->bf = RH;
					break;
				case EH:
					(*BBST)->bf = rc->bf = EH;
					break;
				case RH:
					(*BBST)->bf = LH;
					rc->bf = EH;
					break;
			}			
			ld->bf = EH;
			R_Rotate(&(*BBST)->rchild);
			L_Rotate(BBST);
			break;
	}
}
*/

/*(06)算法9.12：左平衡处理。*/
void LeftBalance(BBSTree *BBST)
{
	// 对以指针BBST所指结点为根的二叉树作左平衡旋转处理，本算法结束时，
	// 指针BBST指向新的根结点
	BBSTree lc, rd;
	
	lc = (*BBST)->lchild;		//  lc指向*BBST的左子树根结点
	
	switch(lc->bf)					// 检查*BBST的左子树的平衡度，并作相应平衡处理
	{
		case LH:							// 新结点插入在*BBST的左孩子的左子树上，要作单右旋处理 
			(*BBST)->bf = lc->bf = EH;
			R_Rotate(BBST);
			break;
		
		case RH:							// 新结点插入在*BBST的左孩子的右子树上，要作双旋处理
			rd = lc->rchild;		// rd指向*BBST的左孩子的右子树根		
			switch(rd->bf)			// 修改*BBST及其左孩子的平衡因子，如何修改？
			{
				case LH:
					(*BBST)->bf = RH;
					lc->bf = EH;
					break;
				case EH:
					(*BBST)->bf = lc->bf = EH;
					break;
				case RH:
					(*BBST)->bf = EH;
					lc->bf = LH;
					break;
			}			
			rd->bf = EH;
			L_Rotate(&(*BBST)->lchild);		// 对*BBST的左子树作左旋平衡处理
			R_Rotate(BBST);								// 对*BBST作右旋平衡处理
			break;
	}
}

/*(07)算法9.9：右旋。*/
void R_Rotate(BBSTree *p)
{
	// 对以*p为根的二叉排序树作右旋处理，处理之后p指向新的树根结点，即旋转
	// 处理之前的左子树的根结点
	BBSTree lc;
	
	lc = (*p)->lchild;						// lc指向*p的左子树根结点
	(*p)->lchild = lc->rchild;		// lc的右子树挂接为*p的左子树
	lc->rchild = *p;		
	*p = lc;											// p指向新的根结点
}

/*(08)算法9.10：左旋。*/
void L_Rotate(BBSTree *p)
{
	// 对以*p为根的二叉排序树作左旋处理，处理之后p指向新的树根结点，即旋转
	// 处理之前的右子树的根结点
	BBSTree rc;
	
	rc = (*p)->rchild;						// rc指向*p的右子树根结点
	(*p)->rchild = rc->lchild;		// rc的左子树挂接为*p的右子树
	rc->lchild = *p;
	*p = rc;											// p指向新的根结点
}

/*(09)中序遍历。*/
void InOrderTraverse_AVL(BBSTree BBST, void(Visit)(ElemType_Search))
{
  if(BBST)
  {
    InOrderTraverse_AVL(BBST->lchild, Visit);
    Visit(BBST->data);
    InOrderTraverse_AVL(BBST->rchild, Visit);
  }
}

/*(10)求树的深度。*/
int AVLDepth(BBSTree BBST)
{
  int LD, RD;

  if(BBST==NULL)    
    return 0;                       // 空树深度为0
  else
  {
    LD = AVLDepth(BBST->lchild);    // 求左子树深度
    RD = AVLDepth(BBST->rchild);    // 求右子树深度

    return (LD>=RD?LD:RD)+1;
  }  
}

/*(11)打印树。*/
void PrintAVLTree(BBSTree BBST)
{
	int row, col;
	int i, j, m, l, r;
	BBSTNode a[100][100] = {};
	
	if(BBST)
	{
		row = AVLDepth(BBST);					  // 总行数 
		col = pow(2, row) - 1;					// 总列数 
		
		for(i=1; i<=row-1; i++)
		{
			for(j=1; j<=pow(2, i-1); j++)
			{
				m = (2*j-1)*pow(2, row-i);		// 当前行结点相对位序 
				l = (4*j-3)*pow(2, row-i-1);	// 下一行结点相对位序 
				r = (4*j-1)*pow(2, row-i-1);
				
				if(i==1)						          // 初始化 
					a[i][m] = *BBST;
				
				if(a[i][m].lchild)				    // 下一行 
					a[i+1][l] = *(a[i][m].lchild);
					
				if(a[i][m].rchild)				    // 下一行 
					a[i+1][r] = *(a[i][m].rchild);
			} 
		}
		
		for(i=1; i<=row; i++)
		{
			for(j=1; j<=col; j++)
			{
				if(a[i][j].data.key)
					printf("%2d", a[i][j].data.key);
				else
					printf("  ");
			}
			printf("\n");
		}	
	}
}

#endif
