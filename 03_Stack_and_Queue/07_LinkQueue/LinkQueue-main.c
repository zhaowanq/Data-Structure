/********************************************
 *                                          *
 * 文件夹: 03_Stack_and_Queue/07_LinkQueue  *
 *                                          *
 * 文件名: LinkQueue-main.c                 *
 *                                          *
 * 内  容: 链队相关函数测试                 *
 *                                          *
 ********************************************/
 
#include "LinkQueue.c"		/*03 栈和队列*/

void PrintElem(QElemType_L e);

int main(void)
{
	LinkQueue Q;
	int i;
	QElemType_L e;
	
	printf("函数：初始化链队Q。测试...\n");
	PressEnter;
	InitQueue_L(&Q);
	printf("初始化链队Q成功，Q的地址为0x%x\n",&Q);
	printf("头结点的地址为0x%x\n\n",Q.front);
	printf("队头指针为0x%x，队尾指针为0x%x\n",Q.front, Q.rear);
	
	
	
	printf("函数：判断Q是否为空。测试...\n");
	PressEnter;
	QueueEmpty_L(Q) ? printf("Q 为空！！\n") : printf("Q 不为空！\n");
	printf("\n");  
	
	
	printf("函数：元素e入队。测试...\n");
	PressEnter;
	for(i=1; i<=6; i++)
	{
		printf("元素 \"%2d\" 入队，", 2*i);
		EnQueue_L(&Q, 2*i);
		printf("（累计第 %d 个元素）...\n", QueueLength_L(Q));
	}
	printf("\n\n");
	
	
	printf("函数：访问队列。测试...\n");
	PressEnter;
	printf("Q 中的元素为：Q = ");
	QueueTraverse_L(Q, PrintElem);
	printf("\n\n");
	
	
	printf("函数：元素e出队。测试...\n");
	PressEnter;
	DeQueue_L(&Q, &e);
	printf("队头元素 \"%d\" 出队...\n", e);
	printf("Q 中的元素为：Q = ");
	QueueTraverse_L(Q, PrintElem);
	printf("\n\n");
 
 
	printf("函数：返回Q元素个数。测试...\n");
	PressEnter;
	i = QueueLength_L(Q);
	printf("Q 的长度为 %d \n", i);
	printf("\n");
	
	printf("函数：获取队头元素。测试...\n");
	PressEnter;
	GetHead_L(Q, &e);
	printf("Q 的队头元素为 %d \n", e);
	printf("\n");
	
	
	printf("函数：置空Q。测试...\n");
	PressEnter;
	printf("置空Q之前：");
	QueueEmpty_L(Q) ? printf("Q 为空！！\n") : printf("Q 不为空！\n");
	ClearQueue_L(&Q); 
	printf("置空Q之后：");
	QueueEmpty_L(Q) ? printf("Q 为空！！\n") : printf("Q 不为空！\n");
	printf("\n");
	
	
	printf("函数：销毁Q。测试...\n");
	PressEnter;
	printf("销毁Q之前：");
	Q.front&&Q.rear ? printf("Q 存在！\n") : printf("Q 不存在！！\n");
	DestroyQueue_L(&Q);
	printf("销毁Q之后：");
	Q.front&&Q.rear ? printf("Q 存在！\n") : printf("Q 不存在！！\n");
	printf("\n");
	 
	return 0;
}

void PrintElem(QElemType_L e)
{
	printf("%d ",e);
}
