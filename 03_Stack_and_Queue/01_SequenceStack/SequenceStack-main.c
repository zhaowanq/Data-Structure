/*****************************************
 *									 	 *
 *	文件夹: 03_Stack_and_Queue/01_SequenceStack *
 *									 	 *
 *	文件名: SequenceStack-main.c	 	 *
 *									 	 *
 *	内  容: 顺序栈相关函数测试  	 	 *
 *									 	 *
 *****************************************/

#include <stdio.h>
#include "SequenceStack.c" 		/* 03 栈和队列 */

//测试函数，打印整型 
void PrintElem(SElemType_Sq e);

int main(void)
{
	SqStack S;
	int i;
	SElemType_Sq e;
	
	printf("函数：初始化顺序栈 S 测试...\n");
	PressEnter;
	InitStack_Sq(&S);
	printf("初始化顺序栈 S 成功，它的地址为%#x\n",&S);
	printf("栈底指针为%#x,栈顶指针为%#x,栈的容量为%d\n",S.base,S.top,S.stacksize);
	printf("\n\n");
	
	printf("函数：判断顺序栈 S 是否为空...\n");
	PressEnter;
	StackEmpty_Sq(S) ? printf("S 为空！！\n") : printf("S 不为空！\n");
	printf("\n\n");
	
	printf("函数：插入元素 e 为新的栈顶元素。测试...\n");
	PressEnter; 
	for(i=1; i<=6; i++)
	{
		printf("将 \"%2d\" 压入栈 S ",2*i);
		Push_Sq(&S,2*i);
		printf("（累计第 %d 个元素）...\n", S.top-S.base);
	}	
	printf("\n\n");
	
	printf("函数：遍历顺序栈 S 。测试...\n");
	PressEnter;
	printf("S 中的元素为：S = ");
	StackTraverse_Sq(S,PrintElem);
	printf("\n\n");
	
	printf("函数：出栈，删除 S 的栈顶元素，用 e 返回其值。测试...\n");
	PressEnter;
	Pop_Sq(&S,&e);
	printf("栈顶元素 \"%d\" 出栈...\n", e); 
	printf("S 中的元素为：S = ");						 
	StackTraverse_Sq(S, PrintElem);
	printf("\n\n");
	
	printf("函数：顺序栈 S 的长度。测试...\n");
	PressEnter;
	printf("S 的长度为：%d\n",StackLength_Sq(S));						 
	printf("\n\n");
	
	printf("函数：获取顺序栈 S 的栈顶元素。测试...\n");
	PressEnter;
	GetTop_Sq(S, &e);
	printf("栈顶元素值为：\"%d\"\n",e);						 
	printf("\n\n");
	
	printf("函数：清空顺序栈 S 。测试...\n");
	PressEnter;
	printf("清空 S 前：");	
	StackEmpty_Sq(S) ? printf("S 为空！！\n") : printf("S 不为空！\n");
	ClearStack_Sq(&S);
	printf("清空 S 后：");
	StackEmpty_Sq(S) ? printf("S 为空！！\n") : printf("S 不为空！\n");
	printf("\n");
	
	printf("函数：销毁顺序栈 S 。测试...\n");
	PressEnter;
	printf("销毁 S 前：");
	S.base!=NULL && S.top!=NULL ? printf("S 存在！\n") : printf("S 不存在！！\n");
	DestroyStack_Sq(&S);
	printf("销毁 S 后：");
	S.base!=NULL && S.top!=NULL ? printf("S 存在！\n") : printf("S 不存在！！\n");
		
	return 0;
}

void PrintElem(SElemType_Sq e)
{
	printf("%d ",e);
} 