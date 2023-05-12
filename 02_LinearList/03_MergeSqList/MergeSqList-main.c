/*****************************************
*									                       *
*	文件夹: 02_LinearList/03_MergeSqList   * 
*									                       *							
*	文件名: MergeSqList-main.c 		         *
*									                       *
*	内  容:	归并相关操作测试		           *
*									                       *
*****************************************/

#include <stdio.h>
#include "MergeSqList.c"

/* 测试函数-打印整型 */
void PrintElem(LElemType_Sq e);

int main(void)
{
	SqList La, Lb, Lc;
	LElemType_Sq a[4] = {3, 5, 8, 11};
	LElemType_Sq b[7] = {2, 6, 8, 9, 11, 15, 20};
	int i;
	InitList_Sq(&La);			//初始化La 
	for(i=0;i<4;i++)
		ListInsert_Sq(&La, i+1, a[i]);
	InitList_Sq(&Lb);			//初始化Lb
	for(i=0;i<7;i++)
		ListInsert_Sq(&Lb, i+1, b[i]);
	
	printf("La 的基地址为 %#x\nLb 的基地址为 %#x\n",La.elem,Lb.elem);
	printf("\n");
	printf("La = ");					//输出La
	ListTraverse_Sq(La, PrintElem);
	printf("\n\n");
	printf("Lb = ");					//输出Lb
	ListTraverse_Sq(Lb, PrintElem);
	printf("\n\n");
	
	//MergeSqList_1(La, Lb, &Lc);
	MergeSqList_2(La, Lb, &Lc);
	printf("%d\n",Lc.length);
	printf("Lc = ");			//输出新表Lc的内容
	ListTraverse_Sq(Lc, PrintElem);
	printf("\n\n");
	return 0;	
} 

void PrintElem(LElemType_Sq e)
{
	printf("%d ",e);
}
