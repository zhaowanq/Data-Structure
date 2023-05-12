/****************************************
 *							                        *
 * 文件夹: 02_LinearList/10_MergeElist  *
 * 							                        *
 * 文件名: MergeEList-main.c            *
 * 							                        *
 * 内  容: 归并扩展的单链表相关操作测试 *
 *                                      *
 ****************************************/
 
#include <stdio.h>
#include "MergeElist.c"				/*02 线性表*/

void PrintElem(LElemType_E e);			//测试函数，打印整型

int main(void)
{
	FILE *fp;
	ELinkList La, Lb, Lc;
	int m, n;
	
	m = 4;
	n = 6;
	
	printf("作为示例，La长度设定为 %d ，Lb设定为 %d ，创建La和Lb...\n", m, n);
	PressEnter;
	fp = fopen("TestData_La.txt", "r");	//文件指针，指向数据源	
	CreateList_ascend(fp, &La, m);		//创建La与Lb 
	fclose(fp);
	fp = fopen("TestData_Lb.txt", "r");	//文件指针，指向数据源
	CreateList_ascend(fp, &Lb, n);	
	fclose(fp);
	
	printf("La= ");						//输出La与Lb 
	ListTraverse_E(La, PrintElem);
	printf("\n");
	printf("Lb= ");
	ListTraverse_E(Lb, PrintElem);
	printf("\n\n");
	
	printf("将La和Lb归并为一个非递减排列的单链表Lc。测试...\n");
	PressEnter;
	MergeEList_L(La, Lb, &Lc, Cmp);
	printf("合并La和Lb为 Lc = ");
	ListTraverse_E(Lc, PrintElem);
	printf("\n\n");
	
	return 0;
}

void PrintElem(LElemType_E e)
{
	printf("%d ", e);
}
