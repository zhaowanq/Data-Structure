/********************************************
*									                          *
*	文件夹: 02_LinearList/06_StaticLinkedList * 
*									   	                      *							
*	文件名: StaticLinkedList-main.c   	      *
*									  	                      *
*	内  容:	静态链表相关函数测试		          *
*									   	                      *
********************************************/

#include <stdio.h>
#include "StaticLinkedList.c"

/* 函数原型 */
void PrintElem(LElemType_S e);		//测试函数，打印整型

int main(void)
{
	SLinkList H;
	LElemType_S e;
	int i;
	
	printf("函数：初始化静态链表的备用空间 SPACE ...\n");
	PressEnter;
	InitSpace_SL();
	printf("初始化 SPACE 成功，首地址为%#x\n\n",SPACE);
	
	printf("初始化静态链表 H ，用Malloc_SL申请空间...\n");
	PressEnter;
	InitList_SL(&H);
	printf("头结点所在的内存地址为%#x\n\n",&SPACE[H]);
	
	printf("静态链表 H 判空测试...\n");
	PressEnter;
	ListEmpty_SL(H) ? printf(" H 为空！！\n") : printf(" H 不为空！\n");
	printf("\n");
	
	printf("函数：在静态链表H第i个位置插入e。测试...\n");
	PressEnter;
	for(i=1;i<=6;i++)
	{
		printf("在 H 第 %d 个位置插入 \"%d\"\n",i,2*i);
		ListInsert_SL(H,i,2*i);
	}
	printf("\n");
	
	printf("函数：遍历静态链表 H 测试...\n");
	PressEnter;
	printf("H 中的元素为：H = ");
	ListTraverse_SL(H,PrintElem);
	printf("\n\n");
	
	printf("静态链表 H 的长度测试...\n");
	PressEnter;
	printf("H 的长度为%d\n",ListLength_SL(H));
	printf("\n");
	
	printf("删除指定结点测试...\n");
	PressEnter;
	ListDelete_SL(H, 6, &e);
	printf("删除 H 中第 6 个元素 \"%d\" ，用Free_SL释放空间...\n", e);	
	printf("H 的元素为：H = ");						 
	ListTraverse_SL(H, PrintElem);
	printf("\n");
	printf("H 的长度为%d\n",ListLength_SL(H));
	printf("\n\n"); 
	
	printf("函数：获取 H 中第 i 个位置的元素\n");
	PressEnter;
	GetElem_SL(H,4,&e);
	printf("H 中第 4 个位置的元素为 \"%d\" \n", e);
	printf("\n");
	
	printf("函数：查找 H 中值为e的元素，返回它的位序。\n");
	PressEnter;
	printf("元素 \"8\" 在 H 中的位序为 %d \n", LocateElem_SL(H, 8)); 
	printf("\n");
	
	printf("函数：寻找指定结点的前驱。\n");
	PressEnter;
	if(PriorElem_SL(H, 6, &e))
		printf("元素\"6\" 的前驱为\"%d\"\n\n",e);
	else
		printf("输入不合法！！\n\n");
	
	printf("函数：寻找指定结点的后继。\n");
	PressEnter;
	if(NextElem_SL(H, 6, &e))
		printf("元素\"6\" 的后继为\"%d\"\n\n",e);
	else
		printf("输入不合法！！\n\n");
	
	printf("函数：清空静态链表 H 测试...\n");
	PressEnter; 
	printf("清空 H 前：");
	ListEmpty_SL(H) ? printf(" H 为空！！\n") : printf(" H 不为空！\n");
	ClearList_SL(H);
	printf("清空 H 后：");
	ListEmpty_SL(H) ? printf(" H 为空！！\n") : printf(" H 不为空！\n");
	printf("\n");
	 
	printf("函数：销毁静态链表 H 测试...\n");
	PressEnter; 
	printf("销毁 H 前：");
	H ? printf(" H 存在！\n") : printf(" H 不存在！！\n");
	DestroyList_SL(&H);
	printf("销毁 H 后：");
	H ? printf(" H 存在！\n") : printf(" H 不存在！！\n");
	printf("\n");
		
	return 0;
}

void PrintElem(LElemType_S e)
{
	printf("%d ",e);
} 
 
