/**********************************************
 *							                              *
 * 文件夹: 03_Stack_and_Queue/05_Expression   *
 * 							                              *
 * 文件名: Expression.c                       *
 * 							                              *
 * 内  容: 算法3.4				                    *
 *                                            *
 **********************************************/
 
#ifndef EXPRESSION_C
#define EXPRESSION_C

#include "Expression.h"					/*03 栈和队列*/

/*(01)算法3.4：表达式求值，假设表达式中操作数均只有一位。*/
OperandType EvaluateExpression(char exp[])	//从exp读入表达式 
{
	//算术表达式求值的算符优先算法。设OPTR和OPND分别为运算符栈和运算数栈，
	//OP为运算符集合。 
	
	SqStack OPTR, OPND;
	SElemType_Sq e, ch;
	OperatorType theta, x;
	OperandType a, b;
	int i;
	
	InitStack_Sq(&OPTR);
	Push_Sq(&OPTR,'#');
	InitStack_Sq(&OPND);
	
	i = 0;
	ch = exp[i++];
	
	while(ch!='#' || GetTop_OPTR(OPTR)!='#')
	{
		if(!In(ch))
		{
			Push_Sq(&OPND, ch);
			ch = exp[i++];
		}
		else
		{
			switch(Precede(GetTop_OPTR(OPTR), ch))
			{
				case '<' :	//栈顶元素优先权低，继续进栈 
					Push_Sq(&OPTR, ch);
					ch = exp[i++];
					break;
				
				case '=' :	//脱括号并接收下一字符
					Pop_Sq(&OPTR, &x);
					ch = exp[i++];
					break;
				
				case '>' :	//栈顶元素优先权高，退栈并将运算结果入栈
					Pop_Sq(&OPTR, &theta);
					Pop_Sq(&OPND, &b);
					Pop_Sq(&OPND, &a);
					Push_Sq(&OPND, Operate(a, theta, b));
					break;			//这儿没有读字符，c保留的还是刚才读到的字符
			}
		}
			
		
	}
	
	GetTop_Sq(OPND,&e);
	return e;
			
} 

/*(02)获取操作符栈的栈顶元素。*/
OperatorType GetTop_OPTR(SqStack OPTR)
{
	OperatorType e;
	
	GetTop_Sq(OPTR, &e);
	
	return e;
}

/*(03)判断c是否属于操作符集。*/
Status In(SElemType_Sq c)
{
	switch(c)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '(':
		case ')':
		case '#':
			return TRUE;
		default :
			return FALSE;		
	}
}

/*(04)判断栈中操作符o1与表达式中的操作符o2的优先级。*/
OperatorType Precede(OperatorType o1, OperatorType o2)
{
	OperatorType f;
	
	switch(o2)
	{
		case '+':
		case '-':
			if(o1=='(' || o1=='#')
				f = '<';
			else
				f = '>';
			break;
		
		case '*':
		case '/':
			if(o1=='*' || o1=='/' || o1==')')
				f = '>';
			else
				f = '<';
			break;
			
		case '(':
			if(o1==')')
			{
				printf("括号匹配错误！\n");
				exit(ERROR);	
			}
			else
				f = '<';
			break;
		
		case ')':
			switch(o1)
			{
				case '(':
					f = '=';
					break;
				case '#':
					printf("输入了错误的括号！\n");
					exit(ERROR);
				default :
					f = '>';	
			}
			break;
			
		case '#':
			switch(o1)
			{
				case '#':
					f = '=';
					break;
				case '(':
					printf("表达式中有多余的括号！\n");
					exit(ERROR);
				default :
					f = '>';	
			}
			break;					
	}
	
	return f; 
} 

/*(05)返回操作数a,b按照theta运算后的结果。*/
OperandType Operate(OperandType a, OperatorType theta, OperandType b)
{
	int x, y, tmp;
	
	x = a - 48;
	y = b - 48;
	
	switch(theta)
	{
		case '+':
			tmp = x + y;
			break;
		case '-':
			tmp = x - y;
			break;
		case '*':
			tmp = x * y;
			break;
		case '/':
			tmp = x / y;
			break;
	}
	
	return tmp+48;
} 

#endif
