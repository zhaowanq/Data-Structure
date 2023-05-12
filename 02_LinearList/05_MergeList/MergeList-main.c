/******************************************
*									                        *
*	文件夹: 02_LinearList/05_MergeList		  * 
*									   	                    *							
*	文件名: MergeList-main.c 		   	        *
*									  	                    *
*	内  容:	单链表归并相关函数测试		      *
*									   	                    *
******************************************/

#include <stdio.h>
#include "MergeList.c"

/* 函数原型 */
void PrintElem(LElemType_L e);		//测试函数，打印整型

int main(void)
{
	LinkList La, Lb, Lc;
	FILE *fp;
		
	fp = fopen("TestData_HL.txt", "r");
	CreateList_HL(fp, &La, 5); 	
	fp = fopen("TestData_TL.txt", "r");
	CreateList_TL(fp, &Lb, 5);
	fclose(fp);			//关闭文件流 
	printf("La 中的元素为：La = ");
	ListTraverse_L(La,PrintElem);
	printf("\n");
	printf("Lb 中的元素为：Lb = ");
	ListTraverse_L(Lb,PrintElem);
	printf("\n\n");
	
	printf("单链表归并测试\n");
	PressEnter;
	MergeList_L(La, &Lb, &Lc);
	printf("合并La和Lb为Lc = ");
	ListTraverse_L(Lc, PrintElem);
	printf("\n\n");
		
	return 0;
}

void PrintElem(LElemType_L e)
{
	printf("%d ",e);
}
