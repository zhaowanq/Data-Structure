/**********************************************
 *							                              *
 * 文件夹: 03_Stack_and_Queue/05_Expression   *
 * 							                              *
 * 文件名: Expression-main.c                  *
 * 							                              *
 * 内  容: 表达式求值相关函数测试             *
 *                                            *
 **********************************************/

#include <stdio.h>
#include "Expression.c"		/*03 栈和队列*/

int main(void)
{
	unsigned char opnd;				//这里要注意运算的操作数只能有1位，还要注意中间计算的结果不能超出OperandType所表示的范围 
	char *exp = "(2+3)*4*6#";		//7+(7+3)*(6/3+3)*4#
	
	opnd = EvaluateExpression(exp);
	
	printf("作为示例，%s 的计算结果为：%d\n",exp, opnd-'0');
	
	printf("\n");
	
	return 0;	
} 
