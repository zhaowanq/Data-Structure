/**********************************************
 *			                     				    	    *
 * 文件夹: 03_Stack_and_Queue/02_Conversion   *
 * 							    	                        *
 * 文件名: Conversion.c         	            *
 * 							    	                        *
 * 内  容: 算法3.1				 	                  *
 *                              	            *
 **********************************************/
 
#ifndef CONVERSION_C 
#define CONVERSION_C

#include "Conversion.h"

/*(01)算法3.1：十进制数转八进制数。*/
void conversion(int i)
{
	SqStack S;
	SElemType_Sq e;
	
	InitStack_Sq(&S);	//构造空栈
	
	printf("十进制数 %d 转换为八进制数后为：0", i);
	
	while(i)
	{
		Push_Sq(&S, i%8);		//进栈时从低位到高位
		i = i/8;
	}
	
	while(!StackEmpty_Sq(S))
	{
		Pop_Sq(&S, &e);			//出栈时从高位到低位
		printf("%d", e);
	}
}

#endif
