/******************************************
*									                        *
*	文件夹: 02_LinearList/07_Difference		  * 
*									   	                    *							
*	文件名: Difference-main.c 		   	      *
*									  	                    *
*	内  容:	算法2.17测试				            *
*									   	                    *
******************************************/

#include <stdio.h>
#include "Difference.c"

/* 函数原型 */
void PrintElem(LElemType_S e);		//测试函数，打印整型

int main(void)
{
	SLinkList S;
	FILE *fp;
	int len_A, len_B, i; 
	LElemType_S A[100], B[100];
	
	len_A = 3;
	len_B = 5;
	
	fp = fopen("TestData.txt","r");
	for(i=0;i<len_A;i++)
		Scanf(fp,"%d",&A[i]);
	for(i=0;i<len_B;i++)
		Scanf(fp,"%d",&B[i]);
	fclose(fp);
			
	printf("A = ");
	for(i=0;i<len_A;i++)
		PrintElem(A[i]);
	printf("\n"); 
	printf("B = ");
	for(i=0;i<len_B;i++)
		PrintElem(B[i]);
	printf("\n");
	printf("函数：求(A-B)∪(B-A) 测试...\n");	
	PressEnter;
	difference(&S, A, len_A, B, len_B); 
	printf("S = (A-B)∪(B-A) = ");
	ListTraverse_SL(S,PrintElem);
	printf("\n\n");
	
	return 0;
}

void PrintElem(LElemType_S e)
{
	printf("%d ",e);
} 
