/*****************************************
*				                                 *
*	文件夹: 02_LinearList/01_SequenceList  * 
*                                        *							
*	文件名: SequenceList-main.c            *
*                                        *
*	内  容:	单链表顺序结构相关函数测试     *
*                                        *
*****************************************/

#include <stdio.h>
#include "SequenceList.c"

/* 测试调用的函数原型 */

/* 测试函数-打印整型 */
void PrintElem(LElemType_Sq e);
/* 若data>e，返回TRUE，否则返回FALSE */
Status CmpGreater(LElemType_Sq e, LElemType_Sq data); 

int main(void)
{
	SqList L;	//这里注意：不要把间接寻址运算符用于未初始化的指针变量。 
				//不要写成SqList *L;	if (InitList_Sq(L))
				//因为在InitList_Sq函数中会用到间接寻址符，即
				//(*L).elem = (LElemType_Sq*)malloc(LIST_INIT_SIZE*sizeof(LElemType_Sq));
	int i; 
	LElemType_Sq e;
	
	InitList_Sq(&L);
	printf("初始化顺序表成功\n");
	printf("顺序表的基地址为%#x\n",(&L)->elem);
	printf("\n");
	
	printf("函数：测试顺序表是否为空\n");
	PressEnter;
	ListEmpty_Sq(L) ? printf("L为空！\n"): printf("L不为空！\n");
	printf("\n");
	
	printf("函数：在第i个位置插入元素e到顺序表中\n");
	PressEnter;
	for(i=1; i<=6; i++)									
	{
		printf("作为示范，在 L 第 %d 个位置插入 \"%d\"...\n", i, 2*i);
		ListInsert_Sq(&L, i, 2*i);
	}
	printf("\n");
	
	
	printf("函数：顺序表L中元素的个数\n");
	PressEnter;
	printf("顺序表L中一共有%d个元素\n",ListLength_Sq(L));
	printf("\n");
	
	printf("函数：作为示范，获取顺序表L中第1个元素\n");
	PressEnter;
	if(GetElem_Sq(L, 1, &e))
		printf("顺序表L中第1个元素为%d\n",e);
	else
		printf("输入的元素位置不合法！\n");
	printf("\n");
	
	printf("函数：遍历顺序表L中的元素\n");
	PressEnter;
	printf("L 中的元素为：L = ");
	ListTraverse_Sq(L, PrintElem);
	printf("\n\n");
	
	printf("作为示范，删除顺序表L的第1个元素，并将删除后的元素放入e中。\n");
	PressEnter;
	if(ListDelete_Sq(&L,1,&e))
		printf("删除成功！被删除的元素是%d\n",e);
	else
		printf("删除失败，元素位置不合法！\n");
		
	printf("删除之后的顺序表为：");
	ListTraverse_Sq(L, PrintElem);
	printf("\n\n");
	
	printf("函数：作为示范，返回顺序表L中首个比7大的元素位序。\n");
	PressEnter;
	i = LocateElem_Sq(L,7,CmpGreater);
	if(i)
		printf("首个比7大的元素位序为%d\n",i);
	else
		printf("顺序表L中没有元素比7大！\n");
	printf("\n");
	
	printf("函数：作为示范，找出顺序表L中值为10的元素前面的元素\n");
	PressEnter;
	if(PriorElem_Sq(L, 10, &i))
		printf("元素\"10\"的前驱为%d\n",i);
	else
		printf("输入不合法！\n"); 	
	printf("\n");
	
	printf("函数：作为示范，找出顺序表L中值为10的元素后面的元素\n");
	PressEnter;
	if(NextElem_Sq(L, 10, &i))
		printf("元素\"10\"的后继为%d\n",i);
	else
		printf("输入不合法！\n"); 	
	printf("\n");
	
		
	printf("函数：清空顺序表L\n");
	PressEnter;
	printf("清空L之前：");
	ListEmpty_Sq(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");
	ClearList_Sq(&L); 
	printf("清空L之后：");
	ListEmpty_Sq(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");
	printf("\n");
	
	printf("函数：销毁顺序表L\n");
	PressEnter;
	printf("销毁 L 前：");
	L.elem ? printf(" L 存在！\n") : printf(" L 不存在！！\n");
	DestroyList_Sq(&L);
	printf("销毁 L 后：");
	L.elem ? printf(" L 存在！\n") : printf(" L 不存在！！\n");
	printf("\n");
		
	return 0;
}

void PrintElem(LElemType_Sq e)
{
	printf("%d ",e);
}
Status CmpGreater(LElemType_Sq e, LElemType_Sq data)
{
	return (data > e)? TRUE : FALSE;
}
