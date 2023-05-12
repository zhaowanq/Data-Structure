/************************************************
 *									 	                          *
 *	文件夹: 03_Stack_and_Queue/01_SequenceStack *
 *									 	                          *
 *	文件名: SequenceStack.c			 	              *
 *									 	                          *
 ************************************************/

#ifndef SEQUENCESTACK_C
#define SEQUENCESTACK_C

#include "SequenceStack.h"		/* 03 栈和队列 */

/*(01)构造空栈S。*/
Status InitStack_Sq(SqStack *S)
{
	(*S).base = (SElemType_Sq *)malloc(STACK_INIT_SIZE * sizeof(SElemType_Sq));
	if(!(*S).base)
		exit(OVERFLOW);		//存储分配失败 
	
	(*S).top = (*S).base;
	(*S).stacksize = STACK_INIT_SIZE;
	
	return OK;
}

/*(02)销毁栈S。*/
Status DestroyStack_Sq(SqStack *S)
{
	free((*S).base);
	
	(*S).base = (*S).top = NULL;
	(*S).stacksize = 0;
	
	return OK;
}

/*(03)将栈S置为空栈。*/
Status ClearStack_Sq(SqStack *S)
{
	(*S).top = (*S).base;
	
	return OK;
}

/*(04)判断S是否为空。*/
Status StackEmpty_Sq(SqStack S)
{
	return (S.base==S.top) ? TRUE : FALSE;
}

/*(05)返回S元素个数。*/
int StackLength_Sq(SqStack S)
{
	return S.top-S.base;
}

/*(06)用e获取栈顶元素。*/
Status GetTop_Sq(SqStack S, SElemType_Sq *e)
{
	if(S.base==S.top)
		return ERROR;
	
	*e = *(S.top-1);	//并不破坏栈 
	
	return OK;	
}

/*(07)元素e进栈。*/
Status Push_Sq(SqStack *S, SElemType_Sq e)
{
	if(((*S).top-(*S).base) >= (*S).stacksize)	//栈满，追加存储空间，栈顶指针可以指向未分配存储空间的单元，但是注意不要取其内容，如*((*S).top)。 
	{
		(*S).base = (SElemType_Sq *)realloc((*S).base, ((*S).stacksize+STACKINCREMENT)*sizeof(SElemType_Sq));
		if(!(*S).base)
			exit(OVERFLOW);		//存储分配失败
		 (*S).top = (*S).base + (*S).stacksize;		//这行代码的作用发挥在以下情况。如果原先的内存区域后面没有足够的空闲空间用来分配，那么从堆中另外找一块newsize大小的内存。
 		  											//并把原来大小内存空间中的内容复制到新分配的内存区域。返回新的指针。（数据被移动了）。
 		  											//老块被放回堆上，也就是说，旧的mem_address指向的旧内存已被free掉了。 
		 (*S).stacksize += STACKINCREMENT;
	}
	*((*S).top)++ = e;			//进栈先赋值，栈顶指针再自增
	return OK;
}

/*(08)元素e出栈。*/
Status Pop_Sq(SqStack *S, SElemType_Sq *e)
{
	if((*S).top == (*S).base)
		return ERROR;
	
	--(*S).top;					//出栈栈顶指针先递减，再赋值
	*e = *((*S).top);
	
	return OK;
}


/*(09)访问栈。*/
Status StackTraverse_Sq(SqStack S, void(Visit)(SElemType_Sq))
{									//遍历不应该破坏栈
	SElemType_Sq *p;

	p = S.base;
	
	while(p<S.top)
		Visit(*p++);
	
	return OK;	
}

#endif
