/**************************************************
*									        	                      *
*	文件夹: 02_LinearList/08_DualCycleLinkedList    * 
*									   			                        *							
*	文件名: DualCycleLinkedList-main.c 		   	      *
*									  	 		                        *
*	内  容:	双向循环链表相关函数测试			          *
*									   			                        *
**************************************************/

#include <stdio.h>
#include "DualCycleLinkedList.c"

/* 函数原型 */
void PrintElem(LElemType_DC e);			//测试函数，打印整型
Status CmpGreater(LElemType_DC e, LElemType_DC data);		//判断data是否大于e //若data大于e，返回TRUE

int main(void)
{
	DuLinkList L;	// 这里的 L 是一个 (DuLNode *)类型的变量，与InitList_DuL函数形参中的 L 是不同类型
					// InitList_DuL函数形参中的 L 是(DuLNode **)类型，它存放的是这里的 L 的地址
					// 为什么要在InitList_DuL函数中把 L 定义为(DuLNode **)类型？
					// 这是因为在主函数中定义的 L ，我们要在其他函数中对 L 进行操作，必须把
					// L 的地址发送过去，否则，当InitList_DuL函数调用完后，它定义的局部变量 L 会自动释放，
					// 相当于对主函数中的 L 没有做任何操作。
	int i;
	LElemType_DC e;
	
	printf("函数：初始化双循环链表 L 测试...\n");
	PressEnter;
	InitList_DuL(&L);
	printf("初始化双循环链表 L 成功！\n");
	printf("双循环链表 L 的头指针是%#x\n",L);
	printf("\n"); 
	
	printf("函数：双循环链表 L 是否为空测试...\n");
	PressEnter;
	ListEmpty_DuL(L) ? printf("L 为空！！\n") : printf("L 不为空！\n");
	printf("\n");
	
	printf("函数：在双循环链表 L 第i个位置之前插入e。测试...\n");
	PressEnter;
	for(i=1;i<=6;i++)
	{
		printf("在 L 第 %d 个位置插入 \"%d\"\n",i,2*i);
		ListInsert_DuL(L,i,2*i);
	}
	printf("\n\n");
	
	printf("函数：遍历双循环链表 L 。测试...\n");
	PressEnter;
	printf("L 中的元素为：L = ");
	ListTraverse_DuL(L,PrintElem); 
 	printf("\n\n");
 	
 	printf("函数：双循环链表 L 的长度。测试...\n");
	PressEnter;
	printf("L 的长度为：L = %d\n",ListLength_DuL(L));
 	printf("\n");
 	
 	printf("函数：删除双循环链表L第i个位置的结点，并用e接收。测试...\n");
	PressEnter;
	ListDelete_DuL(L,6,&e);
	printf("删除双循环链表L第6个位置的结点，被删除的元素为%d\n",e);
	printf("L 中的元素为：L = ");
	ListTraverse_DuL(L,PrintElem);
	printf("\n");
	printf("L 的长度为：L = %d\n",ListLength_DuL(L));
 	printf("\n\n");
 	
 	printf("函数：用e接收双循环链表L中第3个元素。测试...\n");
	PressEnter;
	if(GetElem_DuL(L,3,&e))
		printf("双循环链表L中第3个元素为%d\n\n",e);
 	else
 		printf("元素位置不合法！\n\n",e);
	
	printf("函数：作为示范，返回双循环链表L中首个比7大的元素位序。\n");
	PressEnter;
	i = LocateElem_DuL(L, 7, CmpGreater);
	if(i)
		printf("首个比7大的元素位序为%d\n\n",i);
	else
		printf("L中没有元素比7大！\n");
	
	printf("函数：寻找指定结点的前驱。\n");
	PressEnter;
	if(PriorElem_DuL(L, 6, &e))
		printf("元素\"6\" 的前驱为\"%d\"\n\n",e);
	else
		printf("输入不合法！！\n\n");
	
	printf("函数：寻找指定结点的后继。\n");
	PressEnter;
	if(NextElem_DuL(L, 6, &e))
		printf("元素\"6\" 的后继为\"%d\"\n\n",e);
	else
		printf("输入不合法！！\n\n");
		
	printf("函数：获取L中指向第i个结点的指针，测试...\n");
	PressEnter;
	DuLinkList p;
	p = GetElemPtr_DuL(L, 3);
	if(p)
		printf("链表 L 中第 3 个结点的指针为 %#x，其对应的元素值为 \"%d\" \n", p, p->data);
	else
		printf("输入不合法！！\n");	
	printf("\n");
	
	printf("函数：清空 L 测试...\n");
	printf("清空 L 前：");
	ListEmpty_DuL(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");
	PressEnter;
	ClearList_DuL(L);
	printf("清空 L 后：");
	ListEmpty_DuL(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");
	
	printf("\n");
	
	printf("函数：销毁 L 测试...\n");
	printf("销毁 L 前：");
	L ? printf(" L 存在！\n") : printf(" L 不存在！！\n");
	PressEnter; 
	DestroyList_DuL(&L);
	printf("销毁 L 后：");
	L ? printf(" L 存在！\n") : printf(" L 不存在！！\n");
	printf("\n");
		
	return 0;
}

void PrintElem(LElemType_DC e)
{
	printf("%d ",e);
}

Status CmpGreater(LElemType_DC e, LElemType_DC data)
{
	return (data > e) ? TRUE : FALSE;
}
