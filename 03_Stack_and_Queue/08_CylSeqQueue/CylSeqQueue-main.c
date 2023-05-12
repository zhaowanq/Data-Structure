/**********************************************
 *							                              *
 * 文件夹: 03_Stack_and_Queue/08_CylSeqQueue  *
 *							  			                      *
 * 文件名: CylSeqQueue-main.c			            *
 *							  			                      *
 * 内  容: 循环队列相关函数测试	 		          *
 *							  			                      *
 **********************************************/
 
#include "CylSeqQueue.c"

void PrintElem(QElemType_CSq e);

int main(void)
{
	CSqQueue Q;
	int i;
	QElemType_CSq e;
	
	
	printf("函数：初始化循环队列Q。测试...\n");
	PressEnter;
	InitQueue_CSq(&Q);
	printf("初始化循环队列Q成功，Q的地址为0x%x\n",&Q);
	printf("为循环队列分配的存储空间的首地址为0x%x\n",Q.base);
	printf("队头指针为%d，队尾指针为%d\n\n",Q.front, Q.rear);
	
	
	printf("函数：判断循环队列Q是否为空。测试...\n");
	PressEnter;
	QueueEmpty_CSq(Q) ? printf("循环队列 Q 为空！！\n") : printf("循环队列 Q 不为空！\n"); 
	printf("\n");
	
	
	printf("函数：元素e入队。测试...\n");
	PressEnter;
	for(i=1; i<=6; i++)
	{
		printf("元素 \"%2d\" 入队，", 2*i);
		EnQueue_CSq(&Q, 2*i);
		printf("（累计第 %d 个元素）...\n", QueueLength_CSq(Q));
	}
	printf("\n");
	
	
	printf("函数：访问队列。测试...\n");
	PressEnter;
	printf("循环队列 Q 中的元素为：Q = ");
	Queue_Traverse_CSq(Q,PrintElem); 
	printf("\n\n");
	
	
	printf("函数：元素e出队。测试...\n");
	PressEnter;
	DeQueue_CSq(&Q, &e);
	printf("队头元素 \"%d\" 出队...\n", e);
	printf("Q 中的元素为：Q = ");
	Queue_Traverse_CSq(Q,PrintElem); 
	printf("\n\n");
	
	
	printf("函数：返回Q元素个数。测试...\n");
	PressEnter;
	i = QueueLength_CSq(Q);
	printf("Q 的长度为 %d \n", i);
	printf("\n");
	
	
	printf("函数：获取队头元素。测试...\n");
	PressEnter;
	GetHead_CSq(Q, &e);
	printf("Q 的队头元素为 %d \n", e);
	printf("\n");
	
	
	printf("函数：置空Q。测试...\n");
	PressEnter;
	printf("置空Q之前：");
	QueueEmpty_CSq(Q) ? printf("循环队列 Q 为空！！\n") : printf("循环队列 Q 不为空！\n"); 
	ClearQueue_CSq(&Q); 
	printf("置空Q之后：");
	QueueEmpty_CSq(Q) ? printf("循环队列 Q 为空！！\n") : printf("循环队列 Q 不为空！\n");
	printf("\n");
	
	
	printf("函数：销毁Q。测试...\n");
	PressEnter;
	printf("销毁Q之前：");
	Q.base!=NULL ? printf("Q 存在！\n") : printf("Q 不存在！！\n");
	DestroyQueue_CSq(&Q);
	printf("销毁Q之后：");
	Q.base!=NULL ? printf("Q 存在！\n") : printf("Q 不存在！！\n");
	printf("\n");
	 
	return 0;
}

void PrintElem(QElemType_CSq e)
{
	printf("%d ",e);
}
