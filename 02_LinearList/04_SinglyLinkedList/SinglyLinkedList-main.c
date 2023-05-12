#include <stdio.h>
#include "SinglyLinkedList.c"

/* 函数原型 */
void PrintElem(LElemType_L e);			//测试函数，打印整型
Status CmpGreater(LElemType_L e, LElemType_L data);		//判断data是否大于e //若data大于e，返回TRUE

int main(void)
{
	LinkList L;		// 这里的 L 是一个 (LNode *)类型的变量，与InitList_L函数形参中的 L 是不同类型
					// InitList_L函数形参中的 L 是(LNode **)类型，它存放的是这里的 L 的地址
					// 为什么要在InitList_L函数中把 L 定义为(LNode **)类型？
					// 这是因为在主函数中定义的 L ，我们要在其他函数中对 L 进行操作，必须把
					// L 的地址发送过去，否则，当InitList_L函数调用完后，它定义的局部变量 L 会自动释放，
					// 相当于对主函数中的 L 没有做任何操作。
	int i;
	LElemType_L e; 
	
	printf("函数：初始化单链表L测试...\n");
	PressEnter;
	InitList_L(&L);
	printf("初始化单链表 L 成功！\n");
	printf("单链表 L 的头指针是%#x\n\n",L);
	
	printf("函数：单链表 L 是否为空测试...\n");
	PressEnter;
	ListEmpty_L(L) ? printf("L 为空！\n") :  printf("L 非空！\n");
	printf("\n"); 
	
	printf("函数：在单链表L第i个位置之前插入e。测试...\n");
	PressEnter;
	for(i=1;i<=6;i++)
	{
		printf("在 L 第 %d 个位置插入 \"%d\"\n",i,2*i);
		ListInsert_L(L,i,2*i);
	}	//此处，请使用debug调试程序，对插入的结果进行测试。
	printf("\n\n");
	
	printf("函数：遍历单链表L。测试...\n");
	PressEnter;
	printf("L 中的元素为：L = ");
	ListTraverse_L(L,PrintElem); 
 	printf("\n\n");
 	
 	printf("函数：删除单链表L第i个位置的结点，并用e接收。测试...\n");
	PressEnter;
	ListDelete_L(L,6,&e);
	printf("删除单链表L第6个位置的结点，被删除的元素为%d\n",e);
	printf("L 中的元素为：L = ");
	ListTraverse_L(L,PrintElem);
	printf("\n\n");
	
	printf("函数：单链表L的长度。测试...\n");
	PressEnter;
	printf("L 的长度为：L = %d\n",ListLength_L(L));
 	printf("\n");
	
	printf("函数：用e接收单链表L中第3个元素。测试...\n");
	PressEnter;
	GetElem_L(L,3,&e);
	printf("单链表L中第3个元素为%d\n\n",e); 
	
	printf("函数：作为示范，返回单链表L中首个比7大的元素位序。\n");
	PressEnter;
	i = LocateElem_L(L, 7, CmpGreater);
	if(i)
		printf("首个比7大的元素位序为%d\n\n",i);
	else
		printf("L中没有元素比7大！\n");
	
	printf("函数：寻找指定结点的前驱。\n");
	PressEnter;
	if(PriorElem_L(L, 6, &e))
		printf("元素\"6\" 的前驱为\"%d\"\n\n",e);
	else
		printf("输入不合法！！\n\n");

	printf("函数：寻找指定结点的后继。\n");
	PressEnter;
	if(NextElem_L(L, 6, &e))
		printf("元素\"6\" 的后继为\"%d\"\n\n",e);
	else
		printf("输入不合法！！\n\n");
	
	printf("函数：清空单链表 L 测试...\n");
	printf("清空 L 前：");
	ListEmpty_L(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");
	PressEnter; 
	ClearList_L(L);
	printf("清空 L 后：");
	ListEmpty_L(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");
	printf("\n");
	
	printf("函数：头插法建立单链表L1（逆序输入）。\n");
	PressEnter;
	{
		FILE *fp;
		LinkList L1;
		fp = fopen("TestData_HL.txt", "r");
		CreateList_HL(fp, &L1, 5);
		fclose(fp);			//关闭文件流 
		printf("L1 中的元素为：L1 = ");
		ListTraverse_L(L1,PrintElem);
		printf("\n\n");
	}
	
	printf("函数：尾插法建立单链表L2（顺序输入）。\n");
	PressEnter;
	{
		FILE *fp;
		LinkList L2;
		fp = fopen("TestData_TL.txt", "r");
		CreateList_TL(fp, &L2, 5);
		fclose(fp);			//关闭文件流 
		printf("L2 中的元素为：L2 = ");
		ListTraverse_L(L2,PrintElem);
		printf("\n\n");
	}
	
	printf("函数：销毁单链表L。\n");
	PressEnter;
	printf("销毁 L 前：");
	L ? printf(" L 存在！\n") : printf(" L 不存在！！\n");
	DestroyList_L(&L);
	printf("销毁 L 后：");
	L ? printf(" L 存在！\n") : printf(" L 不存在！！\n");
	
	return 0;
}

void PrintElem(LElemType_L e)
{
	printf("%d ",e);
}

Status CmpGreater(LElemType_L e, LElemType_L data)
{
	return (data > e) ? TRUE : FALSE;
}