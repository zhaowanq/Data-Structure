/************************
 *                      *
 * 文件夹: 09_Searching *
 *                      *
 * 文件名: B-Tree.c     *
 *                      *
 * 算  法: 9.13、9.14   *
 *                      *
 ************************/

#include "B-Tree.h" 				/* 09_Searching */

/*(01)创建B树。*/
Status CreateBTree(BTree *BT, Table T)
{
	int i;
	
	*BT = NULL;

	if(T.length)
	{
		for(i=1; i<=T.length; i++)
		{
			if(!InsertKey(BT, T.elem[i].key))     // 插入失败则跳出循环 
				break;
		}				
	}
	
	if(i>T.length) 
		return OK;
	else
		return ERROR;
}

/*(02)算法9.13：查找，返回查找信息。*/
Result SearchBTree(BTree BT, KeyType K)
{
  // 在m阶B-树BT上查找关键字K，返回结果(pt,i,tag)。若查找成功，则特征值tag=1,指针pt
  // 所指结点中第i个关键字等于K；否则特征值tag=0，等于K的关键字应插入在指针pt所指
  // 结点中第i和第i+1个关键字之间

  Result R = {NULL, 0, 0};
	BTree p, q;
	int found, i;

  p = BT;                     // 初始化，p指向待查找结点，q指向p的双亲
  q = NULL;
  found = FALSE;
  i = 0;                      // p->key[i]<=K<p->key[i+1]

  while(p && !found)
  {
    i = Search(p, K);         // 在p->key[1...keynum]中查找，
                              // i使得：p->key[i]<=K<p->key[i+1]
    if(i>0 && p->key[i]==K)   // 找到待查关键字
      found = TRUE;
    else                      // 准备查找下一个结点
    {
      q = p;
      p = p->ptr[i];
    }
  }

  R.i = i;

  if(found)                   // 查找成功
  {
    R.pt = p;
    R.tag = 1;
  }
  else                        // 查找不成功，返回K的插入位置信息
  {
    R.pt = q;
    R.tag = 0;
  }

  return R;
}

/*(03)返回K在结点p中的次序，若不存在，返回0。*/
int Search(BTree p, KeyType K)
{
	int i, j;

	for(i=0,j=1; j<=p->keynum; j++)
	{
		if(p->key[j]<=K)
			i = j;
		else
			break;
	}
	
	return i;
}

/*(04)将关键字K插入B树。*/
Status InsertKey(BTree *BT, KeyType K)
{
	Result R;
	
	R = SearchBTree(*BT, K);
	
	if(R.tag==0)					// B树中不存在此关键字 
	{
		InsertBTree(BT, K, R.pt, R.i);
		return OK;	
	}
	else
		return ERROR;	
}

/*(05)算法9.14：插入，在结点*q的key[i]和key[i+1]之间插入关键字K。*/
Status InsertBTree(BTree *BT, KeyType K, BTree q, int i)
{
  // 在m阶B-树BT上结点*q的key[i]与key[i+1]之间插入关键字K。
  // 若引起结点过大，则沿双亲链进行必要的结点分裂调整，使BT仍是m阶B-树。
	KeyType x;
	BTree ap;
	int finished;
	int s;
	
	x = K;
	ap = NULL;
	finished = FALSE;
	
	while(q && !finished)
	{
		Insert(q, i, x, ap);	    // 将x和ap分别插入到q->key[i+1]和q->ptr[i+1]
		
		if(q->keynum<M)
			finished = TRUE;	      // 插入完成
		else					            // 关键字数目超出限制	
		{
			s = ceil((double)M/2);	// B树结点中关键字个数必须>=ceil(M/2)-1
			split(q, s, &ap);     	// 分裂结点*q 
			x = q->key[s];			
			q = q->parent;
			
			if(q)				            // 在双亲结点*q中查找x的插入位置 
				i = Search(q, x);
		}
	}
	
	if(!finished)				        // BT是空树（参数q初值为NULL）或者根结点已分裂为结点*q和*ap 
		NewRoot(BT, q, x, ap); 	  // 生成含信息(BT,x,ap)的新的根结点*BT，原BT和ap为子树指针 
	
	return OK;
}

/*(06)将x和ap分别插入到q->key[i+1]和q->ptr[i+1]。*/
void Insert(BTree q, int i, KeyType x, BTree ap)
{
	int j;
	
	for(j=q->keynum; j>i; j--)
	{
		q->key[j+1] = q->key[j];
		q->ptr[j+1] = q->ptr[j];
	}
	
	q->key[i+1] = x;
	q->ptr[i+1] = ap;
	q->keynum++;
}

