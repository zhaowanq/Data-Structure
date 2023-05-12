/**********************************************
 *							                              *
 * 文件夹: 03_Stack_and_Queue/05_Expression   *
 * 							                              *
 * 文件名: Expression.h                       *
 * 							                              *
 * 内  容: 表达式求值相关操作列表             *
 *                                            *
 **********************************************/
 
#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <stdio.h>

/* 类型定义 */
typedef char SElemType_Sq;
#include "../01_SequenceStack/SequenceStack.c"		/*03 栈和队列*/

typedef SElemType_Sq OperandType;					//操作数类型
typedef SElemType_Sq OperatorType;					//运算符类型

/*(01)算法3.4：表达式求值，假设表达式中操作数均只有一位。*/
OperandType EvaluateExpression(char exp[]);

/*(02)获取操作符栈的栈顶元素。*/
OperatorType GetTop_OPTR(SqStack OPTR);

/*(03)判断c是否属于操作符集。*/
Status In(SElemType_Sq c);

/*(04)判断栈中操作符o1与表达式中的操作符o2的优先级。*/
OperatorType Precede(OperatorType o1, OperatorType o2);

/*(05)返回操作数a,b按照theta运算后的结果。*/
OperandType Operate(OperandType a, OperatorType theta, OperandType b);

#endif
