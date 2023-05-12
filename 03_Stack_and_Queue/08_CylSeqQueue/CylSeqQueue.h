/**********************************************
 *							                              *
 * 文件夹: 03_Stack_and_Queue/08_CylSeqQueue  *
 *							  			                      *
 * 文件名: CylSeqQueue.h	  			            *
 *							  			                      *
 * 内  容: 循环队列相关操作列表	 		          *
 *							  			                      *
 **********************************************/

#ifndef CYLSEQQUEUE_H
#define CYLSEQQUEUE_H

#include <stdio.h>
#include <stdlib.h>					//提供malloc、realloc、free、exit原型
#include "../../01_Preface/Status.h"	/*01 绪论*/

/* 宏定义 */
#define MAXQSIZE 100	//最大队列长度

/* 循环队列类型定义 */
typedef int QElemType_CSq;
typedef struct					//队列的顺序存储结构 
{
	QElemType_CSq *base;		//初始化的动态分配存储空间 
	int front;					//头指针，若队列不空，指向队头元素 
	int rear;					//尾指针，若队列不空，指向队尾元素的下一个位置 
}CSqQueue;

// 少用一个元素空间，约定以“队列头指针在队列尾指针的下一位置（指环状的下一位置）上”
// 作为队列呈“满”状态的标志。

/* 循环队列函数列表 */
/*(01)初始化循环队列Q。*/
Status InitQueue_CSq(CSqQueue *Q);

/*(02)置空Q。*/
void ClearQueue_CSq(CSqQueue *Q);

/*(03)销毁Q。*/
void DestroyQueue_CSq(CSqQueue *Q);

/*(04)判断Q是否为空。*/
Status QueueEmpty_CSq(CSqQueue Q);
 
/*(05)返回Q的元素个数。*/
int QueueLength_CSq(CSqQueue Q);

/*(06)用e获取队头元素。*/
Status GetHead_CSq(CSqQueue Q, QElemType_CSq *e);

/*(07)元素e入队。*/
Status EnQueue_CSq(CSqQueue *Q, QElemType_CSq e);

/*(08)元素e出队。*/
Status DeQueue_CSq(CSqQueue *Q, QElemType_CSq *e);

/*(09)访问队列。*/
void Queue_Traverse_CSq(CSqQueue Q, void(Visit)(QElemType_CSq));

#endif