/*(07)以s为界，将q指向的结点分裂成q和ap指向的两部分。*/
void split(BTree q, int s, BTree *ap)				// s初值为┌M/2┐
{	
	int i;
	
	(*ap) = (BTree)malloc(sizeof(BTNode));
	(*ap)->ptr[0] = q->ptr[s];
	
	for(i=s+1; i<=M; i++)						// 将q->key[s+1...M],q->ptr[s...M]移入新结点*ap;
	{
		(*ap)->key[i-s] = q->key[i];
		(*ap)->ptr[i-s] = q->ptr[i];
		
/*
		if((*ap)->ptr[i-s])
			(*ap)->ptr[i-s]->parent = *ap;*/
	}
	
	(*ap)->keynum = M-s;
	q->keynum = s - 1;
	
	(*ap)->parent = q->parent;
	
	for(i=0; i<=(*ap)->keynum; i++)
	{
		if((*ap)->ptr[i])
			(*ap)->ptr[i]->parent = *ap;
	}
}

/*(08)生成含信息(BT,x,ap)的新的根结点*BT，原BT和ap为子树指针，q初值为NULL。*/
void NewRoot(BTree *BT, BTree q, int x, BTree ap)	//q初始值为空
{ 
	BTree p;

	p = (BTree)malloc(sizeof(BTNode));
	p->keynum = 1;
	p->parent = NULL;
	p->key[1] = x;
	p->ptr[0] = *BT;
	p->ptr[1] = ap;
	
	if(p->ptr[0])
		p->ptr[0]->parent = p;
	if(p->ptr[1])
		p->ptr[1]->parent = p;
	
	*BT = p;	
}

/*(09)从B树中删除关键字K。*/
Status DeleteKey(BTree *BT, KeyType K)
{
	Result R;
	
	R = SearchBTree(*BT, K);
	
	if(R.tag==1)					// B树中存在此关键字 
	{
		DeleteBTree(BT, R.pt, R.i);
		return OK;	
	}
	else
		return ERROR;
}

/*(10)从B树中删除结点q中第i个关键字。*/
Status DeleteBTree(BTree *BT, BTree q, int i)
{
	Result R = {q, i, 1};
	
	if(i<1||i>q->keynum)					// 第i个关键字需存在 
		return ERROR;
	
	if(q->ptr[i])
		SearchMinKey(q->ptr[i], &R);
		
	q->key[i] = R.pt->key[R.i];				// 用右子树中最小结点替换当前结点		 
		
	Delete(BT, R.pt, R.i);					// 开始删除R.pt中第R.i个元素
	
	return OK;
}

/*(11)从B树中删除结点q中第i个关键字(特殊)。*/
void Delete(BTree *BT, BTree q, int i)
{
	int s, tag, order, count;
	BTree p, lc, rc;
	
	s = ceil((double)M/2);
	p = NULL;										// 指向q的父结点 
	order = -1;									// q为p的第j个关键字 
	
	tag = 0;										// 初始化为0 
	
	if(!FoundParent(q, &p, &order))				// 只有一个根结点
		tag = 1;
	else
	{
		if(q->keynum>=s)			// q->keynum>=┌M/2┐
			tag = 2;						// 直接删除结点 
		else									// q->keynum==┌M/2┐-1 
		{			
			if(tag==0 && order<p->keynum && p->ptr[order+1]->keynum>=s)
				tag = 3;					// 右兄弟关键字个数>=┌M/2┐
			
			if(tag==0 && order>0 && p->ptr[order-1]->keynum>=s)
				tag = 4; 					// 左兄弟关键字个数>=┌M/2┐
										
			if(tag==0 && order<p->keynum && p->ptr[order+1]->keynum==s-1)
				tag = 5;					// 右兄弟关键字个数==┌M/2┐-1
			
			if(tag==0 && order>0 && p->ptr[order-1]->keynum==s-1 )
				tag = 6;					// 左兄弟关键字个数==┌M/2┐-1
		}	
	}
	
	switch(tag)
	{
		case 1:
			if(q->keynum==1&&i==1)
			{
				*BT = q->ptr[0];
				free(q);
			}
			else
			{
				LeftMove(q, i+1, q, i, q->keynum-i);
				q->keynum--;			
			}
			break;
		case 2:
			LeftMove(q, i+1, q, i, q->keynum-i);
			q->keynum--;
			break;
		case 3:
			rc = p->ptr[order+1];
			LeftMove(q, i+1, q, i, q->keynum-i);
			q->key[q->keynum] = p->key[order+1];
			q->ptr[q->keynum] = rc->ptr[0];
			p->key[order+1] = rc->key[1];
			rc->ptr[0] = rc->ptr[1];
			LeftMove(rc, 2, rc, 1, rc->keynum-1);
			rc->keynum--;
			break;
		case 4:
			lc = p->ptr[order-1];										// 找到兄弟结点
			q->ptr[i] = q->ptr[i-1];
			RightMove(q, i-1, q, i, i-1);
			q->key[1] = p->key[order];							// 将父结点p中的中间元素加入到q结点中
			q->ptr[0] = lc->ptr[lc->keynum];				// 将左兄弟结点的最右指针加入到q结点的最左端
			p->key[order] = lc->key[lc->keynum];		// 将左兄弟结点的值最大的元素加入到父结点中	
			lc->keynum--;														// 左兄弟结点元素数减一
			break;
		case 5:
			rc = p->ptr[order+1];
			LeftMove(q, i+1, q, i, q->keynum-i);		// 将q指向结点中待删除元素的后序元素依次向前移动
			q->key[q->keynum] = p->key[order+1];		// 将父结点p中的中间元素加入到q结点中
			q->ptr[q->keynum] = rc->ptr[0];					// 将兄弟结点的指针加入到q结点中
			LeftMove(rc, 1, q, q->keynum+1, rc->keynum);	// 将兄弟结点中的所有元素和指针合并到q结点中
			q->keynum += rc->keynum;
			free(p->ptr[order+1]);									// 删除合并后的多余结点
			LeftMove(p, order+2, p, order+1, p->keynum-order-1);	// 由于父结点p中的元素加入q中，p中的剩余结点向前移动
			p->keynum--;														// p元素数减一
			if(p->keynum<s-1)												// 如果合并后使得父结点无法满足B树条件，则父结点首先尝试借其兄弟结点的元素，否则继续向上递归合并，直到根的孩子被合并
			{
				p->keynum++;				// 构造一个虚拟关键字 
				q = p;
				Delete(BT, q, q->keynum);
			}
			break;
		case 6:
			lc = p->ptr[order-1];																	// 左兄弟结点
			lc->key[lc->keynum+1] = p->key[order];								// 将父结点加入
			lc->ptr[lc->keynum+1] = q->ptr[0];
			LeftMove(q, 1, lc, lc->keynum+2, i-1);								// 将q中剩余元素赋值到lc中
			LeftMove(q, i+1, rc, lc->keynum+i+1, q->keynum-i);
			lc->keynum += q->keynum;
			free(p->ptr[order]);
			LeftMove(p, order+1, p, order, p->keynum-order);
			p->keynum--;
			if(p->keynum<s-1)
			{
				p->keynum++;				// 构造一个虚拟关键字 
				q = p;
				Delete(BT, q, q->keynum);				
			}
			break;
	}
}

