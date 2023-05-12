/********************************************
 *							      	                    *
 * 文件夹: 03_Stack_and_Queue/03_LineEdit   *
 * 							      	                    *
 * 文件名: LineEdit.c             	        *
 * 							      	                    *
 * 内  容: 算法3.2				  	              *
 *                                	        *
 ********************************************/
 
#ifndef LINEEDIT_C
#define LINEEDIT_C

#include "LineEdit.h"

/*(01)算法3.2：行编辑程序。*/
void LineEdit(char Buffer[])
{
	SqStack S;
	SElemType_Sq e;
	int i;
	char ch;
	
	InitStack_Sq(&S);
	
	i=0;
	ch = Buffer[i++];
	
	while(ch!='\0')		// '\0' 是字符串的结束符
	{
		while(ch!='\0' && ch!='\n')
		{
			switch(ch)
			{
				case '#': 
					Pop_Sq(&S, &e);
					break;
				case '@':
					ClearStack_Sq(&S);
					break;
				default :
					Push_Sq(&S, ch);
			}
			ch = Buffer[i++];
		}
		
		if(ch=='\n')
		{
			Push_Sq(&S, ch);
			StackTraverse_Sq(S, Print);
			ClearStack_Sq(&S);
			ch = Buffer[i++];
		}
	}
	
	if(ch=='\0')
	{
		StackTraverse_Sq(S, Print);
		DestroyStack_Sq(&S);
	}
}

/*(02)打印元素e。*/
void Print(SElemType_Sq e)
{
	printf("%c", e);
}

#endif
