/****************************************
 *						                          *
 * 文件夹: 06_Tree_and_BinTree/08_MFSet *
 * 						                          *
 * 文件名: MFSet.c                      *
 *    	    			                      *
 * 算  法: 6.8、6.9、6.10、6.11         *  
 *    	    					                  *
 ****************************************/

#ifndef MFSET_C
#define MFSET_C

#include "MFSet.h" 								/* 06_Tree_and_BinTree */

/*(01)构造一个由n个子集（每个子集只包含单个成员）构成的集合S。*/
void Initial_mfset(FILE *fp, MFSet *S)
{
	int i;

	Scanf(fp, "%d", &(S->n));
	
	for(i=1; i<=S->n; i++)				// nodes[0]弃用 
	{
		Scanf(fp, "%d", &i);
		S->nodes[i].data = i;
		S->nodes[i].parent = -1;
	}
}

/*(02)算法6.8：查找集合S中i所在子集的根。*/
int find_mfset(MFSet S, int i)
{
	int j;
	
	if(i<1 || i>S.n)							// i不属于S中任一子集 
		return -1; 

	for(j=i; S.nodes[j].parent>0; j=S.nodes[j].parent)
		;
	
	return j;
} 

/*(03)算法6.9：求Si和Sj的并集，Si和Sj无交集。*/
Status merge_mfset(MFSet *S, int i, int j)
{
	if(i<1 || j<1 || i>S->n || j>S->n)
		return ERROR;
	
	if(i!=j)													// i与j是不同元素 
		S->nodes[i].parent = j;					// 固定将集合Si并入Sj 
	
	return OK;
}

/*(04)算法6.10：集合归并函数，算法6.9改进。*/
Status mix_mfset(MFSet *S, int i, int j)		// 令parent域存储子集中所含成员数目的负值 
{
	if(i<1 || j<1 || i>S->n || j>S->n)
		return ERROR;
	
	if(S->nodes[i].parent>S->nodes[j].parent)	// Si中成员数目较少
	{
		S->nodes[j].parent += S->nodes[i].parent; 
		S->nodes[i].parent = j;					// 将Si并入Sj 
	}
	else										// Sj中成员数目较少
	{
		S->nodes[i].parent += S->nodes[j].parent;
		S->nodes[j].parent = i;					// 将Sj并入Si 
	}
	
	return OK;
}

/*(05)算法6.11：查找集合S中i所在子集的根, 算法6.8改进。*/
int fix_mfset(MFSet *S, int i)					// 将i至根路径上所有结点压缩为根的孩子结点 
{
	int j, k, t;
	
	if(i<1 || i>S->n)							// i不属于S中任一子集 
		return -1; 
	
	for(j=i; S->nodes[j].parent>0; j=S->nodes[j].parent);	// 找到i所在子集根结点 
	
	for(k=i; k!=j; k=t)							// 顺便压缩路径 
	{
		t = S->nodes[k].parent;				// t为当前结点的父结点 
		S->nodes[k].parent = j;
	}
	
	return j;	
}

/*(06)建立二元等价关系。*/
Status BuildRelation_mfset(FILE *fp, Relation *R)
{
	int k;

	Scanf(fp, "%d", &(R->n));		
	if(R->n<0)
		return ERROR;
	
	for(k=1; k<=R->n; k++)
		Scanf(fp, "%d%d", &(R->nodes[k-1].i), &(R->nodes[k-1].j));
	
	return OK;
}

/*(07-1)求在等价关系R下集合S的等价类。*/
Status EquivalenceClass_mfset_1(MFSet *S, Relation R)
{
	int k, x, y;
	
	for(k=0; k<R.n; k++)
	{
		x = find_mfset(*S, R.nodes[k].i);		// 分别求取当前元素所属子集 
		y = find_mfset(*S, R.nodes[k].j);
		merge_mfset(S, x, y);					// 合并子集 
	}

	return OK;
}

/*(07-2)求在等价关系R下集合S的等价类。*/
Status EquivalenceClass_mfset_2(MFSet *S, Relation R)
{
	int k, x, y;
	
	for(k=0; k<R.n; k++)
	{
		x = fix_mfset(S, R.nodes[k].i);			// 分别求取当前元素所属子集 
		y = fix_mfset(S, R.nodes[k].j);
		mix_mfset(S, x, y);						// 合并子集 
	}

	return OK;
}

/*(08)返回集合S中非空子集数目。*/
int SubsetCount_mfset(MFSet S)
{
	int i, count;
	
	for(i=1,count=0; i<=S.n; i++) 
	{
		if(S.nodes[i].parent<0)
			count++;
	}
	
	return count;
}

/*(09)展示集合S。*/
void ShowSet_mfset(MFSet S)
{
	int i, j, k, count;
	int a[MAX_TREE_SIZE][MAX_TREE_SIZE] = {};							// a[i][j] 表示i集合中第j个元素的值
	int tmp[MAX_TREE_SIZE] = {}; 													// tmp[j] 表示j集合中元素的个数
	
	for(i=1; i<=S.n; i++)
	{
		j = find_mfset(S, i);					// 判断第i个结点属于哪个集合 
		if(j>0)
		{
			tmp[j]++;
			a[j][tmp[j]] = S.nodes[i].data;
		}	
	}
	
	k = SubsetCount_mfset(S);					// 子集个数 
	
	printf("{");
	count = 0;												// 记录当前为第几个子集
	
	for(i=1; i<=S.n; i++)
	{
		for(j=1; j<=S.n; j++)
		{
			if(a[i][j])
			{
				if(j==1)										// 某集合第一个元素 
					printf("{%d", a[i][j]);
				else
					printf(",%d", a[i][j]);
				
				if(j==tmp[i])								// 某集合最后一个元素
				{
					count++;
					printf("}");
					if(count!=k)							// 子集之间要隔开 
						printf(", ");
				}
			}
		}
	}
	
	printf("}\n");
}

#endif