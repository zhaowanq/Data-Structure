/********************************************
 *                                          *
 * 文件夹: 03_Stack_and_Queue/07_LinkQueue  *
 *                                          *
 * 文件名: LinkQueue.c                      *
 *                                          *
 ********************************************/

#ifndef LINKQUEUE_C
#define LINKQUEUE_C

#include "LinkQueue.h"		/*03 栈和队列*/

/*(01)初始化链队Q。*/
Status InitQueue_L(LinkQueue *Q)
{
	(*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(QNode));
	if(!(*Q).front)
		exit(OVERFLOW);		//存储分配失败
		
	(*Q).front->next = NULL;
	
	return OK;	
}

/*(02)置空Q。*/
void ClearQueue_L(LinkQueue *Q)
{
	(*Q).rear = (*Q).front->next;
	
	while((*Q).rear)
	{
		(*Q).front->next = (*Q).rear->next;
		free((*Q).rear);
		(*Q).rear = (*Q).front->next;
	}
	
	(*Q).rear = (*Q).front;	
}

/*(03)销毁Q。*/
void DestroyQueue_L(LinkQueue *Q)
{
	while((*Q).front)
	{
		(*Q).rear = (*Q).front->next;
		free((*Q).front);
		(*Q).front = (*Q).rear; 
	}
		
}

/*(04)判断Q是否为空。*/
Status QueueEmpty_L(LinkQueue Q)
{
	return Q.front== Q.rear ? TRUE : FALSE;  
}

/*(05)返回Q元素个数。*/
int QueueLength_L(LinkQueue Q)
{
	QueuePtr p = Q.front;
	int count = 0;
	 
	while(p!=Q.rear)
	{
		count++;
		p = p->next;
	}
	
	return count;
}

/*(06)用e获取队头元素。*/
Status GetHead_L(LinkQueue Q, QElemType_L *e)
{
	if(Q.front==Q.rear)
		return ERROR;
		
	*e = Q.front->next->data;
	
	return OK;
}

/*(07)元素e入队。*/
Status EnQueue_L(LinkQueue *Q, QElemType_L e)
{
	QueuePtr p;
	
	p = (QueuePtr)malloc(sizeof(QNode));
	if(!p)
		exit(OVERFLOW);		//存储分配失败
		
	p->data = e;
	p->next = NULL;
	
	(*Q).rear->next = p;
	(*Q).rear = p;
	
	return OK;
}

/*(08)元素e出队。*/
Status DeQueue_L(LinkQueue *Q, QElemType_L *e)
{
	QueuePtr p;
	
	if((*Q).front == (*Q).rear)	//队列空 
		return ERROR;
	
	p = (*Q).front->next;
	*e = p->data;
	
	(*Q).front->next = p->next;
	if((*Q).rear == p)			//删除最后一个结点后，队尾指针指向头结点 
		(*Q).rear = (*Q).front;
	free(p);
	
	return OK;
}

/*(09)访问队列。*/
void QueueTraverse_L(LinkQueue Q, void(Visit)(QElemType_L))
{
	QueuePtr p = Q.front->next;
	 
	while(p)
	{
		Visit(p->data);
		p = p->next;
	}
}

#endif
