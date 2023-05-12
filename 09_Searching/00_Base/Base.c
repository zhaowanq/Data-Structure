/************************
 *                      *
 * 文件夹: 09_Searching  *
 *                      *
 * 文件名: Base.c        *
 *                      *
 ************************/

#ifndef BASE_C
#define BASE_C

#include "Base.h" 					/* 09_Searching */

/*(01)创建查找表*/
Status Create(FILE *fp, Table *T, int n)
{
	int i;
	int a;
	float b;
	 
	T->elem = (ElemType_Search *)malloc((n+1)*sizeof(ElemType_Search));
	if(!(T->elem))
		exit(OVERFLOW);
	
	// 此表0号单元是弃用的 
	for((*T).length=0,i=1; i<=n; i++)
	{
		if(Scanf(fp, "%d%f", &a, &b)==2)
		{
			(*T).elem[i].key = a;
			(*T).elem[i].weight = b;
			(*T).length++;
		}
	}
	
	return OK;
}

/*(02)销毁查找表*/
void Destory(Table *T)
{
	if(T->elem)
		free(T->elem);
	
	T->elem = NULL;
	T->length = 0;
}

/*(03)遍历查找表*/
void Traverse(Table T, void(Visit)(ElemType_Search))
{
	int i;
	
	for(i=0; i<T.length; i++)
	{
		if(i && !(i%10))
			printf("\n");
		
		Visit(T.elem[i+1]);
	}
	
	printf("\n");	
}

/*(04)输出查找表中的关键字（只输出key域）*/
void PrintKey(ElemType_Search e)
{
	printf("%3d ", e.key);
}

#endif