/*(12)找出BT中最小的关键字。*/
Status SearchMinKey(BTree BT, Result *R)
{
	BTree q = BT;
	
	while(q && q->ptr[0])					// 向最下层最左端结点移动
		q = q->ptr[0];
	
	if(q)
	{
		(*R).pt = q;
		(*R).i = 1;
		(*R).tag = 1;
		return OK;
	}
	else
		return ERROR;	
}

/*(13)寻找双亲结点：q为p的第j个孩子。*/
Status FoundParent(BTree q, BTree *p, int *order)		// B树不为空 
{
	*p = q->parent;
	
	if(*p==NULL)				// q指向根结点 
	{
		*order = -1;
		return ERROR;
	}
	else
	{
		for(*order=0; (*p)->ptr[*order]!=q; (*order)++)
			;
		return OK;
	}
}

/*(14)向左移动关键字和指针。*/
Status LeftMove(BTree old_ptr, int m, BTree new_ptr, int n, int len)
{	// 将old_ptr所指向结点中的key/ptr[m...m+len-1]赋值给new_ptr所指向结点中的key/ptr[n...n+len-1]
	int k;
	
	if(!old_ptr || !new_ptr || m<1 || m>old_ptr->keynum)
		return ERROR;
	
	for(k=0; k<len; k++,m++,n++)
	{
		new_ptr->key[n] = old_ptr->key[m];
		new_ptr->ptr[n] = old_ptr->ptr[m];
	}
	
	return OK;
}

/*(15)向右移动关键字和指针。*/
Status RightMove(BTree old_ptr, int m, BTree new_ptr, int n, int len)
{
	int k;

	if(!old_ptr || !new_ptr || m<1 || m>old_ptr->keynum)
		return ERROR;
	
	for(k=0; k<len; k++,m--,n--)
	{
		new_ptr->key[n] = old_ptr->key[m];
		new_ptr->ptr[n-1] = old_ptr->ptr[m-1];
	}
	
	return OK;
}

/*(16)层序输出B树。*/
void PrintBT_Level(BTree BT)
{
	BTree p[100], q[100];
	int i, j, k;
	int a, b, count;
	
	a = 1;
	p[a] = BT;
	count = 0;
	
	while(a)
	{
		printf("  第 %2d 行关键字：", ++count);
		
		b = 0;
		for(i=1; i<=a; i++)
		{
			printf("(");			
			for(j=0; j<=p[i]->keynum; j++)
			{
				if(j)
					printf(" %2d", p[i]->key[j]);
				
				if(p[i]->ptr[j])
					q[++b] = p[i]->ptr[j];
			}
			printf(") ");			
		}
		
		printf("\n");
		
		a = b;
		for(k=1; k<=b; k++)
			p[k] = q[k];
	}
}

/*(17)中序输出B树。*/
void PrintBT_InOrder(BTree BT)
{
	int j;
	
	if(BT)
	{
		for(j=0; j<=BT->keynum; j++)
		{
			PrintBT_InOrder(BT->ptr[j]);
			if(j<BT->keynum)
				printf("%d ", BT->key[j+1]);		
		}	
	}
}