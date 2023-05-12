/**********************************************
 *							                              *
 * 文件夹: 03_Stack_and_Queue/08_CylSeqQueue  *
 *							  			                      *
 * 文件名: CylSeqQueue.c	  			            *
 *							  			                      *
 **********************************************/

#ifndef CYLSEQQUEUE_C
#define CYLSEQQUEUE_C

#include "CylSeqQueue.h"		/*03 栈和队列*/

/*(01)初始化循环队列Q。*/
Status InitQueue_CSq(CSqQueue *Q)
{
	(*Q).base = (QElemType_CSq *)malloc(MAXQSIZE*sizeof(QElemType_CSq));
	if(!(*Q).base)
		exit(OVERFLOW);		//存储分配失败 
	
	(*Q).front = (*Q).rear = 0;
	
	return OK;	
}

/*(02)置空Q。*/
void ClearQueue_CSq(CSqQueue *Q)
{
	(*Q).front = (*Q).rear = 0;
}

/*(03)销毁Q。*/
void DestroyQueue_CSq(CSqQueue *Q)
{
	if((*Q).base)
		free((*Q).base);
		
	(*Q).base = NULL;
	(*Q).front = (*Q).rear = 0;
}

/*(04)判断Q是否为空。*/
Status QueueEmpty_CSq(CSqQueue Q)
{
	if(Q.front==Q.rear)			//队列空的标志 
		return TRUE;
	else
		return FALSE; 
} 

/*(05)返回Q的元素个数。*/
int QueueLength_CSq(CSqQueue Q)
{
	return (Q.rear-Q.front+MAXQSIZE) % MAXQSIZE;
}

/*(06)用e获取队头元素。*/
Status GetHead_CSq(CSqQueue Q, QElemType_CSq *e)
{
	if(Q.front == Q.rear)		//队列空 
		return ERROR;
		
	*e = Q.base[Q.front];
	
	return OK;
}

/*(07)元素e入队。*/
Status EnQueue_CSq(CSqQueue *Q, QElemType_CSq e)
{
	if(((*Q).rear+1)%MAXQSIZE == (*Q).front)
		return ERROR;		//队列满
	
	(*Q).base[(*Q).rear] = e;
	(*Q).rear = ((*Q).rear+1) % MAXQSIZE;
	
	return OK;
}

/*(08)元素e出队。*/
Status DeQueue_CSq(CSqQueue *Q, QElemType_CSq *e)
{	//若队列不空，则删除Q的队头元素，用e返回其值，并返回OK；否则返回ERROR			
	if((*Q).front == (*Q).rear)		//队列空 
		return ERROR;
	
	*e = (*Q).base[(*Q).front];
	(*Q).front = ((*Q).front+1) % MAXQSIZE;
	
	return OK;		
}

/*(09)访问队列。*/
void Queue_Traverse_CSq(CSqQueue Q, void(Visit)(QElemType_CSq))
{
	int i = Q.front;
	
	while(i!=Q.rear)
	{
		Visit(Q.base[i]);
		i = (i+1)%MAXQSIZE;
	}
} 

#endif
