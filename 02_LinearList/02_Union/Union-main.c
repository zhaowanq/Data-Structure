/***************************************
*									                     *
*	文件夹: 02_LinearList/02_Union		   * 
*									                     *							
*	文件名: Union-main.c 			           *
*									                     *
*	内  容:	求并集相关操作测试		       *
*									                     *
***************************************/

#include <stdio.h>
#include "Union.c"

/* 测试函数-打印整型 */
void PrintElem(LElemType_Sq e);

int main(void)
{
	SqList La,Lb;
	LElemType_Sq a[5] = {5, 2, 1, 3, 9};
	LElemType_Sq b[7] = {7, 2, 6, 9, 11, 3, 10};
	int i;
	InitList_Sq(&La);			//初始化La 
	for(i=0;i<5;i++)
		ListInsert_Sq(&La, i+1, a[i]);
	InitList_Sq(&Lb);			//初始化Lb
	printf("La 的基地址为 %#x\nLb 的基地址为 %#x\n",La.elem,Lb.elem);
	printf("\n");
	for(i=0;i<7;i++)
		ListInsert_Sq(&Lb, i+1, b[i]);
		
	printf("La = ");					//输出La
	ListTraverse_Sq(La, PrintElem);
	printf("\n\n");
	printf("Lb = ");					//输出Lb
	ListTraverse_Sq(Lb, PrintElem);
	printf("\n\n");
	
	printf("La = LaULb = ");			//输出新表La的内容
	Union(&La,Lb);
	ListTraverse_Sq(La, PrintElem);
	printf("\n\n");
			
	printf("La中共有");
	printf("%d个元素\n",ListLength_Sq(La));
	printf("\n");
	
	return 0;
}

void PrintElem(LElemType_Sq e)
{
	printf("%d ",e);
}
